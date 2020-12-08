/*
 * production.c
 *
 *  Created on: Jul 4, 2019
 *      Author: Therese
 */
#include "production.h"


#include "LinkedList.h"
//TODO: modify production to accept argument
bool production(int argc, char* argv[])
{
	bool answer = false;

	if(argc <=1) //no interesting information
	{
		puts("Didn't find any arguments.");
		fflush(stdout);
		answer = false;
	}
	else //there is interesting information
	{
		printf("Found %d interesting arguments.\n", argc-1);
		fflush(stdout);
		char* eptr=(char*) malloc(sizeof(char*));
		long aL=-1L;

		for(int i = 1; i<argc; i++) //don't want to read argv[0]
		{//argv[i] is a string

			switch(i)
			{
			case 1:
			    aL =  strtol(argv[i], &eptr, 10);
			    int ballsToCall = (int) aL;
			    printf("Number of balls to call: %d\n", ballsToCall);
                bingoBall** theSpaceP = malloc(20 * 20 * sizeof(bingoBall));
                answer = initBingoCard(theSpaceP,20);
                displayBingoCard(theSpaceP, 20); //Visual test. If the console prints out a randomized bingo card, then the test can continue
                for (int j = 0; j<ballsToCall; j++)
                {
                    callBingoBall(theSpaceP, 20); //this should call a bunch of bingo balls, and add matches to the list.
                }
			    break;
			default:
				puts("Unexpected argument count."); fflush(stdout);
				answer = false;
				break;
			}//end of switch
		}//end of for loop on argument count
	}//end of else we have good arguments


	return answer;
}


