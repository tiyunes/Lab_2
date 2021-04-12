#ifndef ARRAYSEQUENCE_H
#define ARRAYSEQUENCE_H
#include "DynamicArray.h"
#include "SEQUENCE.H"

template<class T>
class ArraySequence: public Sequence<T>
{
    public:
        friend class DynamicArray<T>;

        ArraySequence(int size)
        {
            this->items = new DynamicArray<T>(size);
        }
        ArraySequence(T* items, int c)
        {
            this->items = new DynamicArray<T>(items,
                                               c);
        }
        ArraySequence(const DynamicArray<T>& dynamicArray)
        {
            this->items = new DynamicArray<T>(dynamicArray);
        }
        T GetFirst() override
        {
            return this->items->Get(0);
        }
        T GetLast() override
        {
            return this->items->Get(this->items->size - 1);
        }
        T Get(int index) override
        {
            return this->items->Get(index);
        }
        int GetLength() override
        {
            return this->items->GetSize();
        }
        void Append(T item) override
        {
            this->items->Resize(this->items->size + 1);
            this->items->Set(this->items->size - 1, item);
        }
        void Prepend(T item) override
        {
            this->items->Resize(this->items->size + 1);
            this->items->Set(0, item);
        }
        void InsertAt(T item, int index) override
        {
            this->items->Resize(this->items->size + 1);
            this->items->Set(index, item);
        }
        DynamicArray<T>* Concat(DynamicArray <T> *l)
        {
            DynamicArray<T>* concatArray = new DynamicArray<T>(*l);
            concatArray->Resize(l->size + this->items->size);
            for (int i = 0; i < this->items->size; i++)
            {
                concatArray->Set(i + l->size, this->items->Get(i));
            }
            return concatArray;
        }
    private:
        DynamicArray<T>* items;
};

#endif // ARRAYSEQUENCE_H
