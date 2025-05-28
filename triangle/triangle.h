#pragma once

//define class
class Triangle {
private:
	double base;
	double height;
public:
	double getBase() const;
	double getHeight() const;
	double getArea() const;
	void setBase(double);
	void setHeight(double);

};