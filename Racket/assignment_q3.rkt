#lang racket

;creating a node structure for a binary search tree
(struct node (val left right))

(define example_tree '(((() 2 ()) 3 ((() 5 ()) 6 (() 8 ()))) 10 (() 11 ((() 15 ()) 17 ()))))


;Display contents of a binary search tree in sorted order
(define (display_tree lst)
  (begin (cond 
          [(not (empty? (node-left lst))) (display_tree (node-left lst))])
	    (printf "~a~n" (node-val lst))
	  (cond
            [(not (empty? (node-right lst))) (display_tree (node-right lst))]))
)
		  
;return #t or #f if an item is present or absent in a tree repsectively
;goes to the left if the value is smaller, and to the right if it is bigger                  
(define (TrueOrFalse el lst)
   (cond
     [(empty? lst) #f]
     [else (cond
           [(= el (node-val lst)) #t]
           [(< el (node-val lst))
            (TrueOrFalse el (node-left lst))]
           [(> el (node-val lst))
            (TrueOrFalse el (node-right lst))])])
           
  )

;Insert an item into the correct position of a list
(define (InsertToList el lst)
   0)

;take a list of items and insert them into a binary search tree
(define (ListInserter lst treeList)
   0)

;Implemet a tree-sort algorithm
(define (TreeSortAlgorithm lst)
   0)

;Implements a higer order version of the tree-sort function & takes a list
;of functions that determines the sorted order
;e.g write a version that sorts the list in ascending, descending & based
;on last digit
(define (HigherOrderTreeSort lst)
   0)