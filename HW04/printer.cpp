#include <iostream>
#include <string>
#include "printer.h"
using namespace std;

Printer::Printer(string model, string manufacturer, int availableCount) { 
		this->model = model;
		this->manufacturer = manufacturer;
		this->availableCount = availableCount;
		printedCount = 0;
}

void Printer::print(int pages) {
	if (availableCount >= pages) {
		printedCount += pages;
		availableCount -= pages;
	}
	else
		cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
}

void Printer::showPrinter() {
		cout << model << ", " << manufacturer << ", 남은 종이 " << availableCount << "장";
}


InkJetPrinter::InkJetPrinter(string model, string manufacturer, int availableCount, int availableInk)
	: Printer(model, manufacturer, availableCount) {
	this->availableInk = availableInk;
}
	
void InkJetPrinter::printInkJet(int pages) {
	if (availableCount >= pages) {
		if (availableInk >= pages) {
			print(pages);
			availableInk -= pages;
			cout << "프린트하였습니다" << endl;
		}
		else
			cout << "잉크가 부족하여 프린트할 수 없습니다." << endl;
	}
	else
		cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
}

void InkJetPrinter::showInkJetPrinter() {
	showPrinter();
	cout << ", 남은 잉크 " << availableInk << endl;
}

LaserPrinter::LaserPrinter(string model, string manufacturer, int availableCount, float availableToner)
	: Printer(model, manufacturer, availableCount) {
	this->availableToner = availableToner;
}

void LaserPrinter::printLaser(int pages) {
	if (availableCount >= pages) {
		if (availableToner >= pages*0.5) {
			print(pages);
			availableToner -= pages*0.5;
			cout << "프린트하였습니다" << endl;
		}
		else
			cout << "토너가 부족하여 프린트할 수 없습니다." << endl;
	}
	else
		cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
}

void LaserPrinter::showLaserPrinter() {
	showPrinter();
	cout << ", 남은토너 " << availableToner << endl;
}