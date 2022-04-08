#ifndef ZORKUL_H_
#define ZORKUL_H_

#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "item.h"
#include <iostream>
#include <string>
#include <exception>

using namespace std;

class ZorkUL {

private:
    Parser parser;
    Room *currentRoom;
    void createRooms();
    //void printWelcome();
    //bool processCommand(Command command);
    //void printHelp();
    //void goRoom(Command command);
    void createItems();
    void displayItems();
    vector<Room*> rooms;



public:
    ZorkUL();
    void play();
    //string go(string direction);
    Room* getCurrentRoom();
    void setCurrentRoom(Room*);
    string teleport(string rooms);
};

#endif /*ZORKUL_H_*/
