%Programm zur Berechnung der Koeffizienten f�r den zeitdiskreten Regler
%----------------------------------------------------------------------
%Vor Ausf�hrung die Werte der Konstanten definieren oder "load default"
%ausf�hren.
a_0=T_1/T_2*exp(-T_a*(1/T_2-1/T_1));
a_1=T_1/T_2*exp(-T_a/T_2);
b_1=exp(-T_a/T_2);