//This is the scanner file for project 1
//Rachel Festervand
//Program Translation 

#include <iostream>
#include <ctype.h>
#include <fstream>
#include <sstream> 
#include <string> 
#include <stdlib.h>    
#include "token.h"
#include "scanner.h"  


using namespace std;

Scanner::Scanner(){
	lineNum = 0; 
}

int Scanner::getLine(){ 
	return lineNum; 
} 

//Sets line number 
void Scanner:: setLine(){ 
	lineNum = lineNum + 1; 
}  

//Creates the token 
void Scanner::makeToken(string type,string inst){
	Token token;  
	token.lineNum = getLine(); 
	token.tokenType = type;
	token.instance = inst;  	
    print(&token); 
} 
 

void Scanner::getToken(string type, Token *token){ 
	token->lineNum = getLine(); 
	token->tokenType = type; 
} 

//Checks what type of token 
bool Scanner:: checkDelimiter (char x) { 
	string type; 
	string inst; 

    // =  <  >  :   +  -  *  /   %  . (  ) , { } ; [ ]
    if (x == '=') {
	   type = "eqTkn"; 
	   inst = "="; 
	   makeToken(type,inst);
		return true;  
	} 
	 if (x == '<') {
        type = "LaTkn";
        inst = "<";
        makeToken(type,inst);
		return true; 
     }
	 if (x == '>') {
        type = "RaTkn";
        inst = ">";
        makeToken(type,inst);
		return true; 
     }
	 if (x == ':') {
        type = "colanTkn";
        inst = ":";
        makeToken(type,inst);
		return true; 
     }
	 if (x == '+') {
        type = "plusTkn";
        inst = "+";
        makeToken(type,inst);
		return true; 
     }
	 if (x == '-') {
        type = "minusTkn";
        inst = "-";
        makeToken(type,inst);
		return true; 
     }
	 if (x == '/') {
        type = "slashTkn";
        inst = "/";
        makeToken(type,inst);
		return true; 
     }
	 if (x == '%') {
        type = "percentTkn";
        inst = "%";
        makeToken(type,inst);
		return true; 
     }
	 if (x == '.') {
        type = "periodTkn";
        inst = ".";
        makeToken(type,inst);
		return true; 
     }
	 if (x == '*') {
        type = "starTkn";
        inst = "*";
        makeToken(type,inst);
		return true; 
     }
	 if (x == '(') {
        type = "lparaTkn";
        inst = "(";
        makeToken(type,inst);
		return true; 
     }
	 if (x == ')') {
        type = "RparaTkn";
        inst = ")";
        makeToken(type,inst);
		return true; 
     }
	 if (x == '{') {
        type = "LbraceTkn";
        inst = "{";
        makeToken(type,inst);
		return true; 
     }
      if (x == '}') {
        type = "RBraceTkn";
        inst = "}";
        makeToken(type,inst);
		return true; 
     }
	 if (x == '[') {
        type = "LBraceTkn";
        inst = "[";
        makeToken(type,inst);
		return true; 
     }
	 if (x == ']') {
        type = "RBracketTkn";
        inst = "]";
        makeToken(type,inst);
		return true; 
     }
	 if (x == ',') {
        type = "commaTkn";
        inst = ",";
        makeToken(type,inst);
		return true; 
     }

	 if( x == ';'){ 
		type = "semiTkn"; 
		inst = ";"; 
		makeToken(type, inst); 
		return true; 
	} 
	else  
		return false; 
   	
}
//Check if keyword 
int  Scanner::checkKeyword(string word){ 
 	string type;
	string inst;    
	if(word == "Begin"){ 
		type = "BeginTkn";
		inst = "Begin";  
		makeToken(type,inst); 
		return 7; 
 	}  
    else if(word == "End"){ 
        type = "EndTkn";
		inst = "End"; 
		makeToken(type,inst);
		return 8;  
	}	
    else if(word == "Loop"){
		type = "LoopTkn";
		inst = "Loop";  
		makeToken(type,inst);
		return 10;  
	} 
	else if(word == "Void"){ 
		type = "VoidTkn";
		inst = "Void";  
		makeToken(type,inst);
		return 11;  
	} 
	else if(word == "Return"){
		type = "ReturnTkn"; 
		inst = "Return"; 
		makeToken(type,inst);
		return 12;  
	} 
	else if(word == "Read"){
		type = "ReadTkn";
		inst = "Read";  
		makeToken(type,inst);
		return 13;  
	} 
	else if(word == "Output"){
		type = "outputTkn";
		inst = "Output";  
		makeToken(type,inst);
		return 14;  
 	} 
	else if(word == "Program"){ 
		type = "programTkn";
		inst = "Program";  
		makeToken(type,inst);
		return 15;  
	} 
	else if(word == "IFF"){ 
		type = "iffTkn"; 
		inst = "IFF"; 
		makeToken(type,inst); 
		return 16;   
	} 
	else if(word == "Then"){ 
		type = "thenTkn";
		inst = "Then";  
		makeToken(type,inst);
		return 17; 
	} 
	else if (word == "Let"){ 
		type = "letTkn";
		inst = "Let";  
	    makeToken(type,inst);
		return 18; 
	}
	else if (word == "INT") { 
		type = "intTkn";
		inst = "INT";  
		makeToken(type,inst); 
		return 9; 
	} 
	else { 
		return 0;   
	} 
	

} 

//This is the eof table. Numbers refer to the attached table  
int Scanner::table (string s){
  string type;   
  char p[s.length()];    
    for (int i = 0; i < sizeof(p); i++) { 
        p[i] = s[i]; 
    } 
  for(int i = 0; i < p[i]!= '\0'; i++) { 
	  //If char is // return comTkn and filter rest of strings 
 	 if ( p[i] == '\\'){
		type = "comTkn";  
		string inst = "\\"; 
		setLine(); 
		makeToken(type,inst);
		return 5;    	
   	} 
	else if(isdigit(p[i])){ 
    	bool isvalid =  true; 
		isvalid = validInt(s);   
	  	type = "intTkn"; 
	  	string inst = s;  
	 	makeToken(type,inst);
	  	return 2;  
   	 }
	else if(isalpha(p[i])){ //If uppercase string, check for keyword 
		if(isupper(p[i])){ 
			bool isKey = checkKeyword(s); 
			if (isKey != 0) //Is keyword  
				return isKey; 
           else{ //Is identifier 
				type = "IDTkn";
				string inst = s;   
				makeToken(type,inst); 
				return 6; 
			}
        }
		else{ //is lower case 
			cout << "Error, tokens can not start with lower case" << endl; 
			exit(EXIT_FAILURE);   
		} 
     } 
	else if (bool isKey = checkDelimiter(p[i])){ 
    	if(s[0] == '-' && isdigit(s[1])) { 
			cout << "Scanner error: no negative number" << endl; 
			exit(EXIT_FAILURE); 
			return 3; 
         } 
    } 
	else if (p[i] == '\\'  && p[i+1] == 'n'){ //whitespace 
	    type = "wsTkn"; 
		string inst = "Whitespace instance"; 
		makeToken(type,inst); 
		return 1; 
    }
	else if (p[i] == EOF){  
		type = "EOFTkn"; 
		string inst = "EOF"; 
		makeToken(type,inst); 
		return 1;  
    } 
	else{ //invalid charactor 
		cout << "Scanner error: Invalid charactor, line number: " <<  getLine()  << endl; 
		exit(EXIT_FAILURE); 
    } 
  }  		  
}  

bool Scanner::validInt(string s) { 
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
	 
}        


void Scanner:: print(Token *tkn){ 
	cout << "{" <<  tkn->tokenType << ",'" <<  tkn->instance << "'," << tkn->lineNum << "}" << endl; 
} 
