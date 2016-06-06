/*****************************************************************************
 *
 * file CompiledDFA.cpp
 * the implementation file for the CompiledDFA class
 *
 * Shawn Quinn
 * quinnms1
 * 02/21/2015
 *
 ****************************************************************************/

#include <iostream>
#include <sstream>
#include "CompiledDFA.h"

/*****************************************************************************
 * constructor
 *
 * - argument - pointer to a FiniteStateMachine struct
 *
 ****************************************************************************/
CompiledDFA::CompiledDFA(FiniteStateMachine* someFSM)
{
   fSM = *someFSM;
   list<Transition>::iterator listIt;
   string key;
   for (listIt = fSM.transitions.begin(); listIt != fSM.transitions.end(); ++listIt) {
      key = hash((*listIt).source, (*listIt).transitionChar);
      stateMap[key] = (*listIt).destination;
   }
}

/*****************************************************************************
 * destructor
 *
 *
 ****************************************************************************/
CompiledDFA::~CompiledDFA()
{
}

/*****************************************************************************
 * method evaluate
 * - argument - string to test against NFA of current instance
 * - return - true if string recognized, false if string not recognized
 * - pseudocode -
 *       create temp variable to hold current state
 *       set current state to start state
 *       for each char in string
 *       	for each transition in the transition list
 *       		if a char matches the transitionChar
 *       			current state = destination
 *       search for current state in goal states
 *       return result of search
****************************************************************************/    
bool CompiledDFA::evaluate(string testStr)
{
   string::iterator chPtr;
   cout << "input string = \"";
   for (chPtr = testStr.begin(); chPtr < testStr.end(); chPtr++) {
      cout << *chPtr;
   }
   cout << "\"" << endl;
   char currCh;
   int currState;
   list<Transition>::iterator transIt;
   currState = fSM.startNode;
   string key;
   // iterate over the charcters in the string
   for (chPtr = testStr.begin(); chPtr != testStr.end(); ++chPtr) {
      currCh = *chPtr;
      key = hash(currState, currCh);
      if (stateMap.find(key) != stateMap.end() ) {
         currState = stateMap[key];
      }
   }
   // see if current state is a goal node
   if (fSM.goalNodes.find(currState) != fSM.goalNodes.end()) {
      cout << endl << "string accepted, found goal node " << currState
            << endl << endl;
		   return true;
   }
   cout << endl << "string rejected" << endl;
   return false;
}

string CompiledDFA::hash(int node, char ch)
{
   ostringstream keySS;
   keySS << node;
   string key = keySS.str();
   key += "->";
   key += ch;
   cout << "key = " << key << endl;

   return key;
}
