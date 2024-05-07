#include "../Utils.hpp"

// https://www.geeksforgeeks.org/recursive-programs-to-find-minimum-and-maximum-elements-of-array/

#define PRINTING_PROBLEM 0

using namespace std;

int findMaxRec(vector<int>& nums)
{


    return 2;
}

void Solution()
{
    vector<int> input = {1, 2, 3, 4, 5};
    cout << "Input: ";
    print(input);

    cout << "Output: ";
#if PRINTING_PROBLEM
    findMaxRec(input);
#else
    print(findMaxRec(input));
#endif
}