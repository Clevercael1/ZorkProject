#include <iostream>

using namespace std;
#include "ZorkUL.h"

ZorkUL::ZorkUL() {
    createRooms();
}

void ZorkUL::createRooms()  {
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i, *j, *k, *l;

    a = new Room("a");
        a->addItem(new Item("x", 1, 11));
        a->addItem(new Item("y", 2, 22));
    b = new Room("b");
        b->addItem(new Item("xx", 3, 33));
        b->addItem(new Item("yy", 4, 44));
    c = new Room("c");
    d = new Room("d");
    e = new Room("e");
    f = new Room("f");
    g = new Room("g");
    h = new Room("h");
    i = new Room("i");
    j = new Room("j");
    k = new Room("k");
    l = new Room("l");

//             (N, E, S, W)
    a->setExits(f, b, d, c);
    b->setExits(NULL, NULL, NULL, a);
    c->setExits(NULL, a, NULL, NULL);
    d->setExits(a, e, NULL, i);
    e->setExits(NULL, NULL, NULL, d);
    f->setExits(NULL, g, a, h);
    g->setExits(NULL, NULL, NULL, f);
    h->setExits(NULL, f, NULL, NULL);
    i->setExits(NULL, d, j, NULL);
    j->setExits(i, k, NULL, NULL);
    k->setExits(NULL, l, NULL, j);
    l->setExits(NULL, NULL, NULL, k);



        currentRoom = a;


        rooms.push_back(a);
        rooms.push_back(b);
        rooms.push_back(c);
        rooms.push_back(d);
        rooms.push_back(e);
        rooms.push_back(f);
        rooms.push_back(g);
        rooms.push_back(h);
        rooms.push_back(i);
        rooms.push_back(j);
        rooms.push_back(k);
        rooms.push_back(l);
}

/**
 *  Main play routine.  Loops until end of play.
 */
void ZorkUL::play() {
    printWelcome();

    // Enter the main command loop.  Here we repeatedly read commands and
    // execute them until the ZorkUL game is over.

    bool finished = false;
    while (!finished) {
        // Create pointer to command and give it a command.
        Command* command = parser.getCommand();
        // Pass dereferenced command and check for end of game.
        finished = processCommand(*command);
        // Free the memory allocated by "parser.getCommand()"
        //   with ("return new Command(...)")
        delete command;
    }
    cout << endl;
    cout << "end" << endl;
}

void ZorkUL::printWelcome() {
    cout << "start"<< endl;
    cout << "info for help"<< endl;
    cout << endl;
    cout << currentRoom->longDescription() << endl;
}

/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the ZorkUL game, true is returned, otherwise false is
 * returned.
 */
bool ZorkUL::processCommand(Command command) {
    if (command.isUnknown()) {
        cout << "invalid input"<< endl;
        return false;
    }

    string commandWord = command.getCommandWord();
    if (commandWord.compare("info") == 0)
        printHelp();

    /*else if (commandWord.compare("map") == 0)
        {
        cout << "[h] --- [f] --- [g]" << endl;
        cout << "         |         " << endl;
        cout << "         |         " << endl;
        cout << "[c] --- [a] --- [b]" << endl;
        cout << "         |         " << endl;
        cout << "         |         " << endl;
        cout << "[i] --- [d] --- [e]" << endl;
        cout << " |                 " << endl;
        cout << " |                 " << endl;
        cout << "[j] --- [k] --- [l]" << endl;

    }*/

    //else if (commandWord.compare("go") == 0)
        //goRoom(command);

//    else if (commandWord.compare("teleport") == 0)
//    {
//        string roomName;
//        int randomNum = rand() % 12;
//            switch(randomNum) {
//            case(0):
//                roomName = "a";
//                break;
//            case(1):
//                roomName = "b";
//                break;
//            case(2):
//                roomName = "c";
//                break;
//            case(3):
//                roomName = "d";
//                break;
//            case(4):
//                roomName = "e";
//                break;
//            case(5):
//                roomName = "f";
//                break;
//            case(6):
//                roomName = "g";
//                break;
//            case(7):
//                roomName = "h";
//                break;
//            case(8):
//                roomName = "i";
//                break;
//            case(9):
//                roomName = "j";
//                break;
//            case(10):
//                roomName = "k";
//                break;
//            case(11):
//                roomName = "l";
//                break;
//            }
//        teleport(roomName);
//    }
    else if (commandWord.compare("take") == 0)
    {
        if (!command.hasSecondWord()) {
        cout << "incomplete input"<< endl;
        }
        else
         if (command.hasSecondWord()) {
        cout << "you're trying to take " + command.getSecondWord() << endl;
        int location = currentRoom->isItemInRoom(command.getSecondWord());
        if (location  < 0 )
            cout << "item is not in room" << endl;
        else {
            cout << "item is in room" << endl;
            cout << "index number " << + location << endl;
            cout << endl;
            cout << currentRoom->longDescription() << endl;
            }
         }
    }

    else if (commandWord.compare("put") == 0)
    {

    }
    /*
    {
    if (!command.hasSecondWord()) {
        cout << "incomplete input"<< endl;
        }
        else
            if (command.hasSecondWord()) {
            cout << "you're adding " + command.getSecondWord() << endl;
            itemsInRoom.push_Back;
        }
    }
*/
/*    else if (commandWord.compare("quit") == 0) {
        if (command.hasSecondWord())
            cout << "overdefined input"<< endl;
        else
            return true; signal to quit
    }*/
    return false;
}
/** COMMANDS **/
void ZorkUL::printHelp() {
    cout << "valid inputs are; " << endl;
    parser.showCommands();

}

/*void ZorkUL::goRoom(Command command) {
    if (!command.hasSecondWord()) {
        cout << "incomplete input"<< endl;
        return;
    }

    string direction = command.getSecondWord();

    // Try to leave current room.
    Room* nextRoom = currentRoom->nextRoom(direction);

    if (nextRoom == NULL)
        cout << "underdefined input"<< endl;
    else {
        currentRoom = nextRoom;
        cout << currentRoom->longDescription() << endl;
    }
}*/

string ZorkUL::go(string direction) {
    //Make the direction lowercase
    //transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
    //Move to the next room
    Room* nextRoom = currentRoom->nextRoom(direction);
    if (nextRoom == NULL)
        return("direction null");
    else
    {
        currentRoom = nextRoom;
        return currentRoom->longDescription();
    }
}


//Teleport method. if called will teleport you to a specified location.
void ZorkUL::teleport(string roomName) {
        for (unsigned int i = 0; i < rooms.size(); i++)
        {
            if (rooms[i]->shortDescription().compare(roomName) == 0) {
                currentRoom = rooms[i];
                cout << currentRoom->longDescription() << endl;
            }
        }
    }


Room* ZorkUL::getCurrentRoom() {
    return currentRoom;
}

void ZorkUL::setCurrentRoom(Room* inRoom) {
    currentRoom = inRoom;
}
