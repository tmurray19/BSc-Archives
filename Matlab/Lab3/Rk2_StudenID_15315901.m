%% Euler_solution.m
% A MATLAB script file that generates a table showing the 
% convergence of Euler's method.
% WRITTEN BY: Niall Madden, NUI Galway. Niall.Madden@NUIGalway.ie
% DATE:      12 November 2018
% FOR:        MA385, Lab 2 (solution).
% See also:   http://www.maths.nuigalway.ie/MA385/

clear;  % clear any old  variables

f = @(t,y)(y./(1 + t.^2));
%f = @(t,y)(3*t-2*y/t);
y = @(t)(exp(atan(t)));
%y = @(t)();

fprintf('\n-----------------------------------\n');
fprintf('|     Eulers Method (Solution)     |\n');
fprintf('|        MA385: Lab 2              |\n');
fprintf('-----------------------------------\n');

%calculate a, alpha and beta
%student ID: 15315901
b = 1;
a = 1-b;
alpha = 1/2(b);
beta = alpha;


t0=0; % initial time
T=4;  % final time
fprintf('| %4s | %6s | %9s | %4s |\n', ...
   'n', 'y(n)', 'E(n)', 'rho');
for j=1:9
   n = 2^j; %%% <--- This is the number of points used.
   h = (T-t0)/n;  % h=t_k-t_{k-1}
     
   t=t0:h:T;    % time steps
   Y0=1;         % Initial value
   
   Y(1)=Y0;
   
   %% The method:
   for i=1:n
      %RK 2 modification
      %adding k1, and k2 to for loop
      k1 = f(t(i), Y(i));
      k2 = f(t(i)+alpha*h, Y(i)+beta*h*k1);
      Y(i+1) = Y(i) + h*(a*k1 + b*k2);
   end
   %%
   %p(n)= log2(abs(Error(n/2)./abs(Error(n))));
   Error(j) = abs(Y(n+1) - y(T));
   if (j==1)
      p(j)=nan;
   else
      p(j)= log2(Error(j-1)./Error(j));
   end
   fprintf('| %4d |',n);
   fprintf(' %6.2f |',Y(n+1));
   fprintf(' %9.3e |',Error(j));
   fprintf(' %4.2f |\n',p(j));
end



%Plot of calculations     
plot(t,y(t), t,Y, '--o');
title(n);
legend('True Solution','RK2', 0);
