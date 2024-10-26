#include <vector>
#include <string>
#include <array>
#include <cmath>
#include <iostream>
#include <algorithm>

#include "../Utils.hpp"

// https://www.geeksforgeeks.org/first-uppercase-letter-in-a-string-iterative-and-recursive/

#define VOID_FUNCTION 0

using namespace std;

bool isUpperCase(char ch) {
    return ch >= 'A' && ch <= 'Z';
}

// find first uppercase character in string
char solver(std::string& str, int counter = 0)
{
    if (counter == str.size())
        return '1';

    if (isUpperCase(str.at(counter)))
        return str.at(counter);

    return solver(str, counter + 1);
}

void Solution()
{
    std::string input = "prIMe";
    cout << "Input: ";
    print(input);

    cout << "Output: ";
#if VOID_FUNCTION
    solver(input);
#else
    print(solver(input));
#endif
}