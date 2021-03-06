#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

const std::vector<int> matchingStrings(std::vector<stqd::string>& strings,
                                        std::vector<std::string>& queries)
{
    std::vector<int> matches(queries.size(), 0);

    for (int i = 0; i < queries.size(); ++i)
    {
        for (int j = 0; j < strings.size(); ++j)
        {
            if(strings.at(j) == queries.at(i))
                matches.at(i)++;
        }
    }

    return matches;
}

template<typename T>
bool checkVectors(std::vector<T>& v1, std::vector<T>& v2)
{
    return v1.size() == v2.size() &&  std::equal(v1.begin(), v1.end(), v2.begin());
}

template<typename T>
void printVector(std::vector<T> v1)
{
    for(auto& elem : v1)
        std::cout << elem << " ";
    std::cout << std::endl;
}

void testMatchingStrings(std::vector<std::string>& strings,
                            std::vector<std::string>& queries,
                            std::vector<int>& wanted)
{
    std::vector<int> got (matchingStrings(strings, queries));

    if (checkVectors(wanted, got) == false)
    {
        std::cout << "not passed" << std::endl;

        std::cout << "wanted: " << std::endl;
        printVector(wanted);

        std::cout << "got: " << std::endl;
        printVector(got);
    } else {
        std::cout << "all ok\n";
    }
}

int main(void)
{
    std::vector<std::string> str1{"aba", "baba", "aba", "xzxb"};
    std::vector<std::string> q1{"aba", "xzxb", "ab"};
    std::vector<int> r1{2, 1, 0};

    std::vector<std::string> str2{"ab", "abc", "ab"};
    std::vector<std::string> q2{"ab", "abc", "bd"};
    std::vector<int> r2{2, 1, 0};

    testMatchingStrings(str1, q1, r1);
    testMatchingStrings(str2, q2, r2);

    return 0;
}