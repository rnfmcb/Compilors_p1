//Rachel Festervand
//Program Translation
//This is the types including token file 


#ifndef TOKEN_H 
#define TOKEN_H 	

#include <string> 
using namespace std; 

const char Num[]  = {'1','2','3','4','5','6','7','8','9','0'};
const char letters[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
const char capitals[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};  
const char delimiter[] = {'=','<','>',':','+','-','*','/','%','.',',',';','(',')','{','}','[',']'}; 
const string tokens[] = {"INTTkn","ltrTkn","delTkn","begintkn","endTkn","LoopTkn","voidTkn", "returnTkn","readTkn","outputTkn","programTkn","IFFTkn","thenTkn","LetTkn","wsTkn","charTkn","eofTkn"};
const string keywords[] = {"Begin","End","Loop","Void","INT","Return","Read","Output","Program","IFF","Then","Let"};






 struct Token{ 

  //  enum tokenID id; 
    int lineNum;
    string tokenType;  
};  
 
    
  
//}

#endif 
