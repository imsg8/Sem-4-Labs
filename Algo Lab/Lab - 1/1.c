/*Write a program to construct a binary tree to support the following operations.
Assume no duplicate elements while constructing the tree.
i. Given a key, perform a search in the binary search tree. If the key is found
then display “key found” else insert the key in the binary search tree.
ii. Display the tree using inorder, preorder and post order traversal methods*/

#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    struct Node* left;
    int data;
    struct Node* right;
} node;

node* createnode(int x) {
    node* newnode = (node*) malloc(sizeof(node));
    newnode->data = x;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void preorder(node* start) {
    if (start != NULL) {
        printf("%d ", start->data);
        preorder(start->left);
        preorder(start->right);
    }
}

void postorder(node* start) {
    if (start != NULL) {
        postorder(start->left);
        postorder(start->right);
        printf("%d ", start->data);
    }
}

void inorder(node* start) {
    if (start != NULL) {
        inorder(start->left);
        printf("%d ", start->data);
        inorder(start->right);
    }
}

void insert(node** start, int x) {
    node* newnode = createnode(x);
    node* iterator = *start;
    node* previous = NULL;

    while (iterator != NULL) {
        previous = iterator;
        if (iterator->data > x) {
            iterator = iterator->left;
        } else if (iterator->data == x) {
            printf("Duplicate found!\n");
            return;
        } else {
            iterator = iterator->right;
        }
    }

    if (previous == NULL) {
        *start = newnode;
    } else if (x < previous->data) {
        previous->left = newnode;
    } else {
        previous->right = newnode;
    }
}

int main() {
    printf("Enter BST element and type -1 to exit.\n");
    int x;
    node* start = NULL;

    do {
        printf("Enter element: ");
        scanf("%d", &x);
        if (x < 0)
            break;
        insert(&start, x);
    } while (x != -1);

    printf("\nPreOrder: ");
    preorder(start);
    printf("\nInOrder: ");
    inorder(start);
    printf("\nPostOrder: ");
    postorder(start);

    return 0;
}
