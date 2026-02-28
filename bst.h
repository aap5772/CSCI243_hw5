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
#define BUFLEN 80   // we abstract the length to a def 

/*
* dynarray
* made to dynamicly handle array sizes
* pointer array to hold integers
* designated capacity 
* size tracker so we can see the size
*/

typedef struct dynarray {
    int * ary;      ///< points to an array of ints; capacity is its dimension
    int capacity;   // capacity for the actual size
    int size;       // how many integers there were
} dynarray_t;

/*
* bst_node
* basic node to allow for building of trees
*/

typedef struct bst_node {
    int data ;                  // the actual data
    struct bst_node * left ;    // pointer to the left node
    struct bst_node * right ;   // pointer to the right node
} bst_node_t;

/// The three supported traversals

typedef enum {
    PREORDER,           // preorder
    INORDER,            // inorder
    POSTORDER           // postorder
} traversal_type_t;

/**
 * Create and initialize a dynamic array structure.
 *
 * Allocates a dynarray_t and an internal integer buffer with the given
 * initial capacity. The dynarray starts empty (size = 0).
 *
 * @param capacity  Initial number of integers the dynarray can hold.
 *                 Must be > 0.
 * @return Pointer to a newly allocated dynarray_t on success, or NULL on failure.
 *
 * @ownership Caller owns the returned dynarray_t and must free it with
 *            dynarray_free().
 */
dynarray_t * dynarray_init(int capacity);

/**
 * Append one integer to the dynamic array.
 *
 * If the internal buffer is full, the buffer is grown (typically doubled)
 * before inserting.
 *
 * @param dp    Pointer to an initialized dynarray_t.
 * @param data  Integer value to append.
 *
 * @pre dp != NULL
 * @post dp->size is increased by 1 if insertion succeeds.
 */
void dynarray_insert(dynarray_t * dp, int data);

/**
 * Read integers from an input stream and append them to the dynarray.
 *
 * Parses the input as whitespace-separated or line-based integers. Non-integer
 * lines/tokens may be ignored depending on implementation.
 *
 * @param dp  Pointer to an initialized dynarray_t to receive values.
 * @param fp  Input stream to read from (e.g., stdin or an open file).
 *
 * @pre dp != NULL
 * @pre fp != NULL
 */
void dynarray_read(dynarray_t * dp, FILE * fp);

/**
 * Print the contents of the dynamic array to stdout.
 *
 * Output format is implementation-defined, but typically prints the integers
 * in stored order.
 *
 * @param dp  Pointer to a dynarray_t to print.
 *
 * @pre dp != NULL
 */
void dynarray_print(const dynarray_t * dp);

/**
 * Free a dynamic array and its internal buffer.
 *
 * Safe to call with NULL (no effect).
 *
 * @param dp  dynarray_t to free, or NULL.
 *
 * @post Memory owned by dp is released; dp becomes invalid.
 */
void dynarray_free(dynarray_t * dp);

/**
 * Insert a value into a binary search tree.
 *
 * Inserts value into the BST rooted at bp and returns the (possibly new) root.
 * If value already exists, the tree is unchanged (typical BST set behavior).
 *
 * @param bp     Root of the BST (may be NULL for an empty tree).
 * @param value  Value to insert.
 * @return Root pointer of the BST after insertion (may differ from bp if bp was NULL).
 *
 * @ownership The tree nodes are heap-allocated; caller owns the tree and must
 *            free it with bst_free().
 */
bst_node_t * bst_insert(bst_node_t * bp, int value);

/**
 * Build a BST by inserting each element from an integer array.
 *
 * Inserts x[0..size-1] into a BST (typically in order) and returns the root.
 *
 * @param size  Number of elements in x to insert.
 * @param x     Array of integers of length at least size.
 * @return Root of the newly built BST, or NULL if size == 0.
 *
 * @pre x != NULL if size > 0
 * @ownership Caller owns the returned tree and must free it with bst_free().
 */
bst_node_t * ary_to_bst(int size, const int x[]);

/**
 * Traverse and print a BST in the requested order.
 *
 * Prints node values to stdout in one of: preorder, inorder, or postorder.
 *
 * @param bp  Root of the BST (may be NULL; prints nothing).
 * @param tt  Traversal type (PREORDER, INORDER, POSTORDER).
 */
void bst_traverse(const bst_node_t * bp, traversal_type_t tt);

/**
 * Free an entire BST.
 *
 * Recursively frees all nodes in the BST. Safe to call with NULL.
 *
 * @param bp  Root of the BST to free, or NULL.
 *
 * @post All nodes reachable from bp are freed; bp becomes invalid.
 */
void bst_free(bst_node_t * bp);

#endif // _BST_H

