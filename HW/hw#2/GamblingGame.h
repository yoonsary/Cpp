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
	void setName(string name);
	string getName();
};

class GamblingGame {
	Player player[2];
public:
	void play();
	bool ranNum(string name);
};

#endif