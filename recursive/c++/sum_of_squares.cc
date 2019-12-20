#include <iostream>
#include <vector>

bool is_odd(int number)
{
    return number % 2 == 1;
}

int square(int x)
{
    return x * x;
}

int sum_numbers_in_list(const std::vector<int> &numbers)
{
    if (numbers.size() == 1)
        return numbers.at(0);

    return numbers.at(0) + sum_numbers_in_list(
                               std::vector<int>(numbers.begin() + 1, numbers.end()));
}

template <typename T>
std::vector<T> extend_vector(const std::vector<T> &v1, const std::vector<T> &v2)
{
    if (v2.empty())
        return v1;

    if (v1.empty())
        return v2;

    std::vector<T> concatenated{v1};
    std::copy(v2.begin(), v2.end(), std::back_inserter(concatenated));

    return concatenated;
}

template <typename T>
void print_vector(const std::vector<T> &vector)
{
    std::cout << "[ ";
    for (auto &element : vector)
    {
        std::cout << element << " ";
    }
    std::cout << "]" << std::endl;
}

std::vector<int> filter_odds_from_list(const std::vector<int> &numbers)
{
    if (numbers.empty())
        return {};
    if (numbers.size() == 1 && is_odd(numbers.at(0)))
        return numbers;
    if (numbers.size() == 1 && !is_odd(numbers.at(0)))
        return {};

    std::vector<int> odds{filter_odds_from_list({numbers.at(0)})};

    return extend_vector(
        odds, filter_odds_from_list({numbers.begin() + 1, numbers.end()}));
}

std::vector<int> squared_odds_from_list(const std::vector<int> &numbers)
{
    if (numbers.empty())
        return {};
    if (numbers.size() == 1)
    {
        if (is_odd(numbers.at(0)))
        {
            return {square(numbers.at(0))};
        }
        return {};
    }

    std::vector<int> filtered {filter_odds_from_list(numbers)};

    return extend_vector(
        {filtered.at(0)},
        squared_odds_from_list({filtered.begin() + 1, filtered.end()}));
}

int main(int argc, char const *argv[])
{
    
    std::vector<int> v1{1, 2, 3};
    std::vector<int> v2{2, 3, 4};

    std::cout << sum_numbers_in_list(v1) << std::endl;
    std::cout << sum_numbers_in_list(extend_vector(v1, v2)) << std::endl;

    std::cout << "extend vectors" << std::endl;
    print_vector(extend_vector(v1, v2));

    std::cout << "filter odds" << std::endl;
    print_vector(filter_odds_from_list(v1));
    print_vector(filter_odds_from_list(v2));
    
    std::cout << "squared odds" << std::endl;
    print_vector(squared_odds_from_list(v1));
    print_vector(squared_odds_from_list(v2));

    return 0;
}