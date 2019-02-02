%% Euler.m
% A MATLAB script file that implements Euler's method to numerically solve
%    y(t0)=y0,  y'(t)=f(t,y)
% on the interval [t0, tN]
% WRITTEN BY: Niall Madden, NUI Galway. Niall.Madden@NUIGalway.ie
% DATE:       05 November 2018
% FOR:        MA385, Lab 2.
% See also:   http://www.maths.nuigalway.ie/MA385/

% Student ID: 1531590
% Name: Taidgh Murray
% Course: 4BS9

%{
We were tasked with completing the table found in the .pdf file related to lab 2.
Specifically, we needed to calculate the rho for each n. The solution I have come up
with for this assignment is far from elegant, and could be very easily tied up with functions.
Regardless, it gives what I believe to be a correct, completed table, & shows that for Euler's
method, the rho value is close to 1.

%}


clear;  % clear any old  variables

%f = @(t,y)(y./(1 + t.^2));
f = @(t,y) ((3*t - 2*y)/t);
y = @(t)(exp(atan(t)));

fprintf('\n--------------------------\n');
fprintf(' ----  Eulers Method  ----\n');
fprintf(' ----  MA385 - Lab 2  ----\n');

t0=0; % initial time
y0=1; % Initial value: y(t0)=y0
T=4;  % final time

n = 2; % <--- This is the number of points used.
h = (T-t0)/n;  % h=t_k-t_{k-1}

t=t0:h:T;    % time steps

Y(1)=y0;

%% The method:
for i=1:n
    Y(i+1) = Y(i) + h*f(t(i), Y(i));
end

%% Compute and display errors
Error = abs(Y(n+1) - y(T));

fprintf(' n    |  y(n)    |  epsilon(n)  | rho(n/2) |\n');
fprintf('--------------------------------------------\n');
     
fprintf(' %d    | %f | %e | N/A      |\n', n, Y(n+1), Error);
prevError = Error;

% reset - n=4
clear -x prevError;

f = @(t,y)(y./(1 + t.^2));
y = @(t)(exp(atan(t)));

t0=0; 
y0=1; 
T=4;  

n = 4; 
h = (T-t0)/n;  

t=t0:h:T;   

Y(1)=y0;

for i=1:n
    Y(i+1) = Y(i) + h*f(t(i), Y(i));
end

Error = abs(Y(n+1) - y(T));

fprintf(' %d    | %f | %e | %f |\n', n, Y(n+1), Error, log2(prevError/Error));
prevError = Error;

% reset - n=8
clear -x prevError;

f = @(t,y)(y./(1 + t.^2));
y = @(t)(exp(atan(t)));

t0=0; 
y0=1; 
T=4;  

n = 8; 
h = (T-t0)/n;  

t=t0:h:T;   

Y(1)=y0;

for i=1:n
    Y(i+1) = Y(i) + h*f(t(i), Y(i));
end

Error = abs(Y(n+1) - y(T));

fprintf(' %d    | %f | %e | %f |\n', n, Y(n+1), Error, log2(prevError/Error));
prevError = Error;

% reset - n=16
clear -x prevError;

f = @(t,y)(y./(1 + t.^2));
y = @(t)(exp(atan(t)));

t0=0; 
y0=1; 
T=4;  

n = 16; 
h = (T-t0)/n;  

t=t0:h:T;   

Y(1)=y0;

for i=1:n
    Y(i+1) = Y(i) + h*f(t(i), Y(i));
end

Error = abs(Y(n+1) - y(T));

fprintf(' %d   | %f | %e | %f |\n', n, Y(n+1), Error, log2(prevError/Error));
prevError = Error;

% reset - n=32
clear -x prevError;

f = @(t,y)(y./(1 + t.^2));
y = @(t)(exp(atan(t)));

t0=0; 
y0=1; 
T=4;  

n = 32; 
h = (T-t0)/n;  

t=t0:h:T;   

Y(1)=y0;

for i=1:n
    Y(i+1) = Y(i) + h*f(t(i), Y(i));
end

Error = abs(Y(n+1) - y(T));

fprintf(' %d   | %f | %e | %f |\n', n, Y(n+1), Error, log2(prevError/Error));
prevError = Error;


% reset - n=64
clear -x prevError;

f = @(t,y)(y./(1 + t.^2));
y = @(t)(exp(atan(t)));

t0=0; 
y0=1; 
T=4;  

n = 64; 
h = (T-t0)/n;  

t=t0:h:T;   

Y(1)=y0;

for i=1:n
    Y(i+1) = Y(i) + h*f(t(i), Y(i));
end

Error = abs(Y(n+1) - y(T));

fprintf(' %d   | %f | %e | %f |\n', n, Y(n+1), Error, log2(prevError/Error));
prevError = Error;


% reset - n=128
clear -x prevError;

f = @(t,y)(y./(1 + t.^2));
y = @(t)(exp(atan(t)));

t0=0; 
y0=1; 
T=4;  

n = 128;
h = (T-t0)/n;  

t=t0:h:T;   

Y(1)=y0;

for i=1:n
    Y(i+1) = Y(i) + h*f(t(i), Y(i));
end

Error = abs(Y(n+1) - y(T));

fprintf(' %d  | %f | %e | %f |\n', n, Y(n+1), Error, log2(prevError/Error));
prevError = Error;

% reset - n=256
clear -x prevError;

f = @(t,y)(y./(1 + t.^2));
y = @(t)(exp(atan(t)));

t0=0; 
y0=1; 
T=4;  

n = 256; 
h = (T-t0)/n;  

t=t0:h:T;   

Y(1)=y0;

for i=1:n
    Y(i+1) = Y(i) + h*f(t(i), Y(i));
end

Error = abs(Y(n+1) - y(T));

fprintf(' %d  | %f | %e | %f |\n', n, Y(n+1), Error, log2(prevError/Error));
prevError = Error;


% reset - n=512
clear -x prevError;

f = @(t,y)(y./(1 + t.^2));
y = @(t)(exp(atan(t)));

t0=0; 
y0=1; 
T=4;  

n = 512; 
h = (T-t0)/n;  

t=t0:h:T;   

Y(1)=y0;

for i=1:n
    Y(i+1) = Y(i) + h*f(t(i), Y(i));
end

Error = abs(Y(n+1) - y(T));

fprintf(' %d  | %f | %e | %f |\n', n, Y(n+1), Error, log2(prevError/Error));
prevError = Error;


















     
plot(t,y(t), t,Y, '--o');
title(n);
legend('True Solution','Eulers Method', 0);
