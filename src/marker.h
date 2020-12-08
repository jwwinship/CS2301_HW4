//
// Created by John on 11/28/2020.
//

#ifndef CS2301_HW3_MARKER_H
#define CS2301_HW3_MARKER_H

#include "BingoCard.h"

typedef struct
{

    int row;
    int col;
    int number;
    char letter;
    // We create a marker for every ball called, for simplicity's sake.
    // Because of this, we have a field that tells us if a marker actually has a match on the board
    bool matchFound;
}Marker;

#include <stdbool.h>
#include <stdlib.h>
#include <LinkedList.h>

Marker* placeMarker(int, int, int,char, bool matchFound);


#endif //CS2301_HW3_MARKER_H
