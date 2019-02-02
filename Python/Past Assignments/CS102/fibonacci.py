# Name:        Taidgh Murray
# Student ID:  15315901

# File:        fibonacci.py

############################################################################

def f():
        n = int(input("Please enter a number: "))
        print(fib(n))
	
def fib(n):
        if n==0:
                return 0
        elif n==1:
                return 1
        else:
                return fib(n-1)+fib(n-2)
f()
