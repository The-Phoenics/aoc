#include <vector>
#include <string>
#include <array>
#include <cmath>
#include <iostream>
#include <algorithm>

#include "../Utils.hpp"

// https://www.geeksforgeeks.org/sum-triangle-from-array/

using namespace std;

vector<int> modify(const vector<int>& nums)
{
    vector<int> newNums(nums.size() - 1);
    for (int i = 0; i < newNums.size(); i++) {
        newNums.at(i) = nums.at(i) + nums.at(i + 1);
    }
    return newNums;
}

void sumTriangleArray(const vector<int>& nums)
{
    if (nums.size() == 0) {
        // print(nums);
        return;
    }

    vector<int> modifiedArr = modify(nums);

    // recursive call
    sumTriangleArray(modifiedArr);
    print(nums);
}

void Solution()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    sumTriangleArray(nums);
}
