#include <map>
#include <sstream>
#include <string>

using namespace std;

class LabelManager {
public:
    static LabelManager& getInstance() {
        static LabelManager instance;
        return instance;
    }

    string getIfLabel();
    string getWhileLabel();
    string getForLabel();
    string getElseLabel();
private:
    LabelManager(); 
    int if_count;
    int else_count;
    int while_count;
    int for_count;
};