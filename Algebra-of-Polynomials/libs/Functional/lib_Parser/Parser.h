#ifndef LIB_PARSER_PARSER_H_
#define LIB_PARSER_PARSER_H_

#include <map>
#include <stack>
#include <iostream>
#include "../lib_Stack/Stack.h"
#include "../lib_Monom/Monom.h"
#include "../lib_SyntaxTree/SyntaxTree.h"
#include "../lib_List/List.h"
#include "../lib_SortedArrayTable/SortedArrayTable.h"

class Parser {
    std::string infixExpression;
    std::string postfixExpression;
    std::map<char, int> operationsPriority = {
            {'(', 0},
            {'+', 1},
            {'-', 1},
            {'*', 2},
            {'/', 2},
            {'^', 3},
            {'~', 4}
    };
	std::string targetExpression;
    SortedArrayTable<std::string, Polynom>* table;
    List<Monom> list;
    void removeSpaces();
    bool isDigit(char c);

public:
    Parser();
	Parser(std::string expression);
    Parser(std::string expression, SortedArrayTable<std::string, Polynom>* table);
	List<Monom> parse();
	void parseMonom(std::string monom);
    void removeSpaces(std::string& expression);
    void toPostfix(std::string expression);
    Polynom calculate();
    std::string parseNumber(std::string expression, int* position);
    std::string parseKey(std::string expression, int* position);
    Polynom execute(char operation, Polynom first, Polynom second);
};

#endif // !LIB_PARSER_PARSER_H_