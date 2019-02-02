sunny.
windy.
warm.
early.
happy.

and(A,B):- A,B.
or(A,B) :- A;B.
nand(A,B) :- (not(and(A,B))).
nor(A,B) :- not(or(A,B)).
xor(A,B) :- or(A,B), nand(A,B).


