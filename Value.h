/*
 * Value.h
 *
 *  Created on: Mar 27, 2009
 *      Author: ivan_deras
 */

#ifndef VALUE_H_
#define VALUE_H_

#include <string>
#include <list>

using namespace std;

typedef unsigned char byte;

/*
 * Tipos de datos soportados por Decaf
 */
enum Type {
	Int,
	Char,
	Real,
	Boolean,
	String,
	Void
};

inline string TypeToString(Type type)
{
	switch (type)
	{
		case Int: return "int";
		case Char: return "char";
		case Boolean: return "boolean";
		case String: return "string";
		case Void: return "void";
	}

	return "None";
}

/*
 * Esta estructura representa el atributo sintetizado en la 
 * generacion de código de una Expresion.
 */
struct Result
{
	string place;
	string code;
};

struct Constant
{
	Type type;
	union {
		int int_value;
		bool bool_value;
		char *string_value;
	} value;
};


#endif /* VALUE_H_ */
