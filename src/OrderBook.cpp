#include <iostream>
#include "OrderBook.hpp"
#include <unordered_map>
using namespace std;

OrderBook::OrderBook (string fileName){
     entries = CSV_Reader::readCSV(fileName);
} //Blank Constructor for OrderBook class

int OrderBook::getNoOfEntries (void){return entries.size();}

vector <string> OrderBook::getKnownProducts (){
     unordered_map <string, bool> productMap;
     vector <string> productList;
     int noOfEntries = getNoOfEntries();
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

vector <OrderBookEntry *> OrderBook::getOrdersReference (OrderBookType type, string product, string timeStamp){
     vector <OrderBookEntry *> matchedEntries;
     for (OrderBookEntry & entry : entries)
          if (entry.getOrderType() == type && entry.getProduct() == product && entry.getTimeStamp() == timeStamp) matchedEntries.push_back(&entry);
     return matchedEntries;
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

OrderBookEntry * OrderBook :: insertOrder (const OrderBookEntry & entry){
     if (entry == OrderBookEntry ()) return nullptr;
     entries.push_back(entry);
     sort(entries.begin(), entries.end(), OrderBookEntry::compareByTimeStamp);
     for (OrderBookEntry & e : entries)
          if (e == entry) {
               OrderBookEntry* entryReference = &e;
               return entryReference;
          }
     return nullptr;
}

vector <OrderBookEntry> OrderBook::matchAsksToBids(string product, string timeStamp, vector <OrderBookEntry *> & asks, vector <OrderBookEntry *> & bids){
     // Return references to main vector entries to vectors Bids and Asks
     if (asks.empty())
          asks = getOrdersReference(OrderBookType::ask, product, timeStamp);
     if (bids.empty())
          bids = getOrdersReference(OrderBookType::bid, product, timeStamp);
     vector <OrderBookEntry> sales; //Return all Sales Made
     int asksSize = asks.size(), bidsSize = bids.size();
     if (asksSize > 1) 
          sort(asks.begin(), asks.end(), OrderBookEntry::compareByPriceNonIncreasing);
     if (bidsSize > 1) 
          sort(bids.begin(), bids.end(), OrderBookEntry::compareByPriceNonDecreasing);

     for (int i = 0; i < asksSize; i++){
          double curAskPrice {(asks[i])->getPrice()}, curAskAmount {(asks[i])->getAmount()};

          for (int j = 0; j < bidsSize; j++){
               double curBidPrice {(bids[j])->getPrice()}, curBidAmount {(bids[j])->getAmount()};
               if (curBidAmount == 0) continue; // Skip bids that are already fully processed
               if (curBidPrice >= curAskPrice){
                    double salePrice {bids[j]->getPrice()}, saleAmount; //Sale happens at Bidding amount

                    if (curBidAmount == curAskAmount){
                         saleAmount = curAskAmount;
                         sales.push_back(OrderBookEntry{timeStamp, product, OrderBookType::sale, salePrice, saleAmount});
                         (bids[j])->setAmount(0);
                         (asks[i])->setAmount(0);
                         break;
                    }

                    else if (curBidAmount > curAskAmount){
                         saleAmount = curAskAmount;
                         sales.push_back(OrderBookEntry{timeStamp, product, OrderBookType::sale, salePrice, saleAmount});
                         bids[j]->setAmount(curBidAmount - curAskAmount);
                         asks[i]->setAmount(0);
                         break;
                    }
                    
                    else {
                         saleAmount = curBidAmount;
                         sales.push_back(OrderBookEntry{timeStamp, product, OrderBookType::sale, salePrice, saleAmount});
                         bids[j]->setAmount(0);
                         asks[i]->setAmount(curAskAmount - curBidAmount);
                         continue;
                    }
               }
          }
     }
     for (auto itr = entries.begin(); itr != entries.end(); ) 
          if (itr->getAmount() == 0)
               itr = entries.erase(itr);
          else ++itr;
     return sales;
}