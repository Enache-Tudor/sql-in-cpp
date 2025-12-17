#pragma once
#include <fstream>

enum TypeID {
    INT_TYPE = 0,
    FLOAT_TYPE = 1,
    STRING_TYPE =2
};

class Value{
    public:
    virtual void print() const = 0;
    virtual Value* clone() const = 0;
    virtual void serialize(std::ofstream& out) const = 0;

    virtual ~Value() = default;
};