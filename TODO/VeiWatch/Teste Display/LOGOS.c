
#include "RaspberryGPIO.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/sysinfo.h>
#include "PCD8544.h"
#include "Logo.h"
// pin setup
int _din = 24;
int _sclk = 23;
int _dc = 25;
int _rst = 7;
int _cs = 8;
  
// lcd contrast 
int contrast = 50;

int main (void)
{
  // print infos
  printf("Raspberry Pi PCD8544 sysinfo display\n");
  printf("========================================\n");
  
  // check wiringPi setup
  GPIOExport(18);
	GPIODirection(18,OUTPUT);
	GPIOWrite(18,HIGH);
  // init and clear lcd
  LCDInit(_sclk, _din, _dc, _cs, _rst, contrast);
  LCDclear();
  
  // show logo
  LCDshowLogo();
  
  delay_ms(2000);
	SLCDDrawBitmap(main_display);
	  delay_ms(2000);
	getchar();
	GPIOWrite(18,LOW);	
	GPIOUnexport(18);
	GPIOUnexport(_sclk);
	GPIOUnexport(_din);
	GPIOUnexport(_dc);

	GPIOUnexport(_cs);
	GPIOUnexport(_rst);
}
