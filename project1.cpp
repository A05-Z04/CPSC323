#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <cctype>

using namespace std;

// Define token types
unordered_map<string, string> TOKENS = {
    {"leftParen", "("}, {"rightParen", ")"}, {"leftBracket", "["}, {"rightBracket", "]"},
    {"leftBrace", "{"}, {"rightBrace", "}"}, {"dot", "."}, {"plus", "+"}, {"minus", "-"},
    {"multiply", "*"}, {"divide", "/"}, {"modulus", "%"}, {"lessThan", "<"},
    {"greaterThan", ">"}, {"assignment", "="}, {"semicolon", ";"}, {"comma", ","},
    {"increment", "++"}, {"decrement", "--"}, {"lessThanEq", "<="}, {"greaterThanEq", ">="},
    {"logicEqual", "=="}, {"logicAnd", "&&"}, {"logicOr", "||"}, {"logicNot", "!"},
    {"bitAnd", "&"}, {"bitOr", "|"}
};

// Keywords
unordered_set<string> KEYWORDS = {"int", "return", "if", "switch", "float", "while", "else", "case",
                                  "char", "for", "goto", "unsigned", "main", "break", "continue", "void"};

void lexicalAnalyzer(const std::string filename, const std::unordered_map<std::string, std::string>& Tokens, 
    unordered_set<string> KEYWORDSconst)
{
    ifstream file(filename);
    if(!file)
    {
        std::cerr << "Error opening file!";
    }

}

int main() {
    return 0;
}