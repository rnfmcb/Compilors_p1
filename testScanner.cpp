//Rachel Festervand 
//Program Translation
//This is the test scanner file for project 1. 
//This file tests the functionality of the scanner file.
#include <iostream> 
#include <string> 
#include <fstream>
#include <ctype.h> 
#include <sstream>  
#include "token.h" 
#include "scanner.h" 


using namespace std; 


void  BADriver(ifstream &infile,string filename){
	Scanner scanner; 
    string line;
     string type;
     infile.open(filename.c_str());
     if(!infile){
         cout << "Error opening file" << endl;
     }

     string word;
     while(getline(infile,line)){
        scanner.setLine();
         istringstream stm(line);
             while(stm >> word)
             {
             cout << scanner.table(word) << endl;
             }
      }
     if (infile.eof()) {
         type = "eofTkn";
        scanner.makeToken(type);
    }
   infile.close();
 }
 
