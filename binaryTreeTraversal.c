#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure for binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary tree
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

// Function to print the binary tree
void printBinaryTree(struct Node* root, int space) {
    // Base case
    if (root == NULL) {
        return;
    }

    // Increase the distance between levels
    int i;
    for (i = 0; i < space; i++) {
        printf(" ");
    }

    // Print the current node
    printf("%d\n", root->data);

    // Process the right child
    printBinaryTree(root->right, space + 4);

    // Process the left child
    printBinaryTree(root->left, space + 4);
}

void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    // Open the file in read mode to read the numbers
    FILE* readfile = fopen("random_number.txt", "r");

    if (readfile != NULL) {
        // Create an empty binary tree
        struct Node* root = NULL;
        int number;

        // Read numbers from the file and insert them into the binary tree
        while (fscanf(readfile, "%d", &number) != EOF) {
            root = insertNode(root, number);
        }

        // Close the file
        fclose(readfile);

        // Print the binary tree
        printf("Binary Tree:\n");
        printBinaryTree(root, 0);

        printf("\nInorder traversal: ");
        inorderTraversal(root);
        printf("\n");

        printf("Preorder traversal: ");
        preorderTraversal(root);
        printf("\n");

        printf("Postorder traversal: ");
        postorderTraversal(root);
        printf("\n");
    } else {
        printf("Error opening the random_number.txt file.\n");
        return 1;
    }

    return 0;
}
