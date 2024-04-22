#ifndef MYLINKEDLIST_H_
#define MYLINKEDLIST_H_

#include <stdexcept>

template <typename T>
struct node
{
        T data;
        node<T> *next, *back;

        node(T data = 0) :
                data(data), next(nullptr), back(nullptr)
        {
        }
};

template <typename T>
class myLinkedList
{
    private:
        node<T> *head;
        node<T> *tail;
        int r_size(node<T>*);
        void r_insert(node<T> *&p, T n);

    public:
        myLinkedList(myLinkedList<T>&&);myLinkedList() :
        head(nullptr)
        tail(nullptr)
        {
        }
        bool isEmpty();
        void push(T n);
        void insert(T n);
        void pop();
        int size();
        T front();
        bool remove(T n);
};

template <typename T>
myLinkedList<T>::myLinkedList(myLinkedList<T> &&other)
{
    head = other.head;
    tail = other.tail;
    other.head = nullptr;
    other.tail = nullptr;
}

template <typename T>
bool myLinkedList<T>::remove(T n)
{
    node<T> *p = head, *pp = nullptr;
    while (p && p->data <= n) { //only because list is already sorted
        pp = p;
        p = p->next;
    }
    if (p && p->data == n) {
        if (pp) {
            pp->next = p->next;
        }
        else {
            head = p->next;
        }
        delete p;
        return true;
    }
    return false;
}

template <typename T>
void myLinkedList<T>::push(T n)
{
    node<T> *newNode = new node<T>(n);

    if (head) {
        head->back = newNode;
    }
    newNode->next = head;
    head = newNode;

}

template <typename T>
void myLinkedList<T>::insert(T n)
{
    r_insert(head, n);

    if (!head || n < head->data) { // at beginning of list
        push(n);
    }
    else {
        node<T> *newNode = new node<T>(n);
        node<T> *p = head;
        node<T> *pp;
        while (p && n > p->data) {
            pp = p;
            p = p->next;
        }
        pp->next = newNode;
        newNode->back = pp;

        if (p) { // not at end of list
            newNode->next = p;
            //newNode->back = p->back;
            //p->back->next = newNode;
            p->back = newNode;
        }
    }

}

template <typename T>
void myLinkedList<T>::r_insert(node<T> *&p, T n)
{
    if (p && p->data < n) {
        r_insert(p->next, n);
        return;
    }

    node<T> *newNode = new node<T>(n);
    if (p && p->data > n) {
        newNode->next = p;
    }
    p = newNode;
}

template <typename T>
void myLinkedList<T>::pop()
{
    if (!head) {
        throw("Pop empty list");
    }

    node<T> *temp = head; //will always delete temp
    if (head->next) {
        head->next->back = nullptr;
    }

    head = head->next;
    delete temp;
}

template <typename T>
int myLinkedList<T>::size()
{
    return r_size(head);
    /*
     int count = 0;
     node<T> *p = head;
     while(p) {
     count++;
     p = p->next;
     }
     return count;
     */
}

template <typename T>
int myLinkedList<T>::r_size(node<T> *p)
{
    if (p == nullptr) {
        return 0;
    }
    return 1 + r_size(p->next);
}

template <typename T>
T myLinkedList<T>::front()
{
    if (head == nullptr) {
        throw("Head is null");
    }

    return head->data;
}

template <typename T>
bool myLinkedList<T>::isEmpty()
{
    return head == nullptr;
}

#endif // MYLINKEDLIST_H_
