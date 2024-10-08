#include <iostream>
#include <vector>
#include "MerkelRex Application\OrderBookEntry.hpp"
using namespace std;

double computeAveragePrice(const vector<OrderBookEntry> &entries){
    if (entries.empty()){
        cerr << "Error: No entries in order books to compute low price.";
        return 0.0; // Handle empty vector scenario
    }
    double sum{0};
    int size = entries.size();
    for (OrderBookEntry i : entries)
        sum += i.getPrice();
    return (sum / size);
}

double computeHighPrice(const vector<OrderBookEntry> &entries){
    if (entries.empty()){
        cerr << "Error: No entries in order books to compute low price.";
        return 0.0; // Handle empty vector scenario
    }
    double max{numeric_limits<double>::lowest()};
    for (OrderBookEntry i : entries)
        if (max < i.getPrice())
            max = i.getPrice();
    return max;
}

double computeLowPrice(const vector<OrderBookEntry> &entries){
    if (entries.empty()){
        cerr << "Error: No entries in order books to compute low price.";
        return 0.0; // Handle empty vector scenario
    }
    double min{numeric_limits<double>::max()};
    for (OrderBookEntry i : entries)
        if (min > i.getPrice())
            min = i.getPrice();
    return min;
}

double computePriceSpread(const vector<OrderBookEntry> &entries){
    if (entries.empty()){
        cerr << "Error: No entries in order books to compute low price.";
        return 0.0; // Handle empty vector scenario
    }
    double min{computeLowPrice(entries)}, max{computeHighPrice(entries)};
    return (max - min);
}

vector <int> noOfBid_Ask (const vector<OrderBookEntry> &entries){
    if (entries.empty()){
        cerr << "Error: No entries in order books to compute low price.";
        return {0, 0}; // Handle empty vector scenario
    }
    int bids{0}, asks{0};
    for (OrderBookEntry i : entries){
        if (i.getOrderType() == OrderBookType::ask) asks++;
        else bids++;
    }
    return {bids, asks};
}