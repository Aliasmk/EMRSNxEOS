EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr USLetter 11000 8500
encoding utf-8
Sheet 3 9
Title "EMRSNxEOS Console"
Date ""
Rev "A"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Device:Rotary_Encoder_Switch SW?
U 1 1 5F69EEA5
P 5950 3800
AR Path="/5F4A9E86/5F69EEA5" Ref="SW?"  Part="1" 
AR Path="/5F4A9E86/5F640632/5F69EEA5" Ref="SW?"  Part="1" 
AR Path="/5F4A9E86/5F64E1A9/5F69EEA5" Ref="SW7"  Part="1" 
AR Path="/5F4A9E86/5F64E559/5F69EEA5" Ref="SW8"  Part="1" 
AR Path="/5F4A9E86/5F64E7E9/5F69EEA5" Ref="SW9"  Part="1" 
AR Path="/5F4A9E86/5F6DDF02/5F69EEA5" Ref="SW10"  Part="1" 
AR Path="/5F4A9E86/5F60074F/5F69EEA5" Ref="SW?"  Part="1" 
F 0 "SW7" H 5950 4050 50  0000 C CNN
F 1 "Rotary_Encoder_Switch" H 5750 3550 50  0000 C CNN
F 2 "EMRSNxEOS:PEC12RHeader" H 5800 3960 50  0001 C CNN
F 3 "~" H 5950 4060 50  0001 C CNN
F 4 "PEC11R-4220F-S0012-ND" H 5950 3800 50  0001 C CNN "Digikey"
F 5 "PEC11R-4220F-S0012" H 5950 3800 50  0001 C CNN "MPN"
F 6 "Bourns Inc." H 5950 3800 50  0001 C CNN "Manufacturer"
	1    5950 3800
	1    0    0    -1  
$EndComp
$Comp
L Device:C C8
U 1 1 5F6A38A0
P 6750 3950
AR Path="/5F4A9E86/5F64E1A9/5F6A38A0" Ref="C8"  Part="1" 
AR Path="/5F4A9E86/5F640632/5F6A38A0" Ref="C?"  Part="1" 
AR Path="/5F4A9E86/5F64E559/5F6A38A0" Ref="C11"  Part="1" 
AR Path="/5F4A9E86/5F64E7E9/5F6A38A0" Ref="C14"  Part="1" 
AR Path="/5F4A9E86/5F6DDF02/5F6A38A0" Ref="C17"  Part="1" 
AR Path="/5F4A9E86/5F60074F/5F6A38A0" Ref="C?"  Part="1" 
F 0 "C8" H 6865 3996 50  0000 L CNN
F 1 "10n" H 6865 3905 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 6788 3800 50  0001 C CNN
F 3 "~" H 6750 3950 50  0001 C CNN
F 4 "311-1677-1-ND" H 6750 3950 50  0001 C CNN "Digikey"
F 5 "CC0402JRX7R8BB103" H 6750 3950 50  0001 C CNN "MPN"
F 6 "Yageo" H 6750 3950 50  0001 C CNN "Manufacturer"
	1    6750 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	6650 3700 6750 3700
Wire Wire Line
	6750 3700 6750 3800
Wire Wire Line
	6750 4100 6750 4400
$Comp
L power:GND #PWR?
U 1 1 5F6A66A6
P 6750 4400
AR Path="/5F4A9E86/5F64A564" Ref="#PWR?"  Part="1" 
AR Path="/5F4A9E86/5F640632/5F64A564" Ref="#PWR?"  Part="1" 
AR Path="/5F4A9E86/5F640632/5F6A66A6" Ref="#PWR?"  Part="1" 
AR Path="/5F4A9E86/5F64E1A9/5F6A66A6" Ref="#PWR035"  Part="1" 
AR Path="/5F4A9E86/5F64E559/5F6A66A6" Ref="#PWR042"  Part="1" 
AR Path="/5F4A9E86/5F64E7E9/5F6A66A6" Ref="#PWR049"  Part="1" 
AR Path="/5F4A9E86/5F6DDF02/5F6A66A6" Ref="#PWR056"  Part="1" 
AR Path="/5F4A9E86/5F60074F/5F6A66A6" Ref="#PWR?"  Part="1" 
F 0 "#PWR035" H 6750 4150 50  0001 C CNN
F 1 "GND" H 6755 4227 50  0000 C CNN
F 2 "" H 6750 4400 50  0001 C CNN
F 3 "" H 6750 4400 50  0001 C CNN
	1    6750 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	6250 3900 6300 3900
Wire Wire Line
	6300 3900 6300 4400
$Comp
L power:GND #PWR?
U 1 1 5F6A7DE8
P 6300 4400
AR Path="/5F4A9E86/5F64A564" Ref="#PWR?"  Part="1" 
AR Path="/5F4A9E86/5F640632/5F64A564" Ref="#PWR?"  Part="1" 
AR Path="/5F4A9E86/5F640632/5F6A7DE8" Ref="#PWR?"  Part="1" 
AR Path="/5F4A9E86/5F64E1A9/5F6A7DE8" Ref="#PWR033"  Part="1" 
AR Path="/5F4A9E86/5F64E559/5F6A7DE8" Ref="#PWR040"  Part="1" 
AR Path="/5F4A9E86/5F64E7E9/5F6A7DE8" Ref="#PWR047"  Part="1" 
AR Path="/5F4A9E86/5F6DDF02/5F6A7DE8" Ref="#PWR054"  Part="1" 
AR Path="/5F4A9E86/5F60074F/5F6A7DE8" Ref="#PWR?"  Part="1" 
F 0 "#PWR033" H 6300 4150 50  0001 C CNN
F 1 "GND" H 6305 4227 50  0000 C CNN
F 2 "" H 6300 4400 50  0001 C CNN
F 3 "" H 6300 4400 50  0001 C CNN
	1    6300 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	6750 3700 7050 3700
Connection ~ 6750 3700
Text HLabel 7050 3700 2    50   Input ~ 0
ENC_SW
Text HLabel 3850 3700 0    50   Input ~ 0
ENC_A
Text HLabel 3850 3900 0    50   Input ~ 0
ENC_B
Wire Wire Line
	3850 3900 4100 3900
Wire Wire Line
	4950 3900 5100 3900
Wire Wire Line
	4450 4250 4450 4400
$Comp
L power:GND #PWR?
U 1 1 5F6B5A68
P 4450 4400
AR Path="/5F4A9E86/5F64A534" Ref="#PWR?"  Part="1" 
AR Path="/5F4A9E86/5F640632/5F64A534" Ref="#PWR?"  Part="1" 
AR Path="/5F4A9E86/5F640632/5F6B5A68" Ref="#PWR?"  Part="1" 
AR Path="/5F4A9E86/5F64E1A9/5F6B5A68" Ref="#PWR030"  Part="1" 
AR Path="/5F4A9E86/5F64E559/5F6B5A68" Ref="#PWR037"  Part="1" 
AR Path="/5F4A9E86/5F64E7E9/5F6B5A68" Ref="#PWR044"  Part="1" 
AR Path="/5F4A9E86/5F6DDF02/5F6B5A68" Ref="#PWR051"  Part="1" 
AR Path="/5F4A9E86/5F60074F/5F6B5A68" Ref="#PWR?"  Part="1" 
F 0 "#PWR030" H 4450 4150 50  0001 C CNN
F 1 "GND" H 4455 4227 50  0000 C CNN
F 2 "" H 4450 4400 50  0001 C CNN
F 3 "" H 4450 4400 50  0001 C CNN
	1    4450 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	3850 3700 4450 3700
$Comp
L Device:C C?
U 1 1 5F6B8BDC
P 4100 4100
AR Path="/5F4A9E86/5F6B8BDC" Ref="C?"  Part="1" 
AR Path="/5F4A9E86/5F640632/5F6B8BDC" Ref="C?"  Part="1" 
AR Path="/5F4A9E86/5F64E1A9/5F6B8BDC" Ref="C6"  Part="1" 
AR Path="/5F4A9E86/5F64E559/5F6B8BDC" Ref="C9"  Part="1" 
AR Path="/5F4A9E86/5F64E7E9/5F6B8BDC" Ref="C12"  Part="1" 
AR Path="/5F4A9E86/5F6DDF02/5F6B8BDC" Ref="C15"  Part="1" 
AR Path="/5F4A9E86/5F60074F/5F6B8BDC" Ref="C?"  Part="1" 
F 0 "C6" H 4215 4146 50  0000 L CNN
F 1 "10n" H 4215 4055 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 4138 3950 50  0001 C CNN
F 3 "~" H 4100 4100 50  0001 C CNN
F 4 "311-1677-1-ND" H 4100 4100 50  0001 C CNN "Digikey"
F 5 "CC0402JRX7R8BB103" H 4100 4100 50  0001 C CNN "MPN"
F 6 "Yageo" H 4100 4100 50  0001 C CNN "Manufacturer"
	1    4100 4100
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5F6B95E0
P 4450 4100
AR Path="/5F4A9E86/5F6B95E0" Ref="C?"  Part="1" 
AR Path="/5F4A9E86/5F640632/5F6B95E0" Ref="C?"  Part="1" 
AR Path="/5F4A9E86/5F64E1A9/5F6B95E0" Ref="C7"  Part="1" 
AR Path="/5F4A9E86/5F64E559/5F6B95E0" Ref="C10"  Part="1" 
AR Path="/5F4A9E86/5F64E7E9/5F6B95E0" Ref="C13"  Part="1" 
AR Path="/5F4A9E86/5F6DDF02/5F6B95E0" Ref="C16"  Part="1" 
AR Path="/5F4A9E86/5F60074F/5F6B95E0" Ref="C?"  Part="1" 
F 0 "C7" H 4565 4146 50  0000 L CNN
F 1 "10n" H 4565 4055 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 4488 3950 50  0001 C CNN
F 3 "~" H 4450 4100 50  0001 C CNN
F 4 "311-1677-1-ND" H 4450 4100 50  0001 C CNN "Digikey"
F 5 "CC0402JRX7R8BB103" H 4450 4100 50  0001 C CNN "MPN"
F 6 "Yageo" H 4450 4100 50  0001 C CNN "Manufacturer"
	1    4450 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	4950 3700 5450 3700
Wire Wire Line
	5100 3550 5100 3900
Connection ~ 5100 3900
Wire Wire Line
	5100 3900 5650 3900
Wire Wire Line
	5450 3550 5450 3700
Connection ~ 5450 3700
Wire Wire Line
	5450 3700 5650 3700
Wire Wire Line
	4450 3950 4450 3700
Connection ~ 4450 3700
Wire Wire Line
	4450 3700 4650 3700
Wire Wire Line
	4100 3900 4100 3950
Connection ~ 4100 3900
Wire Wire Line
	4100 3900 4650 3900
Wire Wire Line
	6250 3700 6350 3700
Wire Wire Line
	4100 4250 4100 4400
$Comp
L power:GND #PWR?
U 1 1 5F6B50D9
P 4100 4400
AR Path="/5F4A9E86/5F64A534" Ref="#PWR?"  Part="1" 
AR Path="/5F4A9E86/5F640632/5F64A534" Ref="#PWR?"  Part="1" 
AR Path="/5F4A9E86/5F640632/5F6B50D9" Ref="#PWR?"  Part="1" 
AR Path="/5F4A9E86/5F64E1A9/5F6B50D9" Ref="#PWR029"  Part="1" 
AR Path="/5F4A9E86/5F64E559/5F6B50D9" Ref="#PWR036"  Part="1" 
AR Path="/5F4A9E86/5F64E7E9/5F6B50D9" Ref="#PWR043"  Part="1" 
AR Path="/5F4A9E86/5F6DDF02/5F6B50D9" Ref="#PWR050"  Part="1" 
AR Path="/5F4A9E86/5F60074F/5F6B50D9" Ref="#PWR?"  Part="1" 
F 0 "#PWR029" H 4100 4150 50  0001 C CNN
F 1 "GND" H 4105 4227 50  0000 C CNN
F 2 "" H 4100 4400 50  0001 C CNN
F 3 "" H 4100 4400 50  0001 C CNN
	1    4100 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	6750 3600 6750 3700
$Comp
L power:+3V3 #PWR052
U 1 1 5FA5F61A
P 5100 3250
AR Path="/5F4A9E86/5F6DDF02/5FA5F61A" Ref="#PWR052"  Part="1" 
AR Path="/5F4A9E86/5F64E1A9/5FA5F61A" Ref="#PWR031"  Part="1" 
AR Path="/5F4A9E86/5F64E559/5FA5F61A" Ref="#PWR038"  Part="1" 
AR Path="/5F4A9E86/5F64E7E9/5FA5F61A" Ref="#PWR045"  Part="1" 
F 0 "#PWR031" H 5100 3100 50  0001 C CNN
F 1 "+3V3" H 5115 3423 50  0000 C CNN
F 2 "" H 5100 3250 50  0001 C CNN
F 3 "" H 5100 3250 50  0001 C CNN
	1    5100 3250
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR053
U 1 1 5FA5FB6F
P 5450 3250
AR Path="/5F4A9E86/5F6DDF02/5FA5FB6F" Ref="#PWR053"  Part="1" 
AR Path="/5F4A9E86/5F64E1A9/5FA5FB6F" Ref="#PWR032"  Part="1" 
AR Path="/5F4A9E86/5F64E559/5FA5FB6F" Ref="#PWR039"  Part="1" 
AR Path="/5F4A9E86/5F64E7E9/5FA5FB6F" Ref="#PWR046"  Part="1" 
F 0 "#PWR032" H 5450 3100 50  0001 C CNN
F 1 "+3V3" H 5465 3423 50  0000 C CNN
F 2 "" H 5450 3250 50  0001 C CNN
F 3 "" H 5450 3250 50  0001 C CNN
	1    5450 3250
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR055
U 1 1 5FA5FD7B
P 6750 3300
AR Path="/5F4A9E86/5F6DDF02/5FA5FD7B" Ref="#PWR055"  Part="1" 
AR Path="/5F4A9E86/5F64E1A9/5FA5FD7B" Ref="#PWR034"  Part="1" 
AR Path="/5F4A9E86/5F64E559/5FA5FD7B" Ref="#PWR041"  Part="1" 
AR Path="/5F4A9E86/5F64E7E9/5FA5FD7B" Ref="#PWR048"  Part="1" 
F 0 "#PWR034" H 6750 3150 50  0001 C CNN
F 1 "+3V3" H 6765 3473 50  0000 C CNN
F 2 "" H 6750 3300 50  0001 C CNN
F 3 "" H 6750 3300 50  0001 C CNN
	1    6750 3300
	1    0    0    -1  
$EndComp
$Comp
L Device:R R40
U 1 1 5FF1EA9B
P 4800 3700
AR Path="/5F4A9E86/5F64E1A9/5FF1EA9B" Ref="R40"  Part="1" 
AR Path="/5F4A9E86/5F64E559/5FF1EA9B" Ref="R46"  Part="1" 
AR Path="/5F4A9E86/5F64E7E9/5FF1EA9B" Ref="R52"  Part="1" 
AR Path="/5F4A9E86/5F6DDF02/5FF1EA9B" Ref="R58"  Part="1" 
F 0 "R40" V 4593 3700 50  0000 C CNN
F 1 "10K" V 4684 3700 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 4730 3700 50  0001 C CNN
F 3 "~" H 4800 3700 50  0001 C CNN
	1    4800 3700
	0    1    1    0   
$EndComp
$Comp
L Device:R R41
U 1 1 5FF1F393
P 4800 3900
AR Path="/5F4A9E86/5F64E1A9/5FF1F393" Ref="R41"  Part="1" 
AR Path="/5F4A9E86/5F64E559/5FF1F393" Ref="R47"  Part="1" 
AR Path="/5F4A9E86/5F64E7E9/5FF1F393" Ref="R53"  Part="1" 
AR Path="/5F4A9E86/5F6DDF02/5FF1F393" Ref="R59"  Part="1" 
F 0 "R41" V 4593 3900 50  0000 C CNN
F 1 "10K" V 4684 3900 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 4730 3900 50  0001 C CNN
F 3 "~" H 4800 3900 50  0001 C CNN
	1    4800 3900
	0    1    1    0   
$EndComp
$Comp
L Device:R R42
U 1 1 5FF1F59B
P 5100 3400
AR Path="/5F4A9E86/5F64E1A9/5FF1F59B" Ref="R42"  Part="1" 
AR Path="/5F4A9E86/5F64E559/5FF1F59B" Ref="R48"  Part="1" 
AR Path="/5F4A9E86/5F64E7E9/5FF1F59B" Ref="R54"  Part="1" 
AR Path="/5F4A9E86/5F6DDF02/5FF1F59B" Ref="R60"  Part="1" 
F 0 "R42" H 5030 3354 50  0000 R CNN
F 1 "10K" H 5030 3445 50  0000 R CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 5030 3400 50  0001 C CNN
F 3 "~" H 5100 3400 50  0001 C CNN
	1    5100 3400
	-1   0    0    1   
$EndComp
$Comp
L Device:R R43
U 1 1 5FF1F8A9
P 5450 3400
AR Path="/5F4A9E86/5F64E1A9/5FF1F8A9" Ref="R43"  Part="1" 
AR Path="/5F4A9E86/5F64E559/5FF1F8A9" Ref="R49"  Part="1" 
AR Path="/5F4A9E86/5F64E7E9/5FF1F8A9" Ref="R55"  Part="1" 
AR Path="/5F4A9E86/5F6DDF02/5FF1F8A9" Ref="R61"  Part="1" 
F 0 "R43" H 5380 3354 50  0000 R CNN
F 1 "10K" H 5380 3445 50  0000 R CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 5380 3400 50  0001 C CNN
F 3 "~" H 5450 3400 50  0001 C CNN
	1    5450 3400
	-1   0    0    1   
$EndComp
$Comp
L Device:R R44
U 1 1 5FF1FAB4
P 6500 3700
AR Path="/5F4A9E86/5F64E1A9/5FF1FAB4" Ref="R44"  Part="1" 
AR Path="/5F4A9E86/5F64E559/5FF1FAB4" Ref="R50"  Part="1" 
AR Path="/5F4A9E86/5F64E7E9/5FF1FAB4" Ref="R56"  Part="1" 
AR Path="/5F4A9E86/5F6DDF02/5FF1FAB4" Ref="R62"  Part="1" 
F 0 "R44" V 6707 3700 50  0000 C CNN
F 1 "10K" V 6616 3700 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 6430 3700 50  0001 C CNN
F 3 "~" H 6500 3700 50  0001 C CNN
	1    6500 3700
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R45
U 1 1 5FF1FD2A
P 6750 3450
AR Path="/5F4A9E86/5F64E1A9/5FF1FD2A" Ref="R45"  Part="1" 
AR Path="/5F4A9E86/5F64E559/5FF1FD2A" Ref="R51"  Part="1" 
AR Path="/5F4A9E86/5F64E7E9/5FF1FD2A" Ref="R57"  Part="1" 
AR Path="/5F4A9E86/5F6DDF02/5FF1FD2A" Ref="R63"  Part="1" 
F 0 "R45" H 6820 3496 50  0000 L CNN
F 1 "10K" H 6820 3405 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 6680 3450 50  0001 C CNN
F 3 "~" H 6750 3450 50  0001 C CNN
	1    6750 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 3800 5550 3800
$Comp
L power:GND #PWR?
U 1 1 5FC19961
P 5550 3800
AR Path="/5F4A9E86/5F64A564" Ref="#PWR?"  Part="1" 
AR Path="/5F4A9E86/5F640632/5F64A564" Ref="#PWR?"  Part="1" 
AR Path="/5F4A9E86/5F640632/5FC19961" Ref="#PWR?"  Part="1" 
AR Path="/5F4A9E86/5F64E1A9/5FC19961" Ref="#PWR0145"  Part="1" 
AR Path="/5F4A9E86/5F64E559/5FC19961" Ref="#PWR0146"  Part="1" 
AR Path="/5F4A9E86/5F64E7E9/5FC19961" Ref="#PWR0147"  Part="1" 
AR Path="/5F4A9E86/5F6DDF02/5FC19961" Ref="#PWR0148"  Part="1" 
AR Path="/5F4A9E86/5F60074F/5FC19961" Ref="#PWR?"  Part="1" 
F 0 "#PWR0145" H 5550 3550 50  0001 C CNN
F 1 "GND" H 5555 3627 50  0000 C CNN
F 2 "" H 5550 3800 50  0001 C CNN
F 3 "" H 5550 3800 50  0001 C CNN
	1    5550 3800
	0    1    1    0   
$EndComp
$EndSCHEMATC
