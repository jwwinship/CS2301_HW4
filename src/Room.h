/*
 * Room.h
 *
 *  Created on: Dec 8, 2020
 *      Author: John Winship
 */

#ifndef ROOM_H_
#define ROOM_H_

#include <stdbool.h>

typedef struct
{
    int roomNumber;
    float treasure;
    bool searched;
}Room;

#endif /* ROOM_H_ */
