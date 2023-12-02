#include <iostream>
#include <vector>

std::vector<char> decimalToBinary(int decimalNumber) {
    std::vector<char> binaryList;

    // Handle the case when the input is 0
    if (decimalNumber == 0) {
        binaryList.push_back('0');
        return binaryList;
    }

    while (decimalNumber > 0) {
        // Get the remainder when dividing by 2
        int remainder = decimalNumber % 2;

        // Convert the remainder to character and add to the front of the list
        binaryList.insert(binaryList.begin(), static_cast<char>('0' + remainder));

        // Update the decimal number by dividing it by 2
        decimalNumber /= 2;
    }

    return binaryList;
}

int main() {
    // Example usage
    int decimalNumber;
    std::cout << "Enter a decimal number: ";
    std::cin >> decimalNumber;

    std::vector<char> binaryList = decimalToBinary(decimalNumber);

    // Display the binary representation stored in the list
    std::cout << "Binary representation: ";
    for (char digit : binaryList) {
        std::cout << digit;
    }
    std::cout << std::endl;

    return 0;
}