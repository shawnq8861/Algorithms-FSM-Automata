/*****************************************************************************
 *
 * file RedBlackTreeTests.cpp
 * the test driver file for the RedBlackTree class
 *
 * Code written by:
 * Shawn Quinn
 * quinnms1
 * 01/26/2015
 *
 ****************************************************************************/

#include <iostream>
#include "RedBlackTree.h"

using namespace std;

int main(void)
{
   cout << "Testing Red Black Tree implementation:" << endl << endl;

   RedBlackTree* testTree = new RedBlackTree();;
   RBTreeNode* root = testTree->getRoot();
   root = testTree->insertCormen(20);
   root = testTree->insertCormen(10);
   root = testTree->insertCormen(30);
   root = testTree->insertCormen(15);
   root = testTree->insertCormen(25);
   root = testTree->insertCormen(9);
   root = testTree->insertCormen(32);
   root = testTree->insertCormen(23);
   root = testTree->insertCormen(29);
   root = testTree->insertCormen(34);
   root = testTree->insertCormen(39);
   root = testTree->insertCormen(42);
   root = testTree->insertCormen(17);
   root = testTree->insertCormen(13);
   root = testTree->insertCormen(5);
   cout << endl << "in order traverse..." << endl << endl;
   testTree->inOrderTraverse(testTree->getRoot());
   cout << endl;
   cout << endl << "root node value = " << testTree->getRoot()->getData()
      << "  color = " << convertColor(testTree->getRoot()->getColor()) 
      << endl << endl;

   cout << "finding node 15 : " << endl << endl;
   RBTreeNode* node = testTree->search(root, 15);
   if (node != NULL) {
      cout << "node found!..." << " value = " << node->getData() << 
         "  color = " << convertColor(node->getColor()) << endl << endl;
   }

   cout << "deleting node 15 : " << endl << endl;
   testTree->deleteNode(node);

   cout << endl << "in order traverse..." << endl << endl;
   testTree->inOrderTraverse(testTree->getRoot());
   cout << endl;

   //node = testTree->search(root, 32);

   //cout << "deleting node 32 : " << endl << endl;
   //testTree->deleteNode(node);

   //cout << endl << "in order traverse..." << endl << endl;
   //testTree->inOrderTraverse(testTree->getRoot());
   //cout << endl;

   delete testTree;
   
   return 0;
}
