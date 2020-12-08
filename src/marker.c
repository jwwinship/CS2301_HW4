//
// Created by John on 11/28/2020.
//

#include "marker.h"
#include "BingoCard.h"
#include "LinkedList.h"


Marker* placeMarker(int r, int c, int number, char letter, bool matchFound)
{
    Marker* mP = (Marker*) malloc(sizeof(Marker));
    //TODO what do we do?

    mP->row = r;
    mP->col = c;
    mP->letter = letter;
    mP->number = number;
    mP->matchFound = matchFound;

    return mP;
}
