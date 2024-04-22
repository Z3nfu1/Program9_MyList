/*
 * myLinkedList.h
 *
 *  Created on: Mar 29, 2024
 *      Author: Lawson Hale
 */

#ifndef MYLINKEDLIST_H_
#define MYLINKEDLIST_H_

#include <memory>
#include <iostream>
#include "containerInterface.h"
using namespace std;

template <typename T>
struct node
{
        T data;
        node<T> *next;
        node<T> *back;
        node(T e)
        {
            data = e;
            next = nullptr;
            back = nullptr;
        }

        void clear()
        {
            data = 0;
            next = nullptr;
            back = nullptr;
        }
};

template <typename T>
class myLinkedList : public containerInterface<T>
{
    public:
        myLinkedList(); //done
        ~myLinkedList(); //done
        myLinkedList(const myLinkedList<T>&); //done
        myLinkedList(myLinkedList<T>&&); //done
        myLinkedList<T>& pushFront(T); //done
        myLinkedList<T>& pushBack(T); //done
        myLinkedList<T>& popFront(T&); //done
        myLinkedList<T>& popBack(T&); //done
        int getSize() const; //done ?
        int getSizeBack() const;
        bool isEmpty() const; //done
        T front() const; //done
        T back() const; //done
        T& operator [](int n); //done
        void erase(); //done
        myLinkedList<T>& operator =(const myLinkedList<T>&); //done
        // NEEDS TO BE DONE
        myLinkedList<T>& operator =(myLinkedList<T>&&);

        void print();
        void printBack();

    private:
        node<T> *head;
        node<T> *tail;
        int r_size(const node<T> *n);
};

template <typename T>
myLinkedList<T>::myLinkedList() :
        head(nullptr), tail(nullptr)
{
}

template <typename T>
myLinkedList<T>::myLinkedList(myLinkedList<T> &&other)
{
    head = other.head;
    tail = other.tail;
    other.head = nullptr;
    other.tail = nullptr;
}

template <typename T>
myLinkedList<T>::myLinkedList(const myLinkedList<T> &n)
{
    head = tail = nullptr;
    node<T> *p = n.head;
    while (p) {
        pushBack(p->data);
        p = p->next;
    }
}

/*
 * description: class destructor
 * pre-condition: a list object exists
 * post-condition:  all memory allocated to the list is deleted
 * return: nothing
 */

template <typename T>
myLinkedList<T>::~myLinkedList()
{
    erase();
}

template <typename T>
myLinkedList<T>& myLinkedList<T>::operator =(
        const myLinkedList<T> &other)
{
    if (this != &other) {
        if (head) {
            erase();
        }
        node<T> *p = other.head;
        while (p) {
            pushBack(p->data);
            p = p->next;
        }
    }
    return *this;
}

template <typename T>
myLinkedList<T>& myLinkedList<T>::operator =(myLinkedList<T> &&other)
{
    head = other.head;
    tail = other.tail;
    other.head = nullptr;
    other.tail = nullptr;
    return *this;
}

template <typename T>
myLinkedList<T>& myLinkedList<T>::pushFront(T e)
{
    //cout << "Pushing front: " << e << endl;
    node<T> *newNode = new node<T>(e);

    if (head) {
        head->back = newNode;
        newNode->next = head;
    }
    else {
        tail = newNode;
    }
    head = newNode;
    return *this;
}

template <typename T>
myLinkedList<T>& myLinkedList<T>::pushBack(T e)
{
    //cout << "Pushing back: " << e << endl;
    node<T> *newNode = new node<T>(e);

    if (tail) {
        newNode->back = tail;
        tail->next = newNode;
    }
    else {
        head = newNode;
    }
    tail = newNode;
    return *this;
}

template <typename T>
myLinkedList<T>& myLinkedList<T>::popFront(T &e)
{
    //cout << "Popping front" << endl;
    if (head) {
        e = head->data;
        node<T> *temp = head;
        head = head->next;
        delete temp;
    }
    return *this;
}

template <typename T>
myLinkedList<T>& myLinkedList<T>::popBack(T &e)
{
    //cout << "Popping back" << endl;
    if (tail) {
        e = tail->data;
        node<T> *temp = tail;
        tail = tail->back;
        tail->next = nullptr;
        delete temp;
    }
    return *this;
}

template <typename T>
int myLinkedList<T>::getSize() const
{
    node<T> *p = head;
    int count = 0;
    while (p) {
        p = p->next;
        count++;
    }
    return count;
}

template <typename T>
int myLinkedList<T>::getSizeBack() const
{
    node<T> *p = tail;
    int count = 0;
    while (p) {
        p = p->back;
        count++;
    }
    return count;
}

template <typename T>
int myLinkedList<T>::r_size(const node<T> *n)
{
    if (!n) {
        return 0;
    }
    return 1 + r_size(n->next);
}

template <typename T>
bool myLinkedList<T>::isEmpty() const
{
    return (!head);
}

template <typename T>
T myLinkedList<T>::front() const
{
    if (head) {
        return head->data;
    }
    else {
        throw("Empty list");
    }
}

template <typename T>
T myLinkedList<T>::back() const
{
    if (tail) {
        return tail->data;
    }
    else {
        throw("Empty list");
    }
}

template <typename T>
T& myLinkedList<T>::operator [](int n) // assumes that n is a valid location in the list
{
    node<T> *p = head;
    for (int i = 0; i < n; i++) {
        p = p->next;
    }

    return p->data;
}

// while head exists, remove it
template <typename T>
void myLinkedList<T>::erase()
{
    T e;
    while (head) {
        popFront(e);
    }
}

template <typename T>
void myLinkedList<T>::print()
{
    node<T> *p = head;
    int count = 0;
    while (p) {
        cout << p->data << " ";
        p = p->next;
        count++;
        if (count >= 10) {
            p = nullptr;
        }
    }
    cout << endl;
}

template <typename T>
void myLinkedList<T>::printBack()
{
    node<T> *p = tail;
    int count = 0;
    while (p) {
        cout << p->data << " ";
        p = p->back;
        count++;
        if (count >= 10) {
            p = nullptr;
        }
    }
    cout << endl;
}


#endif /* MYLINKEDLIST_H_ */

