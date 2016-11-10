/*
=================================================================================
 Name        : PCD8544.c
 Version     : 0.1

 Copyright (C) 2010 Limor Fried, Adafruit Industries
 CORTEX-M3 version by Le Dang Dung, 2011 LeeDangDung@gmail.com (tested on LPC1769)
 Raspberry Pi version by Andre Wussow, 2012, desk@binerry.de

 Description :
     A simple PCD8544 LCD (Nokia3310/5110) driver. Target board is Raspberry Pi.
     This driver uses 5 GPIOs on target board with a bit-bang SPI implementation
     (hence, may not be as fast).
	 Makes use of WiringPI-library of Gordon Henderson (https://projects.drogon.net/raspberry-pi/wiringpi/)

	 Recommended connection (http://www.raspberrypi.org/archives/384):
	 LCD pins      Raspberry Pi
	 LCD1 - GND    P06  - GND
	 LCD2 - VCC    P01 - 3.3V
	 LCD3 - CLK    P11 - GPIO0
	 LCD4 - Din    P12 - GPIO1
	 LCD5 - D/C    P13 - GPIO2
	 LCD6 - CS     P15 - GPIO3
	 LCD7 - RST    P16 - GPIO4
	 LCD8 - LED    P01 - 3.3V 

 References  :
 http://www.arduino.cc/playground/Code/PCD8544
 http://ladyada.net/products/nokia5110/
 http://code.google.com/p/meshphone/

================================================================================
This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.
================================================================================
 */
#include "RaspberryGPIO.h"
#include "PCD8544.h"

// An abs() :)
#define abs(a) (((a) < 0) ? -(a) : (a))

// bit set
#define _BV(bit) (0x1 << (bit))

// LCD port variables
static uint8_t cursor_x, cursor_y, textsize, textcolor;
static int8_t _din, _sclk, _dc, _rst, _cs;

// font bitmap
static unsigned char  font[] = {
		0x00, 0x00, 0x00, 0x00, 0x00,
		0x3E, 0x5B, 0x4F, 0x5B, 0x3E,
		0x3E, 0x6B, 0x4F, 0x6B, 0x3E,
		0x1C, 0x3E, 0x7C, 0x3E, 0x1C,
		0x18, 0x3C, 0x7E, 0x3C, 0x18,
		0x1C, 0x57, 0x7D, 0x57, 0x1C,
		0x1C, 0x5E, 0x7F, 0x5E, 0x1C,
		0x00, 0x18, 0x3C, 0x18, 0x00,
		0xFF, 0xE7, 0xC3, 0xE7, 0xFF,
		0x00, 0x18, 0x24, 0x18, 0x00,
		0xFF, 0xE7, 0xDB, 0xE7, 0xFF,
		0x30, 0x48, 0x3A, 0x06, 0x0E,
		0x26, 0x29, 0x79, 0x29, 0x26,
		0x40, 0x7F, 0x05, 0x05, 0x07,
		0x40, 0x7F, 0x05, 0x25, 0x3F,
		0x5A, 0x3C, 0xE7, 0x3C, 0x5A,
		0x7F, 0x3E, 0x1C, 0x1C, 0x08,
		0x08, 0x1C, 0x1C, 0x3E, 0x7F,
		0x14, 0x22, 0x7F, 0x22, 0x14,
		0x5F, 0x5F, 0x00, 0x5F, 0x5F,
		0x06, 0x09, 0x7F, 0x01, 0x7F,
		0x00, 0x66, 0x89, 0x95, 0x6A,
		0x60, 0x60, 0x60, 0x60, 0x60,
		0x94, 0xA2, 0xFF, 0xA2, 0x94,
		0x08, 0x04, 0x7E, 0x04, 0x08,
		0x10, 0x20, 0x7E, 0x20, 0x10,
		0x08, 0x08, 0x2A, 0x1C, 0x08,
		0x08, 0x1C, 0x2A, 0x08, 0x08,
		0x1E, 0x10, 0x10, 0x10, 0x10,
		0x0C, 0x1E, 0x0C, 0x1E, 0x0C,
		0x30, 0x38, 0x3E, 0x38, 0x30,
		0x06, 0x0E, 0x3E, 0x0E, 0x06,
		0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x5F, 0x00, 0x00,
		0x00, 0x07, 0x00, 0x07, 0x00,
		0x14, 0x7F, 0x14, 0x7F, 0x14,
		0x24, 0x2A, 0x7F, 0x2A, 0x12,
		0x23, 0x13, 0x08, 0x64, 0x62,
		0x36, 0x49, 0x56, 0x20, 0x50,
		0x00, 0x08, 0x07, 0x03, 0x00,
		0x00, 0x1C, 0x22, 0x41, 0x00,
		0x00, 0x41, 0x22, 0x1C, 0x00,
		0x2A, 0x1C, 0x7F, 0x1C, 0x2A,
		0x08, 0x08, 0x3E, 0x08, 0x08,
		0x00, 0x80, 0x70, 0x30, 0x00,
		0x08, 0x08, 0x08, 0x08, 0x08,
		0x00, 0x00, 0x60, 0x60, 0x00,
		0x20, 0x10, 0x08, 0x04, 0x02,
		0x3E, 0x51, 0x49, 0x45, 0x3E,
		0x00, 0x42, 0x7F, 0x40, 0x00,
		0x72, 0x49, 0x49, 0x49, 0x46,
		0x21, 0x41, 0x49, 0x4D, 0x33,
		0x18, 0x14, 0x12, 0x7F, 0x10,
		0x27, 0x45, 0x45, 0x45, 0x39,
		0x3C, 0x4A, 0x49, 0x49, 0x31,
		0x41, 0x21, 0x11, 0x09, 0x07,
		0x36, 0x49, 0x49, 0x49, 0x36,
		0x46, 0x49, 0x49, 0x29, 0x1E,
		0x00, 0x00, 0x14, 0x00, 0x00,
		0x00, 0x40, 0x34, 0x00, 0x00,
		0x00, 0x08, 0x14, 0x22, 0x41,
		0x14, 0x14, 0x14, 0x14, 0x14,
		0x00, 0x41, 0x22, 0x14, 0x08,
		0x02, 0x01, 0x59, 0x09, 0x06,
		0x3E, 0x41, 0x5D, 0x59, 0x4E,
		0x7C, 0x12, 0x11, 0x12, 0x7C,
		0x7F, 0x49, 0x49, 0x49, 0x36,
		0x3E, 0x41, 0x41, 0x41, 0x22,
		0x7F, 0x41, 0x41, 0x41, 0x3E,
		0x7F, 0x49, 0x49, 0x49, 0x41,
		0x7F, 0x09, 0x09, 0x09, 0x01,
		0x3E, 0x41, 0x41, 0x51, 0x73,
		0x7F, 0x08, 0x08, 0x08, 0x7F,
		0x00, 0x41, 0x7F, 0x41, 0x00,
		0x20, 0x40, 0x41, 0x3F, 0x01,
		0x7F, 0x08, 0x14, 0x22, 0x41,
		0x7F, 0x40, 0x40, 0x40, 0x40,
		0x7F, 0x02, 0x1C, 0x02, 0x7F,
		0x7F, 0x04, 0x08, 0x10, 0x7F,
		0x3E, 0x41, 0x41, 0x41, 0x3E,
		0x7F, 0x09, 0x09, 0x09, 0x06,
		0x3E, 0x41, 0x51, 0x21, 0x5E,
		0x7F, 0x09, 0x19, 0x29, 0x46,
		0x26, 0x49, 0x49, 0x49, 0x32,
		0x03, 0x01, 0x7F, 0x01, 0x03,
		0x3F, 0x40, 0x40, 0x40, 0x3F,
		0x1F, 0x20, 0x40, 0x20, 0x1F,
		0x3F, 0x40, 0x38, 0x40, 0x3F,
		0x63, 0x14, 0x08, 0x14, 0x63,
		0x03, 0x04, 0x78, 0x04, 0x03,
		0x61, 0x59, 0x49, 0x4D, 0x43,
		0x00, 0x7F, 0x41, 0x41, 0x41,
		0x02, 0x04, 0x08, 0x10, 0x20,
		0x00, 0x41, 0x41, 0x41, 0x7F,
		0x04, 0x02, 0x01, 0x02, 0x04,
		0x40, 0x40, 0x40, 0x40, 0x40,
		0x00, 0x03, 0x07, 0x08, 0x00,
		0x20, 0x54, 0x54, 0x78, 0x40,
		0x7F, 0x28, 0x44, 0x44, 0x38,
		0x38, 0x44, 0x44, 0x44, 0x28,
		0x38, 0x44, 0x44, 0x28, 0x7F,
		0x38, 0x54, 0x54, 0x54, 0x18,
		0x00, 0x08, 0x7E, 0x09, 0x02,
		0x18, 0xA4, 0xA4, 0x9C, 0x78,
		0x7F, 0x08, 0x04, 0x04, 0x78,
		0x00, 0x44, 0x7D, 0x40, 0x00,
		0x20, 0x40, 0x40, 0x3D, 0x00,
		0x7F, 0x10, 0x28, 0x44, 0x00,
		0x00, 0x41, 0x7F, 0x40, 0x00,
		0x7C, 0x04, 0x78, 0x04, 0x78,
		0x7C, 0x08, 0x04, 0x04, 0x78,
		0x38, 0x44, 0x44, 0x44, 0x38,
		0xFC, 0x18, 0x24, 0x24, 0x18,
		0x18, 0x24, 0x24, 0x18, 0xFC,
		0x7C, 0x08, 0x04, 0x04, 0x08,
		0x48, 0x54, 0x54, 0x54, 0x24,
		0x04, 0x04, 0x3F, 0x44, 0x24,
		0x3C, 0x40, 0x40, 0x20, 0x7C,
		0x1C, 0x20, 0x40, 0x20, 0x1C,
		0x3C, 0x40, 0x30, 0x40, 0x3C,
		0x44, 0x28, 0x10, 0x28, 0x44,
		0x4C, 0x90, 0x90, 0x90, 0x7C,
		0x44, 0x64, 0x54, 0x4C, 0x44,
		0x00, 0x08, 0x36, 0x41, 0x00,
		0x00, 0x00, 0x77, 0x00, 0x00,
		0x00, 0x41, 0x36, 0x08, 0x00,
		0x02, 0x01, 0x02, 0x04, 0x02,
		0x3C, 0x26, 0x23, 0x26, 0x3C,
		0x1E, 0xA1, 0xA1, 0x61, 0x12,
		0x3A, 0x40, 0x40, 0x20, 0x7A,
		0x38, 0x54, 0x54, 0x55, 0x59,
		0x21, 0x55, 0x55, 0x79, 0x41,
		0x21, 0x54, 0x54, 0x78, 0x41,
		0x21, 0x55, 0x54, 0x78, 0x40,
		0x20, 0x54, 0x55, 0x79, 0x40,
		0x0C, 0x1E, 0x52, 0x72, 0x12,
		0x39, 0x55, 0x55, 0x55, 0x59,
		0x39, 0x54, 0x54, 0x54, 0x59,
		0x39, 0x55, 0x54, 0x54, 0x58,
		0x00, 0x00, 0x45, 0x7C, 0x41,
		0x00, 0x02, 0x45, 0x7D, 0x42,
		0x00, 0x01, 0x45, 0x7C, 0x40,
		0xF0, 0x29, 0x24, 0x29, 0xF0,
		0xF0, 0x28, 0x25, 0x28, 0xF0,
		0x7C, 0x54, 0x55, 0x45, 0x00,
		0x20, 0x54, 0x54, 0x7C, 0x54,
		0x7C, 0x0A, 0x09, 0x7F, 0x49,
		0x32, 0x49, 0x49, 0x49, 0x32,
		0x32, 0x48, 0x48, 0x48, 0x32,
		0x32, 0x4A, 0x48, 0x48, 0x30,
		0x3A, 0x41, 0x41, 0x21, 0x7A,
		0x3A, 0x42, 0x40, 0x20, 0x78,
		0x00, 0x9D, 0xA0, 0xA0, 0x7D,
		0x39, 0x44, 0x44, 0x44, 0x39,
		0x3D, 0x40, 0x40, 0x40, 0x3D,
		0x3C, 0x24, 0xFF, 0x24, 0x24,
		0x48, 0x7E, 0x49, 0x43, 0x66,
		0x2B, 0x2F, 0xFC, 0x2F, 0x2B,
		0xFF, 0x09, 0x29, 0xF6, 0x20,
		0xC0, 0x88, 0x7E, 0x09, 0x03,
		0x20, 0x54, 0x54, 0x79, 0x41,
		0x00, 0x00, 0x44, 0x7D, 0x41,
		0x30, 0x48, 0x48, 0x4A, 0x32,
		0x38, 0x40, 0x40, 0x22, 0x7A,
		0x00, 0x7A, 0x0A, 0x0A, 0x72,
		0x7D, 0x0D, 0x19, 0x31, 0x7D,
		0x26, 0x29, 0x29, 0x2F, 0x28,
		0x26, 0x29, 0x29, 0x29, 0x26,
		0x30, 0x48, 0x4D, 0x40, 0x20,
		0x38, 0x08, 0x08, 0x08, 0x08,
		0x08, 0x08, 0x08, 0x08, 0x38,
		0x2F, 0x10, 0xC8, 0xAC, 0xBA,
		0x2F, 0x10, 0x28, 0x34, 0xFA,
		0x00, 0x00, 0x7B, 0x00, 0x00,
		0x08, 0x14, 0x2A, 0x14, 0x22,
		0x22, 0x14, 0x2A, 0x14, 0x08,
		0xAA, 0x00, 0x55, 0x00, 0xAA,
		0xAA, 0x55, 0xAA, 0x55, 0xAA,
		0x00, 0x00, 0x00, 0xFF, 0x00,
		0x10, 0x10, 0x10, 0xFF, 0x00,
		0x14, 0x14, 0x14, 0xFF, 0x00,
		0x10, 0x10, 0xFF, 0x00, 0xFF,
		0x10, 0x10, 0xF0, 0x10, 0xF0,
		0x14, 0x14, 0x14, 0xFC, 0x00,
		0x14, 0x14, 0xF7, 0x00, 0xFF,
		0x00, 0x00, 0xFF, 0x00, 0xFF,
		0x14, 0x14, 0xF4, 0x04, 0xFC,
		0x14, 0x14, 0x17, 0x10, 0x1F,
		0x10, 0x10, 0x1F, 0x10, 0x1F,
		0x14, 0x14, 0x14, 0x1F, 0x00,
		0x10, 0x10, 0x10, 0xF0, 0x00,
		0x00, 0x00, 0x00, 0x1F, 0x10,
		0x10, 0x10, 0x10, 0x1F, 0x10,
		0x10, 0x10, 0x10, 0xF0, 0x10,
		0x00, 0x00, 0x00, 0xFF, 0x10,
		0x10, 0x10, 0x10, 0x10, 0x10,
		0x10, 0x10, 0x10, 0xFF, 0x10,
		0x00, 0x00, 0x00, 0xFF, 0x14,
		0x00, 0x00, 0xFF, 0x00, 0xFF,
		0x00, 0x00, 0x1F, 0x10, 0x17,
		0x00, 0x00, 0xFC, 0x04, 0xF4,
		0x14, 0x14, 0x17, 0x10, 0x17,
		0x14, 0x14, 0xF4, 0x04, 0xF4,
		0x00, 0x00, 0xFF, 0x00, 0xF7,
		0x14, 0x14, 0x14, 0x14, 0x14,
		0x14, 0x14, 0xF7, 0x00, 0xF7,
		0x14, 0x14, 0x14, 0x17, 0x14,
		0x10, 0x10, 0x1F, 0x10, 0x1F,
		0x14, 0x14, 0x14, 0xF4, 0x14,
		0x10, 0x10, 0xF0, 0x10, 0xF0,
		0x00, 0x00, 0x1F, 0x10, 0x1F,
		0x00, 0x00, 0x00, 0x1F, 0x14,
		0x00, 0x00, 0x00, 0xFC, 0x14,
		0x00, 0x00, 0xF0, 0x10, 0xF0,
		0x10, 0x10, 0xFF, 0x10, 0xFF,
		0x14, 0x14, 0x14, 0xFF, 0x14,
		0x10, 0x10, 0x10, 0x1F, 0x00,
		0x00, 0x00, 0x00, 0xF0, 0x10,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xF0, 0xF0, 0xF0, 0xF0, 0xF0,
		0xFF, 0xFF, 0xFF, 0x00, 0x00,
		0x00, 0x00, 0x00, 0xFF, 0xFF,
		0x0F, 0x0F, 0x0F, 0x0F, 0x0F,
		0x38, 0x44, 0x44, 0x38, 0x44,
		0x7C, 0x2A, 0x2A, 0x3E, 0x14,
		0x7E, 0x02, 0x02, 0x06, 0x06,
		0x02, 0x7E, 0x02, 0x7E, 0x02,
		0x63, 0x55, 0x49, 0x41, 0x63,
		0x38, 0x44, 0x44, 0x3C, 0x04,
		0x40, 0x7E, 0x20, 0x1E, 0x20,
		0x06, 0x02, 0x7E, 0x02, 0x02,
		0x99, 0xA5, 0xE7, 0xA5, 0x99,
		0x1C, 0x2A, 0x49, 0x2A, 0x1C,
		0x4C, 0x72, 0x01, 0x72, 0x4C,
		0x30, 0x4A, 0x4D, 0x4D, 0x30,
		0x30, 0x48, 0x78, 0x48, 0x30,
		0xBC, 0x62, 0x5A, 0x46, 0x3D,
		0x3E, 0x49, 0x49, 0x49, 0x00,
		0x7E, 0x01, 0x01, 0x01, 0x7E,
		0x2A, 0x2A, 0x2A, 0x2A, 0x2A,
		0x44, 0x44, 0x5F, 0x44, 0x44,
		0x40, 0x51, 0x4A, 0x44, 0x40,
		0x40, 0x44, 0x4A, 0x51, 0x40,
		0x00, 0x00, 0xFF, 0x01, 0x03,
		0xE0, 0x80, 0xFF, 0x00, 0x00,
		0x08, 0x08, 0x6B, 0x6B, 0x08,
		0x36, 0x12, 0x36, 0x24, 0x36,
		0x06, 0x0F, 0x09, 0x0F, 0x06,
		0x00, 0x00, 0x18, 0x18, 0x00,
		0x00, 0x00, 0x10, 0x10, 0x00,
		0x30, 0x40, 0xFF, 0x01, 0x01,
		0x00, 0x1F, 0x01, 0x01, 0x1E,
		0x00, 0x19, 0x1D, 0x17, 0x12,
		0x00, 0x3C, 0x3C, 0x3C, 0x3C,
		0x00, 0x00, 0x00, 0x00, 0x00,
};

// the memory buffer for the LCD
uint8_t pcd8544_buffer[LCDWIDTH * LCDHEIGHT / 8] = {0,};

// Le: get the bitmap assistance here! : http://en.radzio.dxp.pl/bitmap_converter/
// Andre: or here! : http://www.henningkarlsen.com/electronics/t_imageconverter_mono.php
const uint8_t pi_logo [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   // 0x0010 (16) pixels
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0xF8, 0xFC, 0xAE, 0x0E, 0x0E, 0x06, 0x0E, 0x06,   // 0x0020 (32) pixels
0xCE, 0x86, 0x8E, 0x0E, 0x0E, 0x1C, 0xB8, 0xF0, 0xF8, 0x78, 0x38, 0x1E, 0x0E, 0x8E, 0x8E, 0xC6,   // 0x0030 (48) pixels
0x0E, 0x06, 0x0E, 0x06, 0x0E, 0x9E, 0xFE, 0xFC, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   // 0x0040 (64) pixels
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   // 0x0050 (80) pixels
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   // 0x0060 (96) pixels
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x0F, 0x0F, 0xFE,   // 0x0070 (112) pixels
0xF8, 0xF0, 0x60, 0x60, 0xE0, 0xE1, 0xE3, 0xF7, 0x7E, 0x3E, 0x1E, 0x1F, 0x1F, 0x1F, 0x3E, 0x7E,   // 0x0080 (128) pixels
0xFB, 0xF3, 0xE1, 0xE0, 0x60, 0x70, 0xF0, 0xF8, 0xBE, 0x1F, 0x0F, 0x07, 0x00, 0x00, 0x00, 0x00,   // 0x0090 (144) pixels
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   // 0x00A0 (160) pixels
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   // 0x00B0 (176) pixels
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0,   // 0x00C0 (192) pixels
0xE0, 0xFC, 0xFE, 0xFF, 0xF3, 0x38, 0x38, 0x0C, 0x0E, 0x0F, 0x0F, 0x0F, 0x0E, 0x3C, 0x38, 0xF8,   // 0x00D0 (208) pixels
0xF8, 0x38, 0x3C, 0x0E, 0x0F, 0x0F, 0x0F, 0x0E, 0x0C, 0x38, 0x38, 0xF3, 0xFF, 0xFF, 0xF8, 0xE0,   // 0x00E0 (224) pixels
0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   // 0x00F0 (240) pixels
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   // 0x0100 (256) pixels
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   // 0x0110 (272) pixels
0x00, 0x7F, 0xFF, 0xE7, 0xC3, 0xC1, 0xE0, 0xFF, 0xFF, 0x78, 0xE0, 0xC0, 0xC0, 0xC0, 0xC0, 0xE0,   // 0x0120 (288) pixels
0x60, 0x78, 0x38, 0x3F, 0x3F, 0x38, 0x38, 0x60, 0x60, 0xC0, 0xC0, 0xC0, 0xC0, 0xE0, 0xF8, 0x7F,   // 0x0130 (304) pixels
0xFF, 0xE0, 0xC1, 0xC3, 0xE7, 0x7F, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   // 0x0140 (320) pixels
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   // 0x0150 (336) pixels
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   // 0x0160 (352) pixels
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x0F, 0x7F, 0xFF, 0xF1, 0xE0, 0xC0, 0x80, 0x01,   // 0x0170 (368) pixels
0x03, 0x9F, 0xFF, 0xF0, 0xE0, 0xE0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xE0, 0xE0, 0xF0, 0xFF, 0x9F,   // 0x0180 (384) pixels
0x03, 0x01, 0x80, 0xC0, 0xE0, 0xF1, 0x7F, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   // 0x0190 (400) pixels
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   // 0x01A0 (416) pixels
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   // 0x01B0 (432) pixels
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,   // 0x01C0 (448) pixels
0x03, 0x03, 0x07, 0x07, 0x0F, 0x1F, 0x1F, 0x3F, 0x3B, 0x71, 0x60, 0x60, 0x60, 0x60, 0x60, 0x71,   // 0x01D0 (464) pixels
0x3B, 0x1F, 0x0F, 0x0F, 0x0F, 0x07, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   // 0x01E0 (480) pixels
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   // 0x01F0 (496) pixels
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

// reduces how much is refreshed, which speeds it up!
// originally derived from Steve Evans/JCW's mod but cleaned up and optimized
//#define enablePartialUpdate

static void my_setpixel(uint8_t x, uint8_t y, uint8_t color)
{
	if ((x >= LCDWIDTH) || (y >= LCDHEIGHT))
		return;
	// x is which column
	if (color)
		pcd8544_buffer[x+ (y/8)*LCDWIDTH] |= _BV(y%8);
	else
		pcd8544_buffer[x+ (y/8)*LCDWIDTH] &= ~_BV(y%8);
}

void LCDshowLogo()
{
	uint32_t i;
	for (i = 0; i < LCDWIDTH * LCDHEIGHT / 8; i++  )
	{
		pcd8544_buffer[i] = pi_logo[i];
	}
	LCDdisplay();
}

#ifdef enablePartialUpdate
static uint8_t xUpdateMin, xUpdateMax, yUpdateMin, yUpdateMax;
#endif

static void updateBoundingBox(uint8_t xmin, uint8_t ymin, uint8_t xmax, uint8_t ymax) {
#ifdef enablePartialUpdate
	if (xmin < xUpdateMin) xUpdateMin = xmin;
	if (xmax > xUpdateMax) xUpdateMax = xmax;
	if (ymin < yUpdateMin) yUpdateMin = ymin;
	if (ymax > yUpdateMax) yUpdateMax = ymax;
#endif
}

void LCDInit(uint8_t SCLK, uint8_t DIN, uint8_t DC, uint8_t CS, uint8_t RST, uint8_t contrast)
{
	_din = DIN;
	_sclk = SCLK;
	_dc = DC;
	_rst = RST;
	_cs = CS;
	cursor_x = cursor_y = 0;
	textsize = 1;
	textcolor = BLACK;

	// set pin directions
	GPIOExport(_din);	GPIODirection(_din,OUTPUT);
	GPIOExport(_sclk);	GPIODirection(_sclk,OUTPUT);
	GPIOExport(_dc);	GPIODirection(_dc,OUTPUT);
	GPIOExport(_rst);	GPIODirection(_rst,OUTPUT);
	GPIOExport(_cs);	GPIODirection(_cs,OUTPUT);
	/*pinMode(_din, OUTPUT);
	pinMode(_sclk, OUTPUT);
	pinMode(_dc, OUTPUT);
	pinMode(_rst, OUTPUT);
	pinMode(_cs, OUTPUT);*/

	// toggle RST low to reset; CS low so it'll listen to us
	if (_cs > 0)
		//digitalWrite(_cs, LOW);
		GPIOWrite(_cs,LOW);
	
	GPIOWrite(_rst,LOW);
	delay_ms(500);
	GPIOWrite(_rst,HIGH);
	//digitalWrite(_rst, LOW);
	//_delay_ms(500);
	//digitalWrite(_rst, HIGH);

	// get into the EXTENDED mode!
	LCDcommand(PCD8544_FUNCTIONSET | PCD8544_EXTENDEDINSTRUCTION );

	// LCD bias select (4 is optimal?)
	LCDcommand(PCD8544_SETBIAS | 0x4);

	// set VOP
	if (contrast > 0x7f)
		contrast = 0x7f;

	LCDcommand( PCD8544_SETVOP | contrast); // Experimentally determined

	// normal mode
	LCDcommand(PCD8544_FUNCTIONSET);

	// Set display to Normal
	LCDcommand(PCD8544_DISPLAYCONTROL | PCD8544_DISPLAYNORMAL);

	// set up a bounding box for screen updates
	updateBoundingBox(0, 0, LCDWIDTH-1, LCDHEIGHT-1);

}

void LCDdrawbitmap(uint8_t x, uint8_t y,const uint8_t *bitmap, uint8_t w, uint8_t h,uint8_t color)
{
	uint8_t j,i;
	for ( j=0; j<h; j++)
	{
		for ( i=0; i<w; i++ )
		{
			if (*(bitmap + i + (j/8)*w) & _BV(j%8))
			{
				my_setpixel(x+i, y+j, color);
			}
		}
	}
	updateBoundingBox(x, y, x+w, y+h);
}

void LCDdrawstring(uint8_t x, uint8_t y, char *c)
{
	cursor_x = x;
	cursor_y = y;
	while (*c)
	{
		LCDwrite(*c++);
	}
}

void LCDdrawstring_P(uint8_t x, uint8_t y, const char *str)
{
	cursor_x = x;
	cursor_y = y;
	while (1)
	{
		char c = (*str++);
		if (! c)
			return;
		LCDwrite(c);
	}
}

void LCDdrawchar(uint8_t x, uint8_t y, char c)
{
	if (y >= LCDHEIGHT) return;
	if ((x+5) >= LCDWIDTH) return;
	uint8_t i,j;
	for ( i =0; i<5; i++ )
	{
		uint8_t d = *(font+(c*5)+i);
		uint8_t j;
		for (j = 0; j<8; j++)
		{
			if (d & _BV(j))
			{
				my_setpixel(x+i, y+j, textcolor);
			}
			else
			{
				my_setpixel(x+i, y+j, !textcolor);
			}
		}
	}

	for ( j = 0; j<8; j++)
	{
		my_setpixel(x+5, y+j, !textcolor);
	}
	updateBoundingBox(x, y, x+5, y + 8);
}

void LCDwrite(uint8_t c)
{
	if (c == '\n')
	{
		cursor_y += textsize*8;
		cursor_x = 0;
	}
	else if (c == '\r')
	{
		// skip em
	}
	else
	{
		LCDdrawchar(cursor_x, cursor_y, c);
		cursor_x += textsize*6;
		if (cursor_x >= (LCDWIDTH-5))
		{
			cursor_x = 0;
			cursor_y+=8;
		}
		if (cursor_y >= LCDHEIGHT)
			cursor_y = 0;
	}
}

void LCDsetCursor(uint8_t x, uint8_t y)
{
	cursor_x = x;
	cursor_y = y;
}

// bresenham's algorithm - thx wikpedia
void LCDdrawline(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint8_t color)
{
	uint8_t steep = abs(y1 - y0) > abs(x1 - x0);
	if (steep)
	{
		swap(x0, y0);
		swap(x1, y1);
	}

	if (x0 > x1)
	{
		swap(x0, x1);
		swap(y0, y1);
	}

	// much faster to put the test here, since we've already sorted the points
	updateBoundingBox(x0, y0, x1, y1);

	uint8_t dx, dy;
	dx = x1 - x0;
	dy = abs(y1 - y0);

	int8_t err = dx / 2;
	int8_t ystep;

	if (y0 < y1)
	{
		ystep = 1;
	} else
	{
		ystep = -1;
	}

	for (; x0<=x1; x0++)
	{
		if (steep)
		{
			my_setpixel(y0, x0, color);
		}
		else
		{
			my_setpixel(x0, y0, color);
		}
		err -= dy;
		if (err < 0)
		{
			y0 += ystep;
			err += dx;
		}
	}
}

// filled rectangle
void LCDfillrect(uint8_t x, uint8_t y, uint8_t w, uint8_t h,  uint8_t color)
{
	// stupidest version - just pixels - but fast with internal buffer!
	uint8_t i,j;
	for ( i=x; i<x+w; i++)
	{
		for ( j=y; j<y+h; j++)
		{
			my_setpixel(i, j, color);
		}
	}
	updateBoundingBox(x, y, x+w, y+h);
}

// draw a rectangle
void LCDdrawrect(uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint8_t color)
{
	// stupidest version - just pixels - but fast with internal buffer!
	uint8_t i;
	for ( i=x; i<x+w; i++) {
		my_setpixel(i, y, color);
		my_setpixel(i, y+h-1, color);
	}
	for ( i=y; i<y+h; i++) {
		my_setpixel(x, i, color);
		my_setpixel(x+w-1, i, color);
	}

	updateBoundingBox(x, y, x+w, y+h);
}

// draw a circle outline
void LCDdrawcircle(uint8_t x0, uint8_t y0, uint8_t r, uint8_t color)
{
	updateBoundingBox(x0-r, y0-r, x0+r, y0+r);

	int8_t f = 1 - r;
	int8_t ddF_x = 1;
	int8_t ddF_y = -2 * r;
	int8_t x = 0;
	int8_t y = r;

	my_setpixel(x0, y0+r, color);
	my_setpixel(x0, y0-r, color);
	my_setpixel(x0+r, y0, color);
	my_setpixel(x0-r, y0, color);

	while (x<y)
	{
		if (f >= 0)
		{
			y--;
			ddF_y += 2;
			f += ddF_y;
		}
		x++;
		ddF_x += 2;
		f += ddF_x;

		my_setpixel(x0 + x, y0 + y, color);
		my_setpixel(x0 - x, y0 + y, color);
		my_setpixel(x0 + x, y0 - y, color);
		my_setpixel(x0 - x, y0 - y, color);

		my_setpixel(x0 + y, y0 + x, color);
		my_setpixel(x0 - y, y0 + x, color);
		my_setpixel(x0 + y, y0 - x, color);
		my_setpixel(x0 - y, y0 - x, color);

	}
}

void LCDfillcircle(uint8_t x0, uint8_t y0, uint8_t r, uint8_t color)
{
	updateBoundingBox(x0-r, y0-r, x0+r, y0+r);
	int8_t f = 1 - r;
	int8_t ddF_x = 1;
	int8_t ddF_y = -2 * r;
	int8_t x = 0;
	int8_t y = r;
	uint8_t i;

	for (i=y0-r; i<=y0+r; i++)
	{
		my_setpixel(x0, i, color);
	}

	while (x<y)
	{
		if (f >= 0)
		{
			y--;
			ddF_y += 2;
			f += ddF_y;
		}
		x++;
		ddF_x += 2;
		f += ddF_x;

		for ( i=y0-y; i<=y0+y; i++)
		{
			my_setpixel(x0+x, i, color);
			my_setpixel(x0-x, i, color);
		}
		for ( i=y0-x; i<=y0+x; i++)
		{
			my_setpixel(x0+y, i, color);
			my_setpixel(x0-y, i, color);
		}
	}
}

// the most basic function, set a single pixel
void LCDsetPixel(uint8_t x, uint8_t y, uint8_t color)
{
	if ((x >= LCDWIDTH) || (y >= LCDHEIGHT))
		return;

	// x is which column
	if (color)
		pcd8544_buffer[x+ (y/8)*LCDWIDTH] |= _BV(y%8);
	else
		pcd8544_buffer[x+ (y/8)*LCDWIDTH] &= ~_BV(y%8);
	updateBoundingBox(x,y,x,y);
}

// the most basic function, get a single pixel
uint8_t LCDgetPixel(uint8_t x, uint8_t y)
{
	if ((x >= LCDWIDTH) || (y >= LCDHEIGHT))
		return 0;

	return (pcd8544_buffer[x+ (y/8)*LCDWIDTH] >> (7-(y%8))) & 0x1;
}

void LCDspiwrite(uint8_t c)
{
	shiftOut(_din, _sclk, MSBFIRST, c);
}

void LCDcommand(uint8_t c)
{
	GPIOWrite(_dc,LOW);
	//digitalWrite( _dc, LOW);
	LCDspiwrite(c);
}

void LCDdata(uint8_t c)
{
	GPIOWrite(_dc,HIGH);
	//digitalWrite(_dc, HIGH);
	LCDspiwrite(c);
}

void LCDsetContrast(uint8_t val)
{
	if (val > 0x7f) {
		val = 0x7f;
	}
	LCDcommand(PCD8544_FUNCTIONSET | PCD8544_EXTENDEDINSTRUCTION );
	LCDcommand( PCD8544_SETVOP | val);
	LCDcommand(PCD8544_FUNCTIONSET);
}

void LCDdisplay(void)
{
	uint8_t col, maxcol, p;

	for(p = 0; p < 6; p++)
	{
#ifdef enablePartialUpdate
		// check if this page is part of update
		if ( yUpdateMin >= ((p+1)*8) )
		{
			continue;   // nope, skip it!
		}
		if (yUpdateMax < p*8)
		{
			break;
		}
#endif

		LCDcommand(PCD8544_SETYADDR | p);


#ifdef enablePartialUpdate
		col = xUpdateMin;
		maxcol = xUpdateMax;
#else
		// start at the beginning of the row
		col = 0;
		maxcol = LCDWIDTH-1;
#endif

		LCDcommand(PCD8544_SETXADDR | col);

		for(; col <= maxcol; col++) {
			//uart_putw_dec(col);
			//uart_putchar(' ');
			LCDdata(pcd8544_buffer[(LCDWIDTH*p)+col]);
		}
	}

	LCDcommand(PCD8544_SETYADDR );  // no idea why this is necessary but it is to finish the last byte?
#ifdef enablePartialUpdate
	xUpdateMin = LCDWIDTH - 1;
	xUpdateMax = 0;
	yUpdateMin = LCDHEIGHT-1;
	yUpdateMax = 0;
#endif

}

// clear everything
void LCDclear(void) {
	//memset(pcd8544_buffer, 0, LCDWIDTH*LCDHEIGHT/8);
	uint32_t i;
	for ( i = 0; i < LCDWIDTH*LCDHEIGHT/8 ; i++)
		pcd8544_buffer[i] = 0;
	updateBoundingBox(0, 0, LCDWIDTH-1, LCDHEIGHT-1);
	cursor_y = cursor_x = 0;
}

// bitbang serial shift out on select GPIO pin. Data rate is defined by CPU clk speed and CLKCONST_2. 
// Calibrate these value for your need on target platform.
/*void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t val)
{
	uint8_t i;
	uint32_t j;

	for (i = 0; i < 8; i++){
		if (bitOrder == LSBFIRST)
			GPIOWrite(dataPin, !!(val & (1 << i)));
		else
			GPIOWrite(dataPin, !!(val & (1 << (7 - i))));

		GPIOWrite(clockPin, HIGH);
		for (j = CLKCONST_2; j > 0; j--); // clock speed, anyone? (LCD Max CLK input: 4MHz)
		GPIOWrite(clockPin, LOW);
	}
}*/
void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t val){
	if(bitOrder == LSBFIRST){
		for(register uint8_t count = 0 ; count < 8 ; count ++){
			GPIOWrite(dataPin,!!(val&(1<<count)));
			GPIOWrite(clockPin,HIGH);
			for(register unsigned int count1 = CLKCONST_2 ; count1 > 0 ; count1--);
			GPIOWrite(clockPin,LOW);
		}
	}
	else{
		for(register uint8_t count = 0 ; count < 8 ; count ++){
			GPIOWrite(dataPin,!!(val & (1 << (7 - count))));
			GPIOWrite(clockPin,HIGH);
			for(register unsigned int count1 = CLKCONST_2 ; count1 > 0 ; count1--);
			GPIOWrite(clockPin,LOW);
		}
	}			
}

// roughly calibrated spin delay
void _delay_ms(uint32_t t){
	uint32_t nCount = 0;
	while (t != 0)
	{
		nCount = CLKCONST_1;
		while(nCount != 0)
			nCount--;
		t--;
	}
}
void LCDDrawBitmap(const unsigned char *logo){
	for (register unsigned int cont = 0; cont < LCDWIDTH * LCDHEIGHT / 8; cont++  ){
		pcd8544_buffer[cont] = logo[cont];
	}
	LCDdisplay();
}
void LCDSet(uint8_t color,uint8_t size){
	textcolor = color;
	textsize = size;
}
void LCDwriteScroll(uint8_t c){
	if (c == '\n')
	{
		cursor_y -= textsize*8;
		cursor_x = 0;
	}
	else if (c == '\r')
	{
		// skip em
	}
	else
	{
		LCDdrawchar(cursor_x, cursor_y, c);
		cursor_x -= textsize*6;
		if (cursor_x >= (LCDWIDTH-5))
		{
			cursor_x = 0;
			cursor_y-=8;
		}
		if (cursor_y >= LCDHEIGHT)
			cursor_y = 0;
	}
}

