#include <iostream>
#include <string>
#include "Member.h"

// Name:         Aloysius X. Student
// Program:      CSC 275 Program 1
// Due Date:     09/32/24
// Compiler:     (whatever one you used.)
// This program simulates a library system through...

int main() {
    // Create four Book objects
    Book book1("Absolute C++", "Walter Savitch", "978-0-13-397078-4");
    Book book2("Effective Java", "Joshua Bloch", "978-0-13-468599-1");
    Book book3("Clean Code", "Robert C. Martin", "978-0-13-235088-4");
    Book book4("Design Patterns", "Erich Gamma", "978-0-201-63361-0");

    // Store books in an array
    Book library[4] = {book1, book2, book3, book4};

    // Create a Member object
    Member member("Xavier", "Charleston", "12345678");

    string command;
    while (true) {
        cout << "Enter command (borrow, return, account, newbook, member, quit): ";
        cin >> command;

        if (command == "borrow") {
            string isbn;
            cout << "Enter ISBN to borrow: ";
            cin >> isbn;
            bool found = false;
            for (int i = 0; i < 4; i++) {
                if (library[i].getISBN() == isbn) {
                    member.borrowBook(library[i]);
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Book not found in the library." << endl;
            }

        } else if (command == "return") {
            string isbn;
            cout << "Enter ISBN to return: ";
            cin >> isbn;
            member.returnBook(isbn);

        } else if (command == "account") {
            cout << member << endl;

        } else if (command == "newbook") {
            string title, author, isbn;
            cout << "Enter title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter author: ";
            getline(cin, author);
            cout << "Enter ISBN: ";
            cin >> isbn;
            Book newBook(title, author, isbn);
            // Add newBook to library logic
            // (since the library is static, this would be handled differently in a more complete implementation)

        } else if (command == "member") {
            string fname, lname;
            cout << "First name: ";
            cin >> fname;
            cout << "Last name: ";
            cin >> lname;
            member.new_fname(fname);
            member.new_lname(lname);

        } else if (command == "quit") {
            break;

        } else {
            cout << "Invalid command." << endl;
        }
    }

    return 0;
}
