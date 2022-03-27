#include <iostream>
#include <string>
#include <vector>

#include "tokenizer.hpp"

int main(int argc, char * argv[]) {
    // string src_code = "print(\"This is some example \\\" source code\n\");";
    string src_code = "4+16+32+901";
    cout << "Source code is "<<src_code<<"\n";
    Tokenizer t(src_code);
    vector<Token> tokens = t.tokenize();
    for (Token t : tokens){
        t.print_token();
    }
    return 0;
}