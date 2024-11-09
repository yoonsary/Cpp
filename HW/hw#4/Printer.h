#ifndef PRINTER_H
#define PRINTER_H

#include <iostream>
#include <string>
using namespace std;

class Printer {
	string model;
	string manufacturer;
	int printedCount;
	int availableCount;
protected:
	Printer(string model, string manuf, int a = 0);
	~Printer() {}
	bool print(int pages);
	void showPrinter();
};

class InkJetPrinter : public Printer {
	int availableInk;
public:
	InkJetPrinter(string model, string manuf, int a = 0, int i = 0);
	~InkJetPrinter() {}
	bool printInkJet(int pages);
	void showInkJetPrinter();
};

class LaserPrinter : public Printer {
	int availableToner;
public:
	LaserPrinter(string model, string manuf, int a = 0, int t = 0);
	~LaserPrinter() {}
	bool printLaser(int pages);
	void showLaserPrinter();
};

#endif