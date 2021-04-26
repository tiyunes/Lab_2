#ifndef STACK_H
#define STACK_H
#include "ArraySequence.h"
#include "LinkedListSequence.h"

template<class T>
class Stack
{
    public:
        Stack()
        {
            elements = (Sequence<T>*) new LinkedListSequence<T>;
        }
        Stack(const Stack& other)
        {
            elements = (Sequence<T>*) new LinkedListSequence<T>(other->elements);
        }
        T top()
        {
            return this->elements->GetFirst();
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
            return this->elements->Prepend(item);
        }
        void pop()
        {
            this->elements->Pop();
        }

    protected:

    private:
        Sequence<T>* elements;
};

#endif // STACK_H
