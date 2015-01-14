/*
 * Program: assignment2_1.c
 * Author: Baturay Daylak, January 14, 2015
 * Class: CS3540 Spring '15 - System Programing with Linux and C
 * Description: Calculates standard deviation for an N element array.
 * Comments: randouble function has been gathered from a GNU source.
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "basic_lib.h"

double randouble(double min, double max)
{
	double range = (max - min);
	double div = RAND_MAX / range;
	return min + (rand()/div);
}

int main()
{
	//Assignment information
	print_assignment_header(2,1);
	
	srand(time(NULL)); //This will make rand function generate unique output at each program run.
	int i = 0;
	int n = 50;
	double values[n];
	
	printf("\nInput values for std_dev calculation:\n");
	for(i = 0; i<n; i++)
	{
		values[i] = randouble(0.0,100.0);
		printf("%f\n",values[i]);
	}
	print_separator();
	printf("\nStandard deviation of values: %f\n",std_dev(values,n));
	print_separator();
	print_newline();
	return 0; 
}
