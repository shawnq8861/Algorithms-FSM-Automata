/*****************************************************************************
 *
 * file BalancedBST.h
 * interface declaration for the Balanced Binary Search Tree Functions
 *
 * Shawn Quinn
 * quinnms1
 * 01/17/2015
 *
 ****************************************************************************/

#ifndef BALANCEDBST_H
#define BALANCEDBST_H

#include <iostream>
#include "TreeNode.h"

using namespace std;

// function findBalancedBSTRoot
// - determine the maximum number of complete, full trees the array may
//   represent
// - 1, 3, 7, 15, 31, 63, ...
// - calculate the number of nodes on the bottom row
// - calculate the number of bottom row nodes greater than the root node
// - calculate the array index of the root node
// - return the index of the root node
int findBalancedBSTRoot(int values[], int numValues);

// function buildBalancedBST
// - determine the maximum number of complete, full trees the array may
//   represent
// - 1, 3, 7, 15, 31, 63, ...
// - calculate the number of nodes on the bottom row
// - calculate the number of bottom row nodes greater than the root node
// - calculate the array index of the root node
// - create a new node and assign the value at index to the value member
//   by calling the set method
// - call left and right child set methods with argument that recursively
//   calls this function
TreeNode* buildBalancedBST(int values[], int numValues);

// function buildBalancedBSTWithTracers
// - same as buildBalanceBST except it includes cout tracers
TreeNode* buildBalancedBSTWithTracers(int values[], int numValues);

// function inOrderTraverse
// - perform recursive in order traversal od a balanced BST
void inOrderTraverse(TreeNode* root);

// function removeTree
// - call delete on each node to deallocate memory
void removeTree(TreeNode* root);

#endif