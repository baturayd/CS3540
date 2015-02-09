// Program: CS4720 Assignment 3.2 - Linked List Implementation
// Author: Baturay Daylak
// Date: Sept 16, 2014

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct FlightStop
{
	int airport;
	struct FlightStop * next;
};

// BEGIN FUNCTION COUNTHOPS
int counthops(struct FlightStop * fs)
{

	struct FlightStop * cursor = fs;
	int hops;
	hops = 0;

	while(cursor!=NULL)
	{
		++hops;
		cursor = cursor->next;
	}

	return hops;

}//END FUNCTION

//BEGIN FUNCTION INSERT
void insert(struct FlightStop * fs, int airport)
{

	struct FlightStop * new;

	if(fs)
		while(fs->next!=NULL)
			fs = fs->next;
	
	new = (struct FlightStop *)malloc(sizeof(struct FlightStop));
	new->airport=airport;
	new->next = NULL;
	
	//CONDITION BELOW IS NOT NECESSARY, HOWEVER IT'S CHECK IN CASE SEGFAULT
	if(fs)
		fs->next = new;
	else
		fs = new;
		
	return;
	
}//END FUNCTION	

//BEGIN FUNCTION INSERTAFTER
void insertAfter(struct FlightStop * fs, int insertAfterAirport, int airport)
{
	
	int count = 0;
	struct FlightStop * temp;

	while(fs->next!=NULL && fs->airport!=insertAfterAirport)	//TRAVERSE THE LIST AS LONG AS THERE EXISTS NEXT ELEMENT AND UNTIL AIRPORT IS FOUND
		fs = fs->next;
	
	temp = fs->next;
	fs->next = (struct FlightStop *)malloc(sizeof(struct FlightStop));
	fs = fs->next;
	fs->airport = airport;
	fs->next = temp;
	return;

}//END FUNCTION

//BEGIN FUNCTION DELETEAIRPORT
void deleteAirport(struct FlightStop * fs, int airport)
{
	
	int count = 0;
	struct FlightStop * temp;

	while(fs->next!=NULL && (fs->next)->airport!=airport)		//TRAVERSE THE LIST AS LONG AS THERE EXISTS NEXT NODE AND UNTIL AIRPORT DATA OF NEXT NODE MATCHES THE CRITERIA
		fs = fs->next;
	
	//BEAUTY OF LINKED LISTS IS BELOW
	temp = fs->next;
	fs->next = temp->next;
	//EASY TO REMOVE A NODE

	free(temp);
	return;

}//END FUNCTIONS	

//BEGIN FUNCTION PRINTAIRPORTS
void printAirports(struct FlightStop * fs)
{

	printf("\nAirports are listed in order:\n");

	while(fs->next!=NULL)
	{
		fs=fs->next;	//TO SKIP HEAD NODE, THIS STATEMENT PRECEEDS THE PRINTING STATEMENT.
		printf("\tAirport code: %d\n",fs->airport);
	}

	return;
}//END FUNCTION

//BEGIN PROGRAM
int main()
{

	struct FlightStop *airports;
	airports = (struct FlightStop *)malloc(sizeof(struct FlightStop));
		
	printAirports(airports);	//EMPTY LIST STATE

	insert(airports, 4);
	insert(airports, 7);

	printAirports(airports);	//LIST WITH 4 AND 7

	insertAfter(airports, 4, 1);	//THIS WILL INSERT AIRPORT 1 AFTER AIRPORT 4

	printAirports(airports);	//PRINT UPDATED LIST

	deleteAirport(airports, 4);	//DELETE AIRPORT 4

	printAirports(airports);	//PRINT UPDATED LIST
	
	return 0;

}//END PROGRAM
