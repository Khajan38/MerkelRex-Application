#pragma once

#include <iostream>
#include <windows.h>
#include <vector>
#include <array>
#include <thread>
#include <chrono>
using namespace std;

inline auto line = [](const int consoleWidth){string line (consoleWidth, '='); return line;}; //lambda fucntion for line

inline auto padding = [](string text, const int consoleWidth) {
     string paddingWidth(static_cast <int> ((consoleWidth - text.size())/2) , ' ');
     return paddingWidth;
}; //lambda function for text padding

int getConsoleWidth();
const int consoleWidth = getConsoleWidth();

class Display{
     static vector <string> menuItems;
     static array <string, 2> Exit_Parts;
     public :
          static void printLine();
          static void sleepForSeconds(int timed);
          static void clearScreen();
          static void Header (string Heading);
          static void Bottom_Line (int page);
          //static void Entrance_Window (char restart_choice);
          static int Main_Menu (vector <string> Menu_items = menuItems);
          static void Exiting_Window ();
};