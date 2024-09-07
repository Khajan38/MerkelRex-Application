#pragma once
#include <iostream>
#include <vector>
#include "OrderBookEntry.hpp"
using namespace std;

double computeAveragePrice(const vector<OrderBookEntry> &entries);
double computeLowPrice(const vector<OrderBookEntry> &entries);
double computeHighPrice(const vector<OrderBookEntry> &entries);
double computePriceSpread(const vector<OrderBookEntry> &entries);