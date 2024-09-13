//MarkelMain Interface Functions

#pragma once
#include <iostream>
#include <vector>
#include "OrderBookEntry.hpp"
#include "CSV Reader.hpp"
#include "OrderBook.hpp"
using namespace std;

class MerkelMain{
    //Creating a Raw Strings of Menu Items
    string Menu = R"delimiter(1 : Print help
2 : Print exchange stats
3 : Place an ask
4 : Place a bid
5 : Print wallet
6 : Continue )delimiter";
    OrderBook orderbook {"data.csv"};
    string currentTime;

public:
    MerkelMain();
    void init(); //Call the Program from here
    void printMenu(void);
    int getUserOption(void);
    OrderBookEntry BidAsk(int choice); //Taking Asking or Bidding values
    void processUserOption(int choice);
    friend void display(const vector<OrderBookEntry> &entries);
    void printMarketStats(); //For Statistical Functions
};