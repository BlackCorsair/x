#include <iostream>
#include <vector>

template<typename T>
int add(int a, int b, T fn)
{
    return fn(a) + fn(b);
}

int pow(int a)
{
    return a * a;
}

template<typename Iterator, typename T>
int sumList(Iterator begin, Iterator end, T fn)
{
    if (begin + 1 == end) { return *begin; }
    return add(*begin, sumList(begin + 1, end, fn), fn);
}

int main(int argc, char const *argv[])
{
    std::cout << "add(1, -2, pow)" << std::endl;
    std::cout << add(1, -2, pow) << std::endl;

    std::vector<int> numList {1, -2};
    std::cout << "numList: {1, -2}\n";
    std::cout << "sumList(numList.begin(), numList.end(), pow)" << std::endl;
    std::cout << sumList(numList.begin(), numList.end(), pow) << std::endl;
    return 0;
}
