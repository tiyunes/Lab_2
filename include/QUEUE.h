#ifndef QUEUE_H
#define QUEUE_H
#include "ArraySequence.h"
//#include "ArraySequence.cpp"
#include "LinkedListSequence.h"
//#include "LinkedListSequence.cpp"

template<class T>
class Queue
{
    public:
        Queue()
        {
            elements = (Sequence<T>*) new LinkedListSequence<T>;
        }
        Queue(const int foo)
        {
            elements = (Sequence<T>*) new LinkedListSequence<T>;
            _foo = foo;
        }
        Queue(const Queue& other)
        {
            elements = (Sequence<T>*) new LinkedListSequence<T>(other->elements);
        }
        T front()
        {
            return this->elements->GetFirst();
        }
        T back()
        {
            return this->elements->GetLast();
        }
        bool empty()
        {
            if (this->elements->GetLength() == 0) return true;
            else return false;
        }
        int size()
        {
            return this->elements->GetLength;
        }
        void push(T item)
        {
            return this->elements->Append(item);
        }
        void pop()
        {
            this->elements->Pop();
        }
    protected:

    private:
        Sequence<T>* elements;
        int _foo = 0;
};

#endif // QUEUE_H

