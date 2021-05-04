#ifndef COMPLEX_H
#define COMPLEX_H


class Complex
{
public:
    Complex()
    {
        this->real = 0;
        this->imaginary = 0;
    }
    Complex(float num)
    {
        this->real = num;
        this->imaginary = num;
    }
    Complex(float num1, float num2)
    {
        this->real = num1;
        this->imaginary = num2;
    }
    Complex(const Complex &c)
    {
        this->real = c.real;
        this->imaginary = c.imaginary;
    }
    bool operator==(Complex* c1)
    {
        return ((c1->real == this->real) && (c1->imaginary == this->imaginary));
    }
    Complex& operator+(Complex* c1)
    {
        Complex* cSum = new Complex();
        cSum->real = this->real + c1->real;
        cSum->imaginary = this->imaginary + c1->imaginary;
        return *cSum;
    }
private:
    float real;
    float imaginary;
};
#endif // COMPLEX_H
