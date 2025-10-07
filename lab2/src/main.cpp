#include "Four.h"
#include <iostream>

int main() {
    Four n1("12");
    Four n2("1");
    
    Four sum = n1.add(n2);
    Four diff = n1.subtract(n2);
    Four copy = n1.copy();
    
    bool isEqual = n1.equals(n2);
    bool isLess = n1.lessThan(n2);
    bool isGreater = n1.greaterThan(n2);
    
    std::cout << "number 1: " << n1.toString() << std::endl;
    std::cout << "number 2: " << n2.toString() << std::endl;
    std::cout << "Sum: " << sum.toString() << std::endl;
    std::cout << "Difference: " << diff.toString() << std::endl;
    std::cout << "Copy: " << copy.toString() << std::endl;
    std::cout << "n1 equals n2: " << isEqual << std::endl;
    std::cout << "n1 less than n2: " << isLess << std::endl;
    std::cout << "n1 greater than n2: " << isGreater << std::endl;

    return 0;
}