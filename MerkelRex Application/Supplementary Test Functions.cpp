#include <iostream>
#include "OrderBookEntry.hpp"
using namespace std;

//display was made just to check if all entries were properly made
void display(const vector<OrderBookEntry> &entries){
    printLine();
    cout << "\n\t\t\t\t\t\tORDER BOOK DATABASE\n";
    printLine();
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
    printLine();
    sleepForSeconds(2);
    clearScreen();
    return;
}

//Asking for Bids or Ask : Initial Approach
OrderBookEntry BidAsk(int choice){
    string a, b, timeStamp, product, type;
    double price, amount;
    OrderBookType orderType;
    if (choice == 3){
        type = "Selling";
        orderType = OrderBookType::ask;
    }
    else{
        type = "Bidding", orderType = OrderBookType::bid;
    }
    cout << "\nEnter the Date of Purchase (Format : 2020/03/17) : ";
    cin >> a;
    cout << "Enter the Time of Purchase (Format : 17:01:24.884492) : ";
    cin >> b;
    timeStamp = a + " " + b;
    cout << type << " of : ";
    cin >> a;
    cout << type << " with : ";
    cin >> b;
    product = a + "/" + b;
    cout << "Value of " << a << " " << type << " : ";
    cin >> price;
    cout << "Value for " << b << " " << type << " : ";
    cin >> amount;
    OrderBookEntry temp(price, amount, timeStamp, product, orderType);
    return temp;
}