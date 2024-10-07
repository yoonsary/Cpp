#include "GamblingGame.h"

void Player::setName(string name) {
	this->name = name;
}

string Player::getName() {
	return name;
}

void GamblingGame::play() {
	cout << "***** 갬블링 게임을 시작합니다. *****" << endl;
	string name;
	cout << "첫번째 선수 이름>>";
	cin >> name;
	player[0].setName(name);
	cout << "두번째 선수 이름>>";
	cin >> name;
	player[1].setName(name);
	cin.ignore();

	int endGame = 0;
	while (true) {
		for (int i = 0; i < 2; i++) {
			if (ranNum(player[i].getName())) {
				cout << player[i].getName() << "님 승리!!!" << endl;
				endGame++;
				break;
			}
			else
				cout << "아쉽군요!" << endl;
		}
		if(endGame == 1)
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
	GamblingGame gg;
	gg.play();

	return 0;
}