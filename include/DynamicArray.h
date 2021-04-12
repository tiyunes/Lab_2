#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

template<class T>
class DynamicArray
{
    public:
        T& operator[] (int index)
        {
            return this->values[index];
        }
        DynamicArray(T* items, int c)
        {
            DynamicArray<T> temp(c);
            this->values = new T[c];
            for (int i = 0; i < c; i++)
            {
                temp.Set(i, items[i]);
            }
            this->values = temp.values;
            this->size = c;
        }
        DynamicArray(int size)
        {
            this->values = new T[size];
            for (int i = 0; i < size; i++)
            {
                this->values[i] = 0;
            }
            this->size = size;
        }
        DynamicArray(const DynamicArray<T>& dynamicArray)
        {
            this->size = dynamicArray.size;
            this->values = new T[dynamicArray.size];
            for (int i = 0; i < dynamicArray.size; i++)
            {
                this->values[i] = dynamicArray.values[i];
            }
        }
        T Get(int index)
        {
            return this->values[index];
        }
        int GetSize()
        {
            return this->size;
        }
        void Set(int index, T value)
        {
            this->values[index] = value;
        }
        void Resize(int newSize)
        {
            int i;
            int *newValues = new T[newSize];
            for (i = 0; i < newSize; i++)
            {
                newValues[i] = this->values[i];
            }
            if (newSize > this->size)
            {
                for (int j = newSize; j < this->size; j++)
                {
                    newValues[j] = 0;
                }
            }
            delete[]this->values;
            this->values = newValues;
            this->size = newSize;
        }

    protected:

    public:
        T* values;
        int size;
};

#endif // DYNAMICARRAY_H
