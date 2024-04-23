/*
 * ListNode.cpp
 *
 *  Created on: Apr 23, 2024
 *      Author: halel
 */

#include "ListNode.h"

// adds a string value to the beginning of the linked list
ListNode* insert(ListNode *ptr, string val) {
	ListNode *currNode = new ListNode();
	currNode->data = val;
	currNode->next = ptr;
	return currNode;
}

// adds a string value to the beginning of the linked list
void insert(ListNode **ptr, string val) {
	*ptr = insert(*ptr, val);
}

// removes a ListNode from the beginning of the linked list
ListNode* remove(ListNode *ptr) {
	ListNode *ret = ptr->next;
	if (ptr)
		delete ptr;
	return ret;
}

// removes a ListNode from the beginning of the linked list
void remove(ListNode **ptr) {
	*ptr = remove(*ptr);
}

// prints the string values found at each node on a separate line in order (front to back)
// I encourage you to use recursion
void printForward(ostream &out, ListNode *ptr) {
	if (ptr == nullptr) {
		return;
	}
	out << ptr->data << endl;
	printForward(out, ptr->next);
}

// prints the string values found at each node on a separate line in reverse order (back to front)
// I encourage you to use recursion
void printReverse(ostream &out, ListNode *ptr) {
	if (ptr == nullptr) {
		return;
	}
	printReverse(out, ptr->next);
	out << ptr->data << endl;
}

