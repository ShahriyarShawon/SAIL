#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#include "tokenizer.hpp"

using namespace std;

vector<string> reserved_keywords{"print"};

string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ,.!";
string numbers = "1234567890";
string ops = "()\"+-*/^><=!{}\\'$;";


Token::Token(string tt, string v) {
    token_type = tt;
    value = v;
}

void Token::print_token(){
    cout<<"Tok["<<token_type<<", "<<value<<" ]\n";
}


Tokenizer::Tokenizer(string src){
    src_code = src;
}

char Tokenizer::advance() {
    curr_pos++;
    if (curr_pos >= src_code.size()){
        return '\0';
    }
    curr_char = src_code.at(curr_pos);
    return curr_char;
}

char Tokenizer::advance_by(size_t len) {
    curr_pos+=len;
    if (curr_pos >= src_code.size()){
        return '\0';
    }
    curr_char = src_code.at(curr_pos);
    return curr_char;
}

string Tokenizer::get_function_name() {
    int function_name_end = src_code.find_first_of(ops, curr_pos);
    if (function_name_end != string::npos){
        int string_length = function_name_end-curr_pos;
        string full_function_name = src_code.substr(curr_pos, string_length);;
        advance_by(string_length);
        return full_function_name;
    }else {
        return "wtf";
    }
}

string Tokenizer::get_string() {
    int    string_initial_pos = curr_pos;

    while(true){
        // string_content.push_back(curr_char);
        advance();
        if (curr_char == '"' && (src_code.at(curr_pos-1) != '\\')){
            // END OF STRING
            break;
        }else if (curr_char == ';') {
            break;
        }
        else {
            cout<<curr_char;
        }
    }
    //                                          want to consume the quote as well
    return src_code.substr(string_initial_pos, (curr_pos+1)-string_initial_pos);

}

vector<Token> Tokenizer::tokenize(){
    advance();
    while(true) {
        if (curr_pos >= src_code.size()){ break; }
        cout<<curr_char<<"\n";
        // if curr_char is in alphabet
        if ( alphabet.find_first_of(curr_char) != string::npos) {
            //check if string or function
            if (!in_string){
                // this is a function
                string rest_of_name = get_function_name();    
                tokens.push_back(Token("FUNCTION", rest_of_name));
            }
        }
        // if curr char is an operator
        else if (ops.find_first_of(curr_char) != string::npos){
            if (curr_char == '"') {
                in_string = 1;
                // get string
                string string_content = get_string();
                tokens.push_back(Token(string("STRING"), string_content));
            }else if(curr_char == ';') {
                tokens.push_back(Token(string("OP_EOS"), ";"));
            }
            else {
                tokens.push_back(Token(string("OP"),string(1,curr_char)));

            }
            advance();
        }
        // if curr char is a number
        else if (numbers.find_first_of(curr_char) != string::npos) {

        }
        else {
            break;
        }
    }
    return tokens;
}

