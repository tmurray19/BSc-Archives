# Name:        Taidgh Murray
# Student ID:  15315901

# File:        fizzbuzz.py

############################################################################
def fizz(n):
	for i in range(1, n+1):
		if i%3==0:
			print("Fizz")
		else:
			print(i)

def buzz(n):
	for i in range(1, n+1):
		if i%5==0:
			print("Buzz")
		else:
			print(i)
def fizzbuzz(n):
        for i in range(1, n+1):
                if i%3==0 and i%5==0:
                        print("FizzBuzz")
                elif i%5==0:
                        print("Buzz")
                elif i%3==0:
                        print("Fizz")
                else:
                        print(i)
def main():
        print("fizz")
        print("-----")
        fizz(15)
        print()
        print("buzz")
        print("-----")
        buzz(15)
        print()
        print("fizzbuzz")
        print("----------")
        fizzbuzz(15)

main()
	
