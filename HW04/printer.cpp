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
		cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
}

void Printer::showPrinter() {
		cout << model << ", " << manufacturer << ", ���� ���� " << availableCount << "��";
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
			cout << "����Ʈ�Ͽ����ϴ�" << endl;
		}
		else
			cout << "��ũ�� �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
	}
	else
		cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
}

void InkJetPrinter::showInkJetPrinter() {
	showPrinter();
	cout << ", ���� ��ũ " << availableInk << endl;
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
			cout << "����Ʈ�Ͽ����ϴ�" << endl;
		}
		else
			cout << "��ʰ� �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
	}
	else
		cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
}

void LaserPrinter::showLaserPrinter() {
	showPrinter();
	cout << ", ������� " << availableToner << endl;
}