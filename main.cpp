#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include "decaf_tree.h"

extern ifstream in;
extern int current_line;

static int errors = 0;

using namespace std;

int yyparse();

ClassDef *class_def;

int main(int argc, char *argv[])
{
	if (argc > 0) {
		++argv, --argc; /* El primer argumento es el nombre del programa */
		in.open(argv[0], ifstream::in|ifstream::binary);

		if (!in.is_open()) {
			cerr << "No se pudo abrir el archivo " << argv[0] << endl << endl;
			return 0;
		}
	}
	else {
		cerr << "Uso: " << argv[0] << " <archivo>" << endl << endl;
		return 0;
	}

	class_def = 0;
	yyparse();

	if (errors == 0) {
		cout << class_def->toString() << endl;
        
        DecoratedNode *decorated_class = class_def->validateSemantics();
        cout << "\033[1;34m" << ErrorHandler::getInstance().allWarnings() << "\033[0m\n";
        if (ErrorHandler::getInstance().getErrorCount() > 0) {
			cout << "\033[1;31m" << ErrorHandler::getInstance().allErrors() << "\033[0m\n";
        } else {
        	cout << "\033[1;32m" << "generating code..." << "\033[0m\n" << endl;
        	cout << decorated_class->generateCode(0);
        }
        
	}

	return 0;
}

void yyerror(const char *message)
{
	errors++;

	fprintf(stderr, "%d:%s\n", current_line, message);
}
