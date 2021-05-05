#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

template<class T>
class DynamicArray
{
public:
    DynamicArray();
    DynamicArray(T* items, int Size);
    DynamicArray(int Size);
    DynamicArray(const DynamicArray<T>& dynamicArray);

    T Get(int index);
    int GetSize();
    T& operator[] (int index);
    void Pop();
    void Reverse();

    void Set(int index, T value);
    void Resize(int newSize);
    void ChangeSize(int newSize);
    ~DynamicArray();

protected:

public:
    T* values;
    int Size;
};

template<class T>
DynamicArray<T>::DynamicArray()
{
    this->values = new T[0];
    this->Size = 0;
}

template<class T>
DynamicArray<T>::DynamicArray(int Size)
{
    this->values = new T[Size];
    for (int i = 0; i < Size; i++)
    {
        this->values[i] = 0;
    }
    this->Size = Size;
}

template<class T>
DynamicArray<T>::DynamicArray(T* items, int Size)
{
    this->values = new T[Size];
    for (int i = 0; i < Size; i++)
    {
        this->values[i] = items[i];
    }
    this->Size = Size;
}

template<class T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& dynamicArray)
{
    this->Size = dynamicArray.Size;
    this->values = new T[dynamicArray.Size];
    for (int i = 0; i < dynamicArray.Size; i++)
    {
        this->values[i] = dynamicArray.values[i];
    }
}

template<class T>
T DynamicArray<T>::Get(int index)
{
    if (index < 0 || index > this->GetSize())
    {
        throw std::out_of_range("Invalid index");
    }
    return this->values[index];
}

template<class T>
int DynamicArray<T>::GetSize()
{
    return this->Size;
}

template<class T>
T& DynamicArray<T>::operator[](int index)
{
    return this->values[index];
}

template<class T>
void DynamicArray<T>::Set(int index, T value)
{
    if (index < 0 || index > this->GetSize())
    {
        throw std::out_of_range("Invalid index");
    }
    this->values[index] = value;
}

template<class T>
void DynamicArray<T>::Resize(int newSize)
{
    if(this->Size > 0)
    {
        int i;
        T *newValues = new T[newSize];
        for (i = 0; i < this->GetSize(); i++)
        {
            newValues[i] = this->Get(i);
        }
        if (newSize > this->Size)
        {
            for (int j = this->Size; j < newSize; j++)
            {
                newValues[j] = 0;
            }
        }
        this->Size = newSize;
        this->values = new T[newSize];
        for (i = 0; i < newSize; i++)
        {
            this->values[i] = newValues[i];
        }
    }
    else
    {
        this->Size = newSize;
        this->values = new T[newSize];
        for (int j = 0; j < newSize; j++)
        {
            this->values[j] = 0;
        }
    }

}

template<class T>
void DynamicArray<T>::ChangeSize(int newSize)
{
    this->Size = newSize;
}

template<class T>
void DynamicArray<T>::Pop()
{
    T *newValues = new T[this->Size - 1];
    if (this->Size - 1 != 0)
    {
        for (int i = 0; i < this->Size - 1; i++)
        {
            newValues[i] = this->Get(i + 1);
        }
        this->ChangeSize(this->Size - 1);
        this->values = new T[this->Size];
        for (int j = 0; j < this->Size; j++)
        {
            this->values[j] = newValues[j];
        }
    }
    else if (this->Size == 1)
    {
        this->ChangeSize(0);
        this->values = new T[0];
    }

}

template<class T>
void DynamicArray<T>::Reverse()
{
    T buff;
    for (int i = 0; i < (this->GetSize() / 2); i++)
    {
        buff = this->Get(i);
        this->values[i] = this->Get(this->GetSize() - i - 1);
        this->values[this->GetSize() - i - 1] = buff;
    }
}

template<class T>
DynamicArray<T>::~DynamicArray()
{
    delete[] this->values;
}

#endif // DYNAMICARRAY_H

