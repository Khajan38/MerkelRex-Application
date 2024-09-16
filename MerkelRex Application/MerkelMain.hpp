//MarkelMain Interface Functions

#pragma once
#include <iostream>
#include <vector>
#include "OrderBookEntry.hpp"
#include "OrderBook.hpp"
#include "MerkelRex Engine.hpp"
#include "Wallet.hpp"
using namespace std;

class MerkelMain{
    //Creating a Raw Strings of Menu Items
    string Menu = R"delimiter(1 : Print help
2 : Print exchange stats
3 : Place an ask
4 : Place a bid
5 : Print wallet
6 : Continue )delimiter";
    string fileName;
    OrderBook orderbook {fileName};
    WalletClass Wallet;
    string currentTime, firstTime;

public:
    MerkelMain(string fileName = "data.csv");
    void init(); //Call the Program from here
    void printMenu(void);
    int getUserOption(void);
    OrderBookEntry BidAsk(int choice);
    void processUserOption(int choice);
    void printMarketStats(); //For Statistical Functions

    //Menu Options Functions
    void helpAndFeedback(void);
    void exchangeStatus(void);
    void placeAsk(void);
    void placeBid(void);
    void printWallet(void);
    void continueToNextFrame(void);
    void defaultCase (void);
};