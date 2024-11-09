#include <iostream>
#include <string>
#include "printer.h"
using namespace std;

int main() {
	InkJetPrinter* inkjet = new InkJetPrinter("officejet V40", "HP", 5, 10);
	LaserPrinter* laser = new LaserPrinter("SCX-6x45", "삼성전자", 3, 20);

	cout << "현재 작동중인 2 대의 프린터는 아래와 같다" << endl;
	cout << "잉크젯 : ";
	inkjet->showInkJetPrinter();
	cout << "레이저 : ";
	laser->showLaserPrinter();

	int printer, pages;
	char ch;
	while (true) {
		cout << endl << "프린터(1:잉크제, 2:레이저)와 매수 입력>>";
		cin >> printer >> pages;
		if (printer == 1) {
			inkjet->printInkJet(pages);
		}
		else if (printer == 2) {
			laser->printLaser(pages);
		}
		else {
			cout << "다시 입력해주세요." << endl;
			continue;
		}
		inkjet->showInkJetPrinter();
		laser->showLaserPrinter();

		cout << "계속 프린트 하시겠습니까(y/n)>>";
		cin >> ch;
		if (ch == 'y') {
			continue;
		}
		else if (ch == 'n') {
			break;
		}
		else
			cout << "다시 입력해주세요." << endl;
	}
	delete inkjet;
	delete laser;
}