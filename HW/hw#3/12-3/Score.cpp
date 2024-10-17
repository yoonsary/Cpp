#include <iostream>
#include "Score.h"
using namespace std;

void Dept::read() {
	cout << size << "개 점수 입력>> ";
	for (int i = 0;i < size;i++) {
		cin >> scores[i];
	}
}

bool Dept::isOver60(int index) {
	return scores[index] >= 60;
}

Dept::~Dept() {
	delete[] scores;
}

int countPass(Dept& dept) {
	int count = 0;
	for (int i = 0; i < dept.getSize(); i++) {
		if (dept.isOver60(i)) count++;
	}
	return count;
}

int main() {
	Dept com(10);
	com.read();
	int n = countPass(com);
	cout << "60점 이상은 " << n << "명";
}
