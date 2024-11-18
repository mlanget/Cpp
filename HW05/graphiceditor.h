#pragma once

class Shape;
class GraphicEditor {
	Shape* pStart;
	Shape* pLast;
	void add(Shape* p);
protected:
	void insert(int shapeNum);
	void remove(int shapeIndex);
	void show();
public:
	GraphicEditor();
	~GraphicEditor();
	void call();
};