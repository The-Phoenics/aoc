#include <vector>
#include <string>
#include <array>
#include <cmath>
#include <iostream>
#include <algorithm>

#include "../Utils.hpp"

// https://leetcode.com/problems/binary-search/

#define VOID_FUNCTION 0

using namespace std;

// binary search using recursion
int bs(vector<int>& nums, int target, int s, int e);

int search(vector<int>& nums, int target) {
    return bs(nums, target, 0, nums.size() - 1);
}

int bs(vector<int>& nums, int target, int s, int e) {
    if (s > e)
        return -1;
    
    int mid = s + (e - s) / 2;
    if (nums.at(mid) == target)
        return mid;
    else if (nums.at(mid) > target)
        return bs(nums ,target, s, mid - 1);
    else
        return bs(nums ,target, mid + 1, e);
}

void Solution()
{
    vector<int> input = {1, 2, 3, 4, 5, 8, 6};
    cout << "Input: \n";
    print(input);
    
    int target;
    cout << "Enter target: ";
    cin >> target;

    cout << "Output: \n";
#if VOID_FUNCTION
    search(input, target);
#else
    print(search(input, target));
#endif
}