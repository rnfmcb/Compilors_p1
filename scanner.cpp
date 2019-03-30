//This is the scanner file for project 1
//Rachel Festervand
//Program Translation 

#include <iostream>
#include <ctype.h>
#include <fstream>
#include <sstream> 
#include <string>    
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
void Scanner::makeToken(string type){
	Token token;  
	token.lineNum = getLine(); 
	token.tokenType = type; 	
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
	if(word.find("Begin")){ 
		type = "BeginTkn"; 
		makeToken(type); 
		return true; 
 	}  
    else if(word.find("End")){ 
		type = "EndTkn";
		makeToken(type);
		return true;  
	}	
    else if(word.find("Loop")){
		type = "LoopTkn"; 
		makeToken(type);
		return true;  
	} 
	else if(word.find("Void")){ 
		type = "VoidTkn"; 
		makeToken(type);
		return true;  
	} 
	else if(word.find("Return")){
		type = "ReturnTkn"; 
		makeToken(type);
		return true;  
	} 
	else if(word.find("Read")){
		type = "ReadTkn"; 
		makeToken(type);
		return true;  
	} 
	else if(word.find("Output")){
		type = "outputTkn"; 
		makeToken(type);
		return true;  
 	} 
	else if(word.find("Program")){ 
		type = "programTkn"; 
		makeToken(type);
		return true;  
	} 
	else if(word.find("IFF")){ 
		type = "iffTkn"; 
		makeToken(type); 
		return true;   
	} 
	else if(word.find("Then")){ 
		type = "thenTkn"; 
		makeToken(type);
		return true; 
	} 
	else if (word.find("Let")){ 
		type = "letTkn"; 
	    makeToken(type);
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
		setLine(); 
		makeToken(type);
		return 1;    	
   	} 
    else if(isdigit(p[i])){ 
	  type = "intTkn"; 
	  makeToken(type);
	  return 2;  
    }
	else if(isalpha(p[i])){ //If uppercase string, check for keyword 
		if(isupper(p[i])){ 
			bool isKey = checkKeyword(s); 
			if (isKey == true) //Is keyword  
				return 3; 
           else //Is identifier 
				return 4; 
        }
		else{ //is lower case 
			type = "ltrTkn"; 
			makeToken(type);
			return 5;  
		} 
     } 
	else if (bool isKey = checkDelimiter(p[i])){ 
		return 6; 
    } 
	else if (p[i] == '\\'  && p[i+1] == 'n'){ //whitespace 
	    cout <<"White space " << endl; 
		return 7; 
    }
	else if (p[i] == EOF){  
		type = "EOFTkn"; 
		makeToken(type); 
		return 8;  
    } 
	else{ //invalid charactor 
		cout << "Invalid charactor " << endl; 
		return 9;
    } 
  }  		  
}  


void Scanner:: print(Token *tkn){ 
	cout << "Token type: " <<  tkn->tokenType << " Line number: " <<  tkn->lineNum << endl; 
} 
