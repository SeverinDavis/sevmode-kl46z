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
Sheet 1 15
Title ""
Date "7 jun 2014"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Sheet
S 3050 1850 1550 600 
U 5387F799
F0 "MOTOR0" 50
F1 "MOTOR_DRIVER.sch" 50
F2 "STEP" U L 3050 2300 60 
F3 "FR" U L 3050 2400 60 
F4 "SDIN" U L 3050 2100 60 
F5 "SDOUT" U L 3050 2200 60 
F6 "VREF" U R 4600 1950 60 
F7 "SCLK" U L 3050 1900 60 
F8 "CS" U L 3050 2000 60 
F9 "SRCLR_b" U R 4600 2050 60 
F10 "OE_b" U R 4600 2150 60 
$EndSheet
$Sheet
S 9100 4100 900  400 
U 5387F9D3
F0 "LED_DUAL_DRIVER1" 50
F1 "LED_DUAL_DRIVER.sch" 50
F2 "LED_SDOUT" U L 9100 4450 60 
F3 "LED_SDIN" U L 9100 4350 60 
F4 "SCLK" U L 9100 4150 60 
F5 "CS" U L 9100 4250 60 
F6 "SRCLR_b" U R 10000 4200 60 
F7 "OE_b" U R 10000 4300 60 
$EndSheet
$Sheet
S 3000 5600 850  550 
U 5387FD7B
F0 "XBEE0" 50
F1 "XBEE.sch" 50
F2 "ON" U L 3000 5950 60 
F3 "RESET_b" U L 3000 6050 60 
F4 "RX" U L 3000 5800 60 
F5 "TX" U L 3000 5700 60 
$EndSheet
$Sheet
S 2450 600  650  200 
U 5387FDA2
F0 "BATTERY0" 50
F1 "BATTERY.sch" 50
$EndSheet
$Sheet
S 3200 600  650  200 
U 5387FDCE
F0 "BATTERY1" 50
F1 "BATTERY.sch" 50
$EndSheet
$Sheet
S 2450 1000 650  200 
U 5387FDE3
F0 "BATTERY2" 50
F1 "BATTERY.sch" 50
$EndSheet
$Sheet
S 3200 1000 650  200 
U 5387FE00
F0 "BATTERY3" 50
F1 "BATTERY.sch" 50
$EndSheet
$Sheet
S 3950 600  600  200 
U 5387FE16
F0 "BATTERY4" 50
F1 "BATTERY.sch" 50
$EndSheet
$Sheet
S 3950 1000 600  200 
U 5387FE2E
F0 "BATTERY5" 50
F1 "BATTERY.sch" 50
$EndSheet
$Sheet
S 5500 4100 1650 2900
U 538A82BA
F0 "KL46Z_DUAL" 50
F1 "KL46Z_DUAL.sch" 50
$EndSheet
$Comp
L PWR_FLAG #FLG01
U 1 1 538B120B
P 1200 700
F 0 "#FLG01" H 1200 795 30  0001 C CNN
F 1 "PWR_FLAG" H 1200 880 30  0000 C CNN
F 2 "" H 1200 700 60  0000 C CNN
F 3 "" H 1200 700 60  0000 C CNN
	1    1200 700 
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR02
U 1 1 538B1213
P 1200 750
F 0 "#PWR02" H 1200 750 30  0001 C CNN
F 1 "GND" H 1200 680 30  0001 C CNN
F 2 "" H 1200 750 60  0000 C CNN
F 3 "" H 1200 750 60  0000 C CNN
	1    1200 750 
	1    0    0    -1  
$EndComp
NoConn ~ 3000 5700
NoConn ~ 3000 5800
NoConn ~ 3000 5950
NoConn ~ 3000 6050
$Comp
L +3.3V #PWR03
U 1 1 538B11FE
P 600 700
F 0 "#PWR03" H 600 660 30  0001 C CNN
F 1 "+3.3V" H 600 810 30  0000 C CNN
F 2 "" H 600 700 60  0000 C CNN
F 3 "" H 600 700 60  0000 C CNN
	1    600  700 
	-1   0    0    1   
$EndComp
$Comp
L PWR_FLAG #FLG04
U 1 1 538B0DF3
P 600 700
F 0 "#FLG04" H 600 795 30  0001 C CNN
F 1 "PWR_FLAG" H 600 880 30  0000 C CNN
F 2 "" H 600 700 60  0000 C CNN
F 3 "" H 600 700 60  0000 C CNN
	1    600  700 
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG05
U 1 1 538B7E12
P 900 700
F 0 "#FLG05" H 900 795 30  0001 C CNN
F 1 "PWR_FLAG" H 900 880 30  0000 C CNN
F 2 "" H 900 700 60  0000 C CNN
F 3 "" H 900 700 60  0000 C CNN
	1    900  700 
	1    0    0    -1  
$EndComp
$Comp
L +8V #PWR06
U 1 1 538B7E1A
P 900 700
F 0 "#PWR06" H 900 670 20  0001 C CNN
F 1 "+8V" H 900 810 30  0000 C CNN
F 2 "" H 900 700 60  0000 C CNN
F 3 "" H 900 700 60  0000 C CNN
	1    900  700 
	-1   0    0    1   
$EndComp
Text Label 4750 2150 0    60   ~ 0
MOTOR_OE_b
Text Label 4750 2050 0    60   ~ 0
MOTOR_SRCLR_b
Text Label 4750 1950 0    60   ~ 0
MOTOR_VREF
Text Label 2900 2300 2    60   ~ 0
MOTOR0_STEP
Text Label 2900 2400 2    60   ~ 0
MOTOR0_FR
Text Label 2900 2100 2    60   ~ 0
SDATA
Text Label 2900 2000 2    60   ~ 0
MOTOR_CS
Text Label 2900 1900 2    60   ~ 0
SCLK
Text Label 4750 2950 0    60   ~ 0
MOTOR_OE_b
Text Label 4750 2850 0    60   ~ 0
MOTOR_SRCLR_b
Text Label 4750 2750 0    60   ~ 0
MOTOR_VREF
Text Label 2900 3100 2    60   ~ 0
MOTOR1_STEP
Text Label 2900 3200 2    60   ~ 0
MOTOR1_FR
Text Label 2900 2800 2    60   ~ 0
MOTOR_CS
Text Label 2900 2700 2    60   ~ 0
SCLK
Text Label 4750 3750 0    60   ~ 0
MOTOR_OE_b
Text Label 4750 3650 0    60   ~ 0
MOTOR_SRCLR_b
Text Label 4750 3550 0    60   ~ 0
MOTOR_VREF
Text Label 2900 3900 2    60   ~ 0
MOTOR1_STEP
Text Label 2900 4000 2    60   ~ 0
MOTOR1_FR
Text Label 2900 3600 2    60   ~ 0
MOTOR_CS
Text Label 2900 3500 2    60   ~ 0
SCLK
Text Label 4750 4550 0    60   ~ 0
MOTOR_OE_b
Text Label 4750 4450 0    60   ~ 0
MOTOR_SRCLR_b
Text Label 4750 4350 0    60   ~ 0
MOTOR_VREF
Text Label 2900 4700 2    60   ~ 0
MOTOR1_STEP
Text Label 2900 4800 2    60   ~ 0
MOTOR1_FR
Text Label 2900 4400 2    60   ~ 0
MOTOR_CS
Text Label 2900 4300 2    60   ~ 0
SCLK
NoConn ~ 3050 4600
$Sheet
S 3050 2650 1550 600 
U 5393B696
F0 "MOTOR1" 50
F1 "MOTOR_DRIVER.sch" 50
F2 "STEP" U L 3050 3100 60 
F3 "FR" U L 3050 3200 60 
F4 "SDIN" U L 3050 2900 60 
F5 "SDOUT" U L 3050 3000 60 
F6 "VREF" U R 4600 2750 60 
F7 "SCLK" U L 3050 2700 60 
F8 "CS" U L 3050 2800 60 
F9 "SRCLR_b" U R 4600 2850 60 
F10 "OE_b" U R 4600 2950 60 
$EndSheet
$Sheet
S 3050 3450 1550 600 
U 5393E24C
F0 "MOTOR2" 50
F1 "MOTOR_DRIVER.sch" 50
F2 "STEP" U L 3050 3900 60 
F3 "FR" U L 3050 4000 60 
F4 "SDIN" U L 3050 3700 60 
F5 "SDOUT" U L 3050 3800 60 
F6 "VREF" U R 4600 3550 60 
F7 "SCLK" U L 3050 3500 60 
F8 "CS" U L 3050 3600 60 
F9 "SRCLR_b" U R 4600 3650 60 
F10 "OE_b" U R 4600 3750 60 
$EndSheet
$Sheet
S 3050 4250 1550 600 
U 5393E5B4
F0 "MOTOR3" 50
F1 "MOTOR_DRIVER.sch" 50
F2 "STEP" U L 3050 4700 60 
F3 "FR" U L 3050 4800 60 
F4 "SDIN" U L 3050 4500 60 
F5 "SDOUT" U L 3050 4600 60 
F6 "VREF" U R 4600 4350 60 
F7 "SCLK" U L 3050 4300 60 
F8 "CS" U L 3050 4400 60 
F9 "SRCLR_b" U R 4600 4450 60 
F10 "OE_b" U R 4600 4550 60 
$EndSheet
$Sheet
S 9100 3400 900  400 
U 539441D7
F0 "LED_DUAL_DRIVER0" 50
F1 "LED_DUAL_DRIVER.sch" 50
F2 "LED_SDOUT" U L 9100 3750 60 
F3 "LED_SDIN" U L 9100 3650 60 
F4 "SCLK" U L 9100 3450 60 
F5 "CS" U L 9100 3550 60 
F6 "SRCLR_b" U R 10000 3500 60 
F7 "OE_b" U R 10000 3600 60 
$EndSheet
Text Label 8950 3450 2    60   ~ 0
SCLK
Text Label 8950 3650 2    60   ~ 0
SDATA
Text Label 8950 4150 2    60   ~ 0
SCLK
Text Label 8950 3550 2    60   ~ 0
LED_CS
Text Label 8950 4250 2    60   ~ 0
LED_CS
NoConn ~ 9100 4450
Text Label 10150 3500 0    60   ~ 0
LED_SRCLR_b
Text Label 10150 3600 0    60   ~ 0
LED_OE_b
Text Label 10150 4200 0    60   ~ 0
LED_SRCLR_b
Text Label 10150 4300 0    60   ~ 0
LED_OE_b
Wire Wire Line
	1200 700  1200 750 
Wire Wire Line
	4600 1950 4750 1950
Wire Wire Line
	4600 2050 4750 2050
Wire Wire Line
	4600 2150 4750 2150
Wire Wire Line
	3050 1900 2900 1900
Wire Wire Line
	2900 2000 3050 2000
Wire Wire Line
	2900 2100 3050 2100
Wire Wire Line
	2900 2300 3050 2300
Wire Wire Line
	2900 2400 3050 2400
Wire Wire Line
	4600 2750 4750 2750
Wire Wire Line
	4600 2850 4750 2850
Wire Wire Line
	4600 2950 4750 2950
Wire Wire Line
	3050 2700 2900 2700
Wire Wire Line
	2900 2800 3050 2800
Wire Wire Line
	2100 2900 3050 2900
Wire Wire Line
	2900 3100 3050 3100
Wire Wire Line
	2900 3200 3050 3200
Wire Wire Line
	4600 3550 4750 3550
Wire Wire Line
	4600 3650 4750 3650
Wire Wire Line
	4600 3750 4750 3750
Wire Wire Line
	3050 3500 2900 3500
Wire Wire Line
	2900 3600 3050 3600
Wire Wire Line
	2100 3700 3050 3700
Wire Wire Line
	2900 3900 3050 3900
Wire Wire Line
	2900 4000 3050 4000
Wire Wire Line
	4600 4350 4750 4350
Wire Wire Line
	4600 4450 4750 4450
Wire Wire Line
	4600 4550 4750 4550
Wire Wire Line
	3050 4300 2900 4300
Wire Wire Line
	2900 4400 3050 4400
Wire Wire Line
	2100 4500 3050 4500
Wire Wire Line
	2900 4700 3050 4700
Wire Wire Line
	2900 4800 3050 4800
Wire Wire Line
	3050 2200 2100 2200
Wire Wire Line
	2100 2200 2100 2900
Wire Wire Line
	3050 3000 2100 3000
Wire Wire Line
	2100 3000 2100 3700
Wire Wire Line
	3050 3800 2100 3800
Wire Wire Line
	2100 3800 2100 4500
Wire Wire Line
	9100 3750 8450 3750
Wire Wire Line
	8450 3750 8450 4350
Wire Wire Line
	8450 4350 9100 4350
Wire Wire Line
	8950 4150 9100 4150
Wire Wire Line
	8950 4250 9100 4250
Wire Wire Line
	8950 3450 9100 3450
Wire Wire Line
	8950 3550 9100 3550
Wire Wire Line
	8950 3650 9100 3650
Wire Wire Line
	10000 3500 10150 3500
Wire Wire Line
	10000 3600 10150 3600
Wire Wire Line
	10000 4200 10150 4200
Wire Wire Line
	10000 4300 10150 4300
Text Label 2850 5700 2    60   ~ 0
XBEE_TX
Text Label 2850 5800 2    60   ~ 0
XBEE_RX
Text Label 2850 5950 2    60   ~ 0
XBEE_ON
Text Label 2850 6050 2    60   ~ 0
XBEE_RESET_b
$EndSCHEMATC
