#include "../Utils.hpp"

// https://www.geeksforgeeks.org/problems/geek-onacci-number/0

#define VOID_FUNCTION 0

using namespace std;

int solver(int a, int b, int c, int n) {
    if (n == 1)
        return a;
    if (n == 2)
        return b;
    if (n == 3)
        return c;
    
    return solver(a, b, c, n - 1) + solver(a, b, c, n - 2) + solver(a, b, c, n - 3);
}
void Solution()
{
    vector<int> input = {1, 3, 2, 6};
    cout << "Input: ";
    print(input);

    cout << "Output: ";
#if VOID_FUNCTION
    solver(input);
#else
    print(solver(input[0], input[1], input[2], input[3]));
#endif
}