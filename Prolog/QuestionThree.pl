contains1(EL,LST):-
    %checks if an element EL is the same as the
    %head of a given list LST
    %Splits list into head H & tail T
    %Then compares the given element EL to the head H of the
    %list LST
   [H|_T] = LST,
   EL=H.

contains2(EL,LST):-
    %checks to see if a give a given
    %list LST is the same as a tail
    %of another given list EL
    [_H|EL] = LST.

