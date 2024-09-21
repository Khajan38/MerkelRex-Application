#include <iostream>
#include "..\include\Display Basics.hpp"
#include "..\include\OrderBookEntry.hpp"
using namespace std;

//display was made just to check if all entries were properly made
void display(const vector<OrderBookEntry> &entries){
    Display::printLine();
    cout << "\n\t\t\t\t\t\tORDER BOOK DATABASE\n";
    Display::printLine();
    cout <<endl;
    if (entries.size() == 0){
        cout << "\nNo entries in Order Books DataBase..." << endl;
        return;
    }
    int count = 1;
    cout << endl;
    for (vector<OrderBookEntry>::const_iterator itr = entries.begin(); itr != entries.end(); itr++, count++)
        cout << count << ". " << itr->timeStamp << "," << itr->product << "," << ((static_cast<int>(itr->orderType)) ? "ask" : "bid") << "," << itr->price << "," << itr->amount << endl;
    cout << "\n\t\t\t\t        Press any key to continue " << flush;
    char pause;
    cin >> pause;
    Display::printLine();
    Display::sleepForSeconds(2);
    Display::clearScreen();
    return;
}