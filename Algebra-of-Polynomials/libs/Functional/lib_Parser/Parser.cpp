#include "Parser.h"
#include "../lib_Polynom/Polynom.h"

Parser::Parser() {
    targetExpression = "";
}

Parser::Parser(std::string expression) {
    targetExpression = expression;
    removeSpaces();
    table = new SortedArrayTable<std::string, Polynom>();
}
Parser::Parser(std::string expression, SortedArrayTable<std::string, Polynom> *table) {
    targetExpression = expression;
    removeSpaces();
    this->table = table;
}


//COMPLETED
List<Monom> Parser::parse() {
     std::string delimeter = "+-";
     std::string token;
     size_t start = 0, end = targetExpression.find_first_of(delimeter, start);
     if (end != std::string::npos && end != 0) {
         token = targetExpression.substr(start, end - start);
         parseMonom(token);
         start = ++end;
         while ((end = targetExpression.find_first_of(delimeter,start)) != std::string::npos) {
             token = targetExpression.substr(start - 1, end - start + 1);
             parseMonom(token);
             start = ++end;
         }
         parseMonom(targetExpression.substr(start - 1));
     } else if (targetExpression.find_first_of(delimeter,start + 1) != std::string::npos) {
         end = targetExpression.find_first_of(delimeter, start + 1);
         token = targetExpression.substr(start, end - start);
         parseMonom(token);
         start = ++end;
         while((end = targetExpression.find_first_of(delimeter, start)) != std::string::npos) {
             token = targetExpression.substr(start - 1, end - start + 1);
             parseMonom(token);
             start = ++end;
         }
         parseMonom(token);
     } else {
         parseMonom(targetExpression);
     }
     return list;
}
//COMPLETED
void Parser::removeSpaces() {
    targetExpression.erase(std::remove(targetExpression.begin(), targetExpression.end(), ' '), targetExpression.end());
}

//COMPLETED
void Parser::parseMonom(std::string monom) {
    double coeff = 1;
    int numVars = 3;
    int powers[] = { 0, 0, 0};
    std::string varsName = "xyz";
    for (int i = 0; i < monom.size(); i++) {
        if (monom[i] >= '0' && monom[i] <= '9') {
            coeff = std::stod(monom);
        }
        if (monom[i] == 'x' || monom[i] == 'y' || monom[i] == 'z') {
            for (int j = 0; j < 3; j++) {
                if (monom[i] == varsName[j]) {
                    if (monom[i + 1] == '^') {
                        powers[j] = std::stoi(monom.substr(i + 2));
                    }
                    else {
                        powers[j] = 1;
                    }
                }
            }
        }
    }
    Monom temp(coeff, numVars, powers);
    int index = list.contains(temp);
    if (index != -1) {
        if ((list.get(index).getCoeff() > 0 && temp.getCoeff() < 0) || (list.get(index).getCoeff() < 0 && temp.getCoeff() > 0)) {
            list.remove(list.get(index));
        } else {
          list.get(index) += temp;
        }
    } else {
        list.push_back(temp);
    }
}

void Parser::removeSpaces(std::string& expression) {
    std::string delimeter = " ";
    size_t start = 0, end = expression.find_first_of(delimeter, start);
    std::string token;
    while (expression.find_first_of(delimeter, start)) {
        token.append(expression.substr(start, end - start));
        start = ++end;
    }
    expression = token;
}

bool Parser::isDigit(char c) {
    if ('0' <= c && c <= '9') return true;
    else return false;
}

Polynom Parser::calculate() {
    Stack<Polynom> stack;
    for (int i = 0; i < postfixExpression.size(); i++) {
        char expressionChar = postfixExpression[i];
        if (isDigit(expressionChar)) {
            Polynom tmp = Polynom(parseNumber(postfixExpression, &i));
            stack.push(tmp);
        } else if (operationsPriority.contains(expressionChar)) {
            Polynom second = stack.isEmpty() ? Polynom("0") : stack.top();
            stack.pop();
            Polynom first = stack.isEmpty() ? Polynom("0") : stack.top();
            stack.pop();
            stack.push(execute(expressionChar, first, second));
        } else if (expressionChar != ' '){
            Polynom tmp = table->find(parseKey(postfixExpression, &i));
            stack.push(tmp);
        }
    }
    return stack.top();
}

std::string Parser::parseNumber(std::string expression, int *position) {
    std::string number = "";
    for (; (*position) < expression.length(); (*position)++) {
        char expressionChar = expression[(*position)];
        if (isDigit(expressionChar))
            number += expressionChar;
        else {
            (*position)--;
            break;
        }
    }
    return number;
}

std::string Parser::parseKey(std::string expression, int *position) {
    std::string key = "";
    for(; (*position) < expression.size(); (*position)++) {
        char expressionChar = expression[(*position)];
        if (!operationsPriority.contains(expressionChar) && expressionChar != ' ') {
            key+=expressionChar;
        } else  {
            (*position)--;
            break;
        }
    }
    return key;
}

void Parser::toPostfix(std::string expression) {
    postfixExpression = "";
    Stack<char> operations;
    for (int i = 0; i < expression.size(); i++) {
        char expressionChar = expression[i];
        if (isDigit(expressionChar)) {
            postfixExpression += parseNumber(expression, &i) + " ";
        } else if (operationsPriority.contains(expressionChar)) {
            operations.push(expressionChar);
        } else if (expressionChar != ' ') {
            postfixExpression += parseKey(expression, &i) + " ";
        }
    }
    while (!operations.isEmpty()) {
        postfixExpression += operations.top();
        operations.pop();
    }
}

Polynom Parser::execute(char operation, Polynom first, Polynom second){
    switch (operation) {
        case '+':
            return first + second;
        case '-':
            return first - second;
        case '*':
            return first * second;
        /*case '/':
            return first / second;*/
    }
}