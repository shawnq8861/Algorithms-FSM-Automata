/*****************************************************************************
 *
 * file RedBlackTree.cpp
 *
 * Implementation file for class RedBlackTree
 *
 * Code written by:
 * Shawn Quinn
 * quinnms1
 * 01/24/2015
 *
 ****************************************************************************/

#include "RedBlackTree.h"

// Helper function
const char* convertColor(nodeColor ndColor)
{
   return (ndColor == red) ? "red" : "black";
}

/*****************************************************************************
 *
 * default constructor
 *
 ****************************************************************************/
RedBlackTree::RedBlackTree()
{
   root = NULL;
   numNodes = 0;
}

/*****************************************************************************
 *
 * destructor
 *
 ****************************************************************************/
RedBlackTree::~RedBlackTree()
{
}

/*****************************************************************************
 *
 * public method getRoot
 * - return the pointer to the root node
 *
 ****************************************************************************/
RBTreeNode* RedBlackTree::getRoot()
{
   return root;
}

/*****************************************************************************
 *
 * public method search
 * 
 * TREE-SEARCH(x, k)
 * 1 if x == NULL or k == x.key
 * 2      return x
 * 3 if k < x.key
 * 4     return TREE-SEARCH(x.left, k)
 * 5 else
 * 6     return TREE-SEARCH(x.right, k)
 *
 ****************************************************************************/
RBTreeNode* RedBlackTree::search(RBTreeNode* node, int newData)
{
   if (node == NULL || newData == node->getData()) {
      return node;
   }
   if (newData < node->getData()) {
      return search(node->getLeftChild(), newData);
   }
   else {
      return search(node->getRightChild(), newData);
   }
}

/*****************************************************************************
 *
 * public method insert
 * - non- recursively insert the data into the tree
 * - set color of new node to red
 * - return root
 *
 * RB-INSERT (T, z)
 * 1   y = T.nil
 * 2   x = T.root
 * 3   while x != T.nil
 * 4		y = x
 * 5		if z.key < x.key
 * 6			x = x.left
 * 7		else x = x.right
 * 8   z.p = y
 * 9   if y == T.nil
 * 10		T.root = z ́
 * 11  elseif z.key < y.key
 * 12		y.left = z ́
 * 13  else y.right = z ́
 * 14  z.left = T.nil
 * 15  z.right = T.nil
 * 16  z.color = RED
 * 17  RB-INSERT -FIXUP (T, z)
 *
 ****************************************************************************/
RBTreeNode* RedBlackTree::insert(RBTreeNode* rootNode, int newData)
{
	// allocate a new node to hold the data
	RBTreeNode* newNode = new RBTreeNode();
	newNode->setData(newData);
   // first check if root is NULL
   if (rootNode == NULL) {
      cout << "inserting new root node value: " << newData << endl;
      newNode->setColor(black);
      newNode->setParent(NULL);
      root = newNode;
      ++numNodes;
      return root;
   }
   else {
	   // create 2 temporary nodes to facilitate searching
	   RBTreeNode* y = NULL;	// 1
	   RBTreeNode* x = root;	// 2
      // search for insertion location
	   while ( x != NULL) {		// 3
		   y = x;				// 4
		   if (newNode->getData() < x->getData()) {	// 5
			   x = x->getLeftChild();	// 6
		   }
		   else {
			   x = x->getRightChild();	// 7
		   }
	   }
	   cout << "setting parent of new node, parent data =  " << y->getData()
			   << endl;
	   newNode->setParent(y);	// 8
	   if (newNode->getData() < y->getData()) {	// 11
		   cout << "inserting new left child node value = "
				   << newNode->getData() << endl;
		   y->setLeftChild(newNode);		// 12
	   }
	   else {
		   cout << "inserting new right child node value = "
		   				   << newNode->getData() << endl;
		   y->setRightChild(newNode);		// 13
	   }
	   newNode->setColor(red);				// 16
	   // next, rebalance as needed....
	   insertFixUpOld(newNode);
   }
   return root;

}

/*****************************************************************************
 *
 * public method insert
 * - non-recursively insert the data into the tree
 * - set color of new node to red
 * - return root
 *
 * RB-INSERT (T, z)
 * 1   y = T.nil
 * 2   x = T.root
 * 3   while x != T.nil
 * 4		y = x
 * 5		if z.key < x.key
 * 6			x = x.left
 * 7		else x = x.right
 * 8   z.p = y
 * 9   if y == T.nil
 * 10		T.root = z ́
 * 11  elseif z.key < y.key
 * 12		y.left = z ́
 * 13  else y.right = z ́
 * 14  z.left = T.nil
 * 15  z.right = T.nil
 * 16  z.color = RED
 * 17  RB-INSERT -FIXUP (T, z)
 *
 ****************************************************************************/
RBTreeNode* RedBlackTree::insertCormen(int newData)
{
	// allocate a new node to hold the data
	RBTreeNode* newNode = new RBTreeNode();
	newNode->setData(newData);
    cout << "inserting new node value: " << newData << endl;
    ++numNodes;
    RBTreeNode* y = NULL;			// 1
    RBTreeNode* x = root;			// 2
    // search for insertion location
	while ( x != NULL) {				// 3
		y = x;						// 4
		if (newNode->getData() < x->getData()) {	// 5
		   x = x->getLeftChild();	// 6
		}
		else {
		   x = x->getRightChild();	// 7
		}
	}
	newNode->setParent(y);			// 8
	if (y == NULL) {				// 9
	   root = newNode;				// 10
	}
	else if (newNode->getData() < y->getData()) {	// 11
	   cout << "inserting new left child node value = "
			   << newNode->getData() << endl;
	   y->setLeftChild(newNode);		// 12
	}
	else {
	   cout << "inserting new right child node value = "
	   				   << newNode->getData() << endl;
	   y->setRightChild(newNode);		// 13
	}
	newNode->setLeftChild(NULL);		// 14
	newNode->setRightChild(NULL);		// 15
	newNode->setColor(red);				// 16
	// next, fixup as needed....
	//insertFixUpOld(newNode);
   insertFixUp(newNode);
	return root;
}

/*****************************************************************************
 *
 * RB-INSERT-FIXUP(T.z)
 * 1 while  z.p.color == RED
 * 2		if  z.p == z.p.p.left
 * 3			y = z.p.p.right
 * 4			if y.color == RED
 * 5				z.p.color = BLACK		// case 1: z’s uncle y is red
 * 6				y.color = BLACK			// case 1
 * 7				z.p.p.color = RED		// case 1
 * 8				z = z.p.p				// case 1
 * 9			else                    // y is BLACK
 * 9           if  z == z.p.right
 *10					 z = z.p			// case 2: z’s uncle y is black and z is a right child
 *11					 LEFT-ROTATE(T,z)	// case 2 transform case 2 into case 3
 *12				z.p.color = BLACK		// case 3: z’s uncle y is black and z is a left child
 *13				z.p.p.color = RED		// case 3
 *14				RIGHT-ROTATE(T,z.p.p)	// case 3
 *
 *15		else z.p == z.p.p.right
 *       (same as then clause with “right” and “left” exchanged)
 * 3			y = z.p.p.left
 * 4			if y.color == RED
 * 5				z.p.color = BLACK		// case 1
 * 6				y.color = BLACK			// case 1
 * 7				z.p.p.color = RED		// case 1
 * 8				z = z.p.p				// case 1
 * 9			else if  z == z.p.left
 *10					 z = z.p			// case 2
 *11					 RIGHT-ROTATE(T,z)	// case 2
 *12				z.p.color = BLACK		// case 3
 *13				z.p.p.color = RED		// case 3
 *14				LEFT-ROTATE(T,z.p.p)	// case 3
 *
 *16 T.root.color = BLACK
 *
 ****************************************************************************/
void RedBlackTree::insertFixUp(RBTreeNode* node)
{
   RBTreeNode* y = NULL;
   // while  z.p.color == RED
   while (node != root && node->getParent()->getColor() == red) {
   // 	RBTreeNode* y = NULL;
         // 2 if  z.p == z.p.p.left
        if (node->getParent() == node->getParent()->getParent()->getLeftChild()) {
           cout << endl << "if block..." << endl;
           // 3 y = z.p.p.right
           
           y = node->getParent()->getParent()->getRightChild();
           
           // 4 if y.color == RED
           if (y != NULL && y->getColor() == red) { // y.color == RED
              
              //  5 z.p.color = BLACK		// case 1
              node->getParent()->setColor(black);
              // 6 y.color = BLACK			// case 1
              y->setColor(black);
              // 7 z.p.p.color = RED		// case 1
              node->getParent()->getParent()->setColor(red);
              // 8 z = z.p.p				// case 1
              node = node->getParent()->getParent();
           }
           // 9 else if  z == z.p.right
           else { // y.color == BLACK
              // if  z == z.p.right
              if (node == node->getParent()->getRightChild()) {
                 // 10 z = z.p	
                 node = node->getParent();
                 // 11 LEFT-ROTATE(T,z)
                 leftRotate(node);
              } 
              // 12 z.p.color = BLACK
              node->getParent()->setColor(black);
              // 13 z.p.p.color = RED
              node->getParent()->getParent()->setColor(red);
              // 14 RIGHT-ROTATE(T,z.p.p)
              rightRotate(node->getParent()->getParent());
           }
        }
        else { // 2 z.p == z.p.p.right
           cout << endl << "else block..." << endl;
           // 3 y = z.p.p.left
           y = node->getParent()->getParent()->getLeftChild();
           // 4 if y.color == RED
           if (y != NULL && y->getColor() == red) { // y.color == RED
              //  5 z.p.color = BLACK		// case 1
              node->getParent()->setColor(black);
              // 6 y.color = BLACK			// case 1
              y->setColor(black);
              // 7 z.p.p.color = RED		// case 1
              node->getParent()->getParent()->setColor(red);
              // 8 z = z.p.p				// case 1
              node = node->getParent()->getParent();
           }
           // 9 else if  z == z.p.left
           else { // y.color == BLACK
              // if  z == z.p.left
              if (node == node->getParent()->getLeftChild()) {
                 // 10 z = z.p	
                 node = node->getParent();
                 // 11 RIGHT-ROTATE(T,z)
                 rightRotate(node);
              } 
              // 12 z.p.color = BLACK
              node->getParent()->setColor(black);
              // 13 z.p.p.color = RED
              node->getParent()->getParent()->setColor(red);
              // 14 LEFT-ROTATE(T,z.p.p)
              leftRotate(node->getParent()->getParent());
           }
        }
    }
    root->setColor(black);	//keep root always black
}

/*****************************************************************************
 * public method insertRebalance(RBTreeNode* newNode)
 *
 * - 1) Do the following if color of newNode’s parent is not BLACK or
 * 		newNode is not root.
 *		a) If newNode's uncle is red (grand parent must have been black from
 *		   property 4)
 *			(i) Change color of parent and uncle to black.
 *			(ii) set color of grand parent to red.
 *			(iii) set newNode = newNode’s grandparent, repeat steps 2 and
 *				  3 for new newNode.
 *		b) If newNode’s uncle is black, then there can be four configurations
 *		   for newNode,
 *		   newNode’s parent (p) and newNode’s grandparent (g).
 *			(i) Left Left Case (p is left child of g and newNode is left
 *				 child of p)
 *			(ii) Left Right Case (p is left child of g and newNode is right
 *				  child of p)
 *			(iii) Right Right Case (Mirror of case i)
 *			(iv)  Right Left Case (Mirror of case ii)
 * - 2) If newNode is root, change color of newNode to black (black height
 * 	  of complete	tree increases by 1).
 *
 ****************************************************************************/
void RedBlackTree::insertFixUpOld(RBTreeNode* node)
{
    // iterate until z is not the root and z's parent color is red
    while (node != root && node->getParent()->getColor() == red) {	// 1
    	RBTreeNode* y = NULL;

        // Find uncle and store uncle in y
        if (node->getParent() == node->getParent()->getParent()->getLeftChild())
            y = node->getParent()->getParent()->getRightChild();
        else
            y = node->getParent()->getParent()->getLeftChild();

        // If uncle is RED, do following
        // (i)  Change color of parent and uncle to black
        // (ii) Change color of grandparent to red
        // (iii) set node to grandparent
        if (y->getColor() == red)
        {
            y->setColor(black);
            node->getParent()->setColor(black);
            node->getParent()->getParent()->setColor(red);
            node = node->getParent()->getParent();
        }

        // Uncle is BLACK, there are four cases (LL, LR, RL and RR)
        else
        {
            // Left-Left (LL) case, do following
            // (i)  Swap color of parent and grandparent
            // (ii) Right Rotate Grandparent
            if (node->getParent() == node->getParent()->getParent()->getLeftChild() &&
                node == node->getParent()->getLeftChild())
            {
                nodeColor clr = node->getParent()->getColor();
                node->getParent()->setColor(node->getParent()->getParent()->getColor());
                node->getParent()->getParent()->setColor(clr);
                rightRotate(node->getParent()->getParent());
            }

            // Left-Right (LR) case, do following
            // (i)  Swap color of current node  and grandparent
            // (ii) Left Rotate Parent
            // (iii) Right Rotate Grand Parent
            if (node->getParent() == node->getParent()->getParent()->getLeftChild() &&
            		node == node->getParent()->getRightChild())
            {
            	nodeColor clr = node->getColor();
            	node->setColor(node->getParent()->getParent()->getColor());
            	node->getParent()->getParent()->setColor(clr);
               leftRotate(node->getParent());
               rightRotate(node->getParent()->getParent());
            }

            // Right-Right (RR) case, do following
            // (i)  Swap color of parent and grandparent
            // (ii) Left Rotate Grandparent
            if (node->getParent() == node->getParent()->getParent()->getRightChild() &&
            		node == node->getParent()->getRightChild()) {

            	nodeColor clr = node->getParent()->getColor();
            	node->getParent()->setColor(node->getParent()->getParent()->getColor());
            	node->getParent()->getParent()->setColor(clr);
               leftRotate(node->getParent()->getParent());
            }

            // Right-Left (RL) case, do following
            // (i)  Swap color of current node  and grandparent
            // (ii) Right Rotate Parent
            // (iii) Left Rotate Grand Parent
            if (node->getParent() == node->getParent()->getParent()->getRightChild() &&
            		node == node->getParent()->getLeftChild())
            {
            	nodeColor clr = node->getColor();
            	node->setColor(node->getParent()->getParent()->getColor());
            	node->getParent()->getParent()->setColor(clr);
               rightRotate(node->getParent());
               leftRotate(node->getParent()->getParent());
            }
        }
    }
    root->setColor(black);	//keep root always black
}

/* Left rotation pseudocode
 *
 * LEFT -ROTATE (T, x)
 * 1  y = x.right			// set y
 * 2  x.right = y.left		// turn y’s left subtree into x’s right subtree
 * 3  if y.left != T.nil
 * 4	   y.left.p = x
 * 5  y.p = x.p				// link x’s parent to y
 * 6  if x.p == T.nil
 * 7	   T.root = y
 * 8  elseif x == x.p.left
 * 9	   x.p.left = y
 * 10 else x.p.right = y
 * 11 y.left = x			// put x on y’s left
 * 12 x.p = y
 *
 */
void RedBlackTree::leftRotate(RBTreeNode* node)
{
	RBTreeNode* y = node->getRightChild();	// 1
	node->setRightChild(y->getLeftChild());	// 2
    if (y->getLeftChild() != NULL)			// 3
    	y->getLeftChild()->setParent(node);	// 4
    y->setParent(node->getParent());		// 5
    if (node->getParent() == NULL) {		// 6
        root = y;							// 7
    }
    else if (node == node->getParent()->getLeftChild()) {	// 8
        node->getParent()->setLeftChild(y);					// 9
    }
    else {
    	node->getParent()->setRightChild(y);				// 10
    }
    y->setLeftChild(node);					// 11
    node->setParent(y);						// 12
}

// Right Rotation
/*
 * Right rotation pseudocode
 *
 * RIGHT -ROTATE (T, y)
 * 1  x = y.left			// set X
 * 2  y.left = x.right		// turn X’s right subtree into Y’s left subtree
 * 3  if x.right != T.nil
 * 4	   x.right.p = y
 * 5  x.p = y.p				// link y’s parent to x
 * 6  if y.p == T.nil
 * 7	   T.root = x
 * 8  elseif y == y.p.right
 * 9	   y.p.right = x
 * 10 else y.p.left = x
 * 11 x.right = y			// put y on x’s right
 * 12 y.p = x
 *
 */

void RedBlackTree::rightRotate(RBTreeNode* node)
{
	// 1
   RBTreeNode* x = node->getLeftChild();

   // 2
   node->setLeftChild(x->getRightChild());

   // 3
   if (x->getRightChild() != NULL) {
	   // 4
	   x->getRightChild()->setParent(node);
   }
   x->setParent(node->getParent());	// 5

   if (node->getParent() == NULL) {	// 6
	   root = x;		// 7
   }
   else if (node == node->getParent()->getRightChild()) {	// 8
	   // 9
	   node->getParent()->setRightChild(x);
   }
   // 10
   else node->getParent()->setLeftChild(x);
   // 11
   x->setRightChild(node);
   // 12
   node->setParent(x);
}

/*****************************************************************************
 * method transplant
 *
 * RB-TRANSPLANT(T, u, v)
 * 1 if u.p == T.nil
 * 2 	T.root = v
 * 3 else if u == u.p.left
 * 4 	u.p.left = v
 * 5 else
 * 		u.p.left = v
 * 		v.p = u.p
 *
 ****************************************************************************/
void RedBlackTree::transplant(RBTreeNode* u, RBTreeNode* v)
{
   if(u->getParent() == NULL) {
      root = v;
	}
   else if(u == u->getParent()->getLeftChild()) {
      u->getParent()->setLeftChild(v);
	}
	else {
      u->getParent()->setLeftChild(v);
      v->setParent(u->getParent());
	}
}

/*****************************************************************************
 * method treeMinimum
 *
 * TREE-MINIMUM(x)
 * 1 while x.left != NULL
 * 2     x = x.left
 * 3 return x
 *
 ****************************************************************************/
RBTreeNode* RedBlackTree::treeMinimum(RBTreeNode* x)
{
   while(x->getLeftChild() != NULL) {
      x = x->getLeftChild();
   }
   return x;
}

/*****************************************************************************
 * method delete
 *
 * - non-recursively delete a node
 *
 * RB-DELETE(T,z)
 * 1 y = z
 * 2 y-original-color = y.color
 * 3 if z.left == T.nil
 * 4 	   x = z.right
 * 5 	   RB-TRANSPLANT(T, z, z.right)
 * 6 elseif z.right == T.nil
 * 7	   x = z.left
 * 8	   RB-TRANSPLANT(T, z, z.left)
 * 9 else y = TREE-MINIMUM(z.right)
 * 10	   y-original-color = y.color
 * 11	   x = y.right
 * 12	   if y.p == z
 * 13		   x.p = y
 * 14	   else RB-TRANSPLANT(T, y, y.right)
 * 15		   y.right = z.right
 * 16		   y.right.p = y
 * 17	   RB-TRANSPLANT(T, z, y)
 * 18	   y.left = z.left
 * 19	   y.left.p = y
 * 20	   y.color = z.color
 * 21 if y-original-color == BLACK
 * 22	   RB-DELETE-FIXUP(T, x)
 *
 ****************************************************************************/
void RedBlackTree::deleteNode(RBTreeNode* node)
{
   RBTreeNode* x = NULL;
	RBTreeNode* y = node;   // 1 y = z
	nodeColor yOrigColor = y->getColor();  // 2 y-original-color = y.color
   if(node->getLeftChild() == NULL) { // 3 if z.left == T.nil
      // 4 x = z.right
      RBTreeNode* x = node->getRightChild();
      // 5 RB-TRANSPLANT(T, z, z.right)
      transplant(node, node->getRightChild());
	}
   else if(node->getRightChild() == NULL) { // 6 elseif z.right == T.nil
      // 7 x = z.left
      x = node->getLeftChild();
      // 8 RB-TRANSPLANT(T, z, z.left)
      transplant(node, node->getLeftChild());
	}
	else {
      // 9 y = TREE-MINIMUM(z.right)
      y = treeMinimum(node->getRightChild());
      // 10 y-original-color = y.color
      yOrigColor = y->getColor();
      // 11 x = y.right
      x = y->getRightChild();
      if(y->getParent() == node) { // 12 if y.p == z
         // 13 x.p = y
         x->setParent(y);
		}
		else {
         // 14 RB-TRANSPLANT(T, y, y.right)
         transplant(y, y->getRightChild());
         // 15 y.right = z.right
         y->setRightChild(node->getRightChild());
         // 16 y.right.p = y
         y->getRightChild()->setParent(y);
		}
      // 17 RB-TRANSPLANT(T, z, y)
      transplant(node, y);
      // 18 y.left = z.left
      y->setLeftChild(node->getLeftChild());
      // 19 y.left.p = y
      y->getLeftChild()->setParent(y);
      // 20 y.color = z.color
      y->setColor(node->getColor());

	}
   if (yOrigColor == black ) { // 21 if y-original-color == BLACK
      // 22 RB-DELETE-FIXUP(T, x)
      deleteFixUp(x);
   }
}

/*****************************************************************************
 * method deleteFixUp
 *
 * RB-DELETE-FIXUP(T, x)
 * 1 while x != T.root and x.color == BLACK
 * 2     if x == x.p.left
 * 3        w = x.p.right
 * 4        if w.color == RED
 * 5           w.color = BLACK                  // case 1: x’s sibling w is red
 * 6           x.p.color = RED                  // case 1
 * 7           LEFT-ROTATE(T, x.p)              // case 1
 * 8           w = x.p.right                    // case 1 convert case 1 into case 2, 3, or 4
 * 9        if w.left.color == BLACK and w.right.color == BLACK
 *10           w.color = RED                    // case 2: x’s sibling w is black, and both of w’s children are black
 *11           x = x.p                          // case 2
 *12        else 
 *12              if w.right.color == BLACK
 *13              w.left.color = BLACK          // case 3: x’s sibling w is black, w’s left child is red, and w’s right child is black
 *14              w.color = RED                 // case 3
 *15              RIGHT-ROTATE(T, w)            // case 3
 *16              w = x.p.right                 // transform case 3 into case 4        
 *17           w.color = x.p.color              // case 4: x’s sibling w is black, and w’s right child is red
 *18           x.p.color = BLACK                // case 4
 *19           w.right.color = BLACK            // case 4
 *20           LEFT-ROTATE(T, x.p)              // case 4
 *21           x = T.root                       // case 4
 *22     else (same as then clause with “right” and “left” exchanged)
 * 3        w = x.p.left
 * 4        if w.color == RED
 * 5           w.color = BLACK
 * 6           x.p.color = RED
 * 7           RIGHT-ROTATE(T, x.p)
 * 8           w = x.p.left
 * 9        if w.right.color == BLACK and w.left.color == BLACK
 *10           w.color = RED
 *11           x = x.p
 *12        else if w.left.color == BLACK
 *13              w.right.color = BLACK
 *14              w.color = RED
 *15              LEFT-ROTATE(T, w)
 *16              w = x.p.left
 *17           w.color = x.p.color
 *18           x.p.color = BLACK
 *19           w.left.color = BLACK
 *20           RIGHT-ROTATE(T, x.p)
 *21           x = T.root

 *23 x.color = BLACK
 *
 ****************************************************************************/
void RedBlackTree::deleteFixUp(RBTreeNode* node)
{
   RBTreeNode* w = NULL;
   // 1 while x != T.root and x.color == BLACK
   while(node != root && node->getColor() == black) {
      if(node == node->getParent()->getLeftChild()) { // 2 if x == x.p.left
         w = node->getParent()->getRightChild(); // 3 w = x.p.right
         if(w->getColor() == red) { // 4 if w.color == RED
            // 5 w.color = BLACK
            w->setColor(black);
            // 6 x.p.color = RED
            node->getParent()->setColor(red);
            // 7 LEFT-ROTATE(T, x.p)
            leftRotate(node->getParent());
            // 8 w = x.p.right
            w = node->getParent()->getRightChild();
         }
         // 9 if w.left.color == BLACK and w.right.color == BLACK
         if(w->getLeftChild()->getColor() == black 
            && w->getRightChild()->getColor() == black) {
               // 10 w.color = RED
               w->setColor(red);
               // 11 x = x.p
               node = node->getParent();
         }
         else { // 12
            // 12 if w.right.color == BLACK
            if (w->getRightChild()->getColor() == black) {
               // 13 w.left.color = BLACK
               w->getLeftChild()->setColor(black);
               // 14 w.color = RED
               w->setColor(red);
               // 15 RIGHT-ROTATE(T, w)
               rightRotate(w);
               // 16 w = x.p.right
               w = node->getParent()->getRightChild();
            }
            // 17 w.color = x.p.color
            w->setColor(node->getParent()->getColor());
            // 18 x.p.color = BLACK
            node->getParent()->setColor(black);
            // 19 w.right.color = BLACK
            w->getRightChild()->setColor(black);
            // 20 LEFT-ROTATE(T, x.p)
            leftRotate(node->getParent());
            // 21 x = T.root
            node = root;
         } 
      }

      // (same as then clause with “right” and “left” exchanged)
      else { // 22
         w = node->getParent()->getLeftChild(); // 3 w = x.p.left
         if(w->getColor() == red) { // 4 if w.color == RED
            // 5 w.color = BLACK
            w->setColor(black);
            // 6 x.p.color = RED
            node->getParent()->setColor(red);
            // 7 RIGHT-ROTATE(T, x.p)
            rightRotate(node->getParent());
            // 8 w = x.p.left
            w = node->getParent()->getLeftChild();
         }
         // 9 if w.right.color == BLACK and w.left.color == BLACK
         if(w->getRightChild()->getColor() == black 
            && w->getLeftChild()->getColor() == black) {
               // 10 w.color = RED
               w->setColor(red);
               // 11 x = x.p
               node = node->getParent();
         }
         else { // 12
            // 12 if w.left.color == BLACK
            if (w->getLeftChild()->getColor() == black) {
               // 13 w.right.color = BLACK
               w->getRightChild()->setColor(black);
               // 14 w.color = RED
               w->setColor(red);
               // 15 LEFT-ROTATE(T, w)
               leftRotate(w);
               // 16 w = x.p.left
               w = node->getParent()->getLeftChild();
            }
            // 17 w.color = x.p.color
            w->setColor(node->getParent()->getColor());
            // 18 x.p.color = BLACK
            node->getParent()->setColor(black);
            // 19 w.left.color = BLACK
            w->getLeftChild()->setColor(black);
            // 20 RIGHT-ROTATE(T, x.p)
            rightRotate(node->getParent());
            // 21 x = T.root
            node = root;
         } 
      }
   }
   // 23 x.color = BLACK
   node->setColor(black);
}

/*****************************************************************************
 * method inOrderTraverse
 *
 * - perform recursive in order traversal of a balanced BST
 *
 ****************************************************************************/
void RedBlackTree::inOrderTraverse(RBTreeNode* node)
{
   if ( node == NULL ) {
      return;
   }
   // recursive call on left child node
   inOrderTraverse(node->getLeftChild());

   // "visit" the root node by pronting it's value
   cout << "node color: "<< convertColor(node->getColor()) << " node data: " 
      << node->getData();
   if (node != root) {
	   cout << " parent color: " << convertColor(node->getParent()->getColor())
			   << " parent data: " << node->getParent()->getData() << endl;
   }
   else {
	   cout << " node is root" << endl;
   }

   // recursive call on right child node
   inOrderTraverse(node->getRightChild());
}
