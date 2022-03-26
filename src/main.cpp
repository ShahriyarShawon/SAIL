#include <iostream>
#include <string>
#include <vector>

#include "tokenizer.hpp"

int main(int argc, char * argv[]) {
    string src_code = "print(\"This is some example \\\" source code\n\");";
    cout << "Source code is "<<src_code<<"\n";
    Tokenizer t(src_code);
    auto tokens = t.tokenize();
    for (auto t : tokens){
        t.print_token();
    }
    return 0;
}