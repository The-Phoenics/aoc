#include "../Utils.hpp"

// https://www.geeksforgeeks.org/recursive-programs-to-find-minimum-and-maximum-elements-of-array/

#define VOID_FUNCTION 0

using namespace std;

int maxVal(int a, int b) {
    if (a > b)
        return a;
    return b;
}

int minVal(int a, int b) {
    if (a > b)
        return b;
    return a;
}

// max value in an array
int findMaxRec(vector<int>& nums, int size)
{
    if (size == 1)
        return nums.at(0);

    return maxVal(nums.at(size - 1), findMaxRec(nums, size - 1));
}

// max value in an array
int findMinRec(vector<int>& nums, int counter = 0) {
    if (counter == nums.size()) {
        return nums.at(counter - 1);
    }
    return minVal(nums.at(counter), findMinRec(nums, counter + 1));
}

void Solution()
{
    vector<int> input = {6, 4, 3, 2, 5};
    cout << "Input: ";
    print(input);

    cout << "Output: ";
#if VOID_FUNCTION
    findMinRec(input);
#else
    print(findMinRec(input));
#endif
}