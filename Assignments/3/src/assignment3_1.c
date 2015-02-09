// Program: CS4720 Assignment 3.1 - ComplexNumber Operations
// Author: Baturay Daylak
// Date: Sept 16, 2014

#include <stdio.h>
#include <stdlib.h>

const ARRAYSIZE = 10; // ARRAY SIZE FOR ALL ARRAYS WHICH ARE DEFINED IN THIS PROGRAM

//COMPLEX NUMBER STRUCTURE
struct ComplexNum {
	double realpart;
	double imagpart;
};

// BEGIN DEFINITION OF ALGEBRAIC OPERATIONS ON COMPLEX NUMBERS
struct ComplexNum add(struct ComplexNum a, struct ComplexNum b)
{
	struct ComplexNum result;
	result.realpart = a.realpart + b.realpart;
	result.imagpart = a.imagpart + b.imagpart;
	return result;
}

struct ComplexNum substract(struct ComplexNum a, struct ComplexNum b)
{
	struct ComplexNum result;
	result.realpart = a.realpart - b.realpart;
	result.imagpart = a.imagpart - b.imagpart;
	return result;
}

struct ComplexNum divide(struct ComplexNum a, struct ComplexNum b)
{
	struct ComplexNum result;
	result.realpart = a.realpart / b.realpart;
	result.imagpart = a.imagpart / b.imagpart;
	return result;
}

struct ComplexNum multiply(struct ComplexNum a, struct ComplexNum b)
{
	struct ComplexNum result;
	result.realpart = a.realpart * b.realpart;
	result.imagpart = a.imagpart * b.imagpart;
	return result;
}// END DEFINITION OF ALGEBRAIC OPERATIONS ON COMPLEX NUMBERS



// BEGIN ARRAY OPERATIONS FUNCTION
//
// This function returns a pointer to a ComplexNum typed memory field. 
// Array allocation is done through malloc function of stdlib, using a constant for array size.
// First argument is a ComplexNum typed array
// Second argument is also a ComplexNum typed array
// Third argument is opcode, which are following
// 	0 for addition
// 	1 for substraction
// 	2 for division
// 	3 for multiplication
//
// This way, one function handles all four operations interchangebly. 
// Tidy.
struct ComplexNum * arrayops(struct ComplexNum a[], struct ComplexNum b[], int opcode)
{

	struct ComplexNum * results;
	int i;
	results = malloc(ARRAYSIZE * sizeof(struct ComplexNum));
	for(i=0;i<ARRAYSIZE;i++)
		if(opcode == 0)
			results[i] = add(a[i], b[i]);
		else if(opcode == 1)
			results[i] = substract(a[i], b[i]);
		else if(opcode == 2)
			results[i] = divide(a[i], b[i]);
		else if(opcode == 3) 
			results[i] = multiply(a[i], b[i]);
	
	return results;
}// END ARRAY OPERATIONS FUNCTION



// BEGIN PROGRAM
int main()
{

	struct ComplexNum a[ARRAYSIZE], b[ARRAYSIZE];
	int i;
	struct ComplexNum *radd, *rsub, *rdiv, *rmul;

	printf("\n\nProgram: Assignment 3.1 Complex number operations\nAuthor: Baturay Daylak\n\n Input data:\n");	
	
	// This loop is to fill up the ComplexNum arrays. 
	// Because it's boring to manually create those.
	// ARRAYSIZE can be changed at the top of the definitions, and this will continue to work.
	// By default, 10 seems to be enough.
	for(i=0; i<ARRAYSIZE; i++)
	{
	
		a[i].realpart = i+100;
		a[i].imagpart = 50 - i;
		
		b[i].realpart = i + 5;
		b[i].imagpart = 60 + i;

		printf("Array 1 Element %d) Real: %lf\t Imaginary: %lf\n", i+1, a[i].realpart, a[i].imagpart);
		printf("Array 2 Element %d) Real: %lf\t Imaginary: %lf\n", i+1, b[i].realpart, b[i].imagpart);

	}
 
	// For opcode definitions, refer to the function definition inline doc.
	radd = arrayops(a, b, 0); //Addition
	rsub = arrayops(a, b, 1); //Substraction
	rdiv = arrayops(a, b, 2); //Division
	rmul = arrayops(a, b, 3); //Multiplication

	printf("\n\nAddition results\n");
	for(i=0; i<ARRAYSIZE; i++)
		printf("\t%d) Real: %lf\t Imaginary: %lf\n", i+1, radd[i].realpart, radd[i].imagpart);

	printf("\nSubstraction results\n");
		for(i=0; i<ARRAYSIZE; i++)
			printf("\t%d) Real: %lf\t Imaginary: %lf\n", i+1, rsub[i].realpart, rsub[i].imagpart);

	printf("\nMultiplication results\n");
		for(i=0; i<ARRAYSIZE; i++)
			printf("\t%d) Real: %lf\t Imaginary: %lf\n", i+1, rmul[i].realpart, rmul[i].imagpart);

	printf("\nDivision results\n");
		for(i=0; i<ARRAYSIZE; i++)
			printf("\t%d) Real: %lf\t Imaginary: %lf\n", i+1, rdiv[i].realpart, rdiv[i].imagpart);

	printf("\n\n"); //leave spaces on CLI  after finishing output so that output can be seen easily.

	return 0;

} // END PROGRAM
