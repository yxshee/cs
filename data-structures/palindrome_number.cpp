#include <iostream>

bool isPalindrome(int x) {
    if (x < 0) return false;

    int original = x;
    int reversed = 0;

    while (x != 0) {
        int digit = x % 10;
        reversed = reversed * 10 + digit;
        x /= 10;
    }

    return original == reversed;
}

int main() {
    int num;
    std::cout << "Enter an integer: ";
    std::cin >> num;

    if (isPalindrome(num)) {
        std::cout << num << " is a palindrome." << std::endl;
    } else {
        std::cout << num << " is not a palindrome." << std::endl;
    }

    return 0;
}