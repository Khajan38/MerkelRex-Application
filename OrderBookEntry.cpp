//MerkelRex application

#include <iostream>
#include <thread>
#include <chrono>
#include <limits>
#include <vector>
using namespace std;

//Some needed definitions
auto line = []() {string line (117, '='); return line; }; //lambda fucntion for line
#define printline cout << endl \
                       << line() << endl
#define sleep(timed) this_thread::sleep_for(chrono::seconds(timed))
#define clear_screen system("clear");

enum class OrderBookType : int
{
    bid = 0,
    ask = 1
};
class OrderBookEntry
{
    //Private Members
    double price, amount;
    string timeStamp, product;
    OrderBookType orderType;
    friend void display(const vector<OrderBookEntry> &entries);
    //Iterating over vector values
public:
    OrderBookEntry(double price, double amount, string timeStamp, string product, OrderBookType orderType) : price(price), amount(amount), timeStamp(timeStamp), product(product), orderType(orderType) {}
    OrderBookEntry() {} //Blank Constructor
    double getPrice(void) { return this->price; }
    double getAmount(void) { return this->amount; }
};

void printMenu(void)
{
    //Creating a Raw Strings of Menu Items
    string Menu = R"delimiter(1 : Print help
2 : Print exchange stats
3 : Place an ask
4 : Place a bid
5 : Print wallet
6 : Continue )delimiter";
    printline;
    cout << "\n\t\t\t\t\t\t     MAIN MENU\n";
    printline;
    cout << "\n\n"
         << Menu << endl;
    return;
}

int getUserOption(void)
{
    int choice;
    cout << "\nEnter your choice : ";
    cin >> choice;
    cout << endl;
    return choice;
}

OrderBookEntry BidAsk(int choice); //Taking Asking or Bidding values

void processUserOption(int choice, vector<OrderBookEntry> &entries)
{
    switch (choice)
    {
    case 1:
        cout << "Help - choose options from the menu" << endl
             << "and follow the on screen instructions." << endl;
        break;
    case 2:
        cout << "You chose for printing Exhange Status..." << endl;
        display(entries);
        cout << "\n\t\t\t\t        Press any key to continue " << flush;
        char pause;
        cin >> pause;
        cout << endl;
        break;
    case 3:
        cout << "You chose for placing an Ask..." << endl;
        entries.push_back(BidAsk(choice));
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
    default:
    {
        char exitChoice = 'Y';
        cout << "Enter a valid choice..." << endl
             << endl
             << "Do you want to exit from the program (Y/N)? : ";
        cin >> exitChoice;
        if (exitChoice == 89 || exitChoice == 121)
        { //exitChoice = 'Y' or 'y'
            cout << "\n\t\t\t   Exiting, Thank you for using our MerkleRex application..." << endl;
            printline;
            sleep(2);
            clear_screen;
            exit(2);
        }
        else
            cout << "\n\t\t\t\t       Continuing, Going to the next frame..." << endl;
    }
    }
    printline;
    sleep(2);
    clear_screen;
    return;
}

int main()
{
    clear_screen;
    vector<OrderBookEntry> entries;
    //Making loop for Menu Choices
    while (true)
    {
        printMenu();
        int choice = getUserOption();
        processUserOption(choice, entries);
    }
    return 0;
}

OrderBookEntry BidAsk(int choice)
{
    string a, b, timeStamp, product, type;
    double price, amount;
    OrderBookType orderType;
    if (choice == 3)
    {
        type = "Selling";
        orderType = OrderBookType::ask;
    }
    else
    {
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

//computeAveragePrice, computeLowPrice, computeHighPrice, computePriceSpread
double computeAveragePrice(const vector<OrderBookEntry> &entries)
{
    if (entries.empty())
    {
        cerr << "Error: No entries in order books to compute low price." << endl;
        return 0.0; // Handle empty vector scenario
    }
    double sum{0};
    int size = entries.size();
    for (OrderBookEntry i : entries)
        sum += i.getPrice();
    return (sum / size);
}

double computeHighPrice(const vector<OrderBookEntry> &entries)
{
    if (entries.empty())
    {
        cerr << "Error: No entries in order books to compute low price." << endl;
        return 0.0; // Handle empty vector scenario
    }
    double max{numeric_limits<double>::lowest()};
    for (OrderBookEntry i : entries)
        if (max < i.getPrice())
            max = i.getPrice();
    return max;
}

double computeLowPrice(const vector<OrderBookEntry> &entries)
{
    if (entries.empty())
    {
        cerr << "Error: No entries in order books to compute low price." << endl;
        return 0.0; // Handle empty vector scenario
    }
    double min{numeric_limits<double>::max()};
    for (OrderBookEntry i : entries)
        if (min > i.getPrice())
            min = i.getPrice();
    return min;
}

double computePriceSpread(const vector<OrderBookEntry> &entries)
{
    if (entries.empty())
    {
        cerr << "Error: No entries in order books to compute low price." << endl;
        return 0.0; // Handle empty vector scenario
    }
    double min{computeLowPrice(entries)}, max{computeHighPrice(entries)};
    return (max - min);
}

void display(const vector<OrderBookEntry> &entries)
{
    if (entries.size() == 0)
    {
        cout << "\nNo entries in Order Books DataBase..." << endl;
        return;
    }
    //2020/03/17 17:01:24.884492,ETH/BTC,bid,0.02186299,0.1
    //2020/03/17 17:01:24.884492,BTC/ETH,ask,0.1,0.02186299
    int count = 1;
    cout << endl;
    for (vector<OrderBookEntry>::const_iterator itr = entries.begin(); itr != entries.end(); itr++, count++)
        cout << count << ". " << itr->timeStamp << "," << itr->product << "," << ((static_cast<int>(itr->orderType)) ? "ask" : "bid") << "," << itr->price << "," << itr->amount << endl;
    cout << "\nAverage Price : " << computeAveragePrice(entries) << endl
         << "Highest Price : " << computeHighPrice(entries) << endl
         << "Lowest Price : " << computeLowPrice(entries) << endl
         << "Price Spread : " << computePriceSpread(entries) << endl;
    return;
}