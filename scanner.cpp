//This is the scanner file for project 1
//Rachel Festervand
//Program Translation 

#include <iostream> 
#include "token.h"
#include "scanner.h"  


using namespace std;

Scanner::Scanner(){
} 

//Creates the token 
void Scanner::makeToken(string type, int line){ 
	Token token; 
	token.lineNum = line; 
	token.tokenType = type; 	

} 

//Checks what type of token 
void Scanner:: checkType (char x, int line) { 
	string type; 
    line = 0; 

	if(x == Num[0]) { 
		type = "numId"; 
    	makeToken(type, line);  
	}
} 









