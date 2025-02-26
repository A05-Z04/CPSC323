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
    if(!file) {// Error test case
        std::cerr << "Error opening file!";
        return;
    }

    std::string currentLine; // String for containing the current line from the file
    std::vector<std::pair<std::string, std::string>> output_token;
    while(getline(file, currentLine)) {// Looping through each line
        std::istringstream lineStream(currentLine); // Line is taken from file and contained in string currentLine
        std::string token; // String to hold current token
        while(lineStream >> token) {// Need to loop through the string to get each token and check type
    
            bool is_number = true;
            for(char character : token) {
                if(!isdigit(character))  //checking token represents number
                is_number = false;
                break; //stops checking characters
            }

            if(is_number && !token.empty()) {      //checks if token is number and push number to vector
            output_token.push_back({"number", token});
            continue; 
            }

            // check if token 
            else if(TOKENS.count(token)) {  // Checks if the current token is in the TOKENS mao
                output_token.push_back({token,TOKENS[token]}); 
                continue;
            }

            // check if keyword

            //check if operator 

            // look for errors?
        }
    }

    return output_token;
}

int main() {  // Array of test files created
    std::string testFiles[] = {   
        "Test Cases/Case1.txt"
        "Test Cases/Case2.txt"
        "Test Cases/Case3.txt"
        "Test Cases/Case4.txt"
        "Test Cases/Case5.txt"
    };

    for( const auto& filename: testFiles) {  // loop goinf through each test case
        std::vector<std::pair<std::string, std::string>> output_token = lexicalAnalyzer(filename);  // vector that holds the token and types
        for( const auto& tokens: output_token) // A loop to print out the tokens and types from output_token vector
        {
            std::cout << "Token: " << tokens.first << ", Type: " << tokens.second<< std::endl;
        }

    }
    return 0;
}