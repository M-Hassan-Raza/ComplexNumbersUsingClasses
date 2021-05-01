#include <iostream>
#include <cmath>

using namespace std;

class ComplexNumber
{
private:
	int real;
	int imaginary;
public:
	ComplexNumber(int, int); //with default arguments
	~ComplexNumber(); //Does Nothing.
	void Input();
	void Output();
	bool IsEqual(ComplexNumber);
	ComplexNumber Conjugate();
	ComplexNumber Add(ComplexNumber);
	ComplexNumber Subtract(ComplexNumber);
	ComplexNumber Multiplication(ComplexNumber);
	float Magnitude();
};


ComplexNumber::ComplexNumber(int r = 0, int imag = 0)
{
	real = r;
	imaginary = imag;

}


ComplexNumber::~ComplexNumber()
{

}


void ComplexNumber::Input()
{
	cout << "Enter Real: \t\t";
	cin >> real;

	cout << "Enter Imaginary: \t";
	cin >> imaginary;

	while(imaginary == 0)
	{
		cout << "Imaginary part can't be 0 for complex numbers. Input again: ";
		cin >> imaginary;
	}

	return;
}


void ComplexNumber::Output()
{
	if(real != 0 && imaginary != 0)
	{
		if(imaginary > 0)
		{
			cout << real << "+" << imaginary << "i\n";
		}
		else if (imaginary < 0)
		{
			cout << real << imaginary << "i\n";
		}
	}
	else if (real == 0 && imaginary != 0)
	{
		cout << imaginary << "i\n";
	}
	else if (real != 0 && imaginary == 0)
	{
		cout << real << "\n";
	}
	else if (real == 0 && imaginary == 0)
	{
		cout << "0\n";
	}


	return;

}


//The complex conjugate of the complex number z = x + yi is given by x − yi. So, we just multiply the imaginary part by -1. 
ComplexNumber ComplexNumber::Conjugate()
{
	ComplexNumber conj;
	conj.real = real;
	conj.imaginary = imaginary * (-1);

	return conj;


}

//Two complex numbers a1 + b1i and a2 + b2i are equal if both their real and imaginary parts are equal, that is, if a1 = a2 and b1 = b2
//So, we just compare th real and imaginary part of both complex numbers, if they are equal we return true. Otherwise, return false. 
bool ComplexNumber::IsEqual(ComplexNumber c2)
{
	if((real == c2.real) && (imaginary == c2.imaginary))
	{
		return true;
	}

	return false;

}


//Two complex numbers a and b are most easily added by separately adding their real and imaginary parts of the summands. a+b=(x+yi)+(u+vi)=(x+u)+(y+v)i
//So, just just add the real and imaginary parts separately. 
ComplexNumber ComplexNumber::Add(ComplexNumber c2)
{
	ComplexNumber add;
	add.real = real + c2.real;
	add.imaginary = imaginary + c2.imaginary;

	return add;
}


//Subtraction can be performed as: a-b=(x+yi)-(u+vi)=(x-u)+(y-v)i.
//So, just just subtract the real and imaginary parts separately. 
ComplexNumber ComplexNumber::Subtract(ComplexNumber c2)
{
	ComplexNumber sub;
	sub.real = real - c2.real;
	sub.imaginary = imaginary - c2.imaginary;

	return sub;
}


//Two complex numbers, z = x + yi and w = u + vi are multiplied under the rules of the distributive and commutative properties, and i^2 = −1
//So, we just multiply real with real, and imaginary with imaginary. Multiply imaginary with -1 (as i^2 = -1). Then add them together.
//Then, multiply real with imaginary, and imaginary with real. Add them together normally. 
ComplexNumber ComplexNumber::Multiplication(ComplexNumber c2)
{
	ComplexNumber multiply;

	multiply.real = (real * c2.real) + ((imaginary * c2.imaginary) * (-1));
	multiply.imaginary = (real * c2.imaginary) + (c2.real * imaginary);

	return multiply;
}

//The magnitude/modulus, of a complex number in the form z = a + bi is the positive square root of the sum of the squares of a and b. 
//Simply, it's |z| = sqrt(a^2 + b^2).
float ComplexNumber::Magnitude()
{
	float magnitude;
	magnitude = sqrt((real * real) + (imaginary * imaginary));

	return magnitude;
}


int main()
{
	ComplexNumber c1, c2, conjC1, conjC2, addition, subtraction, multiplication;
	float magnitudeC1, magnitudeC2;
	bool equalOrNot;

	cout << "Enter C1: \n";
	c1.Input();


	cout << "\nEnter C2: \n";
	c2.Input();


	cout << "\n\nc1 = ";
	c1.Output();
	

	cout << "\nc2 = ";
	c2.Output();


	equalOrNot = c1.IsEqual(c2);
	if(equalOrNot)
	{
		cout << "\n\nc1 is Equal to c2\n";
	}
	else
	{
		cout << "\n\nc1 is NOT Equal to c2\n";
	}


	conjC1 = c1.Conjugate();
	cout << "\n\nConjugate of c1: ";
	conjC1.Output();
	

	conjC2 = c2.Conjugate();
	cout << "\nConjugate of c2: ";
	conjC2.Output();
	

	addition = c1.Add(c2);
	cout << "\n\nc1 + c2 : ";
	addition.Output();
	

	subtraction = c1.Subtract(c2);
	cout << "\nc1 - c2 : ";
	subtraction.Output();
	

	multiplication = c1.Multiplication(c2);
	cout << "\nc1 * c2 : ";
	multiplication.Output();
	

	magnitudeC1 = c1.Magnitude();
	cout << "\n\nMagnitude of c1 = " << magnitudeC1 << "\n\n";
	

	magnitudeC2 = c2.Magnitude();
	cout << "\nMagnitude of c2 = " << magnitudeC2 << "\n\n";
	

	system("pause>0");
}
