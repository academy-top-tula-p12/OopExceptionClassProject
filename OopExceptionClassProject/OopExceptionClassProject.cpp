#include <iostream>
#include "MyException.h"

class Fraction
{
    int numerator;
    int denominator;
public:
    Fraction(int numerator, int denominator) : numerator{ numerator }
    {
        if (denominator == 0)
            throw MyException("Divide by zero");
        this->denominator = denominator;
    }
};

template <typename T, int size>
class Array
{
    T items[size]{};
public:
    int Size() { return size; }

    T& operator[](int index)
    {
        if (index < 0 || index >= size)
            throw MyRangeException();
        return items[index];
    }
};

class Base
{
    int value;
public:
    Base(int value) : value{ value }
    {
        if (value == 0)
            throw MyException("Invalid of value");
    }
};

class Derived : public Base
{
public:
    Derived(int value) try : Base(value) 
    {
    }
    catch(MyException e)
    {
        std::cout << e.Message() << "\n";
        std::cout << "Derived construct\n";
        throw;
    };
};


class Doned
{
public:
    ~Doned()
    {
        std::cout << "Doned destruct\n";
    }
};

void Thrower()
{
    std::cout << "Throw exception\n";
    throw 1;
}

void PatentallyThrow()
{
    std::cout << "PatentallyThrow starting\n";
    Doned doned{};
    Thrower();
    std::cout << "This message never prints\n";
}

void NoExceptThrow() noexcept
{
    std::cout << "NoExceptThrow starting\n";
    Doned doned{};
    Thrower();
    std::cout << "This message never prints\n";
}

void Tester(int code) noexcept
{
    std::cout << "Tester starting with " << code << "\n";
    try
    {
        if (code == 1)
            PatentallyThrow();
        else
            NoExceptThrow();
    }
    catch (...)
    {
        std::cout << "Tester try catch\n";
    }
}



int main()
{
    /*
    try
    {
        Fraction f1(10, 0);
    }
    catch (MyException e)
    {
        std::cout << e.Message() << "\n";

    }
    
    Array<int, 5> array;
    try
    {
        array[10] = 100;
    }
    catch (MyException e)
    {
        std::cout << e.Message() << "\n";
    }

    try
    {
        Derived d1(0);
    }
    catch (MyException e)
    {
        std::cout << "Main try catch\n";
        std::cout << e.Message() << "\n";
    }

    Fraction* f2 = nullptr;

    try
    {
        f2 = new Fraction(10, 20);
        // code with f2
    }
    catch (...)
    {
        
    }
    delete f2;

    */

    Tester(1);
    std::cout << "Test sucessful\n\n";
    Tester(2);
    std::cout << "Test sucessful\n\n";
}
