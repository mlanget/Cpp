#pragma once

class Shape {
protected:
	virtual void draw() = 0;
public:
	Shape() {}
	virtual ~Shape() { }
	void paint();
};
