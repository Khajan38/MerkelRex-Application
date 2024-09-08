#pragma once
#include <iostream>
#include <fstream>
#include "OrderBookEntry.hpp"
using namespace std;

class CSV_Reader{
          static OrderBookType stringToOrderBookType(const string& type);
          static vector <string> tokenise (const string csvLine, const char seperator);
          static OrderBookEntry stringToOrderBookEntry (const vector <string> &tokens);
     public :
          CSV_Reader();
          static vector <OrderBookEntry> readCSV (const string csvFileInput);
};