#include "../Utils.hpp"

// https://leetcode.com/problems/fibonacci-number/

#define VOID_FUNCTION 0

using namespace std;

int fib(int n)
{
    if (n <= 0)
        return 0;
    if (n == 1)
        return 1;

    return fib(n-1) + fib(n-2);
}

void Solution()
{
    int input = 3;
    cout << "Input: ";
    print(input);

    cout << "Output: ";
#if VOID_FUNCTION
    fib(input);
#else
    print(fib(input));
#endif
}