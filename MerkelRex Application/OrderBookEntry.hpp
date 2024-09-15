//OrderBookEntry class and some pre-requisite functions

#pragma once
#include <thread>
#include <chrono>
#include <limits>
#include <vector>
using namespace std;

//Some needed functions
string line();
void printLine();
void sleepForSeconds(int timed);
void clearScreen();

enum class OrderBookType : int{bid = 0, ask = 1, sale = 2};

class OrderBookEntry{
    //Private Members
    double price, amount;
    string timeStamp, product;
    OrderBookType orderType;
    friend void display(const vector<OrderBookEntry> &entries);
public:
    explicit OrderBookEntry(double price, double amount, string timeStamp, string product, OrderBookType orderType); //Constructor
    explicit OrderBookEntry(string timeStamp, string product, OrderBookType orderType, double price, double amount);
    explicit OrderBookEntry(); //Blank Constructor
    void display (void);
    double getPrice(void);
    double getAmount(void);
    void setAmount (double Amount);
    OrderBookType getOrderType (void);
    string getProduct (void);
    string getTimeStamp (void);

    //Operator Overloading of == 
    friend bool operator == (const OrderBookEntry & e1, const OrderBookEntry & e2);

    //Sorting Functions
    static bool compareByTimeStamp (OrderBookEntry &e1, OrderBookEntry &e2);
    static bool compareByPriceNonDecreasing(const OrderBookEntry* e1, const OrderBookEntry* e2);
    static bool compareByPriceNonIncreasing (const OrderBookEntry *e1, const OrderBookEntry *e2);
};