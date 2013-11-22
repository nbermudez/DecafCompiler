DECAF_LEXER 	:= decaf_lexer.cpp
DECAF_GRAMMAR	:= decaf_grammar.cpp
DECAF_TOKENS	:= decaf_tokens.h
DECAF_TREE_DEF	:= decaf_tree.tc
DECAF_TREE	:= decaf_tree.cpp

TARGET  := decaf
SRCS    := ${DECAF_TREE} ${DECAF_LEXER} ${DECAF_GRAMMAR} Util.cpp error_handler.cpp register_manager.cpp label_manager.cpp main.cpp
OBJS    := ${SRCS:.cpp=.o} 

CCFLAGS = -fpermissive -g
LDFLAGS = 
LIBS    = 

.PHONY: all clean

all:: ${TARGET} 

${TARGET}: ${OBJS} 
	${CXX} ${LDFLAGS} -o $@ $^ ${LIBS} 

${OBJS}: %.o: %.cpp
	${CXX} ${CCFLAGS} -o $@ -c $< 
	
${DECAF_LEXER}:	decaf_lexer.l ${DECAF_TOKENS}
	flex -o $@ $<
	
${DECAF_GRAMMAR} ${DECAF_TOKENS}: decaf_grammar.y
	bison --defines=${DECAF_TOKENS} -r all -o ${DECAF_GRAMMAR} $< -v

${DECAF_TREE}: ${DECAF_TREE_DEF}
	treecc --output decaf_tree.cpp --header decaf_tree.h $<
	
clean:: 
	-rm -f *~ *.o ${TARGET} ${DECAF_LEXER} ${DECAF_GRAMMAR} ${DECAF_TOKENS} ${DECAF_TREE} decaf_tree.h decaf_grammar.output

