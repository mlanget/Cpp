#include <iostream>
#include "ui.h"
using namespace std;

int UI::selectFn() {
	int fnNum;
	cout << "����:1, ����:2, ��κ���:3, ����:4 >> ";
	cin >> fnNum;
	return fnNum;
}
int UI::selectShape() {
	int shapeNum;
	cout << "��:1, ��:2, �簢��:3 >> ";
	cin >> shapeNum;
	return shapeNum;
}
int UI::deleteShape() {
	int shapeIndex;
	cout << "�����ϰ��� �ϴ� ������ �ε��� >> ";
	cin >> shapeIndex;
	return shapeIndex;
}