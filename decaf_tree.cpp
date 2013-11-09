/* decaf_tree.cpp.  Generated automatically by treecc */
#line 69 "decaf_tree.tc"

#include "decaf_tree.h"

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
#line 1 "decaf_semantic_tree.tc"

    #include "data_layout/register_utils.h"
    #include "label_manager.h"

    string indent(int count) {
        ostringstream out;
        out << string(count, '\t');
        return "";
        //return out.str();
    }
#line 42 "decaf_tree.cpp"

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
#line 321 "decaf_tree.cpp"
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
#line 14 "decaf_types.tc"
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
#line 383 "decaf_tree.cpp"

bool FloatType::isNumeric()
#line 63 "decaf_types.tc"
{
    return true;
}
#line 390 "decaf_tree.cpp"

bool FloatType::isBoolean()
#line 82 "decaf_types.tc"
{
    return false;
}
#line 397 "decaf_tree.cpp"

string FloatType::stringValue()
#line 101 "decaf_types.tc"
{
    return "float";
}
#line 404 "decaf_tree.cpp"

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
#line 42 "decaf_types.tc"
{
    StringType *casted_to_string = dynamic_cast<StringType*>(secondType);
    if (casted_to_string != NULL) {
        return true;
    } else {
        return false;
    }
}
#line 440 "decaf_tree.cpp"

bool StringType::isNumeric()
#line 75 "decaf_types.tc"
{
    return false;
}
#line 447 "decaf_tree.cpp"

bool StringType::isBoolean()
#line 94 "decaf_types.tc"
{
    return false;
}
#line 454 "decaf_tree.cpp"

string StringType::stringValue()
#line 113 "decaf_types.tc"
{
    return "string";
}
#line 461 "decaf_tree.cpp"

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
#line 28 "decaf_types.tc"
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
#line 502 "decaf_tree.cpp"

bool IntegerType::isNumeric()
#line 67 "decaf_types.tc"
{
    return true;
}
#line 509 "decaf_tree.cpp"

bool IntegerType::isBoolean()
#line 86 "decaf_types.tc"
{
    return false;
}
#line 516 "decaf_tree.cpp"

string IntegerType::stringValue()
#line 105 "decaf_types.tc"
{
    return "integer";
}
#line 523 "decaf_tree.cpp"

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
#line 51 "decaf_types.tc"
{
    BooleanType *casted_to_boolean = dynamic_cast<BooleanType*>(secondType);
    if (casted_to_boolean != NULL) {
        return true;
    } else {
        return false;
    }
}
#line 559 "decaf_tree.cpp"

bool BooleanType::isNumeric()
#line 71 "decaf_types.tc"
{
    return false;
}
#line 566 "decaf_tree.cpp"

bool BooleanType::isBoolean()
#line 90 "decaf_types.tc"
{
    return true;
}
#line 573 "decaf_tree.cpp"

string BooleanType::stringValue()
#line 109 "decaf_types.tc"
{
    return "boolean";
}
#line 580 "decaf_tree.cpp"

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
#line 600 "decaf_semantic_tree.tc"
{
    ostringstream out;

    out << this->name << ":" << endl;
    out << indent(indentLevel) << "main: " << endl;
    if (main != NULL) {
        out << indent(indentLevel) << main->generateCode(indentLevel + 1) << endl;
    }
    return out.str();
}
#line 655 "decaf_tree.cpp"

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

DecoratedStatement::DecoratedStatement()
	: DecoratedNode()
{
	this->kind__ = DecoratedStatement_kind;
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
}

DecoratedLValue::~DecoratedLValue()
{
	// not used
}

string DecoratedLValue::generateCode(int indentLevel)
#line 483 "decaf_semantic_tree.tc"
{
    ostringstream out;

    string reg;
    reg = RegisterManager::getInstance().getTempRegister();

    out << indent(indentLevel) << "la " << reg << ", " << variable_name << endl;
    if (array_index != NULL) {
        out << indent(indentLevel) << "add " << reg << ", " << reg << ", " << array_index->place << endl;
    }
    out << indent(indentLevel) << "sw " << reg << ", 0(" << reg << ")" << endl;
    this->place =  reg;

    return out.str();
}
#line 825 "decaf_tree.cpp"

string DecoratedLValue::getLocation(int indentLevel)
#line 613 "decaf_semantic_tree.tc"
{
    ostringstream out;

    string reg;
    reg = RegisterManager::getInstance().getTempRegister();

    out << indent(indentLevel) << "la " << reg << ", " << variable_name << endl;
    if (array_index != NULL) {
        out << indent(indentLevel) << "add " << reg << ", " << reg << ", " << array_index->place << endl;
    }
    this->place =  reg;

    return out.str();
}
#line 843 "decaf_tree.cpp"

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
#line 499 "decaf_semantic_tree.tc"
{
    ostringstream out;

    list<DecoratedExpression*>::iterator it = arguments->begin();
    int argc = 0;
    while (it != arguments->end()) {
        if (argc < 5) {
            //usar $a0...$a4
        } else {
            //poner en la pila
        }
        it++;
    }
    out << indent(indentLevel) << "jal " << name << endl;
    
    this->place = "$v0";

    return out.str();
}
#line 892 "decaf_tree.cpp"

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
#line 129 "decaf_semantic_tree.tc"
{
    ostringstream out;
    
    out << left->generateCode(indentLevel + 1);
    out << right->generateCode(indentLevel + 1);
    
    freeRegister(left->place);
    freeRegister(right->place);
    
    string reg;
    reg = RegisterManager::getInstance().getTempRegister();
    
    out << indent(indentLevel) << "add " << reg << ", " <<left->place << ", " << right->place << endl;
    this->place = reg;
    
    return out.str();
}
#line 937 "decaf_tree.cpp"

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
#line 147 "decaf_semantic_tree.tc"
{
    ostringstream out;
    
    out << left->generateCode(indentLevel + 1);
    out << right->generateCode(indentLevel + 1);
    
    freeRegister(left->place);
    freeRegister(right->place);
    
    string reg;
    reg = RegisterManager::getInstance().getTempRegister();
    
    out << indent(indentLevel) << "sub " << reg << ", " <<left->place << ", " << right->place << endl;
    this->place = reg;
    
    return out.str();
}
#line 982 "decaf_tree.cpp"

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
#line 165 "decaf_semantic_tree.tc"
{
    ostringstream out;
    
    out << left->generateCode(indentLevel + 1);
    out << right->generateCode(indentLevel + 1);
    
    freeRegister(left->place);
    freeRegister(right->place);
    
    string reg;
    reg = RegisterManager::getInstance().getTempRegister();
    
    out << indent(indentLevel) << "mul " << reg << ", " <<left->place << ", " << right->place << endl;
    this->place = reg;
    
    return out.str();
}
#line 1027 "decaf_tree.cpp"

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
#line 183 "decaf_semantic_tree.tc"
{
    ostringstream out;
    
    out << left->generateCode(indentLevel + 1);
    out << right->generateCode(indentLevel + 1);
    
    freeRegister(left->place);
    freeRegister(right->place);
    
    string reg;
    reg = RegisterManager::getInstance().getTempRegister();
    
    out << indent(indentLevel) << "div " << reg << ", " <<left->place << ", " << right->place << endl;
    this->place = reg;
    
    return out.str();
}
#line 1072 "decaf_tree.cpp"

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
#line 201 "decaf_semantic_tree.tc"
{
    ostringstream out;
    
    out << left->generateCode(indentLevel + 1);
    out << right->generateCode(indentLevel + 1);
    
    freeRegister(left->place);
    freeRegister(right->place);
    
    string reg;
    reg = RegisterManager::getInstance().getTempRegister();
    
    out << indent(indentLevel) << "rem " << reg << ", " <<left->place << ", " << right->place << endl;
    this->place = reg;
    
    return out.str();
}
#line 1117 "decaf_tree.cpp"

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
#line 219 "decaf_semantic_tree.tc"
{
    ostringstream out;
    
    out << left->generateCode(indentLevel + 1);
    out << right->generateCode(indentLevel + 1);
    
    freeRegister(left->place);
    freeRegister(right->place);
    
    string reg;
    reg = RegisterManager::getInstance().getTempRegister();
    
    out << indent(indentLevel) << "and " << reg << ", " <<left->place << ", " << right->place << endl;
    this->place = reg;
    
    return out.str();
}
#line 1162 "decaf_tree.cpp"

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
#line 237 "decaf_semantic_tree.tc"
{
    ostringstream out;
    
    out << left->generateCode(indentLevel + 1);
    out << right->generateCode(indentLevel + 1);
    
    freeRegister(left->place);
    freeRegister(right->place);
    
    string reg;
    reg = RegisterManager::getInstance().getTempRegister();
    
    out << indent(indentLevel) << "or " << reg << ", " <<left->place << ", " << right->place << endl;
    this->place = reg;
    
    return out.str();
}
#line 1207 "decaf_tree.cpp"

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
#line 255 "decaf_semantic_tree.tc"
{
    ostringstream out;
    
    out << left->generateCode(indentLevel + 1);
    out << right->generateCode(indentLevel + 1);
    
    freeRegister(left->place);
    freeRegister(right->place);
    
    string reg;
    reg = RegisterManager::getInstance().getTempRegister();
    
    out << indent(indentLevel) << "slt " << reg << ", " <<right->place << ", " << left->place << endl;
    this->place = reg;
    
    return out.str();
}
#line 1252 "decaf_tree.cpp"

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
#line 273 "decaf_semantic_tree.tc"
{
    ostringstream out;
    
    out << left->generateCode(indentLevel + 1);
    out << right->generateCode(indentLevel + 1);
    
    freeRegister(left->place);
    freeRegister(right->place);
    
    string reg;
    reg = RegisterManager::getInstance().getTempRegister();
    
    out << indent(indentLevel) << "slt " << reg << ", " <<left->place << ", " << right->place << endl;
    this->place = reg;
    
    return out.str();
}
#line 1297 "decaf_tree.cpp"

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
#line 291 "decaf_semantic_tree.tc"
{
    ostringstream out;
    
    out << left->generateCode(indentLevel + 1);
    out << right->generateCode(indentLevel + 1);
    
    freeRegister(left->place);
    freeRegister(right->place);
    
    string reg;
    reg = RegisterManager::getInstance().getTempRegister();
    
    out << indent(indentLevel) << "sle " << reg << ", " <<right->place << ", " << left->place << endl;
    this->place = reg;
    
    return out.str();
}
#line 1342 "decaf_tree.cpp"

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
#line 309 "decaf_semantic_tree.tc"
{
    ostringstream out;
    
    out << left->generateCode(indentLevel + 1);
    out << right->generateCode(indentLevel + 1);
    
    freeRegister(left->place);
    freeRegister(right->place);
    
    string reg;
    reg = RegisterManager::getInstance().getTempRegister();
    
    out << indent(indentLevel) << "sle " << reg << ", " <<left->place << ", " << right->place << endl;
    this->place = reg;
    
    return out.str();
}
#line 1387 "decaf_tree.cpp"

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
#line 327 "decaf_semantic_tree.tc"
{
    ostringstream out;
    
    out << left->generateCode(indentLevel + 1);
    out << right->generateCode(indentLevel + 1);
    
    freeRegister(left->place);
    freeRegister(right->place);
    
    string reg;
    reg = RegisterManager::getInstance().getTempRegister();
    
    out << indent(indentLevel) << "seq " << reg << ", " <<left->place << ", " << right->place << endl;
    this->place = reg;
    
    return out.str();
}
#line 1432 "decaf_tree.cpp"

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
#line 345 "decaf_semantic_tree.tc"
{
    ostringstream out;
    
    out << left->generateCode(indentLevel + 1);
    out << right->generateCode(indentLevel + 1);
    
    freeRegister(left->place);
    freeRegister(right->place);
    
    string reg;
    reg = RegisterManager::getInstance().getTempRegister();
    
    out << indent(indentLevel) << "sne " << reg << ", " <<left->place << ", " << right->place << endl;
    this->place = reg;
    
    return out.str();
}
#line 1477 "decaf_tree.cpp"

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
#line 363 "decaf_semantic_tree.tc"
{
    ostringstream out;
    
    out << left->generateCode(indentLevel + 1);
    out << right->generateCode(indentLevel + 1);
    
    freeRegister(left->place);
    freeRegister(right->place);
    
    string reg;
    reg = RegisterManager::getInstance().getTempRegister();
    
    out << indent(indentLevel) << "sarv " << reg << ", " <<left->place << ", " << right->place << endl;
    this->place = reg;
    
    return out.str();
}
#line 1522 "decaf_tree.cpp"

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
#line 381 "decaf_semantic_tree.tc"
{
    ostringstream out;
    
    out << left->generateCode(indentLevel + 1);
    out << right->generateCode(indentLevel + 1);
    
    freeRegister(left->place);
    freeRegister(right->place);
    
    string reg;
    reg = RegisterManager::getInstance().getTempRegister();
    
    string reg_neg;
    reg_neg = RegisterManager::getInstance().getTempRegister();
    
    out << indent(indentLevel) << "sub " << reg_neg << ", $zero, " << right->place << endl;
    out << indent(indentLevel) << "sarv " << reg << ", " <<left->place << ", " << reg_neg << endl;
    this->place = reg;
    
    return out.str();
}
#line 1571 "decaf_tree.cpp"

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
#line 403 "decaf_semantic_tree.tc"
{
    ostringstream out;
    
    out << left->generateCode(indentLevel + 1);
    out << right->generateCode(indentLevel + 1);
    
    freeRegister(left->place);
    freeRegister(right->place);
    
    string reg;
    reg = RegisterManager::getInstance().getTempRegister();
    
    out << indent(indentLevel) << "ror " << reg << ", " <<left->place << ", " << right->place << endl;
    this->place = reg;
    
    return out.str();
}
#line 1616 "decaf_tree.cpp"

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
#line 421 "decaf_semantic_tree.tc"
{
    ostringstream out;
    
    out << expression->generateCode(indentLevel + 1);
    
    freeRegister(expression->place);
    
    string reg;
    reg = RegisterManager::getInstance().getTempRegister();
    
    out << indent(indentLevel) << "seq " << reg << ", $zero, " << expression->place << endl;
    this->place = reg;
    
    return out.str();
}
#line 1659 "decaf_tree.cpp"

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
#line 437 "decaf_semantic_tree.tc"
{
    ostringstream out;
    
    out << expression->generateCode(indentLevel + 1);
    
    freeRegister(expression->place);
    
    string reg;
    reg = RegisterManager::getInstance().getTempRegister();
    
    out << indent(indentLevel) << "sub " << reg << ", $zero, " << expression->place << endl;
    this->place = reg;
    
    return out.str();
}
#line 1702 "decaf_tree.cpp"

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
#line 453 "decaf_semantic_tree.tc"
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
#line 1745 "decaf_tree.cpp"

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
#line 468 "decaf_semantic_tree.tc"
{
    ostringstream out;
    string reg;
    reg = RegisterManager::getInstance().getTempRegister();

    out << indent(indentLevel) << "li " << reg << ", " << value;
    this->place = reg;

    return out.str();
}
#line 1784 "decaf_tree.cpp"

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
#line 479 "decaf_semantic_tree.tc"
{
    
}
#line 1816 "decaf_tree.cpp"

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

DecoratedAssignmentStatement::DecoratedAssignmentStatement(DecoratedLValue * lvalue, DecoratedExpression * value)
	: DecoratedStatement()
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
#line 520 "decaf_semantic_tree.tc"
{
    ostringstream out;

    out << lvalue->getLocation(indentLevel + 1);
    out << value->generateCode(indentLevel + 1);
    out << indent(indentLevel) << "sw " << value->place << ", 0(" << lvalue->place << ")" << endl;

    return out.str();
}
#line 1855 "decaf_tree.cpp"

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

DecoratedMethodCallStatement::DecoratedMethodCallStatement(DecoratedExpressionList * arguments)
	: DecoratedStatement()
{
	this->kind__ = DecoratedMethodCallStatement_kind;
	this->method_index = 0;
	this->arguments = arguments;
}

DecoratedMethodCallStatement::~DecoratedMethodCallStatement()
{
	// not used
}

string DecoratedMethodCallStatement::generateCode(int indentLevel)
#line 530 "decaf_semantic_tree.tc"
{
    ostringstream out;

    return out.str();
}
#line 1890 "decaf_tree.cpp"

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

DecoratedIfStatement::DecoratedIfStatement(DecoratedExpression * condition, DecoratedStatement * true_part, DecoratedStatement * false_part)
	: DecoratedStatement()
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
#line 536 "decaf_semantic_tree.tc"
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

    return out.str();
}
#line 1938 "decaf_tree.cpp"

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

DecoratedWhileStatement::DecoratedWhileStatement(DecoratedExpression * condition, DecoratedStatement * loop_body)
	: DecoratedStatement()
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
#line 554 "decaf_semantic_tree.tc"
{
    ostringstream out;

    return out.str();
}
#line 1973 "decaf_tree.cpp"

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

DecoratedForStatement::DecoratedForStatement(DecoratedStatement * assignment_list1, DecoratedExpression * condition, DecoratedStatement * assignment_list2, DecoratedStatement * loop_body)
	: DecoratedStatement()
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
#line 560 "decaf_semantic_tree.tc"
{
    ostringstream out;

    return out.str();
}
#line 2010 "decaf_tree.cpp"

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

DecoratedReturnStatement::DecoratedReturnStatement(DecoratedExpression * expression)
	: DecoratedStatement()
{
	this->kind__ = DecoratedReturnStatement_kind;
	this->expression = expression;
}

DecoratedReturnStatement::~DecoratedReturnStatement()
{
	// not used
}

string DecoratedReturnStatement::generateCode(int indentLevel)
#line 566 "decaf_semantic_tree.tc"
{
    ostringstream out;
    if (expression != NULL) {
        out << expression->generateCode(indentLevel + 1);
    }
    return out.str();
}
#line 2046 "decaf_tree.cpp"

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

DecoratedBreakStatement::DecoratedBreakStatement()
	: DecoratedStatement()
{
	this->kind__ = DecoratedBreakStatement_kind;
}

DecoratedBreakStatement::~DecoratedBreakStatement()
{
	// not used
}

string DecoratedBreakStatement::generateCode(int indentLevel)
#line 574 "decaf_semantic_tree.tc"
{
    ostringstream out;

    return out.str();
}
#line 2079 "decaf_tree.cpp"

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

DecoratedContinueStatement::DecoratedContinueStatement()
	: DecoratedStatement()
{
	this->kind__ = DecoratedContinueStatement_kind;
}

DecoratedContinueStatement::~DecoratedContinueStatement()
{
	// not used
}

string DecoratedContinueStatement::generateCode(int indentLevel)
#line 580 "decaf_semantic_tree.tc"
{
    ostringstream out;

    return out.str();
}
#line 2112 "decaf_tree.cpp"

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

DecoratedBlockStatement::DecoratedBlockStatement(DecoratedStatementList * statement_list)
	: DecoratedStatement()
{
	this->kind__ = DecoratedBlockStatement_kind;
	this->statement_list = statement_list;
}

DecoratedBlockStatement::~DecoratedBlockStatement()
{
	// not used
}

string DecoratedBlockStatement::generateCode(int indentLevel)
#line 586 "decaf_semantic_tree.tc"
{
    ostringstream out;

    list<DecoratedStatement*>::iterator it = statement_list->begin();

    while (it != statement_list->end()) {
        out << (*it)->generateCode(indentLevel + 1);

        it++;
    }

    return out.str();
}
#line 2154 "decaf_tree.cpp"

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
#line 250 "decaf_tree.tc"
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
#line 2334 "decaf_tree.cpp"

DecoratedNode * ClassDef::validateSemantics()
#line 453 "decaf_tree.tc"
{
    list<VariableDef*>::iterator variable_iterator = field_def_list->begin();
    
    while(variable_iterator != field_def_list->end()) {
        VariableDef * field_def = *variable_iterator;
        field_def->registerDefinition();
        variable_iterator++;
    }
    
    list<MethodDef*>::iterator method_iterator = method_def_list->begin();
    
    while(method_iterator != method_def_list->end()) {
        MethodDef * method_def = *method_iterator;
        method_def->registerDefinition();
        method_iterator++;
    }
    
    /************ Check method bodies. ************/
    method_iterator = method_def_list->begin();
    DecoratedBlockStatement *main_block = NULL;
    while(method_iterator != method_def_list->end()) {
        MethodDef * method_def = *method_iterator;
        if (method_def->method_name == "main") {
        	main_block = method_def->checkBody();
        } else {
        	method_def->checkBody();
        }
        method_iterator++;
    }

    DecoratedClass *decorated_class = new DecoratedClass(this->name);
    decorated_class->main = main_block;
    
    return decorated_class;
}
#line 2373 "decaf_tree.cpp"

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
#line 267 "decaf_tree.tc"
{
	ostringstream out;

	out << "//Linea: " << line << ": Columna: " << column << endl;
	out << TypeToString(variable_type) << " " << variable_name;

	if (is_array_def)
		out << "[" << array_dimension << "]";

	if (initial_value != 0)
		out << " = " + initial_value->toString();

	return out.str();
}
#line 2421 "decaf_tree.cpp"

DecoratedNode * VariableDef::validateSemantics()
#line 794 "decaf_tree.tc"
{
    /* DO NOTHING */
    return NULL;
}
#line 2429 "decaf_tree.cpp"

void VariableDef::registerDefinition()
#line 817 "decaf_tree.tc"
{

}
#line 2436 "decaf_tree.cpp"

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
#line 282 "decaf_tree.tc"
{
	return TypeToString(parameter_type) + " " + parameter_name;
}
#line 2469 "decaf_tree.cpp"

DecoratedNode * ParameterDef::validateSemantics()
#line 799 "decaf_tree.tc"
{
    /* DO NOTHING */
    return NULL;
}
#line 2477 "decaf_tree.cpp"

void ParameterDef::registerDefinition()
#line 821 "decaf_tree.tc"
{

}
#line 2484 "decaf_tree.cpp"

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

MethodDef::MethodDef(string method_name)
	: Definition()
{
	this->kind__ = MethodDef_kind;
	this->method_name = method_name;
}

MethodDef::~MethodDef()
{
	// not used
}

string MethodDef::toString()
#line 286 "decaf_tree.tc"
{
	ostringstream out;

	out << TypeToString(method_return_type) << " " << method_name << "(";
	if (method_parameters != 0)
		out << ListToString(method_parameters, ", ", false);
	out << ")" << endl;
	out << method_body->toString() << endl;

	return out.str();
}
#line 2524 "decaf_tree.cpp"

DecoratedNode * MethodDef::validateSemantics()
#line 804 "decaf_tree.tc"
{
    /* DO NOTHING */
    return NULL;
}
#line 2532 "decaf_tree.cpp"

void MethodDef::registerDefinition()
#line 813 "decaf_tree.tc"
{

}
#line 2539 "decaf_tree.cpp"

DecoratedBlockStatement * MethodDef::checkBody()
#line 828 "decaf_tree.tc"
{
    return (DecoratedBlockStatement*)method_body->validateSemantics();
}
#line 2546 "decaf_tree.cpp"

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
#line 298 "decaf_tree.tc"
{
    ostringstream out;
    
    out << left->toString() << OperatorToString(expression_operator) << right->toString();
    
    return out.str();
}
#line 2584 "decaf_tree.cpp"

DecoratedNode * BinaryExpression::validateSemantics()
#line 489 "decaf_tree.tc"
{
    cout << "validating binary expression semantics" << endl;
    
    DecoratedExpression *dLeft = (DecoratedExpression*)(left->validateSemantics());
    DecoratedExpression *dRight = (DecoratedExpression*)(right->validateSemantics());
    
    if (dLeft == NULL || dRight == NULL)
        return NULL;
    
    if (!dLeft->type->isEquivalent(dRight->type)) {
        ErrorHandler::getInstance().handleError("type mismatch for operator " + 
                                                OperatorToString(expression_operator) +
                                                " for types " + dLeft->type->stringValue() +
                                                " and " + dRight->type->stringValue());
        cout << dLeft->type->stringValue() << " not equivalent to" << dRight->type->stringValue() << endl;
        return NULL;
    }
    cout << "before testing string type" << endl;
    if (dynamic_cast<StringType*>(dLeft->type) != NULL) {
        ErrorHandler::getInstance().handleError("type mismatch for operator " + 
                                                OperatorToString(expression_operator) +
                                                " for types " + dLeft->type->stringValue() +
                                                " and " + dRight->type->stringValue());
        return NULL;
    }
    
    ExpressionType      *type;
    
    cout << "operator " << OperatorToString(expression_operator) << endl;
    
    if (dynamic_cast<FloatType*>(dLeft->type) != NULL
        || dynamic_cast<FloatType*>(dRight->type) != NULL) {
        
        type = new FloatType();
        cout << "left side is float " << endl;
    }
    if (dynamic_cast<BooleanType*>(dLeft->type) != NULL) {
        type = new BooleanType();
        
        cout << "left side is boolean " << endl;
    }
    if (dynamic_cast<IntegerType*>(dLeft->type) != NULL) {
        type = new IntegerType();
        
        cout << "left side is integer " << endl;
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
            if (type->isBoolean())
                return new DecoratedGTExpression(type, dLeft, dRight);
            else
                return NULL;
        case OpLT:
            if (type->isBoolean())
                return new DecoratedLTExpression(type, dLeft, dRight);
            else
                return NULL;
        case OpGTE:
            if (type->isBoolean())
                return new DecoratedGTEExpression(type, dLeft, dRight);
            else
                return NULL;
        case OpLTE:
            if (type->isBoolean())
                return new DecoratedLTEExpression(type, dLeft, dRight);
            else
                return NULL;
        case OpEq:
            if (type->isBoolean())
                return new DecoratedEqExpression(type, dLeft, dRight);
            else
                return NULL;
        case OpNotEq:
            if (type->isBoolean())
                return new DecoratedNotEqExpression(type, dLeft, dRight);
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
#line 2721 "decaf_tree.cpp"

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
#line 306 "decaf_tree.tc"
{
    ostringstream out;
    
    out << OperatorToString(expression_operator) << expression->toString();
    
    return out.str();
}
#line 2758 "decaf_tree.cpp"

DecoratedNode * UnaryExpression::validateSemantics()
#line 623 "decaf_tree.tc"
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
#line 2785 "decaf_tree.cpp"

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
#line 314 "decaf_tree.tc"
{
	ostringstream out;

	out << this->variable_name;

	if (array_index != 0)
		out << "[" << array_index->toString() << "]";

	return out.str();
}
#line 2825 "decaf_tree.cpp"

DecoratedNode * LValueExpression::validateSemantics()
#line 647 "decaf_tree.tc"
{
    cout << "validating lvalue semantics " << endl;
    DecoratedExpression *d_array_index = NULL;
    if (array_index != NULL)
        d_array_index = (DecoratedExpression*)array_index->validateSemantics();
    return new DecoratedLValue(new IntegerType(), variable_name, d_array_index);
}
#line 2836 "decaf_tree.cpp"

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
#line 325 "decaf_tree.tc"
{
	ostringstream out;

	out << this->method_name << "(" << ListToString(method_arguments, ", ", false) << ")";

	return out.str();
}
#line 2873 "decaf_tree.cpp"

DecoratedNode * MethodCallExpression::validateSemantics()
#line 655 "decaf_tree.tc"
{
    cout << "validating method call expression " << endl;
    list<Expression*>::iterator expression_iterator = method_arguments->begin();
    
    cout << "parameters: " << endl;
    DecoratedExpressionList *d_arguments = new DecoratedExpressionList;

    while (expression_iterator != method_arguments->end()) {
        Expression *expression = *expression_iterator;
        DecoratedExpression *d_expr = (DecoratedExpression*)expression->validateSemantics();
        d_arguments->push_back(d_expr);
        
        expression_iterator++;
    }

    return new DecoratedMethodCallExpression(new IntegerType(), method_name, d_arguments);
}
#line 2894 "decaf_tree.cpp"

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
#line 333 "decaf_tree.tc"
{
	ostringstream out;

	out << int_value ;
	return out.str();
}
#line 2930 "decaf_tree.cpp"

DecoratedNode * IntConstantExpression::validateSemantics()
#line 673 "decaf_tree.tc"
{
    cout << "validating int constant semantics " << endl;
    return new DecoratedIntConstant(new IntegerType(), int_value);
}
#line 2938 "decaf_tree.cpp"

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
#line 340 "decaf_tree.tc"
{
	ostringstream out;

	out << float_value;
	return out.str();
}
#line 2974 "decaf_tree.cpp"

DecoratedNode * RealConstantExpression::validateSemantics()
#line 678 "decaf_tree.tc"
{
    cout << "validating real constant semantics " << endl;
    /*TODO: instancia el nuevo nodo decorado*/
}
#line 2982 "decaf_tree.cpp"

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
#line 347 "decaf_tree.tc"
{
	ostringstream out;

	out << bool_value;
	return out.str();
}
#line 3018 "decaf_tree.cpp"

DecoratedNode * BooleanConstantExpression::validateSemantics()
#line 683 "decaf_tree.tc"
{
    cout << "validating boolean constant semantics " << endl;
    return new DecoratedBooleanConstant(new BooleanType(), bool_value);
}
#line 3026 "decaf_tree.cpp"

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
#line 354 "decaf_tree.tc"
{
	ostringstream out;

	out << string_value;
	return out.str();
}
#line 3062 "decaf_tree.cpp"

DecoratedNode * StringConstantExpression::validateSemantics()
#line 688 "decaf_tree.tc"
{
    cout << "validating string constant semantics " << endl;
    /*TODO: instancia el nuevo nodo decorado*/
}
#line 3070 "decaf_tree.cpp"

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
#line 362 "decaf_tree.tc"
{
	ostringstream out;

	out << "// Linea " << line << " Columna " << column << "\n"; 
	out << lvalue->toString() << " = " << expr->toString() << ";";

	return out.str();
}
#line 3108 "decaf_tree.cpp"

DecoratedNode * AssignmentStatement::validateSemantics()
#line 695 "decaf_tree.tc"
{
    cout << "validating assignment statement semantics" << endl;
    DecoratedLValue *d_lvalue = (DecoratedLValue*)lvalue->validateSemantics();
    cout << "after lvalue semantics" << endl;
    DecoratedExpression *d_expr = (DecoratedExpression*)expr->validateSemantics();

    return new DecoratedAssignmentStatement(d_lvalue, d_expr);
}
#line 3120 "decaf_tree.cpp"

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
#line 371 "decaf_tree.tc"
{
	return this->name + "(" + ListToString(arguments, ", ", false) + ");";
}
#line 3153 "decaf_tree.cpp"

DecoratedNode * MethodCallStatement::validateSemantics()
#line 704 "decaf_tree.tc"
{
    list<Expression*>::iterator expression_iterator = arguments->begin();
    
    DecoratedExpressionList *d_arguments = new DecoratedExpressionList;
    while (expression_iterator != arguments->end()) {
        Expression *expression = *expression_iterator;
        DecoratedExpression *d_expr = (DecoratedExpression*)expression->validateSemantics();

        d_arguments->push_back(d_expr);
        
        expression_iterator++;
    }

    return new DecoratedMethodCallStatement(d_arguments);
}
#line 3172 "decaf_tree.cpp"

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
#line 375 "decaf_tree.tc"
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
#line 3216 "decaf_tree.cpp"

DecoratedNode * IfStatement::validateSemantics()
#line 720 "decaf_tree.tc"
{
    cout << "validating if statement semantics " << endl;
    condition->validateSemantics();
    
    cout << "validateSemantics if true part " << endl;
    true_part->validateSemantics();
    
    if (false_part != NULL)
        false_part->validateSemantics();
}
#line 3230 "decaf_tree.cpp"

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
#line 389 "decaf_tree.tc"
{
	ostringstream out;

	out << "while (" << condition->toString() << ")" << endl;
	out << "{" << loop_body->toString() << endl << "}";

	return out.str();
}
#line 3268 "decaf_tree.cpp"

DecoratedNode * WhileStatement::validateSemantics()
#line 731 "decaf_tree.tc"
{
    condition->validateSemantics();
    loop_body->validateSemantics();
}
#line 3276 "decaf_tree.cpp"

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
#line 398 "decaf_tree.tc"
{
	ostringstream out;

	out << "for (" << assignment_list1->toString();
	out << ";" << condition->toString();
	out << ";" << assignment_list2->toString();
	out << "{" << endl << loop_body->toString() << endl << "}";

	return out.str();
}
#line 3318 "decaf_tree.cpp"

DecoratedNode * ForStatement::validateSemantics()
#line 736 "decaf_tree.tc"
{
    DecoratedStatement *d_assignment_list1 = (DecoratedStatement*)assignment_list1->validateSemantics();
    condition->validateSemantics();
    assignment_list2->validateSemantics();
    loop_body->validateSemantics();
}
#line 3328 "decaf_tree.cpp"

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
#line 409 "decaf_tree.tc"
{
	ostringstream out;
	
	out << "return ";
	if (expr != NULL) {
		out << expr->toString();
	}
	out << ";";
	
	return out.str();
}
#line 3368 "decaf_tree.cpp"

DecoratedNode * ReturnStatement::validateSemantics()
#line 743 "decaf_tree.tc"
{
    cout << "validating return statement semantics " << endl;
    DecoratedExpression *decorated_expression = NULL;
    if (expr != NULL) {
        decorated_expression = (DecoratedExpression*)expr->validateSemantics();
    }
    return new DecoratedReturnStatement(decorated_expression);
}
#line 3380 "decaf_tree.cpp"

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
#line 421 "decaf_tree.tc"
{
	return "break;";
}
#line 3411 "decaf_tree.cpp"

DecoratedNode * BreakStatement::validateSemantics()
#line 752 "decaf_tree.tc"
{
    /*TODO: instancia el nuevo nodo decorado*/
    return new DecoratedBreakStatement();
}
#line 3419 "decaf_tree.cpp"

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
#line 425 "decaf_tree.tc"
{
	return "continue;";
}
#line 3450 "decaf_tree.cpp"

DecoratedNode * ContinueStatement::validateSemantics()
#line 757 "decaf_tree.tc"
{
    /*TODO: instancia el nuevo nodo decorado*/
    return new DecoratedContinueStatement();
}
#line 3458 "decaf_tree.cpp"

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
#line 429 "decaf_tree.tc"
{
	ostringstream out;

	out << "{" << endl;

	if (statement_list != 0)
		out << ListToString(statement_list, "\n", true);

	out << "}";

	return out.str();
}
#line 3499 "decaf_tree.cpp"

DecoratedNode * BlockStatement::validateSemantics()
#line 762 "decaf_tree.tc"
{
    list<Statement*>::iterator statement_iterator = statement_list->begin();
    
    DecoratedStatementList  *decorated_statement_list = new DecoratedStatementList;
    
    while (statement_iterator != statement_list->end()) {
        Statement *statement = *statement_iterator;
        DecoratedStatement *decorated_statement =  (DecoratedStatement*)statement->validateSemantics();
        decorated_statement_list->push_back(decorated_statement);
        
        statement_iterator++;
    }
    
    return new DecoratedBlockStatement(decorated_statement_list);
}
#line 3518 "decaf_tree.cpp"

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
#line 442 "decaf_tree.tc"
{
	return  "print (" + ListToString(arguments, ", ", false) + ");";
}
#line 3550 "decaf_tree.cpp"

DecoratedNode * PrintStatement::validateSemantics()
#line 778 "decaf_tree.tc"
{
	list<Expression*>::iterator expression_iterator = arguments->begin();
    
    DecoratedExpressionList *d_arguments = new DecoratedExpressionList;
    while (expression_iterator != arguments->end()) {
        Expression *expression = *expression_iterator;
        DecoratedExpression *d_expr = (DecoratedExpression*)expression->validateSemantics();

        d_arguments->push_back(d_expr);
        
        expression_iterator++;
    }

    return new DecoratedMethodCallStatement(d_arguments);
}
#line 3569 "decaf_tree.cpp"

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

#line 116 "decaf_tree.tc"

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
#line 234 "decaf_tree.tc"

void setStatementList(BlockStatement *block, StatementList *stList) {
	block->statement_list = stList;
}

void addStatement(BlockStatement *block, Statement *statement) {
	if (block->statement_list == 0)
		block->statement_list = new StatementList;

	block->statement_list->push_back(statement);
}
#line 3609 "decaf_tree.cpp"
