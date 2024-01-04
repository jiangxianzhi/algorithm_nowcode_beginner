#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// minmax implement by myself
// but alpha beta is not such clear
struct Node
{
    int value;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void createTree(struct Node *root, int depth)
{
    if (depth > 1)
    {
        root->left = createNode(0);
        root->right = createNode(0);
        createTree(root->left, depth - 1);
        createTree(root->right, depth - 1);
    }
}

// depth first print tree

void printTree(struct Node *root)
{
    printf("%d  ", root->value);
    if (root->left == NULL && root->right == NULL)
    {
        return;
    }

    printTree(root->left);

    printTree(root->right);
};

// set leaf node value from 1 to 8
int count = 1;
void setLeafNode(struct Node *root)
{
    if (root->left == NULL && root->right == NULL)
    {
           
        root->value = count++;
        return;
    }

    setLeafNode(root->left);

    setLeafNode(root->right);
}

int min_max_algorithm(struct Node *root, int depth)
{
    if (root->left == NULL && root->right == NULL)
    {
        return root->value;
    }
    if (depth % 2 == 0)
    {
        // max
        return min_max_algorithm(root->left, depth - 1) > min_max_algorithm(root->right, depth - 1) ? min_max_algorithm(root->left, depth - 1) : min_max_algorithm(root->right, depth - 1);
    }
    else
    {
        // min
        return min_max_algorithm(root->left, depth - 1) < min_max_algorithm(root->right, depth - 1) ? min_max_algorithm(root->left, depth - 1) : min_max_algorithm(root->right, depth - 1);
    }
}

int main()
{
    struct Node *root = createNode(0);
    createTree(root, 4);
    setLeafNode(root);

    // Print the values of the leaf nodes
    // You can add your own logic here to print the values of the leaf nodes
    // For example, you can use a depth-first traversal to print the values
    // printTree(root);

    printf("%d", min_max_algorithm(root, 4));
    return 0;
}