#include <stdio.h>
#include <stdlib.h>
#include<time.h>

struct node {
  int key;
  struct node *left, *right;
};

struct node *newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

// Inorder Traversal
void inorder(struct node *root, FILE *file)
{
  if (root != NULL) {

    inorder(root->left, file);

    fprintf(file, "%d ", root->key);

    inorder(root->right, file);
  }
}

// Preorder Traversal
void preorder(struct node *root, FILE *file)
{
  if (root != NULL) {
    fprintf(file, "%d ", root->key);

    preorder(root->left, file);

    preorder(root->right, file);
  }
}

// Postorder Traversal
void postorder(struct node *root, FILE *file)
{
  if (root != NULL) {
    postorder(root->left, file);

    postorder(root->right, file);

    fprintf(file, "%d ", root->key);
  }
}

// Insert a node
struct node *insert(struct node *node, int key)
{
  // Return a new node if the tree is empty
  if (node == NULL) return newNode(key);

  // Traverse to the right place and insert the node
  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}

// Driver code
int main() {
  struct node *root = NULL;
  srand(time(0));
  int i;
  for (i = 0; i < 10000; i++) {
    int randomNumber = rand() % 1000 + 1;
    root = insert(root, randomNumber);
  }
  FILE *inorderFile = fopen("inorder.txt", "w");
  FILE *preorderFile = fopen("preorder.txt", "w");
  FILE *postorderFile = fopen("postorder.txt", "w");
  FILE *ftime_comp = fopen("timecomplexity.txt","w");
  printf("Inorder traversal: ");
  clock_t t1 = clock();
    inorder(root, inorderFile);
    clock_t t2 = clock();

    double time_inorder = ((double)t2-t1)/CLOCKS_PER_SEC*1000;
    fprintf(ftime_comp,"Inorder,Time = %lf seconds ",time_inorder);
  fclose(inorderFile);
  printf("Saved to file: inorder.txt\n");

  printf("Preorder traversal: ");
  clock_t t3 = clock();
    preorder(root, preorderFile);
    clock_t t4 = clock();

    double time_preorder = ((double)t4-t3)/CLOCKS_PER_SEC*1000;
    fprintf(ftime_comp,"preorder, Time = %lf seconds ",time_preorder);
  fclose(preorderFile);
  printf("Saved to file: preorder.txt\n");

  printf("Postorder traversal: ");
  clock_t t5 = clock();
    postorder(root, postorderFile);
    clock_t t6 = clock();

    double time_postorder = ((double)t6-t5)/CLOCKS_PER_SEC*1000;
    fprintf(ftime_comp,"postorder, Time = %lf seconds ",time_postorder);
  fclose(postorderFile);
  printf("Saved to file: postorder.txt\n");

  return 0;
}
