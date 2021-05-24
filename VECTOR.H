#ifndef VECTOR_H
#define VECTOR_H
#include "ArraySequence.h"
#include "LinkedListSequence.h"
#include <cmath>

template<class T>
class Vector
{
public:
    Vector()
    {
        //this->coordinates = (Sequence<T>*) new LinkedListSequence<T>();
        this->coordinates = (Sequence<T>*) new ArraySequence<T>();
        this->length = 0;
    }

    Vector(T* items, int size)
    {
        //this->coordinates = (Sequence<T>*) new LinkedListSequence<T>(); 0.004 s for 1000 elements
        this->coordinates = (Sequence<T>*) new ArraySequence<T>(0); //0.137 s for 1000 elements
        for(int i = 0; i < size; i++)
        {
            this->coordinates->Append(items[i]);
        }
        this->length = size;
    }

    int GetLength()
    {
        return this->length;
    }

    T GetCoordinate(int index) //0.003 s (List) and 0.001 (Array) for 1000 iterations
    {
        return (this->coordinates->Get(index));
    }

    Vector<T>* Sum(Vector<T>* v) //0.012 s (List) and 0.132 s (Array) for vectors of 1000 elements
    {
        if(v->GetLength() != this->GetLength())
        {
            throw std::out_of_range("Invalid sizes of vectors");
        }
        else
        {
            Vector<T>* sumV = new Vector<T>();
            for (int i = 0; i < this->GetLength(); i++)
            {
                sumV->coordinates->Append(this->GetCoordinate(i) + v->GetCoordinate(i));
                sumV->length++;
            }
            return sumV;
        }
    }

    Vector<T>* Mult(int number) //multiplication by scalar - 0.008 s (List) and 0.137 s (Array) for vector of 1000 elementss
    {
        Vector<T>* mult = new Vector<T>();
        for (int i = 0; i < this->GetLength(); i++)
        {
            mult->coordinates->Append(number*(this->GetCoordinate(i)));
            mult->length++;
        }
        return mult;
    }

    T ScalarProd(Vector<T>* v) //0.006 s (List) and 0.001 s (Array) for vectors of 1000 elements
    {
        if(v->GetLength() != this->GetLength())
        {
            throw std::out_of_range("Invalid sizes of vectors");
        }
        else
        {
            T mult = 0;
            for (int i = 0; i < this->GetLength(); i++)
            {
                mult += (v->GetCoordinate(i))*(this->GetCoordinate(i));
            }
            return mult;
        }
    }

    float Norm()
    {
        float normV = 0.0;
        normV = float(this->ScalarProd(this));
        return sqrt(normV);
    }
protected:

private:
    Sequence<T>* coordinates;
    int length;
};

#endif // VECTOR_H
