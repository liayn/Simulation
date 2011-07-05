% System mit P-Regler
% Handventilstellungen:5 5 5 1 Umdrehungen ge�ffnet
% Sollwert erst 4V dann 3V
% 1. Spalte: U-pumpe
% 2. Spalte: Istwert h4 in Volt
% 3. Spalte: Sollwert h4 in Volt
%1 Volt= 3,38 cm
% Verst�rkung P-Regler K=5
%----------------------------------------------
t=(0:276)*5; %Zeitvektor Abtastintervall 5 s
x=[0.0000	0.1730	3.9900
9.8910	0.1730	3.9850
9.8870	0.2240	3.9860
9.8890	0.4410	3.9860
9.8860	0.7130	3.9870
9.8880	1.0310	3.9900
9.8840	1.2430	3.9870
9.8890	1.3860	3.9870
9.8830	1.6430	3.9840
9.8810	1.9400	3.9880
9.2590	2.2480	3.9870
7.7830	2.5590	3.9850
6.1080	2.8890	3.9860
4.5760	3.1960	3.9860
3.1910	3.4650	3.9870
2.0190	3.6910	3.9870
1.0930	3.8520	3.9910
0.5390	3.9410	3.9870
0.3460	3.9610	3.9890
0.3350	3.9610	3.9870
0.3710	3.9460	3.9880
0.6580	3.8680	3.9880
1.1250	3.7680	3.9870
1.6040	3.6690	3.9860
2.1120	3.5660	3.9870
2.6550	3.4590	3.9890
3.1260	3.3670	3.9900
3.6390	3.2580	3.9880
4.0790	3.1780	3.9890
4.4430	3.1030	3.9900
4.8280	3.0320	3.9870
5.0610	2.9950	3.9850
5.1460	2.9860	3.9880
5.1490	2.9860	3.9880
5.1170	3.0010	3.9890
4.8850	3.0640	3.9870
4.5060	3.1430	3.9890
4.1760	3.2050	3.9870
3.8800	3.2610	3.9830
3.6600	3.2980	3.9870
3.5750	3.3050	3.9890
3.5740	3.3050	3.9890
3.5990	3.2920	3.9870
3.8840	3.2200	3.9870
4.2130	3.1580	3.9890
4.4890	3.1020	3.9880
4.7360	3.0580	3.9890
4.8520	3.0470	3.9850
4.8540	3.0470	3.9890
4.8580	3.0470	3.9880
4.8400	3.0570	3.9900
4.6040	3.1140	3.9890
4.3220	3.1710	3.9890
4.0800	3.2180	3.9880
3.8720	3.2590	3.9890
3.7230	3.2800	3.9880
3.7040	3.2800	3.9870
3.7070	3.2800	3.9890
3.7460	3.2580	3.9880
4.0090	3.1990	3.9840
4.2800	3.1510	3.9880
4.4980	3.1040	3.9860
4.6760	3.0730	3.9880
4.7610	3.0640	3.9870
4.7710	3.0640	3.9880
4.7700	3.0640	3.9890
4.7350	3.0800	3.9870
4.5570	3.1210	3.9850
4.3110	3.1700	3.9850
4.1080	3.2100	3.9890
3.9470	3.2370	3.9880
3.8390	3.2540	3.9880
3.7940	3.2620	3.9900
3.8090	3.2540	3.9850
3.8280	3.2530	3.9870
3.9530	3.2170	3.9880
4.1460	3.1740	3.9880
4.3390	3.1390	3.9880
4.5270	3.1020	3.9880
4.6370	3.0830	3.9890
4.6810	3.0810	3.9860
4.6830	3.0810	3.9880
4.6800	3.0810	3.9890
4.6810	3.0810	3.9880
4.6150	3.1050	3.9880
4.4540	3.1410	3.9870
4.2700	3.1750	3.9880
4.1240	3.2020	3.9910
4.0140	3.2190	3.9880
3.9580	3.2280	3.9880
3.9580	3.2280	3.9870
3.9570	3.2280	3.9890
3.9620	3.2280	3.9880
4.0010	3.2120	3.9880
4.1200	3.1850	3.9900
4.2680	3.1590	3.9890
4.3670	3.1400	3.9880
4.4660	3.1170	3.9890
4.5480	3.1070	3.9880
4.5550	3.1070	3.9870
4.5560	3.1070	3.9900
4.5560	3.1070	3.9880
4.5550	3.1070	3.9870
4.5570	3.1090	3.9860
4.4810	3.1310	3.9870
4.3410	3.1580	3.9900
4.2340	3.1760	3.9870
4.1650	3.1930	3.9890
4.0880	3.2030	3.9880
4.0870	3.2020	3.9880
4.0870	3.2020	3.9890
4.0900	3.2020	3.9870
4.0840	3.2020	3.9860
4.0830	3.1990	3.9890
4.1650	3.1800	3.9890
4.2510	3.1620	3.9890
4.3420	3.1500	3.9870
4.4160	3.1300	3.9890
4.4850	3.1160	3.9870
4.5130	3.1160	3.9880
4.5120	3.1160	3.9870
4.5190	3.1160	3.9910
4.5160	3.1160	3.9870
4.5140	3.1150	3.9890
4.4800	3.1240	3.9870
4.3810	3.1490	3.9880
4.2810	3.1680	3.9900
4.1930	3.1840	3.9860
4.1340	3.1930	3.9870
4.0890	3.2020	3.9880
4.0890	3.2020	3.9880
4.0870	3.2020	3.9880
4.0860	3.2020	3.9880
4.1140	3.1930	3.9880
4.1420	3.1840	3.9860
4.2200	3.1690	3.9870
4.2890	3.1590	3.9870
4.3360	3.1440	3.9890
4.4100	3.1330	3.9860
4.4650	3.1240	3.9900
4.4740	3.1170	3.9860
4.5140	3.1150	3.9870
4.4940	3.1180	3.9870
4.4710	3.1240	3.9870
4.4690	3.1240	3.9890
4.4750	3.1240	3.9890
4.4040	3.1480	3.9870
4.3050	3.1640	3.9890
4.2270	3.1760	3.9910
4.1690	3.1920	3.9890
4.1190	3.2010	3.9880
4.0830	3.2020	3.9880
4.0870	3.2020	3.9880
4.0900	3.2020	3.9880
4.0830	3.2020	3.9880
4.1190	3.1930	3.9900
4.1310	3.1860	3.9890
4.2100	3.1760	3.9890
4.2530	3.1640	3.9870
4.2970	3.1530	3.9880
4.3610	3.1420	3.9860
4.3870	3.1420	3.9880
4.3870	3.1420	3.9890
4.3840	3.1420	3.9870
4.3810	3.1420	3.9890
4.3810	3.1420	3.9880
4.3860	3.1420	3.9870
4.3840	3.1420	3.9890
4.3810	3.1410	3.9880
4.3790	3.1490	3.9870
4.3410	3.1580	3.9870
4.2800	3.1670	3.9870
4.2390	3.1760	3.9890
4.2170	3.1770	3.9880
4.1720	3.1840	3.9890
4.1750	3.1850	3.9840
4.1680	3.1850	3.9910
0.0000	3.1840	2.9940
0.0000	3.1850	2.9940
0.0000	3.1760	2.9910
0.0000	3.1500	2.9920
0.0000	3.0930	2.9910
0.0000	3.0100	2.9910
0.3950	2.9120	2.9920
0.8750	2.8170	2.9900
1.2990	2.7310	2.9930
1.7850	2.6310	2.9940
2.2420	2.5410	2.9910
2.6620	2.4590	2.9940
3.0790	2.3680	2.9910
3.5450	2.2720	2.9950
4.0260	2.1820	2.9940
4.3780	2.1200	2.9910
4.5720	2.0900	2.9890
4.6140	2.0900	2.9900
4.5700	2.1050	2.9900
4.4740	2.1230	2.9920
4.3460	2.1520	2.9910
4.2130	2.1790	2.9900
4.0660	2.2130	2.9910
3.8300	2.2600	2.9910
3.7310	2.2690	2.9920
3.7630	2.2610	2.9930
3.8050	2.2460	2.9920
3.9370	2.2150	2.9910
4.1530	2.1690	2.9910
4.3360	2.1340	2.9930
4.4420	2.1230	2.9930
4.4450	2.1230	2.9900
4.4380	2.1310	2.9920
4.4030	2.1320	2.9880
4.3640	2.1410	2.9930
4.3230	2.1540	2.9910
4.2200	2.1780	2.9920
4.0830	2.2040	2.9920
3.9520	2.2270	2.9910
3.8930	2.2410	2.9920
3.8540	2.2440	2.9920
3.8710	2.2360	2.9900
3.8940	2.2360	2.9920
3.8940	2.2280	2.9920
3.9450	2.2180	2.9910
4.0240	2.2010	2.9900
4.1270	2.1840	2.9910
4.2140	2.1660	2.9920
4.2710	2.1580	2.9920
4.2770	2.1580	2.9930
4.3150	2.1500	2.9920
4.3220	2.1500	2.9890
4.3190	2.1500	2.9910
4.2780	2.1580	2.9910
4.2000	2.1750	2.9920
4.1180	2.1990	2.9910
3.9930	2.2180	2.9910
3.9140	2.2360	2.9920
3.8920	2.2360	2.9930
3.8930	2.2360	2.9910
3.8960	2.2360	2.9920
3.8930	2.2350	2.9910
3.8910	2.2330	2.9900
3.9300	2.2270	2.9940
3.9780	2.2170	2.9890
4.0410	2.2010	2.9910
4.1130	2.1840	2.9910
4.1860	2.1750	2.9900
4.2340	2.1670	2.9910
4.2360	2.1670	2.9930
4.2330	2.1660	2.9930
4.2330	2.1660	2.9920
4.2360	2.1680	2.9930
4.1870	2.1820	2.9900
4.1090	2.1980	2.9920
4.0160	2.2180	2.9910
3.9550	2.2270	2.9900
3.8940	2.2360	2.9910
3.8930	2.2360	2.9920
3.8950	2.2360	2.9910
3.8930	2.2360	2.9890
3.8920	2.2360	2.9910
3.9340	2.2270	2.9910
3.9380	2.2250	2.9930
3.9840	2.2100	2.9920
4.0540	2.1990	2.9900
4.1250	2.1830	2.9880
4.1830	2.1750	2.9920
4.1910	2.1740	2.9920
4.2320	2.1660	2.9920
4.2340	2.1660	2.9920
4.2120	2.1750	2.9910
4.1910	2.1750	2.9890
4.1900	2.1790	2.9890
4.1210	2.1950	2.9910
4.0360	2.2100	2.9910
3.9770	2.2180	2.9940
3.9680	2.2260	2.9920
3.9310	2.2270	2.9910
3.9370	2.2270	2.9900
];
plot(t,x(:,2)*0.0338,t,x(:,3)*0.0338)
xlabel('Zeit [s]')
ylabel('h4 [m]')
figure
plot(t,x(:,1))
xlabel('Zeit [s]')
ylabel('u [V]')
