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
		cout << "삭제할 도형이 없습니다." << endl;
		return;
	}
	if (shapeIndex < 0 || shapeIndex >= v.size()) {
		cout << "유효하지 않은 인데스" << endl;
		return;
	}
	delete v[shapeIndex];
	v.erase(v.begin() + shapeIndex);
}

void GraphicEditorVector::show() {
	if (v.empty()) {
		cout << "저장된 도형이 없습니다." << endl;
		return;
	}
	for (int i = 0; i < v.size(); ++i) {
		cout << i << ": ";
		v[i]->paint();
	}
}

void GraphicEditorVector::call() {
	cout << "그래픽 에디터입니다." << endl;

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
			cout << "그래픽 에디터를 종료합니다." << endl;
			exit(0);
		default:
			cout << "다시 입력해주세요" << endl;
			break;
		}
	}
}