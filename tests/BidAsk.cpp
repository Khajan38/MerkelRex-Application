#include <iostream>
#include "..\include\Display Basics.hpp"
#include "..\include\OrderBookEntry.hpp"
using namespace std;

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