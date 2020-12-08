//
// Created by John on 11/28/2020.
//

#include <stdio.h>
#include <string.h>
#include "BingoCard.h"
#include "marker.h"


//A list of markers in the space
LLNode* markerList;
//TODO: add functionality for a second type of linked list, which will keep track of all called balls.

bool initBingoCard(bingoBall** corner, int howManyRows)
{
    //Another test
    //bingoBall cardlist[400];
    bool ok = true;
    bingoBall* tempSpaceP;
    for(int row = 0; row< 20; row++)
    {
        for(int col = 0; col < 20; col++)
        {
            tempSpaceP = malloc(sizeof(bingoBall));
            //Sets letter to random letter from A to Z
            tempSpaceP->letter = rand()%26 + 65;
            //Sets number from 0-9
            tempSpaceP->number = rand()%10; //Testing should pass

            *(corner+row*howManyRows + col) = tempSpaceP;
            if (tempSpaceP->letter > 90 || tempSpaceP->letter < 65 || tempSpaceP->number < 0 || tempSpaceP->number > 9)
            {
                ok = false;
            }

        }
    }

    //Also initializing the Linked List
    markerList = makeEmptyLinkedList();
    return ok;
}

bool displayBingoCard(bingoBall** corner, int howManyRows)
{
    bool ok = true;
    for(int row = 0; row< 20; row++)
    {
        for(int col = 0; col < 20; col++)
        {
            bingoBall tempSpace = **(corner + row * howManyRows + col);
            printf("|%c%d",tempSpace.letter, tempSpace.number);
        }
        printf("|\n");
    }

    return ok;
}

//This method calls the checkCardForMatch method, so needs the necessary parameters for bingo card.
bingoBall* callBingoBall(bingoBall** corner, int howManyRows)
{
    //TODO: Find a way to incorporate row and column into the calls for a bingo ball, so we can tell where it is.

    puts("\nCalling new Bingo Ball......");
    bingoBall* ballCalledP;
    ballCalledP = malloc(sizeof(bingoBall));
    //Sets letter to random letter from A to Z
    ballCalledP->letter = rand()%26 + 65;
    //Sets number from 0-9
    ballCalledP->number = rand()%10;
    printf("%c%d!\n\n", ballCalledP->letter, ballCalledP->number);
    ballCalledP = checkCardForMatch(corner, howManyRows, ballCalledP); //See if the currently called ball is on the bingo card anywhere

    if(ballCalledP->matchFound)
    {
        Marker* ballMarkerP = malloc(sizeof(Marker));
        ballMarkerP->letter = ballCalledP->letter;
        ballMarkerP->number = ballCalledP->number;
        ballMarkerP->row = ballCalledP->rowFound;
        ballMarkerP->col = ballCalledP->colFound;
        ballMarkerP->matchFound = true;

        savePayload(markerList, ballMarkerP);
    }
    printList(markerList); //Used for test purposes. Uncomment in order to test functionality of method

    return ballCalledP;
}

bingoBall* checkCardForMatch(bingoBall** corner, int howManyRows, bingoBall* ballToCheck)
{

    bingoBall* tempBallP = ballToCheck;
    for(int row = 0; row< 20; row++)
    {
        for(int col = 0; col < 20; col++)
        {
            tempBallP = *(corner + row * howManyRows + col);

            if (tempBallP->number == ballToCheck->number && tempBallP->letter == ballToCheck->letter)
            {
                tempBallP->colFound = col;
                tempBallP->rowFound = row;
                tempBallP->matchFound = true;
                return tempBallP;
            }
            else
            {
                tempBallP = ballToCheck;
            }
        }

    }
    return tempBallP;

}

void printHistoryList()
{
    //prints out the entirety of the marker history list
    printList(markerList);
}