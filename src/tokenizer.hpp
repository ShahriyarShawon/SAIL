#ifndef tokenizerhpp
#define tokenizerhpp

#include <string>
#include <vector>

using namespace std;

enum TokenTypes {
    L_Paren,
    R_Paren,
    FUNCTION,
    IDENTIFIER,
    DOUBLE_QUOTE,
    NUM,
    OPERATOR
};

class Token{
private:
    string token_type;
    string value;
public:
    Token(string tt, string v);
    void print_token();
};

class Tokenizer {
private:
    int  curr_pos = -1;
    char curr_char{};
    string src_code{};

public:
    Tokenizer(string src);
    vector<Token> tokenize();
    vector<Token> tokens{};
    string        get_function_name();
    string        get_string();
    char          advance();
    char          advance_by(size_t len);
    void          print_tokens();
    bool          in_string = false;
    bool          in_function = false;


};

#endif