#pragma once
#include <iostream>
#include <vector>
#include "ConcreteValues.h"

class Row{
    private:
    std::vector<Value*> cells;
    public:
    Row();
    ~Row();
    Row(const Row& r);
    Row& operator=(const Row& r);

    void addInt(int v);
    void addFloat(float v);
    void addString(std::string v);

    void saveRow(std::ofstream& out);
    void loadRow(std::ifstream& in);
};