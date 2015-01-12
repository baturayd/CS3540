// Spring 2015 - CS3540 - Systems Programming w/ C
// Assignment 1 Question 1
// Baturay Daylak

#include<stdio.h>
#include<math.h>
int main()
{
	float bh, h, D, theta;
	printf("\n--------------------------------------------------\n");
	printf("Assignment 1 Question 1 - CS3540 - Baturay Daylak\n");
	printf("--------------------------------------------------\n");
	printf("Please enter the height of the person: ");
	scanf("%f", &h);
	printf("Please enter the distance from the building: ");
	scanf("%f", &D);
	printf("Please enter the elevation angle: ");
	scanf("%f", &theta);
	bh = h + D * tan(M_PI*theta/180.0);
	printf("--------------------------------------------------\n");	
	printf("Height of the building is %.2f\n", bh);
	printf("--------------------------------------------------\n\n");
	return 0; 
}
