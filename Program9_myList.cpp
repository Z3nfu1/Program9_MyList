//============================================================================
// Name        : Program9_myList.cpp
// Author      : Lawson Hale
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include "myLinkedList.h"

void test(myLinkedList<int> l)
{
    l.print();
    l.printBack();
    cout << "Front: " << l.front() << endl;
    cout << "Back:  " << l.back() << endl;
    cout << "Size:      " << l.getSize() << endl;
    cout << "Size back: " << l.getSizeBack() << endl << endl;
}

int main()
{
    myLinkedList<int> arr;
    int e = 50;
    for (int i = 0; i < 5; i++) {
        arr.pushFront(100 * i);
        cout << arr.back() << " ";
    }
    cout << endl;

    test(arr);

    arr.popBack(e);
    test(arr);

    arr.popFront(e);
    test(arr);

    arr.popBack(e);
    test(arr);

    arr.popFront(e);
    test(arr);

    return 0;
}
