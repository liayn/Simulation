function H = pidDiscret( K_p, T_n, T_v, T_a )

T_n = 1/T_n;

% Koef. für Diskreten Regler
T_1 = T_n/2 + sqrt(T_n^2/4 -T_n*T_v);
T_2 = T_n/2 - sqrt(T_n^2/4 -T_n*T_v);
T_p = min(T_1,T_2)*0.05;

K_pid = K_p/T_n;

G_par = K_pid*tf([T_1*T_2 T_1+T_2 1],[T_p 1 0]);
    
H = c2d(G_par,T_a,'tustin');

end