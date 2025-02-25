# CPSC323

## Overview

The first phase of a standard compiler is lexical analysis. The job of the lexical analyzer
is to read in the source program and tokenize it. That is, it must identify the lexemes of the
source program and assign to each lexeme its appropriate token. The lexer (shorthand for the
lexical analyzer) must not accept invalid lexemes. Error handling functionality is common in a
lexer, but will not be required here. The output of the lexer is a stream of tokens corresponding to
the lexemes it has analyzed. The work of lexing is typically performed by a DFA, or something
computationally equivalent.

In this project, you will be building a lexical analyzer that must recognize the valid
lexemes of a toy programming language. A list of tokens and their corresponding lexemes (or
lexeme specification) will be provided along with a set of keywords. Please note that all
keywords are their own token and so their corresponding output token is the same as the lexeme.
The part of your lexer that can handle identifiers is capable of matching keywords. One strategy
is to treat keywords as though they are identifiers, then perform a lookup to see if it is a keyword.
If it is, emit the appropriate keyword token; if not, emit the identifier token. There is more than
one way to do this; I leave it up to your team to design and implement a method. Per the
syllabus, your group may utilize either C++ or Python. You may not utilize a regular expression
engine, pattern matcher, or any library that provides similar functionality.


## Learning Outcomes
1. Understand the basic principles of how the lexemes of a programming language are
built-up, recognized, and tokenized.
2. Develop familiarity with implementing theoretical concepts such as a DFA in order to
recognize the lexemes of a programming language.
3. Develop familiarity with converting specifications and requirements into a correct,
working piece of software.
4. Develop skills in goal setting, communication, and time management in a group context.


## Requirements
Your project must satisfy the following in order to receive full marks:
1. It must have all required submission items uploaded to Canvas before the deadline.
2. It must utilize a table-driven lexing scheme
3. It must successfully recognize all lexemes from the provided Token-Lexeme list.
4. It must properly assign and output a token for each valid lexeme recognized.
5. It must successfully lex all provided test cases.
6. It must not utilize any regular expression engines or libraries of any kind.


## Grading
The project will be graded based on how many of the above requirements your
submission satisfies. If a project successfully meets all of the requirements above, then it will be
awarded full marks. Points will be deducted for each requirement that is not met; partial credit is
possible. The project will be worth 60 points. Per the course syllabus, there will be no late work
accepted.


## Submission Items
The following items must be submitted in a zipped file format to Canvas no later than the
assigned due date of the project:
1. Source code.
2. Screenshot of input and successful output.
3. A very brief project report (pdf format) that outlines the following:
a. Group members.
b. Which member did what work.
c. Programming language used.
d. An explanation of your design choices and how your lexer works. You may
include a diagram or design sketch.
e. Citation of any external resources utilized (stackoverflow, reddit, wikipedia, etc).
f. A statement that no AI resources were utilized in the production of any work for
this project.


## Remarks
1. Your test cases should be transformed, line-by-line, into their tokenized version. That is,
each lexeme of the test case should have been replaced by its appropriate token.
2. For Test Case 1, the set of lexemes for the tokens identifier, number, and comment are
infinite. Please use every keyword as your identifier test cases, three different numbers as
your number test cases, and a small comment for comment.
3. The way comments are meant to be understood is that we ignore everything between //
and the first newline we encounter.
4. The token as named in the Token-Lexeme list is what should be output when a lexeme is
matched.


## Token Lexeme Specification
identifier *([𝑎 − 𝑍])([𝑎 − 𝑍]|[0 − 9])
number *([0 − 9])([0 − 9)
comment *(//)([𝑎𝑛𝑦 𝑠𝑦𝑚𝑏𝑜𝑙 𝑜𝑟 𝑤ℎ𝑖𝑡𝑒𝑠𝑝𝑎𝑐𝑒]) (\𝑛)
leftParen (
rightParen )
leftBracket [
rightBracket ]
leftBrace {
rightBrace }
dot .
plus +
minus -
multiply *
divide /
modulus %
lessThan <
greaterThan >
assignment =
semicolon ;
comma ,
increment ++
decrement --
lessThanEq <=
greaterThanEq >=
logicEqual ==
logicAnd &&
logicOr ||
logicNot !
bitAnd &
bitOr |
Keywords
int return if switch
float while else case
char for goto unsigned
main break continue void

# TEST CASE

Case 1
Feed your lexer every lexeme from the provided Token-Lexeme list. It should output the
appropriate token for each lexeme it is provided.


Case 2
int main()
{
int myInt = 0;
myInt++;
myInt << 1;
return 0;
}


Case 3
int main()
{
int 1stint= 0;;
charmyChar2;
return0;
}


Case 4
int main(void)
{
float myFloat = 0.01;
int counter = 0;
while (counter < 5)
{
++counter;
myFloat = myFloat * 3;
}
counter > myFloat;
return 0;
}


Case 5
int main()
{
int myResult1 = 0;
int arraySize = 5;
int myArray[arraySize] = {1,2,3,4,5};
// this is a for loop
for (int i = 0; i < arraySize; ++i)
{
if (myArray[i] % 2 == 0)
{
myResult++;
}
else
{
myResult--;
}
}
if (myResult >= 0)
{
continue;
}
else
{
myResult = myResult * (-1);
}
return 0;
}
