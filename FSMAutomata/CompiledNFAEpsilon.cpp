/*****************************************************************************
 *
 * file CompiledNFAEpsilon.cpp
 * the implementation file for the CompiledNFAEpsilon class
 *
 * Shawn Quinn
 * quinnms1
 * 02/21/2015
 *
 ****************************************************************************/

#include <iostream>
#include <sstream>
#include <map>
#include "CompiledNFAEpsilon.h"

/*****************************************************************************
 * constructor
 *
 * - argument - pointer to a FiniteStateMachine struct
 *
 ****************************************************************************/
CompiledNFAEpsilon::CompiledNFAEpsilon(FiniteStateMachine* someFSM)
{
   fSM = *someFSM;
   set<int>::iterator nextNode;
   list<Transition>::iterator nextTransition;
   set<string> keys;
   set<string>::iterator nextKey;
   string key;
   for (nextNode = fSM.nodes.begin(); nextNode != fSM.nodes.end(); 
      ++nextNode) {
      for (nextTransition = fSM.transitions.begin(); nextTransition 
         != fSM.transitions.end(); ++nextTransition) {
            if ( (*nextTransition).source == *nextNode ) {
               keys.insert( hash(*nextNode, (*nextTransition).transitionChar) );
            }
      }
   }  
   for (nextKey = keys.begin(); nextKey != keys.end(); ++nextKey) {
      set<int> nodeSetForKey;
      for (nextTransition = fSM.transitions.begin(); nextTransition 
         != fSM.transitions.end(); ++nextTransition) {
            if ( *nextKey == hash((*nextTransition).source, (*nextTransition).transitionChar) ) {
               nodeSetForKey.insert((*nextTransition).destination);
            }
      }
      stateMap[*nextKey] = nodeSetForKey;
   }
}

/*****************************************************************************
 * destructor
 *
 *
 ****************************************************************************/
CompiledNFAEpsilon::~CompiledNFAEpsilon()
{
}

/*****************************************************************************
 * method evaluate
 * - argument - string to test against NFA of current instance
 * - return - true if string recognized, false if string not recognized
 * - pseudocode -
 *       create empty set to hold current states
 *       insert start state into current state set
 *       for each char in string
 *          for each state in the current state set
 *             for each transition in the transition list
 *                if a transition exists for a state, including epsilon
 *                transitions, an item is added to the new state set
 *          assign new set to current set
 *       search for goal states in the current state set
 *       return result of search
 ****************************************************************************/
bool CompiledNFAEpsilon::evaluate(string testStr)
{
   string::iterator chPtr;
   cout << "input string = \"";
   for (chPtr = testStr.begin(); chPtr < testStr.end(); chPtr++) {
      cout << *chPtr;
   }
   cout << "\"" << endl;
   char currCh;
   set<int> currStates;
   set<int>::iterator stateIt;
   list<Transition>::iterator transIt;
   currStates.insert(0);
   string key;
   // iterate over the charcters in the string
   for (chPtr = testStr.begin(); chPtr != testStr.end(); ++chPtr) {
      currCh = *chPtr;
      for (stateIt = currStates.begin(); stateIt != currStates.end();
    		  ++stateIt) {
         key = hash(*stateIt, currCh);
         if (stateMap.find(key) != stateMap.end() ) {           
            currStates = stateMap[key];
          }
      }
   }
   // see if goal state is in currStates
   for (stateIt = fSM.goalNodes.begin(); stateIt != fSM.goalNodes.end();
		   ++stateIt) {
	   if (currStates.find(*stateIt) != currStates.end()) {
		   cout << endl << "string accepted, found goal node " << *stateIt 
            << endl << endl;
		   return true;
	   }
   }
   cout << endl << "string rejected" << endl;
   return false;
}

/*****************************************************************************
 * method nFAeToDFA
 * - argument - string to test against NFA of current instance
 * - return - true if string recognized, false if string not recognized
 * - pseudocode -
 *   compute start state of DFA:
 *     - find e-closure of NFAe start node
 *       create an empty set to represent DFA start set
 *       insert NFA start node into set
 *       while new nodes are being added to set
 *          for each transition in transition list
 *             if source node is in the set && char == epsilon
 *                insert destination node into set
 *          node = next node in set
 *   compute additional states of DFA from a set of source nodes for a 
 *   given transition char:
 *     - find the move set from the destination nodes of moves for the 
 *       given set of source nodes
 *       create an empty set to represent the NFAe move set
 *       for each node in the source set
 *	         for each transition in transition list
 *		         if source == source && transitionChar == char
 *			         insert destination node into set
 *   compute e-closure of additional state:
 *     - find e-closure of NFAe start node
 *       create an empty set to represent DFA start set
 *       for each node in the move set
 *          insert NFA start node into set
 *          while new nodes are being added to set
 *             for each transition in transition list
 *                if source node is in the set && char == epsilon
 *                   insert destination node into set
 *             node = next node in set
 *
 *       1. find start set
 *       2. add start set to list of sets
 *       3. set current set to start set
 *       4. while current set is not checked
 *       5.    for each trans char
 *       6.       find move set
 *       7.       find epsilon closure
 *       8.          if set does not already exist
 *       9.             add to list of sets
 *       10.      complete the transition
 *       11.      add the transisition to the translist
 *       10.   change current set to checked
 *       11.   set current set to next set
 *       12. assign goal state
 *
 ****************************************************************************/
 FiniteStateMachine CompiledNFAEpsilon::nFAeToDFA(void)
{
//------------- DFA start node is the epsilon closure of NFAe start node -----
   set<int> DFAStart;
   DFAStart.insert(fSM.startNode);
   list<Transition>::iterator transIt;
   int setSize = 0;
   while ((int)DFAStart.size() > setSize) {
      setSize = DFAStart.size();
      for (transIt = fSM.transitions.begin(); transIt != fSM.transitions.end(); 
         ++transIt) {
         if ( (DFAStart.find((*transIt).source) != DFAStart.end()) 
            && 
            ((*transIt).transitionChar == epsilon) ) {
            DFAStart.insert((*transIt).destination);
         }
      }
   }
   set<int>::iterator setIt;
   cout << endl << "start set..." << endl << endl;
   for (setIt = DFAStart.begin(); setIt != DFAStart.end(); ++setIt) {
      cout << "node = " << *setIt << endl;
   }   
   DFAFromNFAeTrans dFATrans; // variable to hold a DFA transaction
   list<DFAFromNFAeTrans> dFATransList;   // list to hold DFA transactions
   list<DFANode> nodeList; // list to hold DFA nodes
//------------- assign the DFA start node set --------------------------------
   DFANode currNode;
   currNode.checked = false;
   DFANode tempNode;
   tempNode.checked = false;
   currNode.nodes = DFAStart;
   nodeList.push_back(currNode);
   cout << endl << "initial list size = " << nodeList.size() << endl;
   list<DFANode>::iterator nodeListIt = nodeList.begin();
   int loopCount = 0;
   while ( currNode.checked == false) {
      cout << "current node:" << endl << endl;
      for (setIt = currNode.nodes.begin(); setIt != currNode.nodes.end(); ++setIt) {
         cout << "node = " << *setIt << endl;
      }
//------------- move set for current transitionChar --------------------------
      set<int> NFAeMove;
//------------- epsilon closure for current move set -------------------------
      set<int> DFANewNode;
      set<char> transCharSet;
      list<Transition>::iterator transIt2;
      // start of outer for loop
      for (transIt2 = fSM.transitions.begin(); transIt2 != fSM.transitions.end();
            ++transIt2) {
         cout << "transition char = " << (*transIt2).transitionChar << endl << endl;   
         // create a variable to hold each transition char
         char currChar;
         currChar = (*transIt2).transitionChar;
         // start of outer if
	      if (currChar != epsilon && (transCharSet.find(currChar) == transCharSet.end())) {
            // keep track of chars we have already looked at
		      transCharSet.insert(currChar);
            cout << endl << "currChar = " << currChar << endl;
//-------------- build move set for currChar ---------------------------------
            NFAeMove = buildMoveSet(currNode.nodes, currChar);
//-------------- determine epsilon closure for current move set --------------
            DFANewNode = epsilonClosure(NFAeMove);
            tempNode.nodes = DFANewNode;
            // verify that node does not already exist
            list<DFANode>::iterator searchIt;
            bool newNode = true;
            for (searchIt = nodeList.begin(); searchIt != nodeList.end(); ++searchIt) {
               if ((*searchIt).nodes == tempNode.nodes) {
                  newNode = false;
                  break;
               }
            }
            if (newNode == true) {
               nodeList.push_back(tempNode);
               cout << endl << "list size = " << nodeList.size() << endl;
            }
//------------------------- build the transition -----------------------------
         dFATrans.sourceNodes = currNode.nodes;
         dFATrans.transitionChar = currChar;
         dFATrans.destinationNodes = tempNode.nodes;
//------------------------- add it to the list -------------------------------
         dFATransList.push_back(dFATrans);
	      }// end of outer if 
      }// end of outer for loop    
      currNode.checked = true;   
      // if we are at the end of the list, we are done
      ++nodeListIt;
      if (nodeListIt != nodeList.end()) {
         currNode = *(nodeListIt);
      }
      cout << "next node:" << endl << endl;
      for (setIt = currNode.nodes.begin(); setIt != currNode.nodes.end(); ++setIt) {
         cout << "node = " << *setIt << endl;
      }
      ++loopCount;
      cout << endl << "loop count = " << loopCount << endl;
   }// end of outer while loop

   // convert DFAFromNFAeTrans list to a Transition list
   // convert DFA nodes to int nodes
   
   set<int> nodes;
   int startNode = 1;
   set<int> goalNodes;
   list<Transition> transitions;

   int i = startNode;
//------------- map node sets to int nodes -----------------------------------
// iterate over goal nodes to determine if any match nodes in current node set
//----------------------------------------------------------------------------
   map<set<int>, int> nodeMap;
   for (nodeListIt = nodeList.begin(); nodeListIt != nodeList.end(); ++nodeListIt) {
      nodeMap[(*nodeListIt).nodes] = i;
      nodes.insert(i);
      for (setIt = fSM.goalNodes.begin(); setIt != fSM.goalNodes.end(); ++setIt) {
         if ((*nodeListIt).nodes.find(*setIt) != (*nodeListIt).nodes.end()) {
            goalNodes.insert(i);
         }
      }
      ++i;
   }
   cout << endl << "final list size = " << nodeList.size() << endl;

//------------- iterate over the transition list, map set nodes to int nodes--
   list<DFAFromNFAeTrans>::iterator dFATransListIt;
   Transition tempTrans;
   for (dFATransListIt = dFATransList.begin(); dFATransListIt != dFATransList.end(); ++dFATransListIt) {
      tempTrans.source = nodeMap[(*dFATransListIt).sourceNodes];
      tempTrans.transitionChar = (*dFATransListIt).transitionChar;
      tempTrans.destination = nodeMap[(*dFATransListIt).destinationNodes];
      transitions.push_back(tempTrans);
   }

   FiniteStateMachine tempFSM;
   tempFSM.nodes = nodes;
   tempFSM.startNode = startNode;
   tempFSM.goalNodes = goalNodes;
   tempFSM.transitions = transitions;

   return tempFSM;
}

/*****************************************************************************
 * method buildMoveSet
 * - argument - starting set of nodes, transition character
 * - return - set of nodes
 * - pseudocode -
 *       create an empty set to hold move nodes
 *          for each state in the input state set
 *             for each transition in the transition list
 *                if the source node matches the current set node and the 
 *                transition char matches the current transition char
 *                   insert the destination node into the move set
 *       return the move set
 ****************************************************************************/
set<int> CompiledNFAEpsilon::buildMoveSet(set<int> startSet, char currChar)
{
   set<int> NFAeMove;
   set<int>::iterator setIt;
   list<Transition>::iterator transIt;
   for (setIt = startSet.begin(); setIt != startSet.end(); ++setIt) {
      for (transIt = fSM.transitions.begin(); transIt != fSM.transitions.end();
            ++transIt) {
         if ( *setIt == (*transIt).source
            && 
            (*transIt).transitionChar == currChar ) {
               NFAeMove.insert((*transIt).destination);
         }
      }
   }
   cout << endl << "move set..." << endl << endl;
   for (setIt = NFAeMove.begin(); setIt != NFAeMove.end(); ++setIt) {
      cout << "node = " << *setIt << endl;
   }
   return NFAeMove;
}

/*****************************************************************************
 * method epsilonClosure
 * - argument - a move set of nodes as returned by buildMoveSet
 * - return - set of nodes
 * - pseudocode -
 *       create an empty set to hold new DFA nodes
 *          for each state in the input state set
 *             insert the current node
 *             while new nodes are being added to set
 *             for each transition in transition list
 *                if source node is in the set && char == epsilon
 *                   insert destination node into set
 *       return the DFA set
 ****************************************************************************/
set<int> CompiledNFAEpsilon::epsilonClosure(set<int> moveSet)
{
   set<int> DFANewNode;  
   set<int>::iterator setIt;
   list<Transition>::iterator transIt;
   int setSize = 0;
   for (setIt = moveSet.begin(); setIt != moveSet.end(); ++setIt)
   {   
      DFANewNode.insert(*setIt);
      while ((int)DFANewNode.size() > setSize) {
         setSize = DFANewNode.size();
         for (transIt = fSM.transitions.begin(); transIt != fSM.transitions.end(); 
               ++transIt) {
            if ( (DFANewNode.find((*transIt).source) != DFANewNode.end()) 
               && 
               ((*transIt).transitionChar == epsilon) ) {
               DFANewNode.insert((*transIt).destination);
            }
         }
      }   
   }
   cout << endl << "new node set..." << endl << endl;
   for (setIt = DFANewNode.begin(); setIt != DFANewNode.end(); ++setIt) {
      cout << "node = " << *setIt << endl;
   }
   return DFANewNode;
}

string CompiledNFAEpsilon::hash(int node, char charValue)
{
   ostringstream keyStringStream;
   keyStringStream << node;
   string key = keyStringStream.str();
   key += "->";
   key += charValue;
   cout << "key = " << key << endl;

   return key;
}