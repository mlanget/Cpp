#include <iostream>
#include <string>
#include "printer.h"
using namespace std;

int main() {
	InkJetPrinter* inkjet = new InkJetPrinter("officejet V40", "HP", 5, 10);
	LaserPrinter* laser = new LaserPrinter("SCX-6x45", "�Ｚ����", 3, 20);

	cout << "���� �۵����� 2 ���� �����ʹ� �Ʒ��� ����" << endl;
	cout << "��ũ�� : ";
	inkjet->showInkJetPrinter();
	cout << "������ : ";
	laser->showLaserPrinter();

	int printer, pages;
	char ch;
	while (true) {
		cout << endl << "������(1:��ũ��, 2:������)�� �ż� �Է�>>";
		cin >> printer >> pages;
		if (printer == 1) {
			inkjet->printInkJet(pages);
		}
		else if (printer == 2) {
			laser->printLaser(pages);
		}
		else {
			cout << "�ٽ� �Է����ּ���." << endl;
			continue;
		}
		inkjet->showInkJetPrinter();
		laser->showLaserPrinter();

		cout << "��� ����Ʈ �Ͻðڽ��ϱ�(y/n)>>";
		cin >> ch;
		if (ch == 'y') {
			continue;
		}
		else if (ch == 'n') {
			break;
		}
		else
			cout << "�ٽ� �Է����ּ���." << endl;
	}
	delete inkjet;
	delete laser;
}