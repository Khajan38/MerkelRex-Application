//OrderBookEntry.h Implementations

#include <iostream>
#include "OrderBookEntry.hpp"
using namespace std;

std::string line(){return string(117, '=');}

void printLine(){cout << endl << line() <<endl;}

void sleepForSeconds(int timed){std::this_thread::sleep_for(std::chrono::seconds(timed));}

void clearScreen(){
    #ifdef _WIN32
        system("cls"); // For Windows
    #else
        system("clear"); // For Linux and MacOS
    #endif
}

OrderBookEntry::OrderBookEntry(double price, double amount, string timeStamp, string product, OrderBookType orderType) : price(price), amount(amount), timeStamp(timeStamp), product(product), orderType(orderType) {}
OrderBookEntry::OrderBookEntry() {} //Blank Constructor
double OrderBookEntry::getPrice(void) { return this->price; }
double OrderBookEntry::getAmount(void) { return this->amount; }
OrderBookType OrderBookEntry::getOrderType (void) { return this->orderType; }