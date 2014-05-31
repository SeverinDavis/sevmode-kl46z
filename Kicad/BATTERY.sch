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
Sheet 12 14
Title ""
Date "31 may 2014"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L CONN2 J?
U 1 1 53880043
P 6550 3650
AR Path="/5387FE16/53880043" Ref="J?"  Part="1" 
AR Path="/5387FE00/53880043" Ref="J?"  Part="1" 
F 0 "J?" H 6550 3850 60  0000 C CNN
F 1 "CONN2" H 6550 3450 60  0000 C CNN
F 2 "~" H 6400 3650 60  0000 C CNN
F 3 "~" H 6400 3650 60  0000 C CNN
	1    6550 3650
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 53880055
P 6100 3850
AR Path="/5387FE16/53880055" Ref="#PWR?"  Part="1" 
AR Path="/5387FE00/53880055" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 6100 3850 30  0001 C CNN
F 1 "GND" H 6100 3780 30  0001 C CNN
F 2 "" H 6100 3850 60  0000 C CNN
F 3 "" H 6100 3850 60  0000 C CNN
	1    6100 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	6100 3750 6100 3850
$Comp
L ___POWER_DIODE D?
U 1 1 538800B9
P 5900 3550
AR Path="/5387FE16/538800B9" Ref="D?"  Part="1" 
AR Path="/5387FE00/538800B9" Ref="D?"  Part="1" 
F 0 "D?" H 5900 3650 40  0000 C CNN
F 1 "___POWER_DIODE" H 5900 3450 40  0000 C CNN
F 2 "~" H 5900 3550 60  0000 C CNN
F 3 "~" H 5900 3550 60  0000 C CNN
	1    5900 3550
	-1   0    0    1   
$EndComp
$Comp
L __BATTERYBARLUG L?
U 1 1 5388012D
P 5350 3400
AR Path="/5387FE16/5388012D" Ref="L?"  Part="1" 
AR Path="/5387FE00/5388012D" Ref="L?"  Part="1" 
F 0 "L?" H 5500 3350 60  0000 C CNN
F 1 "__BATTERYBARLUG" H 5350 3450 20  0000 C CNN
F 2 "~" H 5350 3450 60  0000 C CNN
F 3 "~" H 5350 3450 60  0000 C CNN
	1    5350 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	5700 3550 5350 3550
Wire Wire Line
	5350 3550 5350 3450
$EndSCHEMATC
