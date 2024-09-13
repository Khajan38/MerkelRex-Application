#include <iostream>
#include "OrderBook.hpp"
#include <unordered_map>
using namespace std;

OrderBook::OrderBook (string fileName){
     entries = CSV_Reader::readCSV("data.csv");
     noOfEntries = entries.size();
} //Blank Constructor for OrderBook class

vector <string> OrderBook::getKnownProducts (){
     unordered_map <string, bool> productMap;
     vector <string> productList;
     for (int i = 0; i < noOfEntries; i++)
          productMap[entries[i].getProduct()] = true;
     for (pair <string, bool> i : productMap)
          productList.push_back(i.first);
     return productList;
}

vector <OrderBookEntry> OrderBook::getOrders (OrderBookType type, string product, string timeStamp){
     vector <OrderBookEntry> matchedEntries;
     for (OrderBookEntry & entry : entries)
          if (entry.getOrderType() == type && entry.getProduct() == product && entry.getTimeStamp() == timeStamp) matchedEntries.push_back(entry);
     return matchedEntries;
}

void OrderBook::BidAsk (const OrderBookEntry & entry){
     entries.push_back(entry);
     return;
}

double OrderBook::getHighPrice (vector <OrderBookEntry> &matchedEntries){
     if (matchedEntries.empty()) return 0.0;
     double maxPrice {matchedEntries[0].getPrice()};
     for (OrderBookEntry & entry : matchedEntries){
          double curPrice = entry.getPrice();
          if (curPrice >  maxPrice) maxPrice = curPrice;
     }
     return maxPrice;
}

double OrderBook::getLowPrice (vector <OrderBookEntry> &matchedEntries){
     if (matchedEntries.empty()) return 0.0;
     double minPrice {matchedEntries[0].getPrice()};
     for (OrderBookEntry & entry : matchedEntries){
          double curPrice = entry.getPrice();
          if (curPrice <  minPrice) minPrice = curPrice;
     }
     return minPrice;
}

string OrderBook::getEarliestTime (){
     return entries[0].getTimeStamp();
}

string OrderBook::getNextTime (string currentTime){
     for (OrderBookEntry entry : entries){
          string nextTimeStamp = entry.getTimeStamp();
          if (nextTimeStamp > currentTime) return nextTimeStamp;
     }
     return entries[0].getTimeStamp();
}