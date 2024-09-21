#include <iostream>
#include "MerkelMain.hpp"
using namespace std;

class Help {
     friend MerkelMain;
     vector <string> Information;
     public :
          void processHelpOptions(int helpChoice);
          void about(void);
          void menuOptions(void);
          void useageExamples(void);
          void errorHandling(void);
          void support(void);
          void TXTReader(void);
};