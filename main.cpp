#include "header.h"
#include <iostream>

using namespace std;

int main() {
    const int librarySize = 10;
    Book library[librarySize];

     for (int i = 0; i < librarySize; ++i) {
        cout << "Enter details for Book " << i + 1 << ":\n";
        cout << "Title: ";
        getline(cin, library[i].title);

        cout << "Author: ";
        getline(cin, library[i].author);

        cout << "Publisher: ";
        getline(cin, library[i].publisher);

        cout << "Enter genre (0-Fiction, 1-Non-Fiction, 2-Mystery, 3-Science Fiction, 4-Romance, 5-Horror): ";
        int genre;
        cin >> genre;
        cin.ignore();  
        library[i].genre = static_cast<Genre>(genre);

        cout << "\n";
    }

     int choice;
    do {
        cout << "\nLibrary Menu:\n";
        cout << "1. Edit a book\n";
        cout << "2. Print all books\n";
        cout << "3. Search by author\n";
        cout << "4. Search by title\n";
        cout << "5. Sort books by title\n";
        cout << "6. Sort books by author\n";
        cout << "7. Sort books by publisher\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  

        switch (choice) {
        case 1: {
            int bookIndex;
            cout << "Enter the index of the book to edit: ";
            cin >> bookIndex;
            cin.ignore(); 

            if (bookIndex >= 0 && bookIndex < librarySize) {
                editBook(library[bookIndex]);
                cout << "Book edited successfully.\n";
            }
            else {
                cout << "Invalid index.\n";
            }
            break;
        }
        case 2:
            printAllBooks(library, librarySize);
            break;
        case 3: {
            string author;
            cout << "Enter the author to search for: ";
            getline(cin, author);

            int index = searchByAuthor(library, librarySize, author);
            if (index != -1) {
                cout << "Book found at index " << index << ".\n";
            }
            else {
                cout << "Book not found.\n";
            }
            break;
        }
        case 4: {
            string title;
            cout << "Enter the title to search for: ";
            getline(cin, title);

            int index = searchByTitle(library, librarySize, title);
            if (index != -1) {
                cout << "Book found at index " << index << ".\n";
            }
            else {
                cout << "Book not found.\n";
            }
            break;
        }
        case 5:
            sortBooksByTitle(library, librarySize);
            cout << "Books sorted by title.\n";
            break;
        case 6:
            sortBooksByAuthor(library, librarySize);
            cout << "Books sorted by author.\n";
            break;
        case 7:
            sortBooksByPublisher(library, librarySize);
            cout << "Books sorted by publisher.\n";
            break;
        case 0:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 0);

    return 0;
}
