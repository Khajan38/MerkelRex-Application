#include <iostream>
#include "Display Basics.hpp"
#include "OrderBookEntry.hpp"
using namespace std;

/*char Entrance_Window (vector <unique_ptr <Member>> &Members){
     //Checking if you are master or client
     int MemberId; string Name, Password;
     while (true){
          Display::Header("LIBRARIAN'S HUB : LOGIN PAGE");
          cout<<"\nEnter your Member ID : "; cin>>MemberId;
          cin.ignore(INT_MAX, '\n');
          cout<<"Enter your Name : "; getline(cin, Name);
          cout<<"Enter Password : "; getline(cin, Password);
          /*Password to open your Member Window is your Name with Initials matching in member list
          While for Director Window MemberId = 0, Name = {Your_Name} and Password is - "Librarian's Hub Director"
          for (auto & Mem : Members){
               if (MemberId == (Check_Member == *Mem)){
                    if (Password == Name){
                         cout<<endl<<padding("Fetching Permissions")<<"Fetching Permissions";
                         Bottom_Line(0); Current_MemberId = MemberId; 
                         return 'M';
                    }
                    else {
                         cout<<endl<<padding("Wrong Password Entered...")<<"Wrong Password Entered...";
                         cout<<endl; printline;
                         cout<<padding("Enter L to go to Login Again or any other key to exit : ")<<"Enter L to go to Login Again or any other key to exit : ";
                         cin>>Password; 
                         if (Password != "L") Exiting_Window(Exit_Parts);
                    }
               }
               else if (MemberId == 0 && Password == "Librarian's Hub Director"){
                    cout<<endl<<padding("Fetching Permissions")<<"Fetching Permissions";
                    Bottom_Line(0); return 'D';
               }
          }
          if (Password != "L"){
               cout<<endl<<padding("Wrong Information Entered...")<<"Wrong Information Entered..."<<endl; printline;
               cout<<padding("Enter L to go to Login Again or any other key to exit : ")<<"Enter L to go to Login Again or any other key to exit : ";
               cin>>Password; 
               if (Password != "L") Exiting_Window(Exit_Parts);
          }
     }
     return '\0';
}*/