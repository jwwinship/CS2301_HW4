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
        char* eptr=(char*) malloc(sizeof(char*));
        long aL=-1L;
        int maxRooms = 0;
        float maxTreasure = 0.0F;
        double maxTreas = 0.0;
        if (argc == 2)
        {
            printf("Enter the maximum number of rooms to search: ");
            scanf("%d", &maxRooms);

            printf("Max number of rooms is %d\n",maxRooms);fflush(stdout);


            printf("Enter the maximum amount of treasure to search for: ");
            scanf("%lf", &maxTreas);
            char *ptr;
            printf("Max amount of  treasure is %f\n",maxTreas);fflush(stdout);
            maxTreasure = (float) maxTreas;
        }
        else if (argc == 3)
        {
            printf("Enter the maximum amount of treasure to search for: ");
            scanf("%lf", &maxTreas);
            char *ptr;
            printf("Max amount of  treasure is %f\n",maxTreas);fflush(stdout);
            maxTreasure = (float) maxTreas;
        }
        for(int i = 1; i<argc; i++) //don't want to read argv[0]
        {//argv[i] is a string
            //in this program our arguments are NR, NC, gens, filename, print and pause
            //because pause is optional, argc could be 6 or 7
            //because print is optional (if print is not present, neither is pause) argc could be 5
            switch(i)
            {
                case 1:
                    //this is filename
                    printf("The length of the filename is %d.\n",strlen(argv[i]));
                    printf("The proposed filename is %s.\n", argv[i]);
                    if(strlen(argv[i])>=FILENAMELENGTHALLOWANCE)
                    {
                        puts("Filename is too long.");
                        fflush(stdout);
                        answer = false;
                    }
                    else
                    {
                        strcpy(filename, argv[i]);
                        printf("Filename was %s.\n", filename);
                        fflush(stdout);
                    }
                    break;
                case 2:
                    //this is maximum number of rooms

                    aL= strtol(argv[i], &eptr, 10);
                    maxRooms = (int) aL;
                    printf("Max number of rooms is %d\n",maxRooms);fflush(stdout);
                    break;
                case 3:
                    //this is maximum amount of treasure
                    char *ptr;
                    maxTreas = strtod(argv[i], &ptr);
                    printf("Max amount of  treasure is %f\n",maxTreas);fflush(stdout);
                    maxTreasure = (float) maxTreas;
                    break;

                default:
                    puts("Unexpected argument count."); fflush(stdout);
                    answer = false;
                    break;
            }//end of switch
        }//end of for loop on argument count
        puts("after reading arguments"); fflush(stdout);
        //we'll want to read the file
        int nrooms = -1;
        AdjMat* adjMP = (AdjMat*) malloc(sizeof(AdjMat));
        //cannot, do not know nrooms init(adjMP);
        //puts("Back from init Adj Mat"); fflush(stdout);
        Room* theRoomPs[10];//addresses for 10 rooms

        puts("Before read file"); fflush(stdout);
        answer = readFile(filename, &nrooms, adjMP, theRoomPs); //read the file
        puts("Back from read file"); fflush(stdout);

        //we'll want to conduct the search
        //for the search we'll need an empty search history
        LLNode2* historyP = makeEmptyLinkedList2();
        //we'll need the Queue, into which we put rooms, and remove rooms
        LLNode* searchQ = makeEmptyLinkedList();
        puts("starting search"); fflush(stdout);
        //we'll start searching with room 0
        bool done = false;
        int searchedRooms = 0;
        float foundTreasure = 0.0F;
        Room* roomBeingSearchedP = theRoomPs[0];
        //we set its searched field to true, and take its treasure
        roomBeingSearchedP->searched = true;
        foundTreasure += roomBeingSearchedP->treasure;//Take the treasure

        //we record it in the history
        SearchResults* srP = (SearchResults*) malloc(sizeof(SearchResults));
        srP->roomNumber= 0;
        srP->treasure = roomBeingSearchedP->treasure;
        savePayload2(historyP, srP); //NEW, save room to history list.
        if((srP->treasure <= maxTreas) && (maxRooms>0))
        {
            //here we are enqueueing room 0
            puts("Enqueuing room 0");
            //TODO: what else goes here?
            savePayload(searchQ, roomBeingSearchedP); //Save this room into the search queue.

        }

        while(!done)
        {   //here we want to find all of the rooms adjacent to the roomBeingSearched,
            //so we look in the adj matrix
            for(int col = 0; (col<nrooms)&&!done; col++)
            {
                //we check whether this room is neighboring
                printf("checking rooms %d and %d.\n", roomBeingSearchedP->roomNumber, col); fflush(stdout);
                if(getEdge(adjMP,roomBeingSearchedP->roomNumber, col)==1)
                {
                    puts("found an edge"); fflush(stdout);
                    //if so, we check whether room has been searched
                    if(!(theRoomPs[col]->searched))
                    {//if it hasn't been searched
                        printf("Room %d hasn't already been searched.\n", col); fflush(stdout);
                        //we set it to searched
                        theRoomPs[col]->searched=true;
                        if((foundTreasure <= maxTreas) && (maxRooms>0))
                        {//we enqueue it for search
                            foundTreasure += theRoomPs[col]->treasure;
                            searchedRooms+=1;
                            printf("found treasure updated to %f.\n", foundTreasure);
                            printf("enqueuing room %d.\n", col); fflush(stdout);
                            printf("Before enqueuing queue empty reports %d\n", isEmpty(searchQ));
                            savePayload(searchQ,theRoomPs[col]);
                            srP = (SearchResults*) malloc(sizeof(SearchResults));
                            srP->roomNumber=theRoomPs[col]->roomNumber;
                            srP->treasure = theRoomPs[col]->treasure;
                            savePayload2(historyP,srP);
                            printf("After enqueuing, queue empty reports %d\n", isEmpty(searchQ));
                        }//check about search limits
                    }//room can still be searched
                }//room is a neighbor

                if(foundTreasure >= maxTreasure)
                {
                    done = true;
                    puts("Done by treasure");
                }
                if (searchedRooms>=maxRooms)
                {
                    done = true;
                    puts("Done by rooms");
                }
            }//scan for all possible rooms to search from this room
            //time to get the next room
            if(isEmpty(searchQ))
            {
                done=true;
                puts("Done by queue empty");
            }
            if(!done)
            {
                puts("Invoking  dequeue");fflush(stdout);
                roomBeingSearchedP = dequeueLIFO(searchQ);

            }
        }//while search is not done
        //search is now done, time to print the history
        printHistory(historyP);


    }//end of else we have good arguments

    return answer;
}
bool readFile(char* filename, int* nrooms, AdjMat* adjMP, Room** theRoomPs)
{
    bool ok = false;
    //the file tells how many rooms there are
    FILE* fp = fopen(filename, "r"); //read the file

    if (fp == NULL)
    {
        puts("Error! opening file");

    }
    else
    {
        fscanf(fp,"%d", nrooms);
        adjMP->n=*nrooms;
        int howManyRooms = *nrooms;
        adjMP->edgesP = (int*) malloc(howManyRooms * howManyRooms *sizeof(int));
        puts("Before init Adj Mat"); fflush(stdout);
        init(adjMP);
        int temp = -1;
        for(int roomr = 1; roomr<=*nrooms; roomr++)
        {
            printf("on row %d\n", roomr);fflush(stdout);
            for(int roomc = 0; roomc<roomr; roomc++)
            {
                fscanf(fp,"%d", &temp);
                printf("in column %d, read %d\n", roomc, temp);fflush(stdout);
                //now set the value in the adjacency matrix
                if(temp==1)
                {
                    setEdge(adjMP, roomr-1, roomc);
                }

            }
        }

        float tempTreas = 2.9;
        for(int roomr = 0; roomr<*nrooms; roomr++)
        {
            fscanf(fp,"%f", &tempTreas);
            //make a room and set its treasure
            Room** aRoomP = theRoomPs;
            aRoomP = aRoomP+roomr;
            *aRoomP = (Room*) malloc(sizeof(Room));
            //now set the treasures
            (*aRoomP)->treasure = tempTreas;
            (*aRoomP)->roomNumber = roomr;
            (*aRoomP)->searched = false;
            printf("The treasure in room %d is %f\n", roomr, (*aRoomP)->treasure);
        }
        ok = true;
    }
    fclose(fp);

    return ok;
}

