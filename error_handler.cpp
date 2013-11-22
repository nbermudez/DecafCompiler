#include "error_handler.h"

void ErrorHandler::handleFatal(int line, string fatalMessage) {
    cout << "\033[1;31m" << line << ": " << fatalMessage << "\033[0m\n";
    exit(1);
}

void ErrorHandler::handleError(int line, string errorMessage) {
    ostringstream out;

    out << line << ": " << errorMessage;
    this->errors.push_back(out.str());
}

void ErrorHandler::handleWarning(int line, string errorWarning) {
    ostringstream out;

    out << line << ": " << errorWarning;
    this->warnings.push_back(out.str());
}

string ErrorHandler::allErrors() {
    list<string>::iterator it = errors.begin();
    
    string result = "errors:\n";
    while (it != errors.end()) {
        result += "  " + (*it) + "\n";
        it++;
    }
    
    return result;
}

string ErrorHandler::allWarnings() {
    list<string>::iterator it = warnings.begin();
    
    string result = "";
    if (warnings.size()>0) 
        result = "warnings: \n";
    while (it != warnings.end()) {
        result += "  " + (*it) + "\n";
        it++;
    }
    
    return result;
}