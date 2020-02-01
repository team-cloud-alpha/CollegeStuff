/**
Name: Gautam Abhyankar
Panel: B
Roll No. : PB - 49 
*/

// Problem Statement: Define a class Complex consisting following:
// Data members:
// 	a. real
//	 b. imaginary part
// Member Functions:
// 	a. One default constructor
// 	b. Function setComplex () to set the value of real and imaginary part.
//	c. Function printComplex() to display
// and
//	 1. Four overloaded operator member functions
// 		i. Operator+ to add two complex numbers.
// 		ii. Operator * to multiply two complex numbers.
// 		iii. Overloaded &lt;&lt; and &gt;&gt; to print and read Complex Numbers.

// 2. Friend function to add two complex number by taking two reference variables of
// class complex and returning another reference.

#include<iostream>

using namespace std;

class Complex
{
	private:
	double _r, _i;
	
	public:
	//Constructor to initialize complex number
	Complex() : _r(0), _i(0) {};
	//To set the values of Complex Number
	void SetComplex(void);
	//To print the values of the Complex Number
	void PrintComplex();
	//Operator overload to add Complex Numbers
	Complex operator +(Complex);
	//Operator overload to multiply Complex Numbers
	Complex operator *(Complex);
	//Operator overload to pass Complex Numbers to output stream
	friend ostream& operator <<(ostream& out, Complex& c);
	//Operator overload to get Complex Numbers from input stream
	friend istream& operator >>(istream& in, Complex& c);
	//Friend function to add 2 complex numbers
	friend Complex& AddComplex(Complex& c1, Complex& c2);
};

void Complex::SetComplex()
{
	cin >> *this;
}

void Complex::PrintComplex()
{
	cout << *this;
}

Complex Complex::operator +(Complex c2)
{
	Complex res;
	res._r = _r + c2._r;
	res._i = _i + c2._i;
	return res;
}

Complex Complex::operator *(Complex c2)
{
	Complex res;
	res._r = _r * c2._r - _i * c2._i;
	res._i = _r * c2._i + _i * c2._r;
	return res; 
}

ostream& operator << (ostream& out, Complex &c)
{
	out << c._r << " + " << c._i << "i" << endl;
	return out;
}

istream& operator >> (istream& in, Complex& c)
{
	cout << "Enter real part:- ";
	in >> c._r;
	cout << "Enter imaginary part:- ";
	in >> c._i;
	return in;
}

Complex& AddComplex(Complex& c1, Complex &c2) 
{
	c1 = c1 + c2;
	return c1;
} 

int main()
{
	Complex c1, c2;
	cout << "Enter Complex No. 1" << endl;
	c1.SetComplex();
	cout << "\nEnter Complex No. 2" << endl;
	c2.SetComplex();
	cout << "\nAddition of the given complex" << endl;
	auto c3 = c1 + c2;
	c3.PrintComplex();
	cout << "\nMultiplication of the given complex numbers" << endl;
	auto c4 = c1 * c2;
	c4.PrintComplex();
	return 0;
}

/** 
mitwpu@C04L0830:~/Downloads$ g++ complex.cpp -std="c++17"
mitwpu@C04L0830:~/Downloads$ ./a.out
Enter Complex No. 1
Enter real part:- 2
Enter imaginary part:- 1

Enter Complex No. 2
Enter real part:- 1
Enter imaginary part:- 2

Addition of the given complex
3 + 3i

Multiplication of the given complex numbers
0 + 5i 
*/