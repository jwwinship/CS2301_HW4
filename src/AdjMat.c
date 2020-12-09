//
// Created by John on 12/8/2020.
//

#include "AdjMat.h"
#include <stdio.h>

void init(AdjMat* adjMP)
{
    int ncols = adjMP->n;
    printf("In init with ncols = %d\n", ncols);
    for(int row = 0; row<ncols; row++)
    {
        for(int col = 0; col<ncols; col++)
        {
            int* memoryToAssign = ((adjMP->edgesP)+(row*ncols)+col);
            *memoryToAssign= 0;
        }
    }

}

void setEdge(AdjMat* adjMP, int row, int col)
{

    int ncols = adjMP->n;
    int* arrayBeginning = adjMP->edgesP;
    *(arrayBeginning + (ncols*row) +col) = 1;
    *(arrayBeginning + (ncols*col) + row) = 1;
}
int getEdge(AdjMat* adjMP, int row, int col)
{
    int ncols = adjMP->n;
    int* arrayBeginning = adjMP->edgesP;
    int returnValue = *(arrayBeginning + (ncols*row) +col); //Wrong value for test.
    return returnValue;
}