#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>

enum Genre {
    FICTION,
    NON_FICTION,
    MYSTERY,
    SCIENCE_FICTION,
    ROMANCE,
    HORROR
};

struct Book {
    std::string title;
    std::string author;
    std::string publisher;
    Genre genre;
};

void editBook(Book& book);
void printAllBooks(const Book books[], int size);
int searchByAuthor(const Book books[], int size, const std::string& author);
int searchByTitle(const Book books[], int size, const std::string& title);
void sortBooksByTitle(Book books[], int size);
void sortBooksByAuthor(Book books[], int size);
void sortBooksByPublisher(Book books[], int size);

#endif // LIBRARY_H

