//
// a Complex object holds one Complex number
#include <iostream>
#include <cmath>

using namespace std;
#include "Complex.h"

//------------------------------ Complex ------------------------------------
// default constructor: parameters are real and imaginary parts respectively
Complex::Complex(double re, double im)
{
	this->re = re;
	this->im = im;
}
//(a)------------------------------- add ------------------------------------
// addition of 2 complex number, current object and parameter
Complex Complex::add(const Complex& z)
{
	Complex c;
	c.re = re + z.re;
	c.im = im + z.im;
	return c;
}
//(b)---------------------------- subtract ----------------------------------
// subtraction of 2 complex number, current object and parameter
Complex Complex::subtract(const Complex& z) {
	Complex c;
	c.re = re - z.re;
	c.im = im - z.im;
	return c;
}
//(c)---------------------------- multiply ----------------------------------
Complex Complex::multiply(const Complex& z) {
	Complex c;
	c.re = re * z.re;
	c.im = im * z.im;
	return c;
}
//(d)------------------------------ divide ----------------------------------
// division of 2 complex number, current object and parameter,
// division by zero crashes
Complex Complex::divide(const Complex& z) {
	Complex c;
	c.re = re / z.re;
	c.im = im / z.im;
	if (c.re == 0 || c.im == 0) {
		return 0;
	}
	else {
		return c;
	}

}
//(e)------------------------------ equality ---------------------------------
// equality of 2 complex number, current object and parameter
bool Complex::equal(const Complex &z){
	Complex c;
	if (c.re == c.im) {
		return true;
	}
	else {
		return false;
	}
}
//(f)------------------------------ modulus ---------------------------------
double Complex::modulus() {
	Complex c;
	double modulus = sqrt(pow(c.re, 2) + pow(c.im, 2));
	return modulus;
}
//(g)------------------------------ print -----------------------------------
// print the complex number with the format: a + bi (or a - bi)
// enclosed the complex number with parenthesis if is_parenthesis is true
// e.g., is_parenthesis = true: (4 + 2i), (-10 +7i), etc.
void Complex::print(bool is_parenthesis) {

	if (is_parenthesis) {
		cout << "(";
	}

	cout << re;

	if (im >= 0) {
		cout << " + " << im << "i";
	}
	else {
		cout << " - " << -im << "i";
	}

	if (is_parenthesis) {
		cout << ")";
	}

	cout << endl;

}