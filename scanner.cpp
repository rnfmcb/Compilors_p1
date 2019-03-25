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
    //If char is a number, then it is a int
	if(x == Num[0] | x == Num[1] | x == Num[2] | x == Num[3] | x == Num[4] | x == Num[5] | x == Num[6] | x == Num[7] | x == Num[8] | x == Num[9])  { 
		type = "intId"; 
    	makeToken(type, line);  
	}
    // =  <  >  :   +  -  *  /   %  . (  ) , { } ; [ ]
    else if ( x == delimiter[0] |  x == delimiter[1] | x == delimiter[2] | x == delimiter[3] |  x == delimiter[4] | x == delimiter[5] | x == delimiter[6]
	| x == delimiter[7] | x == delimiter[8] | x == delimiter[9] | x == delimiter[10] | x == delimiter[11] | x == delimiter[12] | x == delimiter[13] |
	 x == delimiter[14] | x == delimiter[15] | x == delimiter[16]){
   	    type = "delId"; 
		makeToken(type,line); 
    }  	  	




} 









