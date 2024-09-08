#include <iostream>
#include "CSV Reader.hpp"
using namespace std;

CSV_Reader :: CSV_Reader (){}

vector <string> CSV_Reader::tokenise (const string csvLine, const char seperator){
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

OrderBookType CSV_Reader::stringToOrderBookType(const string& type) {
     if (type == "bid") return OrderBookType::bid;
     if (type == "ask") return OrderBookType::ask;
     throw invalid_argument("Invalid OrderBookType");
}

OrderBookEntry CSV_Reader::stringToOrderBookEntry (const vector <string> &tokens){
     if (tokens.size() != 5) {
          cout<<"\nTokens : ";for (string i : tokens) cout<<i<<" "; cout<<"\b\b"<<endl;
          throw std::invalid_argument("Invalid number of tokens, expected 5.");
     }
     string timeStamp = tokens[0], product = tokens[1];
     double price, amount;
     OrderBookType orderType;
     try {
          price = stod(tokens[3]);
          amount = stod(tokens[4]);
          orderType = stringToOrderBookType(tokens[2]);
     }
     catch(const exception & e){
          throw std::runtime_error("Error converting string to OrderBookEntry: " + std::string(e.what()));
     }
     OrderBookEntry orderBookVecEle (price, amount, timeStamp, product, orderType);
     return orderBookVecEle;
}

vector <OrderBookEntry> CSV_Reader::readCSV (const string csvFileInput){
     vector <OrderBookEntry> entries;
     ifstream csvFile {csvFileInput};
     if (!csvFile.is_open()) throw std::runtime_error("Could not open file: " + csvFileInput);
     string csvLine;
     while(getline(csvFile, csvLine, '\n')){
          OrderBookEntry entry = stringToOrderBookEntry(tokenise(csvLine, ','));
          entries.push_back(entry);
     }
     return entries;
}