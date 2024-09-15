#include <iostream>
#include <string>
#include "Book.h"

const int MAX_BOOKS = 50;

class Member {
private:
    string first_name;
    string last_name;
    string ID;
    Book borrowedBooks[MAX_BOOKS];
    int borrowedCount;

public:
    // Default constructor
    Member() : first_name(""), last_name(""), ID(""), borrowedCount(0) {}

    // Parameterized constructor
    Member(string fname, string lname, string id)
        : first_name(fname), last_name(lname), ID(id), borrowedCount(0) {}

    // Destructor
    ~Member() {}

    // Method to borrow a book
    void borrowBook(const Book& book) {
        if (borrowedCount < MAX_BOOKS) {
            borrowedBooks[borrowedCount++] = book;
            cout << "Book borrowed successfully!" << endl;
        } else {
            cout << "Cannot borrow more books. Maximum limit reached." << endl;
        }
    }

    // Method to return a book by ISBN
    void returnBook(const string& isbn) {
        for (int i = 0; i < borrowedCount; i++) {
            if (borrowedBooks[i].getISBN() == isbn) {
                borrowedBooks[i] = borrowedBooks[--borrowedCount];
                cout << "Book returned successfully!" << endl;
                return;
            }
        }
        cout << "Book not found in the borrowed list." << endl;
    }

    // List all borrowed books
    void listBorrowedBooks() const {
        if (borrowedCount == 0) {
            cout << "No books borrowed." << endl;
        } else {
            for (int i = 0; i < borrowedCount; i++) {
                cout << borrowedBooks[i] << endl;
            }
        }
    }

    // Update last name
    void new_lname(const string& lname) {
        last_name = lname;
    }

    // Update first name
    void new_fname(const string& fname) {
        first_name = fname;
    }

    // Overloaded << operator for output
    friend ostream& operator<<(ostream& os, const Member& member) {
        os << member.first_name << " " << member.last_name << " (ID: " << member.ID << ") has borrowed the following books:" << endl;
        for (int i = 0; i < member.borrowedCount; i++) {
            os << "  " << member.borrowedBooks[i] << endl;
        }
        return os;
    }
};
