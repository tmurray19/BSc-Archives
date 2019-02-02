# Name:        Taidgh Murray
# Student ID:  15315901

# File:        overtime.py

############################################################################
def main():
	hours = float(input("Enter number of hours worked: "))
	rateofpay = float(input("Enter rate of pay per hour: "))
	pay(hours, rateofpay)
	
def pay(hours, rateofpay):
	wages = hours * rateofpay
	print("Total pay: ", wages)
main()
