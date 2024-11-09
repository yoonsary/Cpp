#include "Printer.h"

int main() {
	InkJetPrinter* ink = new InkJetPrinter("Officejet V40", "HP", 5, 10);
	LaserPrinter* laser = new LaserPrinter("SCX-6x45", "삼성전자", 3, 20);

	cout << "현재 작동중인 2 대의 프린터는 아래와 같다" << endl;
	cout << "잉크젯 : ";
	ink->showInkJetPrinter();
	cout << "레이저 : ";
	laser->showLaserPrinter();

	int printer, paper;
	char ch;
	while (true) {
		cout << endl << "프린터(1:잉크젯, 2:레이저)와 매수 입력>>";
		cin >> printer >> paper;
		if (printer == 1) ink->printInkJet(paper);
		else if (printer == 2) laser->printLaser(paper);
		else cout << "프린터를 잘못 선택하셨습니다." << endl;

		ink->showInkJetPrinter();
		laser->showLaserPrinter();

		cout << "계속 프린트 하시겠습니까(y/n)>>";
		cin >> ch;
		if (ch == 'n') break;
		else if (ch == 'y') continue;
		else cout << "잘못 입력하셨습니다." << endl;
	}

	delete ink;
	delete laser;
	return 0;
}