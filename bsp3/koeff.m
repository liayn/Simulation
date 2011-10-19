
g = 9.81
v = 3
bm = 5           %bike mass
dm = 50          %biker mass
d = 0.6          %tire (diameter i guess)
h = 0.9          %bike height
dh = 0.5         %biker height

m = bm + dm      %total mass
J = bm*h*h       %trägheitsmoment of bike
Js = dm*dh*dh    %trägheitsmoment of biker

Ki = [0.05 0.05]
Kp = [0.005 0.005]
Kd = [0.00001 0.00001]

tau = 0.01
               % P     I     D    Regler
H1 = pidDiscret(0.005,0.05,0.00001,tau); %Lenker
H2 = pidDiscret(0.005,0.05,0.00001,tau); %Fahrer

% constants in the model

dmv = d*1*v
mv2 = m * v * v
mhg = 1 / (m*h*g)
Jsh2m = Js + h*h*m
h2mg = h/2*m*g       