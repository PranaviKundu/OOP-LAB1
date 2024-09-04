// Develop a program in C++ to create a database of student’s information system containing the
// following information: Name, Roll number, Class, Division, Date of Birth, Blood group, Contact
// address, Telephone number, Driving license no. and other. Construct the database with
// suitable member functions. Make use of constructor, default constructor, copy constructor,
// destructor, static member functions, friend class, this pointer, inline code and dynamic
// memory allocation operators-new and delete as well as exception handling.

#include <iostream>//input-output stream library for handling standard input and output.
#include <string>//standard string class for using std::string
#include <stdexcept>//Provides standard exception classes like std::out_of_range and std::runtime_error.
using namespace std;//Allows usage of standard library objects and functions without prefixing std::

class Student; // Forward declaration of Student class for friend class usage

class StudentDatabase {
private:
    Student** students; // Pointer to an array of pointers to Student objects
    int numStudents;    // Number of students in the database
    static int totalStudents; // Static member to keep track of total students across all databases
                            // Static member belongs to the class and not t anyone instance of the class, it is initialised only once, member can be a variable or method 
public:
    // Default constructor
    StudentDatabase() : students(nullptr), numStudents(0) { //default constructor initializes students to nullptr and numStudent to 0
        cout << "StudentDatabase created." << endl;         //nullptr is a way to represent a pointer that doesn't point to any object or memory location. we can also use 0 or NULL for the same purpose. It is used in a context where a pointer is expected 
    }

    // Parameterized constructor
    StudentDatabase(int num) : numStudents(num) {  // studentDatabase is a constructor for the studentdatabase class that takes an integer num as an argument, represents number of student slot the database will have. The initializer list : numStudents(num) assigns the value of num (the parameter) to the member variable numStudents.
        students = new Student*[numStudents];  //Here, the constructor allocates memory dynamically for an array of pointers to Student objects. creates an array of Student* pointers with numStudents slots. Each slot in this array is meant to hold a pointer to a Student object.students is a pointer to this array of Student* pointers. Initially, all elements in this array are uninitialized and may contain garbage values.
        new Student*[numStudents];
        for (int i = 0; i < numStudents; ++i) {
            students[i] = nullptr; // Initialize pointers to nullptr
        }
        cout << "StudentDatabase created with " << numStudents << " slots." << endl;
    }

    // Copy constructor
    StudentDatabase(const StudentDatabase& other) : numStudents(other.numStudents) {  
        // takes a constant reference to another StudentDatabase object (other) as its parameter.
        //numStudents(other.numStudents) part initializes the numStudents member variable of the new object with the value of numStudents from the other object.
        students = new Student*[numStudents];//This line allocates memory for an array of pointers to Student objects. This creates a new students array in the new StudentDatabase object with the same size as the students array in the other object. Each element in this array is a pointer to a Student.
        for (int i = 0; i < numStudents; ++i) {
            students[i] = other.students[i] ? new Student(*other.students[i]) : nullptr;
            //other.students[i]: Checks if the pointer at index i in the other database is not nullptr. If it points to a Student object, it performs a deep copy.
            //new Student(*other.students[i]): Creates a new Student object in the students array of the new StudentDatabase by calling the copy constructor of the Student class, which makes a copy of the Student pointed to by other.students[i].
            //: nullptr: If the pointer in other.students[i] is nullptr, it sets the corresponding pointer in the new students array to nullptr.
        }
        cout << "StudentDatabase copied." << endl;
    }

    // Destructor
    ~StudentDatabase() {//The ~ symbol before the class name indicates that this is a destructor. It does not take any parameters and does not return any value.
        for (int i = 0; i < numStudents; ++i) {
            delete students[i]; // Free each student's memory
            //This line frees the memory allocated for each Student object pointed to by students[i]. This is crucial to prevent memory leaks by ensuring that each dynamically allocated Student is properly deallocated.
        }
        delete[] students; // Free the array of student pointers
        //This line frees the memory allocated for the array of Student* pointers itself. The array was created using new Student*[numStudents] in the constructor, and it must be deallocated using delete[] to avoid memory leaks.
        cout << "StudentDatabase destroyed." << endl;
    }

    // Static member function
    static int getTotalStudents() {
        //This line declares a static member function named getTotalStudents that returns an int. The static keyword indicates that this function is associated with the class itself rather than with any individual object of the class.
        return totalStudents;
    }

    // Method to add a student
    void addStudent(int index, const string& name, int rollNo, const string& className, const string& division,
                    const string& dob, const string& bloodGroup, const string& contactAddress, 
                    const string& phoneNumber, const string& drivingLicenseNo) {//These parameters hold the details of the student to be added.
        if (index < 0 || index >= numStudents) {
            throw out_of_range("Index out of range.");//If the index is out of range, an out_of_range exception is thrown with the message "Index out of range.". This helps prevent invalid array access and keeps the program from crashing.
        }
        if (students[index] != nullptr) {//students[index] != nullptr: If this condition is true, it means that there is already a Student object at that position in the students array.
                                         // If a student already exists at the given index, a runtime_error exception is thrown with the message "Student already exists at this index.". This prevents overwriting an existing student entry.
            throw runtime_error("Student already exists at this index.");
        }
        students[index] = new Student(name, rollNo, className, division, dob, bloodGroup, contactAddress, phoneNumber, drivingLicenseNo);
        ++totalStudents;//This line dynamically allocates memory for a new Student object using the provided parameters and assigns the newly created Student object to the specified index in the students array.
        //new Student(...): Calls the parameterized constructor of the Student class to initialize the new Student object with the provided details.
        //students[index]: The Student* at the given index is set to point to the newly allocated Student object.
    }

    // Friend class declaration
    friend class Student;

    // Inline function to print database
    inline void printDatabase() const {
        for (int i = 0; i < numStudents; ++i) {
            if (students[i] != nullptr) {
                students[i]->printDetails();
            }
        }
    }
};

// Static member initialization
int StudentDatabase::totalStudents = 0;

class Student {
private:
    string name;
    int rollNo;
    string className;
    string division;
    string dob;
    string bloodGroup;
    string contactAddress;
    string phoneNumber;
    string drivingLicenseNo;

public:
    // Default constructor
    Student() : name("Unknown"), rollNo(0), className("Unknown"), division("Unknown"),
                dob("Unknown"), bloodGroup("Unknown"), contactAddress("Unknown"),
                phoneNumber("Unknown"), drivingLicenseNo("Unknown") {}

    // Parameterized constructor
    Student(const string& name, int rollNo, const string& className, const string& division,
            const string& dob, const string& bloodGroup, const string& contactAddress,
            const string& phoneNumber, const string& drivingLicenseNo)
        : name(name), rollNo(rollNo), className(className), division(division),
          dob(dob), bloodGroup(bloodGroup), contactAddress(contactAddress),
          phoneNumber(phoneNumber), drivingLicenseNo(drivingLicenseNo) {}

    // Copy constructor
    Student(const Student& other)
        : name(other.name), rollNo(other.rollNo), className(other.className), division(other.division),
          dob(other.dob), bloodGroup(other.bloodGroup), contactAddress(other.contactAddress),
          phoneNumber(other.phoneNumber), drivingLicenseNo(other.drivingLicenseNo) {}

    // Destructor
    ~Student() {
        // Destructor doesn't need to explicitly release memory as no dynamic memory is allocated within Student
        cout << "Student " << name << " destroyed." << endl;
    }

    // Method to print student details
    void printDetails() const {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNo << endl;
        cout << "Class: " << className << endl;
        cout << "Division: " << division << endl;
        cout << "Date of Birth: " << dob << endl;
        cout << "Blood Group: " << bloodGroup << endl;
        cout << "Contact Address: " << contactAddress << endl;
        cout << "Telephone Number: " << phoneNumber << endl;
        cout << "Driving License No: " << drivingLicenseNo << endl;
        cout << "------------------------" << endl;
    }

    // Friend class declaration
    friend class StudentDatabase;
};

int main() {
    try {
        // Create a StudentDatabase with 3 slots
        StudentDatabase db(3);

        // Add students
        db.addStudent(0, "John Doe", 101, "10th", "A", "01/01/2006", "O+", "123 Elm St", "555-1234", "D1234567");
        db.addStudent(1, "Jane Smith", 102, "10th", "B", "02/02/2006", "A-", "456 Oak St", "555-5678", "D2345678");

        // Print database
        db.printDatabase();

        // Attempt to add a student at an invalid index
        db.addStudent(3, "Invalid Student", 103, "10th", "C", "03/03/2006", "B+", "789 Pine St", "555-9012", "D3456789");
    } catch (const exception& e) {
        cout << "Exception: " << e.what() << endl;
    }

    cout << "Total students in all databases: " << StudentDatabase::getTotalStudents() << endl;

    return 0;
}
