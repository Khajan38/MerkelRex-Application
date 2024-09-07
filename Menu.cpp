//MerkelRex application

#include <iostream>
#include <thread>
#include <chrono>
using namespace std;
auto line = []() {string line (117, '='); return line; }; //lambda fucntion for line
#define printline cout << endl \
                       << line() << endl
#define sleep(timed) this_thread::sleep_for(chrono::seconds(timed))
#define clear_screen system("cls")

int main()
{

    //Creating a Raw Strings of Menu Items
    string Menu = R"delimiter(1 : Print help
2 : Print exchange stats
3 : Place an ask
4 : Place a bid
5 : Print wallet
6 : Continue )delimiter";

    clear_screen;
    //Making loop for Menu Choices
    while (true)
    {
        int choice;
        printline;
        cout << "\n\t\t\t\t\t\t     MAIN MENU\n";
        printline;
        cout << "\n\n"
             << Menu << endl;
        cout << "\nEnter your choice : ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
            cout << "Help - choose options from the menu" << endl
                 << "and follow the on screen instructions." << endl;
            break;
        case 2:
            cout << "You chose for printing Exhange Status..." << endl;
            break;
        case 3:
            cout << "You chose for placing an Ask..." << endl;
            break;
        case 4:
            cout << "You chose for placing a Bid..." << endl;
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
                return 1;
            }
            else
                cout << "\n\t\t\t\t       Continuing, Going to the next frame..." << endl;
        }
        }
        printline;
        sleep(2);
        clear_screen;
    }
    return 0;
}