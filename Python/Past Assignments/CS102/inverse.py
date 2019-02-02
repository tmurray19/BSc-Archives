# Name:        Taidgh Murray
# Student ID:  15315901	

# File:        inverse.py

############################################################################

def gcd(a, b):
	if a == 0:
		return (b, 0, 1)
	else:
		g, y, x = egcd (b % a, a)
		return (g, x - (b // a) * y, y)

def inverse(i, n):
	g, x, y = gcd(i, n)
	if g !=1:
		print("None")
	else:
		print("Modular inverse =", x % n)
	
i=abs(int(input("Please insert positive integer (i): ")))
n=abs(int(input("Please insert positive integer (n): ")))
inverse(i,n)