#include <iostream>

using namespace std;
#include "ZorkUL.h"

ZorkUL::ZorkUL() {
    createRooms();
}

void ZorkUL::createRooms()  {
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i, *j, *k, *l;

    a = new Room("a");
    b = new Room("b");
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

    l->addItem(new Item("Key", 4, 44));

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

//Teleport method. if called will teleport you to a specified location.
string ZorkUL::teleport(string roomName) {
        for (unsigned int i = 0; i < rooms.size(); i++)
        {
            if (rooms[i]->shortDescription().compare(roomName) == 0) {
                currentRoom = rooms[i];
                string s = currentRoom->longDescription() + "\n";
                return s;
            }
        }
        return "No Room Found";
    }


Room* ZorkUL::getCurrentRoom() {
    return currentRoom;
}

void ZorkUL::setCurrentRoom(Room* inRoom) {
    currentRoom = inRoom;
}
