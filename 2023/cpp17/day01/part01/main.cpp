#include <iostream>
#include <string>
#include <vector>
#include <fstream>

size_t sum = 0;

int getFirstLastNumCombination(std::string &str)
{
    int res = 0;
    for (size_t i = 0; i < str.size(); i++)
    {
        if (std::isdigit(str.at(i)))
        {
            res = str.at(i) - 48;
            res *= 10;
            break;
        }
    }
    for (size_t i = str.size() - 1; i >= 0; i--)
    {
        if (std::isdigit(str.at(i)))
        {
            res += str.at(i) - 48;
            break;
        }
    }
    return res;
}

size_t solve()
{
    std::ifstream input;
    input.open("input.txt");

    std::string str;
    while (std::getline(input, str))
    {
        sum += getFirstLastNumCombination(str);
    }
    return sum;
}

int main()
{
    auto ans = solve();
    std::cout << ans << std::endl;
}