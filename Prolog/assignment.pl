%%%%Definitions for isElementInList(El, List)
%Base Case
isElementInList(El, [El|_]).

%Reductive Step
isElementInList(El, [_|T]):-
    isElementInList(El,T).

%%%%Definitions for reverseList(List, ReversedList)
%Base Case
reverseList([],[]).

%Reductive case
reverseList([ListH|ListT], ReversedList):-
    reverseList(ListT, RevT), mergeLists(RevT, [ListH], ReversedList).

%%%%Definitionas for insertElementIntoListEnd(El, List, NewList)
%Base Case
insertElementIntoListEnd(El, [], [El]).

insertElementIntoListEnd(El, [H|List], [H|NewList]):-
    insertElementIntoListEnd(El, List, NewList).

%%%%Definitions for mergeLists(List1, List2, Merged)
%Base Case
mergeLists([],L,L).

%Reductive Step
mergeLists([List1|Tail], List2, [List1|Merged]):-
    mergeLists(Tail, List2, Merged).
