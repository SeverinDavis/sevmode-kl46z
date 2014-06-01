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
Sheet 13 15
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
L CONN2 J9
U 1 1 53880043
P 6550 3650
AR Path="/5387FDA2/53880043" Ref="J9"  Part="1" 
AR Path="/5387FDCE/53880043" Ref="J10"  Part="1" 
AR Path="/5387FDE3/53880043" Ref="J11"  Part="1" 
AR Path="/5387FE00/53880043" Ref="J12"  Part="1" 
AR Path="/5387FE16/53880043" Ref="J13"  Part="1" 
AR Path="/5387FE2E/53880043" Ref="J14"  Part="1" 
F 0 "J9" H 6550 3850 60  0000 C CNN
F 1 "CONN2" H 6550 3450 60  0000 C CNN
F 2 "~" H 6400 3650 60  0000 C CNN
F 3 "~" H 6400 3650 60  0000 C CNN
	1    6550 3650
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR058
U 1 1 53880055
P 6100 3850
AR Path="/5387FDA2/53880055" Ref="#PWR058"  Part="1" 
AR Path="/5387FDCE/53880055" Ref="#PWR060"  Part="1" 
AR Path="/5387FDE3/53880055" Ref="#PWR062"  Part="1" 
AR Path="/5387FE00/53880055" Ref="#PWR064"  Part="1" 
AR Path="/5387FE16/53880055" Ref="#PWR066"  Part="1" 
AR Path="/5387FE2E/53880055" Ref="#PWR068"  Part="1" 
F 0 "#PWR058" H 6100 3850 30  0001 C CNN
F 1 "GND" H 6100 3780 30  0001 C CNN
F 2 "" H 6100 3850 60  0000 C CNN
F 3 "" H 6100 3850 60  0000 C CNN
	1    6100 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	6100 3750 6100 3850
$Comp
L ___POWER_DIODE D1
U 1 1 538800B9
P 5900 3550
AR Path="/5387FDA2/538800B9" Ref="D1"  Part="1" 
AR Path="/5387FDCE/538800B9" Ref="D2"  Part="1" 
AR Path="/5387FDE3/538800B9" Ref="D3"  Part="1" 
AR Path="/5387FE00/538800B9" Ref="D4"  Part="1" 
AR Path="/5387FE16/538800B9" Ref="D5"  Part="1" 
AR Path="/5387FE2E/538800B9" Ref="D6"  Part="1" 
F 0 "D1" H 5900 3650 40  0000 C CNN
F 1 "___POWER_DIODE" H 5900 3450 40  0000 C CNN
F 2 "~" H 5900 3550 60  0000 C CNN
F 3 "~" H 5900 3550 60  0000 C CNN
	1    5900 3550
	-1   0    0    1   
$EndComp
$Comp
L __BATTERYBARLUG L5
U 1 1 5388012D
P 5350 3400
AR Path="/5387FDA2/5388012D" Ref="L5"  Part="1" 
AR Path="/5387FDCE/5388012D" Ref="L6"  Part="1" 
AR Path="/5387FDE3/5388012D" Ref="L7"  Part="1" 
AR Path="/5387FE00/5388012D" Ref="L8"  Part="1" 
AR Path="/5387FE16/5388012D" Ref="L9"  Part="1" 
AR Path="/5387FE2E/5388012D" Ref="L10"  Part="1" 
F 0 "L5" H 5500 3350 60  0000 C CNN
F 1 "__BATTERYBARLUG" H 5350 3450 20  0000 C CNN
F 2 "~" H 5350 3450 60  0000 C CNN
F 3 "~" H 5350 3450 60  0000 C CNN
	1    5350 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	5150 3550 5700 3550
Wire Wire Line
	5350 3550 5350 3450
Connection ~ 5350 3550
$Comp
L +8V #PWR067
U 1 1 538B7656
P 5150 3550
AR Path="/5387FE16/538B7656" Ref="#PWR067"  Part="1" 
AR Path="/5387FDA2/538B7656" Ref="#PWR059"  Part="1" 
AR Path="/5387FDCE/538B7656" Ref="#PWR061"  Part="1" 
AR Path="/5387FDE3/538B7656" Ref="#PWR063"  Part="1" 
AR Path="/5387FE00/538B7656" Ref="#PWR065"  Part="1" 
AR Path="/5387FE2E/538B7656" Ref="#PWR069"  Part="1" 
F 0 "#PWR059" H 5150 3520 20  0001 C CNN
F 1 "+8V" H 5150 3660 30  0000 C CNN
F 2 "" H 5150 3550 60  0000 C CNN
F 3 "" H 5150 3550 60  0000 C CNN
	1    5150 3550
	1    0    0    -1  
$EndComp
$EndSCHEMATC
