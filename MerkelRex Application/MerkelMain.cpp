//MarkelMain Interface Functions Definitions

#include <iostream>
#include "MerkelMain.hpp"
using namespace std;

MerkelMain::MerkelMain(string fileName): fileName(fileName) {
    firstTime = orderbook.getEarliestTime();
} //Constructor for MerkelMain

void MerkelMain::init (){
    currentTime = orderbook.getEarliestTime();
    matchingEngine(orderbook, firstTime);
    while (true){
        printMenu();
        int choice = getUserOption();
        processUserOption(choice);
    }
}

void MerkelMain::printMenu(void){
    clearScreen();
    printLine();
    cout << "\n\t\t\t\t\t\t     MAIN MENU\n";
    printLine();
    cout << "\n\n"
         << Menu << endl;
    return;
}

int MerkelMain::getUserOption(void){
    int iChoice; string sChoice;
    cout << "\nEnter your choice : ";
    try{
        cin >> sChoice;
        iChoice = stoi(sChoice);
    }
    catch (const exception & e){cerr<<"\nError in input given : "<<e.what(); iChoice = 0;}
    cout << endl;
    return iChoice;
}

void MerkelMain::processUserOption(int choice){
    switch (choice){
    case 1:
        helpAndFeedback();
        break;
    case 2:
        exchangeStatus();
        break;
    case 3:
        placeAsk();
        break;
    case 4:
        placeBid();
        break;
    case 5:
        printWallet();
        break;
    case 6:
        continueToNextFrame();
        break;
    default:
        defaultCase();
    }
    printLine();
    sleepForSeconds(2);
    clearScreen();
    return;
}

void MerkelMain::printMarketStats(){
    cout << "\n\t\t\t\t   Market Statistics of "<<currentTime<<endl;
    cout<<"\nProducts : ";
    vector <string> productList = orderbook.getKnownProducts();
    for (string & p : productList){
        cout<<p<<" :"<<endl;
        vector <OrderBookEntry> matchedEntries = orderbook.getOrders(OrderBookType::ask, p, currentTime);
        cout<<"\tNo. of Asks -> "<<matchedEntries.size()<<endl
            <<"\tMax Ask -> "<<OrderBook::getHighPrice(matchedEntries)<<endl
            <<"\tMin Ask -> "<<OrderBook::getLowPrice(matchedEntries)<<endl
            <<"\tSMA of Asks -> "<<OrderBook::simpleMovingAverage(matchedEntries)<<endl
            <<"\tEMA of Asks -> "<<OrderBook::exponentialMovingAverage(matchedEntries)<<endl;
    }
    cout<<"\b\b"<<endl;
    return;
}

OrderBookEntry MerkelMain::BidAsk(int choice) {
    string a, b, product, price, amount, orderType;
    try{
        if (choice == 3) orderType = "ask";
        else orderType = "bid";
        cout <<"\nYou are "<< orderType << "ing of : ";
        cin >> a;
        cout <<"You are "<< orderType << "ing with : ";
        cin >> b;
        product = a + "/" + b;
        cout << "Value of " << a << " " << orderType << "ing : ";
        cin >> price;
        cout << "Value for " << b << " " << orderType << "ing : ";
        cin >> amount;
    } catch (const std::exception & e) {
        // Handle the exception here
        cerr <<endl<< "An error occurred: " << e.what() << endl;
    }
    vector<string> tokens {currentTime, product, orderType, price, amount};
    try {
        OrderBookEntry temp = CSV_Reader::stringToOrderBookEntry(tokens);
        return temp;
    } catch (const std::exception& e) {
        cerr <<endl<< "Error creating OrderBookEntry: " << e.what() << endl;
        // Handle the error as needed, e.g., return a default entry or terminate
        return OrderBookEntry(); // Return a default or invalid entry
    }
}