#pragma once
#include <string>
using namespace std;

class Printer {
protected:
	string model, manufacturer;
	int printedCount, availableCount;
public:
	Printer(string model, string manufacturer, int availableCount);
	void print(int pages);
	void showPrinter();
};

class InkJetPrinter : protected Printer {
	int availableInk;
public:
	InkJetPrinter(string model, string manufacturer, int availableCount, int availableInk);
	void printInkJet(int pages);
	void showInkJetPrinter();
};

class LaserPrinter : protected Printer {
	float availableToner;
public:
	LaserPrinter(string model, string manufacturer, int availableCount, float availableToner);
	void printLaser(int pages);
	void showLaserPrinter();
};