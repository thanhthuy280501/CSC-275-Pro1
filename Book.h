#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    string ISBN;

public:
    // Default constructor
    Book() : title(""), author(""), ISBN("") {}                                 //Implement a default constructor.

    // Parameterized constructor
    Book(string t, string a, string i) : title(t), author(a), ISBN(i) {}        //Parameterized constructor that initializes all attributes.

    // Destructor
    ~Book() {}

    // Overloaded == operator to compare ISBNs                                  //Overload the == and != operators to compare books based on their ISBN
    bool operator==(const Book& other) const {
        return this->ISBN == other.ISBN;
    }

    // Overloaded != operator to compare ISBNs
    bool operator!=(const Book& other) const {
        return this->ISBN != other.ISBN;
    }

    // Overloaded << operator for output
    friend ostream& operator<<(ostream& os, const Book& book) {
        os << book.title << ", by " << book.author << ", ISBN: " << book.ISBN;
        return os;
    }

    // Accessor methods
    string getISBN() const {
        return ISBN;
    }

    string getTitle() const {
        return title;
    }
};
