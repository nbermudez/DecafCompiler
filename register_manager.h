#include <map>
#include <sstream>
#include <string>

using namespace std;

class RegisterManager {
public:
    static RegisterManager& getInstance() {
        static RegisterManager instance;
        return instance;
    }

    void freeRegister(string reg);
    string getTempRegister();
    string getSavedRegister();
    string getReturnRegister();
private:
    RegisterManager(); 
    map<string, int> tempRegisters;
    map<string, int> savedRegisters;
    map<string, int> paramRegisters;
    map<string, int> returnRegisters;
};