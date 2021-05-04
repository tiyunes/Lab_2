#ifndef QUEUE_COMPLEX_H
#define QUEUE_COMPLEX_H
#include "QUEUE.h"

class Queue_Complex
{
    public:
        class Complex
        {
        public:
            Complex()
            {
                this->real = 0;
                this->imaginary = 0;
            }
            Complex(int num)
            {
                this->real = num;
                this->imaginary = num;
            }
            Complex(const Complex &c)
            {
                this->real = c.real;
                this->imaginary = c.imaginary;
            }
        private:
            float real;
            float imaginary;
        };

        Queue_Complex()
        {
            elements = (Sequence<Complex>*) new LinkedListSequence<Complex>;
            //elements = (Sequence<Complex>*) new ArraySequence<Complex>;
        }
        Queue(Complex* items, int size)
        {
            this->elements = (Sequence<Complex>*) new LinkedListSequence<Complex>(items, size);
            //this->elements = (Sequence<Complex>*) new ArraySequence<Complex>(items, size);
        }
        Complex front()
        {
            return this->elements->GetFirst();
        }
        Complex back()
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
            return this->elements->GetLength();
        }
        void push(Complex item)
        {
            return this->elements->Append(item);
        }
        void pop()
        {
            this->elements->Pop();
        }

    protected:

    private:
        Sequence<Complex>* elements;
};

#endif // QUEUE_COMPLEX_H
