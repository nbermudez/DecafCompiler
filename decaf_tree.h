/* decaf_tree.h.  Generated automatically by treecc */
#ifndef __yy_decaf_tree_h
#define __yy_decaf_tree_h
#line 1 "decaf_tree.tc"

#include <string>
#include <list>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <cstddef>

#include "Value.h"
#include "Util.h"
#include "error_handler.h"
#include "register_manager.h"
using namespace std;

class Statement;
typedef list<Statement *> StatementList;

class Expression;
typedef list<Expression *> ExpressionList;

class VariableDef;
typedef list<VariableDef *> VariableDefList;

class ParameterDef;
typedef list<ParameterDef *> ParameterDefList;

class MethodDef;
typedef list<MethodDef *> MethodDefList;

class BlockStatement;
void setStatementList(BlockStatement *block, StatementList *stList);
void addStatement(BlockStatement *block, Statement *statement);

typedef enum {
	OpAdd,
	OpSub,
	OpMul,
	OpDiv,
	OpMod,
	OpAnd,
	OpOr,
	OpNot,
	OpGT,
	OpLT,
	OpGTE,
	OpLTE,
	OpEq,
	OpNotEq,
	OpRShift,
	OpLShift,
	OpRot
} ExpressionOperator;

typedef union {
	int int_value;
	bool bool_value;
	char *string_value;
} union_constants;


/*** Typedefs for Decorated Nodes ***/
class DecoratedExpression;
typedef list<DecoratedExpression *> DecoratedExpressionList;

class DecoratedStatement;
typedef list<DecoratedStatement *> DecoratedStatementList;
#line 72 "decaf_tree.h"

#include <new>

const int ExpressionType_kind = 28;
const int FloatType_kind = 29;
const int StringType_kind = 30;
const int IntegerType_kind = 31;
const int BooleanType_kind = 32;
const int DecoratedNode_kind = 33;
const int DecoratedClass_kind = 34;
const int DecoratedExpression_kind = 35;
const int DecoratedStatement_kind = 62;
const int DecoratedBinaryExpression_kind = 36;
const int DecoratedUnaryExpression_kind = 53;
const int DecoratedConstant_kind = 56;
const int DecoratedLValue_kind = 60;
const int DecoratedMethodCallExpression_kind = 61;
const int DecoratedAddExpression_kind = 37;
const int DecoratedSubExpression_kind = 38;
const int DecoratedMultExpression_kind = 39;
const int DecoratedDivExpression_kind = 40;
const int DecoratedModExpression_kind = 41;
const int DecoratedAndExpression_kind = 42;
const int DecoratedOrExpression_kind = 43;
const int DecoratedGTExpression_kind = 44;
const int DecoratedLTExpression_kind = 45;
const int DecoratedGTEExpression_kind = 46;
const int DecoratedLTEExpression_kind = 47;
const int DecoratedEqExpression_kind = 48;
const int DecoratedNotEqExpression_kind = 49;
const int DecoratedRShiftExpression_kind = 50;
const int DecoratedLShiftExpression_kind = 51;
const int DecoratedRotExpression_kind = 52;
const int DecoratedNotExpression_kind = 54;
const int DecoratedNegExpression_kind = 55;
const int DecoratedBooleanConstant_kind = 57;
const int DecoratedIntConstant_kind = 58;
const int DecoratedStringConstant_kind = 59;
const int DecoratedAssignmentStatement_kind = 63;
const int DecoratedMethodCallStatement_kind = 64;
const int DecoratedIfStatement_kind = 65;
const int DecoratedWhileStatement_kind = 66;
const int DecoratedForStatement_kind = 67;
const int DecoratedReturnStatement_kind = 68;
const int DecoratedBreakStatement_kind = 69;
const int DecoratedContinueStatement_kind = 70;
const int DecoratedBlockStatement_kind = 71;
const int DNode_kind = 1;
const int MainNode_kind = 2;
const int Definition_kind = 4;
const int Expression_kind = 8;
const int Statement_kind = 17;
const int ClassDef_kind = 3;
const int VariableDef_kind = 5;
const int ParameterDef_kind = 6;
const int MethodDef_kind = 7;
const int BinaryExpression_kind = 9;
const int UnaryExpression_kind = 10;
const int LValueExpression_kind = 11;
const int MethodCallExpression_kind = 12;
const int IntConstantExpression_kind = 13;
const int RealConstantExpression_kind = 14;
const int BooleanConstantExpression_kind = 15;
const int StringConstantExpression_kind = 16;
const int AssignmentStatement_kind = 18;
const int MethodCallStatement_kind = 19;
const int IfStatement_kind = 20;
const int WhileStatement_kind = 21;
const int ForStatement_kind = 22;
const int ReturnStatement_kind = 23;
const int BreakStatement_kind = 24;
const int ContinueStatement_kind = 25;
const int BlockStatement_kind = 26;
const int PrintStatement_kind = 27;

class ExpressionType;
class FloatType;
class StringType;
class IntegerType;
class BooleanType;
class DecoratedNode;
class DecoratedClass;
class DecoratedExpression;
class DecoratedStatement;
class DecoratedBinaryExpression;
class DecoratedUnaryExpression;
class DecoratedConstant;
class DecoratedLValue;
class DecoratedMethodCallExpression;
class DecoratedAddExpression;
class DecoratedSubExpression;
class DecoratedMultExpression;
class DecoratedDivExpression;
class DecoratedModExpression;
class DecoratedAndExpression;
class DecoratedOrExpression;
class DecoratedGTExpression;
class DecoratedLTExpression;
class DecoratedGTEExpression;
class DecoratedLTEExpression;
class DecoratedEqExpression;
class DecoratedNotEqExpression;
class DecoratedRShiftExpression;
class DecoratedLShiftExpression;
class DecoratedRotExpression;
class DecoratedNotExpression;
class DecoratedNegExpression;
class DecoratedBooleanConstant;
class DecoratedIntConstant;
class DecoratedStringConstant;
class DecoratedAssignmentStatement;
class DecoratedMethodCallStatement;
class DecoratedIfStatement;
class DecoratedWhileStatement;
class DecoratedForStatement;
class DecoratedReturnStatement;
class DecoratedBreakStatement;
class DecoratedContinueStatement;
class DecoratedBlockStatement;
class DNode;
class MainNode;
class Definition;
class Expression;
class Statement;
class ClassDef;
class VariableDef;
class ParameterDef;
class MethodDef;
class BinaryExpression;
class UnaryExpression;
class LValueExpression;
class MethodCallExpression;
class IntConstantExpression;
class RealConstantExpression;
class BooleanConstantExpression;
class StringConstantExpression;
class AssignmentStatement;
class MethodCallStatement;
class IfStatement;
class WhileStatement;
class ForStatement;
class ReturnStatement;
class BreakStatement;
class ContinueStatement;
class BlockStatement;
class PrintStatement;

class YYNODESTATE
{
public:

	YYNODESTATE();
	virtual ~YYNODESTATE();

#line 1 "cpp_skel.h"
private:

	struct YYNODESTATE_block *blocks__;
	struct YYNODESTATE_push *push_stack__;
	int used__;
#line 233 "decaf_tree.h"
private:

	static YYNODESTATE *state__;

public:

	static YYNODESTATE *getState()
		{
			if(state__) return state__;
			state__ = new YYNODESTATE();
			return state__;
		}

public:

	void *alloc(size_t);
	void dealloc(void *, size_t);
	int push();
	void pop();
	void clear();
	virtual void failed();
	virtual char *currFilename();
	virtual long currLinenum();

};

class ExpressionType
{
protected:

	int kind__;
	char *filename__;
	long linenum__;

public:

	int getKind() const { return kind__; }
	const char *getFilename() const { return filename__; }
	long getLinenum() const { return linenum__; }
	void setFilename(char *filename) { filename__ = filename; }
	void setLinenum(long linenum) { linenum__ = linenum; }

	void *operator new(size_t);
	void operator delete(void *, size_t);

protected:

	ExpressionType();

public:

	virtual bool isEquivalent(ExpressionType * secondType) = 0;
	virtual bool isNumeric() = 0;
	virtual bool isBoolean() = 0;
	virtual string stringValue() = 0;

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ExpressionType();

};

class FloatType : public ExpressionType
{
public:

	FloatType();

public:

	virtual bool isEquivalent(ExpressionType * secondType);
	virtual bool isNumeric();
	virtual bool isBoolean();
	virtual string stringValue();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~FloatType();

};

class StringType : public ExpressionType
{
public:

	StringType();

public:

	virtual bool isEquivalent(ExpressionType * secondType);
	virtual bool isNumeric();
	virtual bool isBoolean();
	virtual string stringValue();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~StringType();

};

class IntegerType : public ExpressionType
{
public:

	IntegerType();

public:

	virtual bool isEquivalent(ExpressionType * secondType);
	virtual bool isNumeric();
	virtual bool isBoolean();
	virtual string stringValue();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~IntegerType();

};

class BooleanType : public ExpressionType
{
public:

	BooleanType();

public:

	virtual bool isEquivalent(ExpressionType * secondType);
	virtual bool isNumeric();
	virtual bool isBoolean();
	virtual string stringValue();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~BooleanType();

};

class DecoratedNode
{
protected:

	int kind__;
	char *filename__;
	long linenum__;

public:

	int getKind() const { return kind__; }
	const char *getFilename() const { return filename__; }
	long getLinenum() const { return linenum__; }
	void setFilename(char *filename) { filename__ = filename; }
	void setLinenum(long linenum) { linenum__ = linenum; }

	void *operator new(size_t);
	void operator delete(void *, size_t);

protected:

	DecoratedNode();

public:

	virtual string generateCode(int indentLevel) = 0;

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~DecoratedNode();

};

class DecoratedClass : public DecoratedNode
{
public:

	DecoratedClass(string name);

public:

	string name;
	DecoratedBlockStatement * main;

	virtual string generateCode(int indentLevel);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~DecoratedClass();

};

class DecoratedExpression : public DecoratedNode
{
protected:

	DecoratedExpression(ExpressionType * type);

public:

	ExpressionType * type;
	string place;

	virtual string generateCode(int indentLevel) = 0;

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~DecoratedExpression();

};

class DecoratedStatement : public DecoratedNode
{
protected:

	DecoratedStatement();

public:

	virtual string generateCode(int indentLevel) = 0;

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~DecoratedStatement();

};

class DecoratedBinaryExpression : public DecoratedExpression
{
protected:

	DecoratedBinaryExpression(ExpressionType * type, DecoratedExpression * left, DecoratedExpression * right);

public:

	DecoratedExpression * left;
	DecoratedExpression * right;

	virtual string generateCode(int indentLevel) = 0;

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~DecoratedBinaryExpression();

};

class DecoratedUnaryExpression : public DecoratedExpression
{
protected:

	DecoratedUnaryExpression(ExpressionType * type, DecoratedExpression * expression);

public:

	DecoratedExpression * expression;

	virtual string generateCode(int indentLevel) = 0;

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~DecoratedUnaryExpression();

};

class DecoratedConstant : public DecoratedExpression
{
protected:

	DecoratedConstant(ExpressionType * type);

public:

	virtual string generateCode(int indentLevel) = 0;

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~DecoratedConstant();

};

class DecoratedLValue : public DecoratedExpression
{
public:

	DecoratedLValue(ExpressionType * type, string variable_name, DecoratedExpression * array_index);

public:

	string variable_name;
	DecoratedExpression * array_index;

	virtual string generateCode(int indentLevel);
	virtual string getLocation(int indentLevel);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~DecoratedLValue();

};

class DecoratedMethodCallExpression : public DecoratedExpression
{
public:

	DecoratedMethodCallExpression(ExpressionType * type, string name, DecoratedExpressionList * arguments);

public:

	string name;
	DecoratedExpressionList * arguments;

	virtual string generateCode(int indentLevel);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~DecoratedMethodCallExpression();

};

class DecoratedAddExpression : public DecoratedBinaryExpression
{
public:

	DecoratedAddExpression(ExpressionType * type, DecoratedExpression * left, DecoratedExpression * right);

public:

	virtual string generateCode(int indentLevel);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~DecoratedAddExpression();

};

class DecoratedSubExpression : public DecoratedBinaryExpression
{
public:

	DecoratedSubExpression(ExpressionType * type, DecoratedExpression * left, DecoratedExpression * right);

public:

	virtual string generateCode(int indentLevel);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~DecoratedSubExpression();

};

class DecoratedMultExpression : public DecoratedBinaryExpression
{
public:

	DecoratedMultExpression(ExpressionType * type, DecoratedExpression * left, DecoratedExpression * right);

public:

	virtual string generateCode(int indentLevel);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~DecoratedMultExpression();

};

class DecoratedDivExpression : public DecoratedBinaryExpression
{
public:

	DecoratedDivExpression(ExpressionType * type, DecoratedExpression * left, DecoratedExpression * right);

public:

	virtual string generateCode(int indentLevel);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~DecoratedDivExpression();

};

class DecoratedModExpression : public DecoratedBinaryExpression
{
public:

	DecoratedModExpression(ExpressionType * type, DecoratedExpression * left, DecoratedExpression * right);

public:

	virtual string generateCode(int indentLevel);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~DecoratedModExpression();

};

class DecoratedAndExpression : public DecoratedBinaryExpression
{
public:

	DecoratedAndExpression(ExpressionType * type, DecoratedExpression * left, DecoratedExpression * right);

public:

	virtual string generateCode(int indentLevel);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~DecoratedAndExpression();

};

class DecoratedOrExpression : public DecoratedBinaryExpression
{
public:

	DecoratedOrExpression(ExpressionType * type, DecoratedExpression * left, DecoratedExpression * right);

public:

	virtual string generateCode(int indentLevel);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~DecoratedOrExpression();

};

class DecoratedGTExpression : public DecoratedBinaryExpression
{
public:

	DecoratedGTExpression(ExpressionType * type, DecoratedExpression * left, DecoratedExpression * right);

public:

	virtual string generateCode(int indentLevel);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~DecoratedGTExpression();

};

class DecoratedLTExpression : public DecoratedBinaryExpression
{
public:

	DecoratedLTExpression(ExpressionType * type, DecoratedExpression * left, DecoratedExpression * right);

public:

	virtual string generateCode(int indentLevel);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~DecoratedLTExpression();

};

class DecoratedGTEExpression : public DecoratedBinaryExpression
{
public:

	DecoratedGTEExpression(ExpressionType * type, DecoratedExpression * left, DecoratedExpression * right);

public:

	virtual string generateCode(int indentLevel);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~DecoratedGTEExpression();

};

class DecoratedLTEExpression : public DecoratedBinaryExpression
{
public:

	DecoratedLTEExpression(ExpressionType * type, DecoratedExpression * left, DecoratedExpression * right);

public:

	virtual string generateCode(int indentLevel);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~DecoratedLTEExpression();

};

class DecoratedEqExpression : public DecoratedBinaryExpression
{
public:

	DecoratedEqExpression(ExpressionType * type, DecoratedExpression * left, DecoratedExpression * right);

public:

	virtual string generateCode(int indentLevel);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~DecoratedEqExpression();

};

class DecoratedNotEqExpression : public DecoratedBinaryExpression
{
public:

	DecoratedNotEqExpression(ExpressionType * type, DecoratedExpression * left, DecoratedExpression * right);

public:

	virtual string generateCode(int indentLevel);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~DecoratedNotEqExpression();

};

class DecoratedRShiftExpression : public DecoratedBinaryExpression
{
public:

	DecoratedRShiftExpression(ExpressionType * type, DecoratedExpression * left, DecoratedExpression * right);

public:

	virtual string generateCode(int indentLevel);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~DecoratedRShiftExpression();

};

class DecoratedLShiftExpression : public DecoratedBinaryExpression
{
public:

	DecoratedLShiftExpression(ExpressionType * type, DecoratedExpression * left, DecoratedExpression * right);

public:

	virtual string generateCode(int indentLevel);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~DecoratedLShiftExpression();

};

class DecoratedRotExpression : public DecoratedBinaryExpression
{
public:

	DecoratedRotExpression(ExpressionType * type, DecoratedExpression * left, DecoratedExpression * right);

public:

	virtual string generateCode(int indentLevel);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~DecoratedRotExpression();

};

class DecoratedNotExpression : public DecoratedUnaryExpression
{
public:

	DecoratedNotExpression(ExpressionType * type, DecoratedExpression * expression);

public:

	virtual string generateCode(int indentLevel);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~DecoratedNotExpression();

};

class DecoratedNegExpression : public DecoratedUnaryExpression
{
public:

	DecoratedNegExpression(ExpressionType * type, DecoratedExpression * expression);

public:

	virtual string generateCode(int indentLevel);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~DecoratedNegExpression();

};

class DecoratedBooleanConstant : public DecoratedConstant
{
public:

	DecoratedBooleanConstant(ExpressionType * type, bool value);

public:

	bool value;

	virtual string generateCode(int indentLevel);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~DecoratedBooleanConstant();

};

class DecoratedIntConstant : public DecoratedConstant
{
public:

	DecoratedIntConstant(ExpressionType * type, int value);

public:

	int value;

	virtual string generateCode(int indentLevel);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~DecoratedIntConstant();

};

class DecoratedStringConstant : public DecoratedConstant
{
public:

	DecoratedStringConstant(ExpressionType * type, string value);

public:

	string value;

	virtual string generateCode(int indentLevel);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~DecoratedStringConstant();

};

class DecoratedAssignmentStatement : public DecoratedStatement
{
public:

	DecoratedAssignmentStatement(DecoratedLValue * lvalue, DecoratedExpression * value);

public:

	DecoratedLValue * lvalue;
	DecoratedExpression * value;

	virtual string generateCode(int indentLevel);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~DecoratedAssignmentStatement();

};

class DecoratedMethodCallStatement : public DecoratedStatement
{
public:

	DecoratedMethodCallStatement(DecoratedExpressionList * arguments);

public:

	int method_index;
	DecoratedExpressionList * arguments;

	virtual string generateCode(int indentLevel);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~DecoratedMethodCallStatement();

};

class DecoratedIfStatement : public DecoratedStatement
{
public:

	DecoratedIfStatement(DecoratedExpression * condition, DecoratedStatement * true_part, DecoratedStatement * false_part);

public:

	DecoratedExpression * condition;
	DecoratedStatement * true_part;
	DecoratedStatement * false_part;

	virtual string generateCode(int indentLevel);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~DecoratedIfStatement();

};

class DecoratedWhileStatement : public DecoratedStatement
{
public:

	DecoratedWhileStatement(DecoratedExpression * condition, DecoratedStatement * loop_body);

public:

	DecoratedExpression * condition;
	DecoratedStatement * loop_body;

	virtual string generateCode(int indentLevel);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~DecoratedWhileStatement();

};

class DecoratedForStatement : public DecoratedStatement
{
public:

	DecoratedForStatement(DecoratedStatement * assignment_list1, DecoratedExpression * condition, DecoratedStatement * assignment_list2, DecoratedStatement * loop_body);

public:

	DecoratedStatement * assignment_list1;
	DecoratedExpression * condition;
	DecoratedStatement * assignment_list2;
	DecoratedStatement * loop_body;

	virtual string generateCode(int indentLevel);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~DecoratedForStatement();

};

class DecoratedReturnStatement : public DecoratedStatement
{
public:

	DecoratedReturnStatement(DecoratedExpression * expression);

public:

	DecoratedExpression * expression;

	virtual string generateCode(int indentLevel);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~DecoratedReturnStatement();

};

class DecoratedBreakStatement : public DecoratedStatement
{
public:

	DecoratedBreakStatement();

public:

	virtual string generateCode(int indentLevel);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~DecoratedBreakStatement();

};

class DecoratedContinueStatement : public DecoratedStatement
{
public:

	DecoratedContinueStatement();

public:

	virtual string generateCode(int indentLevel);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~DecoratedContinueStatement();

};

class DecoratedBlockStatement : public DecoratedStatement
{
public:

	DecoratedBlockStatement(DecoratedStatementList * statement_list);

public:

	DecoratedStatementList * statement_list;

	virtual string generateCode(int indentLevel);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~DecoratedBlockStatement();

};

class DNode
{
protected:

	int kind__;
	char *filename__;
	long linenum__;

public:

	int getKind() const { return kind__; }
	const char *getFilename() const { return filename__; }
	long getLinenum() const { return linenum__; }
	void setFilename(char *filename) { filename__ = filename; }
	void setLinenum(long linenum) { linenum__ = linenum; }

	void *operator new(size_t);
	void operator delete(void *, size_t);

protected:

	DNode();

public:

	virtual string toString() = 0;
	virtual DecoratedNode * validateSemantics() = 0;

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~DNode();

};

class MainNode : public DNode
{
protected:

	MainNode();

public:

	virtual string toString() = 0;
	virtual DecoratedNode * validateSemantics() = 0;

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~MainNode();

};

class Definition : public DNode
{
protected:

	Definition();

public:

	virtual string toString() = 0;
	virtual DecoratedNode * validateSemantics() = 0;
	virtual void registerDefinition() = 0;

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~Definition();

};

class Expression : public DNode
{
protected:

	Expression();

public:

	virtual string toString() = 0;
	virtual DecoratedNode * validateSemantics() = 0;

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~Expression();

};

class Statement : public DNode
{
protected:

	Statement(int line, int column);

public:

	int line;
	int column;

	virtual string toString() = 0;
	virtual DecoratedNode * validateSemantics() = 0;

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~Statement();

};

class ClassDef : public MainNode
{
public:

	ClassDef(string name, VariableDefList * field_def_list, MethodDefList * method_def_list);

public:

	string name;
	VariableDefList * field_def_list;
	MethodDefList * method_def_list;

	virtual string toString();
	virtual DecoratedNode * validateSemantics();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ClassDef();

};

class VariableDef : public Definition
{
public:

	VariableDef(string variable_name, int line, int column);

public:

	string variable_name;
	int line;
	int column;
	Type variable_type;
	bool is_array_def;
	int array_dimension;
	Expression * initial_value;

	virtual string toString();
	virtual DecoratedNode * validateSemantics();
	virtual void registerDefinition();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~VariableDef();

};

class ParameterDef : public Definition
{
public:

	ParameterDef(string parameter_name, Type parameter_type);

public:

	string parameter_name;
	Type parameter_type;

	virtual string toString();
	virtual DecoratedNode * validateSemantics();
	virtual void registerDefinition();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ParameterDef();

};

class MethodDef : public Definition
{
public:

	MethodDef(string method_name);

public:

	string method_name;
	Type method_return_type;
	ParameterDefList * method_parameters;
	Statement * method_body;

	virtual string toString();
	virtual DecoratedNode * validateSemantics();
	virtual void registerDefinition();
	virtual DecoratedBlockStatement * checkBody();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~MethodDef();

};

class BinaryExpression : public Expression
{
public:

	BinaryExpression(Expression * left, Expression * right, ExpressionOperator expression_operator);

public:

	Expression * left;
	Expression * right;
	ExpressionOperator expression_operator;

	virtual string toString();
	virtual DecoratedNode * validateSemantics();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~BinaryExpression();

};

class UnaryExpression : public Expression
{
public:

	UnaryExpression(Expression * expression, ExpressionOperator expression_operator);

public:

	Expression * expression;
	ExpressionOperator expression_operator;

	virtual string toString();
	virtual DecoratedNode * validateSemantics();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~UnaryExpression();

};

class LValueExpression : public Expression
{
public:

	LValueExpression(string variable_name, Expression * array_index);

public:

	string variable_name;
	Expression * array_index;

	virtual string toString();
	virtual DecoratedNode * validateSemantics();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~LValueExpression();

};

class MethodCallExpression : public Expression
{
public:

	MethodCallExpression(string method_name, ExpressionList * method_arguments);

public:

	string method_name;
	ExpressionList * method_arguments;

	virtual string toString();
	virtual DecoratedNode * validateSemantics();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~MethodCallExpression();

};

class IntConstantExpression : public Expression
{
public:

	IntConstantExpression(int int_value);

public:

	Type constant_type;
	int int_value;

	virtual string toString();
	virtual DecoratedNode * validateSemantics();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~IntConstantExpression();

};

class RealConstantExpression : public Expression
{
public:

	RealConstantExpression(float float_value);

public:

	Type constant_type;
	float float_value;

	virtual string toString();
	virtual DecoratedNode * validateSemantics();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~RealConstantExpression();

};

class BooleanConstantExpression : public Expression
{
public:

	BooleanConstantExpression(bool bool_value);

public:

	Type constant_type;
	bool bool_value;

	virtual string toString();
	virtual DecoratedNode * validateSemantics();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~BooleanConstantExpression();

};

class StringConstantExpression : public Expression
{
public:

	StringConstantExpression(char * string_value);

public:

	Type constant_type;
	char * string_value;

	virtual string toString();
	virtual DecoratedNode * validateSemantics();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~StringConstantExpression();

};

class AssignmentStatement : public Statement
{
public:

	AssignmentStatement(int line, int column, Expression * lvalue, Expression * expr);

public:

	Expression * lvalue;
	Expression * expr;

	virtual string toString();
	virtual DecoratedNode * validateSemantics();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~AssignmentStatement();

};

class MethodCallStatement : public Statement
{
public:

	MethodCallStatement(int line, int column, string name, ExpressionList * arguments);

public:

	string name;
	ExpressionList * arguments;

	virtual string toString();
	virtual DecoratedNode * validateSemantics();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~MethodCallStatement();

};

class IfStatement : public Statement
{
public:

	IfStatement(int line, int column, Expression * condition, Statement * true_part, Statement * false_part);

public:

	Expression * condition;
	Statement * true_part;
	Statement * false_part;

	virtual string toString();
	virtual DecoratedNode * validateSemantics();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~IfStatement();

};

class WhileStatement : public Statement
{
public:

	WhileStatement(int line, int column, Expression * condition, Statement * loop_body);

public:

	Expression * condition;
	Statement * loop_body;

	virtual string toString();
	virtual DecoratedNode * validateSemantics();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~WhileStatement();

};

class ForStatement : public Statement
{
public:

	ForStatement(int line, int column, Statement * assignment_list1, Expression * condition, Statement * assignment_list2, Statement * loop_body);

public:

	Statement * assignment_list1;
	Expression * condition;
	Statement * assignment_list2;
	Statement * loop_body;

	virtual string toString();
	virtual DecoratedNode * validateSemantics();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ForStatement();

};

class ReturnStatement : public Statement
{
public:

	ReturnStatement(int line, int column, Expression * expr);

public:

	Expression * expr;

	virtual string toString();
	virtual DecoratedNode * validateSemantics();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ReturnStatement();

};

class BreakStatement : public Statement
{
public:

	BreakStatement(int line, int column);

public:

	virtual string toString();
	virtual DecoratedNode * validateSemantics();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~BreakStatement();

};

class ContinueStatement : public Statement
{
public:

	ContinueStatement(int line, int column);

public:

	virtual string toString();
	virtual DecoratedNode * validateSemantics();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ContinueStatement();

};

class BlockStatement : public Statement
{
public:

	BlockStatement(int line, int column);

public:

	StatementList * statement_list;

	virtual string toString();
	virtual DecoratedNode * validateSemantics();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~BlockStatement();

};

class PrintStatement : public Statement
{
public:

	PrintStatement(int line, int column, ExpressionList * arguments);

public:

	ExpressionList * arguments;

	virtual string toString();
	virtual DecoratedNode * validateSemantics();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~PrintStatement();

};



#endif
