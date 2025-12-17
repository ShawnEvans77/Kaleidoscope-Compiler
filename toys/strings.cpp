#include <iostream>
#include <string>

int main() {
    std::string word = "Hello World";

    std::cout << word[0] << '\n';
    std::cout << word.size() << '\n';

    word.push_back('!'); // you can add an exclamation mark to a string. 

    std::cout << word << '\n';
    word.pop_back(); // removes the element at the end - like a stack operation.

    std::cout << word << '\n';

    return 0;
}