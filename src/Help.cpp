#include <iostream>
#include "Help.hpp"
using namespace std;

void MerkelMain::helpAndFeedback(){
     Help help;
     vector <string> helpMenu_items = {"MERKELREX APPLICATION : HELP MENU", "About The Application", "Help With Main Menu Options", "Usage Examples", "Error Handling", "Contact/Support"};
     int helpChoice = Display::Main_Menu(helpMenu_items);
     help.TXTReader();
     help.processHelpOptions(helpChoice);
     return;
}

void Help::processHelpOptions (int helpChoice){
     Display::Header("HELP AND FEEDBACK");
     switch (helpChoice){
     case 1:
          about();
          break;
     case 2:
          menuOptions();
          break;
     case 3:
          useageExamples();
          break;
     case 4:
          errorHandling();
          break;
     case 5:
          support();
          break;
     }
     return;
}

void Help::about(void){cout<<Information[0];}
void Help::menuOptions(void){cout<<Information[1];}
void Help::useageExamples(void){cout<<Information[2];}
void Help::errorHandling(void){cout<<Information[3];}
void Help::support(void){cout<<Information[4];}

void Help::TXTReader(void){
     ifstream txtFile{"docs/Help.txt"};
     if (!txtFile.is_open()) throw std::runtime_error("Could not open file: Help.txt");
     string txtLine; int lineNumber {0};
     getline(txtFile, txtLine, '#');
     while (getline(txtFile, txtLine, '#')) {
          getline(txtFile, txtLine, '#');
          try {
               if (txtLine == "") continue;
               lineNumber++;
               Information.push_back(txtLine);
          }
          catch (const std::exception& e) {
               cerr << "Error processing line " << lineNumber << ": " << e.what() << endl;
               break;
          }
     }
     return;
} 