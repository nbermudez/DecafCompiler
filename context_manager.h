#include <stack>
#include <map>
#include <string>
#include <iostream>
#include "Value.h"

using namespace std;

class VarInfo {
public:
    int offset_base;
    int size;
    Type type;
    VarInfo();
    VarInfo(int offset_base, int size, Type type);

};

class Context {
public:
    Context();
    int getOffset(string variable_name);
    void saveOffset(string variable_name, int offset);
    VarInfo* getVarInfo(string variable_name);
    void saveVarInfo(string variable_name, VarInfo *var_info);

    int transformOffset(int offset);

    Context *previous;

private:
    map<string, int> offsets;
    map<string, VarInfo*> variables;
};

#define MAX_DEEP_NESTING 10

class ContextManager {
public:
	static ContextManager& getInstance() {
        static ContextManager instance;
        return instance;
    }
    int getCurrentScopeSize();
    void popScopeSize();
    void pushScopeSize(int scopeSize);
    int getMaximumNesting();

    void registerContext(int displayPosition, Context *context);
    void unregisterContext(int displayPosition);

    int getOffset(int displayStartPosition, string variable_name);
    int getDeepLevel(int displayStartPosition, string variable_name);
    Type getType(int displayStartPosition, string variable_name);

    Context *getContext(int displayPosition);

    void pushUnregisterLogic(string unregisterLogic, bool belongsToLoop);
    void popUnregisterLogic();
    string getUnregisterLogic();
    bool unregisterLogicsIsEmpty();

    void pushEpilog(string epilog);
    void popEpilog();
    string getEpilog();
    bool epilogsIsEmpty();

    bool belongsToLoop();

private:
	ContextManager();
	stack<int> scopeSizes;
    stack<string> unregisterLogicStack;
    stack<string> epilogs;
    stack<bool> registeredBlockBelongsToLoop;

    Context* display[MAX_DEEP_NESTING];

};