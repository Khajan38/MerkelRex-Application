//MarkelMain Interface Functions Definitions

#include <iostream>
#include "MerkelMain.hpp"
#include "Statistical Functions.hpp"
using namespace std;

MerkelMain::MerkelMain(){} 
//Blank Constructor for MerkelMain

void MerkelMain::init (){
    while (true){
        printMenu();
        int choice = getUserOption();
        processUserOption(choice, entries);
    }
}

void MerkelMain::printMenu(void){
    printLine();
    cout << "\n\t\t\t\t\t\t     MAIN MENU\n";
    printLine();
    cout << "\n\n"
         << Menu << endl;
    return;
}

int MerkelMain::getUserOption(void){
    int choice;
    cout << "\nEnter your choice : ";
    cin >> choice;
    cout << endl;
    return choice;
}

OrderBookEntry MerkelMain::BidAsk(int choice){
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

void MerkelMain::processUserOption(int choice, vector<OrderBookEntry> &entries){
    switch (choice){
    case 1:
        cout << "Help - choose options from the menu" << endl
             << "and follow the on screen instructions." << endl;
        break;
    case 2:
        cout << "You chose for printing Exhange Status..." << endl;
        break;
    case 3:
        cout << "You chose for placing an Ask..." << endl;
        entries.push_back(MerkelMain::BidAsk(choice));
        break;
    case 4:
        cout << "You chose for placing a Bid..." << endl;
        entries.push_back(BidAsk(choice));
        break;
    case 5:
        cout << "You chose for printing Wallet..." << endl;
        break;
    case 6:
        cout << "Continuing, Going to the next frame..." << endl;
        break;
    default:{
        char exitChoice = 'Y';
        cout << "Enter a valid choice..." << endl
             << endl
             << "Do you want to exit from the program (Y/N)? : ";
        cin >> exitChoice;
        if (exitChoice == 89 || exitChoice == 121){ 
            //exitChoice = 'Y' or 'y'
            cout << "\n\t\t\t   Exiting, Thank you for using our MerkleRex application..." << endl;
            printLine();
            sleepForSeconds(2);
            clearScreen();
            exit(2);
        }
        else
            cout << "\n\t\t\t\t       Continuing, Going to the next frame..." << endl;
    }
    }
    printLine();
    char menuChoice{'M'};
    cout << "\n\t\t     Press M to goto Menu or any other key to look Order Book DataBase : ";
    cin >> menuChoice;
    sleepForSeconds(2);
    clearScreen();
    if (menuChoice != 'M') loadOrderBook(entries, this);
    return;
}

void loadOrderBook (const vector <OrderBookEntry> & entries, MerkelMain * thisptr){
    printLine();
    cout << "\n\t\t\t\t\t\tORDER BOOK DATABASE\n";
    printLine();
    cout <<endl;
    display(entries);
    thisptr->printMarketStats();
    cout << "\n\t\t\t\t        Press any key to continue " << flush;
    char pause;
    cin >> pause;
    printLine();
    sleepForSeconds(2);
    clearScreen();
}

void display(const vector<OrderBookEntry> &entries){
    if (entries.size() == 0){
        cout << "\nNo entries in Order Books DataBase..." << endl;
        return;
    }
    //2020/03/17 17:01:24.884492,ETH/BTC,bid,0.02186299,0.1
    //2020/03/17 17:01:24.884492,BTC/ETH,ask,0.1,0.02186299
    int count = 1;
    cout << endl;
    for (vector<OrderBookEntry>::const_iterator itr = entries.begin(); itr != entries.end(); itr++, count++)
        cout << count << ". " << itr->timeStamp << "," << itr->product << "," << ((static_cast<int>(itr->orderType)) ? "ask" : "bid") << "," << itr->price << "," << itr->amount << endl;
    return;
}

void MerkelMain::printMarketStats(){
    cout << "\nMarket Statistics : "<<endl;
    cout << "\nAverage Price : " << computeAveragePrice(entries) << endl
         << "Highest Price : " << computeHighPrice(entries) << endl
         << "Lowest Price : " << computeLowPrice(entries) << endl
         << "Price Spread : " << computePriceSpread(entries) << endl;
    return;
}