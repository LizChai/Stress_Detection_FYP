clear all; close all; clc;

V_In = 3.3; %V
R_GSR = 200000:100:10000000; %Ohms; minimum GSR is 200k, otherwise Vout is negative
V_GSR = R_GSR./(200000+R_GSR)*(V_In/2); 
V_Out = 2*(V_GSR-V_In/4);

figure
semilogx(R_GSR, V_Out)
xlabel('GSR Resistance')
ylabel('Vout')
title('Vout vs GSR Resistance')

Analogue = V_Out/V_In * 1024;

figure
semilogx(R_GSR, Analogue)
xlabel('GSR Resistance')
ylabel('Analogue Out')
title('Analogue Out vs GSR Resistance')

% A = 0:491;
A = Analogue;
R = 100000*(2^10+2*A)./(2^9-A);

hold on
semilogx(R, A)
xlabel('Resistance')
ylabel('Analogue')
title('Analogue vs Resistance')
legend('Expected Analogue Reading from set Resistance', 'Calculated Resistance from set Analogue Reading', 'location', 'best')