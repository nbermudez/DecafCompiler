#include <iostream>
#include <list>
#include <string>

using namespace std;

class ErrorHandler {
public:
    static ErrorHandler& getInstance() {
        static ErrorHandler instance;
        return instance;
    }
    
    void handleError(string errorMessage);
    void handleWarning(string errorWarning);
    string allErrors();
    string allWarnings();

    int getErrorCount() { return errors.size(); }
    int getWarningCount() { return warnings.size(); }
private:
    ErrorHandler(){}
    list<string> errors, warnings;
};