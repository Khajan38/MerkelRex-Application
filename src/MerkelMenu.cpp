#include <iostream>
#include "MerkelMain.hpp"
using namespace std;

void MerkelMain::exchangeStatus(){
     Display::Header("EXCHANGE STATUS WINDOW");
     printMarketStats();    
     return;
}

void MerkelMain::placeAsk (){
     Display::Header("PLACE AN ASK WINDOW");
     OrderBookEntry entry = BidAsk(3);
     if (Wallet.canFullfillOrder(entry)){
          OrderBookEntry * entryReference = orderbook.insertOrder(entry);
          vector <double> sales = newBidAskEngine(orderbook, currentTime, entryReference);
          vector <string> currencies = callToknise(entry.getProduct(), '/');
          cout<<endl; //Formatting
          Wallet.removeCurrency(currencies[0], sales[0]);
          Wallet.insertCurrency(currencies[1], sales[1]);
     }
     return;
}

void MerkelMain::placeBid(){
     Display::Header("PLACE AN BID WINDOW");
     OrderBookEntry entry = BidAsk(4);
     if (Wallet.canFullfillOrder(entry)){
          OrderBookEntry * entryReference = orderbook.insertOrder(entry);
          vector <double> sales = newBidAskEngine(orderbook, currentTime, entryReference);
          vector <string> currencies = callToknise(entry.getProduct(), '/');
          cout<<endl; //Formatting
          Wallet.removeCurrency(currencies[1], sales[1]);
          Wallet.insertCurrency(currencies[0], sales[0]);
     }
     return;
}

void MerkelMain::printWallet(){
     Display::Header("YOUR WALLET");
     string currencies = Wallet.toString();
     if (currencies == "") {cout<<endl<<padding("Wallet is Empty...", consoleWidth)<<"Wallet is Empty..."<<endl; return;}
     string paddingRows = padding("|   CURRENCIES   |       AMOUNT       |", consoleWidth);
     cout<<format("\n\n{}---------------------------------------\n", paddingRows)
         <<format("{}|   CURRENCIES   |       AMOUNT       |\n", paddingRows)
         <<format("{}---------------------------------------", paddingRows);
     currencies += format("{}---------------------------------------\n\n", paddingRows);
     cout<<endl<<currencies;
     return;
}

void MerkelMain::continueToNextFrame(){
     Display::printLine();
     cout <<endl<<padding("Continuing, Going to the next frame...", consoleWidth)
          <<"Continuing, Going to the next frame..." << endl<<endl
          << "Current Time is : "<<currentTime<<endl;
     currentTime = orderbook.getNextTime(currentTime);
     cout<<endl<<"Next Time is : "<<currentTime<<endl;
     matchingEngine(orderbook, currentTime);
     return;
}

void MerkelMain::defaultCase(){
     char exitChoice = 'Y';
     cout <<endl<<padding("Enter a valid choice...", consoleWidth)<<"Enter a valid choice..."<< endl;
     return;
}