#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

int first_integer_index(std::string& str)
{
    for (int i = 0; i < str.size(); i++) {
        if (std::isdigit(str.at(i))) {
            return i;
        }
    }
    return -1;
}

int get_game_id(std::string& str, int colonIndex)
{
    std::string gameId = str.substr(first_integer_index(str), colonIndex);
    if (!gameId.empty()) {
        return std::stoi(gameId);
    }
    return -1;
}

int get_space_count(std::string& str)
{
    int count = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str.at(i) == ' ')
            count++;
    }
    return count;
}

// return game id if game is valid otherwise, return 0
int get_valid_game_id(std::string& str)
{
    int rCount = 0;
    int gCount = 0;
    int bCount = 0;

    int indexOfColon = str.find(':');
    int game_id = get_game_id(str, indexOfColon);

    std::string cubesString = str.substr(indexOfColon + 1, str.size());
    int spaceCount = get_space_count(cubesString);

    int index = 0;
    for (int i = 0; i < spaceCount / 2; i++) {
        int colour_value = 0;

        if (cubesString.at(index) == ' ')
        {
            if (std::isdigit(cubesString.at(++index)))
            {
                // get integer from string
                int startIndex = index;
                while (std::isdigit(cubesString.at(index + 1))) {
                    index++;
                }
                colour_value = std::stoi(cubesString.substr(startIndex, index));
                index += 2;
            }
            if (cubesString.at(index) == 'r') {
                rCount += colour_value;
                index += std::string("red").size();
            }
            else if (cubesString.at(index) == 'g') {
                gCount += colour_value;
                index += std::string("green").size();
            }
            else {
                bCount += colour_value;
                index += std::string("blue").size();
            }
            index++;

            if (index - 1 == cubesString.size()) {
                if (rCount > 12 || gCount > 13 || bCount > 14) {
                    return 0;
                }
                else {
                    return game_id;
                }
            }

            if (cubesString.at(index - 1) == ';') {
                if (rCount > 12 || gCount > 13 || bCount > 14) {
                    return 0;
                }
                else {
                    rCount = 0;
                    gCount = 0;
                    bCount = 0;
                }
            }
        }
    }
    // valid game
    return game_id;
}

int solve()
{
    int result = 0;
    std::ifstream input;
    input.open("input.txt");

    std::string str;
    while (std::getline(input, str))
    {
        int game_id = get_valid_game_id(str);
        std::cout << game_id << std::endl;
        result += game_id;
    }
    return result;
}

int main()
{
    std::cout << solve() << std::endl;
}