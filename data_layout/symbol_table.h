#include <cstring>
#include <map>

using namespace std;

class SymbolTable {
public:
    SymbolTable();
    
    void addFunction(string methodName, Function function);
    Function getFunction(string methodName);
    void deleteFunction(string methodName);
    int getFunctionCount();
    
private:
    map<string, Function> functions;
};

class Function {
public:
    Function();
    
private:
    DecoratedBlockStatement *body;
    list<SimpleVariable *> parameters;
    ReturnType  type;
};