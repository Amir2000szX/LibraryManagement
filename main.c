#include <stdio.h>
#include <stdlib.h>
#include "Node.h"
#include "BST.h"
#include "CToJson.h"

int main() {
    Book books[10] = {
        {9783161484100ULL, "The Great Gatsby", "F. Scott Fitzgerald", 1925},
        {9780451524935ULL, "1984", "George Orwell", 1949},
        {9780743273565ULL, "To Kill a Mockingbird", "Harper Lee", 1960},
        {9780141182803ULL, "Brave New World", "Aldous Huxley", 1932},
        {9780679734529ULL, "One Hundred Years of Solitude", "Gabriel Garcia Marquez", 1967},
        {9780307277671ULL, "The Road", "Cormac McCarthy", 2006},
        {9780553382563ULL, "Dune", "Frank Herbert", 1965},
        {9780374533557ULL, "The Catcher in the Rye", "J.D. Salinger", 1951},
        {9780061120084ULL, "Fahrenheit 451", "Ray Bradbury", 1953},
        {9780316769488ULL, "The Bell Jar", "Sylvia Plath", 1963}
    };
    Node* root = (Node*)malloc(sizeof(Node));
    Node* rootNode = makeNode(&books[0], root);

    for (int i = 1; i < 10; i++) {
        insert(&books[i], root);
    }
    saveJson(root);
}
