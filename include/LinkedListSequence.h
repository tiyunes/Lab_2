#include "SEQUENCE.H"
#include "LinkedList.h"
#ifndef LINKEDLISTSEQUENCE_H
#define LINKEDLISTSEQUENCE_H

template<class T>
class LinkedListSequence: public Sequence<T>
{
    public:
        friend class LinkedList<T>;

        LinkedListSequence()
        {
            this->items->first = nullptr;
            this->items->Size = 0;
        }
        LinkedListSequence(T* items, int c)
        {
            this->items = new LinkedList<T>(items, c);
            this->items->Size = c;
        }
        LinkedListSequence(const LinkedList<T>& l)
        {
             this->items = new LinkedList<T>(l);
        }
        T GetFirst() override
        {
            return this->items->GetFirst();
        }
        T GetLast() override
        {
            return this->items->GetLast();
        }
        T Get(int index) override
        {
            return this->items->Get(index);
        }
        LinkedList<T>* GetSubsequence(int startIndex, int endIndex)
        {
            return this->items->GetSubList(startIndex, endIndex);
        }
        int GetLength() override
        {
            return this->items->GetLength();
        }

        void Append(T item) override
        {
            this->items->Append(item);
        }
        void Prepend(T item) override
        {
            this->items->Prepend(item);
        }
        void InsertAt(T item, int index) override
        {
            this->items->InsertAt(item, index);
        }
        LinkedList<T>* Concat(LinkedList <T> *l)
        {
            return this->items->Concat(l);
        }
    protected:

    private:
        LinkedList<T>* items;
};

#endif // LINKEDLISTSEQUENCE_H
