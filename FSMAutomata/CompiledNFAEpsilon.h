/*****************************************************************************
 *
 * file CompiledNFAEpsilon.h
 * interface declaration for the Non-deterministic Finite Automata epsilon
 * (NFAe) class
 *
 * Shawn Quinn
 * quinnms1
 * 02/21/2015
 *
 ****************************************************************************/

#ifndef COMPILED_NFA_EPSILON_H
#define COMPILED_NFA_EPSILON_H

#include "dataStructsHW5.h"
#include <string>
#include <unordered_map>

class CompiledNFAEpsilon
{
public:
   // constructor
   // - argument - pointer to a FiniteStateMachine struct
   CompiledNFAEpsilon(FiniteStateMachine* someFSM);

   // destructor
   // - 
   ~CompiledNFAEpsilon();

   // method evaluate
   // - argument - string to test against NFA of current instance
   // - return - true if string recognized, false if string not recognized
   // - pseudocode -
   //      create empty set to hold current states
   //      insert start state into current state set
   //       for each char in string
   //          for each state in the current state set
   //             for each transition in the transition list
   //                if a transition exists for a state, including epsilon
   //                transitions, an item is added to the new state set
   //          assign new set to current set
   //       search for goal states in the current state set
   //       return result of search
   //       
   bool evaluate(string testStr);

   // method nFAeToDFA
   // - argument - none
   // - return - DFA FiniteStateMachine representation of the NFAe
   // - pseudocode -
   //   compute start state of DFA:
   //     - find e-closure of NFAe start node
   //       create an empty set to represent DFA start set
   //       insert NFA start node into set
   //       while new nodes are being added to set
   //          for each transition in transition list
	//             if source node is in the set && char == epsilon
	//	               insert destination node into set
   //          node = next node in set
   //   compute additional states of DFA from a set of source nodes for a 
   //   given transition char:
   //     - find the move set from the destination nodes of moves for the 
   //       given set of source nodes
   //       create an empty set to represent the NFAe move set
   //       for each node in the source set
   //	         for each transition in transition list
   //		         if source == source && transitionChar == char
   //			         insert destination node into set
   //   compute e-closure of additional state:
   //     - find e-closure of NFAe move node
   //       create an empty set to represent DFA start set
   //       for each node in the move set
   //          insert NFA start node into set
   //          while new nodes are being added to set
   //             for each transition in transition list
	//                if source node is in the set && char == epsilon
	//	                  insert destination node into set
   //             node = next node in set
   FiniteStateMachine nFAeToDFA(void);

private:
   FiniteStateMachine fSM;
   // method buildMoveSet
   // - argument - starting set of nodes, transition character
   // - return - set of nodes
   set<int> buildMoveSet(set<int> startSet, char currChar);
   // method epsilonClosure
   // - argument - a move set of nodes as returned by buildMoveSet
   // - return - set of nodes
   set<int> epsilonClosure(set<int> moveSet);
    // store the hashed states
   unordered_map<string, set<int> > stateMap;
   // create a key for state hashing
   string hash(int node, char charValue);
};

#endif
