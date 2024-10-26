#include <vector>
#include <string>
#include <array>
#include <cmath>
#include <iostream>
#include <algorithm>

#include "../Utils.hpp"

// https://www.geeksforgeeks.org/problems/print-1-to-n-without-using-loops-1587115620/1

#define VOID_FUNCTION 1

using namespace std;

void printUptoN(int n)
{
    if (n == 0)
        return;

    printUptoN(n - 1);
    std::cout << n << " ";
}

void Solution()
{
    int input = 11;
    cout << "Input: ";
    print(input);

    cout << "Output: ";
#if VOID_FUNCTION
    printUptoN(input);
    cout << endl;
#else
    print(printUptoN(input));
#endif
}