EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 8 9
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
L MK_Library:AP2114-HA U?
U 1 1 5F8D37EF
P 8000 1650
AR Path="/5F4A9ECD/5F8D37EF" Ref="U?"  Part="1" 
AR Path="/5F8D37EF" Ref="U?"  Part="1" 
AR Path="/5F8CC9DA/5F8D37EF" Ref="U8"  Part="1" 
F 0 "U8" H 8000 1915 50  0000 C CNN
F 1 "AP2114HA-3.3TRG1" H 8000 1824 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-223-3_TabPin2" H 8000 1650 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/AP2114.pdf" H 8000 1650 50  0001 C CNN
F 4 "AP2114HA-3.3TRG1" H 8000 1650 50  0001 C CNN "Digikey"
F 5 "AP2114HA-3.3TRG1DICT-ND" H 8000 1650 50  0001 C CNN "MPN"
F 6 "Diodes Inc." H 8000 1650 50  0001 C CNN "Manufacturer"
	1    8000 1650
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5F8D37F8
P 8850 1900
AR Path="/5F4A9ECD/5F8D37F8" Ref="C?"  Part="1" 
AR Path="/5F8D37F8" Ref="C?"  Part="1" 
AR Path="/5F8CC9DA/5F8D37F8" Ref="C38"  Part="1" 
F 0 "C38" H 8965 1946 50  0000 L CNN
F 1 "4.7uF" H 8965 1855 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 8888 1750 50  0001 C CNN
F 3 "~" H 8850 1900 50  0001 C CNN
F 4 "1276-1055-1-ND" H 8850 1900 50  0001 C CNN "Digikey"
F 5 "Samsung" H 8850 1900 50  0001 C CNN "Manufacturer"
F 6 "CL31B475KAHNNNE" H 8850 1900 50  0001 C CNN "MPN"
	1    8850 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	8850 1650 8850 1750
Wire Wire Line
	8850 2050 8850 2200
$Comp
L Device:C C?
U 1 1 5F8D3803
P 5050 3400
AR Path="/5F4A9ECD/5F8D3803" Ref="C?"  Part="1" 
AR Path="/5F8D3803" Ref="C?"  Part="1" 
AR Path="/5F8CC9DA/5F8D3803" Ref="C35"  Part="1" 
F 0 "C35" H 5165 3446 50  0000 L CNN
F 1 "4.7uF" H 5165 3355 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 5088 3250 50  0001 C CNN
F 3 "~" H 5050 3400 50  0001 C CNN
F 4 "1276-1055-1-ND" H 5050 3400 50  0001 C CNN "Digikey"
F 5 "Samsung" H 5050 3400 50  0001 C CNN "Manufacturer"
F 6 "CL31B475KAHNNNE" H 5050 3400 50  0001 C CNN "MPN"
	1    5050 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	5050 3550 5050 3800
$Comp
L power:GND #PWR?
U 1 1 5F8D380A
P 5050 3800
AR Path="/5F4A9ECD/5F8D380A" Ref="#PWR?"  Part="1" 
AR Path="/5F8D380A" Ref="#PWR?"  Part="1" 
AR Path="/5F8CC9DA/5F8D380A" Ref="#PWR0112"  Part="1" 
F 0 "#PWR0112" H 5050 3550 50  0001 C CNN
F 1 "GND" H 5055 3627 50  0000 C CNN
F 2 "" H 5050 3800 50  0001 C CNN
F 3 "" H 5050 3800 50  0001 C CNN
	1    5050 3800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F8D3810
P 8000 2200
AR Path="/5F4A9ECD/5F8D3810" Ref="#PWR?"  Part="1" 
AR Path="/5F8D3810" Ref="#PWR?"  Part="1" 
AR Path="/5F8CC9DA/5F8D3810" Ref="#PWR0119"  Part="1" 
F 0 "#PWR0119" H 8000 1950 50  0001 C CNN
F 1 "GND" H 8005 2027 50  0000 C CNN
F 2 "" H 8000 2200 50  0001 C CNN
F 3 "" H 8000 2200 50  0001 C CNN
	1    8000 2200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F8D3816
P 8850 2200
AR Path="/5F4A9ECD/5F8D3816" Ref="#PWR?"  Part="1" 
AR Path="/5F8D3816" Ref="#PWR?"  Part="1" 
AR Path="/5F8CC9DA/5F8D3816" Ref="#PWR0121"  Part="1" 
F 0 "#PWR0121" H 8850 1950 50  0001 C CNN
F 1 "GND" H 8855 2027 50  0000 C CNN
F 2 "" H 8850 2200 50  0001 C CNN
F 3 "" H 8850 2200 50  0001 C CNN
	1    8850 2200
	1    0    0    -1  
$EndComp
Connection ~ 5050 2950
$Comp
L power:+5V #PWR?
U 1 1 5F8D381D
P 5050 2950
AR Path="/5F4A9ECD/5F8D381D" Ref="#PWR?"  Part="1" 
AR Path="/5F8D381D" Ref="#PWR?"  Part="1" 
AR Path="/5F8CC9DA/5F8D381D" Ref="#PWR0111"  Part="1" 
F 0 "#PWR0111" H 5050 2800 50  0001 C CNN
F 1 "+5V" H 5065 3123 50  0000 C CNN
F 2 "" H 5050 2950 50  0001 C CNN
F 3 "" H 5050 2950 50  0001 C CNN
	1    5050 2950
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR?
U 1 1 5F8D3823
P 8850 1650
AR Path="/5F4A9ECD/5F8D3823" Ref="#PWR?"  Part="1" 
AR Path="/5F8D3823" Ref="#PWR?"  Part="1" 
AR Path="/5F8CC9DA/5F8D3823" Ref="#PWR0120"  Part="1" 
F 0 "#PWR0120" H 8850 1500 50  0001 C CNN
F 1 "+3V3" H 8865 1823 50  0000 C CNN
F 2 "" H 8850 1650 50  0001 C CNN
F 3 "" H 8850 1650 50  0001 C CNN
	1    8850 1650
	1    0    0    -1  
$EndComp
Connection ~ 8850 1650
Wire Wire Line
	5050 3250 5050 2950
Wire Wire Line
	2150 2950 3150 2950
$Comp
L power:GND #PWR?
U 1 1 5F8D382C
P 2700 3800
AR Path="/5F4A9ECD/5F8D382C" Ref="#PWR?"  Part="1" 
AR Path="/5F8D382C" Ref="#PWR?"  Part="1" 
AR Path="/5F8CC9DA/5F8D382C" Ref="#PWR098"  Part="1" 
F 0 "#PWR098" H 2700 3550 50  0001 C CNN
F 1 "GND" H 2705 3627 50  0000 C CNN
F 2 "" H 2700 3800 50  0001 C CNN
F 3 "" H 2700 3800 50  0001 C CNN
	1    2700 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	2700 3150 2700 3800
Wire Wire Line
	2150 3150 2700 3150
$Comp
L Connector:Barrel_Jack_Switch J?
U 1 1 5F8D3837
P 1850 3050
AR Path="/5F4A9ECD/5F8D3837" Ref="J?"  Part="1" 
AR Path="/5F8D3837" Ref="J?"  Part="1" 
AR Path="/5F8CC9DA/5F8D3837" Ref="J8"  Part="1" 
F 0 "J8" H 1907 3367 50  0000 C CNN
F 1 "Barrel_Jack_Switch" H 1907 3276 50  0000 C CNN
F 2 "Connector_BarrelJack:BarrelJack_CUI_PJ-102AH_Horizontal" H 1900 3010 50  0001 C CNN
F 3 "~" H 1900 3010 50  0001 C CNN
F 4 "CP-102AH-ND" H 1850 3050 50  0001 C CNN "Digikey"
F 5 "PJ-102AH" H 1850 3050 50  0001 C CNN "MPN"
F 6 "CUI Devices" H 1850 3050 50  0001 C CNN "Manufacturer"
	1    1850 3050
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5F8D3840
P 3150 3400
AR Path="/5F4A9ECD/5F8D3840" Ref="C?"  Part="1" 
AR Path="/5F8D3840" Ref="C?"  Part="1" 
AR Path="/5F8CC9DA/5F8D3840" Ref="C34"  Part="1" 
F 0 "C34" H 3265 3446 50  0000 L CNN
F 1 "0.1uF" H 3265 3355 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 3188 3250 50  0001 C CNN
F 3 "~" H 3150 3400 50  0001 C CNN
F 4 "311-4046-1-ND" H 3150 3400 50  0001 C CNN "Digikey"
F 5 "CC0603KRX5R9BB104" H 3150 3400 50  0001 C CNN "MPN"
F 6 "Yageo" H 3150 3400 50  0001 C CNN "Manufacturer"
	1    3150 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	3150 3250 3150 2950
Connection ~ 3150 2950
Wire Wire Line
	3150 3550 3150 3800
$Comp
L power:GND #PWR?
U 1 1 5F8D3849
P 3150 3800
AR Path="/5F4A9ECD/5F8D3849" Ref="#PWR?"  Part="1" 
AR Path="/5F8D3849" Ref="#PWR?"  Part="1" 
AR Path="/5F8CC9DA/5F8D3849" Ref="#PWR099"  Part="1" 
F 0 "#PWR099" H 3150 3550 50  0001 C CNN
F 1 "GND" H 3155 3627 50  0000 C CNN
F 2 "" H 3150 3800 50  0001 C CNN
F 3 "" H 3150 3800 50  0001 C CNN
	1    3150 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	8000 2100 8000 2200
Wire Wire Line
	8550 1650 8850 1650
$Comp
L power:PWR_FLAG #FLG?
U 1 1 5F8D3851
P 8850 1650
AR Path="/5F8D3851" Ref="#FLG?"  Part="1" 
AR Path="/5F8CC9DA/5F8D3851" Ref="#FLG07"  Part="1" 
F 0 "#FLG07" H 8850 1725 50  0001 C CNN
F 1 "PWR_FLAG" V 8850 1778 50  0000 L CNN
F 2 "" H 8850 1650 50  0001 C CNN
F 3 "~" H 8850 1650 50  0001 C CNN
	1    8850 1650
	0    1    1    0   
$EndComp
Text Notes 1750 3550 0    79   Italic 0
Power Input:\n5V, 1.5A DC
Wire Wire Line
	2150 3050 2700 3050
Text Label 2700 3050 2    50   ~ 0
SELF_POWER
$Comp
L Device:D_Zener D?
U 1 1 5F8D385A
P 3550 3200
AR Path="/5F8D385A" Ref="D?"  Part="1" 
AR Path="/5F8CC9DA/5F8D385A" Ref="D12"  Part="1" 
F 0 "D12" V 3504 3280 50  0000 L CNN
F 1 "DDZ5V6BSF-7" V 3400 3150 50  0000 L CNN
F 2 "Diode_SMD:D_SOD-323F" H 3550 3200 50  0001 C CNN
F 3 "~" H 3550 3200 50  0001 C CNN
F 4 "DDZ5V6BSF-7DICT-ND" V 3550 3200 50  0001 C CNN "Digikey"
	1    3550 3200
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5F8D3860
P 3550 3600
AR Path="/5F8D3860" Ref="R?"  Part="1" 
AR Path="/5F8CC9DA/5F8D3860" Ref="R22"  Part="1" 
F 0 "R22" H 3620 3646 50  0000 L CNN
F 1 "1k" H 3620 3555 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 3480 3600 50  0001 C CNN
F 3 "~" H 3550 3600 50  0001 C CNN
	1    3550 3600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F8D3866
P 3550 3800
AR Path="/5F4A9ECD/5F8D3866" Ref="#PWR?"  Part="1" 
AR Path="/5F8D3866" Ref="#PWR?"  Part="1" 
AR Path="/5F8CC9DA/5F8D3866" Ref="#PWR0100"  Part="1" 
F 0 "#PWR0100" H 3550 3550 50  0001 C CNN
F 1 "GND" H 3555 3627 50  0000 C CNN
F 2 "" H 3550 3800 50  0001 C CNN
F 3 "" H 3550 3800 50  0001 C CNN
	1    3550 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	3550 3800 3550 3750
Wire Wire Line
	3550 3450 3550 3400
Wire Wire Line
	3550 3050 3550 2950
Wire Wire Line
	3150 2950 3550 2950
$Comp
L Device:Q_SCR_KAG D?
U 1 1 5F8D3870
P 4050 3300
AR Path="/5F8D3870" Ref="D?"  Part="1" 
AR Path="/5F8CC9DA/5F8D3870" Ref="D14"  Part="1" 
F 0 "D14" H 4138 3346 50  0000 L CNN
F 1 "S4SRP" H 4138 3255 50  0000 L CNN
F 2 "Diode_SMD:D_SMB_Modified" V 4050 3300 50  0001 C CNN
F 3 "~" V 4050 3300 50  0001 C CNN
	1    4050 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	4050 3150 4050 2950
Wire Wire Line
	4050 2950 3550 2950
Connection ~ 3550 2950
Wire Wire Line
	4050 3450 4050 3800
$Comp
L power:GND #PWR?
U 1 1 5F8D387A
P 4050 3800
AR Path="/5F4A9ECD/5F8D387A" Ref="#PWR?"  Part="1" 
AR Path="/5F8D387A" Ref="#PWR?"  Part="1" 
AR Path="/5F8CC9DA/5F8D387A" Ref="#PWR0104"  Part="1" 
F 0 "#PWR0104" H 4050 3550 50  0001 C CNN
F 1 "GND" H 4055 3627 50  0000 C CNN
F 2 "" H 4050 3800 50  0001 C CNN
F 3 "" H 4050 3800 50  0001 C CNN
	1    4050 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	3550 3400 3900 3400
Connection ~ 3550 3400
Wire Wire Line
	3550 3400 3550 3350
Wire Wire Line
	4050 2950 4300 2950
Connection ~ 4050 2950
Wire Wire Line
	4500 3250 4500 3800
$Comp
L power:GND #PWR?
U 1 1 5F8D3886
P 4500 3800
AR Path="/5F4A9ECD/5F8D3886" Ref="#PWR?"  Part="1" 
AR Path="/5F8D3886" Ref="#PWR?"  Part="1" 
AR Path="/5F8CC9DA/5F8D3886" Ref="#PWR0110"  Part="1" 
F 0 "#PWR0110" H 4500 3550 50  0001 C CNN
F 1 "GND" H 4505 3627 50  0000 C CNN
F 2 "" H 4500 3800 50  0001 C CNN
F 3 "" H 4500 3800 50  0001 C CNN
	1    4500 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	5050 2950 4700 2950
$Comp
L power:PWR_FLAG #FLG?
U 1 1 5F8D388D
P 5050 2950
AR Path="/5F8D388D" Ref="#FLG?"  Part="1" 
AR Path="/5F8CC9DA/5F8D388D" Ref="#FLG06"  Part="1" 
F 0 "#FLG06" H 5050 3025 50  0001 C CNN
F 1 "PWR_FLAG" V 5050 3300 50  0000 C CNN
F 2 "" H 5050 2950 50  0001 C CNN
F 3 "~" H 5050 2950 50  0001 C CNN
	1    5050 2950
	0    1    1    0   
$EndComp
Text Label 2700 2950 2    50   ~ 0
VCC_IN
$Comp
L Device:Q_PMOS_GSD Q?
U 1 1 5F8D3895
P 4000 5100
AR Path="/5F8D3895" Ref="Q?"  Part="1" 
AR Path="/5F8CC9DA/5F8D3895" Ref="Q1"  Part="1" 
F 0 "Q1" V 3850 4800 50  0000 L CNN
F 1 "FDN338P" V 3950 4600 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 4200 5200 50  0001 C CNN
F 3 "https://www.onsemi.com/pub/Collateral/FDN338P-D.pdf" H 4000 5100 50  0001 C CNN
F 4 "FDN338PCT-ND" H 4000 5100 50  0001 C CNN "Digikey"
	1    4000 5100
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R?
U 1 1 5F8D389B
P 3550 5300
AR Path="/5F8D389B" Ref="R?"  Part="1" 
AR Path="/5F8CC9DA/5F8D389B" Ref="R23"  Part="1" 
F 0 "R23" V 3757 5300 50  0000 C CNN
F 1 "4.7k" V 3666 5300 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 3480 5300 50  0001 C CNN
F 3 "~" H 3550 5300 50  0001 C CNN
	1    3550 5300
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R?
U 1 1 5F8D38A1
P 3150 5300
AR Path="/5F8D38A1" Ref="R?"  Part="1" 
AR Path="/5F8CC9DA/5F8D38A1" Ref="R21"  Part="1" 
F 0 "R21" V 3357 5300 50  0000 C CNN
F 1 "510k" V 3266 5300 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 3080 5300 50  0001 C CNN
F 3 "~" H 3150 5300 50  0001 C CNN
	1    3150 5300
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3400 5300 3350 5300
Wire Wire Line
	3000 5300 2650 5300
Text Label 2650 5300 0    50   ~ 0
VCC_IN
Wire Wire Line
	3350 5300 3350 5600
Wire Wire Line
	3350 5600 2650 5600
Connection ~ 3350 5300
Wire Wire Line
	3350 5300 3300 5300
Text Label 2650 5600 0    50   ~ 0
SELF_POWER
$Comp
L power:+5V #PWR?
U 1 1 5F8D38AF
P 4300 5000
AR Path="/5F4A9ECD/5F8D38AF" Ref="#PWR?"  Part="1" 
AR Path="/5F8D38AF" Ref="#PWR?"  Part="1" 
AR Path="/5F8CC9DA/5F8D38AF" Ref="#PWR0107"  Part="1" 
F 0 "#PWR0107" H 4300 4850 50  0001 C CNN
F 1 "+5V" H 4315 5173 50  0000 C CNN
F 2 "" H 4300 5000 50  0001 C CNN
F 3 "" H 4300 5000 50  0001 C CNN
	1    4300 5000
	-1   0    0    -1  
$EndComp
Wire Wire Line
	4300 5000 4200 5000
Wire Wire Line
	3800 5000 3700 5000
$Comp
L power:VBUS #PWR?
U 1 1 5F8D38B7
P 3700 5000
AR Path="/5F8D38B7" Ref="#PWR?"  Part="1" 
AR Path="/5F8CC9DA/5F8D38B7" Ref="#PWR0101"  Part="1" 
F 0 "#PWR0101" H 3700 4850 50  0001 C CNN
F 1 "VBUS" H 3715 5173 50  0000 C CNN
F 2 "" H 3700 5000 50  0001 C CNN
F 3 "" H 3700 5000 50  0001 C CNN
	1    3700 5000
	-1   0    0    -1  
$EndComp
Text Notes 2500 5900 0    50   ~ 0
Allows the system to accept additional power from the power jack.\nUSB Only: VCC_IN = SELF_POWER = 0V; MOSFET ON, VBUS ≡ +5V\nDC In:     VCC_IN = 5V, SELF_POWER = 5V (switch open); MOSFET OFF, VBUS floating 
$Comp
L Device:C C?
U 1 1 5F8D38C1
P 6800 1900
AR Path="/5F4A9ECD/5F8D38C1" Ref="C?"  Part="1" 
AR Path="/5F8D38C1" Ref="C?"  Part="1" 
AR Path="/5F8CC9DA/5F8D38C1" Ref="C36"  Part="1" 
F 0 "C36" H 6915 1946 50  0000 L CNN
F 1 "4.7uF" H 6915 1855 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 6838 1750 50  0001 C CNN
F 3 "~" H 6800 1900 50  0001 C CNN
F 4 "1276-1055-1-ND" H 6800 1900 50  0001 C CNN "Digikey"
F 5 "Samsung" H 6800 1900 50  0001 C CNN "Manufacturer"
F 6 "CL31B475KAHNNNE" H 6800 1900 50  0001 C CNN "MPN"
	1    6800 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	6800 2050 6800 2200
$Comp
L power:GND #PWR?
U 1 1 5F8D38C8
P 6800 2200
AR Path="/5F4A9ECD/5F8D38C8" Ref="#PWR?"  Part="1" 
AR Path="/5F8D38C8" Ref="#PWR?"  Part="1" 
AR Path="/5F8CC9DA/5F8D38C8" Ref="#PWR0114"  Part="1" 
F 0 "#PWR0114" H 6800 1950 50  0001 C CNN
F 1 "GND" H 6805 2027 50  0000 C CNN
F 2 "" H 6800 2200 50  0001 C CNN
F 3 "" H 6800 2200 50  0001 C CNN
	1    6800 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	6800 1750 6800 1650
$Comp
L power:+5V #PWR?
U 1 1 5F8D38CF
P 6800 1650
AR Path="/5F4A9ECD/5F8D38CF" Ref="#PWR?"  Part="1" 
AR Path="/5F8D38CF" Ref="#PWR?"  Part="1" 
AR Path="/5F8CC9DA/5F8D38CF" Ref="#PWR0113"  Part="1" 
F 0 "#PWR0113" H 6800 1500 50  0001 C CNN
F 1 "+5V" H 6815 1823 50  0000 C CNN
F 2 "" H 6800 1650 50  0001 C CNN
F 3 "" H 6800 1650 50  0001 C CNN
	1    6800 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	6800 1650 7250 1650
Connection ~ 6800 1650
$Comp
L MK_Library:DMP1005UFDF U?
U 1 1 5F8D38D7
P 4500 2950
AR Path="/5F8D38D7" Ref="U?"  Part="1" 
AR Path="/5F8CC9DA/5F8D38D7" Ref="U7"  Part="1" 
F 0 "U7" V 4742 2950 50  0000 C CNN
F 1 "DMP1005UFDF" V 4651 2950 50  0000 C CNN
F 2 "Package_DFN_QFN:Diodes_UDFN2020-6_Type-F" H 4500 2950 50  0001 C CNN
F 3 "" H 4500 2950 50  0001 C CNN
	1    4500 2950
	0    1    -1   0   
$EndComp
Wire Wire Line
	4000 5300 3700 5300
$Comp
L power:+5V #PWR?
U 1 1 5F8D38DE
P 7050 3950
AR Path="/5F4A9ECD/5F8D38DE" Ref="#PWR?"  Part="1" 
AR Path="/5F8D38DE" Ref="#PWR?"  Part="1" 
AR Path="/5F8CC9DA/5F8D38DE" Ref="#PWR0115"  Part="1" 
F 0 "#PWR0115" H 7050 3800 50  0001 C CNN
F 1 "+5V" H 7065 4123 50  0000 C CNN
F 2 "" H 7050 3950 50  0001 C CNN
F 3 "" H 7050 3950 50  0001 C CNN
	1    7050 3950
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR?
U 1 1 5F8D38E4
P 7050 4300
AR Path="/5F4A9ECD/5F8D38E4" Ref="#PWR?"  Part="1" 
AR Path="/5F8D38E4" Ref="#PWR?"  Part="1" 
AR Path="/5F8CC9DA/5F8D38E4" Ref="#PWR0116"  Part="1" 
F 0 "#PWR0116" H 7050 4150 50  0001 C CNN
F 1 "+3V3" H 7065 4473 50  0000 C CNN
F 2 "" H 7050 4300 50  0001 C CNN
F 3 "" H 7050 4300 50  0001 C CNN
	1    7050 4300
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5F8D38EA
P 7300 3950
AR Path="/5F8D38EA" Ref="R?"  Part="1" 
AR Path="/5F8CC9DA/5F8D38EA" Ref="R27"  Part="1" 
F 0 "R27" V 7093 3950 50  0000 C CNN
F 1 "0R" V 7184 3950 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 7230 3950 50  0001 C CNN
F 3 "~" H 7300 3950 50  0001 C CNN
	1    7300 3950
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5F8D38F0
P 7300 4300
AR Path="/5F8D38F0" Ref="R?"  Part="1" 
AR Path="/5F8CC9DA/5F8D38F0" Ref="R28"  Part="1" 
F 0 "R28" V 7093 4300 50  0000 C CNN
F 1 "DNP" V 7184 4300 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 7230 4300 50  0001 C CNN
F 3 "~" H 7300 4300 50  0001 C CNN
	1    7300 4300
	0    1    1    0   
$EndComp
Wire Wire Line
	7050 4300 7150 4300
Wire Wire Line
	7050 3950 7150 3950
Wire Wire Line
	7450 3950 7550 3950
Wire Wire Line
	7550 3950 7550 4300
Wire Wire Line
	7550 4300 7450 4300
Text Label 6650 4650 0    50   ~ 0
LED_PWM
Wire Wire Line
	8300 4600 8300 4700
Wire Wire Line
	8300 4700 8450 4700
Text GLabel 8450 4700 2    50   Input ~ 0
LED_Power
$Comp
L Device:Q_PMOS_GSD Q?
U 1 1 5F8D3900
P 8200 4400
AR Path="/5F8D3900" Ref="Q?"  Part="1" 
AR Path="/5F8CC9DA/5F8D3900" Ref="Q3"  Part="1" 
F 0 "Q3" H 8450 4300 50  0000 L CNN
F 1 "FDN338P" H 8400 4400 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 8400 4500 50  0001 C CNN
F 3 "https://www.onsemi.com/pub/Collateral/FDN338P-D.pdf" H 8200 4400 50  0001 C CNN
F 4 "FDN338PCT-ND" H 8200 4400 50  0001 C CNN "Digikey"
	1    8200 4400
	1    0    0    1   
$EndComp
Connection ~ 7550 3950
$Comp
L power:GND #PWR?
U 1 1 5F8D3907
P 7850 4950
AR Path="/5F4A9ECD/5F8D3907" Ref="#PWR?"  Part="1" 
AR Path="/5F8D3907" Ref="#PWR?"  Part="1" 
AR Path="/5F8CC9DA/5F8D3907" Ref="#PWR0118"  Part="1" 
F 0 "#PWR0118" H 7850 4700 50  0001 C CNN
F 1 "GND" H 7855 4777 50  0000 C CNN
F 2 "" H 7850 4950 50  0001 C CNN
F 3 "" H 7850 4950 50  0001 C CNN
	1    7850 4950
	1    0    0    -1  
$EndComp
Wire Wire Line
	7150 4650 6650 4650
$Comp
L Device:R R?
U 1 1 5F8D390E
P 7300 4650
AR Path="/5F8D390E" Ref="R?"  Part="1" 
AR Path="/5F8CC9DA/5F8D390E" Ref="R29"  Part="1" 
F 0 "R29" V 7093 4650 50  0000 C CNN
F 1 "1k" V 7184 4650 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 7230 4650 50  0001 C CNN
F 3 "~" H 7300 4650 50  0001 C CNN
	1    7300 4650
	0    1    1    0   
$EndComp
Connection ~ 7850 4400
Wire Wire Line
	7850 4400 8000 4400
Wire Wire Line
	7850 4950 7850 4850
Wire Wire Line
	7850 4400 7850 4450
Wire Wire Line
	7450 4650 7550 4650
$Comp
L Device:Q_NPN_BCE Q?
U 1 1 5F8D3919
P 7750 4650
AR Path="/5F8D3919" Ref="Q?"  Part="1" 
AR Path="/5F8CC9DA/5F8D3919" Ref="Q2"  Part="1" 
F 0 "Q2" H 7950 4550 50  0000 L CNN
F 1 "MMBT3904" H 7900 4450 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 7950 4750 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/MMBT3904.pdf" H 7750 4650 50  0001 C CNN
F 4 "1727-4044-1-ND" H 7750 4650 50  0001 C CNN "Digikey"
	1    7750 4650
	1    0    0    -1  
$EndComp
Wire Wire Line
	8300 3950 8300 4200
Connection ~ 7850 3950
Wire Wire Line
	7550 3950 7850 3950
Wire Wire Line
	8300 3950 7850 3950
Wire Wire Line
	7850 3950 7850 4000
Wire Wire Line
	7850 4300 7850 4400
$Comp
L Device:R R?
U 1 1 5F8D3925
P 7850 4150
AR Path="/5F8D3925" Ref="R?"  Part="1" 
AR Path="/5F8CC9DA/5F8D3925" Ref="R30"  Part="1" 
F 0 "R30" H 7780 4104 50  0000 R CNN
F 1 "1k" H 7780 4195 50  0000 R CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 7780 4150 50  0001 C CNN
F 3 "~" H 7850 4150 50  0001 C CNN
	1    7850 4150
	-1   0    0    1   
$EndComp
Text Notes 1700 4400 0    50   ~ 0
Input Voltage and Protection\n- Protects against overvoltage by activating the SCR diode above the conduction voltage of the zener diode\n- Protects against reverse voltage by closing the MOSFET if the Gate (Ground) is higher than pin 4 (VCC_IN), \nwhich can only happen if the connection is reversed
Text Notes 6450 5900 0    50   ~ 0
PWM LED Driver\n- Select between 5V and 3V3 diode voltage (useful for white LEDs which have high forward voltage)\n- When the gate of the MOSFET (pin 1) is equal to the source (pin 2), current is not allowed to flow to the LEDs\n- When the gate is lower than the source, current IS allowed to flow\n- To control the brightness, we turn on and off the LEDs quickly, known as PWM. \nThis control signal is 0V or 3V3, coming from the processor\n- If we power the LEDs from 5V, the 3V3 signal won't be enough to turn off the MOSFET, \nso we use a transistor to switch the gate between ground and the source voltage.
Text Notes 6850 2850 0    50   ~ 0
3V3 Regulator\nGenerates 3V3 from the 5V input coming from the power jack or USB
Text HLabel 2200 1600 0    50   Output ~ 0
SELF_POWER
Text HLabel 2200 1700 0    50   Input ~ 0
LED_PWM
Wire Wire Line
	2200 1600 2750 1600
Text Label 2750 1600 2    50   ~ 0
SELF_POWER
Wire Wire Line
	2200 1700 2750 1700
Text Label 2750 1700 2    50   ~ 0
LED_PWM
$Comp
L Device:R R?
U 1 1 5FB959DB
P 3800 1550
AR Path="/5FB959DB" Ref="R?"  Part="1" 
AR Path="/5F8CC9DA/5FB959DB" Ref="R24"  Part="1" 
F 0 "R24" H 3730 1504 50  0000 R CNN
F 1 "270R" H 3730 1595 50  0000 R CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 3730 1550 50  0001 C CNN
F 3 "~" H 3800 1550 50  0001 C CNN
	1    3800 1550
	-1   0    0    1   
$EndComp
$Comp
L power:+3V3 #PWR?
U 1 1 5FB96BAA
P 3800 1400
AR Path="/5F4A9ECD/5FB96BAA" Ref="#PWR?"  Part="1" 
AR Path="/5FB96BAA" Ref="#PWR?"  Part="1" 
AR Path="/5F8CC9DA/5FB96BAA" Ref="#PWR0102"  Part="1" 
F 0 "#PWR0102" H 3800 1250 50  0001 C CNN
F 1 "+3V3" H 3815 1573 50  0000 C CNN
F 2 "" H 3800 1400 50  0001 C CNN
F 3 "" H 3800 1400 50  0001 C CNN
	1    3800 1400
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D13
U 1 1 5FB9701E
P 3800 1850
F 0 "D13" V 3839 1732 50  0000 R CNN
F 1 "LED" V 3748 1732 50  0000 R CNN
F 2 "LED_SMD:LED_0603_1608Metric" H 3800 1850 50  0001 C CNN
F 3 "~" H 3800 1850 50  0001 C CNN
	1    3800 1850
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5FB98492
P 3800 2000
AR Path="/5F4A9ECD/5FB98492" Ref="#PWR?"  Part="1" 
AR Path="/5FB98492" Ref="#PWR?"  Part="1" 
AR Path="/5F8CC9DA/5FB98492" Ref="#PWR0103"  Part="1" 
F 0 "#PWR0103" H 3800 1750 50  0001 C CNN
F 1 "GND" H 3805 1827 50  0000 C CNN
F 2 "" H 3800 2000 50  0001 C CNN
F 3 "" H 3800 2000 50  0001 C CNN
	1    3800 2000
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5FB9945A
P 4150 1550
AR Path="/5FB9945A" Ref="R?"  Part="1" 
AR Path="/5F8CC9DA/5FB9945A" Ref="R25"  Part="1" 
F 0 "R25" H 4080 1504 50  0000 R CNN
F 1 "270R" H 4080 1595 50  0000 R CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 4080 1550 50  0001 C CNN
F 3 "~" H 4150 1550 50  0001 C CNN
	1    4150 1550
	-1   0    0    1   
$EndComp
$Comp
L Device:LED D15
U 1 1 5FB99466
P 4150 1850
F 0 "D15" V 4189 1732 50  0000 R CNN
F 1 "LED" V 4098 1732 50  0000 R CNN
F 2 "LED_SMD:LED_0603_1608Metric" H 4150 1850 50  0001 C CNN
F 3 "~" H 4150 1850 50  0001 C CNN
	1    4150 1850
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5FB9946C
P 4150 2000
AR Path="/5F4A9ECD/5FB9946C" Ref="#PWR?"  Part="1" 
AR Path="/5FB9946C" Ref="#PWR?"  Part="1" 
AR Path="/5F8CC9DA/5FB9946C" Ref="#PWR0106"  Part="1" 
F 0 "#PWR0106" H 4150 1750 50  0001 C CNN
F 1 "GND" H 4155 1827 50  0000 C CNN
F 2 "" H 4150 2000 50  0001 C CNN
F 3 "" H 4150 2000 50  0001 C CNN
	1    4150 2000
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5FB9A028
P 4150 1400
AR Path="/5F4A9ECD/5FB9A028" Ref="#PWR?"  Part="1" 
AR Path="/5FB9A028" Ref="#PWR?"  Part="1" 
AR Path="/5F8CC9DA/5FB9A028" Ref="#PWR0105"  Part="1" 
F 0 "#PWR0105" H 4150 1250 50  0001 C CNN
F 1 "+5V" H 4165 1573 50  0000 C CNN
F 2 "" H 4150 1400 50  0001 C CNN
F 3 "" H 4150 1400 50  0001 C CNN
	1    4150 1400
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5FB9BB45
P 4500 1550
AR Path="/5FB9BB45" Ref="R?"  Part="1" 
AR Path="/5F8CC9DA/5FB9BB45" Ref="R26"  Part="1" 
F 0 "R26" H 4430 1504 50  0000 R CNN
F 1 "270R" H 4430 1595 50  0000 R CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 4430 1550 50  0001 C CNN
F 3 "~" H 4500 1550 50  0001 C CNN
	1    4500 1550
	-1   0    0    1   
$EndComp
$Comp
L Device:LED D16
U 1 1 5FB9BB51
P 4500 1850
F 0 "D16" V 4539 1732 50  0000 R CNN
F 1 "LED" V 4448 1732 50  0000 R CNN
F 2 "LED_SMD:LED_0603_1608Metric" H 4500 1850 50  0001 C CNN
F 3 "~" H 4500 1850 50  0001 C CNN
	1    4500 1850
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5FB9BB57
P 4500 2000
AR Path="/5F4A9ECD/5FB9BB57" Ref="#PWR?"  Part="1" 
AR Path="/5FB9BB57" Ref="#PWR?"  Part="1" 
AR Path="/5F8CC9DA/5FB9BB57" Ref="#PWR0109"  Part="1" 
F 0 "#PWR0109" H 4500 1750 50  0001 C CNN
F 1 "GND" H 4505 1827 50  0000 C CNN
F 2 "" H 4500 2000 50  0001 C CNN
F 3 "" H 4500 2000 50  0001 C CNN
	1    4500 2000
	1    0    0    -1  
$EndComp
$Comp
L power:VBUS #PWR?
U 1 1 5FB9D697
P 4500 1400
AR Path="/5FB9D697" Ref="#PWR?"  Part="1" 
AR Path="/5F8CC9DA/5FB9D697" Ref="#PWR0108"  Part="1" 
F 0 "#PWR0108" H 4500 1250 50  0001 C CNN
F 1 "VBUS" H 4515 1573 50  0000 C CNN
F 2 "" H 4500 1400 50  0001 C CNN
F 3 "" H 4500 1400 50  0001 C CNN
	1    4500 1400
	-1   0    0    -1  
$EndComp
Text Notes 3800 2350 0    50   ~ 0
Power Status LEDs
$Comp
L Device:CP_Small C?
U 1 1 5FBAEF90
P 7250 1900
AR Path="/5F4A9ECD/5FBAEF90" Ref="C?"  Part="1" 
AR Path="/5FBAEF90" Ref="C?"  Part="1" 
AR Path="/5F8CC9DA/5FBAEF90" Ref="C37"  Part="1" 
F 0 "C37" H 7365 1946 50  0000 L CNN
F 1 "4.7uF" H 7365 1855 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D6.3mm_P2.50mm" H 7288 1750 50  0001 C CNN
F 3 "~" H 7250 1900 50  0001 C CNN
F 4 "1276-1055-1-ND" H 7250 1900 50  0001 C CNN "Digikey"
F 5 "Samsung" H 7250 1900 50  0001 C CNN "Manufacturer"
F 6 "CL31B475KAHNNNE" H 7250 1900 50  0001 C CNN "MPN"
	1    7250 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	7250 1800 7250 1650
Connection ~ 7250 1650
Wire Wire Line
	7250 1650 7450 1650
Wire Wire Line
	7250 2000 7250 2200
$Comp
L power:GND #PWR?
U 1 1 5FBB121E
P 7250 2200
AR Path="/5F4A9ECD/5FBB121E" Ref="#PWR?"  Part="1" 
AR Path="/5FBB121E" Ref="#PWR?"  Part="1" 
AR Path="/5F8CC9DA/5FBB121E" Ref="#PWR0117"  Part="1" 
F 0 "#PWR0117" H 7250 1950 50  0001 C CNN
F 1 "GND" H 7255 2027 50  0000 C CNN
F 2 "" H 7250 2200 50  0001 C CNN
F 3 "" H 7250 2200 50  0001 C CNN
	1    7250 2200
	1    0    0    -1  
$EndComp
$EndSCHEMATC
