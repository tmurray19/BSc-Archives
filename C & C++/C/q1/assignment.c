#include <stdio.h>

int main(int arg, char* argc[]){
	/*
	Name: Taidgh Murray
	Student I.D: 15315901
	Assignment 1 - C
	Question 1
	*/

	//Initialising variables
	int integer_var;
	int* integer_pointer_var;
	long long_var;
	double* double_var;
	char** character_var;
		
	//Using sizeof() function to 
	printf("Assignment 1 - Question 1: Size of pointer variables.\n");

	printf("Size of int: %ld bytes.\n", sizeof(integer_var));

	printf("Size of int*: %ld bytes.\n", sizeof(integer_pointer_var));

	printf("Size of long: %ld bytes.\n", sizeof(long_var));

	printf("Size of double*: %ld bytes.\n", sizeof(double_var));

	printf("Size of char**: %ld bytes.\n", sizeof(character_var));

	return 0;
}
