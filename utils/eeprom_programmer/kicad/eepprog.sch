EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:switches
LIBS:relays
LIBS:motors
LIBS:transistors
LIBS:conn
LIBS:linear
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
L ATMEGA16-16PU U1
U 1 1 5A74CEE7
P 3350 3850
F 0 "U1" H 2500 5730 50  0000 L BNN
F 1 "ATMEGA16-16PU" H 3800 1900 50  0000 L BNN
F 2 "DIL40" H 3350 3850 50  0001 C CIN
F 3 "" H 3350 3850 50  0001 C CNN
	1    3350 3850
	1    0    0    -1  
$EndComp
$Comp
L 28C256 U2
U 1 1 5A74D0F8
P 6000 4850
F 0 "U2" H 6200 5850 50  0000 C CNN
F 1 "28C256" H 6300 3850 50  0000 C CNN
F 2 "" H 6000 4850 50  0001 C CNN
F 3 "" H 6000 4850 50  0001 C CNN
	1    6000 4850
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x04 UART1
U 1 1 5A74DDB8
P 1950 6250
F 0 "UART1" H 1950 6450 50  0000 C CNN
F 1 "Conn_01x04" H 1900 5950 50  0001 C CNN
F 2 "" H 1950 6250 50  0001 C CNN
F 3 "" H 1950 6250 50  0001 C CNN
	1    1950 6250
	-1   0    0    1   
$EndComp
$Comp
L VCC #PWR01
U 1 1 5A74E1AA
P 3200 1600
F 0 "#PWR01" H 3200 1450 50  0001 C CNN
F 1 "VCC" H 3200 1750 50  0000 C CNN
F 2 "" H 3200 1600 50  0001 C CNN
F 3 "" H 3200 1600 50  0001 C CNN
	1    3200 1600
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 5A74E368
P 2750 1750
F 0 "R1" V 2830 1750 50  0000 C CNN
F 1 "10k" V 2750 1750 50  0000 C CNN
F 2 "" V 2680 1750 50  0001 C CNN
F 3 "" H 2750 1750 50  0001 C CNN
	1    2750 1750
	0    1    1    0   
$EndComp
$Comp
L Crystal Q1
U 1 1 5A74E8D7
P 2150 2750
F 0 "Q1" H 2150 2900 50  0000 C CNN
F 1 "16MHz" H 2150 2600 50  0000 C CNN
F 2 "" H 2150 2750 50  0001 C CNN
F 3 "" H 2150 2750 50  0001 C CNN
	1    2150 2750
	0    1    1    0   
$EndComp
$Comp
L C C2
U 1 1 5A74E91C
P 1800 2550
F 0 "C2" H 1825 2650 50  0000 L CNN
F 1 "22pF" H 1825 2450 50  0000 L CNN
F 2 "" H 1838 2400 50  0001 C CNN
F 3 "" H 1800 2550 50  0001 C CNN
	1    1800 2550
	0    1    1    0   
$EndComp
$Comp
L C C1
U 1 1 5A74E959
P 1800 2950
F 0 "C1" H 1825 3050 50  0000 L CNN
F 1 "22pF" H 1825 2850 50  0000 L CNN
F 2 "" H 1838 2800 50  0001 C CNN
F 3 "" H 1800 2950 50  0001 C CNN
	1    1800 2950
	0    1    1    0   
$EndComp
$Comp
L GND #PWR02
U 1 1 5A74ED50
P 1400 3600
F 0 "#PWR02" H 1400 3350 50  0001 C CNN
F 1 "GND" H 1400 3450 50  0000 C CNN
F 2 "" H 1400 3600 50  0001 C CNN
F 3 "" H 1400 3600 50  0001 C CNN
	1    1400 3600
	1    0    0    -1  
$EndComp
$Comp
L SW_Push SW_RESET1
U 1 1 5A74EDF7
P 1900 2150
F 0 "SW_RESET1" H 1700 2050 50  0000 L CNN
F 1 "SW_Push" H 1900 2090 50  0001 C CNN
F 2 "" H 1900 2350 50  0001 C CNN
F 3 "" H 1900 2350 50  0001 C CNN
	1    1900 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	4350 3950 5300 3950
Wire Wire Line
	4350 4050 5300 4050
Wire Wire Line
	4350 4150 5300 4150
Wire Wire Line
	4350 4250 5300 4250
Wire Wire Line
	4350 4350 5300 4350
Wire Wire Line
	4350 4450 5300 4450
Wire Wire Line
	4350 4550 5300 4550
Wire Wire Line
	4350 4650 5300 4650
Wire Wire Line
	4350 3050 5150 3050
Wire Wire Line
	5150 3050 5150 4750
Wire Wire Line
	5150 4750 5300 4750
Wire Wire Line
	4350 3150 5100 3150
Wire Wire Line
	5100 3150 5100 4850
Wire Wire Line
	5100 4850 5300 4850
Wire Wire Line
	5300 4950 5050 4950
Wire Wire Line
	5050 4950 5050 3250
Wire Wire Line
	5050 3250 4350 3250
Wire Wire Line
	4350 3350 5000 3350
Wire Wire Line
	5000 3350 5000 5050
Wire Wire Line
	5000 5050 5300 5050
Wire Wire Line
	5300 5150 4950 5150
Wire Wire Line
	4950 5150 4950 3450
Wire Wire Line
	4950 3450 4350 3450
Wire Wire Line
	4350 3550 4900 3550
Wire Wire Line
	4900 3550 4900 5250
Wire Wire Line
	4900 5250 5300 5250
Wire Wire Line
	5300 5350 4850 5350
Wire Wire Line
	4850 5350 4850 3650
Wire Wire Line
	4850 3650 4350 3650
Wire Wire Line
	4350 2850 6800 2850
Wire Wire Line
	6800 2850 6800 4650
Wire Wire Line
	6800 4650 6700 4650
Wire Wire Line
	6700 4550 6850 4550
Wire Wire Line
	6850 4550 6850 2750
Wire Wire Line
	6850 2750 4350 2750
Wire Wire Line
	4350 2650 6900 2650
Wire Wire Line
	6900 2650 6900 4450
Wire Wire Line
	6900 4450 6700 4450
Wire Wire Line
	6700 4350 6950 4350
Wire Wire Line
	6950 4350 6950 2550
Wire Wire Line
	6950 2550 4350 2550
Wire Wire Line
	4350 2450 7000 2450
Wire Wire Line
	7000 2450 7000 4250
Wire Wire Line
	7000 4250 6700 4250
Wire Wire Line
	6700 4150 7050 4150
Wire Wire Line
	7050 4150 7050 2350
Wire Wire Line
	7050 2350 4350 2350
Wire Wire Line
	4350 2250 7100 2250
Wire Wire Line
	7100 2250 7100 4050
Wire Wire Line
	7100 4050 6700 4050
Wire Wire Line
	6700 3950 7150 3950
Wire Wire Line
	7150 3950 7150 2150
Wire Wire Line
	7150 2150 4350 2150
Wire Wire Line
	4350 5050 4750 5050
Wire Wire Line
	4750 5050 4750 5750
Wire Wire Line
	4750 5750 5300 5750
Wire Wire Line
	4350 5150 4700 5150
Wire Wire Line
	4700 5150 4700 5650
Wire Wire Line
	4700 5650 5300 5650
Wire Wire Line
	5300 5550 4650 5550
Wire Wire Line
	4650 5550 4650 5250
Wire Wire Line
	4650 5250 4350 5250
Wire Wire Line
	3200 1600 3200 1850
Wire Wire Line
	2900 1750 3500 1750
Wire Wire Line
	3500 1750 3500 1850
Connection ~ 3200 1750
Wire Wire Line
	2600 1750 2250 1750
Wire Wire Line
	2250 1300 2250 2150
Wire Wire Line
	2100 2150 2350 2150
Wire Wire Line
	1950 2550 2350 2550
Wire Wire Line
	2150 2550 2150 2600
Connection ~ 2150 2550
Wire Wire Line
	1950 2950 2350 2950
Wire Wire Line
	2150 2900 2150 2950
Connection ~ 2150 2950
Wire Wire Line
	1350 3350 2350 3350
Connection ~ 1400 3350
Connection ~ 2250 2150
Wire Wire Line
	1650 2550 1600 2550
Wire Wire Line
	1600 2550 1600 2950
Wire Wire Line
	1600 2950 1650 2950
Wire Wire Line
	1600 2750 1400 2750
Wire Wire Line
	1400 2150 1400 3600
Connection ~ 1600 2750
Wire Wire Line
	1700 2150 1400 2150
Connection ~ 1400 2750
Wire Wire Line
	3300 5850 3300 6450
Wire Wire Line
	3300 6350 2150 6350
Wire Wire Line
	3400 5850 3400 5900
Wire Wire Line
	3400 5900 3300 5900
Connection ~ 3300 5900
Wire Wire Line
	4350 4850 4550 4850
Wire Wire Line
	4550 4850 4550 6050
Wire Wire Line
	4550 6050 2150 6050
Wire Wire Line
	4350 4950 4500 4950
Wire Wire Line
	4500 4950 4500 6150
Wire Wire Line
	4500 6150 2150 6150
$Comp
L VCC #PWR03
U 1 1 5A75113A
P 2300 5550
F 0 "#PWR03" H 2300 5400 50  0001 C CNN
F 1 "VCC" H 2300 5700 50  0000 C CNN
F 2 "" H 2300 5550 50  0001 C CNN
F 3 "" H 2300 5550 50  0001 C CNN
	1    2300 5550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR04
U 1 1 5A751166
P 3300 6450
F 0 "#PWR04" H 3300 6200 50  0001 C CNN
F 1 "GND" H 3300 6300 50  0000 C CNN
F 2 "" H 3300 6450 50  0001 C CNN
F 3 "" H 3300 6450 50  0001 C CNN
	1    3300 6450
	1    0    0    -1  
$EndComp
Connection ~ 3300 6350
Wire Wire Line
	2300 5550 2300 6250
Wire Wire Line
	2300 6250 2150 6250
$Comp
L Conn_02x03_Odd_Even ICSP1
U 1 1 5A75183A
P 5150 1200
F 0 "ICSP1" H 5200 1400 50  0000 C CNN
F 1 "Conn_02x03_Odd_Even" H 5200 1000 50  0001 C CNN
F 2 "" H 5150 1200 50  0001 C CNN
F 3 "" H 5150 1200 50  0001 C CNN
	1    5150 1200
	1    0    0    -1  
$EndComp
Wire Wire Line
	4950 1100 4600 1100
Wire Wire Line
	4600 1100 4600 3650
Connection ~ 4600 3650
Wire Wire Line
	4950 1200 4650 1200
Wire Wire Line
	4650 1200 4650 3750
Wire Wire Line
	4650 3750 4350 3750
Wire Wire Line
	4700 3550 4700 1400
Wire Wire Line
	4700 1400 5500 1400
Wire Wire Line
	5500 1400 5500 1200
Wire Wire Line
	5500 1200 5450 1200
Connection ~ 4700 3550
$Comp
L GND #PWR05
U 1 1 5A7521B1
P 5650 1500
F 0 "#PWR05" H 5650 1250 50  0001 C CNN
F 1 "GND" H 5650 1350 50  0000 C CNN
F 2 "" H 5650 1500 50  0001 C CNN
F 3 "" H 5650 1500 50  0001 C CNN
	1    5650 1500
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR06
U 1 1 5A7521E0
P 5650 950
F 0 "#PWR06" H 5650 800 50  0001 C CNN
F 1 "VCC" H 5650 1100 50  0000 C CNN
F 2 "" H 5650 950 50  0001 C CNN
F 3 "" H 5650 950 50  0001 C CNN
	1    5650 950 
	1    0    0    -1  
$EndComp
Wire Wire Line
	5450 1300 5650 1300
Wire Wire Line
	5650 1300 5650 1500
Wire Wire Line
	5450 1100 5650 1100
Wire Wire Line
	5650 1100 5650 950 
Wire Wire Line
	4950 1300 2250 1300
Connection ~ 2250 1750
NoConn ~ 4350 5350
NoConn ~ 4350 5450
NoConn ~ 4350 5550
$Comp
L PWR_FLAG #FLG07
U 1 1 5A755DD8
P 2250 5800
F 0 "#FLG07" H 2250 5875 50  0001 C CNN
F 1 "PWR_FLAG" H 2250 5950 50  0000 C CNN
F 2 "" H 2250 5800 50  0001 C CNN
F 3 "" H 2250 5800 50  0001 C CNN
	1    2250 5800
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2250 5800 2300 5800
Connection ~ 2300 5800
$Comp
L VCC #PWR08
U 1 1 5A756502
P 6000 3600
F 0 "#PWR08" H 6000 3450 50  0001 C CNN
F 1 "VCC" H 6000 3750 50  0000 C CNN
F 2 "" H 6000 3600 50  0001 C CNN
F 3 "" H 6000 3600 50  0001 C CNN
	1    6000 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	6000 3600 6000 3850
$Comp
L GND #PWR09
U 1 1 5A756709
P 6000 6050
F 0 "#PWR09" H 6000 5800 50  0001 C CNN
F 1 "GND" H 6000 5900 50  0000 C CNN
F 2 "" H 6000 6050 50  0001 C CNN
F 3 "" H 6000 6050 50  0001 C CNN
	1    6000 6050
	1    0    0    -1  
$EndComp
Wire Wire Line
	6000 5850 6000 6050
$Comp
L PWR_FLAG #FLG010
U 1 1 5A7568D4
P 1350 3350
F 0 "#FLG010" H 1350 3425 50  0001 C CNN
F 1 "PWR_FLAG" H 1350 3500 50  0000 C CNN
F 2 "" H 1350 3350 50  0001 C CNN
F 3 "" H 1350 3350 50  0001 C CNN
	1    1350 3350
	0    -1   -1   0   
$EndComp
$EndSCHEMATC