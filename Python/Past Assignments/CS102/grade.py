# Name:        Taidgh Murray	
# Student ID:  15315901

# File:        grade.py

############################################################################

x = int(input("Enter Result: "))
def grade(x):
    if x>100:
        return("Invalid Result")
    elif x>=70:
        return("A")
    elif x>=60:
        return ("B")
    elif x>=50:
        return("C")
    elif x>=45:
        return("D")
    elif x>=40:
        return("E")
    elif x>=0:
        return("F")
    elif x<0:
        return("Invalid Result")
print(grade(x))
    
