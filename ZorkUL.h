#ifndef ZORKUL_H_
#define ZORKUL_H_

#include "Command.h"
#include "Room.h"
#include "item.h"
#include <iostream>
#include <string>
#include <exception>

using namespace std;

class ZorkUL {

private:
    Room *currentRoom;
    void createRooms();
    vector<Room*> rooms;

public:
    ZorkUL();
    Room* getCurrentRoom();
    void setCurrentRoom(Room*);
    string teleport(string rooms);
};

#endif /*ZORKUL_H_*/
