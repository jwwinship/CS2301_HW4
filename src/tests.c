/*
 * tests.c
 *
 *  Created on: Jul 4, 2019
 *      Author: Therese
 */

#include "tests.h"
#include "production.h"
#include "LinkedList.h"



bool tests()
{
	bool answer = false;
    bool ok1 = testReadFile();
	bool ok2 = testMakeLList();
	bool ok3 = testGotAdjacencyMatrix();
	bool ok4 = testSetEdge();
	bool ok5 = testGetEdge();
	bool ok6 = testDequeue();
	bool ok7 = testPrintHistory();
	answer = ok1 && ok2 && ok3 && ok4 && ok5 && ok6;
	return answer;
}



bool testGotAdjacencyMatrix()
{
	bool ans = true;
    int ncols = 8;
    AdjMat* adjMP = (AdjMat*) malloc(sizeof(AdjMat));
    adjMP->n = ncols;
    adjMP->edgesP = (int*) malloc(8 * 8 *sizeof(int)); //Test value with 8 rooms
    init(adjMP);

    printf("Testing init with ncols = %d\n", ncols);
    for(int row = 0; row<ncols; row++)
    {
        for(int col = 0; col<ncols; col++)
        {
            int* memoryToCheck = ((adjMP->edgesP)+(row*ncols)+col);
            if (*memoryToCheck != 0)
            {
                ans = false;
                break;
            }
        }
    }
    if (ans)
    {
        puts("Test gotAdjMatrix passed");
    }
    else
    {
        puts("Test gotAdjMatrix did not pass");
    }

	return ans;
}

bool testSetEdge()
{
    bool ans = true;
    puts("Testing SetEdge...");
    int ncols = 8;
    AdjMat* adjMP = (AdjMat*) malloc(sizeof(AdjMat));
    adjMP->n = ncols;
    adjMP->edgesP = (int*) malloc(8 * 8 *sizeof(int)); //Test value with 8 rooms
    init(adjMP);
    for(int row = 0; row<ncols; row++)
    {
        for(int col = 0; col<ncols; col++)
        {
            setEdge(adjMP, row, col);
            int* memoryToCheck = ((adjMP->edgesP)+(row*ncols)+col);
            if (*memoryToCheck == 0)//This time it's false if any of the edges are 0
            {
                ans = false;
                break;
            }
        }
    }
    if (ans)
    {
        puts("Test setEdge passed");
    }
    else
    {
        puts("Test setEdge did not pass");
    }

    return ans;
}

bool testGetEdge()
{
    bool ans = true;
    puts("Testing GetEdge...");
    int ncols = 8;
    AdjMat* adjMP = (AdjMat*) malloc(sizeof(AdjMat));
    adjMP->n = ncols;
    adjMP->edgesP = (int*) malloc(8 * 8 *sizeof(int)); //Test value with 8 rooms
    init(adjMP);
    for(int row = 0; row<ncols; row++)
    {
        for(int col = 0; col<ncols; col++)
        {

            *((adjMP->edgesP)+(row*ncols)+col) = 1;
            int valueToCheck = getEdge(adjMP, row, col);
            if (valueToCheck != 1)
            {
                ans = false;
            }
        }
    }
    if (ans)
    {
        puts("Test GetEdge passed");
    }
    else
    {
        puts("Test GetEdge did not pass");
    }

    return ans;
}

bool testMakeLList() //Tests the making of a list and the enqueue behavior.
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
	Room* testRoomP = malloc(sizeof(Room));
	savePayload(theListP, testRoomP);
	rightAnswer = false;
	answer = isEmpty(theListP);
    if(answer!=rightAnswer)
    {
        ok = false;
    }

    //test case 3:
    Room* testRoom2P = malloc(sizeof(Room));
    savePayload(theListP, testRoom2P);
    if (!(theListP->next)) //If there is no next, then our second save did not work, or there is an issue with saving payloads to the list.
    {
        ok = false;
    }

    //Test case 4:
    LLNode* temp = theListP;
    while (temp->next)
    {
        temp = temp->next;
        if (!(temp->prev)) //If we move to the second element, and there is no first element, then we know that something is wrong with prev.
        {
            ok = false;
        }

    }

    //Test Case 5
    Room* testRoomCompareP = theListP->payP;
    if (isEmpty(theListP)||testRoomCompareP->roomNumber != testRoomP->roomNumber || testRoomCompareP->searched != testRoomP->searched || testRoomCompareP->treasure != testRoomP->treasure) //If there are discrepancies between the original room and the one from the list, then we know something is wrong.
    {
        ok = false;
    }

    //Test case 6
    LLNode* tempP = theListP;
    while (tempP->next)
    {
        if ((LLNode*)tempP->next == (LLNode*)tempP) //If next points to the same place, then something is wrong with the savePayload function
        {
            ok = false;
        }
        tempP = tempP->next;
    }
    while (tempP->prev)
    {
        if ((LLNode*)tempP->prev == (LLNode*)tempP) //If prev points to the same place, then something is wrong with the savePayload function
        {
            ok = false;
        }
        tempP = tempP->prev;
    }

	if (!ok)
	{
		puts("test make LList did not pass.");
	}
	else
    {
	    puts("Test make LList passed.");
    }

	return ok;
}

bool testPrintHistory()
{
	bool ok = true;
	return ok;
}

bool testReadFile()
{
    puts("starting testReadFile"); fflush(stdout);
    bool ok = false;
    //the file tells how many rooms there are
    int answer = -1;
    int rightAnswer = 8;


    AdjMat* adjMP = (AdjMat*) malloc(sizeof(AdjMat));
    Room* theRoomPs[10];//addresses for 10 rooms


    ok = readFile("houseGraph.txt", &answer, adjMP, theRoomPs); //read the file
    if(ok)
    {
        if(answer!=rightAnswer)
        {
            puts("test failed on number of rooms");
        }

    }
    puts("The adjacency matrix");
    for(int i = 0; i<answer; i++)
    {
        for(int j = 0; j<answer; j++)
        {
            int edge = getEdge(adjMP, i, j);
            printf("%d ",edge);

        }
        printf("\n");
    }
    puts("The treasure values");
    for(int i = 0; i<answer; i++)
    {
        printf("%f\n", theRoomPs[i]->treasure);
    }

    //fclose();
    return ok;
}

bool testDequeue()
{
    bool ok = true;
    puts ("Testing DequeueLIFO..");
    LLNode* queue = makeEmptyLinkedList();
    for (int i = 0; i<5; i++)
    {
        Room* tempRoomP = malloc(sizeof(Room));
        tempRoomP->roomNumber = i;
        savePayload(queue, tempRoomP);
    }
    Room* returnRoomP = dequeueLIFO(queue);
    if (returnRoomP->roomNumber != 4)
    {
        ok = false;
    }

    if (ok)
    {
        puts("Test DequeueLIFO passed");
    }
    else
    {
        puts("Test DequeueLIFO did not pass");
    }

    return ok;
}