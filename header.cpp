#include "header.h"
#include <iostream>
#include <algorithm>

using namespace std;

void editBook(Book& book) {
    cout << "Enter new title: ";
    getline(cin, book.title);

    cout << "Enter new author: ";
    getline(cin, book.author);

    cout << "Enter new publisher: ";
    getline(cin, book.publisher);

    cout << "Enter new genre (0-Fiction, 1-Non-Fiction, 2-Mystery, 3-Science Fiction, 4-Romance, 5-Horror): ";
    int genre;
    cin >> genre;
    cin.ignore();  
    book.genre = static_cast<Genre>(genre);
}

void printAllBooks(const Book books[], int size) {
    cout << "Library Catalog:\n";
    for (int i = 0; i < size; ++i) {
        cout << "Book " << i + 1 << ":\n";
        cout << "Title: " << books[i].title << "\n";
        cout << "Author: " << books[i].author << "\n";
        cout << "Publisher: " << books[i].publisher << "\n";
        cout << "Genre: " << books[i].genre << "\n\n";
    }
}

int searchByAuthor(const Book books[], int size, const string& author) {
    for (int i = 0; i < size; ++i) {
        if (books[i].author == author) {
            return i;
        }
    }
    return -1;
}

int searchByTitle(const Book books[], int size, const string& title) {
    for (int i = 0; i < size; ++i) {
        if (books[i].title == title) {
            return i;
        }
    }
    return -1;
}

void sortBooksByTitle(Book books[], int size) {
    sort(books, books + size, [](const Book& a, const Book& b) {
        return a.title < b.title;
        });
}

void sortBooksByAuthor(Book books[], int size) {
    sort(books, books + size, [](const Book& a, const Book& b) {
        return a.author < b.author;
        });
}

void sortBooksByPublisher(Book books[], int size) {
    sort(books, books + size, [](const Book& a, const Book& b) {
        return a.publisher < b.publisher;
        });
}
