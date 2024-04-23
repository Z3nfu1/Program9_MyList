//============================================================================
// Name        : Lab8_LinkedList.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "ListNode.h"

using namespace std;

string names[] = {"Fido", "Dixie", "Bones", "Huck", "Frenchy", "Scooby", "SgtShultz"};

int main() {
  ListNode *head = nullptr;

  cout << "Testing ListNode* insert(ListNode*, string)..." << endl << endl;
  for( int i = 0; i < 7; i++ ) {
    head = insert( head, names[i] );
  }

  cout << "Printing Forward..." << endl;
  printForward(cout, head);
  cout << endl;

  cout << "Printing Reverse..." << endl;
  printReverse(cout, head);
  cout << endl;

  cout << "Testing ListNode *remove(ListNode *)..." << endl << endl;
  for( int i = 0; i < 7; i ++ ) {
    head = remove(head);
  }

  cout << "Printing Forward empty list" << endl;
  printForward(cout, head);

  cout << endl;
  cout << "Testing void insert(ListNode**, string)... " << endl << endl;
  for( int i = 0; i < 7; i++ ) {
    insert(&head, names[i]);
  }

  cout << "Printing Forward..." << endl;
  printForward(cout, head);

  cout << endl;
  cout << "Tesing void remove(ListNode**)..." << endl;
  for( int i = 0; i < 7; i++ ) {
    remove(&head);
  }
  if( head != NULL ) {
    cout << "Error" << endl;
  } else {
    cout << "Done" << endl;
  }
  return 0;
}

