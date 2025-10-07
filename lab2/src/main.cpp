#include "Four.h"
#include <iostream>

int main() {
    try {
        // Создание объектов
        Four f1("123"); // 123 в четверичной системе (1*16 + 2*4 + 3 = 27 в десятичной)
        Four f2("31");  // 31 в четверичной системе (3*4 + 1 = 13 в десятичной)
        
        // Арифметические операции
        Four sum = f1.add(f2);     // 27 + 13 = 40 в десятичной = 220 в четверичной
        Four diff = f1.subtract(f2); // 27 - 13 = 14 в десятичной = 32 в четверичной
        Four copy = f1.copy();
        
        // Операции сравнения
        bool isEqual = f1.equals(f2);
        bool isLess = f1.lessThan(f2);
        bool isGreater = f1.greaterThan(f2);
        
        // Вывод результатов
        std::cout << "f1: " << f1.toString() << std::endl;
        std::cout << "f2: " << f2.toString() << std::endl;
        std::cout << "Sum: " << sum.toString() << std::endl;
        std::cout << "Difference: " << diff.toString() << std::endl;
        std::cout << "Copy: " << copy.toString() << std::endl;
        std::cout << "f1 equals f2: " << isEqual << std::endl;
        std::cout << "f1 less than f2: " << isLess << std::endl;
        std::cout << "f1 greater than f2: " << isGreater << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}