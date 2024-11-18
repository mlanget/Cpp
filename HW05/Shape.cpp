#include <iostream>
#include "shape.h"
using namespace std;

void Shape::paint() {
	draw();
}

Shape* Shape::add(Shape* p) {
	this->next = p;
	return p;
}