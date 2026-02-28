// file: bst.h
//
// Binary Search Tree structure and function declarations 
//
// @author: CS@RIT.EDU
// @author: Alex Polo, aap5772

#ifndef _BST_H
#define _BST_H
#include <stdio.h>
// Note: the first definition is properly documented.

#define ARY_SIZE 10 ///< initial dynamic array size
#define BUFLEN 80   // FIXME: correctly document this define

/// **FIXME** replace this with added struct documentation here

typedef struct dynarray {
    int * ary;      ///< points to an array of ints; capacity is its dimension
    int capacity;   // FIXME: replace with complete documentation of fields
    int size;       // FIXME
} dynarray_t;

/// **FIXME** replace this with added struct documentation here and in fields

typedef struct bst_node {
    int data ;                  // FIXME
    struct bst_node * left ;    // FIXME
    struct bst_node * right ;   // FIXME
} bst_node_t;

/// The three supported traversals

typedef enum {
    PREORDER,           // FIXME
    INORDER,            // FIXME
    POSTORDER           // FIXME
} traversal_type_t;

// // // // // // // // // // // // // // // // // // // // 
// FUNCTIONS STUDENTS ARE REQUIRED TO IMPLEMENT
//
// REMOVE THIS COMMENT BLOCK WHEN YOU ADD THE DOCSTRINGS
//
// // // // // // // // // // // // // // // // // // // // 
// **FIXME** DOCUMENT EACH OF THESE AS 'interface functions'
//
// THE FULL, PUBLISHABLE DOCSTRINGS BELONG HERE IN THE .h FILE.
//
// // // // // // // // // // // // // // // // // // // // 

dynarray_t * dynarray_init(int capacity);

void dynarray_insert(dynarray_t * dp, int data);

void dynarray_read(dynarray_t * dp, FILE * fp);

void dynarray_print(const dynarray_t * dp);

void dynarray_free(dynarray_t * dp);

bst_node_t * bst_insert(bst_node_t * bp, int value);

bst_node_t * ary_to_bst(int size, const int x[]);

void bst_traverse(const bst_node_t * bp, traversal_type_t tt);

void bst_free(bst_node_t * bp);

#endif // _BST_H

