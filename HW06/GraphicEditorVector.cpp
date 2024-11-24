#include <iostream>
#include <vector>
#include "graphiceditorvector.h"
#include "ui.h"
#include "shape.h"
#include "circle.h"
#include "rect.h"
#include "line.h"
using namespace std;

GraphicEditorVector::GraphicEditorVector() {}
GraphicEditorVector::~GraphicEditorVector() {
	for (int i=0; i<v.size(); i++)
		delete v[i];
}

void GraphicEditorVector::insert(int shapeNum) {
	switch (shapeNum) {
	case 1:
		v.push_back(new Line());
		break;
	case 2:
		v.push_back(new Circle());
		break;
	case 3:
		v.push_back(new Rect());
		break;
	default:
		break;
	}
}

void GraphicEditorVector::remove(int shapeIndex) {
	if (v.empty()) {
		cout << "������ ������ �����ϴ�." << endl;
		return;
	}
	if (shapeIndex < 0 || shapeIndex >= v.size()) {
		cout << "��ȿ���� ���� �ε���" << endl;
		return;
	}
	delete v[shapeIndex];
	v.erase(v.begin() + shapeIndex);
}

void GraphicEditorVector::show() {
	if (v.empty()) {
		cout << "����� ������ �����ϴ�." << endl;
		return;
	}
	for (int i = 0; i < v.size(); ++i) {
		cout << i << ": ";
		v[i]->paint();
	}
}

void GraphicEditorVector::call() {
	cout << "�׷��� �������Դϴ�." << endl;

	while (true) {
		int fn = UI::selectFn();
		switch (fn) {
		case 1:
			insert(UI::selectShape());
			break;
		case 2:
			remove(UI::deleteShape());
			break;
		case 3:
			show();
			break;
		case 4:
			cout << "�׷��� �����͸� �����մϴ�." << endl;
			exit(0);
		default:
			cout << "�ٽ� �Է����ּ���" << endl;
			break;
		}
	}
}