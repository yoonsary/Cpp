#include "Printer.h"

Printer::Printer(string model, string manuf, int a) : model(model), manufacturer(manuf), availableCount(a), printedCount(0) {}

bool Printer::print(int pages) {
	if (availableCount > pages) {
		printedCount += pages;
		availableCount -= pages;
		return true;
	}
	else {
		cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
		return false;
	}
}

void Printer::showPrinter() {
	cout << model << ", " << manufacturer << ", 남은 종이 " << availableCount << "장";
}

InkJetPrinter::InkJetPrinter(string model, string manuf, int a, int i) : Printer(model, manuf, a), availableInk(i) {}

bool InkJetPrinter::printInkJet(int pages) {
	if (print(pages)) {
		if (availableInk > pages) {
			availableInk -= pages;
			cout << "프린트하였습니다" << endl;
			return true;
		}
		else {
			cout << "잉크가 부족하여 프린트할 수 없습니다." << endl;
			return false;
		}
	}
	return false;
}

void InkJetPrinter::showInkJetPrinter() {
	showPrinter();
	cout << ", 남은 잉크 " << availableInk << endl;
}

LaserPrinter::LaserPrinter(string model, string manuf, int a, int t) : Printer(model, manuf, a), availableToner(t) {}

bool LaserPrinter::printLaser(int pages) {
	if (print(pages)) {
		if (availableToner > pages) {
			availableToner--;
			cout << "프린트하였습니다" << endl;
			return true;
		}
		else {
			cout << "토너가 부족하여 프린트할 수 없습니다." << endl;
			return false;
		}
	}
	return false;
}

void LaserPrinter::showLaserPrinter() {
	showPrinter();
	cout << ", 남은 토너 " << availableToner << endl;
}
