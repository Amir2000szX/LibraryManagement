#ifndef BOOK_H
#define BOOK_H

typedef struct Book {
    unsigned long long int ISBN;
    char Title[100];
    char Author[100];
    unsigned short int Year;
} Book;

extern Book* makeBook(unsigned long long int ISBN, char Title[], char Author[], unsigned short int Year);

#endif // BOOK_H