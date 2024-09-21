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
        int choice = Display::Main_Menu();
        processUserOption(choice);
    }
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
    case 7:
        Display::Exiting_Window();
    default:
        defaultCase();
    }
    if (choice != 6) Display::Bottom_Line(2);
    return;
}

void MerkelMain::printMarketStats(){
    cout <<endl<<padding("MARKET STATISTICS OF "+currentTime, consoleWidth)<<"MARKET STATISTICS OF "<<currentTime<<endl;
    vector <string> productList = orderbook.getKnownProducts();
    for (string & p : productList){
        cout<<endl<<p<<" :"<<endl;
        vector <OrderBookEntry> matchedEntries = orderbook.getOrders(OrderBookType::ask, p, currentTime);
        cout<<"\tNo. of Asks -> "<<matchedEntries.size()<<endl
            <<"\tMax Ask -> "<<OrderBook::getHighPrice(matchedEntries)<<endl
            <<"\tMin Ask -> "<<OrderBook::getLowPrice(matchedEntries)<<endl
            <<"\tSMA of Asks -> "<<OrderBook::simpleMovingAverage(matchedEntries)<<endl
            <<"\tEMA of Asks -> "<<OrderBook::exponentialMovingAverage(matchedEntries)<<endl;
    }
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
        cout << "Price of " <<b<<" per "<< a << " " << orderType << "ing : ";
        cin >> price;
        cout << "Amount of "<<a<<" " << orderType << "ed : ";
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