#include <stdio.h>
#include <limits.h>
// chat gpt 3.5 写的
struct Node {
    int value;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int minimax(struct Node* node, int depth, int alpha, int beta, int isMaxPlayer) {
    if (depth == 0 || node == NULL) {
        return node->value;
    }

    if (isMaxPlayer) {
        int maxEval = INT_MIN;
        while (node != NULL) {
            int eval = minimax(node->left, depth - 1, alpha, beta, 0);
            maxEval = (eval > maxEval) ? eval : maxEval;
            alpha = (alpha > eval) ? alpha : eval;
            if (beta <= alpha) {
                break; // Beta cut-off
            }
            node = node->right;
        }
        return maxEval;
    } else {
        int minEval = INT_MAX;
        while (node != NULL) {
            int eval = minimax(node->left, depth - 1, alpha, beta, 1);
            minEval = (eval < minEval) ? eval : minEval;
            beta = (beta < eval) ? beta : eval;
            if (beta <= alpha) {
                break; // Alpha cut-off
            }
            node = node->right;
        }
        return minEval;
    }
}

int main() {
    // Create the tree with leaf node values 1, 2, 3, 4, 5, 6, 7, 8
    // You can use the createNode function from the previous example to create the tree

    // Call the minimax function with alpha-beta pruning to get the optimal head value
    int optimalHeadValue = minimax(root, 4, INT_MIN, INT_MAX, 1);

    printf("Optimal head value: %d\n", optimalHeadValue);

    return 0;
}