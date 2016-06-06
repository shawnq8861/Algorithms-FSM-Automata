/*****************************************************************************
 *
 * file TreeNode.h
 * class TreeNode contains the interface and implementation of a simple 
 * doubly linked binary tree node data structure
 *
 * Shawn Quinn
 * quinnms1
 * 01/17/2015
 *
 ****************************************************************************/

#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>

using namespace std;

/*****************************************************************************
 *
 * class TreeNode interface declaration
 *
 ****************************************************************************/
class TreeNode
{
public:
   // default constructor
   TreeNode();

   // constructor
   // - initialize value, leftChild, and rightChild
   TreeNode(int num, TreeNode* leftRoot, TreeNode* rightRoot);

   // destructor
   ~TreeNode();

   // method getValue
   // - return the integer stored in member value
   int getValue();

   // method setValue
   // - assign the integer num to member value
   void setValue(int value);

   // method getLeftChild
   // - return the member leftChild
   TreeNode* getLeftChild();

   // method getRightChild
   // - return the member rightChild
   TreeNode* getRightChild();

   // method setLeftChild
   // - assign the pointer leftRoot to member leftChild
   void setLeftChild(TreeNode* leftRoot);

   // method setRightChild
   // - assign the pointer rightRoot to member rightChild
   void setRightChild(TreeNode* rightRoot);

private:
   int value;              // node data
   TreeNode* leftChild;    // points to left child node
   TreeNode* rightChild;   // points to right child node
};

#endif