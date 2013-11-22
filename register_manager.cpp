#include "register_manager.h"

RegisterManager::RegisterManager() {
	freeAllRegisters();
}

void RegisterManager::freeRegister(string reg) {
	if (tempRegisters.count(reg) != 0) {
		tempRegisters[reg] = 0;
	} else if (savedRegisters.count(reg) != 0) {
		savedRegisters[reg] = 0;
	} else if (returnRegisters.count(reg) != 0) {
		returnRegisters[reg] = 0;
	} else if (paramRegisters.count(reg) != 0) {
		paramRegisters[reg] = 0;
	}
}

void RegisterManager::freeTempRegisters() {
	for (int i = 0; i < 8; i++) {
        ostringstream out;
        out << "$t" << i;
        tempRegisters[out.str()] = 0;
    }
}

void RegisterManager::freeParamRegisters() {
	for (int i = 0; i < 4; i++) {
        ostringstream out;
        out << "$a" << i;
        paramRegisters[out.str()] = 0;
    }
}

void RegisterManager::freeSavedRegisters() {
	for (int i = 0; i < 8; i++) {
        ostringstream out;
        out << "$s" << i;
        savedRegisters[out.str()] = 0;
    }
}

void RegisterManager::freeReturnRegisters() {
	for (int i = 0; i < 2; i++) {
        ostringstream out;
        out << "$v" << i;
        returnRegisters[out.str()] = 0;
    }
}

void RegisterManager::freeAllRegisters() {
	freeTempRegisters();
    freeReturnRegisters();
    freeSavedRegisters();
    freeParamRegisters();
}

string RegisterManager::getTempRegister() {
	map<string, int>::iterator it = tempRegisters.begin();

	while (it != tempRegisters.end()) {
		if (it->second == 0) {
			tempRegisters[it->first] = 1;
			return it->first;
		}
		it++;
	}
	return "NOTMPREG";
}

string RegisterManager::getSavedRegister() {
	map<string, int>::iterator it = savedRegisters.begin();

	while (it != savedRegisters.end()) {
		if (it->second == 0) {
			savedRegisters[it->first] = 1;
			return it->first;
		}
		it++;
	}
	return "NOSAVEDREG";
}

string RegisterManager::getReturnRegister() {
	map<string, int>::iterator it = returnRegisters.begin();

	while (it != returnRegisters.end()) {
		if (it->second == 0) {
			returnRegisters[it->first] = 1;
			return it->first;
		}
		it++;
	}
	return "NORETREG";
}

string RegisterManager::getParamRegister() {
	map<string, int>::iterator it = paramRegisters.begin();

	while (it != paramRegisters.end()) {
		if (it->second == 0) {
			paramRegisters[it->first] = 1;
			return it->first;
		}
		it++;
	}
	return "NOPARAMREG";
}

