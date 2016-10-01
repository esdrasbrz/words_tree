#ifndef WORDSHEADER
#define WORDSHEADER

/**
 * Typedefs of binary tree structure
 */
typedef struct Node {
    char *word; // string containing the word to store

    struct Node* left;
    struct Node* right;
} TreeNode;

/**
 * Functions
 */
void destroy(TreeNode*);
TreeNode* add(TreeNode*, char*);
void print(TreeNode*);
int find(TreeNode*, char*);
TreeNode* del(TreeNode*, char*);

#endif
