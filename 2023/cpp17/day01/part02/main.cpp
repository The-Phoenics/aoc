#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::pair<int, int> getFirstStringDigit(std::string& str)
{
    std::pair<int, int> result; // index, digit_value
    int index = -1;
    int digit_value = -1;
    static const std::vector<std::string> alpha_numerics = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    for (int i = 1; i <= alpha_numerics.size(); i++)
    {
        int tmp = str.find(alpha_numerics.at(i - 1));
        if (tmp == -1)
            continue;
        
        // on finding first occurrence of any word
        if (index == -1 && tmp > index) {
            index = tmp;
            digit_value = i;
        }

        if (tmp < index) {
            index = tmp;
            digit_value = i;
        }
    }
    result.first = index;
    result.second = digit_value;
    return result;
}

std::pair<int, int> getLastStringDigit(std::string& str)
{
    std::pair<int, int> result;
    int index = -1;
    int digit_value = -1;
    static const std::vector<std::string> alpha_numerics = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    for (int i = 1; i <= alpha_numerics.size(); i++)
    {
        int tmp = str.rfind(alpha_numerics.at(i - 1));
        if (tmp == -1)
            continue;

        // on finding first occurrence of any word
        if (index == -1 && tmp > index) {
            index = tmp;
            digit_value = i;
        }

        if (tmp > index) {
            index = tmp;
            digit_value = i;
        }
    }
    result.first = index;
    result.second = digit_value;
    return result;
}

int firstDigit(std::string& str)
{
    int firstDigitIndex = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (std::isdigit(str.at(i)))
        {
            firstDigitIndex = i;
            break;
        }
    }

    auto&& [strDigitIndex, strDigitValue] = getFirstStringDigit(str);
    if (strDigitIndex == -1)
        return str.at(firstDigitIndex) - 48;

    if (firstDigitIndex < strDigitIndex)
        return str.at(firstDigitIndex) - 48;

    else
        return strDigitValue;
}

int secondDigit(std::string& str)
{
    int secondDigitIndex = 0;
    for (int i = str.size() - 1; i >= 0; i--)
    {
        if (std::isdigit(str.at(i)))
        {
            secondDigitIndex = i;
            break;
        }
    }

    auto&& [strDigitIndex, strDigitValue] = getLastStringDigit(str);
    if (secondDigitIndex > strDigitIndex)
        return str.at(secondDigitIndex) - 48;

    else
        return strDigitValue;
}

int getFirstLastNumCombination(std::string& str)
{
    int first_digit = firstDigit(str);
    int second_digit = secondDigit(str);
    int result = first_digit * 10 + second_digit;
    return result;
}

int solve()
{
    int sum = 0;
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
    std::string str = "cplmhhrlh5";
    std::cout << solve() << std::endl;
}