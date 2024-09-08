#include <iostream>
#include <fstream>
#include "Tokenising test.cpp"

//Reading whole File
void ReadFile (ifstream & csvFile, string csvLine){
     while(getline(csvFile, csvLine, '\n'))
          cout<<csvLine<<endl;
     return;
}

//Reading n lines
void ReadnLines (ifstream & csvFile, string csvLine){
     int n;
     cout<<"\nEnter number of lines to read : "; cin>>n; cout<<endl;
     for (int i = 0; i < n && getline(csvFile, csvLine, '\n'); i++)
          cout<<csvLine<<endl;
}

enum class OrderBookType : int {bid = 0, ask = 1};
// Function to convert a string to an OrderBookType enum
OrderBookType stringToOrderBookType(const string& type) {
    if (type == "bid") return OrderBookType::bid;
    if (type == "ask") return OrderBookType::ask;
    throw invalid_argument("Invalid OrderBookType");
}

using namespace std;
int main(){
     ifstream csvFile {"data.csv"};
     if (!csvFile.is_open()) {cout<<"Error, File not Opened..."; return 1;}
     string csvLine;

     //Reading 1 line from File
     getline(csvFile, csvLine, '\n');
     cout<<endl<<csvLine<<endl;

     //Tokenising the Lines
     vector <string> tokens = tokenise(csvLine, ',');
     cout<<"\nTokens : ";for (string i : tokens) cout<<i<<"\n"; cout<<"\b\b"<<endl;
     
     //Storing in the respective feilds
     string timeStamp = tokens[0], product = tokens[1]; 
     double price = stod(tokens[3]), amount = stod(tokens[4]);
     OrderBookType orderType = stringToOrderBookType(tokens[2]);

     csvFile.close();
     return 0;
}