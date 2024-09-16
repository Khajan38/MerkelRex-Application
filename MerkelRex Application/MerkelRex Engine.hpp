#pragma once
#include <iostream>
#include <vector>
#include "OrderBookEntry.hpp"
#include "OrderBook.hpp"
using namespace std;

void matchingEngine (OrderBook & orderbook, string currentTime);
vector <double>  newBidAskEngine (OrderBook & orderbook, string currentTime, OrderBookEntry * &entry);
vector <string> callToknise (const string csvLine, const char seperator);