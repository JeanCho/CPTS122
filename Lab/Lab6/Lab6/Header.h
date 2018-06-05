#pragma once

#include <iostream>
#include <string>
using std::endl;
using  std::cout;

class Complex
{
	public:
		Complex(double realPart, double imaginaryPart);
		void setreal(double reaPart);
		void setimaginary(double imaginaryPart);

		double getreal();
		double getimaginary();

		Complex add(const Complex &cp1);
		Complex(Complex &copyComplex);
		Complex();
		~Complex();

	private:
		double pReal;
		double pImaginary;
};

Complex operator+ (Complex &lhs, Complex &rhs)
{
	Complex result;
	result.setimaginary(lhs.getimaginary() + rhs.getimaginary());
	result.setreal(lhs.getreal() + rhs.getreal());

	return result;
}

Complex Complex::add (const Complex  &cp1)
{
	Complex result;
	result.setreal( pReal + cp1.pReal);
	result.setimaginary(pImaginary + cp1.pImaginary);
	return result;

}
void Complex::setreal(double realPart)
{
	pReal = realPart;
}

void Complex::setimaginary(double imaginaryPart)
{
	pImaginary = imaginaryPart;
}

double Complex::getreal()
{
	return pReal;
}
double Complex::getimaginary()
{
	return pImaginary;
}
Complex::Complex(double realPart, double imaginaryPart)
{
	pReal = realPart;
	pImaginary = imaginaryPart;
}
Complex::Complex()
{
	pReal = 0;
	pImaginary = 0;
}
Complex::Complex(Complex &copyComplex)
{
	pReal=(copyComplex.getreal());
	pImaginary=(copyComplex.getimaginary());
	
	
}
Complex::~Complex()
{
	cout<< "Inside of Complex destructor!" << endl;
 }
