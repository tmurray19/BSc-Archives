#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"


//changed char* to void*
typedef struct listElementStruct {
	void* data;
	size_t size;
	void (*printFunction)();
	struct listElementStruct* next;
} listElement;

//Creates a new linked list element with given content of size
//Returns a pointer to the elements
listElement* createEl(void* data, size_t size, void* printFunction) {
	//Allocating memeory for the element e
	listElement* e = malloc(sizeof(listElement));
	if (e == NULL) {
		//malloc has had an error
		return NULL; //return NULL to indicate an error.
	}
	void* dataPointer = malloc(sizeof(data)*size);
	if (dataPointer == NULL) {
		//malloc has had an error
		free(e); //release the previously allocated memory
		return NULL; //return NULL to indicate an error.
	}
	e->data = dataPointer;
	e->size = size;
	e->printFunction = printFunction;
	e->next = NULL;
	return e;
}

//Prints out each element in the list
void traverse(listElement* start) {
	listElement* current = start;
	while (current != NULL) {
		current -> printFunction();
		current = current->next;
	}
}

//Inserts a new element after the given el
//Returns the pointer to the new element
listElement* insertAfter(listElement* el, char* data, size_t size, void* printFunction) {
	listElement* newEl = createEl(data, size,, printFunction);
	listElement* next = el->next;
	newEl->next = next;
	el->next = newEl;
	return newEl;
}


//Delete the element after the given el
void deleteAfter(listElement* after) {
	listElement* delete = after->next;
	listElement* newNext = delete->next;
	after->next = newNext;
	//need to free the memory because we used malloc
	free(delete->data);
	free(delete);
}

//NEW FUNCTIONS

//Returns number of elements in a linked list
int length(listElement* list) {
	listElement* start = list;
	int sizeoflist = 0;
	while (start != NULL)
	{
		++sizeoflist;
		start = start->next;
	}
	return sizeoflist;
}

//Pushes a new element to onto the head of a list, & updates the list reference using side effects
void push(listElement** list, char* data, size_t size, void* printFunction) {
	listElement* newEl = createEl(data, size, printFunction);
	newEl->next = (*list);
	(*list) = newEl;
}


//pop an element from the head of a list, & update the list reference using side effects
listElement* pop(listElement** list) {
	listElement* head = *list;
	if (head) {
		head->next = NULL;
		*list = head->next;
		free(head);
		//list->head = head->next;

	}
	return head;
}


//enqueues an element onto the head of a list, & updates the list references using side effects
void enqueue(listElement** list, char* data, size_t size, void* printFunction) {
	listElement* NewEl = createEl(data, size, printFunction);
	NewEl->next = (*list);
	(*list) = NewEl;
}


//dequeues an element from the tail of a list
listElement* dequeue(listElement* list) {
	listElement* head = list;
	listElement* clear;
	while (head != NULL) {
		if (head->next->next == NULL) {
			clear = createEl(head->next->data, head->next->size, head->next->printFunction);
			free(head->next->data);
			free(head->next);
			head->next = NULL;
		}
		head = head->next;
	}
	return clear;
}


//Q3 Functions - printData 

//Characters
void printChar(void* data) {
	printf("%c\n", *(char*)data);
}

//Strings
void printString(void* data){
	printf("%s\n", *(char*)data);
}

//Integers
void printInt(void* data){
	printf("%d\n", *(int*)data);
}

//Floating point
void printFloat(void* data) {
	printf("%f\n", *(float*)data);
}

//Doubles
void printDouble(void* data) {
	printf("%f\n", *(double*)data);
}

//Long Integers
void printLong(void* data) {
	printf("%l\n", *(long*)data);
}
