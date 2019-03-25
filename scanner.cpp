//This is the scanner file for project 1
//Rachel Festervand
//Program Translation 

#include <iostream>
#include <ctype.h>  
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
    //If char is a number, then it is a int
	if(x == Num[0] | x == Num[1] | x == Num[2] | x == Num[3] | x == Num[4] | x == Num[5] | x == Num[6] | x == Num[7] | x == Num[8] | x == Num[9])  { 
		type = "intTkn"; 
    	makeToken(type, line);  
	}
    // =  <  >  :   +  -  *  /   %  . (  ) , { } ; [ ]
    else if ( x == delimiter[0] |  x == delimiter[1] | x == delimiter[2] | x == delimiter[3] |  x == delimiter[4] | x == delimiter[5] | x == delimiter[6]
	| x == delimiter[7] | x == delimiter[8] | x == delimiter[9] | x == delimiter[10] | x == delimiter[11] | x == delimiter[12] | x == delimiter[13] |
	 x == delimiter[14] | x == delimiter[15] | x == delimiter[16]){
   	    type = "delTkn"; 
		makeToken(type,line); 
    }  	  	
    else if (islower(x)){
		type = "ltrTkn"; 
		makeToken(type,line); 
    } 
    else { 
		cout << "Error, invalid charactor" << endl; 
    } 
}
//Check if keyword 
void Scanner::checkKeyword(string word){ 
 	string type; 
	int line; 
	if(word.find("Begin")){ 
		type = "BeginTkn"; 
		makeToken(type, line); 
 	}  
    else if(word.find("End")){ 
		type = "EndTkn";
		makeToken(type,line); 
	}	
    else if(word.find("Loop")){
		type = "LoopTkn"; 
		makeToken(type,line); 
	} 
	else if(word.find("Void")){ 
		type = "VoidTkn"; 
		makeToken(type, line); 
	} 
	else if(word.find("Return")){
		type = "ReturnTkn"; 
		makeToken(type,line); 
	} 
	else if(word.find("Read")){
		type = "ReadTkn"; 
		makeToken(type,line); 
	} 
	else if(word.find("Output")){
		type = "outputTkn"; 
		makeToken(type,line); 
 	} 
	else if(word.find("Program")){ 
		type = "programTkn"; 
		makeToken(type, line); 
	} 
	else if(word.find("IFF")){ 
		type = "iffTkn"; 
		makeToken(type,line);   
	} 
	else if(word.find("Then")){ 
		type = "thenTkn"; 
		makeToken(type,line);
	} 
	else if (word.find("Let")){ 
		type = "letTkn"; 
	    makeToken(type,line);
	} 
	else { 
		type = "ltrTkn"; 
		makeToken(type,line); 
	} 

} 









