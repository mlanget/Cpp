#pragma once
#include <vector>
using namespace std;

class Shape;
class GraphicEditorVector {
	vector<Shape*> v;
protected:
	void insert(int shapeNum);
	void remove(int shapeIndex);
	void show();
public:
	GraphicEditorVector();
	~GraphicEditorVector();
	void call();
};