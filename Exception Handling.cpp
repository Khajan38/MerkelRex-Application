#include <iostream>
#include <exception>
#include "Tokenising test.cpp"
using namespace std;

enum class OrderBookType : int {bid = 0, ask = 1};
// Function to convert a string to an OrderBookType enum
OrderBookType stringToOrderBookType(const string& type) {
    if (type == "bid") return OrderBookType::bid;
    if (type == "ask") return OrderBookType::ask;
    throw invalid_argument("Invalid OrderBookType");
}

int main(){
     string csvLine1 = "2020/03/17 17:01:24.884492,ETH/BTC,bid,0.02187308,7.44564869";
     string csvLine2 = "2020/03/17 17:01:24.884492,ETH/BTC,bid,0.0a187308,a.44564869"; //Bad Float

     //Tokenising the Lines
     vector <string> tokens = tokenise(csvLine2, ',');
     cout<<"\nTokens : ";for (string i : tokens) cout<<i<<","; cout<<"\b\b\b"<<endl;
     
     //Storing in the respective feilds
     string timeStamp = tokens[0], product = tokens[1]; 
     cout<<"\nTimestamp : "<<timeStamp<<endl
         <<"Products : "<<product<<endl;
     try {
          double price = stod(tokens[3]);
          double amount = stod(tokens[4]);
          cout<<"\nPrice : "<<price<<endl
         <<"Amount : "<<amount<<endl;
     }
     catch(exception & e){
          cout<<"Bad Float..."<<endl;
     }
     OrderBookType orderType = stringToOrderBookType(tokens[2]);
     cout<<"Order Type : "<<tokens[2]<<endl;

     return 0;
}