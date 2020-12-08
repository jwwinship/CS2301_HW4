//
// Created by John on 11/28/2020.
//

#ifndef CS2301_HW3_BINGOCARD_H
#define CS2301_HW3_BINGOCARD_H

#include <stdbool.h>
#include "marker.h"
typedef struct
{
    int number;
    char letter;
    int rowFound;
    int colFound;
    bool matchFound;

}bingoBall;

bool initBingoCard(bingoBall**, int);
bool displayBingoCard(bingoBall**, int);
bingoBall* callBingoBall();
bingoBall* checkCardForMatch(bingoBall**, int, bingoBall*);
void printHistoryList();

#endif //CS2301_HW3_BINGOCARD_H
