#include <iostream>
#include "Wallet.hpp"
using namespace std;

WalletClass::WalletClass (){
     insertCurrency("BTC", 0.5);
     insertCurrency("ETC", 10.0);
     insertCurrency("DOGE", 1500.0);
     insertCurrency("USTD", 500.0);
}

void WalletClass::insertCurrency (string product, double amount){
     try{
          if (amount <= 0) throw invalid_argument("Invalid value for amount"); 
          if (wallet.count(product)) wallet[product] += amount;
          else wallet[product] = amount;
          cout<<amount<<" "<<product<<" credited to Wallet..."<<endl;
          return;
     }
     catch(const invalid_argument& e) {cerr<<"Error : "<<e.what()<<std::endl; return;}
}

bool WalletClass::removeCurrency (string product, double amount){
     try{
          if (amount <= 0) throw invalid_argument("Invalid value for amount"); 
          if (hasCurrency(product, amount)) {
               cout<<amount<<" "<<product<<" debited from Wallet..."<<endl;
               wallet[product] -= amount; 
               return true;
          }
          return false;
     }
     catch(const invalid_argument& e) {cerr<<"Error : "<<e.what()<<std::endl; return false;}
}

bool WalletClass::hasCurrency (string product, double amount){
     if (wallet.count(product) && wallet[product] >= amount){
          cout<<wallet[product]<<" "<<product<<" present in Wallet..."<<endl;
          return true;
     }
     else{cout<<"Not enough "<<product<<" in Wallet..."<<endl; return false;}
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
     for (const pair <const string, double> & currency : wallet)
          currencies += (currency.first + " : " + to_string(currency.second) + "\n");
     return currencies;
}