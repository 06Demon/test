#ifndef FOUR_H
#define FOUR_H

#include <string>
#include <vector>
#include <stdexcept>
#include <initializer_list> 

class Four {
private:
    std::vector<unsigned char> digits;
    size_t size;

    void removeLeadingZeros();
    void validateFourString(const std::string& str) const;
    Four performAddition(const Four& other) const;
    Four performSubtraction(const Four& other) const;

public:
    Four();
    Four(const size_t& n, unsigned char t = 0);
    Four(const std::initializer_list<unsigned char>& t);
    Four(const std::string& t);
    Four(const Four& other);
    
    virtual ~Four() noexcept;

    Four& operator=(const Four& other);

    Four add(const Four& other) const;
    Four subtract(const Four& other) const;
    Four copy() const;

    bool equals(const Four& other) const;
    bool lessThan(const Four& other) const;
    bool greaterThan(const Four& other) const;

    std::string toString() const;
    size_t getSize() const;
    unsigned char getDigit(size_t index) const;

    bool isEmpty() const;
};

#endif