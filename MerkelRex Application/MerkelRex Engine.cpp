#include <iostream>
#include "MerkelRex Engine.hpp"
using namespace std;

void matchingEngine (OrderBook & orderbook, string currentTime){
     char choice;
     cout<<"\nDo you want to run the Matching Engine to clear previous (if any) Asks and Bids (Y/N) : ";
     cin>> choice;
     if (choice == 'N') return;
     clearScreen();
     printLine();
     cout << "\n\t\t\t\t\tMATCHING PENDING BIDS AND BIDS\n";
     printLine(); cout<<endl;
     vector <string> products = orderbook.getKnownProducts();
     for (string & product : products){
          cout<<product<<" :"<<endl;
          vector <OrderBookEntry *> asks, bids;
          vector <OrderBookEntry> sales = orderbook.matchAsksToBids(product, currentTime, asks, bids);
          cout<<"\tNo. of Sales -> "<<sales.size()<<endl
            <<"\tMax Sale -> "<<OrderBook::getHighPrice(sales)<<endl
            <<"\tMin Sale -> "<<OrderBook::getLowPrice(sales)<<endl
            <<"\tSMA of Sales -> "<<OrderBook::simpleMovingAverage(sales)<<endl
            <<"\tEMA of Sales -> "<<OrderBook::exponentialMovingAverage(sales)<<endl;
     }
     printLine;
     cout << "\n\t\t\t\t\t     Press any key to continue ";
     cin.ignore(INT_MAX, '\n');
     cin.get();
}

void newBidAskEngine (OrderBook & orderbook, string currentTime, OrderBookEntry * &entry){
     if (entry == nullptr) return;
     vector <OrderBookEntry *> asks, bids;
     if (entry->getOrderType() == OrderBookType::ask) asks.push_back(entry);
     else bids.push_back(entry);
     vector <OrderBookEntry> sales = orderbook.matchAsksToBids(entry->getProduct(), currentTime, asks, bids);
     cout<<endl<<"Sales :"<<endl;
     cout<<"\tNo. of Sales -> "<<sales.size()<<endl
          <<"\tMax Sale -> "<<OrderBook::getHighPrice(sales)<<endl
          <<"\tMin Sale -> "<<OrderBook::getLowPrice(sales)<<endl
          <<"\tSMA of Sales -> "<<OrderBook::simpleMovingAverage(sales)<<endl
          <<"\tEMA of Sales -> "<<OrderBook::exponentialMovingAverage(sales)<<endl;
     printLine;
     cout << "\n\t\t\t\t\t     Press any key to continue ";
     cin.ignore(INT_MAX, '\n');
     cin.get();
}

vector <string> callToknise (const string csvLine, const char seperator){
     vector <string> tokens = CSV_Reader::tokenise (csvLine, seperator);
     return tokens;
}