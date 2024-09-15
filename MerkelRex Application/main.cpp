//MerkelRex application
#include <iostream>
#include <vector>
#include "MerkelMain.hpp"
using namespace std;

int main(){
    clearScreen();
    printLine();
    cout << "\n\t\t\t\t\tWELCOME TO MERKELREX APPLICATION\n";
    printLine(); cout<<endl;
    string fileName;
    cout<<"Enter Database Name and Location (D:\\Tanuj\\...) or Press Enter to Proceed with Default Database? : ";
    getline(cin, fileName);
    cout<<"\nUsing Database : ";
    if (fileName == "") {cout<<"Default -> data.csv\n"<<endl; fileName = "data.csv";}
    else cout<<fileName<<endl;
    MerkelMain app(fileName);
    printLine();
    cout << "\n\t\t\t\t\t     Press any key to continue ";
    cin.get();
    app.init();
    return 0;
}