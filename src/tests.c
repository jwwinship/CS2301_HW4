/*
 * tests.c
 *
 *  Created on: Jul 4, 2019
 *      Author: Therese
 */

#include "tests.h"
#include "production.h"
#include "LinkedList.h"
#include "BingoCard.h"


bool tests()
{
	bool answer = false;
	bool ok1 = testInitBingoCard();
	bool ok2 = testPrintList();
	bool ok3 = testCallBall();
	//bool ok3 = testMakeLList();
	//bool ok4 = testEnqueue();
	//bool ok5 = testRemoveFromList();
	//bool ok6 = testPrintHistory();
	answer = ok1 && ok2 && ok3;
	return answer;
}



bool testGotAdjacencyMatrix()
{
	bool ans = true;


	return ans;
}

bool testMakeLList()
{
	bool ok = true;
	puts("starting testMakeLList");fflush(stdout);
	//what are the criteria for success for make LList?
	//should be able to make one, add data to it, get the data back
	//test case 1:
	LLNode* theListP = makeEmptyLinkedList();
	bool rightAnswer = true;
	bool answer = isEmpty(theListP);
	if(answer!=rightAnswer)
	{
		ok = false;
	}
	//test case 2:
	//TODO more test cases here
	else
	{
		puts("test make LList did not pass.");
	}

	return ok;
}

bool testPrintHistory()
{
	bool ok = true;
	return ok;
}

//This will simultaneously test the initialization and display of the card, since they are pretty tied together.
bool testInitBingoCard()
{
    bool ok = false;
    bingoBall** theSpaceP = malloc(20 * 20 * sizeof(bingoBall));
    ok = initBingoCard(theSpaceP,20);
    displayBingoCard(theSpaceP, 20); //Visual test. If the console prints out a randomized bingo card, then the test is a success.

    if (ok)
    {
        puts("Test InitBingoCard passed\n");
    }
    else
    {
        puts("Test InitBingoCard failed\n");
    }
    return ok;
}

bool testPrintList()
//This is another visual test. If the test prints out a list of Bingo ball markers, then the test is successful.
{
    bool ok = true;
    LLNode* markerList = makeEmptyLinkedList();
    for (int i = 0; i<5; i++)
    {
        bingoBall* testBingoBallP = malloc(sizeof(bingoBall));
        //Sets letter to random letter from A to Z
        testBingoBallP->letter = rand()%26 + 65;
        //Sets number from 0-9
        testBingoBallP->number = rand()%10;
        Marker* testMarker = malloc(sizeof(Marker));
        testMarker->row = rand()%20;
        testMarker->col = rand()%20;
        testMarker->letter = testBingoBallP->letter;
        testMarker->number = testBingoBallP->number;
        savePayload(markerList, testMarker); //List should be populated, test should pass

    }
    if (isEmpty(markerList))
    {
        ok = false;
    }
    printf("\nTesting Ability to print the contents of a list\n");
    printList(markerList);
    if (ok)
    {
        puts("Test PrintList passed\n");
    }
    else
    {
        puts("Test PrintList failed\n");
    }
    return ok;
}

//A double test again.
bool testCallBall()
{
    bool ok = true;
    bingoBall** theSpaceP = malloc(20 * 20 * sizeof(bingoBall));
    bingoBall* tempBallP;
    ok = initBingoCard(theSpaceP,20);
    displayBingoCard(theSpaceP, 20); //Visual test. If the console prints out a randomized bingo card, then the test can continue
    for (int i = 0; i<10; i++)
    {
        tempBallP = callBingoBall(theSpaceP, 20); //this should call a bunch of bingo balls, and add matches to the list.
        if (tempBallP->letter > 90 || tempBallP->letter < 65 || tempBallP->number < 0 || tempBallP->number > 9)
        {
            ok = false;
        }
    }
    //printHistoryList();
    if (ok)
    {
        puts("Test CallBall passed\n");
    }
    else
    {
        puts("Test CallBall failed\n");
    }
    return ok;
}