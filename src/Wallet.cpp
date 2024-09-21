#include <iostream>
#include "Wallet.hpp"
using namespace std;

WalletClass::WalletClass (){
     wallet["BTC"] = 0.523798;
     wallet["ETH"] =  18.823674;
     wallet["DOGE"] =  1523.239622;
     wallet["USTD"] =  597.023246;
}

void WalletClass::insertCurrency (string product, double amount){
     if (wallet.count(product)) wallet[product] += amount;
     else wallet[product] = amount;
     cout<<endl<<amount<<" "<<product<<" credited to Wallet..."<<endl;
     return;
}

void WalletClass::removeCurrency (string product, double amount){
     wallet[product] -= amount; 
     cout<<endl<<amount<<" "<<product<<" debited from Wallet..."<<endl;
}

bool WalletClass::hasCurrency (string product, double amount){
     try{
          if (amount <= 0) throw invalid_argument("Invalid value for amount"); 
          if (wallet.count(product) && wallet[product] >= amount){
               cout<<endl<<wallet[product]<<" "<<product<<" present in Wallet..."<<endl;
               return true;
          }
          else{cout<<endl<<"Not enough "<<product<<" in Wallet..."<<endl; return false;}
     }
     catch(const invalid_argument& e) {cerr<<"\nError : "<<e.what()<<std::endl; return false;}
}

bool WalletClass::canFullfillOrder (OrderBookEntry & entry){
     vector <string> currencies = callToknise(entry.getProduct(), '/');
     if (entry.getOrderType() == OrderBookType::ask){
          double amount = entry.getAmount();
          string currency = currencies[0];
          return hasCurrency (currency, amount);
     }
     else if (entry.getOrderType() == OrderBookType::bid){
          double amount = entry.getAmount() * entry.getPrice();
          string currency = currencies[1];
          return hasCurrency (currency, amount);
     }
     return false;
}

string WalletClass::toString (void){
     string currencies;
     string paddingRows = padding("|   CURRENCIES   |       AMOUNT       |", consoleWidth);
     for (const pair <const string, double> & currency : wallet){
          string adder = format("{}|   {:10}   |   {:>14.6f}   |\n", paddingRows, currency.first, currency.second);
          currencies += adder;
     }
     return currencies;
}