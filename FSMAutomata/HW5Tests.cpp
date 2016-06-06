/*****************************************************************************
 *
 * file HW5Tests.cpp
 * the test driver file for CSS502 Homework 5
 *
 * Shawn Quinn
 * quinnms1
 * 02/21/2015
 *
 ****************************************************************************/

#include "CompiledNFAEpsilon.h"
#include "CompiledDFA.h"

int main(void)
{
//------------------ first set of tests, uncomment to run --------------------
/*
   Transition trans1e2 = { 1, epsilon, 2 };
   Transition trans1a3 = { 1, 'a', 3 };
   Transition trans2b3 = { 2, 'b', 3};
   Transition trans2e4 = { 2, epsilon, 4};
   Transition trans3e4 = { 3, epsilon, 4};
   Transition trans3b5 = { 3, 'b', 5};
   Transition trans4a5 = { 4, 'a', 5};
   list<Transition> transList;
   transList.push_back(trans1e2);
   transList.push_back(trans1a3);
   transList.push_back(trans2b3);
   transList.push_back(trans2e4);
   transList.push_back(trans3e4);
   transList.push_back(trans3b5);
   transList.push_back(trans4a5);
   set<int> nodes;
   nodes.insert(1);
   nodes.insert(2);
   nodes.insert(3);
   nodes.insert(4);
   nodes.insert(5);
   int startNode = 1;
   set<int> goalNodes;
   goalNodes.insert(5);
   FiniteStateMachine fsm = { nodes, startNode, goalNodes, transList };
   CompiledNFAEpsilon nFAe(&fsm);
   bool retVal = nFAe.evaluate("ab");
   CompiledDFA dFA(&fsm);
   retVal = dFA.evaluate("ab");
   FiniteStateMachine fSMDFA;
   fSMDFA = nFAe.nFAeToDFA();
   CompiledDFA dFAFromNFAe(&fSMDFA);
   dFAFromNFAe.evaluate("ab");
*/

//------------------ second set of tests -------------------------------------
   Transition trans0e1 = { 0, epsilon, 1 };
   Transition trans0e7 = { 0, epsilon, 7 };
   Transition trans1e2 = { 1, epsilon, 2 };
   Transition trans1e4 = { 1, epsilon, 4 };
   Transition trans2a3 = { 2, 'a', 3 };
   Transition trans3e6 = { 3, epsilon, 6 };
   Transition trans4b5 = { 4, 'b', 5 };
   Transition trans5e6 = { 5, epsilon, 6 };
   Transition trans6e7 = { 6, epsilon, 7 };
   Transition trans7a8 = { 7, 'a', 8 };
   Transition trans8b9 = { 8, 'b', 9 };
   Transition trans9b10 = { 9, 'b', 10 };
   list<Transition> transList;
   transList.push_back(trans0e1);
   transList.push_back(trans0e7);
   transList.push_back(trans1e2);
   transList.push_back(trans1e4);
   transList.push_back(trans2a3);
   transList.push_back(trans3e6);
   transList.push_back(trans4b5);
   transList.push_back(trans5e6);
   transList.push_back(trans6e7);
   transList.push_back(trans7a8);
   transList.push_back(trans8b9);
   transList.push_back(trans9b10);
   set<int> nodes;
   nodes.insert(0);
   nodes.insert(1);
   nodes.insert(2);
   nodes.insert(3);
   nodes.insert(4);
   nodes.insert(5);
   nodes.insert(6);
   nodes.insert(7);
   nodes.insert(8);
   nodes.insert(9);
   nodes.insert(10);
   int startNode = 0;
   set<int> goalNodes;
   goalNodes.insert(10);
   FiniteStateMachine fsm = { nodes, startNode, goalNodes, transList };
   CompiledNFAEpsilon nFAe(&fsm);
   bool retVal = nFAe.evaluate("aabb");
   FiniteStateMachine fSMDFA;
   fSMDFA = nFAe.nFAeToDFA();
   CompiledDFA dFAFromNFAe(&fSMDFA);
   retVal = dFAFromNFAe.evaluate("aabb");


   return 0;
}
