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
OrderBookEntry::OrderBookEntry(string timeStamp, string product, OrderBookType orderType, double price, double amount) : price(price), amount(amount), timeStamp(timeStamp), product(product), orderType(orderType) {}
OrderBookEntry::OrderBookEntry() {} //Blank Constructor
double OrderBookEntry::getPrice(void) { return this->price; }
double OrderBookEntry::getAmount(void) { return this->amount; }
void OrderBookEntry::setAmount (double amount) {this->amount = amount;}
OrderBookType OrderBookEntry::getOrderType (void) { return this->orderType; }
string OrderBookEntry::getProduct (void) { return this->product; }
string OrderBookEntry::getTimeStamp (void) { return this->timeStamp; }

void OrderBookEntry::display (void){
    cout<<timeStamp << "," << product << "," << ((static_cast<int>(orderType)) ? "ask" : "bid") << "," << price << "," << amount << endl;
    return;
}

bool OrderBookEntry::compareByTimeStamp (OrderBookEntry &e1, OrderBookEntry &e2){
    return e1.timeStamp < e2.timeStamp;
}

bool OrderBookEntry::compareByPriceNonDecreasing(const OrderBookEntry* e1, const OrderBookEntry* e2) {
    return e1->price < e2->price; // Use < for non-decreasing order
}
bool OrderBookEntry::compareByPriceNonIncreasing (const OrderBookEntry *e1, const OrderBookEntry *e2){
    return e1->price > e2->price; // Use > for non-increasing order
}

bool operator == (const OrderBookEntry & e1, const OrderBookEntry & e2){
    if (e1.timeStamp != e2.timeStamp) return false;
    if (e1.product != e2.product) return false;
    if (e1.orderType != e2.orderType) return false;
    if (e1.price != e2.price) return false;
    if (e1.amount != e2.amount) return false;
    return true;
}