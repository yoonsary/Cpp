#include "Printer.h"

int main() {
	InkJetPrinter* ink = new InkJetPrinter("Officejet V40", "HP", 5, 10);
	LaserPrinter* laser = new LaserPrinter("SCX-6x45", "�Ｚ����", 3, 20);

	cout << "���� �۵����� 2 ���� �����ʹ� �Ʒ��� ����" << endl;
	cout << "��ũ�� : ";
	ink->showInkJetPrinter();
	cout << "������ : ";
	laser->showLaserPrinter();

	int printer, paper;
	char ch;
	while (true) {
		cout << endl << "������(1:��ũ��, 2:������)�� �ż� �Է�>>";
		cin >> printer >> paper;
		if (printer == 1) ink->printInkJet(paper);
		else if (printer == 2) laser->printLaser(paper);
		else cout << "�����͸� �߸� �����ϼ̽��ϴ�." << endl;

		ink->showInkJetPrinter();
		laser->showLaserPrinter();

		cout << "��� ����Ʈ �Ͻðڽ��ϱ�(y/n)>>";
		cin >> ch;
		if (ch == 'n') break;
		else if (ch == 'y') continue;
		else cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
	}

	delete ink;
	delete laser;
	return 0;
}