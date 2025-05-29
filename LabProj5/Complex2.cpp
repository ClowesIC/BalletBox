//
// Name: skeleton template for overloading operators  
//
// One Complex object holds one Complex number

#include "Complex2.h"

//------------------------------ Complex ------------------------------------
// default constructor:  parameters are real and imaginary parts respectively
Complex::Complex(double re, double im)
{
   this->re = re;
   this->im = im;
}

//(a)------------------------------- add -------------------------------------
// overloaded +: addition of 2 complex numbers, current object and parameter
Complex Complex::operator+(const Complex& z) {
	Complex c;
	c.re = re + z.re;
	c.im = im + z.im;
	return c;
}

//(b)------------------------------ subtract ---------------------------------
// overloaded -: subtract 2 complex numbers, current object and parameter
Complex Complex::operator-(const Complex& z) {
	Complex c;
	c.re = re - z.re;
	c.im = im - z.im;
	return c;
}

//(c)------------------------------ multiply ---------------------------------
// overloaded *: multiply 2 complex numbers, current object and parameter
Complex Complex::operator*(const Complex& z) {
	Complex c;
	c.re = re * z.re;
	c.im = im * z.im;
	return c;
}

//(d)-------------------------------- divide ---------------------------------
// overloaded /: divide 2 complex numbers, current object and parameter
// check division by zero condition
Complex Complex::operator/(const Complex& z) {
	Complex c;
	c.re = re / z.re;
	c.im = im / z.im;
	if (z.re == 0 || z.im == 0) {
		cout << "Divide by Zero ERROR!!!";
		return c;
	}
	else {
		return c;
	}
}

//(e)-------------------------------- equal ----------------------------------
// overloaded ==: equal comparison of current Complex object and parameter
bool Complex::operator==(Complex& z) {
	return (re == z.re && im == z.im);
}

//(f)------------------------------- not equal -------------------------------
// overloaded !=: not equal comparison of current Complex object and parameter
bool Complex::operator!=(Complex& z) {
	return (re != z.re && im != z.im);
}


//(g)-------------------------------- print-----------------------------------
// overloaded print()
void Complex::print(ostream& os) {
	os << "(" << re;

	if (im >= 0) {
		os << " + " << im << "i";
	}
	else {
		os << " - " << -im << "i";
	}

	os << ") \n";

}


//(h)--------------------------------- << -------------------------------------
// overloaded << (output operator)
ostream & operator<<(ostream & os, Complex & z)
{
	z.print(os);
	return os;

}


