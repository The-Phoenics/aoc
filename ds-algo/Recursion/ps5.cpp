#include <vector>
#include <string>
#include <array>
#include <cmath>
#include <iostream>
#include <algorithm>

#include "../Utils.hpp"

// https://leetcode.com/problems/reverse-string/

#define VOID_FUNCTION 1

using namespace std;

// revese a string/array in place
void rev(vector<char>& str, int e, int s = 0) {
    // swap till middle of the array
    if (s == str.size() / 2)
        return;

    std::swap(str.at(s++), str.at(e--));
    rev(str, e, s);
}

void reverseString(vector<char>& str)
{
    if (str.size() == 1)
        return;
    rev(str, str.size() - 1);
}

void Solution()
{
    vector<char> input = {'h','e','l','l','o'};
    cout << "Input: ";
    print(input);

    cout << "Output: ";
#if VOID_FUNCTION
    reverseString(input);
#else
    print(reverseString(input));
#endif
}