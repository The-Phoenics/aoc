#include "helper.hpp"
#include <print>

int main() {
    bool a = false;
    bool b = true;
    std::vector<int> vec = {1, 3, 4};
    // std::cout << std::boolalpha << a << ", " << b << std::endl;
    std::print("{}", vec);
}
