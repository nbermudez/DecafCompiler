#include "error_handler.h"

void ErrorHandler::handleError(string errorMessage) {
    this->errors.push_back(errorMessage);
}

void ErrorHandler::handleWarning(string errorWarning) {
    this->warnings.push_back(errorWarning);
}

string ErrorHandler::allErrors() {
    list<string>::iterator it = errors.begin();
    
    string result = "";
    while (it != errors.end()) {
        result += (*it);
    }
    
    return result;
}

string ErrorHandler::allWarnings() {
    list<string>::iterator it = warnings.begin();
    
    string result = "";
    while (it != warnings.end()) {
        result += (*it);
    }
    
    return result;
}