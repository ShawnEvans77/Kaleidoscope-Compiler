#include <vector>
#include <iostream>

int main() {
    std::vector<int> list;
    list.push_back(20);
    list.insert(std::begin(list), 100); // insert is a function that accepts an iterator as input.
    list.insert(std::end(list) - 1, 500); // std::begin && std::end function as a form of iterators. 
    
    for (int i = 0; i < list.size(); i++) {
        std::cout << list.at(i) << ' ';
    }

    return 0;
}