#include <iostream>

int factorial(int number)
{
    if (number == 1) { return 1; }

    return factorial(number - 1) * number;
}

int factorial_accum_aux(int number, int accum)
{
    if (number == 1) { return accum; }

    return factorial_accum_aux(number - 1, number * accum);
}

int factorial_accum(int number)
{
    return factorial_accum_aux(number, 1);
}

int main(void)
{
    std::cout << "factorial(5): " << factorial(5) << std::endl;
    std::cout << "factorial_accum(5): " << factorial_accum(5) << std::endl;
}
