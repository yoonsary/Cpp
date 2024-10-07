#ifndef GAMBLINGGAME_H
#define GAMBLINGGAME_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Player {
	string name;
public:
	Player(string name);
	string getName();
};

class GamblingGame {
	Player* players[2];
public:
	GamblingGame(string name1, string name2);
	~GamblingGame();
	void play();
	bool ranNum(string name);
};

#endif
