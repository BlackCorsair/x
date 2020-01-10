#include <iostream>

template<typename T>
int add(int a, int b, T fn)
{
    return fn(a) + fn(b);
}

int pow(int a)
{
    return a * a;
}

int main(int argc, char const *argv[])
{
    std::cout << add(1, -2, pow) << std::endl;
    return 0;
}
