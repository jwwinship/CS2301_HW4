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


	return ans;
}

bool testSetEdge()
{
    bool ans = true;

    return ans;
}

bool testGetEdge()
{
    bool ans = true;


    return ans;
}

bool testMakeLList() //Tests the making of a list and the enqueue behavior.
{
	bool ok = true;


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

    return ok;
}

bool testDequeue()
{
    bool ok = true;

    return ok;
}