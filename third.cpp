#include <iostream>
#include <string>
using namespace std;

// Base class Publication
class Publication {
protected:
    string title;
    float price;
public:
    void getData() {
        cout << "Enter title: ";
        cin.ignore(); // Clear the input buffer before getline
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
        if (price < 0) throw invalid_argument("Invalid price");
    }
    void displayData() const {
        cout << "Title: " << title << "\nPrice: $" << price << endl;
    }
};

// Derived class Book
class Book : public Publication {
    int pageCount;
public:
    void getData() {
        Publication::getData();
        cout << "Enter page count: ";
        cin >> pageCount;
        if (pageCount < 0) throw invalid_argument("Invalid page count");
    }
    void displayData() const {
        Publication::displayData();
        cout << "Page Count: " << pageCount << endl;
    }
};

// Derived class Tape
class Tape : public Publication {
    float playTime;
public:
    void getData() {
        Publication::getData();
        cout << "Enter play time (minutes): ";
        cin >> playTime;
        if (playTime < 0) throw invalid_argument("Invalid play time");
    }
    void displayData() const {
        Publication::displayData();
        cout << "Play Time: " << playTime << " minutes" << endl;
    }
};

int main() {
    Book book;
    Tape tape;

    try {
        cout << "Enter data for the book:\n";
        book.getData();
    } catch (...) {
        book = Book(); // Reset to default
        cout << "Invalid input. Resetting book data.\n";
    }

    try {
        cout << "Enter data for the tape:\n";
        tape.getData();
    } catch (...) {
        tape = Tape(); // Reset to default
        cout << "Invalid input. Resetting tape data.\n";
    }

    cout << "\nBook Details:\n";
    book.displayData();

    cout << "\nTape Details:\n";
    tape.displayData();

    return 0;
}
