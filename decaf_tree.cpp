/* decaf_tree.cpp.  Generated automatically by treecc */
#line 73 "decaf_tree.tc"

	#include "decaf_tree.h"
	int statement_line;
	int deepLevel = 0;
	int currentScopeSize = 0;

    bool insideLoop = false;
    bool breakFound = false;
    bool continueFound = false;
    bool returnFound = false;

    ExpressionType *currentReturnType = NULL; 

    Function *currentFunction = NULL;
    Context *context = NULL;

    LocalVariablesMap *local_variables = NULL;	

	string OperatorToString(ExpressionOperator oper) {
		switch (oper)
		{
			case OpAdd: return "+";
			case OpSub: return "-";
			case OpMul: return "*";
			case OpDiv: return "/";
			case OpMod: return "%";
			case OpAnd: return "&&";
			case OpOr: return "||";
			case OpNot: return "!";
			case OpGT: return ">";
			case OpLT: return "<";
			case OpGTE: return ">=";
			case OpLTE: return "<=";
			case OpEq: return "==";
			case OpNotEq: return "!=";
			case OpRShift: return ">>";
			case OpLShift: return "<<";
			case OpRot: return "rot";
			default:
					return "Unknown";
		}
	}

	ExpressionType *TypeToExpressionType(Type type) {
		ExpressionType *newType = NULL;
		switch (type) {
			case Int:
				newType = new IntegerType();
				break;
			case Boolean:
				newType = new BooleanType();
				break;
			case Void:
				newType = new VoidType();
				break;
		}

		return newType;
	}

	bool isUnreachableStatement() {
		if (continueFound || breakFound || returnFound)
			return true;
		return false;
	}
#line 1 "decaf_semantic_tree.tc"

    #include "label_manager.h"

    string indent(int count) {
        ostringstream out;
        out << string(count, ' ');
        return out.str();
    }
    int string_count = 0;
    string getStringLabel() {
        ostringstream out;

        out << "string_" << string_count++;

        return out.str();
    }

    string function_end;
    
#line 17 "symbol_table.tc"

	static SymbolTable *symbol_table = NULL;
#line 92 "decaf_tree.cpp"

#define YYNODESTATE_TRACK_LINES 1
#define YYNODESTATE_USE_ALLOCATOR 1
#line 1 "cpp_skel.cc"
/*
 * treecc node allocation routines for C++.
 *
 * Copyright (C) 2001  Southern Storm Software, Pty Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * As a special exception, when this file is copied by treecc into
 * a treecc output file, you may use that output file without restriction.
 */

#ifndef YYNODESTATE_BLKSIZ
#define	YYNODESTATE_BLKSIZ	2048
#endif

/*
 * Types used by the allocation routines.
 */
struct YYNODESTATE_block
{
	char data__[YYNODESTATE_BLKSIZ];
	struct YYNODESTATE_block *next__;

};
struct YYNODESTATE_push
{
	struct YYNODESTATE_push *next__;
	struct YYNODESTATE_block *saved_block__;
	int saved_used__;
};

/*
 * Initialize the singleton instance.
 */
#ifndef YYNODESTATE_REENTRANT
YYNODESTATE *YYNODESTATE::state__ = 0;
#endif

/*
 * Some macro magic to determine the default alignment
 * on this machine.  This will compile down to a constant.
 */
#define	YYNODESTATE_ALIGN_CHECK_TYPE(type,name)	\
	struct _YYNODESTATE_align_##name { \
		char pad; \
		type field; \
	}
#define	YYNODESTATE_ALIGN_FOR_TYPE(type)	\
	((unsigned)(&(((struct _YYNODESTATE_align_##type *)0)->field)))
#define	YYNODESTATE_ALIGN_MAX(a,b)	\
	((a) > (b) ? (a) : (b))
#define	YYNODESTATE_ALIGN_MAX3(a,b,c) \
	(YYNODESTATE_ALIGN_MAX((a), YYNODESTATE_ALIGN_MAX((b), (c))))
YYNODESTATE_ALIGN_CHECK_TYPE(int, int);
YYNODESTATE_ALIGN_CHECK_TYPE(long, long);
#if defined(WIN32) && !defined(__CYGWIN__)
YYNODESTATE_ALIGN_CHECK_TYPE(__int64, long_long);
#else
YYNODESTATE_ALIGN_CHECK_TYPE(long long, long_long);
#endif
YYNODESTATE_ALIGN_CHECK_TYPE(void *, void_p);
YYNODESTATE_ALIGN_CHECK_TYPE(float, float);
YYNODESTATE_ALIGN_CHECK_TYPE(double, double);
#define	YYNODESTATE_ALIGNMENT	\
	YYNODESTATE_ALIGN_MAX( \
			YYNODESTATE_ALIGN_MAX3	\
			(YYNODESTATE_ALIGN_FOR_TYPE(int), \
		     YYNODESTATE_ALIGN_FOR_TYPE(long), \
			 YYNODESTATE_ALIGN_FOR_TYPE(long_long)), \
  	     YYNODESTATE_ALIGN_MAX3 \
		 	(YYNODESTATE_ALIGN_FOR_TYPE(void_p), \
			 YYNODESTATE_ALIGN_FOR_TYPE(float), \
			 YYNODESTATE_ALIGN_FOR_TYPE(double)))

/*
 * Constructor for YYNODESTATE.
 */
YYNODESTATE::YYNODESTATE()
{
	/* Initialize the allocation state */
	blocks__ = 0;
	push_stack__ = 0;
	used__ = 0;

#ifndef YYNODESTATE_REENTRANT
	/* Register this object as the singleton instance */
	if(!state__)
	{
		state__ = this;
	}
#endif
}

/*
 * Destructor for YYNODESTATE.
 */
YYNODESTATE::~YYNODESTATE()
{
	/* Free all node memory */
	clear();

#ifndef YYNODESTATE_REENTRANT
	/* We are no longer the singleton instance */
	if(state__ == this)
	{
		state__ = 0;
	}
#endif
}

#ifdef YYNODESTATE_USE_ALLOCATOR

/*
 * Allocate a block of memory.
 */
void *YYNODESTATE::alloc(size_t size__)
{
	struct YYNODESTATE_block *block__;
	void *result__;

	/* Round the size to the next alignment boundary */
	size__ = (size__ + YYNODESTATE_ALIGNMENT - 1) &
				~(YYNODESTATE_ALIGNMENT - 1);

	/* Do we need to allocate a new block? */
	block__ = blocks__;
	if(!block__ || (used__ + size__) > YYNODESTATE_BLKSIZ)
	{
		if(size__ > YYNODESTATE_BLKSIZ)
		{
			/* The allocation is too big for the node pool */
			return (void *)0;
		}
		block__ = new YYNODESTATE_block;
		if(!block__)
		{
			/* The system is out of memory.  The programmer can
			   inherit the "failed" method to report the
			   out of memory state and/or abort the program */
			failed();
			return (void *)0;
		}
		block__->next__ = blocks__;
		blocks__ = block__;
		used__ = 0;
	}

	/* Allocate the memory and return it */
	result__ = (void *)(block__->data__ + used__);
	used__ += size__;
	return result__;
}

/*
 * Deallocate a block of memory.
 */
void YYNODESTATE::dealloc(void *ptr__, size_t size__)
{
	/* Nothing to do for this type of node allocator */
}

/*
 * Push the node allocation state.
 */
int YYNODESTATE::push()
{
	struct YYNODESTATE_block *saved_block__;
	int saved_used__;
	struct YYNODESTATE_push *push_item__;

	/* Save the current state of the node allocation pool */
	saved_block__ = blocks__;
	saved_used__ = used__;

	/* Allocate space for a push item */
	push_item__ = (struct YYNODESTATE_push *)
			alloc(sizeof(struct YYNODESTATE_push));
	if(!push_item__)
	{
		return 0;
	}

	/* Copy the saved information to the push item */
	push_item__->saved_block__ = saved_block__;
	push_item__->saved_used__ = saved_used__;

	/* Add the push item to the push stack */
	push_item__->next__ = push_stack__;
	push_stack__ = push_item__;
	return 1;
}

/*
 * Pop the node allocation state.
 */
void YYNODESTATE::pop()
{
	struct YYNODESTATE_push *push_item__;
	struct YYNODESTATE_block *saved_block__;
	struct YYNODESTATE_block *temp_block__;

	/* Pop the top of the push stack */
	push_item__ = push_stack__;
	if(push_item__ == 0)
	{
		saved_block__ = 0;
		used__ = 0;
	}
	else
	{
		saved_block__ = push_item__->saved_block__;
		used__ = push_item__->saved_used__;
		push_stack__ = push_item__->next__;
	}

	/* Free unnecessary blocks */
	while(blocks__ != saved_block__)
	{
		temp_block__ = blocks__;
		blocks__ = temp_block__->next__;
		delete temp_block__;
	}
}

/*
 * Clear the node allocation pool completely.
 */
void YYNODESTATE::clear()
{
	struct YYNODESTATE_block *temp_block__;
	while(blocks__ != 0)
	{
		temp_block__ = blocks__;
		blocks__ = temp_block__->next__;
		delete temp_block__;
	}
	push_stack__ = 0;
	used__ = 0;
}

#endif /* YYNODESTATE_USE_ALLOCATOR */

/*
 * Default implementation of functions which may be overridden.
 */
void YYNODESTATE::failed()
{
}

#ifdef YYNODESTATE_TRACK_LINES

char *YYNODESTATE::currFilename()
{
	return (char *)0;
}

long YYNODESTATE::currLinenum()
{
	return 0;
}

#endif
#line 371 "decaf_tree.cpp"
void *SymbolTable::operator new(size_t size__)
{
	return YYNODESTATE::getState()->alloc(size__);
}

void SymbolTable::operator delete(void *ptr__, size_t size__)
{
	YYNODESTATE::getState()->dealloc(ptr__, size__);
}

SymbolTable::SymbolTable()
{
	this->kind__ = SymbolTable_kind;
	this->filename__ = YYNODESTATE::getState()->currFilename();
	this->linenum__ = YYNODESTATE::getState()->currLinenum();
}

SymbolTable::~SymbolTable()
{
	// not used
}

void SymbolTable::registerFunction(string name, Function * function)
#line 121 "symbol_table.tc"
{
	this->functions[name] = function;
}
#line 399 "decaf_tree.cpp"

void SymbolTable::registerVariable(string name, Variable * variable)
#line 127 "symbol_table.tc"
{
	this->variables[name] = variable;
}
#line 406 "decaf_tree.cpp"

void SymbolTable::registerString(string stringValue)
#line 133 "symbol_table.tc"
{
	if (this->strings.count(stringValue) == 0)
		this->strings[stringValue] = getStringLabel();
}
#line 414 "decaf_tree.cpp"

int SymbolTable::getFunctionsCount()
#line 140 "symbol_table.tc"
{
	return this->functions.size();
}
#line 421 "decaf_tree.cpp"

Function * SymbolTable::getFunction(string name)
#line 155 "symbol_table.tc"
{
	if (this->functions.count(name)>0)
		return this->functions[name];
	else
		return NULL;
}
#line 431 "decaf_tree.cpp"

Variable * SymbolTable::getVariable(string variable_name)
#line 164 "symbol_table.tc"
{
	if (this->variables.count(variable_name) > 0) {
		return this->variables[variable_name];
	} else {
		return NULL;
	}
}
#line 442 "decaf_tree.cpp"

string SymbolTable::getString(string string_key)
#line 174 "symbol_table.tc"
{
	if (this->strings.count(string_key) > 0)
		return this->strings[string_key];
	else
		return NULL;
}
#line 452 "decaf_tree.cpp"

FunctionsMap * SymbolTable::getFunctions()
#line 183 "symbol_table.tc"
{
	return &(this->functions);
}
#line 459 "decaf_tree.cpp"

VariablesMap * SymbolTable::getVariables()
#line 189 "symbol_table.tc"
{
	return &(this->variables);
}
#line 466 "decaf_tree.cpp"

StringsMap * SymbolTable::getStrings()
#line 195 "symbol_table.tc"
{
	return &(this->strings);
}
#line 473 "decaf_tree.cpp"

int SymbolTable::isA(int kind) const
{
	if(kind == SymbolTable_kind)
		return 1;
	else
		return 0;
}

const char *SymbolTable::getKindName() const
{
	return "SymbolTable";
}

void *Function::operator new(size_t size__)
{
	return YYNODESTATE::getState()->alloc(size__);
}

void Function::operator delete(void *ptr__, size_t size__)
{
	YYNODESTATE::getState()->dealloc(ptr__, size__);
}

Function::Function()
{
	this->kind__ = Function_kind;
	this->filename__ = YYNODESTATE::getState()->currFilename();
	this->linenum__ = YYNODESTATE::getState()->currLinenum();
	this->body = 0;
	this->activation_size = 4;
}

Function::~Function()
{
	// not used
}

void Function::setBody(DecoratedBlockStatement * body)
#line 30 "symbol_table.tc"
{
	this->body = body;
}
#line 517 "decaf_tree.cpp"

int Function::getParameterRegsNeededCount()
#line 36 "symbol_table.tc"
{
	return this->parameters.size()>4?4:this->parameters.size();
}
#line 524 "decaf_tree.cpp"

bool Function::mustReturnSomething()
#line 42 "symbol_table.tc"
{
	return type == Int || type == Boolean;
}
#line 531 "decaf_tree.cpp"

int Function::offsetFromFp(string parameterName)
#line 48 "symbol_table.tc"
{
	Variable *var = findParameter(parameterName);
	if (var == NULL)
		return -1;
	int offset = parameters.size()>4?4:parameters.size();
	offset = -(offset - ((SimpleVariable*)var)->parameterId)*4;

	return offset;
}
#line 544 "decaf_tree.cpp"

Variable * Function::getParameter(int parameterId)
#line 60 "symbol_table.tc"
{
	if (parameterId > parameters.size() || parameterId < 0) {
		return NULL;
	}
	int i = 0;
	list<SimpleVariable*>::iterator it = parameters.begin();

	while (it != parameters.end()) {
		if (i == parameterId)
			return (*it);
		it++;
		i++;
	}
	return NULL;
}
#line 563 "decaf_tree.cpp"

Variable * Function::findParameter(string parameterName)
#line 78 "symbol_table.tc"
{
	list<SimpleVariable*>::iterator it = parameters.begin();

	while (it != parameters.end()) {
		if ((*it)->variable_name == parameterName)
			return (*it);
		it++;
	}
	return NULL;
}
#line 577 "decaf_tree.cpp"

int Function::isA(int kind) const
{
	if(kind == Function_kind)
		return 1;
	else
		return 0;
}

const char *Function::getKindName() const
{
	return "Function";
}

void *ExpressionType::operator new(size_t size__)
{
	return YYNODESTATE::getState()->alloc(size__);
}

void ExpressionType::operator delete(void *ptr__, size_t size__)
{
	YYNODESTATE::getState()->dealloc(ptr__, size__);
}

ExpressionType::ExpressionType()
{
	this->kind__ = ExpressionType_kind;
	this->filename__ = YYNODESTATE::getState()->currFilename();
	this->linenum__ = YYNODESTATE::getState()->currLinenum();
}

ExpressionType::~ExpressionType()
{
	// not used
}

int ExpressionType::isA(int kind) const
{
	if(kind == ExpressionType_kind)
		return 1;
	else
		return 0;
}

const char *ExpressionType::getKindName() const
{
	return "ExpressionType";
}

FloatType::FloatType()
	: ExpressionType()
{
	this->kind__ = FloatType_kind;
}

FloatType::~FloatType()
{
	// not used
}

bool FloatType::isEquivalent(ExpressionType * secondType)
#line 15 "decaf_types.tc"
{
    FloatType *casted_to_float = dynamic_cast<FloatType*>(secondType);
    if (casted_to_float != NULL) {
        return true;
    } else {
        IntegerType *casted_to_int = dynamic_cast<IntegerType*>(secondType);
        if (casted_to_int != NULL) {
            return true;
        } else {
            return false;
        }
    }
}
#line 653 "decaf_tree.cpp"

bool FloatType::isNumeric()
#line 73 "decaf_types.tc"
{
    return true;
}
#line 660 "decaf_tree.cpp"

bool FloatType::isBoolean()
#line 96 "decaf_types.tc"
{
    return false;
}
#line 667 "decaf_tree.cpp"

string FloatType::stringValue()
#line 119 "decaf_types.tc"
{
    return "float";
}
#line 674 "decaf_tree.cpp"

int FloatType::isA(int kind) const
{
	if(kind == FloatType_kind)
		return 1;
	else
		return ExpressionType::isA(kind);
}

const char *FloatType::getKindName() const
{
	return "FloatType";
}

StringType::StringType()
	: ExpressionType()
{
	this->kind__ = StringType_kind;
}

StringType::~StringType()
{
	// not used
}

bool StringType::isEquivalent(ExpressionType * secondType)
#line 43 "decaf_types.tc"
{
    StringType *casted_to_string = dynamic_cast<StringType*>(secondType);
    if (casted_to_string != NULL) {
        return true;
    } else {
        return false;
    }
}
#line 710 "decaf_tree.cpp"

bool StringType::isNumeric()
#line 85 "decaf_types.tc"
{
    return false;
}
#line 717 "decaf_tree.cpp"

bool StringType::isBoolean()
#line 108 "decaf_types.tc"
{
    return false;
}
#line 724 "decaf_tree.cpp"

string StringType::stringValue()
#line 131 "decaf_types.tc"
{
    return "string";
}
#line 731 "decaf_tree.cpp"

int StringType::isA(int kind) const
{
	if(kind == StringType_kind)
		return 1;
	else
		return ExpressionType::isA(kind);
}

const char *StringType::getKindName() const
{
	return "StringType";
}

IntegerType::IntegerType()
	: ExpressionType()
{
	this->kind__ = IntegerType_kind;
}

IntegerType::~IntegerType()
{
	// not used
}

bool IntegerType::isEquivalent(ExpressionType * secondType)
#line 29 "decaf_types.tc"
{
    FloatType *casted_to_float = dynamic_cast<FloatType*>(secondType);
    if (casted_to_float != NULL) {
        return true;
    } else {
        IntegerType *casted_to_int = dynamic_cast<IntegerType*>(secondType);
        if (casted_to_int != NULL) {
            return true;
        } else {
            return false;
        }
    }
}
#line 772 "decaf_tree.cpp"

bool IntegerType::isNumeric()
#line 77 "decaf_types.tc"
{
    return true;
}
#line 779 "decaf_tree.cpp"

bool IntegerType::isBoolean()
#line 100 "decaf_types.tc"
{
    return false;
}
#line 786 "decaf_tree.cpp"

string IntegerType::stringValue()
#line 123 "decaf_types.tc"
{
    return "integer";
}
#line 793 "decaf_tree.cpp"

int IntegerType::isA(int kind) const
{
	if(kind == IntegerType_kind)
		return 1;
	else
		return ExpressionType::isA(kind);
}

const char *IntegerType::getKindName() const
{
	return "IntegerType";
}

BooleanType::BooleanType()
	: ExpressionType()
{
	this->kind__ = BooleanType_kind;
}

BooleanType::~BooleanType()
{
	// not used
}

bool BooleanType::isEquivalent(ExpressionType * secondType)
#line 52 "decaf_types.tc"
{
    BooleanType *casted_to_boolean = dynamic_cast<BooleanType*>(secondType);
    if (casted_to_boolean != NULL) {
        return true;
    } else {
        return false;
    }
}
#line 829 "decaf_tree.cpp"

bool BooleanType::isNumeric()
#line 81 "decaf_types.tc"
{
    return false;
}
#line 836 "decaf_tree.cpp"

bool BooleanType::isBoolean()
#line 104 "decaf_types.tc"
{
    return true;
}
#line 843 "decaf_tree.cpp"

string BooleanType::stringValue()
#line 127 "decaf_types.tc"
{
    return "boolean";
}
#line 850 "decaf_tree.cpp"

int BooleanType::isA(int kind) const
{
	if(kind == BooleanType_kind)
		return 1;
	else
		return ExpressionType::isA(kind);
}

const char *BooleanType::getKindName() const
{
	return "BooleanType";
}

VoidType::VoidType()
	: ExpressionType()
{
	this->kind__ = VoidType_kind;
}

VoidType::~VoidType()
{
	// not used
}

bool VoidType::isEquivalent(ExpressionType * secondType)
#line 61 "decaf_types.tc"
{
    VoidType *casted_to_void = dynamic_cast<VoidType*>(secondType);
    if (casted_to_void != NULL) {
        return true;
    } else {
        return false;
    }
}
#line 886 "decaf_tree.cpp"

bool VoidType::isNumeric()
#line 89 "decaf_types.tc"
{
    return false;
}
#line 893 "decaf_tree.cpp"

bool VoidType::isBoolean()
#line 112 "decaf_types.tc"
{
    return false;
}
#line 900 "decaf_tree.cpp"

string VoidType::stringValue()
#line 135 "decaf_types.tc"
{
    return "void";
}
#line 907 "decaf_tree.cpp"

int VoidType::isA(int kind) const
{
	if(kind == VoidType_kind)
		return 1;
	else
		return ExpressionType::isA(kind);
}

const char *VoidType::getKindName() const
{
	return "VoidType";
}

void *LocalVariable::operator new(size_t size__)
{
	return YYNODESTATE::getState()->alloc(size__);
}

void LocalVariable::operator delete(void *ptr__, size_t size__)
{
	YYNODESTATE::getState()->dealloc(ptr__, size__);
}

LocalVariable::LocalVariable(ExpressionType * type, string variable_name)
{
	this->kind__ = LocalVariable_kind;
	this->filename__ = YYNODESTATE::getState()->currFilename();
	this->linenum__ = YYNODESTATE::getState()->currLinenum();
	this->type = type;
	this->variable_name = variable_name;
}

LocalVariable::~LocalVariable()
{
	// not used
}

int LocalVariable::isA(int kind) const
{
	if(kind == LocalVariable_kind)
		return 1;
	else
		return 0;
}

const char *LocalVariable::getKindName() const
{
	return "LocalVariable";
}

void *DecoratedNode::operator new(size_t size__)
{
	return YYNODESTATE::getState()->alloc(size__);
}

void DecoratedNode::operator delete(void *ptr__, size_t size__)
{
	YYNODESTATE::getState()->dealloc(ptr__, size__);
}

DecoratedNode::DecoratedNode()
{
	this->kind__ = DecoratedNode_kind;
	this->filename__ = YYNODESTATE::getState()->currFilename();
	this->linenum__ = YYNODESTATE::getState()->currLinenum();
}

DecoratedNode::~DecoratedNode()
{
	// not used
}

int DecoratedNode::isA(int kind) const
{
	if(kind == DecoratedNode_kind)
		return 1;
	else
		return 0;
}

const char *DecoratedNode::getKindName() const
{
	return "DecoratedNode";
}

DecoratedClass::DecoratedClass(string name)
	: DecoratedNode()
{
	this->kind__ = DecoratedClass_kind;
	this->name = name;
	this->main = NULL;
}

DecoratedClass::~DecoratedClass()
{
	// not used
}

string DecoratedClass::generateCode(int indentLevel)
#line 937 "decaf_semantic_tree.tc"
{
    ostringstream out;

    out << ".data" << endl;

    /*********************** Registering Variables **********************/
    map<string, Variable*> *variables = getSymbolTableInstance()->getVariables();
    map<string, Variable*>::iterator variable_it = variables->begin();

    while (variable_it != variables->end()) {
        Variable *variable = variable_it->second;

        out << variable_it->first ;
        SimpleVariable *simpleVariable = dynamic_cast<SimpleVariable*>(variable);
        if (simpleVariable != NULL) {
            out << ": .word ";
            if (variable->initialized) {
                if (((DecoratedIntConstant*)simpleVariable->initial_value) != NULL)
                    out << ((DecoratedIntConstant*)simpleVariable->initial_value)->value << endl;
                else
                    out << ((DecoratedBooleanConstant*)simpleVariable->initial_value)->value << endl;
            } else {
                out << 0 << endl;
            }
        } else {
            int size = ((ArrayVariable*)variable)->size;
            out << ": .space " << (size * 4) << " # " << size << " integers" << endl;
        }
        variable_it++;
    }

    out << "#special data" << endl;
    out << "display: .word 0:" << (MAX_DEEP_NESTING - 1) << endl;

    /*********************** Registering Strings **********************/

    map<string, string> *strings = getSymbolTableInstance()->getStrings();
    map<string, string>::iterator string_it = strings->begin();

    while (string_it != strings->end()) {
        out << string_it->second << ": .asciiz " << string_it->first << endl;
        string_it++;
    }

    out << endl << endl;

     /*********************** Registering Functions **********************/

    out << ".text" << endl;
    out << this->name << ":" << endl;
    out << "j main" << endl << endl;

    map<string, Function*> *functions = getSymbolTableInstance()->getFunctions();
    map<string, Function*>::iterator function = functions->begin();

    string indentation = indent(indentLevel);

    while (function != functions->end()) {
        ostringstream functionCode;

        out << indentation << function->first << ":" << endl;
        currentFunction = function->second;

        function_end = LabelManager::getInstance().getFunctionEndLabel();

        if (function->second->body != NULL) {
            functionCode << indentation << "# function body code" << endl;
            functionCode << function->second->body->generateCode(indentLevel + 1);
            functionCode << indentation << "# end of function body code" << endl;
        }

        if (function->first == "main") {
            functionCode << indentation << "li $v0, 10" << endl;
            functionCode << indentation << "syscall" << endl;
        }

        list<string> toSaveRegisters;
        int count = currentFunction->getParameterRegsNeededCount();
        for (int i = 0; i < count; i++) {
            ostringstream o;
            o << "$a" << i;
            toSaveRegisters.push_back(o.str());
        }

        ostringstream prologo, epilogo;

        prologo << indentation << "#prolog for " << function->first << endl;

        prologo << indentation << "addi $sp, $sp, -8" << endl;

        /* Save $ra */
        prologo << indentation << "sw $ra, 0($sp)" << endl;

        /* Save $fp */
        prologo << indentation << "sw $fp, 4($sp)" << endl;

        /* Set $fp */
        prologo << indentation << "move $fp, $sp" << endl;

        int offset = 0;

        prologo << indentation << "addi $sp, $sp, -" << (toSaveRegisters.size()*4) << endl;

        /* Save registers */
        list<string>::iterator regToSaveIterator = toSaveRegisters.begin();
        while (regToSaveIterator != toSaveRegisters.end()) {
            prologo << indentation << "sw " << (*regToSaveIterator) << ", " << offset << "($sp)" << endl;
            offset += 4;
            regToSaveIterator++;
        }
        prologo << indentation << "#end of prolog for " << function->first << endl;

        /*regToSaveIterator = toSaveRegisters.begin();
        offset = 0;
        while (regToSaveIterator != toSaveRegisters.end()) {
            epilogo << indentation << "lw " << (*regToSaveIterator) << ", " << offset << "($sp)" << endl;
            offset += 4;
            regToSaveIterator++;
        }

        epilogo << indentation << "addi $sp, $sp, " << (toSaveRegisters.size()*4) << endl;
        epilogo << indentation << "lw $fp, 4($sp)" << endl;
        epilogo << indentation << "lw $ra, 0($sp)" << endl;
        epilogo << indentation << "addi $sp, $sp, 8" << endl;*/

        RegisterManager::getInstance().freeAllRegisters();

        out << prologo.str();
        out << functionCode.str();
        //out << function_end << ":" << endl;
        //out << epilogo.str();
        //out << indentation << "jr $ra" << endl;
        out << endl << endl;

        function++;
    }
    return out.str();
}
#line 1147 "decaf_tree.cpp"

int DecoratedClass::isA(int kind) const
{
	if(kind == DecoratedClass_kind)
		return 1;
	else
		return DecoratedNode::isA(kind);
}

const char *DecoratedClass::getKindName() const
{
	return "DecoratedClass";
}

DecoratedExpression::DecoratedExpression(ExpressionType * type)
	: DecoratedNode()
{
	this->kind__ = DecoratedExpression_kind;
	this->type = type;
	this->place = "";
	this->line = 0;
}

DecoratedExpression::~DecoratedExpression()
{
	// not used
}

int DecoratedExpression::isA(int kind) const
{
	if(kind == DecoratedExpression_kind)
		return 1;
	else
		return DecoratedNode::isA(kind);
}

const char *DecoratedExpression::getKindName() const
{
	return "DecoratedExpression";
}

DecoratedStatement::DecoratedStatement(int line)
	: DecoratedNode()
{
	this->kind__ = DecoratedStatement_kind;
	this->line = line;
}

DecoratedStatement::~DecoratedStatement()
{
	// not used
}

int DecoratedStatement::isA(int kind) const
{
	if(kind == DecoratedStatement_kind)
		return 1;
	else
		return DecoratedNode::isA(kind);
}

const char *DecoratedStatement::getKindName() const
{
	return "DecoratedStatement";
}

DecoratedBinaryExpression::DecoratedBinaryExpression(ExpressionType * type, DecoratedExpression * left, DecoratedExpression * right)
	: DecoratedExpression(type)
{
	this->kind__ = DecoratedBinaryExpression_kind;
	this->left = left;
	this->right = right;
}

DecoratedBinaryExpression::~DecoratedBinaryExpression()
{
	// not used
}

int DecoratedBinaryExpression::isA(int kind) const
{
	if(kind == DecoratedBinaryExpression_kind)
		return 1;
	else
		return DecoratedExpression::isA(kind);
}

const char *DecoratedBinaryExpression::getKindName() const
{
	return "DecoratedBinaryExpression";
}

DecoratedUnaryExpression::DecoratedUnaryExpression(ExpressionType * type, DecoratedExpression * expression)
	: DecoratedExpression(type)
{
	this->kind__ = DecoratedUnaryExpression_kind;
	this->expression = expression;
}

DecoratedUnaryExpression::~DecoratedUnaryExpression()
{
	// not used
}

int DecoratedUnaryExpression::isA(int kind) const
{
	if(kind == DecoratedUnaryExpression_kind)
		return 1;
	else
		return DecoratedExpression::isA(kind);
}

const char *DecoratedUnaryExpression::getKindName() const
{
	return "DecoratedUnaryExpression";
}

DecoratedConstant::DecoratedConstant(ExpressionType * type)
	: DecoratedExpression(type)
{
	this->kind__ = DecoratedConstant_kind;
}

DecoratedConstant::~DecoratedConstant()
{
	// not used
}

int DecoratedConstant::isA(int kind) const
{
	if(kind == DecoratedConstant_kind)
		return 1;
	else
		return DecoratedExpression::isA(kind);
}

const char *DecoratedConstant::getKindName() const
{
	return "DecoratedConstant";
}

DecoratedLValue::DecoratedLValue(ExpressionType * type, string variable_name, DecoratedExpression * array_index)
	: DecoratedExpression(type)
{
	this->kind__ = DecoratedLValue_kind;
	this->variable_name = variable_name;
	this->array_index = array_index;
	this->deepLevel = 0;
	this->offset = 0;
	this->isGlobal = false;
	this->isParameter = false;
}

DecoratedLValue::~DecoratedLValue()
{
	// not used
}

string DecoratedLValue::generateCode(int indentLevel)
#line 541 "decaf_semantic_tree.tc"
{
    ostringstream out;

    string reg = RegisterManager::getInstance().getTempRegister();
    Context *context = ContextManager::getInstance().getContext(this->deepLevel);

    string indentation = indent(indentLevel);
    out << indentation << "# " << variable_name << endl;

    if (isGlobal) {
        
        out << indentation << "la " << reg << ", " << variable_name << endl;
        if (array_index != NULL) {
            out << array_index->generateCode(indentLevel + 1);
            out << indent(indentLevel + 1) << "sll " << array_index->place 
                << ", " << array_index->place << ", 2" << "# multiply by 4" << endl;
            out << indentation << "add " << reg << ", " << reg << ", " 
                << array_index->place << endl;
        }
        
    } else if (isParameter) {
        out << indentation << "addi " << reg << ", $fp, " << this->offset << endl;
        out << indentation << "#param: " << variable_name << " offset " << this->offset << endl;
    } else {
        out << indentation << "la " << reg << ", display" << endl;
        out << indentation << "addi " << reg << ", " << reg << ", " << (this->deepLevel*4) << endl;
        out << indentation << "lw " << reg << ", 0(" << reg << ")" << endl;
        out << indentation << "addi " << reg << ", " << reg << ", " << context->transformOffset(this->offset) << endl;
        out << indentation << "#local: " << variable_name << " offset " << this->offset
            << " level " << this->deepLevel << endl;
    }
    out << indentation << "lw " << reg << ", 0(" << reg << ")" << endl;
    this->place =  reg;

    return out.str();
}
#line 1344 "decaf_tree.cpp"

string DecoratedLValue::getLocation(int indentLevel)
#line 1078 "decaf_semantic_tree.tc"
{
    ostringstream out;

    string reg;
    reg = RegisterManager::getInstance().getSavedRegister();

    Context *context = ContextManager::getInstance().getContext(this->deepLevel);

    string indentation;
    indentation = indent(indentLevel);

    out << indentation << "#var " << variable_name << endl;

    if (isGlobal) {
        
        out << indentation << "la " << reg << ", " << variable_name << endl;
        if (array_index != NULL) {
            out << array_index->generateCode(indentLevel + 1);
            out << indent(indentLevel + 1) << "sll " << array_index->place 
                << ", " << array_index->place << ", 2" << "# multiply by 4" << endl;
            out << indentation << "add " << reg << ", " << reg << ", " 
                << array_index->place << endl;
        }
        
    } else if (isParameter) {
        out << indentation << "addi " << reg << ", $fp, " << this->offset << endl;
        out << indentation << "#param: " << variable_name << " offset " << this->offset << endl;
    } else {
        out << indentation << "la " << reg << ", display" << endl;
        out << indentation << "addi " << reg << ", " << reg << ", " << (this->deepLevel*4) << endl;
        out << indentation << "lw " << reg << ", 0(" << reg << ")" << endl;
        out << indentation << "addi " << reg << ", " << reg << ", " << context->transformOffset(this->offset) << endl;
        out << indentation << "#local: " << variable_name << " offset " << this->offset
            << " level " << this->deepLevel << endl;
    }
    this->place =  reg;

    return out.str();
}
#line 1387 "decaf_tree.cpp"

int DecoratedLValue::isA(int kind) const
{
	if(kind == DecoratedLValue_kind)
		return 1;
	else
		return DecoratedExpression::isA(kind);
}

const char *DecoratedLValue::getKindName() const
{
	return "DecoratedLValue";
}

DecoratedMethodCallExpression::DecoratedMethodCallExpression(ExpressionType * type, string name, DecoratedExpressionList * arguments)
	: DecoratedExpression(type)
{
	this->kind__ = DecoratedMethodCallExpression_kind;
	this->name = name;
	this->arguments = arguments;
}

DecoratedMethodCallExpression::~DecoratedMethodCallExpression()
{
	// not used
}

string DecoratedMethodCallExpression::generateCode(int indentLevel)
#line 578 "decaf_semantic_tree.tc"
{
    ostringstream out; 

    string indentation = indent(indentLevel + 1);

    list<DecoratedExpression*>::iterator it = arguments->begin();
    int argc = 0;
    out << indentation << "#method call " << name << endl;
    list<string> toSaveRegisters;
    int offset = 0;
    int paramsInReg = arguments->size()/* >= 4? arguments->size() - 4: 0*/;

    out << indentation << "addi $sp, $sp, " << (-4*paramsInReg) << "#arguments" << endl;

    while (it != arguments->end()) {
        DecoratedExpression *argument = (*it);
        if (argc <= 4) {//usar $a0...$a3
            string param;
            param = RegisterManager::getInstance().getParamRegister();

            out << argument->generateCode(indentLevel + 1);
            out << indentation << "#saving previous value" << endl;
            toSaveRegisters.push_front(param);
            out << indentation << "sw " << param << ", " << offset << "($sp)" << endl;
            offset += 4;
            
            out << indentation << "#end saving" << endl;
            out << indent(indentLevel) << "move " << param << ", " << argument->place << endl;
            RegisterManager::getInstance().freeRegister(argument->place);
        } else {
            //poner en la pila
        }
        it++;
    }
    out << indent(indentLevel) << "jal " << name << endl;

    list<string>::iterator string_iterator = toSaveRegisters.begin();
    int size = -offset;
    offset = 0;
    while (string_iterator != toSaveRegisters.end()) {        
        out << indentation << "lw " << (*string_iterator) << ", " << offset << "($sp)" << endl;
        offset += 4;     
        
        string_iterator++;
    }
    out << indentation << "addi $sp, $sp, " << size << endl;

    out << indentation << "#end method call" << name << endl;

    RegisterManager::getInstance().freeParamRegisters();
    
    this->place = "$v0";

    return out.str();
}
#line 1472 "decaf_tree.cpp"

int DecoratedMethodCallExpression::isA(int kind) const
{
	if(kind == DecoratedMethodCallExpression_kind)
		return 1;
	else
		return DecoratedExpression::isA(kind);
}

const char *DecoratedMethodCallExpression::getKindName() const
{
	return "DecoratedMethodCallExpression";
}

DecoratedAddExpression::DecoratedAddExpression(ExpressionType * type, DecoratedExpression * left, DecoratedExpression * right)
	: DecoratedBinaryExpression(type, left, right)
{
	this->kind__ = DecoratedAddExpression_kind;
}

DecoratedAddExpression::~DecoratedAddExpression()
{
	// not used
}

string DecoratedAddExpression::generateCode(int indentLevel)
#line 159 "decaf_semantic_tree.tc"
{
    ostringstream out;
    
    out << left->generateCode(indentLevel + 1);
    out << right->generateCode(indentLevel + 1);
    
    RegisterManager::getInstance().freeRegister(left->place);
    RegisterManager::getInstance().freeRegister(right->place);
    
    string reg;
    reg = RegisterManager::getInstance().getTempRegister();
    
    out << indent(indentLevel) << "add " << reg << ", " <<left->place << ", " << right->place << endl;
    this->place = reg;
    
    return out.str();
}
#line 1517 "decaf_tree.cpp"

int DecoratedAddExpression::isA(int kind) const
{
	if(kind == DecoratedAddExpression_kind)
		return 1;
	else
		return DecoratedBinaryExpression::isA(kind);
}

const char *DecoratedAddExpression::getKindName() const
{
	return "DecoratedAddExpression";
}

DecoratedSubExpression::DecoratedSubExpression(ExpressionType * type, DecoratedExpression * left, DecoratedExpression * right)
	: DecoratedBinaryExpression(type, left, right)
{
	this->kind__ = DecoratedSubExpression_kind;
}

DecoratedSubExpression::~DecoratedSubExpression()
{
	// not used
}

string DecoratedSubExpression::generateCode(int indentLevel)
#line 177 "decaf_semantic_tree.tc"
{
    ostringstream out;
    
    out << left->generateCode(indentLevel + 1);
    out << right->generateCode(indentLevel + 1);
    
    RegisterManager::getInstance().freeRegister(left->place);
    RegisterManager::getInstance().freeRegister(right->place);
    
    string reg;
    reg = RegisterManager::getInstance().getTempRegister();
    
    out << indent(indentLevel) << "sub " << reg << ", " <<left->place << ", " << right->place << endl;
    this->place = reg;
    
    return out.str();
}
#line 1562 "decaf_tree.cpp"

int DecoratedSubExpression::isA(int kind) const
{
	if(kind == DecoratedSubExpression_kind)
		return 1;
	else
		return DecoratedBinaryExpression::isA(kind);
}

const char *DecoratedSubExpression::getKindName() const
{
	return "DecoratedSubExpression";
}

DecoratedMultExpression::DecoratedMultExpression(ExpressionType * type, DecoratedExpression * left, DecoratedExpression * right)
	: DecoratedBinaryExpression(type, left, right)
{
	this->kind__ = DecoratedMultExpression_kind;
}

DecoratedMultExpression::~DecoratedMultExpression()
{
	// not used
}

string DecoratedMultExpression::generateCode(int indentLevel)
#line 195 "decaf_semantic_tree.tc"
{
    ostringstream out;
    
    out << left->generateCode(indentLevel + 1);
    out << right->generateCode(indentLevel + 1);
    
    RegisterManager::getInstance().freeRegister(left->place);
    RegisterManager::getInstance().freeRegister(right->place);
    
    string reg;
    reg = RegisterManager::getInstance().getTempRegister();
    
    out << indent(indentLevel) << "mul " << reg << ", " <<left->place << ", " << right->place << endl;
    this->place = reg;
    
    return out.str();
}
#line 1607 "decaf_tree.cpp"

int DecoratedMultExpression::isA(int kind) const
{
	if(kind == DecoratedMultExpression_kind)
		return 1;
	else
		return DecoratedBinaryExpression::isA(kind);
}

const char *DecoratedMultExpression::getKindName() const
{
	return "DecoratedMultExpression";
}

DecoratedDivExpression::DecoratedDivExpression(ExpressionType * type, DecoratedExpression * left, DecoratedExpression * right)
	: DecoratedBinaryExpression(type, left, right)
{
	this->kind__ = DecoratedDivExpression_kind;
}

DecoratedDivExpression::~DecoratedDivExpression()
{
	// not used
}

string DecoratedDivExpression::generateCode(int indentLevel)
#line 213 "decaf_semantic_tree.tc"
{
    ostringstream out;
    
    out << left->generateCode(indentLevel + 1);
    out << right->generateCode(indentLevel + 1);
    
    RegisterManager::getInstance().freeRegister(left->place);
    RegisterManager::getInstance().freeRegister(right->place);
    
    string reg;
    reg = RegisterManager::getInstance().getTempRegister();
    
    out << indent(indentLevel) << "div " << reg << ", " <<left->place << ", " << right->place << endl;
    this->place = reg;
    
    return out.str();
}
#line 1652 "decaf_tree.cpp"

int DecoratedDivExpression::isA(int kind) const
{
	if(kind == DecoratedDivExpression_kind)
		return 1;
	else
		return DecoratedBinaryExpression::isA(kind);
}

const char *DecoratedDivExpression::getKindName() const
{
	return "DecoratedDivExpression";
}

DecoratedModExpression::DecoratedModExpression(ExpressionType * type, DecoratedExpression * left, DecoratedExpression * right)
	: DecoratedBinaryExpression(type, left, right)
{
	this->kind__ = DecoratedModExpression_kind;
}

DecoratedModExpression::~DecoratedModExpression()
{
	// not used
}

string DecoratedModExpression::generateCode(int indentLevel)
#line 231 "decaf_semantic_tree.tc"
{
    ostringstream out;
    
    out << left->generateCode(indentLevel + 1);
    out << right->generateCode(indentLevel + 1);
    
    RegisterManager::getInstance().freeRegister(left->place);
    RegisterManager::getInstance().freeRegister(right->place);
    
    string reg;
    reg = RegisterManager::getInstance().getTempRegister();
    
    out << indent(indentLevel) << "rem " << reg << ", " <<left->place << ", " << right->place << endl;
    this->place = reg;
    
    return out.str();
}
#line 1697 "decaf_tree.cpp"

int DecoratedModExpression::isA(int kind) const
{
	if(kind == DecoratedModExpression_kind)
		return 1;
	else
		return DecoratedBinaryExpression::isA(kind);
}

const char *DecoratedModExpression::getKindName() const
{
	return "DecoratedModExpression";
}

DecoratedAndExpression::DecoratedAndExpression(ExpressionType * type, DecoratedExpression * left, DecoratedExpression * right)
	: DecoratedBinaryExpression(type, left, right)
{
	this->kind__ = DecoratedAndExpression_kind;
}

DecoratedAndExpression::~DecoratedAndExpression()
{
	// not used
}

string DecoratedAndExpression::generateCode(int indentLevel)
#line 249 "decaf_semantic_tree.tc"
{
    ostringstream out;
    
    out << left->generateCode(indentLevel + 1);
    out << right->generateCode(indentLevel + 1);
    
    RegisterManager::getInstance().freeRegister(left->place);
    RegisterManager::getInstance().freeRegister(right->place);
    
    string reg;
    reg = RegisterManager::getInstance().getTempRegister();

    string lblFalse, lblEnd;
    lblFalse = LabelManager::getInstance().getFalseLabel();
    lblEnd = LabelManager::getInstance().getEndLabel();
    
    out << indent(indentLevel) << "beq " << left->place << ", $zero, " << lblFalse << endl;
    out << indent(indentLevel) << "beq " << right->place << ", $zero, " << lblFalse << endl;
    out << indent(indentLevel) << "li " << reg << ", 1" << endl;
    out << indent(indentLevel) << "j " << lblEnd << endl;
    out << indent(indentLevel) << lblFalse << ":" << endl;
    out << indent(indentLevel) << "li " << reg << ", 0" << endl;
    out << indent(indentLevel) << lblEnd << ": " << endl;

    this->place = reg;
    
    return out.str();
}
#line 1753 "decaf_tree.cpp"

int DecoratedAndExpression::isA(int kind) const
{
	if(kind == DecoratedAndExpression_kind)
		return 1;
	else
		return DecoratedBinaryExpression::isA(kind);
}

const char *DecoratedAndExpression::getKindName() const
{
	return "DecoratedAndExpression";
}

DecoratedOrExpression::DecoratedOrExpression(ExpressionType * type, DecoratedExpression * left, DecoratedExpression * right)
	: DecoratedBinaryExpression(type, left, right)
{
	this->kind__ = DecoratedOrExpression_kind;
}

DecoratedOrExpression::~DecoratedOrExpression()
{
	// not used
}

string DecoratedOrExpression::generateCode(int indentLevel)
#line 278 "decaf_semantic_tree.tc"
{
    ostringstream out;
    
    out << left->generateCode(indentLevel + 1);
    out << right->generateCode(indentLevel + 1);
    
    RegisterManager::getInstance().freeRegister(left->place);
    RegisterManager::getInstance().freeRegister(right->place);
    
    string reg;
    reg = RegisterManager::getInstance().getTempRegister();

    string lblTrue, lblEnd;

    lblTrue = LabelManager::getInstance().getTrueLabel();
    lblEnd = LabelManager::getInstance().getEndLabel();
    
    out << indent(indentLevel) << "bne " << left->place << ", $zero, " << lblTrue << endl;
    out << indent(indentLevel) << "bne " << right->place << ", $zero, " << lblTrue << endl;
    out << indent(indentLevel) << "li " << reg << ", 0" << endl;
    out << indent(indentLevel) << "j " << lblEnd << endl;
    out << indent(indentLevel) << lblTrue << ":" << endl;
    out << indent(indentLevel) << "li " << reg << ", 1" << endl;
    out << indent(indentLevel) << lblEnd << ":" << endl;

    this->place = reg;
    
    return out.str();
}
#line 1810 "decaf_tree.cpp"

int DecoratedOrExpression::isA(int kind) const
{
	if(kind == DecoratedOrExpression_kind)
		return 1;
	else
		return DecoratedBinaryExpression::isA(kind);
}

const char *DecoratedOrExpression::getKindName() const
{
	return "DecoratedOrExpression";
}

DecoratedGTExpression::DecoratedGTExpression(ExpressionType * type, DecoratedExpression * left, DecoratedExpression * right)
	: DecoratedBinaryExpression(type, left, right)
{
	this->kind__ = DecoratedGTExpression_kind;
}

DecoratedGTExpression::~DecoratedGTExpression()
{
	// not used
}

string DecoratedGTExpression::generateCode(int indentLevel)
#line 308 "decaf_semantic_tree.tc"
{
    ostringstream out;
    
    out << left->generateCode(indentLevel + 1);
    out << right->generateCode(indentLevel + 1);
    
    RegisterManager::getInstance().freeRegister(left->place);
    RegisterManager::getInstance().freeRegister(right->place);
    
    string reg;
    reg = RegisterManager::getInstance().getTempRegister();
    
    out << indent(indentLevel) << "slt " << reg << ", " <<right->place << ", " << left->place << endl;
    this->place = reg;
    
    return out.str();
}
#line 1855 "decaf_tree.cpp"

int DecoratedGTExpression::isA(int kind) const
{
	if(kind == DecoratedGTExpression_kind)
		return 1;
	else
		return DecoratedBinaryExpression::isA(kind);
}

const char *DecoratedGTExpression::getKindName() const
{
	return "DecoratedGTExpression";
}

DecoratedLTExpression::DecoratedLTExpression(ExpressionType * type, DecoratedExpression * left, DecoratedExpression * right)
	: DecoratedBinaryExpression(type, left, right)
{
	this->kind__ = DecoratedLTExpression_kind;
}

DecoratedLTExpression::~DecoratedLTExpression()
{
	// not used
}

string DecoratedLTExpression::generateCode(int indentLevel)
#line 326 "decaf_semantic_tree.tc"
{
    ostringstream out;
    
    out << left->generateCode(indentLevel + 1);
    out << right->generateCode(indentLevel + 1);
    
    RegisterManager::getInstance().freeRegister(left->place);
    RegisterManager::getInstance().freeRegister(right->place);
    
    string reg;
    reg = RegisterManager::getInstance().getTempRegister();
    
    out << indent(indentLevel) << "slt " << reg << ", " <<left->place << ", " << right->place << endl;
    this->place = reg;
    
    return out.str();
}
#line 1900 "decaf_tree.cpp"

int DecoratedLTExpression::isA(int kind) const
{
	if(kind == DecoratedLTExpression_kind)
		return 1;
	else
		return DecoratedBinaryExpression::isA(kind);
}

const char *DecoratedLTExpression::getKindName() const
{
	return "DecoratedLTExpression";
}

DecoratedGTEExpression::DecoratedGTEExpression(ExpressionType * type, DecoratedExpression * left, DecoratedExpression * right)
	: DecoratedBinaryExpression(type, left, right)
{
	this->kind__ = DecoratedGTEExpression_kind;
}

DecoratedGTEExpression::~DecoratedGTEExpression()
{
	// not used
}

string DecoratedGTEExpression::generateCode(int indentLevel)
#line 344 "decaf_semantic_tree.tc"
{
    ostringstream out;
    
    out << left->generateCode(indentLevel + 1);
    out << right->generateCode(indentLevel + 1);
    
    RegisterManager::getInstance().freeRegister(left->place);
    RegisterManager::getInstance().freeRegister(right->place);
    
    string reg;
    reg = RegisterManager::getInstance().getTempRegister();
    
    out << indent(indentLevel) << "sle " << reg << ", " <<right->place << ", " << left->place << endl;
    this->place = reg;
    
    return out.str();
}
#line 1945 "decaf_tree.cpp"

int DecoratedGTEExpression::isA(int kind) const
{
	if(kind == DecoratedGTEExpression_kind)
		return 1;
	else
		return DecoratedBinaryExpression::isA(kind);
}

const char *DecoratedGTEExpression::getKindName() const
{
	return "DecoratedGTEExpression";
}

DecoratedLTEExpression::DecoratedLTEExpression(ExpressionType * type, DecoratedExpression * left, DecoratedExpression * right)
	: DecoratedBinaryExpression(type, left, right)
{
	this->kind__ = DecoratedLTEExpression_kind;
}

DecoratedLTEExpression::~DecoratedLTEExpression()
{
	// not used
}

string DecoratedLTEExpression::generateCode(int indentLevel)
#line 362 "decaf_semantic_tree.tc"
{
    ostringstream out;
    
    out << left->generateCode(indentLevel + 1);
    out << right->generateCode(indentLevel + 1);
    
    RegisterManager::getInstance().freeRegister(left->place);
    RegisterManager::getInstance().freeRegister(right->place);
    
    string reg;
    reg = RegisterManager::getInstance().getTempRegister();
    
    out << indent(indentLevel) << "sle " << reg << ", " <<left->place << ", " << right->place << endl;
    this->place = reg;
    
    return out.str();
}
#line 1990 "decaf_tree.cpp"

int DecoratedLTEExpression::isA(int kind) const
{
	if(kind == DecoratedLTEExpression_kind)
		return 1;
	else
		return DecoratedBinaryExpression::isA(kind);
}

const char *DecoratedLTEExpression::getKindName() const
{
	return "DecoratedLTEExpression";
}

DecoratedEqExpression::DecoratedEqExpression(ExpressionType * type, DecoratedExpression * left, DecoratedExpression * right)
	: DecoratedBinaryExpression(type, left, right)
{
	this->kind__ = DecoratedEqExpression_kind;
}

DecoratedEqExpression::~DecoratedEqExpression()
{
	// not used
}

string DecoratedEqExpression::generateCode(int indentLevel)
#line 380 "decaf_semantic_tree.tc"
{
    ostringstream out;
    
    out << left->generateCode(indentLevel + 1);
    out << right->generateCode(indentLevel + 1);
    
    RegisterManager::getInstance().freeRegister(left->place);
    RegisterManager::getInstance().freeRegister(right->place);
    
    string reg;
    reg = RegisterManager::getInstance().getTempRegister();
    
    out << indent(indentLevel) << "seq " << reg << ", " <<left->place << ", " << right->place << endl;
    this->place = reg;
    
    return out.str();
}
#line 2035 "decaf_tree.cpp"

int DecoratedEqExpression::isA(int kind) const
{
	if(kind == DecoratedEqExpression_kind)
		return 1;
	else
		return DecoratedBinaryExpression::isA(kind);
}

const char *DecoratedEqExpression::getKindName() const
{
	return "DecoratedEqExpression";
}

DecoratedNotEqExpression::DecoratedNotEqExpression(ExpressionType * type, DecoratedExpression * left, DecoratedExpression * right)
	: DecoratedBinaryExpression(type, left, right)
{
	this->kind__ = DecoratedNotEqExpression_kind;
}

DecoratedNotEqExpression::~DecoratedNotEqExpression()
{
	// not used
}

string DecoratedNotEqExpression::generateCode(int indentLevel)
#line 398 "decaf_semantic_tree.tc"
{
    ostringstream out;
    
    out << left->generateCode(indentLevel + 1);
    out << right->generateCode(indentLevel + 1);
    
    RegisterManager::getInstance().freeRegister(left->place);
    RegisterManager::getInstance().freeRegister(right->place);
    
    string reg;
    reg = RegisterManager::getInstance().getTempRegister();
    
    out << indent(indentLevel) << "sne " << reg << ", " <<left->place << ", " << right->place << endl;
    this->place = reg;
    
    return out.str();
}
#line 2080 "decaf_tree.cpp"

int DecoratedNotEqExpression::isA(int kind) const
{
	if(kind == DecoratedNotEqExpression_kind)
		return 1;
	else
		return DecoratedBinaryExpression::isA(kind);
}

const char *DecoratedNotEqExpression::getKindName() const
{
	return "DecoratedNotEqExpression";
}

DecoratedRShiftExpression::DecoratedRShiftExpression(ExpressionType * type, DecoratedExpression * left, DecoratedExpression * right)
	: DecoratedBinaryExpression(type, left, right)
{
	this->kind__ = DecoratedRShiftExpression_kind;
}

DecoratedRShiftExpression::~DecoratedRShiftExpression()
{
	// not used
}

string DecoratedRShiftExpression::generateCode(int indentLevel)
#line 416 "decaf_semantic_tree.tc"
{
    ostringstream out;
    
    out << left->generateCode(indentLevel + 1);
    out << right->generateCode(indentLevel + 1);
    
    RegisterManager::getInstance().freeRegister(left->place);
    RegisterManager::getInstance().freeRegister(right->place);
    
    string reg;
    reg = RegisterManager::getInstance().getTempRegister();
    
    out << indent(indentLevel) << "srlv " << reg << ", " <<left->place << ", " << right->place << endl;
    this->place = reg;
    
    return out.str();
}
#line 2125 "decaf_tree.cpp"

int DecoratedRShiftExpression::isA(int kind) const
{
	if(kind == DecoratedRShiftExpression_kind)
		return 1;
	else
		return DecoratedBinaryExpression::isA(kind);
}

const char *DecoratedRShiftExpression::getKindName() const
{
	return "DecoratedRShiftExpression";
}

DecoratedLShiftExpression::DecoratedLShiftExpression(ExpressionType * type, DecoratedExpression * left, DecoratedExpression * right)
	: DecoratedBinaryExpression(type, left, right)
{
	this->kind__ = DecoratedLShiftExpression_kind;
}

DecoratedLShiftExpression::~DecoratedLShiftExpression()
{
	// not used
}

string DecoratedLShiftExpression::generateCode(int indentLevel)
#line 434 "decaf_semantic_tree.tc"
{
    ostringstream out;
    
    out << left->generateCode(indentLevel + 1);
    out << right->generateCode(indentLevel + 1);
    
    RegisterManager::getInstance().freeRegister(left->place);
    RegisterManager::getInstance().freeRegister(right->place);
    
    string reg;
    reg = RegisterManager::getInstance().getTempRegister();
    
    out << indent(indentLevel) << "sllv " << reg << ", " <<left->place << ", " << right->place << endl;
    this->place = reg;
    
    return out.str();
}
#line 2170 "decaf_tree.cpp"

int DecoratedLShiftExpression::isA(int kind) const
{
	if(kind == DecoratedLShiftExpression_kind)
		return 1;
	else
		return DecoratedBinaryExpression::isA(kind);
}

const char *DecoratedLShiftExpression::getKindName() const
{
	return "DecoratedLShiftExpression";
}

DecoratedRotExpression::DecoratedRotExpression(ExpressionType * type, DecoratedExpression * left, DecoratedExpression * right)
	: DecoratedBinaryExpression(type, left, right)
{
	this->kind__ = DecoratedRotExpression_kind;
}

DecoratedRotExpression::~DecoratedRotExpression()
{
	// not used
}

string DecoratedRotExpression::generateCode(int indentLevel)
#line 452 "decaf_semantic_tree.tc"
{
    ostringstream out;
    
    out << left->generateCode(indentLevel + 1);
    out << right->generateCode(indentLevel + 1);
    
    RegisterManager::getInstance().freeRegister(left->place);
    RegisterManager::getInstance().freeRegister(right->place);
    
    string reg;
    reg = RegisterManager::getInstance().getTempRegister();
    
    out << indent(indentLevel) << "ror " << reg << ", " <<left->place << ", " << right->place << endl;
    this->place = reg;
    
    return out.str();
}
#line 2215 "decaf_tree.cpp"

int DecoratedRotExpression::isA(int kind) const
{
	if(kind == DecoratedRotExpression_kind)
		return 1;
	else
		return DecoratedBinaryExpression::isA(kind);
}

const char *DecoratedRotExpression::getKindName() const
{
	return "DecoratedRotExpression";
}

DecoratedNotExpression::DecoratedNotExpression(ExpressionType * type, DecoratedExpression * expression)
	: DecoratedUnaryExpression(type, expression)
{
	this->kind__ = DecoratedNotExpression_kind;
}

DecoratedNotExpression::~DecoratedNotExpression()
{
	// not used
}

string DecoratedNotExpression::generateCode(int indentLevel)
#line 470 "decaf_semantic_tree.tc"
{
    ostringstream out;
    
    out << expression->generateCode(indentLevel + 1);
    
    RegisterManager::getInstance().freeRegister(expression->place);
    
    string reg;
    reg = RegisterManager::getInstance().getTempRegister();
    
    out << indent(indentLevel) << "seq " << reg << ", $zero, " << expression->place << endl;
    this->place = reg;
    
    return out.str();
}
#line 2258 "decaf_tree.cpp"

int DecoratedNotExpression::isA(int kind) const
{
	if(kind == DecoratedNotExpression_kind)
		return 1;
	else
		return DecoratedUnaryExpression::isA(kind);
}

const char *DecoratedNotExpression::getKindName() const
{
	return "DecoratedNotExpression";
}

DecoratedNegExpression::DecoratedNegExpression(ExpressionType * type, DecoratedExpression * expression)
	: DecoratedUnaryExpression(type, expression)
{
	this->kind__ = DecoratedNegExpression_kind;
}

DecoratedNegExpression::~DecoratedNegExpression()
{
	// not used
}

string DecoratedNegExpression::generateCode(int indentLevel)
#line 486 "decaf_semantic_tree.tc"
{
    ostringstream out;
    
    out << expression->generateCode(indentLevel + 1);
    
    RegisterManager::getInstance().freeRegister(expression->place);
    
    string reg;
    reg = RegisterManager::getInstance().getTempRegister();
    
    out << indent(indentLevel) << "sub " << reg << ", $zero, " << expression->place << endl;
    this->place = reg;
    
    return out.str();
}
#line 2301 "decaf_tree.cpp"

int DecoratedNegExpression::isA(int kind) const
{
	if(kind == DecoratedNegExpression_kind)
		return 1;
	else
		return DecoratedUnaryExpression::isA(kind);
}

const char *DecoratedNegExpression::getKindName() const
{
	return "DecoratedNegExpression";
}

DecoratedBooleanConstant::DecoratedBooleanConstant(ExpressionType * type, bool value)
	: DecoratedConstant(type)
{
	this->kind__ = DecoratedBooleanConstant_kind;
	this->value = value;
}

DecoratedBooleanConstant::~DecoratedBooleanConstant()
{
	// not used
}

string DecoratedBooleanConstant::generateCode(int indentLevel)
#line 502 "decaf_semantic_tree.tc"
{
    ostringstream out;
    string reg;
    reg = RegisterManager::getInstance().getTempRegister();

    if (value) {
        out << indent(indentLevel) << "li " << reg << ", 1" << endl; 
    } else {
        out << indent(indentLevel) << "li " << reg << ", 0" << endl;
    }
    this->place = reg;

    return out.str();
}
#line 2344 "decaf_tree.cpp"

int DecoratedBooleanConstant::isA(int kind) const
{
	if(kind == DecoratedBooleanConstant_kind)
		return 1;
	else
		return DecoratedConstant::isA(kind);
}

const char *DecoratedBooleanConstant::getKindName() const
{
	return "DecoratedBooleanConstant";
}

DecoratedIntConstant::DecoratedIntConstant(ExpressionType * type, int value)
	: DecoratedConstant(type)
{
	this->kind__ = DecoratedIntConstant_kind;
	this->value = value;
}

DecoratedIntConstant::~DecoratedIntConstant()
{
	// not used
}

string DecoratedIntConstant::generateCode(int indentLevel)
#line 517 "decaf_semantic_tree.tc"
{
    ostringstream out;
    string reg;
    reg = RegisterManager::getInstance().getTempRegister();

    out << indent(indentLevel) << "li " << reg << ", " << value << endl;
    this->place = reg;

    return out.str();
}
#line 2383 "decaf_tree.cpp"

int DecoratedIntConstant::isA(int kind) const
{
	if(kind == DecoratedIntConstant_kind)
		return 1;
	else
		return DecoratedConstant::isA(kind);
}

const char *DecoratedIntConstant::getKindName() const
{
	return "DecoratedIntConstant";
}

DecoratedStringConstant::DecoratedStringConstant(ExpressionType * type, string value)
	: DecoratedConstant(type)
{
	this->kind__ = DecoratedStringConstant_kind;
	this->value = value;
}

DecoratedStringConstant::~DecoratedStringConstant()
{
	// not used
}

string DecoratedStringConstant::generateCode(int indentLevel)
#line 528 "decaf_semantic_tree.tc"
{
    ostringstream out;

    string reg;
    reg = RegisterManager::getInstance().getTempRegister();

    out << indent(indentLevel + 1) << "la " << reg << ", " 
        << getSymbolTableInstance()->getString(value) << endl;
    this->place = reg;

    return out.str();
}
#line 2424 "decaf_tree.cpp"

int DecoratedStringConstant::isA(int kind) const
{
	if(kind == DecoratedStringConstant_kind)
		return 1;
	else
		return DecoratedConstant::isA(kind);
}

const char *DecoratedStringConstant::getKindName() const
{
	return "DecoratedStringConstant";
}

DecoratedAssignmentStatement::DecoratedAssignmentStatement(int line, DecoratedLValue * lvalue, DecoratedExpression * value)
	: DecoratedStatement(line)
{
	this->kind__ = DecoratedAssignmentStatement_kind;
	this->lvalue = lvalue;
	this->value = value;
}

DecoratedAssignmentStatement::~DecoratedAssignmentStatement()
{
	// not used
}

string DecoratedAssignmentStatement::generateCode(int indentLevel)
#line 635 "decaf_semantic_tree.tc"
{
    ostringstream out;

    out << lvalue->getLocation(indentLevel + 1);
    out << value->generateCode(indentLevel + 1);
    out << indent(indentLevel) << "sw " << value->place << ", 0(" << lvalue->place << ")" << endl;
    out << "#termino assignment..." << endl;

    RegisterManager::getInstance().freeRegister(lvalue->place);
    RegisterManager::getInstance().freeRegister(value->place);

    return out.str();
}
#line 2467 "decaf_tree.cpp"

int DecoratedAssignmentStatement::isA(int kind) const
{
	if(kind == DecoratedAssignmentStatement_kind)
		return 1;
	else
		return DecoratedStatement::isA(kind);
}

const char *DecoratedAssignmentStatement::getKindName() const
{
	return "DecoratedAssignmentStatement";
}

DecoratedMethodCallStatement::DecoratedMethodCallStatement(int line, string name, DecoratedExpressionList * arguments)
	: DecoratedStatement(line)
{
	this->kind__ = DecoratedMethodCallStatement_kind;
	this->method_index = 0;
	this->name = name;
	this->arguments = arguments;
}

DecoratedMethodCallStatement::~DecoratedMethodCallStatement()
{
	// not used
}

string DecoratedMethodCallStatement::generateCode(int indentLevel)
#line 649 "decaf_semantic_tree.tc"
{
    ostringstream out;

    list<DecoratedExpression*>::iterator it = arguments->begin();
    int argc = 0;
    while (it != arguments->end()) {
        DecoratedExpression *argument = (*it);
        if (argc < 5) {
            //usar $a0...$a4
            string param;
            param = RegisterManager::getInstance().getParamRegister();

            out << argument->generateCode(indentLevel + 1);
            out << indent(indentLevel) << "move " << param << " ," << argument->place << endl;
            RegisterManager::getInstance().freeRegister(argument->place);
        } else {
            //poner en la pila
        }
        it++;
    }
    //TODO:save registers
    out << indent(indentLevel) << "jal " << name << endl;
    //TODO:restore registers

    RegisterManager::getInstance().freeParamRegisters();

    return out.str();
}
#line 2526 "decaf_tree.cpp"

int DecoratedMethodCallStatement::isA(int kind) const
{
	if(kind == DecoratedMethodCallStatement_kind)
		return 1;
	else
		return DecoratedStatement::isA(kind);
}

const char *DecoratedMethodCallStatement::getKindName() const
{
	return "DecoratedMethodCallStatement";
}

DecoratedPrintStatement::DecoratedPrintStatement(int line, DecoratedExpressionList * arguments)
	: DecoratedStatement(line)
{
	this->kind__ = DecoratedPrintStatement_kind;
	this->arguments = arguments;
}

DecoratedPrintStatement::~DecoratedPrintStatement()
{
	// not used
}

string DecoratedPrintStatement::generateCode(int indentLevel)
#line 678 "decaf_semantic_tree.tc"
{
    ostringstream out;

    list<DecoratedExpression *>::iterator argument = arguments->begin();
    while (argument != arguments->end()) {
        DecoratedExpression *expression = (*argument);

        out << expression->generateCode(indentLevel + 1);

        int printType = 4;
        if (!expression->type->isEquivalent(new StringType()))
            printType = 1;

        out << indent(indentLevel) << "move $a0, " << expression->place << endl;
        out << indent(indentLevel) << "li $v0, " << printType << endl;
        out << indent(indentLevel) << "syscall" << endl;

        RegisterManager::getInstance().freeRegister(expression->place);

        argument++;
    }

    return out.str();
}
#line 2579 "decaf_tree.cpp"

int DecoratedPrintStatement::isA(int kind) const
{
	if(kind == DecoratedPrintStatement_kind)
		return 1;
	else
		return DecoratedStatement::isA(kind);
}

const char *DecoratedPrintStatement::getKindName() const
{
	return "DecoratedPrintStatement";
}

DecoratedReadStatement::DecoratedReadStatement(int line, DecoratedExpressionList * arguments)
	: DecoratedStatement(line)
{
	this->kind__ = DecoratedReadStatement_kind;
	this->arguments = arguments;
}

DecoratedReadStatement::~DecoratedReadStatement()
{
	// not used
}

string DecoratedReadStatement::generateCode(int indentLevel)
#line 703 "decaf_semantic_tree.tc"
{
    ostringstream out;

    list<DecoratedExpression *>::iterator argument = arguments->begin();
    while (argument != arguments->end()) {
        DecoratedLValue *arg = (DecoratedLValue*)(*argument);       
        
        out << indent(indentLevel) << "li $v0, 5" << endl;
        out << indent(indentLevel) << "syscall" << endl;

        out << arg->getLocation(indentLevel + 1);

        //TODO: con variables locales donde se guardará?
        out << indent(indentLevel) << "sw $v0, 0(" << arg->place << ")" << endl;

        argument++;
    }

    return out.str();
}
#line 2628 "decaf_tree.cpp"

int DecoratedReadStatement::isA(int kind) const
{
	if(kind == DecoratedReadStatement_kind)
		return 1;
	else
		return DecoratedStatement::isA(kind);
}

const char *DecoratedReadStatement::getKindName() const
{
	return "DecoratedReadStatement";
}

DecoratedIfStatement::DecoratedIfStatement(int line, DecoratedExpression * condition, DecoratedStatement * true_part, DecoratedStatement * false_part)
	: DecoratedStatement(line)
{
	this->kind__ = DecoratedIfStatement_kind;
	this->condition = condition;
	this->true_part = true_part;
	this->false_part = false_part;
}

DecoratedIfStatement::~DecoratedIfStatement()
{
	// not used
}

string DecoratedIfStatement::generateCode(int indentLevel)
#line 724 "decaf_semantic_tree.tc"
{
    ostringstream out;

    out << condition->generateCode(indentLevel);

    string elseLabel;
    elseLabel = LabelManager::getInstance().getElseLabel();

    out << indent(indentLevel) << "beq " << condition->place << ", $zero, " << elseLabel << endl;
    out << true_part->generateCode(indentLevel + 1) << endl;
    out << indent(indentLevel) << elseLabel << ":" << endl;
    if (false_part != NULL) {
        out << false_part->generateCode(indentLevel + 1) << endl;
    }

    RegisterManager::getInstance().freeRegister(condition->place);

    return out.str();
}
#line 2678 "decaf_tree.cpp"

int DecoratedIfStatement::isA(int kind) const
{
	if(kind == DecoratedIfStatement_kind)
		return 1;
	else
		return DecoratedStatement::isA(kind);
}

const char *DecoratedIfStatement::getKindName() const
{
	return "DecoratedIfStatement";
}

DecoratedWhileStatement::DecoratedWhileStatement(int line, DecoratedExpression * condition, DecoratedStatement * loop_body)
	: DecoratedStatement(line)
{
	this->kind__ = DecoratedWhileStatement_kind;
	this->condition = condition;
	this->loop_body = loop_body;
}

DecoratedWhileStatement::~DecoratedWhileStatement()
{
	// not used
}

string DecoratedWhileStatement::generateCode(int indentLevel)
#line 744 "decaf_semantic_tree.tc"
{
    ostringstream out;

    string whileLabel;
    string outOfWhileLabel;
    whileLabel = LabelManager::getInstance().getWhileLabel();
    outOfWhileLabel = LabelManager::getInstance().getOutOfWhileLabel();

    LabelManager::getInstance().pushBreakPoint(outOfWhileLabel);
    LabelManager::getInstance().pushContinuePoint(whileLabel);

    out << indent(indentLevel) << whileLabel << ":" << endl;

    out << condition->generateCode(indentLevel + 1) ;
    out << indent(indentLevel + 1) << "beq " << condition->place << ", $zero, " << outOfWhileLabel << endl;

    out << loop_body->generateCode(indentLevel + 1);
    out << indent(indentLevel) << "j " << whileLabel << endl;

    out << indent(indentLevel) << outOfWhileLabel << ":" << endl;

    LabelManager::getInstance().popContinuePoint();
    LabelManager::getInstance().popCurrentBreakPoint();

    return out.str();
}
#line 2734 "decaf_tree.cpp"

int DecoratedWhileStatement::isA(int kind) const
{
	if(kind == DecoratedWhileStatement_kind)
		return 1;
	else
		return DecoratedStatement::isA(kind);
}

const char *DecoratedWhileStatement::getKindName() const
{
	return "DecoratedWhileStatement";
}

DecoratedForStatement::DecoratedForStatement(int line, DecoratedStatement * assignment_list1, DecoratedExpression * condition, DecoratedStatement * assignment_list2, DecoratedStatement * loop_body)
	: DecoratedStatement(line)
{
	this->kind__ = DecoratedForStatement_kind;
	this->assignment_list1 = assignment_list1;
	this->condition = condition;
	this->assignment_list2 = assignment_list2;
	this->loop_body = loop_body;
}

DecoratedForStatement::~DecoratedForStatement()
{
	// not used
}

string DecoratedForStatement::generateCode(int indentLevel)
#line 771 "decaf_semantic_tree.tc"
{
    ostringstream out;

    string forLabel;
    string outOfForLabel;
    string continuePoint;

    forLabel = LabelManager::getInstance().getForLabel();
    outOfForLabel = LabelManager::getInstance().getOutOfForLabel();
    continuePoint = LabelManager::getInstance().getContinueLabel();


    LabelManager::getInstance().pushBreakPoint(outOfForLabel);
    LabelManager::getInstance().pushContinuePoint(continuePoint);

    out << assignment_list1->generateCode(indentLevel + 1);

    out << indent(indentLevel) << forLabel << ":" << endl;

    out << condition->generateCode(indentLevel + 1);
    out << indent(indentLevel + 1) << "beq " << condition->place << ", $zero, " << outOfForLabel << endl;

    out << loop_body->generateCode(indentLevel + 1);

    out << indent(indentLevel + 1) << continuePoint << ": " << endl;
    
    out << assignment_list2->generateCode(indentLevel + 1);

    out << indent(indentLevel) << "j " << forLabel << endl;

    out << indent(indentLevel) << outOfForLabel << ":" << endl;

    LabelManager::getInstance().popContinuePoint();
    LabelManager::getInstance().popCurrentBreakPoint();

    return out.str();
}
#line 2803 "decaf_tree.cpp"

int DecoratedForStatement::isA(int kind) const
{
	if(kind == DecoratedForStatement_kind)
		return 1;
	else
		return DecoratedStatement::isA(kind);
}

const char *DecoratedForStatement::getKindName() const
{
	return "DecoratedForStatement";
}

DecoratedReturnStatement::DecoratedReturnStatement(int line, DecoratedExpression * expression)
	: DecoratedStatement(line)
{
	this->kind__ = DecoratedReturnStatement_kind;
	this->expression = expression;
}

DecoratedReturnStatement::~DecoratedReturnStatement()
{
	// not used
}

string DecoratedReturnStatement::generateCode(int indentLevel)
#line 809 "decaf_semantic_tree.tc"
{
    ostringstream out, epilogo;

    string indentation = indent(indentLevel);

    if (expression != NULL) {
        out << expression->generateCode(indentLevel + 1);
        if (expression->place != "$v0")
            out << indent(indentLevel) << "move $v0, " << expression->place << endl;
        
    }

    out << indentation << "j " << function_end << endl;

    epilogo << indentation << "#epilog " << endl;

    /* Load $ra */
    epilogo << indentation << "lw $ra, 0($fp)" << endl;

    list<string> toSaveRegisters = RegisterManager::getInstance().registersToSave();
    list<string>::iterator regToSaveIterator = toSaveRegisters.begin();
    int offset = 0;

    /* Load registers */
    regToSaveIterator = toSaveRegisters.begin();
    while (regToSaveIterator != toSaveRegisters.end()) {
        epilogo << indentation << "lw " << (*regToSaveIterator) << ", " << offset << "($sp)" << endl;
        offset += 4;
        regToSaveIterator++;
    }

    /* Load $fp */
    epilogo << indentation << "lw $fp, 4($fp)" << endl;

    epilogo << indentation << "addi $sp, $sp, " << offset << endl;
    epilogo << indentation << "#end of epilog" << endl;

    out << epilogo.str();
    out << indent(indentLevel) << "jr $ra" << endl;
    return out.str();
}
#line 2873 "decaf_tree.cpp"

int DecoratedReturnStatement::isA(int kind) const
{
	if(kind == DecoratedReturnStatement_kind)
		return 1;
	else
		return DecoratedStatement::isA(kind);
}

const char *DecoratedReturnStatement::getKindName() const
{
	return "DecoratedReturnStatement";
}

DecoratedBreakStatement::DecoratedBreakStatement(int line)
	: DecoratedStatement(line)
{
	this->kind__ = DecoratedBreakStatement_kind;
}

DecoratedBreakStatement::~DecoratedBreakStatement()
{
	// not used
}

string DecoratedBreakStatement::generateCode(int indentLevel)
#line 851 "decaf_semantic_tree.tc"
{
    ostringstream out;

    out << indent(indentLevel) << "j " << LabelManager::getInstance().getCurrentBreakPoint() << endl;

    return out.str();
}
#line 2908 "decaf_tree.cpp"

int DecoratedBreakStatement::isA(int kind) const
{
	if(kind == DecoratedBreakStatement_kind)
		return 1;
	else
		return DecoratedStatement::isA(kind);
}

const char *DecoratedBreakStatement::getKindName() const
{
	return "DecoratedBreakStatement";
}

DecoratedContinueStatement::DecoratedContinueStatement(int line)
	: DecoratedStatement(line)
{
	this->kind__ = DecoratedContinueStatement_kind;
}

DecoratedContinueStatement::~DecoratedContinueStatement()
{
	// not used
}

string DecoratedContinueStatement::generateCode(int indentLevel)
#line 859 "decaf_semantic_tree.tc"
{
    ostringstream out;

    out << indent(indentLevel) << "j " << LabelManager::getInstance().getCurrentContinuePoint() << endl;

    return out.str();
}
#line 2943 "decaf_tree.cpp"

int DecoratedContinueStatement::isA(int kind) const
{
	if(kind == DecoratedContinueStatement_kind)
		return 1;
	else
		return DecoratedStatement::isA(kind);
}

const char *DecoratedContinueStatement::getKindName() const
{
	return "DecoratedContinueStatement";
}

DecoratedBlockStatement::DecoratedBlockStatement(int line, DecoratedStatementList * statement_list)
	: DecoratedStatement(line)
{
	this->kind__ = DecoratedBlockStatement_kind;
	this->statement_list = statement_list;
	this->parent = NULL;
	this->deepLevel = 0;
	this->scopeSize = 0;
	this->context = NULL;
}

DecoratedBlockStatement::~DecoratedBlockStatement()
{
	// not used
}

string DecoratedBlockStatement::generateCode(int indentLevel)
#line 867 "decaf_semantic_tree.tc"
{
    if (deepLevel >= MAX_DEEP_NESTING) {
        ostringstream out;
        out << "nesting level cannot be greater than " << MAX_DEEP_NESTING;
        ErrorHandler::getInstance().handleFatal(line, out.str());
    }
    ostringstream out;

    string indentation = indent(indentLevel);

    string displayAddress, displayItem;
    displayAddress = RegisterManager::getInstance().getTempRegister();
    displayItem = RegisterManager::getInstance().getTempRegister();

    int displayOffset = (deepLevel*4);

    out << indentation << "#generating scope registration logic..." << endl;
    out << indentation << "la " << displayAddress << ", display" << endl;
    out << indentation << "lw " << displayItem << ", " << displayOffset << "(" << displayAddress << ")" << endl;
    out << indentation << "addi $sp, $sp, -4" << endl;
    out << indentation << "sw " << displayItem << ", 0($sp)" << endl;
    out << indentation << "addi $sp, $sp, " << (-scopeSize) << "   #reservar el espacio para el scope" << endl;
    out << indentation << "sw $sp, " << displayOffset << "(" << displayAddress << ")" << endl;
    out << indentation << "#end of scope registration" << endl;

    RegisterManager::getInstance().freeRegister(displayAddress);
    RegisterManager::getInstance().freeRegister(displayItem);

    ContextManager::getInstance().registerContext(this->deepLevel, this->context);

    list<DecoratedStatement*>::iterator it = statement_list->begin();
    out << indentation << "# scope level " << deepLevel << endl;

    while (it != statement_list->end()) {
        DecoratedMethodCallStatement *mc = dynamic_cast<DecoratedMethodCallStatement*>(*it);
        if (mc != NULL) {
            list<string> registersToSave = RegisterManager::getInstance().registersToSave();
            //generar codigo para guardar los registros a0...a3 en la pila!
            //cualquier llamada a metodo debe sacar los valores de la pila
            //NUNCA de los parametros!!!!!
            out << indentation << "#saving parameters because of method call" << endl;
            out << indentation << "addi $sp, $sp, -16" << endl;
            int i = 0;
            while (i < 4) {
                out << indentation << "sw $a" << i << ", " << i*4 << "($sp)" << endl;
                i++;
            }
            out << indentation << "#end saving parameters because of method call" << endl;
        }
        out << (*it)->generateCode(indentLevel + 1);
        it++;
    }
    out << indent(indentLevel) << "# end of scope level " << deepLevel << endl;

    displayAddress = RegisterManager::getInstance().getTempRegister();
    displayItem = RegisterManager::getInstance().getTempRegister();
    ContextManager::getInstance().unregisterContext(this->deepLevel);

    out << indentation << "#starting scope unregistration code..." << endl;
    out << indentation << "addi $sp, $sp, " << scopeSize << endl;
    out << indentation << "la " << displayAddress << ", display" << endl;
    out << indentation << "lw " << displayItem << ", 0($sp)" << endl;
    out << indentation << "addi $sp, $sp, 4" << endl;
    out << indentation << "sw " << displayItem << ", " << displayOffset << "(" << displayAddress << ")" << endl;
    out << indentation << "#end of scope unregistration" << endl;


    return out.str();
}
#line 3045 "decaf_tree.cpp"

int DecoratedBlockStatement::isA(int kind) const
{
	if(kind == DecoratedBlockStatement_kind)
		return 1;
	else
		return DecoratedStatement::isA(kind);
}

const char *DecoratedBlockStatement::getKindName() const
{
	return "DecoratedBlockStatement";
}

void *Variable::operator new(size_t size__)
{
	return YYNODESTATE::getState()->alloc(size__);
}

void Variable::operator delete(void *ptr__, size_t size__)
{
	YYNODESTATE::getState()->dealloc(ptr__, size__);
}

Variable::Variable(ExpressionType * type, string variable_name)
{
	this->kind__ = Variable_kind;
	this->filename__ = YYNODESTATE::getState()->currFilename();
	this->linenum__ = YYNODESTATE::getState()->currLinenum();
	this->type = type;
	this->variable_name = variable_name;
	this->initialized = false;
}

Variable::~Variable()
{
	// not used
}

int Variable::isA(int kind) const
{
	if(kind == Variable_kind)
		return 1;
	else
		return 0;
}

const char *Variable::getKindName() const
{
	return "Variable";
}

SimpleVariable::SimpleVariable(ExpressionType * type, string variable_name)
	: Variable(type, variable_name)
{
	this->kind__ = SimpleVariable_kind;
	this->initial_value = 0;
	this->parameterId = 0;
}

SimpleVariable::~SimpleVariable()
{
	// not used
}

int SimpleVariable::isA(int kind) const
{
	if(kind == SimpleVariable_kind)
		return 1;
	else
		return Variable::isA(kind);
}

const char *SimpleVariable::getKindName() const
{
	return "SimpleVariable";
}

ArrayVariable::ArrayVariable(ExpressionType * type, string variable_name, int size)
	: Variable(type, variable_name)
{
	this->kind__ = ArrayVariable_kind;
	this->size = size;
}

ArrayVariable::~ArrayVariable()
{
	// not used
}

int ArrayVariable::isA(int kind) const
{
	if(kind == ArrayVariable_kind)
		return 1;
	else
		return Variable::isA(kind);
}

const char *ArrayVariable::getKindName() const
{
	return "ArrayVariable";
}

void *DNode::operator new(size_t size__)
{
	return YYNODESTATE::getState()->alloc(size__);
}

void DNode::operator delete(void *ptr__, size_t size__)
{
	YYNODESTATE::getState()->dealloc(ptr__, size__);
}

DNode::DNode()
{
	this->kind__ = DNode_kind;
	this->filename__ = YYNODESTATE::getState()->currFilename();
	this->linenum__ = YYNODESTATE::getState()->currLinenum();
}

DNode::~DNode()
{
	// not used
}

int DNode::isA(int kind) const
{
	if(kind == DNode_kind)
		return 1;
	else
		return 0;
}

const char *DNode::getKindName() const
{
	return "DNode";
}

MainNode::MainNode()
	: DNode()
{
	this->kind__ = MainNode_kind;
}

MainNode::~MainNode()
{
	// not used
}

int MainNode::isA(int kind) const
{
	if(kind == MainNode_kind)
		return 1;
	else
		return DNode::isA(kind);
}

const char *MainNode::getKindName() const
{
	return "MainNode";
}

Definition::Definition()
	: DNode()
{
	this->kind__ = Definition_kind;
}

Definition::~Definition()
{
	// not used
}

int Definition::isA(int kind) const
{
	if(kind == Definition_kind)
		return 1;
	else
		return DNode::isA(kind);
}

const char *Definition::getKindName() const
{
	return "Definition";
}

Expression::Expression()
	: DNode()
{
	this->kind__ = Expression_kind;
}

Expression::~Expression()
{
	// not used
}

int Expression::isA(int kind) const
{
	if(kind == Expression_kind)
		return 1;
	else
		return DNode::isA(kind);
}

const char *Expression::getKindName() const
{
	return "Expression";
}

Statement::Statement(int line, int column)
	: DNode()
{
	this->kind__ = Statement_kind;
	this->line = line;
	this->column = column;
}

Statement::~Statement()
{
	// not used
}

int Statement::isA(int kind) const
{
	if(kind == Statement_kind)
		return 1;
	else
		return DNode::isA(kind);
}

const char *Statement::getKindName() const
{
	return "Statement";
}

ClassDef::ClassDef(string name, VariableDefList * field_def_list, MethodDefList * method_def_list)
	: MainNode()
{
	this->kind__ = ClassDef_kind;
	this->name = name;
	this->field_def_list = field_def_list;
	this->method_def_list = method_def_list;
}

ClassDef::~ClassDef()
{
	// not used
}

string ClassDef::toString()
#line 301 "decaf_tree.tc"
{
	ostringstream out;

	out << "class " << name << "\n";
	out << "{" << "\n";

	if (field_def_list != 0)
		out << ListToString(field_def_list, ";\n", true) << "\n";

	if (method_def_list != 0)
		out << ListToString(method_def_list, "\n\n", true);

	out << "}" << endl;

	return out.str();
}
#line 3314 "decaf_tree.cpp"

DecoratedNode * ClassDef::validateSemantics()
#line 517 "decaf_tree.tc"
{
	context = new Context;
	if (field_def_list != NULL) {
	    list<VariableDef*>::iterator variable_iterator = field_def_list->begin();
	    
	    while(variable_iterator != field_def_list->end()) {
	        VariableDef * field_def = *variable_iterator;
	        field_def->registerDefinition();
	        variable_iterator++;
	    }
	}
	ContextManager::getInstance().registerContext(0, context);

    list<MethodDef*>::iterator method_iterator = method_def_list->begin();
    
    while(method_iterator != method_def_list->end()) {
        MethodDef * method_def = *method_iterator;
        method_def->registerDefinition();
        method_iterator++;
    }
    
    /************ Check method bodies. ************/
    bool mainFound = false;
    method_iterator = method_def_list->begin();
    DecoratedBlockStatement *main_block = NULL;
    while(method_iterator != method_def_list->end()) {
        MethodDef * method_def = *method_iterator;
        
        insideLoop = false;
		continueFound = false;
		breakFound = false;
		returnFound = false;

        currentFunction = getSymbolTableInstance()->getFunction(method_def->method_name);
        
        if (method_def->method_name == "main") {
        	main_block = method_def->checkBody();
        	currentFunction->setBody(main_block);
        	mainFound = true;
        } else {
        	DecoratedBlockStatement *block = method_def->checkBody();
        	currentFunction->setBody(block);
        }
        method_iterator++;
    }

    if (!mainFound) {
    	ErrorHandler::getInstance().handleError(statement_line, "main method not found");
    }

    DecoratedClass *decorated_class = new DecoratedClass(this->name);
    decorated_class->main = main_block;
    return decorated_class;
}
#line 3372 "decaf_tree.cpp"

int ClassDef::isA(int kind) const
{
	if(kind == ClassDef_kind)
		return 1;
	else
		return MainNode::isA(kind);
}

const char *ClassDef::getKindName() const
{
	return "ClassDef";
}

VariableDef::VariableDef(string variable_name, int line, int column)
	: Definition()
{
	this->kind__ = VariableDef_kind;
	this->variable_name = variable_name;
	this->line = line;
	this->column = column;
	this->is_array_def = false;
	this->array_dimension = 0;
	this->initial_value = 0;
}

VariableDef::~VariableDef()
{
	// not used
}

string VariableDef::toString()
#line 318 "decaf_tree.tc"
{
	ostringstream out;

	out << TypeToString(variable_type) << " " << variable_name;

	if (is_array_def)
		out << "[" << array_dimension << "]";

	if (initial_value != 0)
		out << " = " + initial_value->toString();

	return out.str();
}
#line 3419 "decaf_tree.cpp"

DecoratedNode * VariableDef::validateSemantics()
#line 1223 "decaf_tree.tc"
{
    /* DO NOTHING */
    return NULL;
}
#line 3427 "decaf_tree.cpp"

void VariableDef::registerDefinition()
#line 1332 "decaf_tree.tc"
{
	if ( variable_type != Int && variable_type != Boolean) {
		ErrorHandler::getInstance().handleError(line, 
			"possible variable types are int or boolean but found " + TypeToString(variable_type));
	} else {
		ExpressionType *type;
		if (variable_type == Int) {
			type = new IntegerType();
		} else {
			type = new BooleanType();
		}

		Variable *variable = getSymbolTableInstance()->getVariable(variable_name);

		if (variable != NULL) {
			ErrorHandler::getInstance().handleError(line, 
				"already defined variable '" + variable_name + "'");
			return;
		}

		if (is_array_def) {
			if (array_dimension < 0) {
				ErrorHandler::getInstance().handleError(line, "array size must be greater than zero");
			} else {
				getSymbolTableInstance()->registerVariable(variable_name, 
					new ArrayVariable(type, variable_name, array_dimension));
			}
		} else {
			SimpleVariable *variable = new SimpleVariable(type, variable_name);
			if (initial_value != NULL) {
				DecoratedExpression *d_init_value = (DecoratedExpression*)initial_value->validateSemantics();
				variable->initialized = true;
				variable->initial_value = d_init_value;
			}
			getSymbolTableInstance()->registerVariable(variable_name, variable);
		}
	}
}
#line 3469 "decaf_tree.cpp"

int VariableDef::isA(int kind) const
{
	if(kind == VariableDef_kind)
		return 1;
	else
		return Definition::isA(kind);
}

const char *VariableDef::getKindName() const
{
	return "VariableDef";
}

ParameterDef::ParameterDef(string parameter_name, Type parameter_type)
	: Definition()
{
	this->kind__ = ParameterDef_kind;
	this->parameter_name = parameter_name;
	this->parameter_type = parameter_type;
}

ParameterDef::~ParameterDef()
{
	// not used
}

string ParameterDef::toString()
#line 340 "decaf_tree.tc"
{
	return TypeToString(parameter_type) + " " + parameter_name;
}
#line 3502 "decaf_tree.cpp"

DecoratedNode * ParameterDef::validateSemantics()
#line 1228 "decaf_tree.tc"
{
    /* DO NOTHING */
    return NULL;
}
#line 3510 "decaf_tree.cpp"

void ParameterDef::registerDefinition()
#line 1371 "decaf_tree.tc"
{
	/* DO NOTHING */
}
#line 3517 "decaf_tree.cpp"

int ParameterDef::isA(int kind) const
{
	if(kind == ParameterDef_kind)
		return 1;
	else
		return Definition::isA(kind);
}

const char *ParameterDef::getKindName() const
{
	return "ParameterDef";
}

MethodDef::MethodDef(string method_name, int line)
	: Definition()
{
	this->kind__ = MethodDef_kind;
	this->method_name = method_name;
	this->line = line;
}

MethodDef::~MethodDef()
{
	// not used
}

string MethodDef::toString()
#line 344 "decaf_tree.tc"
{
	ostringstream out;

	out << TypeToString(method_return_type) << " " << method_name << "(";
	if (method_parameters != 0)
		out << ListToString(method_parameters, ", ", false);
	out << ")" << endl;
	out << method_body->toString() << endl;

	return out.str();
}
#line 3558 "decaf_tree.cpp"

DecoratedNode * MethodDef::validateSemantics()
#line 1233 "decaf_tree.tc"
{
    /* DO NOTHING */
    return NULL;
}
#line 3566 "decaf_tree.cpp"

void MethodDef::registerDefinition()
#line 1256 "decaf_tree.tc"
{
	Function *prev_def = getSymbolTableInstance()->getFunction(method_name);

	if (prev_def != NULL) {
		ErrorHandler::getInstance().handleError(line, 
			"already defined method '" + method_name + "'");
		return;
	}

	if (getSymbolTableInstance()->getVariable(method_name) != NULL) {
		ErrorHandler::getInstance().handleError(line, 
			"there is a global variable declared with this name: '" + method_name + "'");
	}

	if (method_name == "main") {
		if (method_parameters->size() > 0) {
			ErrorHandler::getInstance().handleError(line, 
				"main method cannot have parameters");
		}
		if (method_return_type != Void) {
			ErrorHandler::getInstance().handleError(line, 
				"main method must be void");
		}
	}

	Function *function_def = new Function;

	list<ParameterDef*>::iterator it = method_parameters->begin();
	int parameterId = 0;
	map<string, string> parameter_names;
	while (it != method_parameters->end()) {
		ExpressionType *type;
		string parameter_name = (*it)->parameter_name;

		switch((*it)->parameter_type) {
			case Int:
				type = new IntegerType();
				break;
			case Boolean:
				type = new BooleanType();
				break;
			default:
				ErrorHandler::getInstance().handleError(line, 
					"method parameters can only be integer or boolean");
		}

		if (parameter_names.count(parameter_name) > 0) {
			ErrorHandler::getInstance().handleError(line, 
				"duplicated parameter name '" + (parameter_name) + "'");
		} else {
			parameter_names[parameter_name] = parameter_name;
		}

		SimpleVariable *parameter = new SimpleVariable(type, parameter_name);
		parameter->parameterId = parameterId;
		function_def->parameters.push_back(parameter);

		if (parameterId > 3) {
			function_def->activation_size += 4;
		}

		it++;
		parameterId++;
	}

	if (method_return_type != Int && method_return_type != Boolean && method_return_type != Void) {
		ErrorHandler::getInstance().handleError(line, 
			"method return type must be int or boolean or void");
	}

	function_def->type = method_return_type;

	cout << "registering function " << method_name << " with type " << TypeToString(method_return_type) << endl;
	getSymbolTableInstance()->registerFunction(method_name, function_def);
}
#line 3645 "decaf_tree.cpp"

DecoratedBlockStatement * MethodDef::checkBody()
#line 1378 "decaf_tree.tc"
{
    return (DecoratedBlockStatement*)method_body->validateSemantics();
}
#line 3652 "decaf_tree.cpp"

int MethodDef::isA(int kind) const
{
	if(kind == MethodDef_kind)
		return 1;
	else
		return Definition::isA(kind);
}

const char *MethodDef::getKindName() const
{
	return "MethodDef";
}

BinaryExpression::BinaryExpression(Expression * left, Expression * right, ExpressionOperator expression_operator)
	: Expression()
{
	this->kind__ = BinaryExpression_kind;
	this->left = left;
	this->right = right;
	this->expression_operator = expression_operator;
}

BinaryExpression::~BinaryExpression()
{
	// not used
}

string BinaryExpression::toString()
#line 356 "decaf_tree.tc"
{
    ostringstream out;
    
    out << left->toString() << OperatorToString(expression_operator) << right->toString();
    
    return out.str();
}
#line 3690 "decaf_tree.cpp"

DecoratedNode * BinaryExpression::validateSemantics()
#line 572 "decaf_tree.tc"
{
    DecoratedExpression *dLeft = (DecoratedExpression*)(left->validateSemantics());
    DecoratedExpression *dRight = (DecoratedExpression*)(right->validateSemantics());
    
    if (dLeft == NULL || dRight == NULL)
        return NULL;
    
    if (!dLeft->type->isEquivalent(dRight->type)) {
        ErrorHandler::getInstance().handleError(statement_line, "type mismatch for operator " + 
                                                OperatorToString(expression_operator) +
                                                " for types " + dLeft->type->stringValue() +
                                                " and " + dRight->type->stringValue());
        cout << dLeft->type->stringValue() << " not equivalent to " << dRight->type->stringValue() << endl;
        return NULL;
    }

    if (dynamic_cast<StringType*>(dLeft->type) != NULL) {
        ErrorHandler::getInstance().handleError(statement_line, "type mismatch for operator " + 
                                                OperatorToString(expression_operator) +
                                                " for types " + dLeft->type->stringValue() +
                                                " and " + dRight->type->stringValue());
        return NULL;
    }
    
    ExpressionType      *type;
    
    if (dynamic_cast<FloatType*>(dLeft->type) != NULL
        || dynamic_cast<FloatType*>(dRight->type) != NULL) {
        
        type = new FloatType();
    	ErrorHandler::getInstance().handleError(statement_line, "floating type not supported");
    	return NULL;
    }
    if (dynamic_cast<BooleanType*>(dLeft->type) != NULL) {
        type = new BooleanType();
    }
    if (dynamic_cast<IntegerType*>(dLeft->type) != NULL) {
        type = new IntegerType();
    }
    
    
    switch(expression_operator) {
        case OpAdd:
            if (type->isNumeric())
                return new DecoratedAddExpression(type, dLeft, dRight);
            else
                return NULL;
        case OpSub:
            if (type->isNumeric())
                return new DecoratedSubExpression(type, dLeft, dRight);
            else
                return NULL;
        case OpMul:
            if (type->isNumeric())
                return new DecoratedMultExpression(type, dLeft, dRight);
            else
                return NULL;
        case OpDiv:
            if (type->isNumeric())
                return new DecoratedDivExpression(type, dLeft, dRight);
            else
                return NULL;
        case OpMod:
            if (type->isNumeric())
                return new DecoratedModExpression(type, dLeft, dRight);
            else
                return NULL;
        case OpAnd:
            if (type->isBoolean())
                return new DecoratedAndExpression(type, dLeft, dRight);
            else
                return NULL;
        case OpOr:
            if (type->isBoolean())
                return new DecoratedOrExpression(type, dLeft, dRight);
            else
                return NULL;
        case OpGT:
            if (type->isNumeric())
                return new DecoratedGTExpression(new BooleanType(), dLeft, dRight);
            else
                return NULL;
        case OpLT:
            if (type->isNumeric())
                return new DecoratedLTExpression(new BooleanType(), dLeft, dRight);
            else
                return NULL;
        case OpGTE:
            if (type->isNumeric())
                return new DecoratedGTEExpression(new BooleanType(), dLeft, dRight);
            else
                return NULL;
        case OpLTE:
            if (type->isNumeric())
                return new DecoratedLTEExpression(new BooleanType(), dLeft, dRight);
            else
                return NULL;
        case OpEq:
            if (type->isBoolean() || type->isNumeric())
                return new DecoratedEqExpression(new BooleanType(), dLeft, dRight);
            else
                return NULL;
        case OpNotEq:
            if (type->isBoolean() || type->isNumeric())
                return new DecoratedNotEqExpression(new BooleanType(), dLeft, dRight);
            else
                return NULL;
        case OpRShift:
            if (type->isNumeric())
                return new DecoratedRShiftExpression(type, dLeft, dRight);
            else
                return NULL;
        case OpLShift:
            if (type->isNumeric())
                return new DecoratedLShiftExpression(type, dLeft, dRight);
            else
                return NULL;
        case OpRot:
            if (type->isNumeric())
                return new DecoratedRotExpression(type, dLeft, dRight);
            else
                return NULL;
        default:
            return NULL;
    }
}
#line 3820 "decaf_tree.cpp"

int BinaryExpression::isA(int kind) const
{
	if(kind == BinaryExpression_kind)
		return 1;
	else
		return Expression::isA(kind);
}

const char *BinaryExpression::getKindName() const
{
	return "BinaryExpression";
}

UnaryExpression::UnaryExpression(Expression * expression, ExpressionOperator expression_operator)
	: Expression()
{
	this->kind__ = UnaryExpression_kind;
	this->expression = expression;
	this->expression_operator = expression_operator;
}

UnaryExpression::~UnaryExpression()
{
	// not used
}

string UnaryExpression::toString()
#line 364 "decaf_tree.tc"
{
    ostringstream out;
    
    out << OperatorToString(expression_operator) << expression->toString();
    
    return out.str();
}
#line 3857 "decaf_tree.cpp"

DecoratedNode * UnaryExpression::validateSemantics()
#line 699 "decaf_tree.tc"
{
    DecoratedExpression *dExpression = (DecoratedExpression*)expression->validateSemantics();
    
    if (dExpression == NULL)
        return NULL;
        
    ExpressionType  *type;
    
    switch(expression_operator) {
        case OpSub:
            if (dExpression->type->isNumeric())
                return new DecoratedNegExpression(dExpression->type, dExpression);
            else
                return NULL;
        case OpNot:
            if (dExpression->type->isBoolean())
                return new DecoratedNotExpression(dExpression->type, dExpression);
            else
                return NULL;
        default:
            return NULL;
    }
}
#line 3884 "decaf_tree.cpp"

int UnaryExpression::isA(int kind) const
{
	if(kind == UnaryExpression_kind)
		return 1;
	else
		return Expression::isA(kind);
}

const char *UnaryExpression::getKindName() const
{
	return "UnaryExpression";
}

LValueExpression::LValueExpression(string variable_name, Expression * array_index)
	: Expression()
{
	this->kind__ = LValueExpression_kind;
	this->variable_name = variable_name;
	this->array_index = array_index;
}

LValueExpression::~LValueExpression()
{
	// not used
}

string LValueExpression::toString()
#line 372 "decaf_tree.tc"
{
	ostringstream out;

	out << this->variable_name;

	if (array_index != 0)
		out << "[" << array_index->toString() << "]";

	return out.str();
}
#line 3924 "decaf_tree.cpp"

DecoratedNode * LValueExpression::validateSemantics()
#line 723 "decaf_tree.tc"
{
	cout << "inside lvalue with " << variable_name << endl;
	Variable *variable_def = NULL;

	int variable_offset = ContextManager::getInstance().getOffset(deepLevel, variable_name);
	int variable_level = ContextManager::getInstance().getDeepLevel(deepLevel, variable_name);
	bool isGlobal = false, isParameter = false;
	DecoratedExpression *d_array_index = NULL;
	ExpressionType *type = NULL;

	if (variable_offset == -1) {
		variable_def = getSymbolTableInstance()->getVariable(variable_name);
		if (array_index != NULL) {
			if (dynamic_cast<ArrayVariable*>(variable_def) == NULL) {
	        	ErrorHandler::getInstance().handleError(statement_line, 
	        		"variable '" + variable_name + "' is not an array");
	        }
	        d_array_index = (DecoratedExpression*)array_index->validateSemantics();
	        if (d_array_index == NULL){
	        	return NULL;
	        } else {
	        	if (!d_array_index->type->isEquivalent(new IntegerType())) {
	        		ErrorHandler::getInstance().handleError(statement_line, 
	        			"array index expression must be of int type");
	        		return NULL;
	        	}
	        }
		}
		if (variable_def != NULL) {
			type = variable_def->type;
			isGlobal = true;
		}

	} else {
		if (array_index != NULL) {
			ErrorHandler::getInstance().handleError(statement_line, 
        		"variable '" + variable_name + "' is not an array");
		}
		type = TypeToExpressionType(ContextManager::getInstance().getType(deepLevel, variable_name));
	}


    SimpleVariable *parameter = (SimpleVariable*)currentFunction->findParameter(variable_name);
    if (variable_offset == -1 && variable_def == NULL && parameter == NULL) {
		ErrorHandler::getInstance().handleError(statement_line, 
			"variable '" + variable_name + "' not declared in this scope");
		return NULL;
	}

    if (parameter != NULL && variable_offset == -1) {
    	type = parameter->type;
    	isParameter = true;
    	variable_offset = currentFunction->offsetFromFp(variable_name);
    }    

	DecoratedLValue *d_lvalue = new DecoratedLValue(type, variable_name, d_array_index);
	d_lvalue->offset = variable_offset;
	d_lvalue->deepLevel = variable_level;
	d_lvalue->isParameter = isParameter;
	d_lvalue->isGlobal = isGlobal;
    return d_lvalue;
}
#line 3990 "decaf_tree.cpp"

int LValueExpression::isA(int kind) const
{
	if(kind == LValueExpression_kind)
		return 1;
	else
		return Expression::isA(kind);
}

const char *LValueExpression::getKindName() const
{
	return "LValueExpression";
}

MethodCallExpression::MethodCallExpression(string method_name, ExpressionList * method_arguments)
	: Expression()
{
	this->kind__ = MethodCallExpression_kind;
	this->method_name = method_name;
	this->method_arguments = method_arguments;
}

MethodCallExpression::~MethodCallExpression()
{
	// not used
}

string MethodCallExpression::toString()
#line 383 "decaf_tree.tc"
{
	ostringstream out;

	out << this->method_name << "(" << ListToString(method_arguments, ", ", false) << ")";

	return out.str();
}
#line 4027 "decaf_tree.cpp"

DecoratedNode * MethodCallExpression::validateSemantics()
#line 786 "decaf_tree.tc"
{    
	Function *function_def = getSymbolTableInstance()->getFunction(method_name);
	if ( function_def == NULL ) {
		ErrorHandler::getInstance().handleError(statement_line, "undefined method '" + method_name + "'");
		return NULL;
	}

	DecoratedExpressionList *d_arguments = new DecoratedExpressionList;
	if (method_arguments != NULL) {
	    list<Expression*>::iterator expression_iterator = method_arguments->begin();	 

	    if (function_def->parameters.size() != method_arguments->size()) {
	    	ErrorHandler::getInstance().handleError(statement_line, 
	    		"incorrect number of arguments in method '" + method_name + "'");
	    	return NULL;	
	    }   
	    
	    int parameterId = 0;
	    int nullCount = 0;
	    while (expression_iterator != method_arguments->end()) {
	        Expression *expression = *expression_iterator;
	        DecoratedExpression *d_expr = (DecoratedExpression*)expression->validateSemantics();

	        if (d_expr == NULL)
	        	return NULL;

	        if (!(d_expr->type->isEquivalent(function_def->getParameter(parameterId)->type))) {
	        	ostringstream out;

	        	out << "type mismatch for parameter at position " << parameterId 
	        		<< " expected " << function_def->getParameter(parameterId)->type->stringValue() 
	        		<< " but found " << d_expr->type->stringValue();
	        	ErrorHandler::getInstance().handleError(statement_line, out.str());
	        	nullCount++;
	        }

	        d_arguments->push_back(d_expr);
	        d_expr->line = statement_line;
	        
	        expression_iterator++;
	        parameterId++;
	    }
	    if (nullCount != 0) {
			return NULL;
		}
	}

	ExpressionType *type;

	switch(function_def->type) {
		case Int:
			type = new IntegerType();
			break;
		case Boolean:
			type = new BooleanType();
			break;
		case Void:
			ErrorHandler::getInstance().handleError(statement_line, 
				"void method '" + method_name + "' cannot be used as an expression");
			return NULL;
		default:
			ErrorHandler::getInstance().handleError(statement_line, "this shouldn't be happening");

	}

    return new DecoratedMethodCallExpression(type, method_name, d_arguments);
}
#line 4098 "decaf_tree.cpp"

int MethodCallExpression::isA(int kind) const
{
	if(kind == MethodCallExpression_kind)
		return 1;
	else
		return Expression::isA(kind);
}

const char *MethodCallExpression::getKindName() const
{
	return "MethodCallExpression";
}

IntConstantExpression::IntConstantExpression(int int_value)
	: Expression()
{
	this->kind__ = IntConstantExpression_kind;
	this->constant_type = Int;
	this->int_value = int_value;
}

IntConstantExpression::~IntConstantExpression()
{
	// not used
}

string IntConstantExpression::toString()
#line 391 "decaf_tree.tc"
{
	ostringstream out;

	out << int_value ;
	return out.str();
}
#line 4134 "decaf_tree.cpp"

DecoratedNode * IntConstantExpression::validateSemantics()
#line 854 "decaf_tree.tc"
{
    return new DecoratedIntConstant(new IntegerType(), int_value);
}
#line 4141 "decaf_tree.cpp"

int IntConstantExpression::isA(int kind) const
{
	if(kind == IntConstantExpression_kind)
		return 1;
	else
		return Expression::isA(kind);
}

const char *IntConstantExpression::getKindName() const
{
	return "IntConstantExpression";
}

RealConstantExpression::RealConstantExpression(float float_value)
	: Expression()
{
	this->kind__ = RealConstantExpression_kind;
	this->constant_type = Real;
	this->float_value = float_value;
}

RealConstantExpression::~RealConstantExpression()
{
	// not used
}

string RealConstantExpression::toString()
#line 398 "decaf_tree.tc"
{
	ostringstream out;

	out << float_value;
	return out.str();
}
#line 4177 "decaf_tree.cpp"

DecoratedNode * RealConstantExpression::validateSemantics()
#line 858 "decaf_tree.tc"
{
    ErrorHandler::getInstance().handleError(statement_line, "floating type is not supported");
    return NULL;
}
#line 4185 "decaf_tree.cpp"

int RealConstantExpression::isA(int kind) const
{
	if(kind == RealConstantExpression_kind)
		return 1;
	else
		return Expression::isA(kind);
}

const char *RealConstantExpression::getKindName() const
{
	return "RealConstantExpression";
}

BooleanConstantExpression::BooleanConstantExpression(bool bool_value)
	: Expression()
{
	this->kind__ = BooleanConstantExpression_kind;
	this->constant_type = Boolean;
	this->bool_value = bool_value;
}

BooleanConstantExpression::~BooleanConstantExpression()
{
	// not used
}

string BooleanConstantExpression::toString()
#line 405 "decaf_tree.tc"
{
	ostringstream out;

	if (bool_value)
		out << "true";
	else 
		out << "false";
	return out.str();
}
#line 4224 "decaf_tree.cpp"

DecoratedNode * BooleanConstantExpression::validateSemantics()
#line 863 "decaf_tree.tc"
{
    return new DecoratedBooleanConstant(new BooleanType(), bool_value);
}
#line 4231 "decaf_tree.cpp"

int BooleanConstantExpression::isA(int kind) const
{
	if(kind == BooleanConstantExpression_kind)
		return 1;
	else
		return Expression::isA(kind);
}

const char *BooleanConstantExpression::getKindName() const
{
	return "BooleanConstantExpression";
}

StringConstantExpression::StringConstantExpression(char * string_value)
	: Expression()
{
	this->kind__ = StringConstantExpression_kind;
	this->constant_type = String;
	this->string_value = string_value;
}

StringConstantExpression::~StringConstantExpression()
{
	// not used
}

string StringConstantExpression::toString()
#line 415 "decaf_tree.tc"
{
	ostringstream out;

	out << string_value;
	return out.str();
}
#line 4267 "decaf_tree.cpp"

DecoratedNode * StringConstantExpression::validateSemantics()
#line 867 "decaf_tree.tc"
{
	getSymbolTableInstance()->registerString(string_value);
    return new DecoratedStringConstant(new StringType(), string_value);
}
#line 4275 "decaf_tree.cpp"

int StringConstantExpression::isA(int kind) const
{
	if(kind == StringConstantExpression_kind)
		return 1;
	else
		return Expression::isA(kind);
}

const char *StringConstantExpression::getKindName() const
{
	return "StringConstantExpression";
}

LocalVariableDefList::LocalVariableDefList(int line, int column)
	: Statement(line, column)
{
	this->kind__ = LocalVariableDefList_kind;
	this->variable_names = NULL;
}

LocalVariableDefList::~LocalVariableDefList()
{
	// not used
}

string LocalVariableDefList::toString()
#line 332 "decaf_tree.tc"
{
	ostringstream out;

	out << TypeToString(variable_type) << " ";

	return out.str();
}
#line 4311 "decaf_tree.cpp"

DecoratedNode * LocalVariableDefList::validateSemantics()
#line 1238 "decaf_tree.tc"
{
	context = ContextManager::getInstance().getContext(deepLevel);
	currentFunction->activation_size += variable_names->size() * 4;
	list<string>::iterator string_iterator = variable_names->begin();
	while (string_iterator != variable_names->end()) {
		string variable_name = (*string_iterator);
		cout << "variable " << variable_name << " offset " << currentScopeSize << endl;
		context->saveVarInfo(variable_name, new VarInfo(currentScopeSize, 4, variable_type));
		currentScopeSize += 4;
		string_iterator++;		
	}
	return NULL;
}
#line 4328 "decaf_tree.cpp"

int LocalVariableDefList::isA(int kind) const
{
	if(kind == LocalVariableDefList_kind)
		return 1;
	else
		return Statement::isA(kind);
}

const char *LocalVariableDefList::getKindName() const
{
	return "LocalVariableDefList";
}

AssignmentStatement::AssignmentStatement(int line, int column, Expression * lvalue, Expression * expr)
	: Statement(line, column)
{
	this->kind__ = AssignmentStatement_kind;
	this->lvalue = lvalue;
	this->expr = expr;
}

AssignmentStatement::~AssignmentStatement()
{
	// not used
}

string AssignmentStatement::toString()
#line 423 "decaf_tree.tc"
{
	ostringstream out;

	out << lvalue->toString() << " = " << expr->toString() << ";";

	return out.str();
}
#line 4365 "decaf_tree.cpp"

DecoratedNode * AssignmentStatement::validateSemantics()
#line 874 "decaf_tree.tc"
{
	if (isUnreachableStatement()) 
		ErrorHandler::getInstance().handleWarning(line, "unreachable statement");

	statement_line = line;

    cout << "validating assignment statement semantics" << endl;
    DecoratedLValue *d_lvalue = (DecoratedLValue*)(lvalue->validateSemantics());
    cout << "after lvalue semantics" << endl;
    DecoratedExpression *d_expr = (DecoratedExpression*)(expr->validateSemantics());

    if (d_expr == NULL || d_lvalue == NULL) {
    	cout << "returning null" << endl;
    	return NULL;
    }
    cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡" << endl;
    if (!(d_expr->type->isEquivalent(d_lvalue->type))) {
    	
    	ErrorHandler::getInstance().handleError(line, 
    		"type mismatch assigning " + d_expr->type->stringValue() 
    		+ " to " + d_lvalue->type->stringValue());
    	cout << "!!!!!!!!!!!!!!!!!!!" << endl;
    	return NULL;
    }

    d_lvalue->line = line;
    d_expr->line = line;

    return new DecoratedAssignmentStatement(line, d_lvalue, d_expr);
}
#line 4399 "decaf_tree.cpp"

int AssignmentStatement::isA(int kind) const
{
	if(kind == AssignmentStatement_kind)
		return 1;
	else
		return Statement::isA(kind);
}

const char *AssignmentStatement::getKindName() const
{
	return "AssignmentStatement";
}

MethodCallStatement::MethodCallStatement(int line, int column, string name, ExpressionList * arguments)
	: Statement(line, column)
{
	this->kind__ = MethodCallStatement_kind;
	this->name = name;
	this->arguments = arguments;
}

MethodCallStatement::~MethodCallStatement()
{
	// not used
}

string MethodCallStatement::toString()
#line 431 "decaf_tree.tc"
{
	return this->name + "(" + ListToString(arguments, ", ", false) + ");";
}
#line 4432 "decaf_tree.cpp"

DecoratedNode * MethodCallStatement::validateSemantics()
#line 905 "decaf_tree.tc"
{
	if (isUnreachableStatement()) 
		ErrorHandler::getInstance().handleWarning(line, "unreachable statement");

	statement_line = line;

	Function *function_def = getSymbolTableInstance()->getFunction(name);
	if ( function_def == NULL ) {
		ErrorHandler::getInstance().handleError(line, "undefined method '" + name + "'");
		return NULL;
	}

	DecoratedExpressionList *d_arguments = new DecoratedExpressionList;
	if (arguments != NULL) {
	    list<Expression*>::iterator expression_iterator = arguments->begin();	 

	    if (function_def->parameters.size() != arguments->size()) {
	    	ErrorHandler::getInstance().handleError(line, 
	    		"incorrect number of arguments in method '" + name + "'");
	    	return NULL;	
	    }   
	    
	    int parameterId = 0;
	    int nullCount = 0;
	    while (expression_iterator != arguments->end()) {
	        Expression *expression = *expression_iterator;
	        DecoratedExpression *d_expr = (DecoratedExpression*)expression->validateSemantics();

	        if (d_expr == NULL)
	        	return NULL;

	        if (!(d_expr->type->isEquivalent(function_def->getParameter(parameterId)->type))) {
	        	ErrorHandler::getInstance().handleError(line, 
	        		"type mismatch for parameter at position " + parameterId);
	        	nullCount++;
	        }

	        d_arguments->push_back(d_expr);
	        d_expr->line = line;
	        
	        expression_iterator++;
	        parameterId++;
	    }
	    if (nullCount != 0) {
			return NULL;
		}
	}

    return new DecoratedMethodCallStatement(line, name, d_arguments);
}
#line 4486 "decaf_tree.cpp"

int MethodCallStatement::isA(int kind) const
{
	if(kind == MethodCallStatement_kind)
		return 1;
	else
		return Statement::isA(kind);
}

const char *MethodCallStatement::getKindName() const
{
	return "MethodCallStatement";
}

IfStatement::IfStatement(int line, int column, Expression * condition, Statement * true_part, Statement * false_part)
	: Statement(line, column)
{
	this->kind__ = IfStatement_kind;
	this->condition = condition;
	this->true_part = true_part;
	this->false_part = false_part;
}

IfStatement::~IfStatement()
{
	// not used
}

string IfStatement::toString()
#line 435 "decaf_tree.tc"
{
	ostringstream out;

	out << "if (" << condition->toString() << ")" << endl;
	out << true_part->toString() << endl;

	if (false_part != 0) {
		out << "else" << endl;
		out << false_part->toString() << endl;
	}

	return out.str();
}
#line 4530 "decaf_tree.cpp"

DecoratedNode * IfStatement::validateSemantics()
#line 956 "decaf_tree.tc"
{
	if (isUnreachableStatement()) 
		ErrorHandler::getInstance().handleWarning(line, "unreachable statement");

	statement_line = line;

    DecoratedExpression *d_condition = (DecoratedExpression*)(condition->validateSemantics());
    
    insideLoop = true;
    DecoratedBlockStatement *d_true = (DecoratedBlockStatement*)(true_part->validateSemantics());
    insideLoop = false;
    returnFound = false;
    continueFound = false;
    breakFound = false;

    DecoratedBlockStatement *d_false = NULL;
    
    if (false_part != NULL) {
        d_false = (DecoratedBlockStatement*)(false_part->validateSemantics());

        if (d_false == NULL)
        	return NULL;
    }
    insideLoop = false;

    if (d_true == NULL || d_condition == NULL) {
    	cout << "return null 1" << endl;
    	cout << (d_condition == NULL) << endl;
    	cout << (d_true == NULL) << endl;
    	return NULL;
    }

    if (!d_condition->type->isBoolean()) {
    	ErrorHandler::getInstance().handleError(line, "if statement condition must be boolean");
    	cout << "return null 2" << endl;
    	return NULL;
    }

    return new DecoratedIfStatement(line, d_condition, d_true, d_false);
}
#line 4574 "decaf_tree.cpp"

int IfStatement::isA(int kind) const
{
	if(kind == IfStatement_kind)
		return 1;
	else
		return Statement::isA(kind);
}

const char *IfStatement::getKindName() const
{
	return "IfStatement";
}

WhileStatement::WhileStatement(int line, int column, Expression * condition, Statement * loop_body)
	: Statement(line, column)
{
	this->kind__ = WhileStatement_kind;
	this->condition = condition;
	this->loop_body = loop_body;
}

WhileStatement::~WhileStatement()
{
	// not used
}

string WhileStatement::toString()
#line 449 "decaf_tree.tc"
{
	ostringstream out;

	out << "while (" << condition->toString() << ")" << endl;
	out << loop_body->toString() << endl;

	return out.str();
}
#line 4612 "decaf_tree.cpp"

DecoratedNode * WhileStatement::validateSemantics()
#line 997 "decaf_tree.tc"
{
	if (isUnreachableStatement()) 
		ErrorHandler::getInstance().handleWarning(line, "unreachable statement");

	statement_line = line;

    DecoratedExpression *d_expr = (DecoratedExpression*)condition->validateSemantics();

    insideLoop = true;
    continueFound = false;
    breakFound = false;

    DecoratedStatement *d_stmt = (DecoratedStatement*)loop_body->validateSemantics();
    
    insideLoop = false;
    

    if (d_expr == NULL || d_stmt == NULL)
    	return NULL;

    if (!d_expr->type->isBoolean()) {
    	ErrorHandler::getInstance().handleError(line, "while statement condition must be boolean");
    	return NULL;
    }

    d_expr->line = line;
    d_stmt->line = line;

    return new DecoratedWhileStatement(line, d_expr, d_stmt);
}
#line 4646 "decaf_tree.cpp"

int WhileStatement::isA(int kind) const
{
	if(kind == WhileStatement_kind)
		return 1;
	else
		return Statement::isA(kind);
}

const char *WhileStatement::getKindName() const
{
	return "WhileStatement";
}

ForStatement::ForStatement(int line, int column, Statement * assignment_list1, Expression * condition, Statement * assignment_list2, Statement * loop_body)
	: Statement(line, column)
{
	this->kind__ = ForStatement_kind;
	this->assignment_list1 = assignment_list1;
	this->condition = condition;
	this->assignment_list2 = assignment_list2;
	this->loop_body = loop_body;
}

ForStatement::~ForStatement()
{
	// not used
}

string ForStatement::toString()
#line 458 "decaf_tree.tc"
{
	ostringstream out;

	out << "for (" << assignment_list1->toString();
	out << ";" << condition->toString();
	out << ";" << assignment_list2->toString() << ")";
	out << endl << loop_body->toString() << endl;

	return out.str();
}
#line 4688 "decaf_tree.cpp"

DecoratedNode * ForStatement::validateSemantics()
#line 1028 "decaf_tree.tc"
{
	if (isUnreachableStatement()) 
		ErrorHandler::getInstance().handleWarning(line, "unreachable statement");

	statement_line = line;

    DecoratedStatement *d_assignment_list1 = (DecoratedStatement*)assignment_list1->validateSemantics();
    DecoratedExpression *d_condition = (DecoratedExpression*)condition->validateSemantics();
    DecoratedStatement *d_assignment_list2 = (DecoratedStatement*)assignment_list2->validateSemantics();

    insideLoop = true;
    DecoratedBlockStatement *d_body = (DecoratedBlockStatement*)loop_body->validateSemantics();
    insideLoop = false;
    continueFound = false;
    breakFound = false;

    if (d_assignment_list1 == NULL || d_assignment_list2 == NULL 
    	|| d_condition == NULL || d_body == NULL) {
    	return NULL;
    }

    if (!d_condition->type->isBoolean()) {
    	ErrorHandler::getInstance().handleError(line, "for statement condition must be boolean");
    	return NULL;
    }

    return new DecoratedForStatement(line, d_assignment_list1, d_condition, d_assignment_list2, d_body);
}
#line 4720 "decaf_tree.cpp"

int ForStatement::isA(int kind) const
{
	if(kind == ForStatement_kind)
		return 1;
	else
		return Statement::isA(kind);
}

const char *ForStatement::getKindName() const
{
	return "ForStatement";
}

ReturnStatement::ReturnStatement(int line, int column, Expression * expr)
	: Statement(line, column)
{
	this->kind__ = ReturnStatement_kind;
	this->expr = expr;
}

ReturnStatement::~ReturnStatement()
{
	// not used
}

string ReturnStatement::toString()
#line 469 "decaf_tree.tc"
{
	ostringstream out;
	
	out << "return ";
	if (expr != NULL) {
		out << expr->toString();
	}
	out << ";";
	
	return out.str();
}
#line 4760 "decaf_tree.cpp"

DecoratedNode * ReturnStatement::validateSemantics()
#line 1057 "decaf_tree.tc"
{
	if (isUnreachableStatement()) 
		ErrorHandler::getInstance().handleWarning(line, "unreachable statement");

	statement_line = line;
	returnFound = true;

    DecoratedExpression *decorated_expression = NULL;
    if (expr != NULL) {
        decorated_expression = (DecoratedExpression*)expr->validateSemantics();
    }

    if (expr != NULL && decorated_expression == NULL) {
    	return NULL;
    }

    if (expr == NULL && currentFunction->type != Void) {
    	ErrorHandler::getInstance().handleError(line, 
    		"return expression must be " + TypeToString(currentFunction->type) 
    		+ " but found void ");
    }

    if (currentFunction->type == Void && expr != NULL) {
    	ErrorHandler::getInstance().handleError(line, "void method cannot return an expression");
    	return NULL;
    } else if (decorated_expression != NULL && 
    	!decorated_expression->type->isEquivalent(TypeToExpressionType(currentFunction->type))) {
    	ErrorHandler::getInstance().handleError(line, 
    		"return expression must be " + TypeToString(currentFunction->type)
    		+ " but found " + decorated_expression->type->stringValue());
    	return NULL;
    }

    return new DecoratedReturnStatement(line, decorated_expression);
}
#line 4799 "decaf_tree.cpp"

int ReturnStatement::isA(int kind) const
{
	if(kind == ReturnStatement_kind)
		return 1;
	else
		return Statement::isA(kind);
}

const char *ReturnStatement::getKindName() const
{
	return "ReturnStatement";
}

BreakStatement::BreakStatement(int line, int column)
	: Statement(line, column)
{
	this->kind__ = BreakStatement_kind;
}

BreakStatement::~BreakStatement()
{
	// not used
}

string BreakStatement::toString()
#line 481 "decaf_tree.tc"
{
	return "break;";
}
#line 4830 "decaf_tree.cpp"

DecoratedNode * BreakStatement::validateSemantics()
#line 1093 "decaf_tree.tc"
{
	if (isUnreachableStatement()) 
		ErrorHandler::getInstance().handleWarning(line, "unreachable statement");

	statement_line = line;

    if (!insideLoop) {
    	ErrorHandler::getInstance().handleError(line, "break statement must be inside a loop");
    	return NULL;
    }

    breakFound = true;
    return new DecoratedBreakStatement(line);
}
#line 4848 "decaf_tree.cpp"

int BreakStatement::isA(int kind) const
{
	if(kind == BreakStatement_kind)
		return 1;
	else
		return Statement::isA(kind);
}

const char *BreakStatement::getKindName() const
{
	return "BreakStatement";
}

ContinueStatement::ContinueStatement(int line, int column)
	: Statement(line, column)
{
	this->kind__ = ContinueStatement_kind;
}

ContinueStatement::~ContinueStatement()
{
	// not used
}

string ContinueStatement::toString()
#line 485 "decaf_tree.tc"
{
	return "continue;";
}
#line 4879 "decaf_tree.cpp"

DecoratedNode * ContinueStatement::validateSemantics()
#line 1108 "decaf_tree.tc"
{
	if (isUnreachableStatement()) 
		ErrorHandler::getInstance().handleWarning(line, "unreachable statement");

	statement_line = line;

    if (!insideLoop) {
    	ErrorHandler::getInstance().handleError(line, "continue statement must be inside a loop");
    	return NULL;
    }

    continueFound = true;
    return new DecoratedContinueStatement(line);
}
#line 4897 "decaf_tree.cpp"

int ContinueStatement::isA(int kind) const
{
	if(kind == ContinueStatement_kind)
		return 1;
	else
		return Statement::isA(kind);
}

const char *ContinueStatement::getKindName() const
{
	return "ContinueStatement";
}

BlockStatement::BlockStatement(int line, int column)
	: Statement(line, column)
{
	this->kind__ = BlockStatement_kind;
	this->statement_list = 0;
}

BlockStatement::~BlockStatement()
{
	// not used
}

string BlockStatement::toString()
#line 489 "decaf_tree.tc"
{
	ostringstream out;

	out << "{" << endl;

	if (statement_list != 0)
		out << ListToString(statement_list, "\n", true);

	out << "}";

	return out.str();
}
#line 4938 "decaf_tree.cpp"

DecoratedNode * BlockStatement::validateSemantics()
#line 1123 "decaf_tree.tc"
{
	if (isUnreachableStatement()) 
		ErrorHandler::getInstance().handleWarning(line, "unreachable statement");

	deepLevel += 1;
	ContextManager::getInstance().pushScopeSize(currentScopeSize);
	ContextManager::getInstance().registerContext(deepLevel, new Context);
    
	currentScopeSize = 0;

	statement_line = line;

    list<Statement*>::iterator statement_iterator = statement_list->begin();
    
    DecoratedStatementList  *decorated_statement_list = new DecoratedStatementList;

    int nullCount = 0;
    
    while (statement_iterator != statement_list->end()) {
        Statement *statement = *statement_iterator;
        
        DecoratedStatement *decorated_statement =  (DecoratedStatement*)statement->validateSemantics();

        if (dynamic_cast<LocalVariableDefList*>(statement) == NULL) {
	        if (decorated_statement != NULL)
	        	decorated_statement_list->push_back(decorated_statement);
	        else
	        	nullCount++;
	    }
        
        statement_iterator++;
    }

    cout << "nullCount " << nullCount << endl;
    if (nullCount>0)
    	return NULL;

    DecoratedBlockStatement *newBlock = new DecoratedBlockStatement(line, decorated_statement_list);
    newBlock->deepLevel = deepLevel;
    newBlock->scopeSize = currentScopeSize;
    newBlock->context = ContextManager::getInstance().getContext(deepLevel);
    cout << "scope size set to " << currentScopeSize << endl;
    cout << "deep level " << deepLevel << endl;
    
    currentScopeSize = ContextManager::getInstance().getCurrentScopeSize();
    ContextManager::getInstance().unregisterContext(deepLevel);
    ContextManager::getInstance().popScopeSize();
    deepLevel -= 1;
    
    return newBlock;
}
#line 4993 "decaf_tree.cpp"

int BlockStatement::isA(int kind) const
{
	if(kind == BlockStatement_kind)
		return 1;
	else
		return Statement::isA(kind);
}

const char *BlockStatement::getKindName() const
{
	return "BlockStatement";
}

PrintStatement::PrintStatement(int line, int column, ExpressionList * arguments)
	: Statement(line, column)
{
	this->kind__ = PrintStatement_kind;
	this->arguments = arguments;
}

PrintStatement::~PrintStatement()
{
	// not used
}

string PrintStatement::toString()
#line 502 "decaf_tree.tc"
{
	return  "print " + ListToString(arguments, ", ", false) + ";";
}
#line 5025 "decaf_tree.cpp"

DecoratedNode * PrintStatement::validateSemantics()
#line 1175 "decaf_tree.tc"
{
	if (isUnreachableStatement()) 
		ErrorHandler::getInstance().handleWarning(line, "unreachable statement");

	statement_line = line;

	list<Expression*>::iterator expression_iterator = arguments->begin();
    
    DecoratedExpressionList *d_arguments = new DecoratedExpressionList;
    while (expression_iterator != arguments->end()) {
        Expression *expression = *expression_iterator;
        DecoratedExpression *d_expr = (DecoratedExpression*)expression->validateSemantics();

        if (d_expr == NULL)
        	return NULL;

        d_arguments->push_back(d_expr);
        
        expression_iterator++;
    }

    return new DecoratedPrintStatement(line, d_arguments);
}
#line 5052 "decaf_tree.cpp"

int PrintStatement::isA(int kind) const
{
	if(kind == PrintStatement_kind)
		return 1;
	else
		return Statement::isA(kind);
}

const char *PrintStatement::getKindName() const
{
	return "PrintStatement";
}

ReadStatement::ReadStatement(int line, int column, ExpressionList * arguments)
	: Statement(line, column)
{
	this->kind__ = ReadStatement_kind;
	this->arguments = arguments;
}

ReadStatement::~ReadStatement()
{
	// not used
}

string ReadStatement::toString()
#line 506 "decaf_tree.tc"
{
	return  "read " + ListToString(arguments, ", ", false) + ";";
}
#line 5084 "decaf_tree.cpp"

DecoratedNode * ReadStatement::validateSemantics()
#line 1199 "decaf_tree.tc"
{
	if (isUnreachableStatement()) 
		ErrorHandler::getInstance().handleWarning(line, "unreachable statement");

	statement_line = line;

	list<Expression*>::iterator expression_iterator = arguments->begin();
    
    DecoratedExpressionList *d_arguments = new DecoratedExpressionList;
    while (expression_iterator != arguments->end()) {
        Expression *expression = *expression_iterator;
        DecoratedExpression *d_expr = (DecoratedExpression*)expression->validateSemantics();

        if (d_expr == NULL)
        	return NULL;

        d_arguments->push_back(d_expr);
        
        expression_iterator++;
    }

    return new DecoratedReadStatement(line, d_arguments);
}
#line 5111 "decaf_tree.cpp"

int ReadStatement::isA(int kind) const
{
	if(kind == ReadStatement_kind)
		return 1;
	else
		return Statement::isA(kind);
}

const char *ReadStatement::getKindName() const
{
	return "ReadStatement";
}

static SymbolTable * getSymbolTableInstance_1__(void)
#line 146 "symbol_table.tc"
{
	if (symbol_table == NULL)
		symbol_table = new SymbolTable;

	return symbol_table;
}
#line 5134 "decaf_tree.cpp"

SymbolTable * getSymbolTableInstance(void)
{
	return getSymbolTableInstance_1__();
	return 0;
}

#line 158 "decaf_tree.tc"

void addFieldDef(ClassDef *classDef, VariableDef *field_def) {
	if (classDef->field_def_list == 0)
		classDef->field_def_list = new VariableDefList;
	classDef->field_def_list->push_back(field_def);
}

void addMethod(ClassDef *classDef, MethodDef *method_def) {
	if (classDef->method_def_list == 0)
		classDef->method_def_list = new MethodDefList;
	classDef->method_def_list->push_back(method_def);
}
#line 285 "decaf_tree.tc"

void setStatementList(BlockStatement *block, StatementList *stList) {
	block->statement_list = stList;
}

void addStatement(BlockStatement *block, Statement *statement) {
	if (block->statement_list == 0)
		block->statement_list = new StatementList;

	block->statement_list->push_back(statement);
}
#line 5167 "decaf_tree.cpp"
