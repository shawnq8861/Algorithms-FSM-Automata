/*****************************************************************************
 *
 * file RBTreeNode.h
 * class RBTreeNode contains the interface and implementation of a doubly
 * linked binary tree node data structure with red-black color differentiation
 *
 * Code written by:
 * Shawn Quinn
 * quinnms1
 * 01/24/2015
 *
 ****************************************************************************/

#ifndef RBTREENODE_H
#define RBTREENODE_H

#include <iostream>

using namespace std;

enum nodeColor {red, black};

/*****************************************************************************
 *
 * class RBTreeNode interface declaration
 *
 ****************************************************************************/
class RBTreeNode
{
public:
   // default constructor
   RBTreeNode();

   // destructor
   ~RBTreeNode();

   // method getData
   // - return the integer stored in member data
   int getData();

   // method setData
   // - assign the integer num to member data
   void setData(int num);

   // method getColor
   // - return node color
   nodeColor getColor();

   // method setColor
   // - assign the value in ndColor to member color
   void setColor(nodeColor ndColor);

   // method getLeftChild
   // - return the member leftChild
   RBTreeNode* getLeftChild();

   // method getRightChild
   // - return the member rightChild
   RBTreeNode* getRightChild();

   // method getParent
   // - return the member parent
   RBTreeNode* getParent();

   // method setLeftChild
   // - assign the pointer leftRoot to member leftChild
   void setLeftChild(RBTreeNode* leftRoot);

   // method setRightChild
   // - assign the pointer rightRoot to member rightChild
   void setRightChild(RBTreeNode* rightRoot);

   // method setParent
   // - assign the pointer parNode to member parent
   void setParent(RBTreeNode* parNode);

private:
   int data;                  // node data
   nodeColor color;           // node color
   RBTreeNode* leftChild;     // points to left child node
   RBTreeNode* rightChild;    // points to right child node
   RBTreeNode* parent;        // points to parent node, Null for root node
};

#endif
