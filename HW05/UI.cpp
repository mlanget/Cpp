#include <iostream>
#include "ui.h"
using namespace std;

int UI::selectFn() {
	int fnNum;
	cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >> ";
	cin >> fnNum;
	return fnNum;
}
int UI::selectShape() {
	int shapeNum;
	cout << "선:1, 원:2, 사각형:3 >> ";
	cin >> shapeNum;
	return shapeNum;
}
int UI::deleteShape() {
	int shapeIndex;
	cout << "삭제하고자 하는 도형의 인덱스 >> ";
	cin >> shapeIndex;
	return shapeIndex;
}