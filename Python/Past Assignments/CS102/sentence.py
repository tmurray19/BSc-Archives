# Name:        Taidgh Murray
# Student ID:  15315901

# File:        sentence.py

############################################################################

sen=input("Please type a sentence here: ")
amount=len(sen.split())
print("There are" ,amount, "words in this sentence")
newsen=sen.replace(" ", "")
letters=len(newsen)
avg=letters/amount

print("The average word lenght is", avg)
