//MarkelMain Interface Functions Definitions

#include <iostream>
#include "MerkelMain.hpp"
using namespace std;

MerkelMain::MerkelMain(){} 
//Blank Constructor for MerkelMain

void MerkelMain::init (){
    currentTime = orderbook.getEarliestTime();
    while (true){
        printMenu();
        int choice = getUserOption();
        processUserOption(choice);
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

void MerkelMain::processUserOption(int choice){
    switch (choice){
    case 1:
        cout << "Help - choose options from the menu" << endl
             << "and follow the on screen instructions." << endl;
        break;
    case 2:
        cout << "You chose for printing Exhange Status..." << endl;
        printMarketStats();    
        cout << "\n\t\t\t\t\t     Press any key to continue " << flush;
        char pause;
        cin >> pause;
        break;
    case 3:
        cout << "You chose for placing an Ask..." << endl;
        orderbook.BidAsk(BidAsk(choice));
        break;
    case 4:
        cout << "You chose for placing a Bid..." << endl;
        orderbook.BidAsk(BidAsk(choice));
        break;
    case 5:
        cout << "You chose for printing Wallet..." << endl;
        break;
    case 6:
        cout << "Continuing, Going to the next frame..." << endl<<endl
             << "Current Time is : "<<currentTime<<endl;
        currentTime = orderbook.getNextTime(currentTime);
        cout<< "Next Time is : "<<currentTime<<endl;
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
    sleepForSeconds(2);
    clearScreen();
    return;
}

void MerkelMain::printMarketStats(){
    cout << "\n\t\t\t\t   Market Statistics of "<<currentTime<<endl;
    cout<<"\nProducts : ";
    vector <string> productList = orderbook.getKnownProducts();
    for (string & p : productList){
        cout<<p<<" :"<<endl;
        vector <OrderBookEntry> matchedEntries = orderbook.getOrders(OrderBookType::ask, p, currentTime);
        cout<<"\tNo. of Asks -> "<<matchedEntries.size()<<endl
            <<"\tMax Ask -> "<<OrderBook::getHighPrice(matchedEntries)<<endl
            <<"\tMin Ask -> "<<OrderBook::getLowPrice(matchedEntries)<<endl;
    }
    cout<<"\b\b"<<endl;
    return;
}

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