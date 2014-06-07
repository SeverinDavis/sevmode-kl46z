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
Sheet 5 15
Title ""
Date "7 jun 2014"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L __XBEE-PRO M1
U 1 1 538988F6
P 5750 3700
F 0 "M1" H 5450 4850 50  0000 L BNN
F 1 "__XBEE-PRO" H 5550 2750 50  0000 L BNN
F 2 "xbee_r1-XBEE-PRO" H 5850 2900 50  0001 C CNN
F 3 "~" H 5750 3700 60  0000 C CNN
	1    5750 3700
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR030
U 1 1 5389890A
P 4950 4450
F 0 "#PWR030" H 4950 4450 30  0001 C CNN
F 1 "GND" H 4950 4380 30  0001 C CNN
F 2 "" H 4950 4450 60  0000 C CNN
F 3 "" H 4950 4450 60  0000 C CNN
	1    4950 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	4950 4450 4950 4350
$Comp
L +3.3V #PWR031
U 1 1 5389891E
P 4950 2950
F 0 "#PWR031" H 4950 2910 30  0001 C CNN
F 1 "+3.3V" H 4950 3060 30  0000 C CNN
F 2 "" H 4950 2950 60  0000 C CNN
F 3 "" H 4950 2950 60  0000 C CNN
	1    4950 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	4950 2950 4950 3000
NoConn ~ 6650 3000
NoConn ~ 6650 3150
NoConn ~ 6650 3300
NoConn ~ 6650 3450
NoConn ~ 6650 3750
NoConn ~ 6650 3600
$Comp
L +3.3V #PWR032
U 1 1 53898952
P 6750 3850
F 0 "#PWR032" H 6750 3810 30  0001 C CNN
F 1 "+3.3V" H 6750 3960 30  0000 C CNN
F 2 "" H 6750 3850 60  0000 C CNN
F 3 "" H 6750 3850 60  0000 C CNN
	1    6750 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	6750 3850 6750 3900
Wire Wire Line
	6750 3900 6650 3900
NoConn ~ 4950 3750
NoConn ~ 4950 3900
NoConn ~ 4950 3450
NoConn ~ 6650 4200
NoConn ~ 6650 4350
NoConn ~ 4950 4050
NoConn ~ 4950 4200
Text HLabel 6700 4050 2    60   UnSpc ~ 0
ON
Text HLabel 4900 3600 0    60   UnSpc ~ 0
RESET_b
Text HLabel 4900 3150 0    60   UnSpc ~ 0
RX
Text HLabel 4900 3300 0    60   UnSpc ~ 0
TX
Wire Wire Line
	4900 3300 4950 3300
Wire Wire Line
	4900 3600 4950 3600
Wire Wire Line
	6700 4050 6650 4050
Wire Wire Line
	4900 3150 4950 3150
$EndSCHEMATC
