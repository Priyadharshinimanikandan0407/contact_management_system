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
    int height;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct Node *n) {
    return (n == NULL) ? 0 : n->height;
}

struct Node* createNode(struct Contact c) {
    struct Node *node = malloc(sizeof(struct Node));

    node->data = c;
    node->left = node->right = NULL;
    node->height = 1;

    return node;
}

int getBalance(struct Node *n) {
    if (n == NULL)
        return 0;

    return height(n->left) - height(n->right);
}

struct Node* rightRotate(struct Node *y) {
    struct Node *x = y->left;
    struct Node *t2 = x->right;

    x->right = y;
    y->left = t2;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

struct Node* leftRotate(struct Node *x) {
    struct Node *y = x->right;
    struct Node *t2 = y->left;

    y->left = x;
    x->right = t2;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

struct Node* insert(struct Node *root, struct Contact c) {
    if (root == NULL)
        return createNode(c);

    if (c.id < root->data.id)
        root->left = insert(root->left, c);
    else if (c.id > root->data.id)
        root->right = insert(root->right, c);
    else {
        printf("Contact ID already exists!\n");
        return root;
    }

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    // LL Case
    if (balance > 1 && c.id < root->left->data.id)
        return rightRotate(root);

    // RR Case
    if (balance < -1 && c.id > root->right->data.id)
        return leftRotate(root);

    // LR Case
    if (balance > 1 && c.id > root->left->data.id) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL Case
    if (balance < -1 && c.id < root->right->data.id) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

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

int main() {
    struct Node *root = NULL;
    struct Contact c;
    int n, choice, key;

    printf("CONTACT MANAGEMENT SYSTEM - AVL TREE\n");

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
                printf("AVL Tree Height: %d\n", height(root));
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
