#include <iostream>
#include "graphiceditor.h"
#include "ui.h"
#include "shape.h"
#include "circle.h"
#include "rect.h"
#include "line.h"
using namespace std;

int main() {
	GraphicEditor* g = new GraphicEditor();
	g->call();
}