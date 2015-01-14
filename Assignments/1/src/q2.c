// Spring 2015 - CS3540 - Baturay Daylak
// Assignment 1 Question 2

#include<stdio.h>
#include<math.h>

int main()
{
	float d, x1, x2, y1, y2;
	printf("\n--------------------------------------------------");
	printf("\nAssignment 1 Question 2 - CS3540 - Baturay Daylak");
	printf("\n--------------------------------------------------\n");
	printf("Please enter first X coordinate: ");
	scanf("%f", &x1);
	printf("Please enter second X ccoordinate: ");
	scanf("%f", &x2);
	printf("Please enter first Y coordinate: ");
	scanf("%f", &y1);
	printf("Please enter second Y coordinate: ");
	scanf("%f", &y2);

	d = sqrt( pow(x2-x1, 2) + pow(y2-y1, 2) );

	printf("--------------------------------------------------\n");
	printf("Distance between two points is %.3f\n", d);
	printf("--------------------------------------------------\n\n");
	return 0;
}
