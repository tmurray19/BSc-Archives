#student I.D: 15315901

"""A class for Gaussian integers
	A Gaussing integer is a complex number of the form a+bi where a and b are integers"""

"""write the code for the class Gaussian which models Gaussian integers. Your code should have:
1. A constructor so that we can create objects of the class Gaussian as follows:
	z = Gaussian(4, -2)
The arguments to the constructor should be converted to ints using the int function.

2. A string representation using the __str__ method.

3. Methods __eq__ and __neq___ for equality testing.

4. Methods for doing arithmetic on Gaussian integers, in particular The following methods should be implemented:

	5. __add__ and __radd__ for addition.
	6. __sub__ and __rsub__	for subtraction.
	7. __mul__ and __rmul__ for multiplication.
	8. For division, we cannot expect the quotient of two Gaussian integers to be a new Gaussian integer, so we will have to implement the methods __floordiv__ (for ‘integer’ division) and __mod__ for remainder.
	
For each of the arithmetic operations, one argument is allowed to be an int. The ‘integer’ division is defined in the following way: 
if z = a + bi and w = c + di, then we can form the quotient in the complex numbers:
z/w = (a + bi) / (c + di) = ((a + bi)(c − di)) /(c^2 + d^2) = (ac + bd)/(c^2 + d^2) + ((ad − bc)/ (c^2 + d^2)) i

Now we let the ‘integer’ quotient of z and w be q = m+ni, where m is the closest
integer to (ac+bd)/(c^2 +d^2) and n is the closest integer to 
(ad−bc)/(c^2+d^2)
Then we can define the remainder by as r = z − q*w."""

class Gaussian:
	"""A class for modeling gaussian integers"""
	
	def __init__(self, a, b):
		"""initialises the two values for the gaussian integer"""
		self.a=int(a)		
		self.b=int(b)	
	
	def __str__(self):
		"""for representing the gaussian integer as a string"""
		if self.a>=0 and self.b>=0:
			return("{}+{}i".format(self.a, self.b))
		if self.a>0 and self.b<0:
			return("{}{}i".format(self.a, self.b))		
		if self.a<0 and self.b>0:
			return("{}+{}i".format(self.a, self.b))
		if self.a<0 and self.b<0:
			return("{}{}i".format(self.a, self.b))
			
	def __eq__(self, other):
		"""for testing if two gaussian integers are the same"""
		return self.a == other.a and self.b == other.b
		
	def __add__(self, other):
		"""[a+bi]+[c+di]=[a+c,bi+di]"""
		if type(other) == int or type(other) == float:
			other = Gaussian(other,other)
		l = self.a + other.a
		r = self.b + other.b
		return Gaussian(l,r)
	
	def __radd__(self, other):
		if type(other) == int or type(other) == float:
			other = Gaussian(other,other)
		return other.__add__(self)
		
	def __sub__(self, other):
		"""[a+bi]-[c+di]=[a-c,bi-di]"""
		if type(other)==int or type(other)==float:
			other=Gaussian(other, other)
		l=self.a - other.a
		r=self.b - other.b
		return Gaussian(l,r)

	def __rsub__(self, other):
		if type(other) == int or type(other) == float:
			other = Gaussian(other, other)
		return other.__sub__(self)
		
	def __mul__(self, other):
		"""[a+bi]*[c+di]=[((a*c)-(b*d))+((a*d)+(b*d))]"""
		if type(other)==int or type(other)==float:
			other=Gaussian(other, other)
		l=((self.a * other.a)-(self.b*other.b))
		r=((self.a*other.b)+(self.b*other.a))
		return Gaussian(l,r)
	
	def __rmul__(self, other):
		if type(other)==int or type(other)==float:
			other=Gaussian(other,other)
		return other.__mul__(self)
		
	def __floordiv__(self, other):
		""" 
		if 
		z = a + bi 
		and 
		w = c + di 
		then we can form the quotient in the complex numbers:
		z/w = (a + bi) / (c + di) = ((a + bi)(c − di)) /(c^2 + d^2) = (ac + bd)/(c^2 + d^2) + ((ad − bc)/ (c^2 + d^2))i

		Now we let the ‘integer’ quotient of z and w be q = m+ni, where m is the closest
		integer to (ac+bd)/(c^2 +d^2) and n is the closest integer to (ad−bc)/(c^2+d^2)
		Then we can define the remainder by as r = z − q*w.
		"""
		if type(other)==int or type(other)==float:
			other=Gaussian(other,other)
		l=((self.a*other.a)+(self.b*other.b))/((other.a**2)+(other.b**2))
		r=((self.a*other.b)-(self.b*other.a))/((other.a**2)+(other.b**2))
		m=int(l)
		n=int(r)
		Gaussian.q=Gaussian(m,n)
		return Gaussian.q
	def __mod__(self, other):
		"""for finding the remainder for division
		r= z - q*w, z=a+bi, q=m+ni, w=c+di"""
		if type(other)==int or type(other)==float:
			other=Gaussian(other, other)
		return self - (Gaussian.q * other)
	

def test_equality():
	assert Gaussian.__eq__(Gaussian(1,1),Gaussian(3,5))==False
def test_addition():
	assert Gaussian.__add__(Gaussian(1,1),Gaussian(3,5)) == Gaussian(4,6)
def test_subtraction():
	assert Gaussian.__sub__(Gaussian(1,1),Gaussian(3,5)) == Gaussian(-2,-4)
def test_multiplication():
	assert Gaussian.__mul__(Gaussian(1,1),Gaussian(3,5)) == Gaussian(-2,8)
def test_floordivision():
	assert Gaussian.__floordiv__(Gaussian(1,1),Gaussian(3,5)) == Gaussian(0,0)
def test_mod():
	assert Gaussian.__mod__(Gaussian(1,1),Gaussian(3,5)) == Gaussian(1,1)
		

first = Gaussian(1,1)
second = Gaussian(3,5)
print(first,",", second)
print("{} == {} = {}".format(first, second, first==second))
print("{} + {} = {}".format(first,second,first+second))
print("{} - {} = {}".format(first,second, first-second))
print("{} * {} = {}".format(first, second, first*second))
print("{} // {} = {}".format(first, second, first//second))
print("{} % {} = {}".format(first, second, first%second))

test_equality()
test_addition()
test_subtraction()
test_multiplication()
test_floordivision()
test_mod()
