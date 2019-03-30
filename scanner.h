//Rachel Festervand
//Program Translation
//This is the scanner header file for project 1
#ifndef SCANNER_H
#define SCANNER_H
#include <string> 
#include <iostream> 
#include <fstream> 
#include "token.h" 

class Scanner{ 
	int lineNum; 
public:
   int getLine();  
   void setLine();     
   void getToken(string, Token*);
   void makeToken(string); 
   bool checkDelimiter(char);
   bool checkKeyword(string); 
   int table(string);
   void processFile(ifstream &infile, string); 
   void print(Token*);    
   Scanner(); 
}; 



#endif 
