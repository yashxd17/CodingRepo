#include <stdio.h>
#include <stdlib.h>

// Structure for the nodes in the binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to perform postorder traversal and generate mirrored tree
struct Node* generateMirroredTree(struct Node* root) {
    if (root == NULL) {
        return NULL;
    }

    // Recursively generate mirrored subtrees
    struct Node* leftMirrored = generateMirroredTree(root->left);
    struct Node* rightMirrored = generateMirroredTree(root->right);

    // Swap left and right subtrees to create the mirrored tree
    root->left = rightMirrored;
    root->right = leftMirrored;

    return root;
}

// Function to construct a binary tree from user inputs
struct Node* constructBinaryTree() {
    int data;
    printf("Enter the data for the node (enter -1 for no node): ");
    scanf("%d", &data);

    if (data == -1) {
        return NULL;
    }

    struct Node* newNode = createNode(data);

    printf("Enter the left child of %d:\n", data);
    newNode->left = constructBinaryTree();

    printf("Enter the right child of %d:\n", data);
    newNode->right = constructBinaryTree();

    return newNode;
}

// Function to perform inorder traversal and print the tree nodes
void inorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }

    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// Driver program to test the mirrored tree generation
int main() {
    printf("Construct the binary tree:\n");
    struct Node* root = constructBinaryTree();

    printf("Original Tree (Inorder Traversal): ");
    inorderTraversal(root);
    printf("\n");

    struct Node* mirroredRoot = generateMirroredTree(root);

    printf("Mirrored Tree (Inorder Traversal): ");
    inorderTraversal(mirroredRoot);
    printf("\n");

    // Free the dynamically allocated memory for both trees
    // You can implement a separate function to free the memory for both trees.

    return 0;
}
