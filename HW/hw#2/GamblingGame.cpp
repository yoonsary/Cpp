#include "GamblingGame.h"

void Player::setName(string name) {
	this->name = name;
}

string Player::getName() {
	return name;
}

void GamblingGame::play() {
	cout << "***** ���� ������ �����մϴ�. *****" << endl;
	string name;
	cout << "ù��° ���� �̸�>>";
	cin >> name;
	player[0].setName(name);
	cout << "�ι�° ���� �̸�>>";
	cin >> name;
	player[1].setName(name);
	cin.ignore();

	int endGame = 0;
	while (true) {
		for (int i = 0; i < 2; i++) {
			if (ranNum(player[i].getName())) {
				cout << player[i].getName() << "�� �¸�!!!" << endl;
				endGame++;
				break;
			}
			else
				cout << "�ƽ�����!" << endl;
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