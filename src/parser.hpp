#ifndef parserhpp
#define parserhpp

#include <string>
#include <vector>

#include "tokenizer.hpp"

using namespace std;

class BinaryOperation {
    Token left;
    Token operation;
    Token right;

    BinaryOperation(Token l, Token op, Token r) {
        left      = l;
        operation = op;
        right     = r;
    }
};

class Number{
    Token tok;
    int value;
    Number(Token t);
};


class Parser {
    vector<Token> tokens;
    Token         curr_token;
    


};

#endif