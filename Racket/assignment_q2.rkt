#lang racket

;This is an example implementation of ins_beg,
;It obviously doesn't do what it should, so you
;can edit this function to get started.
;
;Please note the provide function is necessary
;for the unit tests to work. Please include a
;(provide) for each function you write in your
;submitted assignment.
;
;You may delete these comments!

;nah, ur good fam, imma leave them there thx


(provide ins_beg)
;ins_beg function, inserts element el into end of list lst
(define (ins_beg el lst)
  (cons el lst))
(ins_beg 2 '(4 6 8))

(provide ins_end)
;ins_end function, inserts element el into end of list lst
(define (ins_end el lst)
  (append lst (list el)))
(ins_end 7 '(1 3 5))

(provide ins_end)
;cout_top_level, counds the number of top levels items in a list
(define (cout_top_level lst)
  (if
   (null? lst) 0
   (+ 1 (cout_top_level(cdr lst))))
  )
(cout_top_level '(1 2 3 4 (4 1)))

(provide count_instances)
;count_instances, counds number of times an item occurs in a list
(define (count_instances el lst)
  (cond
    ((empty? lst) 0)
    ((equal? el (car lst))
     (+ 1 (count_instances el (cdr lst))))
    (else (count_instances el (cdr lst))))
 )
(count_instances 1 '(1 2 3 (1 1 34)))

(provide count_instances_tr)
;count_instances_tr, a tail-recursive version of cout_instances
 (define (count_instances_tr el lst)
   (count_instances_tr_helper el lst))
   
 (define (count_instances_tr_helper el lst)
   (cond
     ((empty? lst) 0)
     ((equal? el (car lst))
      (+ 1 (count_instances_tr_helper el (cdr lst))))
     (else (count_instances_tr_helper el (cdr lst)))
   ))
(count_instances_tr 4 '(4 4 1 3 41 4 4( 4 42 134 3 4)))

(provide count_instances_deep)
;count_instances_deep, counts number of times an item occurs in a list
;(includes sub lists by running the function on that list if the el returns a list).
;The function is called on this element el & the rest of the list lst
(define (count_instances_deep el lst)
  (cond
    ((empty? lst) 0)
    ((list? (car lst))
     (+ (count_instances_deep el (car lst)) (count_instances_deep el (cdr lst))))
    ((equal? el (car lst))
     (+ 1 (count_instances_deep el (cdr lst))))
    (else
     (count_instances_deep el (cdr lst)))))
(count_instances_deep 3 '(3 2 1 (3 1 3 4 )))