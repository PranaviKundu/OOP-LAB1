// Implement a class Complex which represents the Complex Number data type. Implement the
// following
// 1. Constructor (including a default constructor which creates the complex number 0+0i).
// 2. Overload operator+ to add two complex numbers.
// 3. Overload operator* to multiply two complex numbers.
// 4. Overload operators << and >> to print and read Complex Numbers.
#include <iostream>

using namespace std;

class Complex {
private:
    double real;
    double imaginary;
// double real: Stores the real part of the complex number.
// double imaginary: Stores the imaginary part of the complex number.

public:
    // Constructors
    Complex() : real(0.0), imaginary(0.0) {}
    // Default constructor initializes real and imaginary to '0.0'
    Complex(double r, double i) : real(r), imaginary(i) {}
    // Parameterized constructor initializes real to r and imaginary to i.

    // Operator overloading
    Complex operator + (const Complex& other)  const {
        return Complex(real + other.real, imaginary + other.imaginary);
    }
    // Return Type: Complex: Indicates that the function will return an object of type Complex.
    // Operator: operator+: This defines the addition operator (+)
    // Parameter: const Complex& other: This parameter is a reference to another Complex object (other).
    // It's marked as const to ensure that the other object is not modified within the function, thus ensuring const-correctness and preventing accidental modifications.
    // const Member Function: The const keyword at the end of the function declaration (const) ensures that 
    // this member function does not modify the state of the object (*this), which is important for maintaining object integrity and enabling const-correctness.
    Complex operator * (const Complex& other) const {
        // operator*:multiply two complex numbers using formula:
        // (a+bi)×(c+di)=(ac−bd)+(ad+bc)i
        double r = real * other.real - imaginary * other.imaginary;
        double i = real * other.imaginary + imaginary * other.real;
        return Complex(r, i);
    }

    // Stream insertion and extraction operators
    friend ostream& operator << (ostream& out, const Complex& c) {
        out << c.real << " + " << c.imaginary << "i";
        return out;
    }

    friend istream& operator >> (istream& in, Complex& c) {
        // friend function is a function that is not a member of a class but has access to the private and protected members of the class if it is declared as a friend within that class.
        
        cout << "Enter real part: ";
        in >> c.real;
        cout << "Enter imaginary part: ";
        in >> c.imaginary;
        return in;
    }
};

int main() {
    Complex c1(3.0, 4.0);
    Complex c2(2.0, -1.0);

    // Addition
    Complex sum = c1 + c2;
    cout << "Sum: " << sum << endl;

    // Multiplication
    Complex product = c1 * c2;
    // Demonstrates the use of operator+ to add two complex numbers (c1 and c2).
    cout << "Product: " << product << endl;

    // Input and output using stream operators
    Complex c3;
    cout << "Enter a complex number:" << endl;
    cin >> c3;
    cout << "You entered: " << c3 << endl;

    return 0;
}
