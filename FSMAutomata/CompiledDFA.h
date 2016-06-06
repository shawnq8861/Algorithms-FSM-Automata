/*****************************************************************************
 *
 * file CompiledDFA.h
 * interface declaration for the Deterministic Finite Automata (DFA) class
 *
 * Shawn Quinn
 * quinnms1
 * 02/21/2015
 *
 ****************************************************************************/

#ifndef COMPILED_DFA_H
#define COMPILED_DFA_H

#include "dataStructsHW5.h"
#include <string>
#include <unordered_map>

class CompiledDFA
{
public:
   // constructor
   // - argument - pointer to a FiniteStateMachine struct
   CompiledDFA(FiniteStateMachine* someFSM);

   // destructor
   // - 
   ~CompiledDFA();

   // method evaluate
   // - argument - string to test against NFA of current instance
   // - return - true if string recognized, false if string not recognized
   // - pseudocode -
   //      create temp variable to hold current state
   //      set current state to start state
   //      for each char in string
   //          for each transition in the transition list
   //             if a char matches the transitionChar
   //                current state = destination
   //      search for current state in goal states
   //      return result of search
   //
   //    modification
   //       pass char and current node into unordered_map
   //       unordered_map returns the value of the next state
   //       
   bool evaluate(string testStr);

private:
   FiniteStateMachine fSM;
   unordered_map<string, int> stateMap;
   string hash(int node, char ch);
};

#endif
