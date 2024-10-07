#include "GamblingGame.h"

Player::Player(string name) {
	this->name = name;
}

string Player::getName() {
	return name;
}

GamblingGame::GamblingGame(string name1, string name2) {
	players[0] = new Player(name1);
	players[1] = new Player(name2);
}

GamblingGame::~GamblingGame() {
	delete players[0];
	delete players[1];
}

void GamblingGame::play() {
	cout << "***** 갬블링 게임을 시작합니다. *****" << endl;

	int endGame = 0;
	while (true) {
		for (int i = 0; i < 2; i++) {
			if (ranNum(players[i]->getName())) {
				cout << players[i]->getName() << "님 승리!!!" << endl;
				endGame++;
				break;
			}
			else
				cout << "아쉽군요!" << endl;
		}
		if (endGame == 1)
			break;
	}
}

bool GamblingGame::ranNum(string name) {
	srand((unsigned)time(NULL));
	cout << name << "<Enter>";
	while (true) {
		char ch;
		cin.get(ch);
		if (ch == '\n')
			break;
	}

	int num[3];
	cout << '\t' << '\t';
	for (int i = 0; i < 3; i++)
	{
		num[i] = rand() % 3;
		cout << num[i] << "\t";
	}
	if (num[0] == num[1] && num[0] == num[2])
		return true;
	else
		return false;
}

int main(void) {
	string name1, name2;
	cout << "첫번째 선수 이름>>";
	cin >> name1;
	cout << "두번째 선수 이름>>";
	cin >> name2;

	GamblingGame gg(name1, name2);
	gg.play();

	return 0;
}
