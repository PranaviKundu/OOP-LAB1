#include <iostream> // this is the header file used to get standard input output from the hardware.
#include <cmath>

using namespace std;
// we have used namespace to use the std function everywhere in the code.

class Complex {
private: // we have declared it as private so that it cannot be altered anywhere in the code.
    double real;       // double real: Stores the real part of the complex number.
    double imaginary;  // double imaginary: Stores the imaginary part of the complex number.

public:
    // initialized the Constructor with the name Complex
    Complex() : real(0.0), imaginary(0.0) {}
    // Default constructor initializes real and imaginary to '0.0'
    Complex(double r, double i) : real(r), imaginary(i) {}
    // Parameterized constructor initializes real to r and imaginary to i.

    // Getter methods - Getters are often used to access values from an object that are not directly accessible, such as nested properties.
    double getReal() const { return real; }
    double getImag() const { return imaginary; }
    // getReal() and getImag(): Public methods to access the private members real and imaginary, respectively. These methods allow read-only access to the internal state of a Complex object.

    // Operator overloading - Polymorphism (or operator overloading) is a manner in which OO systems allow the same operator name or symbol to be used for multiple operations.
    Complex operator + (const Complex& other) const {
        return Complex(real + other.real, imaginary + other.imaginary);
    }
    // Return Type: Complex: Indicates that the function will return an object of type Complex.
    // Operator: operator+: This defines the addition operator (+)
    // Parameter: const Complex& other: This parameter is a reference to another Complex object (other).
    // It's marked as const to ensure that the other object is not modified within the function, thus ensuring const-correctness and preventing accidental modifications.
    // const Member Function: The const keyword at the end of the function declaration (const) ensures that 
    // this member function does not modify the state of the object (*this), which is important for maintaining object integrity and enabling const-correctness.

    // Overload - operator to subtract two complex numbers
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imaginary - other.imaginary);
    }

    Complex operator * (const Complex& other) const {
        // operator*: multiply two complex numbers using formula:
        // (a+bi)×(c+di)=(ac−bd)+(ad+bc)i
        double r = real * other.real - imaginary * other.imaginary;
        double i = real * other.imaginary + imaginary * other.real;
        return Complex(r, i);
    }

    Complex operator/(const Complex& other) const {
        // (a + bi) / (c + di) = ((a + bi) * (c - di)) / (c^2 + d^2)
        double denominator = other.real * other.real + other.imaginary * other.imaginary;
        double result_real = (real * other.real + imaginary * other.imaginary) / denominator;
        double result_imag = (imaginary * other.real - real * other.imaginary) / denominator;
        return Complex(result_real, result_imag);
    }

    // Member function to find argument (angle) of the complex number
    double argument() const {
        return atan2(imaginary, real);
    }

    // (Stream insertion and extraction operators)
    friend ostream& operator << (ostream& out, const Complex& c) {
        // (& used to create a reference of a variable)
        // (const specifies that the object is qualified to not modifiable. ensures that the value of the object cannot be changed through this reference.)
        out << c.real << " + " << c.imaginary << "i";
        return out;
    }

    friend istream& operator >> (istream& in, Complex& c) {
        // const Complex& is used to ensure that a function can access the object efficiently without allowing unintended modification  
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

    // Subtraction
    Complex diff = c1 - c2;
    cout << "Difference: " << diff << endl;

    // Multiplication
    Complex product = c1 * c2;
    cout << "Product: " << product << endl;

    // Division
    Complex quotient = c1 / c2;
    cout << "Quotient: " << quotient << endl;

    // Argument
    cout << "Argument of c1: " << c1.argument() << " radians" << endl;

    // Input and output using stream operators
    Complex c3;
    cout << "Enter a complex number:" << endl;
    cin >> c3;
    cout << "You entered: " << c3 << endl;

    return 0;
}
