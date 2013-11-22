#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <stdlib.h>

using namespace std;

class ErrorHandler {
public:
    static ErrorHandler& getInstance() {
        static ErrorHandler instance;
        return instance;
    }
    
    void handleFatal(int line, string fatalMessage);
    void handleError(int line, string errorMessage);
    void handleWarning(int line, string errorWarning);
    string allErrors();
    string allWarnings();

    int getErrorCount() { return errors.size(); }
    int getWarningCount() { return warnings.size(); }
private:
    ErrorHandler(){}
    list<string> errors, warnings;
};