#pragma once
#include<bits/stdc++.h>
#include <iostream>

using namespace std;

// std::cout << std::boolalpha;

inline void operator<<(std::ostream& os, std::vector<int>& data) {
    std::cout << "[ ";
    for (int i: data) {
        os << i << " "; 
    }
    std::cout << "]\n";
}

inline void print(bool b) {
    if (b)
        cout << "true";
    else
        cout << "false";
    std::cout << std::endl;
}

inline void print(std::vector<int>& data) {
    std::cout << data;
}
