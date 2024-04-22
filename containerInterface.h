/*
 * containerInterface.h
 *
 *  Created on: Mar 29, 2024
 *      Author: halel
 */

#ifndef CONTAINERINTERFACE_H_
#define CONTAINERINTERFACE_H_

class BADINDEX
{
};

template<typename T>
class containerInterface
{
    public:
        virtual containerInterface<T>& pushFront(T) =0;
        virtual containerInterface<T>& pushBack(T) =0;
        virtual containerInterface<T>& popFront(T&) =0;
        virtual containerInterface<T>& popBack(T&) =0;
        virtual int getSize() const =0;
        virtual bool isEmpty() const =0;
        virtual T front() const =0;
        virtual T back() const =0;
        virtual T& operator [](int) =0;
        virtual void erase() =0;
        virtual ~containerInterface()
        {
        }
};

#endif /* CONTAINERINTERFACE_H_ */
