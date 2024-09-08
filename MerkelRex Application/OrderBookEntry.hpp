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

enum class OrderBookType : int{bid = 0, ask = 1};

class OrderBookEntry{
    //Private Members
    double price, amount;
    string timeStamp, product;
    OrderBookType orderType;
    friend void display(const vector<OrderBookEntry> &entries);
    //Iterating over vector values
public:
    OrderBookEntry(double price, double amount, string timeStamp, string product, OrderBookType orderType); //Constructor
    OrderBookEntry(); //Blank Constructor
    double getPrice(void);
    double getAmount(void);
    OrderBookType getOrderType (void);
};