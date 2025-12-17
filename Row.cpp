#include "Row.h"

Row::Row(){

}

Row::~Row(){
    for(Value* c : cells){
        delete c;
    }
    cells.clear();
}

Row::Row(const Row& r){
    for(Value* c: r.cells){
        cells.push_back(c->clone());
    }
}