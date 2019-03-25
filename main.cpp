//Rachel Festervand
//Program Translation project 1
//This is the main file for project 1. 
//This project will implement a token as a triplet {tokenID, tokenInstance, line#} (if doing option with line numbers)
//Dont forget EOFtk token
//Implement the scanner in a separate file with basename "scanner"
//Fior testing purposes, the scanner will be tested using a testing driver implemented in file with basename "testScanner". You need to implement your own tester and include as a part of the project. The tester will call for one token at a time and display the token to the screen one per line, including information (descriptive) on what token class, what token instance, and what line, if applicable.

#include <iostream> 
#include <string>
#include <fstream>  
#include "token.h"

using namespace std; 


int main(int argc, char*argv[]){

//If no argument, open a txt file
  if(argc == 1){
      string filename = "test.txt";
      string temp;
      ofstream file;
      file.open(filename.c_str());
      while(getline(cin,temp)){
         file << temp << " ";
      }
     file.close();
     ifstream infile;
    // processFile(infile,filename);
  }
 return 0;  
} 
