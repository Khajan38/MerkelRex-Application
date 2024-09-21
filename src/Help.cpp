#include <iostream>
#include "Help.hpp"
using namespace std;

void MerkelMain::helpAndFeedback(){
     Help help;
     vector <string> helpMenu_items = {"MERKELREX APPLICATION : HELP MENU", "About The Application", "Help With Main Menu Options", "Usage Examples", "Error Handling", "Contact/Support"};
     int helpChoice = Display::Main_Menu(helpMenu_items);
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
     Display::Bottom_Line(2);
     return;
}

void Help::about(void){}
void Help::menuOptions(void){}
void Help::useageExamples(void){}
void Help::errorHandling(void){}
void Help::support(void){}

void Help::TXTReader(void){
     ifstream csvFile{"Help.txt"};
     if (!csvFile.is_open()) throw std::runtime_error("Could not open file: " + csvFileInput);
     string csvLine;
     int lineNumber = 0;  // For tracking line numbers
     while (getline(csvFile, csvLine, '\n')) {
          lineNumber++;
          try {
               OrderBookEntry entry = stringToOrderBookEntry(tokenise(csvLine, ','));
               entries.push_back(entry);
          }
          catch (const std::exception& e) {
               cerr << "Error processing line " << lineNumber << ": " << e.what() << endl;
          }
     }
     return entries;
} 