takes(tom, ct331).
takes(mary, ct331).
takes(joe, ct331).
takes(tom, ct345).
takes(mary, ct345).
instructs(bob, ct331).
instructs(ann, ct345).

teaches(Teacher, Student) :-
    instructs(Teacher, X),
    takes(Student, X).

classmates(StudentA, StudentB) :-
    takes(StudentA, X),
    takes(StudentB, X).
