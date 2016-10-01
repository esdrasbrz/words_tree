#include "words.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * Function that destroy the tree with free on its pointers
 */
void destroy(TreeNode* tree) {
    if (tree) {
        destroy(tree->left);
        destroy(tree->right);
        free(tree->word);
        free(tree);
    }
}

/**
 * Function for add a new word on tree, checking your position
 *
 * It returns a new (or the old) pointer for tree.
 */
TreeNode* add(TreeNode* tree, char* word) {
    TreeNode* aux;
    TreeNode* word_node = (TreeNode*) malloc(sizeof(TreeNode));
    int comp;

    // create the new node
    word_node->word = word;
    word_node->left = NULL;
    word_node->right = NULL;

    // checks that the tree is empty
    if (!tree) {
        // just returns the new node
        return word_node;
    } else {
        aux = tree;

        // walks on tree finding the position of new word
        while (1) {
            comp = strcmp(aux->word, word);
            if (comp == 0) { // stop and don't add anything
                // free in word mem
                destroy(word_node);
                break;
            } else if (comp > 0) {
                if (aux->left) {
                    aux = aux->left;
                } else {
                    aux->left = word_node;
                    break;
                }
            } else {
                if (aux->right) {
                    aux = aux->right;
                } else {
                    aux->right = word_node;
                    break;
                }
            }
        }
    }

    return tree;
}

/**
 * Function for print binary tree in order
 */
void print(TreeNode* tree) {
    if (tree) {
        print(tree->left);
        printf("%s\n", tree->word);
        print(tree->right);
    }
}

/**
 * Function for find a word with binary search
 *
 * It returns 1 if have founded, else 0
 */
int find(TreeNode* tree, char* word) {
    int comp;
   
    if (tree) {
       comp = strcmp(tree->word, word);

        if (comp == 0)
            return 1;
        else if (comp > 0)
            return find(tree->left, word);
        else
            return find(tree->right, word);
    }
    
    return 0;
}

/**
 * Function that delete a word
 */
TreeNode* del(TreeNode* tree, char* word) {
    TreeNode *node = tree, *father = NULL; // aux for deletion
    TreeNode *aux, *aux_father;
    char *swap;
    int comp;

    // loop to find the element
    while (node && (comp = strcmp(node->word, word)) != 0) {
        father = node;
        
        if (comp > 0)
            node = node->left;
        else
            node = node->right;
    }

    // verify if the elements exists
    if (node) {
        // verify if the node has no childrens
        if (!node->left && !node->right) {
            // just remove the node and update the father
            free(node->word);
            free(node);

            if (father) {
                if (father->left == node)
                    father->left = NULL;
                else
                    father->right = NULL;
            } else {
                return NULL;
            }
        } else if (node->left && node->right) { // has two sons
            aux_father = NULL;
            aux = node->right;

            // find the minimum in the left
            while (aux->left) {
                aux_father = aux;
                aux = aux->left;
            }

            // swap the value with node
            swap = aux->word;
            aux->word = node->word;
            node->word = swap;

            // remove the aux element
            if (aux_father) {
                aux_father->left = aux->right;
            } else {
                node->right = aux->right;
            }

            free(aux->word);
            free(aux);
        } else { // has just one son
            if (father) {
                if (father->left == node)
                    father->left = node->left ? node->left : node->right;
                else
                    father->right = node->left ? node->left : node->right;
            } else {
                tree = tree->left ? tree->left : tree->right;
            }

            free(node->word);
            free(node);
        }
    }

    return tree;
}
