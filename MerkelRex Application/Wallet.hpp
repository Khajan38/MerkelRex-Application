#include <iostream>
#include <unordered_map>
using namespace std;

class Wallet {
          unordered_map <string, double> wallet;
     public :
          Wallet (); //Constructor
          void insertCurrency (string product, double amount);
          bool hasCurrency (string product, double amount);
          string toString (void);
};