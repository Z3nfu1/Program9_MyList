/*
 * ListNode.h
 *
 *  Created on: Apr 23, 2024
 *      Author: halel
 */

#ifndef LISTNODE_H_
#define LISTNODE_H_

#include <iostream>
#include <string>

using namespace std;

struct ListNode {
	string data;
	ListNode *next;

	ListNode() :
			data(""), next(nullptr) {
	}

	ListNode(string s) :
			data(s), next(nullptr) {
	}
};

ListNode* insert(ListNode *ptr, string val);
void insert(ListNode **ptr, string val);
ListNode* remove(ListNode *ptr);
void remove(ListNode **ptr);
void printForward(ostream &out, ListNode *ptr);
void printReverse(ostream &out, ListNode *ptr);

#endif /* LISTNODE_H_ */
