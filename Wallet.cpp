#include <iostream>
#include <unordered_map>
using namespace std;

class WalletClass {
          unordered_map <string, double> wallet;
     public :
          WalletClass (); //Constructor
          void insertCurrency (string product, double amount);
          bool removeCurrency (string product, double amount);
          bool containsCurrency (string product, double amount);
          string toString (void);
};

WalletClass::WalletClass (){
     wallet["BTC"] = 0.5;
     wallet["ETH"] =  10.0;
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
          if (containsCurrency(product, amount)) {
               cout<<amount<<" "<<product<<" debited from Wallet..."<<endl;
               wallet[product] -= amount; 
               return true;
          }
          return false;
     }
     catch(const invalid_argument& e) {cerr<<"Error : "<<e.what()<<std::endl; return false;}
}

bool WalletClass::containsCurrency (string product, double amount){
     try{
          if (amount <= 0) throw invalid_argument("Invalid value for amount"); 
          if (wallet.count(product) && wallet[product] >= amount){
               cout<<wallet[product]<<" "<<product<<" present in Wallet..."<<endl;
               return true;
          }
          else{cout<<"Not enough "<<product<<" in Wallet..."<<endl; return false;}
     }
     catch(const invalid_argument& e) {cerr<<"Error : "<<e.what()<<std::endl; return false;}
}

string WalletClass::toString (void){
     string currencies;
     for (const pair <const string, double> & currency : wallet)
          currencies += (currency.first + " : " + to_string(currency.second) + "\n");
     return currencies;
}

int main (){
     WalletClass Wallet;
     cout<<endl<<"Wallet : "<<endl<<endl;
     cout<<Wallet.toString()<<endl;
     Wallet.containsCurrency("BTC", 0.3);
     Wallet.containsCurrency("ETH", 15.0);
     return 1;
}