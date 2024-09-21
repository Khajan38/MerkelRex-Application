#include <iostream>
#include "Display Basics.hpp"
using namespace std;

array <string, 2> Display::Exit_Parts {"MERKELREX APPLICATION", "MerkelRex Application"};
vector <string> Display::menuItems {"MERKELREX APPLICATION : MAIN MENU", "Print help", "Print exchange stats", "Place an ask", "Place a bid", "Print wallet", "Continue", "Exit"};

int getConsoleWidth() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    return consoleInfo.dwSize.X;
}

void Display::printLine(){cout << endl << line(consoleWidth) <<endl;}

void Display::sleepForSeconds(int timed){
     std::this_thread::sleep_for(std::chrono::seconds(timed));
}

void Display::clearScreen(){
    #ifdef _WIN32
        system("cls"); // For Windows
    #else
        system("clear"); // For Linux and MacOS
    #endif
}

void Display::Header (string Heading){
     Display::clearScreen(); Display::printLine();
     cout<<endl<<padding(Heading, consoleWidth)<<Heading<<endl; Display::printLine();
}

void Display::Bottom_Line (int page){
     switch (page) {
     case 0 : //Necessary for Entrance Window
          cout<<"\n\n"; Display::printLine();
          cout <<padding("Continuing", consoleWidth)<<"Continuing..."<<endl;
          Display::sleepForSeconds(2);
          break;
     case 1 : //Necessary for Main_Menu
          Display::printLine();
          cout<<endl<<padding("Initiating your request...", consoleWidth)<<"Initiating your request...";
          Display::sleepForSeconds(2);
          break;
     case 2 : { //Necessary for Bottom of Page
          Display::printLine();
          char menu_choice;
          cout<<endl<<padding("Enter M to go to Main Menu or any other key to exit : ", consoleWidth)<<"Enter M to go to Main Menu or any other key to exit : ";
          cin>>menu_choice;
          if (menu_choice != 'M') Exiting_Window();
     }
     case 3 : {//Necessary for Stopping      
          Display::printLine();
          cout <<endl<<padding("Press any key to continue ", consoleWidth)<<"Press any key to continue ";
          cin.get();
     }
     }
}

int Display::Main_Menu (vector <string> Menu_items){
     Header(Menu_items[0]);
     int size = Menu_items.size();
     string Menu_items_padding (50, ' ');
     for (int i = 1; i < size; i++)
          cout<<"\n"<<Menu_items_padding<<static_cast <char> ('A' + i - 1)<<". "<<Menu_items[i];
     cout<<"\n\nEnter your choice : ";
     char choice; cin>>choice;
     if (choice >= 'A' && choice < 'A' + size - 1 && choice != 'A' + 5) {Bottom_Line(1); return choice - 'A' + 1;}
     else if (choice >= '1' && choice <= '1' + size - 1 && choice != '1' + 5){Bottom_Line(1); return choice - '1' + 1;}
     else if (choice >= 'a' && choice < 'a' + size - 1 && choice != 'a' + 5) {Bottom_Line(1); return choice - 'a' + 1;}
     else if (choice == 'A' + 5 || choice == '1' + 5 || choice == 'a' + 5) return 6;
     else return -1;
}

void Display::Exiting_Window (){
     Header(Display::Exit_Parts[0] + ": EXIT WINDOW");
     cout<<endl<<endl<<padding("Thank You!", consoleWidth)<<"Thank You!"<<endl<<endl
         <<padding("for using "+Exit_Parts[1], consoleWidth)<<"\bfor using "+Exit_Parts[1]+"..."<<endl<<endl<<endl
         <<padding("WE WILL WAIT FOR YOU!...", consoleWidth)<<"WE WILL WAIT FOR YOU!..."<<endl<<endl;
     Display::printLine(); Display::sleepForSeconds(3);
     system("cls");
     exit(0);
}