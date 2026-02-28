// bst.c
// author Alex Polo aap5772


#include "bst.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


dynarray_t * dynarray_init(int capacity){
    //start at a small size then double the capacity when overflowing, stop it from over flowing using an if statement base case
    dynarray_t *array = malloc(sizeof(dynarray_t));
    array -> ary = malloc(capacity * sizeof(int));
    array -> capacity = capacity;
    array -> size = 0;
    return array;
}

void dynarray_insert(dynarray_t * dp, int data){
    if (dp -> size >= dp -> capacity){ // Checking if its too big, then changes up the stack allocation for a bigger array
        int new_cap = (dp -> capacity * 2) * sizeof(int);
        int *new_ary = realloc(dp -> ary, new_cap);
        dp -> ary = new_ary;
        dp -> capacity = new_cap;
    }
    //inserts and tracks size
    dp -> ary[dp -> size] = data;
    dp -> size++;
}

void dynarray_read(dynarray_t * dp, FILE * fp){
    char buff[BUFLEN]; // Buffer of size 80
    int value;
    while(fgets(buff, sizeof(buff), fp) != NULL){ //while within the buffer limits
        if (sscanf(buff, "%d", &value) == 1){ //takes the integer and stores it
            dynarray_insert(dp, value);
        }
    }
}

void dynarray_print(const dynarray_t * dp){
    printf("Input values:\n");
    for (int i = 0; i < dp -> size; i++){
        printf("%d\n",dp -> ary[i]);
    }
}

void dynarray_free(dynarray_t * dp){
    if (dp == NULL){
        return;
    }
    free(dp -> ary);
    free(dp);
}

bst_node_t * bst_insert(bst_node_t * bp, int value){
    if (bp == NULL){ // start a clean new
        bst_node_t *newNode = malloc(sizeof(bst_node_t));
        newNode -> data = value;
        newNode -> left = NULL;
        newNode -> right = NULL;
        return newNode;
    }
    bst_node_t * nextNode = bp;
    if (value < nextNode -> data){
        nextNode -> left = bst_insert(nextNode -> left, value);
    } else if (value > nextNode -> data){
        nextNode -> right = bst_insert(nextNode -> right, value);
    }
    return bp;
}

bst_node_t * ary_to_bst(int size, const int x[]){
    bst_node_t *tree = NULL;
    for(int i = 0; i < size; i++){
        tree = bst_insert(tree, x[i]);
    }
    return tree;
}

void bst_traverse(const bst_node_t * bp, traversal_type_t tt){

    if (bp == NULL){
        return;
    }
    switch(tt){  //switching based on type
        case PREORDER:
            printf("%d\n", bp -> data);
            bst_traverse(bp->left, tt);
            bst_traverse(bp->right, tt);
            break;
        case INORDER:
            bst_traverse(bp -> left, tt);
            printf("%d\n", bp -> data);
            bst_traverse(bp->right, tt);
            break;
        case POSTORDER:
            bst_traverse(bp -> left, tt);
            bst_traverse(bp->right, tt);
            printf("%d\n", bp -> data);
            break;
    }
}

void bst_free(bst_node_t * bp){
    if (bp == NULL) return;
    bst_free(bp -> left);
    bst_free(bp -> right);
    free(bp);
}

int main(int argc, char *argv[]){
    FILE *fp = stdin;
    if (argc > 1){
        fp = fopen(argv[1], "r");
            if (fp == NULL) {
            perror("Failed to open file");
            return EXIT_FAILURE;
        }
    }
    dynarray_t *dp = dynarray_init(ARY_SIZE);
    dynarray_read(dp, fp);
    dynarray_print(dp);

    bst_node_t * bp = ary_to_bst(dp -> size, dp -> ary);
    
    printf("Preorder traversal:\n");
    bst_traverse(bp, PREORDER);
    
    printf("Inorder traversal:\n");
    bst_traverse(bp, INORDER);
    
    printf("Postorder traversal:\n");
    bst_traverse(bp, POSTORDER);
    
    dynarray_free(dp);
    bst_free(bp);

    if (fp != stdin) fclose(fp);
    return EXIT_SUCCESS;

}
