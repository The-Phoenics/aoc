#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

int first_integer_index(std::string &str)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (std::isdigit(str.at(i)))
        {
            return i;
        }
    }
    return -1;
}

int get_space_count(std::string &str)
{
    int count = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str.at(i) == ' ')
            count++;
    }
    return count;
}

int get_product_of_min_values(std::string &str)
{
    int rCount = 0;
    int gCount = 0;
    int bCount = 0;

    int indexOfColon = str.find(':');
    std::string cubesString = str.substr(indexOfColon + 1, str.size());
    int spaceCount = get_space_count(cubesString);

    int index = 0;
    for (int i = 0; i < spaceCount / 2; i++)
    {
        int colour_value = 0;
        if (cubesString.at(index) == ' ')
        {
            if (std::isdigit(cubesString.at(++index)))
            {
                // get integer from string
                int startIndex = index;
                while (std::isdigit(cubesString.at(index + 1)))
                {
                    index++;
                }
                colour_value = std::stoi(cubesString.substr(startIndex, index));
                index += 2;
            }
            if (cubesString.at(index) == 'r')
            {
                if (rCount < colour_value)
                {
                    rCount = colour_value;
                }
                // add colour string length to index
                index += std::string("red").size();
            }
            else if (cubesString.at(index) == 'g')
            {
                if (gCount < colour_value)
                {
                    gCount = colour_value;
                }
                index += std::string("green").size();
            }
            else
            {
                if (bCount < colour_value)
                {
                    bCount = colour_value;
                }
                index += std::string("blue").size();
            }
            // index++ to set it to next whitespace index value
            index++;
            if (index - 1 == cubesString.size())
                break;
        }
    }

    if (rCount == 0)
        rCount = 1;
    if (gCount == 0)
        gCount = 1;
    if (bCount == 0)
        bCount = 1;
    return rCount * gCount * bCount;
}

int solve()
{
    int result = 0;
    std::ifstream input;
    input.open("input.txt");

    std::string str;
    while (std::getline(input, str))
    {
        int res = get_product_of_min_values(str);
        result += res;
    }
    return result;
}

int main()
{
    std::cout << solve() << std::endl;
}