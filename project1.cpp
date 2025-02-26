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
unordered_map<string, string> TOKENS = {  // I put them in wrong order pair 
    {"(", "leftParen"}, {")", "rightParen"}, {"[", "leftBracket"}, {"]", "rightBracket"},
    {"{", "leftBrace"}, {"}", "rightBrace"}, {".", "dot"}, {"+", "plus"}, {"-", "minus"},
    {"*", "multiply"}, {"/", "divide"}, {"%", "modulus"}, {"<", "lessThan"},
    {">", "greaterThan"}, {"=", "assignment"}, {";", "semicolon"}, {",", "comma"},
    {"++", "increment"}, {"--", "decrement"}, {"<=", "lessThanEq"}, {">=", "greaterThanEq"},
    {"==", "logicEqual"}, {"&&", "logicAnd"}, {"||", "logicOr"}, {"!", "logicNot"},
    {"&", "bitAnd"}, {"|", "bitOr"}
};

// Keywords
unordered_set<string> KEYWORDS = {"int", "return", "if", "switch", "float", "while", "else", "case",
                                  "char", "for", "goto", "unsigned", "main", "break", "continue", "void"};

std::vector<std::pair<std::string, std::string>> lexicalAnalyzer(const std::string fileName)
{
    ifstream file(fileName);  // Extracts info from file
    if(!file)  // Error test case 
    {
        std::cerr << "Error opening file!";
        return;
    }

    std::string currentLine; // String for containing the current line from the file
    while(getline(file, currentLine)) // Looping through each line
    {
        std::istringstream lineStream(currentLine); // Line is taken from file and contained in string currentLine
        std::string token; // String to hold current token
        while(lineStream >> token) // Need to loop through the string to get each token and check type
        {
            // check if number

            // check if token 

            // check if keyword

            //check if operator 

            // look for errors?
        }
    }

}

int main() {
    return 0;
}