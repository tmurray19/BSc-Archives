#lang racket

;Cons of 2 numbers
(cons 1 2)

;list of 3 numbers, using cons
(cons '1 '(2 3 ))

;list containing string, num, & 3 numbers using cons
;(cons "zero" (cons '1 (cons 2 3)))
(cons 'zero (cons '1 '((2 3 4))))

;list containing string, num, & 3 numbers using list
(list 'zero 1 (list 2 3 4 ))

;list containing string, num, & 3 numbers using append
(append '(zero) '(1) '((1 2 3)))