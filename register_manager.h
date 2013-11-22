#include <map>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

class RegisterManager {
public:
    static RegisterManager& getInstance() {
        static RegisterManager instance;
        return instance;
    }

    void freeRegister(string reg);
    void freeTempRegisters();
    void freeParamRegisters();
    void freeSavedRegisters();
    void freeReturnRegisters();
    void freeAllRegisters();

    string getTempRegister();
    string getSavedRegister();
    string getReturnRegister();
    string getParamRegister();
private:
    RegisterManager(); 
    map<string, int> tempRegisters;
    map<string, int> savedRegisters;
    map<string, int> paramRegisters;
    map<string, int> returnRegisters;
};