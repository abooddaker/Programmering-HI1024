#include <stdio.h>

struct complex 
{
    float real, imaginary;
}; typedef struct complex Complex;

Complex createComplex(float real, float imaginary);
void printComplex(Complex c);
void multiplyComplex(Complex *c, float decimal);

int main(void)
{
    Complex c1, c2;
    c1 = createComplex(3,2);
    c2 = createComplex(2,-3);

    printComplex(c1);
    printComplex(c2);

    multiplyComplex(&c1,-2.5);
    multiplyComplex(&c2, -1);

    printComplex(c1);
    printComplex(c2);

    return 0;
}

Complex createComplex(float real, float imaginary)
{
    Complex c;
    c.real = real;
    c.imaginary = imaginary;
    return c;
}

void printComplex(Complex c)
{
    if(c.imaginary > 0)
    {
        printf("%f + %fi\n", c.real, c.imaginary);
    }
    if(c.imaginary < 0)
    {
        printf("%f - %fi\n", c.real, c.imaginary*-1);
    }
}

void multiplyComplex(Complex *c, float decimal)
{
    c -> imaginary *= decimal;
    c -> real *= decimal;
}