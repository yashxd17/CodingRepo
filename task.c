#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure representing a task
typedef struct {
    char* name;
    int priority;
    // Add other task attributes as needed
} Task;

// Structure representing an AVL tree node
typedef struct Node {
    Task data;
    struct Node* left;
    struct Node* right;
    int height;
} Node;

// Function to calculate the height of a node
int getHeight(Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Function to calculate the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to create a new AVL tree node
Node* createNode(Task data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

// Function to perform a right rotation
Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

// Function to perform a left rotation
Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

// Function to get the balance factor of a node
int getBalance(Node* node) {
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// Function to insert a new node into the AVL tree
Node* insert(Node* node, Task data) {
    // Perform the standard BST insertion
    if (node == NULL)
        return createNode(data);

    if (data.priority < node->data.priority)
        node->left = insert(node->left, data);
    else if (data.priority > node->data.priority)
        node->right = insert(node->right, data);
    else
        return node;  // Duplicate priorities are not allowed

    // Update the height of the current node
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // Check the balance factor and perform rotations if necessary
    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && data.priority < node->left->data.priority)
        return rotateRight(node);

    // Right Right Case
    if (balance < -1 && data.priority > node->right->data.priority)
        return rotateLeft(node);

    // Left Right Case
    if (balance > 1 && data.priority > node->left->data.priority) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Right Left Case
    if (balance < -1 && data.priority < node->right->data.priority) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

// Function to perform an in-order traversal of the AVL tree
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("Task Name: %s, Priority: %d\n", root->data.name, root->data.priority);
        inorderTraversal(root->right);
    }
}

// Function to print the AVL tree structure
void printTree(Node* root, int space) {
    if (root == NULL)
        return;

    // Increase distance between levels
    space += 10;

    // Process right child first
    printTree(root->right, space);

    // Print current node after space
    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%s\n", root->data.name);

    // Process left child
    printTree(root->left, space);
}

// Function to find the node with the minimum value in a tree
Node* findMinNode(Node* node) {
    Node* current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

// Function to delete a node from the AVL tree
Node* deleteNode(Node* root, int priority) {
    if (root == NULL)
        return root;

    // Perform standard BST delete
    if (priority < root->data.priority)
        root->left = deleteNode(root->left, priority);
    else if (priority > root->data.priority)
        root->right = deleteNode(root->right, priority);
    else {
        // Node with the given priority found

        // Case 1: Node with no child or only one child
        if (root->left == NULL || root->right == NULL) {
            Node* temp = root->left ? root->left : root->right;

            // No child case
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else { // One child case
                *root = *temp;
            }

            free(temp->data.name);
            free(temp);
        } else {
            // Case 2: Node with two children
            Node* minNode = findMinNode(root->right);

            root->data = minNode->data;
            root->right = deleteNode(root->right, minNode->data.priority);
        }
    }

    // If the tree had only one node, then return
    if (root == NULL)
        return root;

    // Update the height of the current node
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // Check the balance factor and perform rotations if necessary
    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rotateRight(root);

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return rotateLeft(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

// Function to free the memory occupied by the AVL tree
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root->data.name);
        free(root);
    }
}

int main() {
    Node* root = NULL;

    int choice;
    int priority;
    char taskName[100];

    while (1) {
        printf("\n\n----- Task Scheduler -----\n");
        printf("1. Add Task\n");
        printf("2. Delete Task\n");
        printf("3. Display All Tasks\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter Task Name: ");
                scanf("%99s", taskName);
                printf("Enter Priority: ");
                scanf("%d", &priority);
                root = insert(root, (Task){strdup(taskName), priority});
                break;
            case 2:
                printf("\nEnter Priority of Task to Delete: ");
                scanf("%d", &priority);
                root = deleteNode(root, priority);
                break;
            case 3:
                printf("\nAll Tasks:\n");
                inorderTraversal(root);
                break;
            case 4:
                freeTree(root);
                printf("\nExiting...\n");
                return 0;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
}
