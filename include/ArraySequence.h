#ifndef ARRAYSEQUENCE_H
#define ARRAYSEQUENCE_H
#include "SEQUENCE.H"
#include "DynamicArray.h"
//#include "DynamicArray.cpp"

template<class T>
class ArraySequence: public Sequence<T>
{
    public:
        friend class DynamicArray<T>;

        ArraySequence(int size);
        ArraySequence(T* items, int c);
        ArraySequence(const DynamicArray<T>& dynamicArray);

        T GetFirst() override;
        T GetLast() override;
        T Get(int index) override;
        int GetLength() override;

        void Append(T item) override;
        void Prepend(T item) override;
        void InsertAt(T item, int index) override;
        Sequence<T>* GetSubsequence(int startIndex, int endIndex) override;
        Sequence<T>* Concat(Sequence<T> *l) override;
    private:
        DynamicArray<T>* items;
};


#endif // ARRAYSEQUENCE_H

