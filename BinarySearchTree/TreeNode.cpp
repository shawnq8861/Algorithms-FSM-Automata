/*****************************************************************************
 *
 * file TreeNode.cpp
 * Implementation file for class TreeNode
 *
 * Shawn Quinn
 * quinnms1
 * 01/20/2015
 *
 ****************************************************************************/

#include "TreeNode.h"

/*****************************************************************************
 *
 * default constructor
 *
 ****************************************************************************/
TreeNode::TreeNode()
{
   value = 0;
   leftChild = NULL;
   rightChild = NULL;
}

/*****************************************************************************
 *
 * constructor
 * - initialize value, leftChild, and rightChild
 *
 ****************************************************************************/
TreeNode::TreeNode(int num, TreeNode* leftRoot, TreeNode* rightRoot)
{
   value = num;
   leftChild = leftRoot;
   rightChild = rightRoot;
}

/*****************************************************************************
 *
 * destructor
 *
 ****************************************************************************/
TreeNode::~TreeNode()
{
}

/*****************************************************************************
 *
 * public method getValue
 * - return the integer stored in member value
 *
 ****************************************************************************/
int TreeNode::getValue()
{
   return value;
}

/*****************************************************************************
 *
 * public method getLeftChild
 * - return the member leftChild
 *
 ****************************************************************************/
TreeNode* TreeNode::getLeftChild()
{
   return leftChild;
}

/*****************************************************************************
 *
 * public method getRightChild
 * - return the member rightChild
 *
 ****************************************************************************/
TreeNode* TreeNode::getRightChild()
{
   return rightChild;
}

/*****************************************************************************
 *
 * public method setValue
 * - assign the integer num to member value
 *
 ****************************************************************************/
void TreeNode::setValue(int num)
{
   value = num;
}

/*****************************************************************************
 *
 * public method setLeftChild
 * - assign the pointer leftRoot to member leftChild
 *
 ****************************************************************************/
void TreeNode::setLeftChild(TreeNode* leftRoot)
{
   leftChild = leftRoot;
}

/*****************************************************************************
 *
 * public method setRightChild
 * - assign the pointer rightRoot to member rightChild
 *
 ****************************************************************************/
void TreeNode::setRightChild(TreeNode* rightRoot)
{
   rightChild = rightRoot;
}