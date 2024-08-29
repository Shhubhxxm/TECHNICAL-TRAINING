#include <iostream>
#include <string>

// Function to replace substrings according to the given rules
std::string compressString(const std::string& str) {
    std::string temp; // Temporary string to hold the compressed string
    int len = str.length();

    for (int i = 0; i < len; ++i) {
        if (i < len - 1 && str[i] == '3' && str[i + 1] == '3') {
            temp += '2';
            temp += '3';
            ++i; // Skip the next character as it is part of the pattern
        } else if (i < len - 2 && str[i] == '2' && str[i + 1] == '2' && str[i + 2] == '2') {
            temp += '3';
            temp += '2';
            i += 2; // Skip the next two characters as they are part of the pattern
        } else if (str[i] == '5') {
            temp += '1';
            temp += '5';
        } else if (str[i] == '1') {
            temp += '1';
            temp += '1';
        } else {
            temp += str[i];
        }
    }

    return temp;
}

int main() {
    std::string str = "3322251";
    std::cout << "Original string: " << str << std::endl;

    std::string compressedStr = compressString(str);
    std::cout << "Compressed string: " << compressedStr << std::endl;

    return 0;
}
