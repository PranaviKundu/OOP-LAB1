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

    // Getter methods
    double getReal() const { return real; }
    double getImag() const { return imag; }
     // // getReal() and getImag(): Public methods to access the private members real and imag, respectively. These methods allow read-only access to the internal state of a Complex object.

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
    

      // Overload - operator to subtract two complex numbers
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

     Complex operator/(const Complex& other) const {
        // (a + bi) / (c + di) = ((a + bi) * (c - di)) / (c^2 + d^2)
        double denominator = other.real * other.real + other.imag * other.imag;
        double result_real = (real * other.real + imag * other.imag) / denominator;
        double result_imag = (imag * other.real - real * other.imag) / denominator;
        return Complex(result_real, result_imag);
    }
    
    Complex operator * (const Complex& other) const {
        // operator*:multiply two complex numbers using formula:
        // (a+bi)×(c+di)=(ac−bd)+(ad+bc)i
        double r = real * other.real - imaginary * other.imaginary;
        double i = real * other.imaginary + imaginary * other.real;
        return Complex(r, i);
    }
      // Member function to find argument (angle) of the complex number
    double argument() const {
        return std::atan2(imag, real);
    }
    // // // // // Here we have commented the friends function to write a coade without it
    // // (Stream insertion and extraction operators)
    // friend ostream& operator << (ostream& out, const Complex& c) {
    //     // (& used to creat a referance of a variable)
    //     // (const specifies that the object is qualfied to not modifiable. ensures that the value of the object can  not be changed though this referance.)
    //     out << c.real << " + " << c.imaginary << "i";
    //     return out;
    // }

    // friend istream& operator >> (istream& in, Complex& c) {
    //     // const Complex& is used to ensure that a function can acces the object efficiently without allowing unintended modification  
    //     // friend function is a function that is not a member of a class but has access to the private and protected members of the class if it is declared as a friend within that class.

    //     cout << "Enter real part: ";
    //     in >> c.real;
    //     cout << "Enter imaginary part: ";
    //     in >> c.imaginary;
    //     return in;
    // }
     std::ostream& print(std::ostream& os) const {
        os << real << " + " << imag << "i";
        return os;
    }
    // 'os stands for an output stream, which is a type of stream in C++ used for output operations. The std::ostream class is a part of the C++ Standard Library 
    //and is used for outputting data to various destinations, such as the console, files, or other output devices.
    //return os;: This returns the output stream os by reference, which allows for chaining of output operations.


    // Overload >> operator to read Complex numbers
    std::istream& read(std::istream& is) {
        std::cout << "Enter real part: ";
        is >> real;
        std::cout << "Enter imaginary part: ";
        is >> imag;
        return is;
    }
    // // // read(): Member function that reads a complex number from a given input stream (is). 

    // Overload << operator to print Complex numbers
    // It calls the print() member function of the Complex object, passing the output stream os to format and output the complex number.
    std::ostream& operator<<(std::ostream& os, const Complex& complex) {
        return complex.print(os);
    }

     // Overload - operator to subtract two complex numbers
    Complex operator-(const Complex& lhs, const Complex& rhs) {
        return Complex(lhs.getReal() - rhs.getReal(), lhs.getImag() - rhs.getImag());
    }
//In the context of the Complex class and the provided operator- function, getReal and getImag are member functions that are
//used to access the internal state of a Complex object. Their significance is primarily related to encapsulation and ease of access to the properties of the Complex class.
//lhs.getReal() - rhs.getReal(): This expression computes the difference between the real parts of the two Complex objects.
//It calls the getReal() member function of both lhs (left-hand side) and rhs (right-hand side) to get their real parts and subtracts them.

    // Overload >> operator to read Complex numbers
    std::istream& operator>>(std::istream& is, Complex& complex) {
        return complex.read(is);
    }
    // Overload / operator to divide two complex numbers
    Complex operator/(const Complex& lhs, const Complex& rhs) {
        // Calculate the division using member function
        return lhs / rhs;
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
    std::cout << "Difference: " << diff << std::endl;

    // Multiplication
    Complex product = c1 * c2;
    std::cout << "Product: " << product << std::endl;

    // Division
    Complex quotient = c1 / c2;
    std::cout << "Quotient: " << quotient << std::endl;

      // Argument
    std::cout << "Argument of c1: " << c1.argument() << " radians" << std::endl;
    
    // Input and output using stream operators
    Complex c3;
    cout << "Enter a complex number:" << endl;
    cin >> c3;
    cout << "You entered: " << c3 << endl;

    return 0;
}
