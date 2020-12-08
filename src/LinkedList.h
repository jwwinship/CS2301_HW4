/*
 * LinkedList.h
 *
 *  Created on: Nov 4, 2019
 *      Author: Therese
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <stdbool.h>
#include "marker.h"

typedef Marker Payload;

//struct LLNode;

typedef struct
{
    struct LLNode* next;
    struct LLNode* prev;
    Payload* payP;
}LLNode;


typedef struct
{
    Payload* mp;
    LLNode* newQHead;
}backFromDQFIFO;

LLNode* makeEmptyLinkedList();

LLNode* removeFromList(LLNode* hp, Payload* pP);
void savePayload(LLNode* lp, Payload* mp);

bool isEmpty(LLNode* lp);
Payload* dequeueLIFO(LLNode* lp);
backFromDQFIFO* dequeueFIFO(LLNode* lp);


//These functions added by John Winship, to expand functionality of the lists.
void printList(LLNode* lp);


#endif /* LINKEDLIST_H_ */

