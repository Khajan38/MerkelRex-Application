//MarkelMain Interface Functions

#pragma once
#include <iostream>
#include <vector>
#include "Display Basics.hpp"
#include "OrderBookEntry.hpp"
#include "OrderBook.hpp"
#include "MerkelRex Engine.hpp"
#include "Wallet.hpp"
using namespace std;

class MerkelMain{
    string fileName;
    OrderBook orderbook {fileName};
    WalletClass Wallet;
    string currentTime, firstTime;

public:
    MerkelMain(string fileName = "data.csv");
    void init(); //Call the Program from here
    void processUserOption(int choice);
    OrderBookEntry BidAsk(int choice);
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