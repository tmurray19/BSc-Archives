%%  Using the Bisection method to find a zero of f(x)
% Who: Niall Madden (Niall.Madden@NUIGalway.ie)
% Why: Lab1 of MA385
% When: 02 Oct 2018

clear;

fprintf('\n\n---------\n Using Bisection\n');

% The function is
f = @(x)(exp(x) - (2-x).^3);

fprintf('Solving f=0 with the function\n');
disp(f);

%% The true solution is
tau = 0.72614446580549503614;
fprintf('The true solution is %12.8f\n\n', tau);

fprintf(' k |      x(k)      | |tau-x(k)|\n');
fprintf('---------------------------------\n');

%% Our initial guesses are x_1=0 and x_2 =2;
%% Text printouts for answers;

x(1)=0;
fprintf('%2d | %14.8e | %9.3e \n', 1, x(1), abs(tau - x(1)));

x(2)=5;
fprintf('%2d | %14.8e | %9.3e \n', 2, x(2), abs(tau - x(2)));

for k=2:8
   x(k+1) = (x(k-1)+x(k))/2;
   if ( f(x(k+1))*f(x(k-1)) < 0)
      x(k)=x(k-1);
   end
   fprintf('%2d | %14.8e | %9.3e\n', k+1, x(k+1), abs(tau - x(k+1)));
end

%{
% Student I.D: 15315901;
% Lab 1 Question 2 


% (a)

fprintf('\n\n---------\n Secant Method\n');

fprintf(' k |      x(k)      | |tau-x(k)|\n');
fprintf('---------------------------------\n');

x(1)=0;
fprintf('%2d | %14.8e | %9.3e \n', 1, x(1), abs(tau - x(1)));

x(2)=5;
fprintf('%2d | %14.8e | %9.3e \n', 2, x(2), abs(tau - x(2)));

for k=2:8

  x(k+1) = x(k) - (f(x(k))) * ((x(k) - x(k-1))/(f(x(k)) - f(x(k-1))));
  
  fprintf('%2d | %14.8e | %9.3e\n', k+1, x(k+1), abs(tau - x(k+1)));
end


% (b) Solution: 7.26144465e-01
% (c) You need 8 iterations 


%}


% Assignment 1 alterations;
% Student I.D: 15315901;
% Lab 1 Question 3



fprintf('\n\n---------\n Question 3\n');


fprintf('\n\n---------\nNo Power\n');
fprintf(' k |      x(k)      | |tau-x(k)|\n');
fprintf('---------------------------------\n');

x(1)=0;
fprintf('%2d | %14.8e | %9.3e \n', 1, x(1), abs(tau - x(1)));

x(2)=5;
fprintf('%2d | %14.8e | %9.3e \n', 2, x(2), abs(tau - x(2)));

for k=2:8
  x(k+1) = ( abs(tau - x(k-1) ) / abs(tau - x(k)) );
  fprintf('%2d | %14.8e | %9.3e\n', k+1, x(k+1), abs(tau - x(k+1)));
end


fprintf('\n\n---------\n^1.618\n');
fprintf(' k |      x(k)      | |tau-x(k)|\n');
fprintf('---------------------------------\n');

x(1)=0;
fprintf('%2d | %14.8e | %9.3e \n', 1, x(1), abs(tau - x(1)));

x(2)=5;
fprintf('%2d | %14.8e | %9.3e \n', 2, x(2), abs(tau - x(2)));

for k=2:8
  x(k+1) = ( abs(tau - x(k-1)) / (abs(tau - x(k))).^1.618 );
  fprintf('%2d | %14.8e | %9.3e\n', k+1, x(k+1), abs(tau - x(k+1)));
end


fprintf('\n\n---------\n^2\n');
fprintf(' k |      x(k)      | |tau-x(k)|\n');
fprintf('---------------------------------\n');

x(1)=0;
fprintf('%2d | %14.8e | %9.3e \n', 1, x(1), abs(tau - x(1)));

x(2)=5;
fprintf('%2d | %14.8e | %9.3e \n', 2, x(2), abs(tau - x(2)));

for k=2:8
  x(k+1) = ( ( abs( tau - x(k-1) )) / ( (abs( tau - x(k))).^2) );
  fprintf('%2d | %14.8e | %9.3e\n', k+1, x(k+1), abs(tau - x(k+1)));
end