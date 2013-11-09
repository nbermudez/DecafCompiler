#include "symbol_table.h"

SymbolTable::SymbolTable() {

}

void SymbolTable::addFunction(string methodName, Function function) {
    functions[methodName] = function;
}

Function SymbolTable::getFunction(string methodName) {
    return functions[methodName];
}

void SymbolTable::deleteFunction(string methodName) {
    functions.erase(methodName);
}

void SymbolTable::getFunctionCount() {
    return map.size();
}

Function::Function() {
    
}