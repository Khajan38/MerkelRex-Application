#include <iostream>
#include "MerkelRex Engine.hpp"
using namespace std;

void matchingEngine (OrderBook & orderbook, string currentTime){
     char choice;
     cout<<"\nDo you want to run the Matching Engine to clear previous (if any) Asks and Bids (Y/N) : ";
     cin>> choice;
     if (choice == 'N') return;
     Display::Header("MATCHING ENGINE : MATCHING PENDING BIDS AND BIDS");
     vector <string> products = orderbook.getKnownProducts();
     for (string & product : products){
          cout<<endl<<product<<" :"<<endl;
          vector <OrderBookEntry *> asks, bids;
          vector <OrderBookEntry> sales = orderbook.matchAsksToBids(product, currentTime, asks, bids);
          cout<<"\tNo. of Sales -> "<<sales.size()<<endl
            <<"\tMax Sale -> "<<OrderBook::getHighPrice(sales)<<endl
            <<"\tMin Sale -> "<<OrderBook::getLowPrice(sales)<<endl
            <<"\tSMA of Sales -> "<<OrderBook::simpleMovingAverage(sales)<<endl
            <<"\tEMA of Sales -> "<<OrderBook::exponentialMovingAverage(sales)<<endl;
     }
     cin.ignore(INT_MAX, '\n');
     Display::Bottom_Line(3);
}

vector <double> newBidAskEngine (OrderBook & orderbook, string currentTime, OrderBookEntry * &entry){
     if (entry == nullptr) return {0, 0};
     vector <OrderBookEntry *> asks, bids;
     if (entry->getOrderType() == OrderBookType::ask) asks.push_back(entry);
     else bids.push_back(entry);
     vector <OrderBookEntry> sales = orderbook.matchAsksToBids(entry->getProduct(), currentTime, asks, bids);
     cout<<endl<<padding("SALES", consoleWidth)<<"SALES"<<endl<<endl;
     cout<<"No. of Sales -> "<<sales.size()<<endl
          <<"Max Sale -> "<<OrderBook::getHighPrice(sales)<<endl
          <<"Min Sale -> "<<OrderBook::getLowPrice(sales)<<endl
          <<"SMA of Sales -> "<<OrderBook::simpleMovingAverage(sales)<<endl
          <<"EMA of Sales -> "<<OrderBook::exponentialMovingAverage(sales)<<endl;
     double totalAmount{0}, totalCurrAmount{0};
     for (OrderBookEntry & e : sales) {
          totalCurrAmount += e.getAmount() * e.getPrice();
          totalAmount += e.getAmount();
     }
     return {totalAmount, totalCurrAmount};
}

vector <string> callToknise (const string csvLine, const char seperator){
     vector <string> tokens = CSV_Reader::tokenise (csvLine, seperator);
     return tokens;
}