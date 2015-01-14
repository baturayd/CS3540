#include<stdio.h>

void print_newline()
{
	printf("\n");
}

void print_separator()
{
	printf("-----------------------------------------------------\n");
}

void print_assignment_header(int asgno, int qno)
{
	print_newline();
	print_separator();
	printf("Assignment %d - Question %d - CS3540 - Baturay Daylak", asgno, qno);
	print_separator();
	print_newline();
}
