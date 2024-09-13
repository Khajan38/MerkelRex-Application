#pragma once
#include <iostream>
#include "OrderBookEntry.hpp"
#include "CSV Reader.hpp"
using namespace std;

class OrderBook {
          vector <OrderBookEntry> entries;
     public :
          int noOfEntries;
          OrderBook (string fileName);
          vector <string> getKnownProducts ();
          vector <OrderBookEntry> getOrders (OrderBookType type, string product, string timeStamp);
          void BidAsk (const OrderBookEntry & entry);
          static double getHighPrice (vector <OrderBookEntry> &matchedEntries);
          static double getLowPrice (vector <OrderBookEntry> &matchedEntries);
          string getEarliestTime (void);
          string getNextTime (string currentTime);
};