#Decorator lab
#Student I.D: 15315901

#iterates through list of *args, and prints out length
def foo(*args):
	length=0
	for i in args:
		length+=1
	return length


#Tester code
print(foo("two", "args"))
print(foo("or", "three", "args"))

#modulo divides all numbers by 37 and returns the value
def normalize_37(func):
	def calculate(*args):
		return func (*(i % 37 for i in args)) % 37
	return calculate


#Tester code
def add(x,y):
	return x+y

print("add = ", add(45,67))

@normalize_37
def add(x, y):
	return x+y

print("normalize add = ", add(45, 67))

@normalize_37
def bar(n):
	if n >= 37 or n <= -1:
		raise ValueError
	else:
		return n

print(bar(123))
