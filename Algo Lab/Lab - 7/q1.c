#include <stdio.h>
#include <stdlib.h>

struct avl {
    int data;
    struct avl *left;
    struct avl *right;
    int height;
};

struct avl *nn(int key) {
    struct avl *node = (struct avl *)malloc(sizeof(struct avl));
    node->data = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

int height(struct avl *node) {
    if (node == NULL)
        return 0;
    return node->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

struct avl *rightRotate(struct avl *y) {
    struct avl *x = y->left;
    struct avl *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

struct avl *leftRotate(struct avl *x) {
    struct avl *y = x->right;
    struct avl *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int bal(struct avl *node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

struct avl *insertNode(struct avl *node, int key) {
    if (node == NULL)
        return nn(key);

    if (key < node->data)
        node->left = insertNode(node->left, key);
    else if (key > node->data)
        node->right = insertNode(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = bal(node);

    if (balance > 1 && key < node->left->data)
        return rightRotate(node);

    if (balance < -1 && key > node->right->data)
        return leftRotate(node);

    if (balance > 1 && key > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void preOrder(struct avl *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    struct avl *root = NULL;

    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);
    root = insertNode(root, 25);

    printf("Preorder traversal of AVL tree: ");
    preOrder(root);

    return 0;
}
