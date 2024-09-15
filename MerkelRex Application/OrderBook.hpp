#pragma once
#include <iostream>
#include <algorithm>
#include "OrderBookEntry.hpp"
#include "CSV Reader.hpp"
using namespace std;

class OrderBook {
          vector <OrderBookEntry> entries;
     public :
          OrderBook (string fileName);
          int getNoOfEntries (void);
          vector <string> getKnownProducts (void);
          vector <OrderBookEntry> getOrders (OrderBookType type, string product, string timeStamp);
          vector <OrderBookEntry *> getOrdersReference (OrderBookType type, string product, string timeStamp);
          OrderBookEntry * insertOrder (const OrderBookEntry & entry);
          vector <OrderBookEntry> matchAsksToBids(string product, string timeStamp, vector <OrderBookEntry *> & asks, vector <OrderBookEntry *> &bids);

          //Statistical Functions
          static double getHighPrice (vector <OrderBookEntry> &matchedEntries);
          static double getLowPrice (vector <OrderBookEntry> &matchedEntries);
          static double simpleMovingAverage (vector <OrderBookEntry> &matchedEntries);
          static double exponentialMovingAverage (vector <OrderBookEntry> &matchedEntries);

          //Switching Time Frames
          string getEarliestTime (void);
          string getNextTime (string currentTime);

          //Intially made to test out the code, Present in the Supplementary Test Functions.cpp
          //friend OrderBookEntry BidAsk(int choice); //Taking Asking or Bidding values
          //friend void display(const vector<OrderBookEntry> &entries);
};