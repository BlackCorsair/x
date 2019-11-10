# How to TDD with Hacker Rank Challenges - Sparse Array (C++)

This challenge want us to return a std::vector of integer which count how many times a *query* has been found in a *vector of strings*.

For example:
* query: {"aba", "xzxb", "ab"}
* strings: {"aba", "baba", "aba", "xzxb"}
* expected result: {2, 1, 0}

The function is called *matchingStrings*, it receives two vectors of strings and returns one vector of integers:
```cpp
const std::vector<int> matchingStrings(std::vector<std::string>& strings, std::vector<std::string>& queries)
```

## Code your tests first

As the acronym says, first make the tests, but do not rush into it as you may need to refactor multiple times your tests if you don't think them first!

### Think what do you need to test

We need to check that out function which returns -> ```std::vector<int> matches``` matches another expected vector, so we should make a function that compares vectors and gives us an ok or a nok:

```cpp
#include <iostream>
#include <vector>
#include <string>

int checkVectors(std::vector<int>& v1, std::vector<int>& v2)
{
    if (v1.size() != v2.size())
        return -1;
    for (int i = 0; i < v1.size(); ++i)
    {
        if (v1.at(i) != v2.at(i))
            return -1;
    }
    return 1;
}
```

### Complete your testing "framework"

Now that we have our *core* testing framework, let's add a wrapper that pretty prints our tests and let us call easily our test function:

```cpp
...

void printVector(std::vector<int> v1)
{
    std::cout << "{";
    for (int i = 0; i < v1.size(); ++i)
    {
        if (i != v1.size() - 1)
        {
            std::cout << v1.at(i) << ", ";
        } else {
            std::cout << v1.at(i);
        }
    }
    std::cout << "}" << std::endl;
}

void testMatchingStrings(std::vector<std::string>& strings,
                            std::vector<std::string>& queries, 
                            std::vector<int>& wanted)
{
    std::vector<int> got (matchingStrings(strings, queries));
    
    if (checkVectors(wanted, got) == -1)
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
```

## Test - Make sure your code fails

The first thing after writting your code (and in this case, checking that it compiles), is to test it!

You should write the minimum required code to make sure your code **fails successfully** *(insert confusing screaming meme here)*:

```cpp
...

const std::vector<int> matchingStrings(std::vector<std::string>& strings, 
                                        std::vector<std::string>& queries)
{
    std::vector<int> matches{0, 0, 0};

    return matches;
}

...

int main(void)
{
    std::vector<std::string> str1{"aba", "baba", "aba", "xzxb"};
    std::vector<std::string> q1{"aba", "xzxb", "ab"};
    std::vector<int> r1{2, 1, 0};
    
    testMatchingStrings(str1, q1, r1);
    
    return 0;
}
```

After you compile && run your code, it should fails saying:
```
not passed
wanted:
{2, 1, 0}
got:
{0, 0, 0}
```

Perfect! Our code failed the way we expected, we *should* add it to git now.

## Refactor your code so it passes your tests

Write the minimum amount of code to pass your tests:

```cpp
...

const std::vector<int> matchingStrings(std::vector<std::string>& strings, 
                                        std::vector<std::string>& queries)
{
    std::vector<int> matches{2, 1, 0};

    return matches;
}

...
```

You could commit this code... or just skip to the part where you actually add real code.

## Add more test cases so your minimum code fails

```cpp
...

const std::vector<int> matchingStrings(std::vector<std::string>& strings, 
                                        std::vector<std::string>& queries)
{
    std::vector<int> matches{0, 0, 0};

    return matches;
}

...

int main(void)
{
    std::vector<std::string> str1{"aba", "baba", "aba", "xzxb"};
    std::vector<std::string> q1{"aba", "xzxb", "ab"};
    std::vector<int> r1{2, 1, 0};

    std::vector<std::string> str2{"ab", "abc", "ab"};
    std::vector<std::string> q2{"ab", "abc", "bd"};
    std::vector<int> r2{2, 1};
    
    testMatchingStrings(str1, q1, r1);
    testMatchingStrings(str2, q2, r2);
    
    return 0;
}
```

Expected failures:
```
all ok
not passed
wanted:
{2, 1, 0}
got:
{0, 0, 0}
```

We could have more detailed logs... but that's a problem for our future ourselves ;) 

Commit your new test cases.

## Refactor your code so it passes al test cases

```cpp
...

const std::vector<int> matchingStrings(std::vector<std::string>& strings, 
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

...
```

Run your tests...
```
all ok
all ok
```

Sucess!!! Let's commit this working code and call it a day :)

```cpp
#include <iostream>
#include <vector>
#include <string>

const std::vector<int> matchingStrings(std::vector<std::string>& strings, 
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

int checkVectors(std::vector<int>& v1, std::vector<int>& v2)
{
    if (v1.size() != v2.size())
        return -1;
    for (int i = 0; i < v1.size(); ++i)
    {
        if (v1.at(i) != v2.at(i))
            return -1;
    }
    return 1;
}

void printVector(std::vector<int> v1)
{
    std::cout << "{";
    for (int i = 0; i < v1.size(); ++i)
    {
        if (i != v1.size() - 1)
        {
            std::cout << v1.at(i) << ", ";
        } else {
            std::cout << v1.at(i);
        }
    }
    std::cout << "}" << std::endl;
}

void testMatchingStrings(std::vector<std::string>& strings,
                            std::vector<std::string>& queries, 
                            std::vector<int>& wanted)
{
    std::vector<int> got (matchingStrings(strings, queries));
    
    if (checkVectors(wanted, got) == -1)
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
```

And that's it, now you can change your function however you want knowing that you'll know if it's functionality is affected.
