#pragma once
#include <iostream>
#include "Value.h"

class IntValue : public Value{
private:
    int val;
public:
    IntValue(int v){
        val = v;
    }
    void print() const override{
        std::cout << val;
    }
    Value* clone() const override{
        return new IntValue(val);
    }
    void serialize(std::ofstream& out) const override{
        char id = INT_TYPE;
        out.write(&id, sizeof(char));
        out.write((char*)&val, sizeof(int));
    }
};
class FloatValue : public Value{
private:
    float val;
public:
    FloatValue(float v){
        val = v;
    }
    void print() const override{
        std::cout << val;
    }
    Value* clone() const override{
        return new FloatValue(val);
    }
    void serialize(std::ofstream& out) const override{
        char id = FLOAT_TYPE;
        out.write(&id, sizeof(char));
        out.write((char*)&val, sizeof(float));
    }
};
class StringValue : public Value{
private:
    std::string val;
public:
    StringValue(std::string v){
        val = v;
    }
    void print() const override{
        std::cout <<" " << val << " ";
    }
    Value* clone() const override{
        return new StringValue(val);
    }
    void serialize(std::ofstream& out) const override{
        char id = STRING_TYPE;
        out.write(&id, sizeof(char));
        int length = val.size();
        out.write((char*)&length, sizeof(int));
        out.write(val.c_str(), length);
    }
};