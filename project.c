#include <stdio.h>

#define MAX_BOOKS 100
#define MAX_BORROWED 100

// Arrays to store information
int bookIDs[MAX_BOOKS];
char bookTitles[MAX_BOOKS][50];
char bookAuthors[MAX_BOOKS][50];
int isBorrowed[MAX_BOOKS]; // 0 = available, 1 = borrowed
int studentIDs[MAX_BORROWED];
int borrowedBookIDs[MAX_BORROWED];
int bookCount = 0;
int borrowedCount = 0;

// Function to add a new book
void addBook() {
    if (bookCount < MAX_BOOKS) {
        printf("Enter Book ID: ");
        scanf("%d", &bookIDs[bookCount]);

        printf("Enter Book Title: ");
        scanf(" %[^\n]s", bookTitles[bookCount]);  // Reads string with spaces

        printf("Enter Book Author: ");
        scanf(" %[^\n]s", bookAuthors[bookCount]);

        isBorrowed[bookCount] = 0;  // Mark book as available
        bookCount++;
        
        printf("Book Added Successfully.\n");
    } else {
        printf("Library is full, cannot add more books.\n");
    }
}

// Function to borrow a book
void borrowBook() {
    int studentID, bookID, found = -1;

    printf("Enter Student ID: ");
    scanf("%d", &studentID);

    printf("Enter Book ID: ");
    scanf("%d", &bookID);

    for (int i = 0; i < bookCount; i++) {
        if (bookIDs[i] == bookID && isBorrowed[i] == 0) {
            found = i;
            break;
        }
    }

    if (found != -1) {
        isBorrowed[found] = 1;  // Mark as borrowed
        studentIDs[borrowedCount] = studentID;
        borrowedBookIDs[borrowedCount] = bookID;
        borrowedCount++;
        printf("Book Borrowed Successfully by Student %d.\n", studentID);
    } else {
        printf("Book is not available or doesn't exist.\n");
    }
}

// Function to return a borrowed book
void returnBook() {
    int studentID, bookID, daysLate, found = -1, fine = 0;

    printf("Enter Student ID: ");
    scanf("%d", &studentID);

    printf("Enter Book ID: ");
    scanf("%d", &bookID);

    printf("Enter Number of Days Late: ");
    scanf("%d", &daysLate);

    // Calculate fine if any days late
    if (daysLate > 0) {
        fine = daysLate * 10;
        printf("Fine of Rs. %d Applied.\n", fine);
    }

    for (int i = 0; i < bookCount; i++) {
        if (bookIDs[i] == bookID && isBorrowed[i] == 1) {
            isBorrowed[i] = 0;  // Mark as returned
            printf("Book Returned Successfully.\n");
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("Error: Book was not borrowed or does not exist.\n");
    }
}





int main() {
	int choice;
    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Borrow Book\n");
        printf("3. Return Book\n");
        printf("4. EXIt\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: borrowBook(); break;
            case 3: returnBook(); break;
            case 4 :return 0; break;
            default: printf("Invalid choice. Please try again.\n");
        }
    }
}

