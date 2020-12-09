/*
 * production.c
 *
 *  Created on: Jul 4, 2019
 *      Author: Therese
 */
#include "production.h"
#include "AdjMat.h"
#include "Room.h"
#include "LinkedList.h"
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
        char filename[FILENAMELENGTHALLOWANCE];

    }//end of else we have good arguments

    return answer;
}
bool readFile(char* filename, int* nrooms, AdjMat* adjMP, Room** theRoomPs)
{
    bool ok = false;

    return ok;
}

