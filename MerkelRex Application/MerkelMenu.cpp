#include <iostream>
#include "MerkelMain.hpp"
using namespace std;

void MerkelMain::helpAndFeedback(){
     cout << "Help - choose options from the menu" << endl
          << "and follow the on screen instructions." << endl;
     return;
}

void MerkelMain::exchangeStatus(){
     cout << "You chose for printing Exhange Status..." << endl;
     printMarketStats();    
     cout << "\n\t\t\t\t\t     Press any key to continue " << flush;
     cin.ignore(INT_MAX, '\n');
     cin.get();
     return;
}

void MerkelMain::placeAsk (){
     cout << "You chose for placing an Ask..." << endl;
     OrderBookEntry entry = BidAsk(3);
     if (Wallet.canFullfillOrder(entry)){
          OrderBookEntry * entryReference = orderbook.insertOrder(entry);
          vector <double> sales = newBidAskEngine(orderbook, currentTime, entryReference);
          vector <string> currencies = callToknise(entry.getProduct(), '/');
          cout<<sales[0]<<" "<<sales[1]; cout<<endl;
          Wallet.removeCurrency(currencies[0], sales[0]);
          Wallet.insertCurrency(currencies[1], sales[1]);
     }
     printLine;
     cout << "\n\t\t\t\t\t     Press any key to continue ";
     cin.ignore(INT_MAX, '\n');
     cin.get();
     return;
}

void MerkelMain::placeBid(){
     cout << "You chose for placing a Bid..." << endl;
     OrderBookEntry entry = BidAsk(4);
     if (Wallet.canFullfillOrder(entry)){
          OrderBookEntry * entryReference = orderbook.insertOrder(entry);
          vector <double> sales = newBidAskEngine(orderbook, currentTime, entryReference);
          vector <string> currencies = callToknise(entry.getProduct(), '/');
          cout<<sales[0]<<" "<<sales[1]; cout<<endl;
          Wallet.removeCurrency(currencies[1], sales[1]);
          Wallet.insertCurrency(currencies[0], sales[0]);
     }
     printLine;
     cout << "\n\t\t\t\t\t     Press any key to continue ";
     cin.ignore(INT_MAX, '\n');
     cin.get();
     return;
}

void MerkelMain::printWallet(){
     cout << "Wallet : " << endl;
     string currencies = Wallet.toString();
     if (currencies == "") cout<<"Wallet is Empty...";
     else cout<<endl<<currencies;
     return;
}

void MerkelMain::continueToNextFrame(){
     cout << "Continuing, Going to the next frame..." << endl<<endl
          << "Current Time is : "<<currentTime<<endl;
     currentTime = orderbook.getNextTime(currentTime);
     cout<< "Next Time is : "<<currentTime<<endl;
     matchingEngine(orderbook, currentTime);
     return;
}

void MerkelMain::defaultCase(){
     char exitChoice = 'Y';
     cout << "Enter a valid choice..." << endl
          << endl
          << "Do you want to exit from the program (Y/N)? : ";
     cin >> exitChoice;
     if (exitChoice == 89 || exitChoice == 121){ //exitChoice = 'Y' or 'y'
          cout << "\n\t\t\t   Exiting, Thank you for using our MerkleRex application..." << endl;
          printLine();
          sleepForSeconds(2);
          clearScreen();
          exit(2);
     }
     else cout << "\n\t\t\t\t       Continuing, Going to the Main Menu..." << endl;
     return;
}
