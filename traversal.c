#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int getHeight(struct TreeNode* node) {
    if (node == NULL)
        return 0;
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

void printLevel(struct TreeNode* node, int level) {
    if (node == NULL)
        return;
    if (level == 1)
        printf("%d ", node->val);
    else if (level > 1) {
        printLevel(node->left, level - 1);
        printLevel(node->right, level - 1);
    }
}

void levelOrderTraversal(struct TreeNode* root) {
    int height = getHeight(root);
    for (int i = 1; i <= height; i++) {
        printLevel(root, i);
    }
}

int main() {
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Level Order Traversal: ");
    levelOrderTraversal(root);
    printf("\n");

    return 0;
}
