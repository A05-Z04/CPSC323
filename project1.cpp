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

std::vector<std::pair<std::string, std::string>> lexicalAnalyzer(const std::string& fileName)
{
    ifstream file(fileName);  // Extracts info from file
    if(!file) { // Error test case
        std::cerr << "Error opening file!" << std::endl;
        return {}; //Should return an empty vector
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
            output_token.push_back({token, "number"});
            continue; 
            }

            // check if token 
            else if(TOKENS.count(token)) {  // Checks if the current token is in the TOKENS mao
                output_token.push_back({token,TOKENS[token]}); 
                continue;
            }

            // check if keyword
            else if(KEYWORDS.count(token)) {
                output_token.push_back({token,"Keyword"});
                continue;
            }

            // look for errors?
            output_token.push_back({token, "error"});
        }
    }
    file.close();
    return output_token;
}

int main() {  // Array of test files created
    /*std::string testFiles[] = {   
        "testCases/Case1.txt",
        "testCases/Case2.txt",
        "testCases/Case3.txt",
        "testCases/Case4.txt",
        "testCases/Case5.txt"
    };

    for(const auto& filename: testFiles) {  // loop going through each test case
        std::vector<std::pair<std::string, std::string>> output_token = lexicalAnalyzer(filename);  // vector that holds the token and types
        for( const auto& tokens: output_token) // A loop to print out the tokens and types from output_token vector
        {
            std::cout << "Token: " << tokens.first << ", Type: " << tokens.second<< std::endl;
        }

    }
    return 0;
    */
   // TEST 1
   std::cout << "------- TEST 1 -------" << std::endl;
    
   std::string testFile1 = "Case1.txt";
   // Get tokens from lexer
   vector<pair<string, string>> output_token1 = lexicalAnalyzer(testFile1);

   // Print tokens
   for (const auto& token : output_token1) {
       cout << "Token: " << token.first << ", Type: " << token.second << endl;
   }
   std::cout << "----------------------" << std::endl;
   
   
   // TEST 2
   std::cout << "------- TEST 2 -------" << std::endl;
   
   std::string testFile2 = "Case2.txt";
   // Get tokens from lexer
   vector<pair<string, string>> output_token2 = lexicalAnalyzer(testFile2);

   // Print tokens
   for (const auto& token : output_token2) {
       cout << "Token: " << token.first << ", Type: " << token.second << endl;
   }
   std::cout << "----------------------" << std::endl;
   
   
    // TEST 3
   std::cout << "------- TEST 3 -------" << std::endl;
   
   std::string testFile3 = "Case3.txt";
   // Get tokens from lexer
   vector<pair<string, string>> output_token3 = lexicalAnalyzer(testFile3);

   // Print tokens
   for (const auto& token : output_token3) {
       cout << "Token: " << token.first << ", Type: " << token.second << endl;
   }
   std::cout << "----------------------" << std::endl;
   
   
   // TEST 4
   std::cout << "------- TEST 4 -------" << std::endl;
   
   std::string testFile4 = "Case4.txt";
   // Get tokens from lexer
   vector<pair<string, string>> output_token4 = lexicalAnalyzer(testFile4);

   // Print tokens
   for (const auto& token : output_token4) {
       cout << "Token: " << token.first << ", Type: " << token.second << endl;
   }
   std::cout << "----------------------" << std::endl;
   
   
   // TEST 5
   std::cout << "------- TEST 5 -------" << std::endl;
   std::string testFile5 = "Case5.txt";
   // Get tokens from lexer
   vector<pair<string, string>> output_token5 = lexicalAnalyzer(testFile5);

   // Print tokens
   for (const auto& token : output_token5) {
       cout << "Token: " << token.first << ", Type: " << token.second << endl;
   }
   std::cout << "----------------------" << std::endl;

   return 0;
}