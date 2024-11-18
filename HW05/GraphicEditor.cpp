#include <iostream>
#include "graphiceditor.h"
#include "ui.h"
#include "shape.h"
#include "circle.h"
#include "rect.h"
#include "line.h"
using namespace std;

GraphicEditor::GraphicEditor() {
	pStart = NULL;
	pLast = NULL;
}
GraphicEditor::~GraphicEditor() {
	while (pStart != NULL) {
		Shape* p = pStart;
		pStart = pStart->getNext();
		delete p;
	}
}

void GraphicEditor::insert(int shapeNum) {
	Shape* p = NULL;
	switch (shapeNum) {
	case 1:
		p = new Line();
		break;
	case 2:
		p = new Circle();
		break;
	case 3:
		p = new Rect();
		break;
	default:
		break;
	}

	if (p == NULL)
		return;
	if (pStart == NULL) {
		pStart = p;
		pLast = p;
	}
	else {
		pLast = pLast->add(p);
	}
}

void GraphicEditor::remove(int shapeIndex) {
	if (pStart == NULL) {
		cout << "삭제할 도형이 없습니다." << endl;
	}

	Shape* prep = NULL;
	Shape* curp = pStart;
	int currentIndex = 0;
	while (curp != NULL && currentIndex < shapeIndex) {
		prep = curp;
		curp = curp->getNext();
		currentIndex++;
	}
	if (prep == NULL) {
		pStart = curp->getNext();
	} else {
		prep->add(curp->getNext());
	}
	if (curp == pLast) {
		pLast = prep;
	}
	delete curp;
}

void GraphicEditor::show() {
	if (pStart == NULL) {
		cout << "도형이 없습니다." << endl;
		return;
	}

	Shape* p = pStart;
	int index = 0;

	while (p != NULL) {
		cout << index++ << ": ";
		p->paint();
		p = p->getNext();
	}
}

void GraphicEditor::call() {
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