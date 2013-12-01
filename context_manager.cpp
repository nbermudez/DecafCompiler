#include "context_manager.h"

VarInfo::VarInfo() {

}

VarInfo::VarInfo(int offset_base, int size, Type type) {
	this->offset_base = offset_base;
	this->size = size;
	this->type = type;
}

/***********************************************************************************/

Context::Context() {
	previous = NULL;
}

int Context::getOffset(string variable_name) {
	cout << "printing map" << endl;
	map<string, VarInfo*>::iterator it = variables.begin();
	while (it != variables.end()) {
		cout << "var " << it->first << endl;
		it++;
	}
	cout << "end printing" << endl;
	VarInfo *var_info = getVarInfo(variable_name);
	if (var_info != NULL)
		return var_info->offset_base;
	return -1;
}

void Context::saveOffset(string variable_name, int offset) {
	VarInfo *var_info = getVarInfo(variable_name);
	if (var_info != NULL)
		var_info->offset_base = offset;
}

VarInfo* Context::getVarInfo(string variable_name) {
	if (variables.count(variable_name) > 0)
		return variables[variable_name];
	return NULL;
}

void Context::saveVarInfo(string variable_name, VarInfo *var_info) {
	variables[variable_name] = var_info;
}

int Context::transformOffset(int offset) {
	int off = variables.size()*4;
	return off - offset;
}

/***********************************************************************************/

ContextManager::ContextManager() {

}

int ContextManager::getMaximumNesting() {
	return MAX_DEEP_NESTING;
}

int ContextManager::getCurrentScopeSize() {
	if (scopeSizes.size()>0)
		return scopeSizes.top();
	else
		return 0;
}

void ContextManager::popScopeSize() {
	scopeSizes.pop();
}

void ContextManager::pushScopeSize(int scopeSize) {
	scopeSizes.push(scopeSize);
}

void ContextManager::registerContext(int displayPosition, Context *context) {
	context->previous = display[displayPosition];
	display[displayPosition] = context;
}

void ContextManager::unregisterContext(int displayPosition) {
	if (display[displayPosition] != NULL)
		display[displayPosition] = display[displayPosition]->previous;
}

int ContextManager::getOffset(int displayStartPosition, string variable_name) {
	cout << "getOffset called with " << displayStartPosition << " and " << variable_name << endl;
	while (displayStartPosition > 0) {
		Context *context = display[displayStartPosition];

		if (context == NULL) {
			displayStartPosition--;
			continue;
		}

		int offset = context->getOffset(variable_name);

		if (offset == -1) {
			displayStartPosition -= 1;
		} else {
			cout << "returning offset " << offset << endl;
			return offset;
		}
	}
	return -1;
}

int ContextManager::getDeepLevel(int displayStartPosition, string variable_name) {
	cout << "getOffset called with " << displayStartPosition << " and " << variable_name << endl;
	while (displayStartPosition > 0) {
		Context *context = display[displayStartPosition];

		if (context == NULL) {
			displayStartPosition--;
			continue;
		}

		int offset = context->getOffset(variable_name);

		if (offset == -1) {
			displayStartPosition -= 1;
		} else {
			cout << "returning offset " << offset << endl;
			return displayStartPosition;
		}
	}
	return -1;
}

Context *ContextManager::getContext(int displayPosition) {
	return display[displayPosition];
}

Type ContextManager::getType(int displayStartPosition, string variable_name) {
	while (displayStartPosition > 0) {
		Context *context = display[displayStartPosition];

		if (context == NULL) {
			displayStartPosition--;
			continue;
		}

		VarInfo *var_info = context->getVarInfo(variable_name);

		if (var_info == NULL) {
			displayStartPosition--;
		} else {
			return var_info->type;
		}
	}
	return Void;
}