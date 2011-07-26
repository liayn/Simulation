
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

Ki = [1 1]
Kp = [1 1]
Kd = [1 1]

tau = 0.2


dmv = d*m*v
mv2 = m * v * v
mhg = 1 / (m*h*g)
Jsh2m = Js + h*h*m
h2mg = h/2*m*g       