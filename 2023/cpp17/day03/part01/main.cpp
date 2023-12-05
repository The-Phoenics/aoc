#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct Parts
{
    static void load_from_file()
    {
        std::ifstream input("input.txt");
        std::string line;
        while (std::getline(input, line))
        {
            partsVector.push_back(line);
        }
        input.close();
    }
    static const std::string& get_at(int index)
    {
        return partsVector.at(index);
    }
    static size_t size()
    {
        return partsVector.size();
    }
    static std::vector<std::string> partsVector;
};

std::vector<std::string> Parts::partsVector;

bool check_line(const std::string& str)
{
    for (char ch : str)
    {
        if (ch != '.' && !std::isdigit(ch))
            return true;
    }
    return false;
}

//  check right and left to the current value in string
bool check_left_and_right(const std::string& line, int sIndex, int eIndex)
{
    char left_char;
    char right_char;

    // checking only left when string is at right most
    if (eIndex >= line.size() - 1 && sIndex > 0) {
        left_char = line.at(sIndex - 1);
        if (left_char != '.' && !std::isdigit(left_char)) {
            return true;
        }
    }
    // checking only right when string is at left most
    else if (sIndex == 0 && eIndex < line.size() - 1) {
        right_char = line.at(eIndex + 1);
        if (right_char != '.' && !std::isdigit(right_char)) {
            return true;
        }
    }
    // checking both left and right when string is somewhere in between
    else {
        left_char = line.at(sIndex - 1);
        right_char = line.at(eIndex + 1);
        if (left_char != '.' && !std::isdigit(left_char)) {
            return true;
        }
        if (right_char != '.' && !std::isdigit(right_char)) {
            return true;
        }
    }
    // doesn't exist
    return false;
}

// check string at row_index if contains any character in given range
bool check_row(int row_index, int sIndex, int eIndex, int count)
{
    if (row_index > 0) {
        const std::string& strAboveLine = Parts::get_at(row_index - 1);
        const std::string& strAbove = strAboveLine.substr(sIndex, count);
        // check above diagonals and middle
        if (check_left_and_right(strAboveLine, sIndex, eIndex) || check_line(strAbove))
            return true;
    }
    if (row_index < Parts::size() - 1)
    {
        const std::string& strBelowLine = Parts::get_at(row_index + 1);
        const std::string& strBelow = strBelowLine.substr(sIndex, count);
        // check below diagonals and middle
        if (check_left_and_right(strBelowLine, sIndex, eIndex) || check_line(strBelow))
            return true;
    }

    std::string line = Parts::get_at(row_index);
    // check left and right character to the part number
    if (check_left_and_right(line, sIndex, eIndex)) {
        return true;
    }
    return false;
}

void check_part(int* result, int row_index)
{
    const std::string& line = Parts::get_at(row_index);
    for (int i = 0; i < line.size(); i++)
    {
        int value = 0;
        if (std::isdigit(line.at(i)))
        {
            // num of digits in the value integer
            int count_of_value = 0;
            // extract integer value
            int start = i;
            int end = i;
            while (std::isdigit(line.at(end))) {
                end++;
                count_of_value++;
                if (end == line.size())
                    break;
            }

            std::string num = line.substr(start, end);
            value = std::stoi(num);

            // check if its a valid part
            if (check_row(row_index, start, end - 1, count_of_value)) {
                *result += value;
            }
            i = end;
        }
    }
}

int solve()
{
    int result = 0;
    for (int i = 0; i < Parts::size(); i++) {
       check_part(&result, i);
    }
    return result;
}

int main()
{
    Parts::load_from_file();
    std::cout << solve() << std::endl;
}