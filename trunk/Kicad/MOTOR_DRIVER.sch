EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:special
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
LIBS:___power_diode
LIBS:__batterybarlug
LIBS:__freedom_x
LIBS:__xbee-pro
LIBS:CAR
LIBS:car_v3-cache
EELAYER 27 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 5 14
Title ""
Date "1 jun 2014"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L LV8727 U?
U 1 1 53880645
P 5650 2400
F 0 "U?" V 4300 2600 60  0000 C CNN
F 1 "LV8727" V 7050 2600 60  0000 C CNN
F 2 "~" H 5650 2400 60  0000 C CNN
F 3 "~" H 5650 2400 60  0000 C CNN
	1    5650 2400
	1    0    0    -1  
$EndComp
$Comp
L SHFTREG_H U?
U 1 1 53880692
P 4250 5150
F 0 "U?" H 4250 5700 60  0000 C CNN
F 1 "SHFTREG_H" H 4250 4600 60  0000 C CNN
F 2 "~" V 4000 5250 60  0000 C CNN
F 3 "~" V 4000 5250 60  0000 C CNN
	1    4250 5150
	1    0    0    -1  
$EndComp
$Comp
L __BATTERYBARLUG L?
U 1 1 53880889
P 4650 3900
F 0 "L?" H 4800 3850 60  0000 C CNN
F 1 "__BATTERYBARLUG" H 4650 3950 20  0000 C CNN
F 2 "~" H 4650 3950 60  0000 C CNN
F 3 "~" H 4650 3950 60  0000 C CNN
	1    4650 3900
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 538A3F7A
P 6750 2950
F 0 "R?" V 6830 2950 40  0000 C CNN
F 1 "R" V 6757 2951 40  0000 C CNN
F 2 "~" V 6680 2950 30  0000 C CNN
F 3 "~" H 6750 2950 30  0000 C CNN
	1    6750 2950
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 538A3F87
P 4550 2950
F 0 "R?" V 4630 2950 40  0000 C CNN
F 1 "R" V 4557 2951 40  0000 C CNN
F 2 "~" V 4480 2950 30  0000 C CNN
F 3 "~" H 4550 2950 30  0000 C CNN
	1    4550 2950
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 538A3FA9
P 4850 4350
F 0 "C?" H 4850 4450 40  0000 L CNN
F 1 "1000u" H 4856 4265 40  0000 L CNN
F 2 "~" H 4888 4200 30  0000 C CNN
F 3 "~" H 4850 4350 60  0000 C CNN
	1    4850 4350
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 538A3FB8
P 4850 4600
F 0 "#PWR?" H 4850 4600 30  0001 C CNN
F 1 "GND" H 4850 4530 30  0001 C CNN
F 2 "" H 4850 4600 60  0000 C CNN
F 3 "" H 4850 4600 60  0000 C CNN
	1    4850 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 2700 4850 4150
Wire Wire Line
	4650 4050 6450 4050
Wire Wire Line
	6450 4050 6450 2700
Wire Wire Line
	4850 4550 4850 4600
Wire Wire Line
	4650 4050 4650 3950
Connection ~ 4850 4050
$Comp
L GND #PWR?
U 1 1 538A3FEF
P 6350 2750
F 0 "#PWR?" H 6350 2750 30  0001 C CNN
F 1 "GND" H 6350 2680 30  0001 C CNN
F 2 "" H 6350 2750 60  0000 C CNN
F 3 "" H 6350 2750 60  0000 C CNN
	1    6350 2750
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 538A3FF5
P 6650 2750
F 0 "#PWR?" H 6650 2750 30  0001 C CNN
F 1 "GND" H 6650 2680 30  0001 C CNN
F 2 "" H 6650 2750 60  0000 C CNN
F 3 "" H 6650 2750 60  0000 C CNN
	1    6650 2750
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 538A3FFB
P 4650 2750
F 0 "#PWR?" H 4650 2750 30  0001 C CNN
F 1 "GND" H 4650 2680 30  0001 C CNN
F 2 "" H 4650 2750 60  0000 C CNN
F 3 "" H 4650 2750 60  0000 C CNN
	1    4650 2750
	1    0    0    -1  
$EndComp
Wire Wire Line
	4650 2700 4650 2750
Wire Wire Line
	6350 2700 6350 2750
Wire Wire Line
	6650 2700 6650 2750
Wire Wire Line
	5050 2700 5050 4900
Wire Wire Line
	5150 2700 5150 5000
Wire Wire Line
	5250 2700 5250 5100
Wire Wire Line
	5350 2700 5350 5200
Wire Wire Line
	5450 2700 5450 5300
Text HLabel 5650 2700 3    60   UnSpc ~ 0
MOTOR_STEP
Text HLabel 5550 2700 3    60   UnSpc ~ 0
MOTOR_FR
$Comp
L GND #PWR?
U 1 1 538A4FB3
P 4550 3250
F 0 "#PWR?" H 4550 3250 30  0001 C CNN
F 1 "GND" H 4550 3180 30  0001 C CNN
F 2 "" H 4550 3250 60  0000 C CNN
F 3 "" H 4550 3250 60  0000 C CNN
	1    4550 3250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 538A4FB9
P 6750 3250
F 0 "#PWR?" H 6750 3250 30  0001 C CNN
F 1 "GND" H 6750 3180 30  0001 C CNN
F 2 "" H 6750 3250 60  0000 C CNN
F 3 "" H 6750 3250 60  0000 C CNN
	1    6750 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	4550 3200 4550 3250
Wire Wire Line
	6750 3200 6750 3250
Text GLabel 6250 2800 3    60   UnSpc ~ 0
MOTOR_VREF
Wire Wire Line
	6250 2700 6250 2800
$Comp
L C C?
U 1 1 538A522E
P 5800 3000
F 0 "C?" H 5800 3100 40  0000 L CNN
F 1 "C" H 5806 2915 40  0000 L CNN
F 2 "~" H 5838 2850 30  0000 C CNN
F 3 "~" H 5800 3000 60  0000 C CNN
	1    5800 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	5750 2700 5750 2800
Wire Wire Line
	5750 2800 5800 2800
$Comp
L GND #PWR?
U 1 1 538A5251
P 5800 3250
F 0 "#PWR?" H 5800 3250 30  0001 C CNN
F 1 "GND" H 5800 3180 30  0001 C CNN
F 2 "" H 5800 3250 60  0000 C CNN
F 3 "" H 5800 3250 60  0000 C CNN
	1    5800 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	5800 3200 5800 3250
NoConn ~ 5850 2700
NoConn ~ 5950 2700
NoConn ~ 6050 2700
NoConn ~ 6150 2700
Wire Wire Line
	5050 4900 4850 4900
Wire Wire Line
	5150 5000 4850 5000
Wire Wire Line
	5250 5100 4850 5100
Wire Wire Line
	5350 5200 4850 5200
Wire Wire Line
	5450 5300 4850 5300
NoConn ~ 4850 5400
NoConn ~ 4850 5500
$Comp
L CONN_MOTOR J?
U 1 1 538A7481
P 5850 1200
F 0 "J?" H 5850 1350 60  0000 C CNN
F 1 "CONN_MOTOR" H 6350 1200 60  0000 C CNN
F 2 "~" H 5700 1150 60  0000 C CNN
F 3 "~" H 5700 1150 60  0000 C CNN
	1    5850 1200
	1    0    0    -1  
$EndComp
Wire Wire Line
	4750 3350 4750 2700
Wire Wire Line
	4100 3350 4750 3350
Wire Wire Line
	4450 2700 4200 2700
Wire Wire Line
	4200 2700 4200 1600
Wire Wire Line
	4200 1600 5700 1600
Wire Wire Line
	4100 3350 4100 1700
Wire Wire Line
	4100 1700 5900 1700
Wire Wire Line
	5900 1700 5900 1600
Wire Wire Line
	6850 2700 7150 2700
Wire Wire Line
	7150 2700 7150 1800
Wire Wire Line
	7150 1800 5800 1800
Wire Wire Line
	5800 1800 5800 1600
Wire Wire Line
	6550 2700 6550 3350
Wire Wire Line
	6550 3350 7250 3350
Wire Wire Line
	7250 3350 7250 1600
Wire Wire Line
	7250 1600 6000 1600
Wire Wire Line
	4950 2700 4950 4800
Wire Wire Line
	4950 4800 4850 4800
$Comp
L +3.3V #PWR?
U 1 1 538A78DB
P 3650 4750
F 0 "#PWR?" H 3650 4710 30  0001 C CNN
F 1 "+3.3V" H 3650 4860 30  0000 C CNN
F 2 "" H 3650 4750 60  0000 C CNN
F 3 "" H 3650 4750 60  0000 C CNN
	1    3650 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	3650 4750 3650 4800
$Comp
L GND #PWR?
U 1 1 538A7924
P 3650 5600
F 0 "#PWR?" H 3650 5600 30  0001 C CNN
F 1 "GND" H 3650 5530 30  0001 C CNN
F 2 "" H 3650 5600 60  0000 C CNN
F 3 "" H 3650 5600 60  0000 C CNN
	1    3650 5600
	1    0    0    -1  
$EndComp
Wire Wire Line
	3650 5600 3650 5500
Text GLabel 3650 5200 0    60   UnSpc ~ 0
MOTOR_CS
Text GLabel 3100 5300 0    60   UnSpc ~ 0
SRCLR_b
Text GLabel 3650 5400 0    60   UnSpc ~ 0
OE_b
Wire Wire Line
	3650 5300 3100 5300
Text GLabel 3100 5100 0    60   UnSpc ~ 0
SCLK
Wire Wire Line
	3650 5100 3100 5100
Text HLabel 3650 4900 0    60   UnSpc ~ 0
MOTOR_SDIN
Text HLabel 3650 5000 0    60   UnSpc ~ 0
MOTOR_SDOUT
$EndSCHEMATC
