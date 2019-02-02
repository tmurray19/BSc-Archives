# Name:        Taidgh Murray	
# Student ID:  15315901

# File:        digram.py

############################################################################

from itertools import product

aeht = ('a','e','h','t')

two_letter_words = product(aeht, aeht)

for word in two_letter_words:
    print(''.join(word), sep='', end=' ')
