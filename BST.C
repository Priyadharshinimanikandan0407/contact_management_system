#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact {
    int id;
    char name[50];
    char phone[15];
    char email[50];
};

struct Node {
    struct Contact data;
    struct Node *left, *right;
};

struct Node* createNode(struct Contact c) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = c;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node *root, struct Contact c) {
    if (root == NULL)
        return createNode(c);

    if (c.id < root->data.id)
        root->left = insert(root->left, c);
    else if (c.id > root->data.id)
        root->right = insert(root->right, c);
    else
        printf("Contact ID already exists!\n");

    return root;
}

void search(struct Node *root, int key) {
    int comparisons = 0;

    while (root != NULL) {
        comparisons++;

        if (key == root->data.id) {
            printf("\nContact Found!\n");
            printf("ID: %d\n", root->data.id);
            printf("Name: %s\n", root->data.name);
            printf("Phone: %s\n", root->data.phone);
            printf("Email: %s\n", root->data.email);
            printf("Comparisons: %d\n", comparisons);
            return;
        }

        if (key < root->data.id)
            root = root->left;
        else
            root = root->right;
    }

    printf("Contact Not Found!\n");
    printf("Comparisons: %d\n", comparisons);
}

void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);

        printf("%-10d %-20s %-15s %-25s\n",
               root->data.id,
               root->data.name,
               root->data.phone,
               root->data.email);

        inorder(root->right);
    }
}

int height(struct Node *root) {
    if (root == NULL)
        return 0;

    int l = height(root->left);
    int r = height(root->right);

    return 1 + (l > r ? l : r);
}

int main() {
    struct Node *root = NULL;
    struct Contact c;
    int n, choice, key;

    printf("CONTACT MANAGEMENT SYSTEM - BST\n");

    printf("Enter number of contacts: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nEnter Contact ID: ");
        scanf("%d", &c.id);

        printf("Enter Name: ");
        scanf(" %49[^\n]", c.name);

        printf("Enter Phone Number: ");
        scanf("%14s", c.phone);

        printf("Enter Email: ");
        scanf("%49s", c.email);

        root = insert(root, c);
    }

    do {
        printf("\n1. Insert Contact");
        printf("\n2. Search Contact");
        printf("\n3. Display Contacts");
        printf("\n4. Display Tree Height");
        printf("\n5. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Contact ID: ");
                scanf("%d", &c.id);

                printf("Enter Name: ");
                scanf(" %49[^\n]", c.name);

                printf("Enter Phone: ");
                scanf("%14s", c.phone);

                printf("Enter Email: ");
                scanf("%49s", c.email);

                root = insert(root, c);
                break;

            case 2:
                printf("Enter Contact ID to search: ");
                scanf("%d", &key);
                search(root, key);
                break;

            case 3:
                printf("\nID        Name                 Phone           Email\n");
                inorder(root);
                break;

            case 4:
                printf("BST Height: %d\n", height(root));
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
