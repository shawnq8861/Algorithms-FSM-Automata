/*****************************************************************************
 *
 * file RBTreeNode.cpp
 * Implementation file for class RBTreeNode
 *
 * Code written by:
 * Shawn Quinn
 * quinnms1
 * 01/24/2015
 *
 ****************************************************************************/

#include "RBTreeNode.h"

/*****************************************************************************
 *
 * default constructor
 *
 ****************************************************************************/
RBTreeNode::RBTreeNode()
{
   data = 0;
   color = black;
   leftChild = NULL;
   rightChild = NULL;
   parent = NULL;
}

/*****************************************************************************
 *
 * destructor
 *
 ****************************************************************************/
RBTreeNode::~RBTreeNode()
{
}

/*****************************************************************************
 *
 * public method getData
 * - return the integer stored in member data
 *
 ****************************************************************************/
int RBTreeNode::getData()
{
   return data;
}

/*****************************************************************************
 *
 * public method setData
 * - assign the integer num to member data
 *
 ****************************************************************************/
void RBTreeNode::setData(int num)
{
   data = num;
}

/*****************************************************************************
 *
 * public method getColor
 * - return node color
 *
 ****************************************************************************/
nodeColor RBTreeNode::getColor()
{
   return color;
}

/*****************************************************************************
 *
 * public method setColor
 * - assign the value in ndColor to member color
 *
 ****************************************************************************/
void RBTreeNode::setColor(nodeColor ndColor)
{
   color = ndColor;
}

/*****************************************************************************
 *
 * public method getLeftChild
 * - return the member leftChild
 *
 ****************************************************************************/
RBTreeNode* RBTreeNode::getLeftChild()
{
   return leftChild;
}

/*****************************************************************************
 *
 * public method getRightChild
 * - return the member rightChild
 *
 ****************************************************************************/
RBTreeNode* RBTreeNode::getRightChild()
{
   return rightChild;
}

/*****************************************************************************
 *
 * public method getParent
 * - return the member parent
 *
 ****************************************************************************/
RBTreeNode* RBTreeNode::getParent()
{
   return parent;
}

/*****************************************************************************
 *
 * public method setLeftChild
 * - assign the pointer leftRoot to member leftChild
 *
 ****************************************************************************/
void RBTreeNode::setLeftChild(RBTreeNode* leftRoot)
{
   leftChild = leftRoot;
}

/*****************************************************************************
 *
 * public method setRightChild
 * - assign the pointer rightRoot to member rightChild
 *
 ****************************************************************************/
void RBTreeNode::setRightChild(RBTreeNode* rightRoot)
{
   rightChild = rightRoot;
}

/*****************************************************************************
 *
 * public method setParent
 * - assign the pointer parNode to member parent
 *
 ****************************************************************************/
void RBTreeNode::setParent(RBTreeNode* parNode)
{
   parent = parNode;
}
