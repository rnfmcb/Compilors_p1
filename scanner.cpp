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

    // =  <  >  :   +  -  *  /   %  . (  ) , { } ; [ ]
    if ( x == delimiter[0] |  x == delimiter[1] | x == delimiter[2] | x == delimiter[3] |  x == delimiter[4] | x == delimiter[5] | x == delimiter[6]
	| x == delimiter[7] | x == delimiter[8] | x == delimiter[9] | x == delimiter[10] | x == delimiter[11] | x == delimiter[12] | x == delimiter[13] |
	 x == delimiter[14] | x == delimiter[15] | x == delimiter[16]){
   		return true; 
    }  	
 	else 
		return false;   	
}
//Check if keyword 
bool Scanner::checkKeyword(string word){ 
 	string type;  
	string inst = "Keyword"; 
	if(word == "Begin"){ 
		type = "BeginTkn"; 
		makeToken(type,inst); 
		return true; 
 	}  
    else if(word == "End"){ 
		type = "EndTkn";
		makeToken(type,inst);
		return true;  
	}	
    else if(word == "Loop"){
		type = "LoopTkn"; 
		makeToken(type,inst);
		return true;  
	} 
	else if(word == "Void"){ 
		type = "VoidTkn"; 
		makeToken(type,inst);
		return true;  
	} 
	else if(word == "Return"){
		type = "ReturnTkn"; 
		makeToken(type,inst);
		return true;  
	} 
	else if(word == "Read"){
		type = "ReadTkn"; 
		makeToken(type,inst);
		return true;  
	} 
	else if(word == "Output"){
		type = "outputTkn"; 
		makeToken(type,inst);
		return true;  
 	} 
	else if(word == "Program"){ 
		type = "programTkn"; 
		makeToken(type,inst);
		return true;  
	} 
	else if(word == "IFF"){ 
		type = "iffTkn"; 
		makeToken(type,inst); 
		return true;   
	} 
	else if(word == "Then"){ 
		type = "thenTkn"; 
		makeToken(type,inst);
		return true; 
	} 
	else if (word == "Let"){ 
		type = "letTkn"; 
	    makeToken(type,inst);
		return true; 
	}
	else if (word == "INT") { 
		type = "intTkn"; 
		makeToken(type,inst); 
		return true; 
	} 
	else { 
		return false;   
	} 
	

} 

//This functions gets the next state 
int Scanner::table (string s){
  string type;   
  char p[s.length()];    
    for (int i = 0; i < sizeof(p); i++) { 
        p[i] = s[i]; 
    } 
  for(int i = 0; i < p[i]!= '\0'; i++) { 
	  //If char is // return comTkn and filter rest of strings 
 	 if ( p[i] && p[i+1] == '\\'){
		type = "comTkn";  
		string inst = "Comment instance"; 
		setLine(); 
		makeToken(type,inst);
		return 1;    	
   	} 
else if(isdigit(p[i])){ 
    bool isvalid =  false; 
	isvalid = validInt(s);  
	  cout << isvalid << endl; 
	  type = "intTkn"; 
	  string inst = "Number instance";  
	  makeToken(type,inst);
	  return 2;  
    }
	else if(isalpha(p[i])){ //If uppercase string, check for keyword 
if(isupper(p[i])){ 
			bool isKey = checkKeyword(s); 
			if (isKey == true) //Is keyword  
				return 3; 
           else{ //Is identifier 
				type = "IDTkn";
				string inst = "identifier instance";   
				makeToken(type,inst); 
				return 4; 
			}
        }
		else{ //is lower case 
			type = "ltrTkn";
			string inst = "Letter instance";  
			makeToken(type,inst);
			return 5;  
		} 
     } 
	else if (bool isKey = checkDelimiter(p[i])){ 
		return 6; 
    } 
	else if (p[i] == '\\'  && p[i+1] == 'n'){ //whitespace 
	    type = "wsTkn"; 
		string inst = "Whitespace instance"; 
		makeToken(type,inst); 
		return 7; 
    }
	else if (p[i] == EOF){  
		type = "EOFTkn"; 
		string inst = "End of file"; 
		makeToken(type,inst); 
		return 8;  
    } 
	else{ //invalid charactor 
		cout << "Scanner error: Invalid charactor, line number: " <<  getLine()  << endl; 
		exit(EXIT_FAILURE); 
    } 
  }  		  
}  

bool Scanner::validInt(string s) { 
	char p[s.length()];
	for(int i = 0; i < sizeof(p); i++){
		p[i] = s[i]; 
    } 
	for(int i = 0; i < p[i]!= '\0'; i++) {
 
		if (p[i] == '.') {
		  cout<<"Scanner Error: Invalid int number, is decimal" << endl; 
          exit (EXIT_FAILURE);
		  return false; 
		} 
		else if (p[i] == '-'){ 
			cout << "Scanner Error: negative number" << endl; 
			exit (EXIT_FAILURE); 
			return false; 
		}
		else return true;  
	} 
} 	
         


void Scanner:: print(Token *tkn){ 
	cout << "Token type: " <<  tkn->tokenType << " Line number: " <<  tkn->lineNum << " Instance: " << tkn->instance << endl; 
} 
