#include "../Utils.hpp"

// https://www.geeksforgeeks.org/program-for-length-of-a-string-using-recursion/

#define VOID_FUNCTION 0

using namespace std;

int strLength(const std::string& str, int count = 0)
{
    if (str[count] == '\0')
        return count;
    return strLength(str, ++count);
}

void Solution()
{
    std::string input = "string";
    cout << "Input: ";
    print(input);

    cout << "Output: ";
#if VOID_FUNCTION
    strLength(input);
#else
    print(strLength(input));
#endif
}