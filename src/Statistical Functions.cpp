#include <iostream>
#include "OrderBook.hpp"
using namespace std;

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

double OrderBook::simpleMovingAverage (vector <OrderBookEntry> &matchedEntries){
     if (matchedEntries.empty()) return 0.0;
     double averagePrice {0};
     for (OrderBookEntry & entry : matchedEntries)
          averagePrice += entry.getPrice();
     averagePrice /= matchedEntries.size();
     return averagePrice;
}

double OrderBook::exponentialMovingAverage (vector <OrderBookEntry> &matchedEntries){
     if (matchedEntries.empty()) return 0.0;
     int size = matchedEntries.size(); 
     double alpha = 2.0/(size + 1); 
     double EMA = matchedEntries[0].getPrice();
     for (int i = 1; i < size; ++i)
          EMA = alpha * (matchedEntries[i].getPrice() - EMA) + EMA;
     return EMA;
}