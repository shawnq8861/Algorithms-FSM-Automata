/*****************************************************************************
 *
 * file BalancedBST.cpp
 * implementation of the Balanced Binary Search Tree Functions
 *
 * Shawn Quinn
 * quinnms1
 * 01/17/2015
 *
 ****************************************************************************/

#include "BalancedBST.h"

/*****************************************************************************
 * function findBalancedBSTRoot
 *
 * - determine the maximum number of complete, full trees the array may
 *   represent
 * - 1, 3, 7, 15, 31, 63, ...
 * - calculate the number of nodes on the bottom row
 * - calculate the number of bottom row nodes greater than the root node
 * - calculate the array index of the root node
 * - return the index of the root node
 *
 ****************************************************************************/
int findBalancedBSTRoot(int values[], int numValues)
{
   cout << "array size passed in = " << numValues << endl;
   // determine number of full, complete BSTs
   int multiple = 1;
   int maxFC = 1;
   while(maxFC < numValues) {
      multiple *= 2;
      maxFC += multiple;
   }
   maxFC -= multiple;
   cout << "max size BST = " << maxFC << endl;
   //calculate the number of nodes on the bottom row
   int numBottRow = numValues - maxFC;
   cout << "number of nodes on bottom row = " << numBottRow << endl;
   // calculate the number of bottom row nodes greater than the root node
   int numBottGTRoot = numBottRow - (multiple/2);
   if ( numBottGTRoot < 0 )
      numBottGTRoot = 0;
   cout << "number of nodes on bottom row GT root = " << numBottGTRoot << endl;
   // calculate the array index of the root node
   // rootIndex = maxIndex - ((maxFC - 1)/2) - (num nodes GT root)
   int rootIndex = (numValues - 1) - ((maxFC - 1)/2) - numBottGTRoot;
   cout << "root node index = " << rootIndex << endl;
   cout << "root node value = " << values[rootIndex] << endl;

   return rootIndex;
}

/*****************************************************************************
 * function buildBalancedBST
 *
 * - determine the maximum number of complete, full trees the array may
 *   represent
 * - 1, 3, 7, 15, 31, 63, ...
 * - calculate the number of nodes on the bottom row
 * - calculate the number of bottom row nodes greater than the root node
 * - calculate the array index of the root node
 * - create a new node and assign the value at index to the value member
 *   by calling the set method
 * - call left and right child set methods with argument that recursively
 *   calls this function
 *
 ****************************************************************************/
TreeNode* buildBalancedBST(int values[], int numValues)
{
   // base case 1... no elements passed in
   if( numValues < 1 ) {
      return NULL;
   }
   // base case 2... single element must be a leaf
   if( numValues == 1 ) {
      TreeNode* root = new TreeNode();
      root->setValue(values[0]);
      root->setLeftChild(NULL);
      root->setRightChild(NULL);
      return root;
   }
   // determine number of full, complete BSTs
   int multiple = 1;
   int maxFC = 1;
   while(maxFC < numValues) {
      multiple *= 2;
      maxFC += multiple;
   }
   maxFC -= multiple;
   //calculate the number of nodes on the bottom row
   int numBottRow = numValues - maxFC;
   // calculate the number of bottom row nodes greater than the root node
   int numBottGTRoot = numBottRow - (multiple/2);
   if ( numBottGTRoot < 0 )
      numBottGTRoot = 0;
   // calculate the array index of the root node
   // rootIndex = maxIndex - ((maxFC - 1)/2) - (num nodes GT root)
   int rootIndex = (numValues - 1) - ((maxFC - 1)/2) - numBottGTRoot;
   TreeNode* root = new TreeNode();
   root->setValue(values[rootIndex]);
   root->setLeftChild(buildBalancedBST(values, rootIndex));
   root->setRightChild(buildBalancedBST(values + (rootIndex + 1), numValues - (rootIndex + 1)));

   return root;
}

/*****************************************************************************
 * function buildBalancedBSTWithTracers
 *
 * - same as buildBalanceBST except it includes cout tracers
 *
 ****************************************************************************/
TreeNode* buildBalancedBSTWithTracers(int values[], int numValues)
{
   cout << "array size passed in = " << numValues << endl;
   // base case 1... no elements passed in
   if( numValues < 1 ) {
      return NULL;
   }
   // base case 2... single element must be a leaf
   if( numValues == 1 ) {
      TreeNode* root = new TreeNode();
      root->setValue(values[0]);
      cout << "leaf node value = " << root->getValue() << endl;
      root->setLeftChild(NULL);
      root->setRightChild(NULL);
      return root;
   }
   // determine number of full, complete BSTs
   int multiple = 1;
   int maxFC = 1;
   while(maxFC < numValues) {
      multiple *= 2;
      maxFC += multiple;
   }
   maxFC -= multiple;
   cout << "max size BST = " << maxFC << endl;
   //calculate the number of nodes on the bottom row
   int numBottRow = numValues - maxFC;
   cout << "number of nodes on bottom row = " << numBottRow << endl;
   // calculate the number of bottom row nodes greater than the root node
   int numBottGTRoot = numBottRow - (multiple/2);
   if ( numBottGTRoot < 0 )
      numBottGTRoot = 0;
   cout << "number of nodes on bottom row GT root = " << numBottGTRoot << endl;
   // calculate the array index of the root node
   // rootIndex = maxIndex - ((maxFC - 1)/2) - (num nodes GT root)
   int rootIndex = (numValues - 1) - ((maxFC - 1)/2) - numBottGTRoot;
   cout << "root node index = " << rootIndex << endl;
   cout << "root node value = " << values[rootIndex] << endl;
   TreeNode* root = new TreeNode();
   root->setValue(values[rootIndex]);
   root->setLeftChild(buildBalancedBSTWithTracers(values, rootIndex));
   root->setRightChild(buildBalancedBSTWithTracers(values + (rootIndex + 1), numValues - (rootIndex + 1)));

   return root;
}

/*****************************************************************************
 * function inOrderTraverse
 *
 * - perform recursive in order traversal of a balanced BST
 *
 ****************************************************************************/
void inOrderTraverse(TreeNode* root)
{
   if ( root == NULL ) {
      return;
   }
   // recursive call on left child node
   inOrderTraverse(root->getLeftChild());
   // "visit" the root node by pronting it's value
   cout << root->getValue() << " ";
   // recursive call on right child node
   inOrderTraverse(root->getRightChild());
}

/*****************************************************************************
 * function removeTree
 *
 * - call delete on each node to deallocate memory
 *
 ****************************************************************************/
void removeTree(TreeNode* root)
{
   if ( root == NULL ) {
      return;
   }
   // recursive call on left child node
   removeTree(root->getLeftChild());
   // recursive call on right child node
   removeTree(root->getRightChild());
    // call delete on the node, then set node to NULL
   cout << "deleting node..." << endl;
   delete root;
   root = NULL;
}