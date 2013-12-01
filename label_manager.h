#include <map>
#include <sstream>
#include <string>
#include <stack>

using namespace std;

class LabelManager {
public:
    static LabelManager& getInstance() {
        static LabelManager instance;
        return instance;
    }

    string getIfLabel();
    string getWhileLabel();
    string getOutOfWhileLabel();
    string getEndIfLabel();
    string getForLabel();
    string getOutOfForLabel();
    string getElseLabel();
    string getFalseLabel();
    string getTrueLabel();
    string getEndLabel();
    string getContinueLabel();

    void pushCurrentWhileLabel(string label);
    void pushContinuePoint(string label);
    void pushCurrentForLabel(string label);
    void pushBreakPoint(string label);

    void popCurrentForLabel();
    void popCurrentWhileLabel();
    void popContinuePoint();
    void popCurrentBreakPoint();

    string getCurrentWhileLabel();
    string getCurrentContinuePoint();
    string getCurrentForLabel();
    string getCurrentBreakPoint();

    string getFunctionEndLabel();

private:
    LabelManager(); 
    int if_count;
    int endif_count;
    int else_count;
    int while_count;
    int continue_count;
    int out_of_while_count;
    int out_of_for_count;
    int for_count;
    int false_count, true_count, end_count;
    int function_end_count;

    stack<string> continuePoints;
    stack<string> whileLabels;
    stack<string> forLabels;
    stack<string> breakPoints;

};