% Koef. für Simulation
g=9.81;
A=0.00278;
A12=18.54e-6;
A23=17.5e-6;
A34=18.75e-6;
A4=13.44e-6;
hmax=0.338;

T_a = 1;
steps = 1800/T_a;

T_n=127;
T_v=12.7;
K_p=5;

% Koef. für Diskreten Regler
T_1 = T_n/2 + sqrt(T_n^2/4 -T_n*T_v);
T_2 = T_n/2 - sqrt(T_n^2/4 -T_n*T_v);
T_p = min(T_1,T_2)*0.05;

K_pid = K_p/T_n;

G_par = K_pid*tf([T_1*T_2 T_1+T_2 1],[T_p 1 0]);
    
H = c2d(G_par,T_a,'tustin');

b = cell2mat(H.num);
a = cell2mat(H.den);

set_param('diskr_matlab','IgnoredZcDiagnostic','none');