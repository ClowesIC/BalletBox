#pragma once
class Complex { // not fully commented
public:
	Complex(double re = 0.0, double im = 0.0); // default constructor
	Complex add(const Complex& z);
	Complex subtract(const Complex& z);
	Complex multiply(const Complex& z);
	Complex divide(const Complex& z);
	bool equal(const Complex& z);
	double modulus();
	void print(bool is_parenthesis = false);
private:
	double re; // real part
	double im; // imaginary part
};
