# Name:        Taidgh Murray
# Student ID:  15315901

# File:        prime.py

############################################################################


def isprime(n):
        global x
        x = True
        for i in range (2, n):
                if n%i == 0:
                        x = False
                        break
        if x:
                return True
        else:
                return False


def main():
        n=int(input("Please enter integer: "))
        for f in range(1, n+1):
                isprime(f)
                if x==True:
                        print(f, end=" ")
main()
