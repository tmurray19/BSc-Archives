#CS211 Higher Order Function
#Student I.D: 15315901

from functools import *

#compose returns the value f(g(x))
#e.g if g(x) = x+3 & f(x) = x*2
#then f(g(x)) = (x*2)+3
def compose(f, g):
	return lambda x: f(g(x))

#tester
bar = compose(lambda x: 2*x, lambda x: x+3)
print("bar = ", bar(7))

#tester
foo = compose(lambda x: x+3, lambda x: 2*x)
print("foo = ", foo(7))

#compose_many is just an extension of compose
#compose_many iterates through the list backwards
#calculting the functions with the given variables
def compose_many(li):
	return lambda x: reduce(lambda r, f: f(r), reversed(li), x)

#tester
foo2 = compose_many([lambda x: x*3, lambda x: x+3, lambda x: x**2])
print("foo2 = ", foo2(3))

#fixpoint example f(c) == c
#f(c) = x^2
#f(1) = 1^2
#f(1) == 1
def fixpoint(x, f):
	for i in range(f):
		x = g(x)
	return x

l=fixpoint(10, lambda x: x**2)
print(l)

