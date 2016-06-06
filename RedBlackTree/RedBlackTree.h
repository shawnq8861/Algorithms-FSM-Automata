/*****************************************************************************
 *
 * file RedBlackTree.h
 * class RedBlackTree contains the interface and implementation of a red-black
 * balanced binary tree data structure
 *
 * Summary of the 4 Red Black Tree Properties adherred to by this code:
 *
 * 1. Every node is colored either red or black.
 * 2. The root is black.
 * 3. If a node is red, its children must be black.
 * 4. Every path from a node to a null pointer must contain the same number of
 * 	  black nodes.
 *
 * 1. Every node is either red or black.
 * 2. The root is black.
 * 3. Every leaf ( NIL ) is black.
 * 4. If a node is red, then both its children are black.
 * 5. For each node, all simple paths from the node to descendant leaves contain the
 * 	  same number of black nodes.
 *
 * Code written by:
 * Shawn Quinn
 * quinnms1
 * 01/24/2015
 *
 ****************************************************************************/

#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include <iostream>
#include "RBTreeNode.h"

using namespace std;

// Helper function
const char* convertColor(nodeColor ndColor);

/*****************************************************************************
 *
 * class RedBlackTree interface declaration
 *
 ****************************************************************************/
class RedBlackTree
{
public:
   // default constructor
   RedBlackTree();

   // destructor
   ~RedBlackTree();

   // method getRoot
   // - return the pointer to the root node
   RBTreeNode* getRoot();

   // method search
   // - return pointer to node that contains the data value
   RBTreeNode* search(RBTreeNode* node, int newData);

   // method insert
   // - non-recursively insert the data into the tree
   RBTreeNode* insert(RBTreeNode* node, int newData);

   // method insert
   // - non-recursively insert the data into the tree
   RBTreeNode* insertCormen(int newData);

   // method insertRebalance
   // - rebalance the trea after insertion of new red node
   void insertFixUp(RBTreeNode* node);

   // method insertRebalance
   // - rebalance the trea after insertion of new red node
   void insertFixUpOld(RBTreeNode* node);

   // method leftRotate
   void leftRotate(RBTreeNode* node);

   // method rightRotate
   void rightRotate(RBTreeNode* node);

   // method transplant
   void transplant(RBTreeNode* u, RBTreeNode* v);

   // method treeMinimum
   RBTreeNode* treeMinimum(RBTreeNode* x);

   // method delete
   // - non-recursively delete the data from the tree
   void deleteNode(RBTreeNode* node);

   // method deleteFixUp
   // -
   void deleteFixUp(RBTreeNode* node);

   // method inOrderTraverse
   // - print out the node data values in order
   void inOrderTraverse(RBTreeNode* root);

private:
   RBTreeNode* root;     // points to root node
   int numNodes;
   
};

#endif
