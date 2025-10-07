#include "Four.h"
#include <algorithm>
#include <cctype>

Four::Four() : size(0) {
    digits = std::vector<unsigned char>();
}

Four::Four(const size_t& n, unsigned char t) : size(n) {
    if (t > 3) {
        throw std::invalid_argument("Four digit must be between 0 and 3");
    }
    digits = std::vector<unsigned char>(n, t);
}

Four::Four(const std::initializer_list<unsigned char>& t) {
    for (auto digit : t) {
        if (digit > 3) {
            throw std::invalid_argument("Four digit must be between 0 and 3");
        }
    }
    digits = std::vector<unsigned char>(t);
    std::reverse(digits.begin(), digits.end());
    size = digits.size();
    removeLeadingZeros();
}

Four::Four(const std::string& t) {
    validateFourString(t);
    
    if (t.empty()) {
        size = 0;
        return;
    }
    
    for (auto it = t.rbegin(); it != t.rend(); ++it) {
        digits.push_back(*it - '0');
    }
    size = digits.size();
    removeLeadingZeros();
}

Four::Four(const Four& other) 
    : digits(other.digits), size(other.size) {
}

Four::~Four() noexcept {
}

Four& Four::operator=(const Four& other) {
    if (this != &other) {
        digits = other.digits;
        size = other.size;
    }
    return *this;
}

Four Four::add(const Four& other) const {
    return performAddition(other);
}

Four Four::subtract(const Four& other) const {
    return performSubtraction(other);
}

Four Four::copy() const {
    return Four(*this);
}

bool Four::equals(const Four& other) const {
    return digits == other.digits;
}

bool Four::lessThan(const Four& other) const {
    if (size != other.size) {
        return size < other.size;
    }
    
    for (int i = static_cast<int>(size) - 1; i >= 0; --i) {
        if (digits[i] != other.digits[i]) {
            return digits[i] < other.digits[i];
        }
    }
    return false;
}

bool Four::greaterThan(const Four& other) const {
    if (size != other.size) {
        return size > other.size;
    }
    
    for (int i = static_cast<int>(size) - 1; i >= 0; --i) {
        if (digits[i] != other.digits[i]) {
            return digits[i] > other.digits[i];
        }
    }
    return false;
}

std::string Four::toString() const {
    if (size == 0) return "0";
    
    std::string result;
    for (int i = static_cast<int>(size) - 1; i >= 0; --i) {
        result += std::to_string(digits[i]);
    }
    return result;
}

size_t Four::getSize() const {
    return size;
}

unsigned char Four::getDigit(size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return digits[index];
}

bool Four::isEmpty() const {
    return size == 0;
}


void Four::removeLeadingZeros() {
    while (size > 1 && digits.back() == 0) {
        digits.pop_back();
        --size;
    }
}

void Four::validateFourString(const std::string& str) const {
    if (str.empty()) return;
    
    for (char c : str) {
        if (!std::isdigit(c) || c < '0' || c > '3') {
            throw std::invalid_argument("String contains invalid four digit");
        }
    }
}

Four Four::performAddition(const Four& other) const {
    std::vector<unsigned char> result;
    size_t maxSize = std::max(size, other.size);
    unsigned char carry = 0;
    
    for (size_t i = 0; i < maxSize || carry; ++i) {
        unsigned char sum = carry;
        if (i < size) sum += digits[i];
        if (i < other.size) sum += other.digits[i];
        
        result.push_back(sum % 4);
        carry = sum / 4;
    }
    
    Four fourResult;
    fourResult.digits = result;
    fourResult.size = result.size();
    fourResult.removeLeadingZeros();
    
    return fourResult;
}

Four Four::performSubtraction(const Four& other) const {
    if (lessThan(other)) {
        throw std::invalid_argument("Result would be negative");
    }
    
    if (equals(other)) {
        return Four(1, 0);
    }
    
    std::vector<unsigned char> result;
    int borrow = 0;
    
    for (size_t i = 0; i < size; ++i) {
        int diff = digits[i] - borrow;
        if (i < other.size) {
            diff -= other.digits[i];
        }
        
        if (diff < 0) {
            diff += 4;
            borrow = 1;
        } else {
            borrow = 0;
        }
        
        result.push_back(static_cast<unsigned char>(diff));
    }
    
    Four fourResult;
    fourResult.digits = result;
    fourResult.size = result.size();
    fourResult.removeLeadingZeros();
    
    return fourResult;
}