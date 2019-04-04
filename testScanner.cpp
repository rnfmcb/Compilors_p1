//Rachel Festervand 
//Program Translation
//This is the test scanner file for project 1. 
//This file tests the functionality of the scanner file.
#include <iostream> 
#include <string> 
#include <fstream>
#include <stdlib.h> 
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
		   exit(EXIT_FAILURE); 
        }
      if (infile.peek() == ifstream::traits_type::eof() ){
         cout << "{EOFTkn,EOF,1}" << endl;
         exit(EXIT_FAILURE);
	   }

     string word;
	 int state; 
	 
     while(getline(infile,line)){
        scanner.setLine();
	    //Comment filter 
        if (line[0] != '\\'){          
	
			istringstream stm(line); 
              while(stm >> word){
			  	 if(word.empty()){ 
					scanner.setLine(); 
				 }   
              	 state = scanner.table(word); 
			  	 cout << "Final State is " << state << endl; 	  	
				 
              }
           }
		else { 
			cout << "{Comment filtered, " << scanner.getLine() << "}" << endl;  
	    }    
        
				  
         
       } 
  
cout << "{EOFTkn,EOF," << scanner.getLine() << "}" << endl; 
  infile.close(); 
 }
} 
 
