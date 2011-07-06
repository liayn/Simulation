%Programm zur Berechnung der Koeffizienten für den zeitdiskreten Regler
%----------------------------------------------------------------------
%Vor Ausführung die Werte der Konstanten definieren oder "load default"
%ausführen.
a_0=T_1/T_2*exp(-T_a*(1/T_2-1/T_1));
a_1=T_1/T_2*exp(-T_a/T_2);
b_1=exp(-T_a/T_2);