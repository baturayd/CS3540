#include <stdio.h>
#include <stdlib.h>
#include "basic_lib.c"

int main()
{

	double values[5][4] = {

		{213.2, 564.3, 485.0, 321.5},
		{301.2, 523.2, 468.6, 352.4},
		{200.2, 510.2, 435.3, 408.4},
		{276.5, 543.1, 432.4, 453.3},
		{298.5, 456.6, 478.2, 300.7}

	};

	int i;
	int j;

	printf("\nInput data for annual quarterly rain fall: \n");
	for(i=0;i<5;i++)
	{
		printf("%d data: ",2010+i);
		for(j=0;j<4;j++)
			printf("%f\t",values[i][j]);
		printf("\n");
	}

	printf("\n");

	for(i=0;i<5;i++)
	{

		printf("Minimum rainfall for %d: %f\n", 2010+i,min(values[i],4)); 
		printf("Maximum rainfall for %d: %f\n", 2010+i,max(values[i],4));
		printf("Average rainfall for %d: %f\n\n", 2010+i,ave_magn(values[i],4));

	}

}
