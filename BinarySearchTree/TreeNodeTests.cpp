/*****************************************************************************
 *
 * file TreeNodeTests.cpp
 * the test driver file for the TreeNode class 
 *
 * Shawn Quinn
 * quinnms1
 * 01/18/2015
 *
 ****************************************************************************/

#include <iostream>
#include "BalancedBST.h"

using namespace std;

int main(void)
{
   int testArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
   int arraySize = 13;
   
   cout << "Tests for non-recursive implementation:" << endl << endl;

   int root = findBalancedBSTRoot(testArray, arraySize);
   cout << endl << "first root index = " << root << endl << endl;

   int arraySizeLeft = root;
   int rootLeft = findBalancedBSTRoot(testArray, arraySizeLeft);
   cout << endl << "left root index = " << rootLeft << endl << endl;

   int arraySizeRight = arraySize - (root + 1);
   int rootRight = findBalancedBSTRoot(testArray + root + 1, arraySizeRight);
   cout << endl << "right root index = " << rootRight << endl << endl;

   cout << "Tests for recursive implementation:" << endl;

   TreeNode* rootPtr1 = buildBalancedBST(testArray, arraySize);
   cout << endl << "root node value = " << rootPtr1->getValue() << endl << endl;

   cout << "Tests for recursive implementation with tracers:" << endl << endl;

   TreeNode* rootPtr2 = buildBalancedBSTWithTracers(testArray, arraySize);
   cout << endl << "root node value = " << rootPtr2->getValue() << endl << endl;

   cout << "In order traversal of the tree:" << endl << endl;
   inOrderTraverse(rootPtr1);

   cout << endl << endl;

   cout << "Delete first tree:" << endl << endl;
   removeTree(rootPtr1);
   cout << endl << endl;

   cout << "Delete second tree:" << endl << endl;
   removeTree(rootPtr2);
   cout << endl << endl;
   
   return 0;
}