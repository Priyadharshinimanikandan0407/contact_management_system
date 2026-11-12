#include <stdio.h>

#define SIZE 101

struct Contact {
    int id;
    char name[50];
    char phone[15];
    char email[50];
    int occupied;
};

struct Contact hashTable[SIZE];
int totalCollisions = 0;

int hashFunction(int key) {
    return key % SIZE;
}

void insert() {
    struct Contact c;
    int index, start;

    printf("\nEnter Contact ID: ");
    scanf("%d", &c.id);

    printf("Enter Name: ");
    scanf(" %49[^\n]", c.name);

    printf("Enter Phone Number: ");
    scanf("%14s", c.phone);

    printf("Enter Email: ");
    scanf("%49s", c.email);

    index = hashFunction(c.id);
    start = index;

    while (hashTable[index].occupied) {

        if (hashTable[index].id == c.id) {
            printf("Contact ID already exists!\n");
            return;
        }

        totalCollisions++;
        index = (index + 1) % SIZE;

        if (index == start) {
            printf("Hash Table is Full!\n");
            return;
        }
    }

    c.occupied = 1;
    hashTable[index] = c;

    printf("Contact Inserted Successfully!\n");
    printf("Stored at Index: %d\n", index);
}

void search() {
    int key, index, start;
    int comparisons = 0;

    printf("\nEnter Contact ID to search: ");
    scanf("%d", &key);

    index = hashFunction(key);
    start = index;

    while (hashTable[index].occupied) {
        comparisons++;

        if (hashTable[index].id == key) {
            printf("\nContact Found!\n");
            printf("ID: %d\n", hashTable[index].id);
            printf("Name: %s\n", hashTable[index].name);
            printf("Phone: %s\n", hashTable[index].phone);
            printf("Email: %s\n", hashTable[index].email);
            printf("Comparisons: %d\n", comparisons);
            return;
        }

        index = (index + 1) % SIZE;

        if (index == start)
            break;
    }

    printf("Contact Not Found!\n");
    printf("Comparisons: %d\n", comparisons);
}

void display() {
    int i;

    printf("\nID        Name                 Phone           Email\n");

    for (i = 0; i < SIZE; i++) {
        if (hashTable[i].occupied) {
            printf("%-10d %-20s %-15s %-25s\n",
                   hashTable[i].id,
                   hashTable[i].name,
                   hashTable[i].phone,
                   hashTable[i].email);
        }
    }
}

int main() {
    int choice, n, i;

    printf("CONTACT MANAGEMENT SYSTEM - HASHING\n");

    for (i = 0; i < SIZE; i++)
        hashTable[i].occupied = 0;

    printf("Enter number of contacts: ");
    scanf("%d", &n);

    if (n < 0 || n > SIZE) {
        printf("Invalid number of contacts!\n");
        return 0;
    }

    for (i = 0; i < n; i++) {
        printf("\nContact %d\n", i + 1);
        insert();
    }

    do {
        printf("\n1. Insert Contact");
        printf("\n2. Search Contact");
        printf("\n3. Display Contacts");
        printf("\n4. Display Total Collisions");
        printf("\n5. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;

            case 2:
                search();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Total Collisions: %d\n",
                       totalCollisions);
                break;

            case 5:
                printf("Program Ended.\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }
    } while (choice != 5);

    return 0;
}
