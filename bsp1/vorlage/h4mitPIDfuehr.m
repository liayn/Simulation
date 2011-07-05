% System mit PID-Regler
%Parameter: K=5 TV=12,73 TN=127,3
% Handventilstellungen:5 4 4 3 Umdrehungen ge�ffnet
% Sollwertspr�nge 0V 2,5V  3V  2V
% 1. Spalte: U-pumpe
% 2. Spalte: Istwert h4 in Volt
% 3. Spalte: Sollwert h4 in Volt
%1 Volt= 3,38 cm
%----------------------------------------------
t=(0:360)*5; %Zeitvektor Abtastintervall 5 s
x=[2.9170	0.0960	0.0000
2.8940	0.0960	0.0000
9.8924	0.0960	2.4910
9.5238	0.1010	2.4900
9.3480	0.1960	2.4880
8.9270	0.3400	2.4910
8.1060	0.5000	2.4890
7.6270	0.6630	2.4860
7.2630	0.8190	2.4910
6.9590	0.9680	2.4880
6.2720	1.1560	2.4890
6.5860	1.2210	2.4900
7.5600	1.2430	2.4910
7.7680	1.2750	2.4890
7.9790	1.3090	2.4900
6.1620	1.4760	2.4890
6.3340	1.5560	2.4900
6.5220	1.6170	2.4910
6.4320	1.6880	2.4900
5.9190	1.7730	2.4910
5.9740	1.8320	2.4910
5.8920	1.8930	2.4900
5.7940	1.9460	2.4920
5.8820	1.9810	2.4910
5.8670	2.0150	2.4890
5.8510	2.0480	2.4900
5.7220	2.0870	2.4900
5.7480	2.1150	2.4910
5.6980	2.1410	2.4900
5.7340	2.1640	2.4900
5.6900	2.1840	2.4900
5.6840	2.2050	2.4900
5.6240	2.2270	2.4890
5.6940	2.2360	2.4920
5.7630	2.2490	2.4890
5.6900	2.2620	2.4870
5.7260	2.2700	2.4900
5.7590	2.2790	2.4920
5.7840	2.2870	2.4890
5.7720	2.2960	2.4890
5.9050	2.2960	2.4890
5.9680	2.2960	2.4880
5.8810	2.3040	2.4900
5.8610	2.3130	2.4920
5.8520	2.3230	2.4910
5.7450	2.3440	2.4900
5.6880	2.3560	2.4900
5.7120	2.3640	2.4940
5.7250	2.3730	2.4900
5.7720	2.3820	2.4900
5.7010	2.3910	2.4890
5.7200	2.3990	2.4920
5.7880	2.3990	2.4920
5.7300	2.4080	2.4900
5.8210	2.4080	2.4910
5.7190	2.4170	2.4910
5.8140	2.4170	2.4910
5.7290	2.4250	2.4910
5.8030	2.4260	2.4910
5.7410	2.4340	2.4900
5.8110	2.4340	2.4910
5.8460	2.4340	2.4910
5.8660	2.4340	2.4890
5.7720	2.4430	2.4940
5.7180	2.4510	2.4890
5.7900	2.4510	2.4880
5.8350	2.4510	2.4890
5.7370	2.4600	2.4910
5.8110	2.4600	2.4910
5.7220	2.4680	2.4910
5.7740	2.4680	2.4910
5.7850	2.4760	2.4900
5.7340	2.4770	2.4900
5.7860	2.4770	2.4900
5.8040	2.4770	2.4900
5.8240	2.4770	2.4900
5.8230	2.4770	2.4890
5.8350	2.4770	2.4900
5.8420	2.4770	2.4880
5.7460	2.4850	2.4900
5.7810	2.4850	2.4900
5.8220	2.4850	2.4890
5.7070	2.4940	2.4900
5.7080	2.5030	2.4910
5.7150	2.5030	2.4910
5.7560	2.5030	2.4920
5.7700	2.5030	2.4900
5.7780	2.5030	2.4900
5.7840	2.5030	2.4890
5.7870	2.5030	2.4920
5.6710	2.5120	2.4910
5.7340	2.5120	2.4900
5.7520	2.5120	2.4900
5.7570	2.5120	2.4900
5.7580	2.5120	2.4890
5.6450	2.5200	2.4910
5.7020	2.5220	2.4900
5.5530	2.5370	2.4910
5.5700	2.5380	2.4880
5.4880	2.5460	2.4910
5.5580	2.5470	2.4910
5.4450	2.5550	2.4910
5.5090	2.5550	2.4900
5.5240	2.5550	2.4890
5.5160	2.5550	2.4910
5.5140	2.5550	2.4890
5.5100	2.5550	2.4900
5.5020	2.5550	2.4890
5.4950	2.5550	2.4920
5.4940	2.5550	2.4930
5.4830	2.5550	2.4870
5.4800	2.5550	2.4920
5.4710	2.5550	2.4930
5.5510	2.5520	2.4890
5.5180	2.5470	2.4900
5.5390	2.5460	2.4900
5.5080	2.5460	2.4920
5.4970	2.5460	2.4900
5.4890	2.5460	2.4900
5.4880	2.5460	2.4910
5.4850	2.5470	2.4900
5.8030	2.5380	2.4930
8.1370	2.5380	2.9880
8.1880	2.5380	2.9880
8.2750	2.5380	2.9880
8.3710	2.5380	2.9890
8.3620	2.5460	2.9880
8.2160	2.5750	2.9890
7.6310	2.6340	2.9870
7.1930	2.7060	2.9880
6.9050	2.7700	2.9890
6.7320	2.8300	2.9900
6.3960	2.8950	2.9920
6.1310	2.9570	2.9880
6.0080	3.0050	2.9900
5.8620	3.0470	2.9890
5.7870	3.0860	2.9890
5.6060	3.1180	2.9910
5.5580	3.1420	2.9900
5.5270	3.1630	2.9880
5.4710	3.1760	2.9890
5.5870	3.1760	2.9890
5.6090	3.1760	2.9890
5.5880	3.1760	2.9880
5.5600	3.1760	2.9890
5.5310	3.1760	2.9900
5.5000	3.1770	2.9890
5.4770	3.1760	2.9900
5.5740	3.1680	2.9890
5.6150	3.1590	2.9910
5.7040	3.1420	2.9910
5.8610	3.1220	2.9890
5.9400	3.0990	2.9890
6.0660	3.0770	2.9900
6.2100	3.0560	2.9870
6.1380	3.0460	2.9900
6.1150	3.0330	2.9900
6.1350	3.0300	2.9880
6.0850	3.0210	2.9900
6.1540	3.0210	2.9870
6.1040	3.0210	2.9900
6.1020	3.0210	2.9910
6.1020	3.0210	2.9920
6.1000	3.0210	2.9870
6.1070	3.0210	2.9900
6.1060	3.0210	2.9900
6.1080	3.0210	2.9880
6.1120	3.0210	2.9910
6.1060	3.0210	2.9890
6.1100	3.0210	2.9890
6.1140	3.0210	2.9910
6.1140	3.0210	2.9900
6.1160	3.0210	2.9930
6.1190	3.0210	2.9890
6.0600	3.0290	2.9890
6.0530	3.0300	2.9910
6.0570	3.0290	2.9910
6.0690	3.0290	2.9880
6.0780	3.0290	2.9890
6.0750	3.0330	2.9910
5.9680	3.0350	2.9890
6.0090	3.0380	2.9900
6.0250	3.0380	2.9890
5.9620	3.0470	2.9880
5.9410	3.0470	2.9880
5.9770	3.0470	2.9890
5.9740	3.0470	2.9910
5.9700	3.0470	2.9880
5.9720	3.0470	2.9910
5.9690	3.0470	2.9880
5.8450	3.0550	2.9890
5.8970	3.0530	2.9910
5.9020	3.0550	2.9900
5.9060	3.0550	2.9870
5.8940	3.0550	2.9890
5.8960	3.0550	2.9900
5.8890	3.0550	2.9910
5.8990	3.0540	2.9890
5.9800	3.0470	2.9870
5.9440	3.0470	2.9890
5.9240	3.0470	2.9900
5.9130	3.0470	2.9890
5.8980	3.0460	2.9890
5.9100	3.0470	2.9890
5.9020	3.0470	2.9900
5.9000	3.0460	2.9870
5.8980	3.0460	2.9900
5.8910	3.0460	2.9870
5.8850	3.0470	2.9900
5.8860	3.0470	2.9910
5.8850	3.0470	2.9890
5.8800	3.0470	2.9880
5.8790	3.0470	2.9900
5.8740	3.0470	2.9880
5.8700	3.0470	2.9890
5.8670	3.0470	2.9880
5.8620	3.0470	2.9900
5.8630	3.0470	2.9910
5.8560	3.0470	2.9900
5.8540	3.0470	2.9880
5.8490	3.0460	2.9890
5.8530	3.0470	2.9900
5.8440	3.0470	2.9870
5.8380	3.0470	2.9870
5.8350	3.0470	2.9880
5.8380	3.0460	2.9900
5.8320	3.0460	2.9880
5.8260	3.0470	2.9870
5.8230	3.0470	2.9900
5.9530	3.0370	2.9900
5.8870	3.0380	2.9870
5.8640	3.0380	2.9860
5.9890	3.0290	2.9920
5.9190	3.0290	2.9870
5.9080	3.0290	2.9890
5.9070	3.0290	2.9880
6.0260	3.0210	2.9910
5.9630	3.0200	2.9910
5.9480	3.0200	2.9890
5.9600	3.0140	2.9870
6.0470	3.0120	2.9890
1.0300	3.0120	2.6770
0.8140	3.0120	1.9910
0.6180	3.0120	1.9910
0.4380	3.0040	1.9910
0.5260	2.9830	1.9920
1.0410	2.9150	1.9920
1.7850	2.8180	1.9920
2.4550	2.6990	1.9900
3.2110	2.5650	1.9930
3.8770	2.4240	1.9900
4.7570	2.2730	1.9920
5.1820	2.1470	1.9920
5.5070	2.0360	1.9900
5.5090	1.9650	1.9900
5.5570	1.9100	1.9920
5.5860	1.8710	1.9900
5.3940	1.8560	1.9910
5.2700	1.8550	1.9920
5.1720	1.8640	1.9910
5.1600	1.8650	1.9920
5.1110	1.8730	1.9920
5.0870	1.8810	1.9900
5.1110	1.8900	1.9930
5.1350	1.8900	1.9930
5.3350	1.8810	1.9940
5.1740	1.8900	1.9930
5.2410	1.8900	1.9930
5.2860	1.8900	1.9920
5.3110	1.8900	1.9890
5.3350	1.8900	1.9940
5.2280	1.8990	1.9920
5.2810	1.9070	1.9950
5.2740	1.9100	1.9920
5.1780	1.9250	1.9930
5.0960	1.9340	1.9910
5.1220	1.9420	1.9940
5.1810	1.9420	1.9910
5.1560	1.9510	1.9930
5.3090	1.9420	1.9940
5.2930	1.9420	1.9930
5.1920	1.9510	1.9900
5.2270	1.9500	1.9930
5.3810	1.9420	1.9920
5.3500	1.9420	1.9930
5.3500	1.9440	1.9940
5.2600	1.9510	1.9920
5.3280	1.9510	1.9930
5.2590	1.9600	1.9920
5.2840	1.9600	1.9940
5.1980	1.9670	1.9910
5.2410	1.9760	1.9940
5.2160	1.9760	1.9930
5.2110	1.9860	1.9930
5.1940	1.9850	1.9930
5.1230	1.9940	1.9930
5.1960	1.9940	1.9930
5.2160	1.9920	1.9930
5.3510	1.9850	1.9940
5.2960	1.9850	1.9900
5.1540	1.9940	1.9930
5.2140	1.9910	1.9940
5.2660	1.9850	1.9940
5.2580	1.9940	1.9910
5.2330	1.9940	1.9890
5.1480	2.0020	1.9910
5.2160	2.0020	1.9930
5.2310	2.0020	1.9920
5.2640	2.0020	1.9940
5.2220	2.0020	1.9890
5.2450	2.0020	1.9910
5.1140	2.0110	1.9930
5.1800	2.0110	1.9920
5.2070	2.0110	1.9910
5.2160	2.0110	1.9920
5.2750	2.0020	1.9930
5.2240	2.0020	1.9910
5.2930	2.0020	1.9920
5.2780	2.0020	1.9920
5.1520	2.0110	1.9920
5.2210	2.0110	1.9920
5.1340	2.0200	1.9900
5.1600	2.0200	1.9920
5.3180	2.0110	1.9920
5.2670	2.0110	1.9910
5.1300	2.0200	1.9890
5.1860	2.0200	1.9920
5.1940	2.0200	1.9910
5.2020	2.0200	1.9920
5.2010	2.0200	1.9920
5.2050	2.0200	1.9910
5.0950	2.0290	1.9930
5.2700	2.0200	1.9890
5.2200	2.0200	1.9910
5.2100	2.0200	1.9930
5.0730	2.0280	1.9920
5.1410	2.0290	1.9930
5.1610	2.0290	1.9920
5.1570	2.0290	1.9920
5.1620	2.0290	1.9910
5.1640	2.0290	1.9920
5.1550	2.0290	1.9960
5.1600	2.0290	1.9930
5.1870	2.0230	1.9920
5.2550	2.0200	1.9910
5.2090	2.0200	1.9920
5.2070	2.0200	1.9920
5.2000	2.0200	1.9960
5.2020	2.0200	1.9930
5.1940	2.0260	1.9920
5.0980	2.0280	1.9930
5.1450	2.0280	1.9910
5.1560	2.0290	1.9950
5.1540	2.0290	1.9930
5.1560	2.0290	1.9910
5.1540	2.0280	1.9940
5.1540	2.0280	1.9910
5.1500	2.0280	1.9940
5.1500	2.0280	1.9950
5.2720	2.0200	1.9940
5.2220	2.0200	1.9920
]
plot(t,x(:,2)*0.0338,t,x(:,3)*0.0338,h(:,1),h(:,2),h(:,1),h(:,3),h(:,1),h(:,4),h(:,1),h(:,5))
xlabel('Zeit [s]')
ylabel('h1, h2, h3, h4 [m]')
figure
plot(t,x(:,1),up(:,1),up(:,2))
xlabel('Zeit [s]')
ylabel('u [V]')