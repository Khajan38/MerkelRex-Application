#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector <string> tokenise (string csvLine, char seperator){
     vector <string> tokens;
     string token;
     for (char i : csvLine){
          if (i != seperator) token += i;
          else {
               if (token == "") continue;
               tokens.push_back(token); 
               token = "";
          }
     }
     tokens.push_back(token);
     return tokens;
}

// int main(){
//      string csvLine; char seperator;
//      cout<<"\nEnter the string : "; cin>>csvLine;
//      cout<<"Enter the seperator : "; cin>>seperator;
//      vector <string> tokens = tokenise(csvLine, seperator);
//      cout<<"\nTokens : ";for (string i : tokens) cout<<i<<" "; cout<<"\b\b"<<endl;
//      return 0;
// }