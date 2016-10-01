/**
 * This program organize the input words to a organized binary tree by alphabetic order
 *
 * Esdras R. Carmo - esdrasbrz@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "words.h"

#define BUFFER_SIZE 1000

int main(void) {
    TreeNode *tree = NULL; // pointer to tree structure
    char buffer[BUFFER_SIZE]; // buffer to input strings
    int size; // size of the new word
    char *word; // new word dinamically allocated
    char option[10]; // option that user choose to operate the tree

    do {
        // read the option
        scanf(" %s", option);

        if (!strcmp(option, "add")) { // add a new word in tree
            // reads the word in buffer
            scanf(" %s", buffer);

            // check the size and alloc the new string
            size = strlen(buffer);
            word = (char*) malloc((size + 1) * sizeof(char));
            strcpy(word, buffer);

            // add on tree
            tree = add(tree, word);
        } else if (!strcmp(option, "find")) {
            // reads the word in buffer
            scanf(" %s", buffer);

            // print the result
            printf("\n%s %s\n\n", buffer, find(tree, buffer) ? "is here" : "is not here");
        } else if (!strcmp(option, "del")) {
            // reads the word in buffer
            scanf(" %s", buffer);

            // remove the element
            tree = del(tree, buffer);
        } else if (!strcmp(option, "print")) { // prints all words in order
            printf("--------------------\n");
            print(tree);
            printf("--------------------\n\n");
        }
    } while (strcmp(option, "exit"));

    // free the mem of tree
    destroy(tree);

    return 0;
}
