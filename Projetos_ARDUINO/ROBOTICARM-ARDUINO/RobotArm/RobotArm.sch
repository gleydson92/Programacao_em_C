EESchema Schematic File Version 2
LIBS:PMIC-LM7805ACT_TO-220_
LIBS:ECA-1EHG682
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:ATMEGA328P-PU
LIBS:CD40106BE
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:RobotArm-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L ATMEGA328P-PU U1
U 1 1 572F9026
P 2500 2850
F 0 "U1" H 2281 3697 50  0000 L CNN
F 1 "ATMEGA328P-PU" H 2304 1628 50  0000 L CNN
F 2 "ATMEGA328P-PU:DIP254P762X457-28" H 2500 2850 50  0001 L CNN
F 3 "" H 2500 2850 60  0000 C CNN
	1    2500 2850
	1    0    0    -1  
$EndComp
$Comp
L CD40106BE U3
U 1 1 572F919C
P 4450 2550
F 0 "U3" H 4235 3129 50  0000 L CNN
F 1 "CD40106BE" H 4260 1573 50  0000 L CNN
F 2 "CD40106BE:DIP254P762X508-14" H 4450 2550 50  0001 L CNN
F 3 "" H 4450 2550 60  0000 C CNN
	1    4450 2550
	-1   0    0    -1  
$EndComp
$Comp
L Crystal Y1
U 1 1 572F92C0
P 1450 3700
F 0 "Y1" H 1450 3850 50  0000 C CNN
F 1 "Crystal" H 1450 3550 50  0000 C CNN
F 2 "Crystals:Crystal_HC48-U_Vertical" H 1450 3700 50  0001 C CNN
F 3 "" H 1450 3700 50  0000 C CNN
	1    1450 3700
	-1   0    0    1   
$EndComp
$Comp
L C C2
U 1 1 572F93D3
P 1300 3900
F 0 "C2" H 1325 4000 50  0000 L CNN
F 1 "C" H 1325 3800 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Radial_D5_L11_P2" H 1338 3750 50  0001 C CNN
F 3 "" H 1300 3900 50  0000 C CNN
	1    1300 3900
	-1   0    0    1   
$EndComp
$Comp
L BARREL_JACK CON1
U 1 1 572F9436
P 1100 950
F 0 "CON1" H 1100 1200 50  0000 C CNN
F 1 "BARREL_JACK" H 1100 750 50  0000 C CNN
F 2 "Connect:JACK_ALIM" H 1100 950 50  0001 C CNN
F 3 "" H 1100 950 50  0000 C CNN
	1    1100 950 
	1    0    0    -1  
$EndComp
$Comp
L D D1
U 1 1 572F94A7
P 1750 850
F 0 "D1" H 1750 950 50  0000 C CNN
F 1 "D" H 1750 750 50  0000 C CNN
F 2 "Diodes_ThroughHole:Diode_DO-35_SOD27_Horizontal_RM10" H 1750 850 50  0001 C CNN
F 3 "" H 1750 850 50  0000 C CNN
	1    1750 850 
	-1   0    0    1   
$EndComp
$Comp
L 7805 U2
U 1 1 572F9516
P 2550 900
F 0 "U2" H 2700 704 50  0000 C CNN
F 1 "7805" H 2550 1100 50  0000 C CNN
F 2 "" H 2550 900 50  0001 C CNN
F 3 "" H 2550 900 50  0000 C CNN
	1    2550 900 
	1    0    0    -1  
$EndComp
$Comp
L CP C5
U 1 1 572F9574
P 2050 1000
F 0 "C5" H 2075 1100 50  0000 L CNN
F 1 "CP" H 2075 900 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Radial_D5_L11_P2" H 2088 850 50  0001 C CNN
F 3 "" H 2050 1000 50  0000 C CNN
	1    2050 1000
	1    0    0    -1  
$EndComp
$Comp
L CP C8
U 1 1 572F95EB
P 3100 1000
F 0 "C8" H 3125 1100 50  0000 L CNN
F 1 "CP" H 3125 900 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Radial_D5_L11_P2" H 3138 850 50  0001 C CNN
F 3 "" H 3100 1000 50  0000 C CNN
	1    3100 1000
	1    0    0    -1  
$EndComp
$Comp
L C C3
U 1 1 572F99EC
P 1600 3900
F 0 "C3" H 1625 4000 50  0000 L CNN
F 1 "C" H 1625 3800 50  0000 L CNN
F 2 "" H 1638 3750 50  0001 C CNN
F 3 "" H 1600 3900 50  0000 C CNN
	1    1600 3900
	-1   0    0    1   
$EndComp
$Comp
L Switch_DPST SW1
U 1 1 572F9A6E
P 2650 4800
F 0 "SW1" H 2950 4850 50  0000 C CNN
F 1 "RESET" V 2500 4800 50  0000 C CNN
F 2 "Buttons_Switches_ThroughHole:SW_TH_Tactile_Omron_B3F-10xx" H 2650 4800 50  0001 C CNN
F 3 "" H 2650 4800 50  0000 C CNN
	1    2650 4800
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 572F9B47
P 650 4250
F 0 "R1" V 730 4250 50  0000 C CNN
F 1 "R" V 650 4250 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM15mm" V 580 4250 50  0001 C CNN
F 3 "" H 650 4250 50  0000 C CNN
	1    650  4250
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR01
U 1 1 572FA7D8
P 2550 1250
F 0 "#PWR01" H 2550 1000 50  0001 C CNN
F 1 "GND" H 2550 1100 50  0000 C CNN
F 2 "" H 2550 1250 50  0000 C CNN
F 3 "" H 2550 1250 50  0000 C CNN
	1    2550 1250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR02
U 1 1 572FAE6C
P 1700 3700
F 0 "#PWR02" H 1700 3450 50  0001 C CNN
F 1 "GND" H 1700 3550 50  0000 C CNN
F 2 "" H 1700 3700 50  0000 C CNN
F 3 "" H 1700 3700 50  0000 C CNN
	1    1700 3700
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR03
U 1 1 572FB388
P 5200 3250
F 0 "#PWR03" H 5200 3000 50  0001 C CNN
F 1 "GND" H 5200 3100 50  0000 C CNN
F 2 "" H 5200 3250 50  0000 C CNN
F 3 "" H 5200 3250 50  0000 C CNN
	1    5200 3250
	1    0    0    -1  
$EndComp
$Comp
L Switch_DPST SW2
U 1 1 572FB622
P 6050 1750
F 0 "SW2" H 6350 1800 50  0000 C CNN
F 1 "BOTÃO1" V 6050 1750 50  0000 C CNN
F 2 "Buttons_Switches_ThroughHole:SW_TH_Tactile_Omron_B3F-10xx" H 6050 1750 50  0001 C CNN
F 3 "" H 6050 1750 50  0000 C CNN
	1    6050 1750
	0    1    1    0   
$EndComp
$Comp
L R R6
U 1 1 572FB781
P 6250 1050
F 0 "R6" V 6330 1050 50  0000 C CNN
F 1 "R" V 6250 1050 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM15mm" V 6180 1050 50  0001 C CNN
F 3 "" H 6250 1050 50  0000 C CNN
	1    6250 1050
	-1   0    0    1   
$EndComp
$Comp
L R R2
U 1 1 572FBA95
P 6050 1400
F 0 "R2" V 6130 1400 50  0000 C CNN
F 1 "R" V 6050 1400 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM15mm" V 5980 1400 50  0001 C CNN
F 3 "" H 6050 1400 50  0000 C CNN
	1    6050 1400
	0    -1   -1   0   
$EndComp
$Comp
L D D2
U 1 1 572FBC05
P 6050 1250
F 0 "D2" H 6050 1350 50  0000 C CNN
F 1 "D" H 6050 1150 50  0000 C CNN
F 2 "Diodes_ThroughHole:Diode_DO-35_SOD27_Horizontal_RM10" H 6050 1250 50  0001 C CNN
F 3 "" H 6050 1250 50  0000 C CNN
	1    6050 1250
	1    0    0    -1  
$EndComp
$Comp
L C C13
U 1 1 572FC0AC
P 5700 1750
F 0 "C13" H 5725 1850 50  0000 L CNN
F 1 "C" H 5725 1650 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Radial_D5_L11_P2" H 5738 1600 50  0001 C CNN
F 3 "" H 5700 1750 50  0000 C CNN
	1    5700 1750
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR04
U 1 1 572FC988
P 6050 2100
F 0 "#PWR04" H 6050 1850 50  0001 C CNN
F 1 "GND" H 6050 1950 50  0000 C CNN
F 2 "" H 6050 2100 50  0000 C CNN
F 3 "" H 6050 2100 50  0000 C CNN
	1    6050 2100
	1    0    0    -1  
$EndComp
$Comp
L R R7
U 1 1 572FCF4A
P 6250 2350
F 0 "R7" V 6330 2350 50  0000 C CNN
F 1 "R" V 6250 2350 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM15mm" V 6180 2350 50  0001 C CNN
F 3 "" H 6250 2350 50  0000 C CNN
	1    6250 2350
	-1   0    0    1   
$EndComp
$Comp
L D D3
U 1 1 572FD30D
P 6050 2550
F 0 "D3" H 6050 2650 50  0000 C CNN
F 1 "D" H 6050 2450 50  0000 C CNN
F 2 "Diodes_ThroughHole:Diode_DO-35_SOD27_Horizontal_RM10" H 6050 2550 50  0001 C CNN
F 3 "" H 6050 2550 50  0000 C CNN
	1    6050 2550
	1    0    0    -1  
$EndComp
$Comp
L R R3
U 1 1 572FD42A
P 6050 2700
F 0 "R3" V 6130 2700 50  0000 C CNN
F 1 "R" V 6050 2700 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM15mm" V 5980 2700 50  0001 C CNN
F 3 "" H 6050 2700 50  0000 C CNN
	1    6050 2700
	0    -1   -1   0   
$EndComp
$Comp
L Switch_DPST SW3
U 1 1 572FD4A2
P 6050 3100
F 0 "SW3" H 6350 3150 50  0000 C CNN
F 1 "BOTÃO2" V 6050 3100 50  0000 C CNN
F 2 "Buttons_Switches_ThroughHole:SW_TH_Tactile_Omron_B3F-10xx" H 6050 3100 50  0001 C CNN
F 3 "" H 6050 3100 50  0000 C CNN
	1    6050 3100
	0    1    1    0   
$EndComp
$Comp
L C C14
U 1 1 572FDC25
P 5700 3100
F 0 "C14" H 5725 3200 50  0000 L CNN
F 1 "C" H 5725 3000 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Radial_D5_L11_P2" H 5738 2950 50  0001 C CNN
F 3 "" H 5700 3100 50  0000 C CNN
	1    5700 3100
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR05
U 1 1 572FF778
P 6000 3450
F 0 "#PWR05" H 6000 3200 50  0001 C CNN
F 1 "GND" H 6000 3300 50  0000 C CNN
F 2 "" H 6000 3450 50  0000 C CNN
F 3 "" H 6000 3450 50  0000 C CNN
	1    6000 3450
	1    0    0    -1  
$EndComp
$Comp
L R R8
U 1 1 573003BF
P 6250 3750
F 0 "R8" V 6330 3750 50  0000 C CNN
F 1 "R" V 6250 3750 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM15mm" V 6180 3750 50  0001 C CNN
F 3 "" H 6250 3750 50  0000 C CNN
	1    6250 3750
	-1   0    0    1   
$EndComp
$Comp
L D D4
U 1 1 5730048A
P 6050 3950
F 0 "D4" H 6050 4050 50  0000 C CNN
F 1 "D" H 6050 3850 50  0000 C CNN
F 2 "Diodes_ThroughHole:Diode_DO-35_SOD27_Horizontal_RM10" H 6050 3950 50  0001 C CNN
F 3 "" H 6050 3950 50  0000 C CNN
	1    6050 3950
	1    0    0    -1  
$EndComp
$Comp
L R R4
U 1 1 57300552
P 6050 4100
F 0 "R4" V 6130 4100 50  0000 C CNN
F 1 "R" V 6050 4100 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM15mm" V 5980 4100 50  0001 C CNN
F 3 "" H 6050 4100 50  0000 C CNN
	1    6050 4100
	0    -1   -1   0   
$EndComp
$Comp
L Switch_DPST SW4
U 1 1 573005DB
P 6050 4450
F 0 "SW4" H 6350 4500 50  0000 C CNN
F 1 "BOTÃO3" V 6050 4450 50  0000 C CNN
F 2 "Buttons_Switches_ThroughHole:SW_TH_Tactile_Omron_B3F-10xx" H 6050 4450 50  0001 C CNN
F 3 "" H 6050 4450 50  0000 C CNN
	1    6050 4450
	0    1    1    0   
$EndComp
$Comp
L C C15
U 1 1 57300679
P 5700 4500
F 0 "C15" H 5725 4600 50  0000 L CNN
F 1 "C" H 5725 4400 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Radial_D5_L11_P2" H 5738 4350 50  0001 C CNN
F 3 "" H 5700 4500 50  0000 C CNN
	1    5700 4500
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR06
U 1 1 57300D5B
P 6050 4800
F 0 "#PWR06" H 6050 4550 50  0001 C CNN
F 1 "GND" H 6050 4650 50  0000 C CNN
F 2 "" H 6050 4800 50  0000 C CNN
F 3 "" H 6050 4800 50  0000 C CNN
	1    6050 4800
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR07
U 1 1 57301B11
P 3200 4850
F 0 "#PWR07" H 3200 4600 50  0001 C CNN
F 1 "GND" H 3200 4700 50  0000 C CNN
F 2 "" H 3200 4850 50  0000 C CNN
F 3 "" H 3200 4850 50  0000 C CNN
	1    3200 4850
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR08
U 1 1 573034C7
P 1450 4100
F 0 "#PWR08" H 1450 3850 50  0001 C CNN
F 1 "GND" H 1450 3950 50  0000 C CNN
F 2 "" H 1450 4100 50  0000 C CNN
F 3 "" H 1450 4100 50  0000 C CNN
	1    1450 4100
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X03 P1
U 1 1 57303FB0
P 1200 6500
F 0 "P1" H 1200 6700 50  0000 C CNN
F 1 "POT1" V 1300 6500 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03" H 1200 6500 50  0001 C CNN
F 3 "" H 1200 6500 50  0000 C CNN
	1    1200 6500
	0    -1   1    0   
$EndComp
$Comp
L CONN_01X03 P2
U 1 1 57304113
P 1750 6500
F 0 "P2" H 1750 6700 50  0000 C CNN
F 1 "POT2" V 1850 6500 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03" H 1750 6500 50  0001 C CNN
F 3 "" H 1750 6500 50  0000 C CNN
	1    1750 6500
	0    -1   1    0   
$EndComp
$Comp
L CONN_01X03 P3
U 1 1 57304196
P 2250 6500
F 0 "P3" H 2250 6700 50  0000 C CNN
F 1 "POT3" V 2350 6500 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03" H 2250 6500 50  0001 C CNN
F 3 "" H 2250 6500 50  0000 C CNN
	1    2250 6500
	0    -1   1    0   
$EndComp
$Comp
L CONN_01X03 P4
U 1 1 5730421E
P 2750 6500
F 0 "P4" H 2750 6700 50  0000 C CNN
F 1 "POT4" V 2850 6500 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03" H 2750 6500 50  0001 C CNN
F 3 "" H 2750 6500 50  0000 C CNN
	1    2750 6500
	0    -1   1    0   
$EndComp
$Comp
L CP C1
U 1 1 57304589
P 1200 6750
F 0 "C1" H 1225 6850 50  0000 L CNN
F 1 "CP" H 1225 6650 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Radial_D5_L11_P2" H 1238 6600 50  0001 C CNN
F 3 "" H 1200 6750 50  0000 C CNN
	1    1200 6750
	0    -1   -1   0   
$EndComp
$Comp
L CP C4
U 1 1 57304BB2
P 1750 6750
F 0 "C4" H 1775 6850 50  0000 L CNN
F 1 "CP" H 1775 6650 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Radial_D5_L11_P2" H 1788 6600 50  0001 C CNN
F 3 "" H 1750 6750 50  0000 C CNN
	1    1750 6750
	0    -1   -1   0   
$EndComp
$Comp
L CP C6
U 1 1 57304C35
P 2250 6750
F 0 "C6" H 2275 6850 50  0000 L CNN
F 1 "CP" H 2275 6650 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Radial_D5_L11_P2" H 2288 6600 50  0001 C CNN
F 3 "" H 2250 6750 50  0000 C CNN
	1    2250 6750
	0    -1   -1   0   
$EndComp
$Comp
L CP C7
U 1 1 57304CDD
P 2750 6750
F 0 "C7" H 2775 6850 50  0000 L CNN
F 1 "CP" H 2775 6650 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Radial_D5_L11_P2" H 2788 6600 50  0001 C CNN
F 3 "" H 2750 6750 50  0000 C CNN
	1    2750 6750
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR09
U 1 1 5730626F
P 1450 6750
F 0 "#PWR09" H 1450 6500 50  0001 C CNN
F 1 "GND" H 1450 6600 50  0000 C CNN
F 2 "" H 1450 6750 50  0000 C CNN
F 3 "" H 1450 6750 50  0000 C CNN
	1    1450 6750
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X03 P5
U 1 1 573071DC
P 3500 6500
F 0 "P5" H 3500 6700 50  0000 C CNN
F 1 "SERVO1" V 3600 6500 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03" H 3500 6500 50  0001 C CNN
F 3 "" H 3500 6500 50  0000 C CNN
	1    3500 6500
	0    -1   1    0   
$EndComp
$Comp
L CONN_01X03 P6
U 1 1 57307A24
P 4000 6500
F 0 "P6" H 4000 6700 50  0000 C CNN
F 1 "SERVO2" V 4100 6500 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03" H 4000 6500 50  0001 C CNN
F 3 "" H 4000 6500 50  0000 C CNN
	1    4000 6500
	0    -1   1    0   
$EndComp
$Comp
L CONN_01X03 P7
U 1 1 57307BDB
P 4500 6500
F 0 "P7" H 4500 6700 50  0000 C CNN
F 1 "SERV03" V 4600 6500 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03" H 4500 6500 50  0001 C CNN
F 3 "" H 4500 6500 50  0000 C CNN
	1    4500 6500
	0    -1   1    0   
$EndComp
$Comp
L CONN_01X03 P8
U 1 1 57307C6D
P 5000 6500
F 0 "P8" H 5000 6700 50  0000 C CNN
F 1 "SERVO4" V 5100 6500 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03" H 5000 6500 50  0001 C CNN
F 3 "" H 5000 6500 50  0000 C CNN
	1    5000 6500
	0    -1   1    0   
$EndComp
$Comp
L CP C9
U 1 1 573081F8
P 3500 6750
F 0 "C9" H 3525 6850 50  0000 L CNN
F 1 "CP" H 3525 6650 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Radial_D5_L11_P2" H 3538 6600 50  0001 C CNN
F 3 "" H 3500 6750 50  0000 C CNN
	1    3500 6750
	0    -1   -1   0   
$EndComp
$Comp
L CP C10
U 1 1 57308382
P 4000 6750
F 0 "C10" H 4025 6850 50  0000 L CNN
F 1 "CP" H 4025 6650 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Radial_D5_L11_P2" H 4038 6600 50  0001 C CNN
F 3 "" H 4000 6750 50  0000 C CNN
	1    4000 6750
	0    -1   -1   0   
$EndComp
$Comp
L CP C11
U 1 1 5730841D
P 4500 6750
F 0 "C11" H 4525 6850 50  0000 L CNN
F 1 "CP" H 4525 6650 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Radial_D5_L11_P2" H 4538 6600 50  0001 C CNN
F 3 "" H 4500 6750 50  0000 C CNN
	1    4500 6750
	0    -1   -1   0   
$EndComp
$Comp
L CP C12
U 1 1 573084BF
P 5000 6750
F 0 "C12" H 5025 6850 50  0000 L CNN
F 1 "CP" H 5025 6650 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Radial_D5_L11_P2" H 5038 6600 50  0001 C CNN
F 3 "" H 5000 6750 50  0000 C CNN
	1    5000 6750
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR010
U 1 1 5730873D
P 2000 6750
F 0 "#PWR010" H 2000 6500 50  0001 C CNN
F 1 "GND" H 2000 6600 50  0000 C CNN
F 2 "" H 2000 6750 50  0000 C CNN
F 3 "" H 2000 6750 50  0000 C CNN
	1    2000 6750
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR011
U 1 1 573087C9
P 2500 6750
F 0 "#PWR011" H 2500 6500 50  0001 C CNN
F 1 "GND" H 2500 6600 50  0000 C CNN
F 2 "" H 2500 6750 50  0000 C CNN
F 3 "" H 2500 6750 50  0000 C CNN
	1    2500 6750
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR012
U 1 1 57308855
P 3000 6750
F 0 "#PWR012" H 3000 6500 50  0001 C CNN
F 1 "GND" H 3000 6600 50  0000 C CNN
F 2 "" H 3000 6750 50  0000 C CNN
F 3 "" H 3000 6750 50  0000 C CNN
	1    3000 6750
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR013
U 1 1 57309911
P 3700 6800
F 0 "#PWR013" H 3700 6550 50  0001 C CNN
F 1 "GND" H 3700 6650 50  0000 C CNN
F 2 "" H 3700 6800 50  0000 C CNN
F 3 "" H 3700 6800 50  0000 C CNN
	1    3700 6800
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR014
U 1 1 573099C8
P 4200 6800
F 0 "#PWR014" H 4200 6550 50  0001 C CNN
F 1 "GND" H 4200 6650 50  0000 C CNN
F 2 "" H 4200 6800 50  0000 C CNN
F 3 "" H 4200 6800 50  0000 C CNN
	1    4200 6800
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR015
U 1 1 57309A54
P 4700 6800
F 0 "#PWR015" H 4700 6550 50  0001 C CNN
F 1 "GND" H 4700 6650 50  0000 C CNN
F 2 "" H 4700 6800 50  0000 C CNN
F 3 "" H 4700 6800 50  0000 C CNN
	1    4700 6800
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR016
U 1 1 57309B36
P 5200 6800
F 0 "#PWR016" H 5200 6550 50  0001 C CNN
F 1 "GND" H 5200 6650 50  0000 C CNN
F 2 "" H 5200 6800 50  0000 C CNN
F 3 "" H 5200 6800 50  0000 C CNN
	1    5200 6800
	1    0    0    -1  
$EndComp
Wire Wire Line
	1400 850  1600 850 
Wire Wire Line
	1900 850  2150 850 
Connection ~ 2050 850 
Wire Wire Line
	2950 850  6400 850 
Wire Wire Line
	1400 950  1450 950 
Wire Wire Line
	1450 950  1450 1050
Wire Wire Line
	1450 1050 1400 1050
Wire Wire Line
	1800 3650 1750 3650
Wire Wire Line
	1750 3650 1750 3750
Wire Wire Line
	1750 3750 1800 3750
Wire Wire Line
	1300 3350 1800 3350
Wire Wire Line
	1600 3450 1800 3450
Wire Wire Line
	1800 2250 650  2250
Wire Wire Line
	650  4400 650  5250
Wire Wire Line
	650  4800 2250 4800
Wire Wire Line
	3200 3750 3300 3750
Wire Wire Line
	3300 3750 3300 5250
Wire Wire Line
	3300 5250 650  5250
Connection ~ 650  4800
Wire Wire Line
	1450 1000 1500 1000
Wire Wire Line
	1500 1000 1500 1250
Wire Wire Line
	1500 1250 3100 1250
Connection ~ 1450 1000
Wire Wire Line
	2050 1150 2050 1250
Connection ~ 2050 1250
Wire Wire Line
	2550 1250 2550 1150
Wire Wire Line
	3100 1250 3100 1150
Connection ~ 2550 1250
Connection ~ 650  2250
Connection ~ 3100 850 
Wire Wire Line
	650  1450 650  4100
Wire Wire Line
	3300 850  3300 1450
Wire Wire Line
	3300 1450 650  1450
Wire Wire Line
	5150 850  5150 2250
Connection ~ 3300 850 
Wire Wire Line
	5150 3150 5200 3150
Wire Wire Line
	5200 3150 5200 3250
Connection ~ 5150 850 
Wire Wire Line
	5150 2450 5200 2450
Wire Wire Line
	5200 2450 5200 1400
Connection ~ 5700 1400
Wire Wire Line
	5700 1600 5700 1400
Wire Wire Line
	5850 1250 5850 1450
Connection ~ 5850 1400
Wire Wire Line
	6250 1200 6250 1450
Connection ~ 6250 1400
Wire Wire Line
	5700 1900 5700 2050
Wire Wire Line
	5700 2050 6250 2050
Connection ~ 5850 2050
Wire Wire Line
	6050 2100 6050 2050
Connection ~ 6050 2050
Wire Wire Line
	5200 1400 5900 1400
Wire Wire Line
	6200 1400 6250 1400
Wire Wire Line
	6200 1250 6250 1250
Wire Wire Line
	5900 1250 5850 1250
Connection ~ 6250 1250
Wire Wire Line
	6250 850  6250 900 
Wire Wire Line
	6250 2500 6250 2800
Wire Wire Line
	6200 2550 6250 2550
Connection ~ 6250 2550
Wire Wire Line
	6200 2700 6250 2700
Connection ~ 6250 2700
Wire Wire Line
	5850 2550 5850 2800
Wire Wire Line
	5850 2550 5900 2550
Wire Wire Line
	5400 2700 5900 2700
Connection ~ 5850 2700
Wire Wire Line
	5700 2950 5700 2700
Wire Wire Line
	5700 3250 5700 3400
Wire Wire Line
	5700 3400 6250 3400
Connection ~ 5850 3400
Wire Wire Line
	6000 3450 6000 3400
Connection ~ 6000 3400
Wire Wire Line
	6400 850  6400 3600
Wire Wire Line
	6400 2200 6250 2200
Connection ~ 6250 850 
Wire Wire Line
	5400 2700 5400 2550
Wire Wire Line
	5400 2550 5150 2550
Connection ~ 5700 2700
Wire Wire Line
	6400 3600 6250 3600
Connection ~ 6400 2200
Wire Wire Line
	6250 3900 6250 4150
Wire Wire Line
	6200 3950 6250 3950
Connection ~ 6250 3950
Wire Wire Line
	6200 4100 6250 4100
Connection ~ 6250 4100
Wire Wire Line
	5850 3950 5850 4150
Wire Wire Line
	5850 3950 5900 3950
Wire Wire Line
	5350 4100 5900 4100
Connection ~ 5850 4100
Wire Wire Line
	5700 4350 5700 4100
Wire Wire Line
	5700 4650 5700 4750
Wire Wire Line
	5700 4750 6250 4750
Connection ~ 5850 4750
Wire Wire Line
	6050 4800 6050 4750
Connection ~ 6050 4750
Wire Wire Line
	5350 4100 5350 2650
Wire Wire Line
	5350 2650 5150 2650
Connection ~ 5700 4100
Wire Wire Line
	2950 4600 3100 4600
Wire Wire Line
	3100 4600 3100 5000
Wire Wire Line
	3100 5000 2950 5000
Connection ~ 3100 4850
Wire Wire Line
	3100 4850 3200 4850
Wire Wire Line
	2350 4600 2250 4600
Wire Wire Line
	2250 4600 2250 5000
Wire Wire Line
	2250 5000 2350 5000
Connection ~ 2250 4800
Wire Wire Line
	1700 3700 1750 3700
Connection ~ 1750 3700
Wire Wire Line
	1300 4050 1600 4050
Wire Wire Line
	1450 4100 1450 4050
Connection ~ 1450 4050
Wire Wire Line
	1300 3350 1300 3750
Wire Wire Line
	1600 3450 1600 3750
Connection ~ 1600 3700
Connection ~ 1300 3700
Wire Wire Line
	1100 6300 1050 6300
Wire Wire Line
	1050 6300 1050 6750
Wire Wire Line
	1350 6750 1350 6300
Wire Wire Line
	1350 6300 1300 6300
Wire Wire Line
	1600 6300 1600 7050
Wire Wire Line
	1600 6300 1650 6300
Wire Wire Line
	1900 6750 1900 6300
Wire Wire Line
	1900 6300 1850 6300
Wire Wire Line
	2100 7050 2100 6300
Wire Wire Line
	2100 6300 2150 6300
Wire Wire Line
	2400 6750 2400 6300
Wire Wire Line
	2400 6300 2350 6300
Wire Wire Line
	2600 6300 2650 6300
Wire Wire Line
	2600 7050 2600 6300
Wire Wire Line
	2850 6300 2900 6300
Wire Wire Line
	2900 6300 2900 6750
Wire Wire Line
	1050 6600 500  6600
Wire Wire Line
	500  3900 500  7050
Wire Wire Line
	500  3900 650  3900
Connection ~ 650  3900
Connection ~ 1050 6600
Wire Wire Line
	1450 6750 1450 6650
Wire Wire Line
	1450 6650 1350 6650
Connection ~ 1350 6650
Wire Wire Line
	500  7050 6050 7050
Connection ~ 1600 6750
Connection ~ 500  6600
Connection ~ 2100 6750
Connection ~ 1600 7050
Connection ~ 2600 6750
Connection ~ 2100 7050
Wire Wire Line
	1900 6650 2000 6650
Wire Wire Line
	2000 6650 2000 6750
Connection ~ 1900 6650
Wire Wire Line
	2400 6650 2500 6650
Wire Wire Line
	2500 6650 2500 6750
Connection ~ 2400 6650
Wire Wire Line
	2900 6650 3000 6650
Wire Wire Line
	3000 6650 3000 6750
Connection ~ 2900 6650
Wire Wire Line
	4100 6300 4200 6300
Wire Wire Line
	4200 6300 4200 6800
Wire Wire Line
	4200 6750 4150 6750
Wire Wire Line
	3850 7050 3850 6600
Wire Wire Line
	3850 6600 4000 6600
Wire Wire Line
	4000 6600 4000 6300
Wire Wire Line
	4350 7050 4350 6600
Wire Wire Line
	4350 6600 4500 6600
Wire Wire Line
	4500 6600 4500 6300
Wire Wire Line
	4600 6300 4700 6300
Wire Wire Line
	4700 6300 4700 6800
Wire Wire Line
	4700 6750 4650 6750
Wire Wire Line
	4850 7050 4850 6600
Wire Wire Line
	4850 6600 5000 6600
Wire Wire Line
	5000 6600 5000 6300
Wire Wire Line
	5100 6300 5200 6300
Wire Wire Line
	5200 6300 5200 6800
Wire Wire Line
	5200 6750 5150 6750
Wire Wire Line
	3350 7050 3350 6600
Wire Wire Line
	3350 6600 3500 6600
Wire Wire Line
	3500 6600 3500 6300
Wire Wire Line
	3650 6750 3700 6750
Wire Wire Line
	3700 6300 3700 6800
Wire Wire Line
	3700 6300 3600 6300
Connection ~ 5200 6750
Connection ~ 4700 6750
Connection ~ 4200 6750
Connection ~ 3700 6750
Connection ~ 3350 6750
Connection ~ 2600 7050
Connection ~ 3850 6750
Connection ~ 3350 7050
Connection ~ 4350 6750
Connection ~ 3850 7050
Connection ~ 4850 6750
Connection ~ 4350 7050
Wire Wire Line
	3750 2250 3300 2250
Wire Wire Line
	3300 2250 3300 2450
Wire Wire Line
	3300 2450 3200 2450
Wire Wire Line
	3750 2350 3350 2350
Wire Wire Line
	3350 2350 3350 1900
Wire Wire Line
	3350 1900 700  1900
Wire Wire Line
	700  1900 700  3150
Wire Wire Line
	700  3150 1800 3150
Wire Wire Line
	3750 2450 3400 2450
Wire Wire Line
	3400 2450 3400 1850
Wire Wire Line
	3400 1850 750  1850
Wire Wire Line
	750  1850 750  3250
Wire Wire Line
	750  3250 1800 3250
Wire Wire Line
	1200 6300 1200 5350
Wire Wire Line
	1200 5350 3400 5350
Wire Wire Line
	3400 5350 3400 3150
Wire Wire Line
	3400 3150 3200 3150
Wire Wire Line
	1750 6300 1750 5450
Wire Wire Line
	1750 5450 3500 5450
Wire Wire Line
	3500 5450 3500 3250
Wire Wire Line
	3500 3250 3200 3250
Wire Wire Line
	2250 6300 2250 5550
Wire Wire Line
	2250 5550 3600 5550
Wire Wire Line
	3600 5550 3600 3350
Wire Wire Line
	3600 3350 3200 3350
Wire Wire Line
	2750 6300 2750 5650
Wire Wire Line
	2750 5650 3700 5650
Wire Wire Line
	3700 5650 3700 3450
Wire Wire Line
	3700 3450 3200 3450
Wire Wire Line
	3400 6300 3400 5750
Wire Wire Line
	3400 5750 3750 5750
Wire Wire Line
	3750 5750 3750 3100
Wire Wire Line
	3750 3100 3300 3100
Wire Wire Line
	3300 3100 3300 2550
Wire Wire Line
	3300 2550 3200 2550
Wire Wire Line
	3900 6300 3900 5800
Wire Wire Line
	3900 5800 900  5800
Wire Wire Line
	900  5800 900  2850
Wire Wire Line
	900  2850 1800 2850
Wire Wire Line
	4400 6300 4400 5900
Wire Wire Line
	4400 5900 1000 5900
Wire Wire Line
	1000 5900 1000 2950
Wire Wire Line
	1000 2950 1800 2950
Wire Wire Line
	4900 6300 4900 6000
Wire Wire Line
	4900 6000 1100 6000
Wire Wire Line
	1100 6000 1100 3050
Wire Wire Line
	1100 3050 1800 3050
$Comp
L CONN_01X08 P9
U 1 1 573105AC
P 6450 5750
F 0 "P9" H 6450 6200 50  0000 C CNN
F 1 "DISPLAY5110-NOKIA" V 6550 5750 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x08" H 6450 5750 50  0001 C CNN
F 3 "" H 6450 5750 50  0000 C CNN
	1    6450 5750
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR017
U 1 1 573111AB
P 6200 6150
F 0 "#PWR017" H 6200 5900 50  0001 C CNN
F 1 "GND" H 6200 6000 50  0000 C CNN
F 2 "" H 6200 6150 50  0000 C CNN
F 3 "" H 6200 6150 50  0000 C CNN
	1    6200 6150
	1    0    0    -1  
$EndComp
Wire Wire Line
	6200 6150 6200 6100
Wire Wire Line
	6200 6100 6250 6100
$Comp
L R R5
U 1 1 57311CCA
P 6050 6150
F 0 "R5" V 6130 6150 50  0000 C CNN
F 1 "R" V 6050 6150 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM15mm" V 5980 6150 50  0001 C CNN
F 3 "" H 6050 6150 50  0000 C CNN
	1    6050 6150
	1    0    0    -1  
$EndComp
Wire Wire Line
	6250 6000 6050 6000
Wire Wire Line
	6050 7050 6050 6300
Connection ~ 4850 7050
Wire Wire Line
	6250 5900 5900 5900
Wire Wire Line
	5900 5900 5900 7050
Connection ~ 5900 7050
Wire Wire Line
	6250 5400 5600 5400
Wire Wire Line
	5600 5400 5600 4950
Wire Wire Line
	5600 4950 5150 4950
Wire Wire Line
	5150 4950 5150 4150
Wire Wire Line
	5150 4150 4750 4150
Wire Wire Line
	4750 4150 4750 2850
Wire Wire Line
	4750 2850 3200 2850
Wire Wire Line
	6250 5500 5500 5500
Wire Wire Line
	5500 5500 5500 5000
Wire Wire Line
	5500 5000 5050 5000
Wire Wire Line
	5050 5000 5050 4250
Wire Wire Line
	5050 4250 4650 4250
Wire Wire Line
	4650 4250 4650 2950
Wire Wire Line
	4650 2950 3200 2950
Wire Wire Line
	6250 5600 5450 5600
Wire Wire Line
	5450 5600 5450 5100
Wire Wire Line
	5450 5100 4950 5100
Wire Wire Line
	4950 5100 4950 4350
Wire Wire Line
	4950 4350 4600 4350
Wire Wire Line
	4600 4350 4600 2800
Wire Wire Line
	4600 2800 3650 2800
Wire Wire Line
	3650 2800 3650 2750
Wire Wire Line
	3650 2750 3200 2750
Wire Wire Line
	3200 2650 3600 2650
Wire Wire Line
	3600 2650 3600 3050
Wire Wire Line
	3600 3050 4500 3050
Wire Wire Line
	4500 3050 4500 4450
Wire Wire Line
	4500 4450 4850 4450
Wire Wire Line
	4850 4450 4850 5250
Wire Wire Line
	4850 5250 5350 5250
Wire Wire Line
	5350 5250 5350 5700
Wire Wire Line
	5350 5700 6250 5700
Wire Wire Line
	6250 5800 4700 5800
Wire Wire Line
	4700 5800 4700 4800
Wire Wire Line
	4700 4800 4100 4800
Wire Wire Line
	4100 4800 4100 4400
Wire Wire Line
	4100 4400 1200 4400
Wire Wire Line
	1200 2750 1800 2750
Wire Wire Line
	1200 4400 1200 2750
Wire Wire Line
	1800 2350 1700 2350
Wire Wire Line
	1700 2350 1700 2250
Connection ~ 1700 2250
$EndSCHEMATC
