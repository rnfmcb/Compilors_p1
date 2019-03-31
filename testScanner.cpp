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


void  FADriver(ifstream &infile,string filename){ 
	Scanner scanner; 
    string line;
    string type;
    infile.open(filename.c_str()); 
    if(infile.is_open()){  
       if(!infile){
           cout << "Scanner Error: unable to open file" << endl;
        }
     string word;
	 int state; 
	 
     while(getline(infile,line)&& !line.empty()){
        scanner.setLine();
	    //Comment filter 
        if (line[0] != '\\'){          
	
			istringstream stm(line); 
              while(stm >> word)
              {
			   cout << word << endl; 
               state = scanner.table(word); 
			   cout << "Final State is " << state << endl;
			     
              }
           }
		else { 
			cout << "ComTkn at line " << scanner.getLine() << " Comment instance " << endl;  
	    }    
        if (infile.eof()) {
			cout << "EOFtkn at line " <<  scanner.getLine() << endl; 	  
          }
       } 
  
  infile.close(); 
 }
} 
 
