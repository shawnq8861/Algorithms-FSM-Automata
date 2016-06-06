/*****************************************************************************
 *
 * file dataStructsHW5.h
 * interface declaration for the Balanced Binary Search Tree Functions
 *
 * Shawn Quinn
 * quinnms1
 * 02/21/2015
 *
 ****************************************************************************/

#ifndef DATA_STRUCTS_HW5_H
#define DATA_STRUCTS_HW5_H

#include <set>
#include <list>

using namespace std;

const char epsilon = '\0';

struct DFANode {
   set<int> nodes;
   bool checked;
};

struct Transition {
   int source; 
   char transitionChar; 
   int destination; 
};

struct DFAFromNFAeTrans {
   set<int> sourceNodes;
   char transitionChar; 
   set<int> destinationNodes;
};

struct FiniteStateMachine { 
   set<int> nodes; 
   int startNode; 
   set<int> goalNodes; 
   list<Transition> transitions; 
};

#endif
