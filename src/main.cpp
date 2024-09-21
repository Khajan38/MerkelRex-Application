//MerkelRex application
#include <iostream>
#include <vector>
#include "MerkelMain.hpp"
using namespace std;

int main(){
    Display::Header("WELCOME TO MERKELREX APPLICATION");
    string fileName;
    cout<<"\nEnter Database Name and Location (D:\\Tanuj\\...) or Press Enter to Proceed with Default Database? : ";
    getline(cin, fileName);
    cout<<"\nUsing Database : ";
    if (fileName == "") {cout<<"Default -> data.csv\n"<<endl; fileName = "data/data.csv";}
    else cout<<fileName<<endl;
    MerkelMain app(fileName);
    Display::Bottom_Line(3);
    app.init();
    return 0;
}