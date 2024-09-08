/* DOCUMENTATION: 

INTRODUXTION: This C++ program reads data from a CSV file containing Bitcoin trading information, parses it into structured entries, and performs some basic analysis. The included CSV contains data as : 

Open time : 2018-01-01, Open : 13715.65000000, High : 13818.55000000, Low : 12750.00000000, Close : 13380.00000000, Volume : 8609.91584400, Close Time : 2018-01-01 23:59:59.999, Quote Asset Volume : 114799747.44197057, Number of Trades : 105595, Taker buy base asset Volume : 3961.93894600, Taker buy quote asset Volume : 52809747.44038045, Ignore : 0

Here's a detailed breakdown of its functionality:

COMPNENETS:

  - Class Definition (bitCoinEntry):
      - Attributes: Stores various trading metrics, such as opening and closing times, prices, volume, and trade count.
      - Constructor: Initializes an entry with specific values for all attributes.
      - Default Constructor: Provides a blank initialization.
      - Method print(): Outputs the entry details in a formatted manner.

  - Tokenization Function (tokenise):
      - Purpose: Splits a CSV line into individual fields based on a specified separator (comma).
      - Input: A string (CSV line) and a character (separator).
      - Output: A vector of strings representing the tokens.

  - Summary Statistics Function (summaryStatistics):
      - Purpose: Provides a summary of the data processed, including counts of valid and invalid entries and size.
      - Input: A vector of bitCoinEntry objects and a reference to an integer tracking invalid data sets.
      - Output: Displays summary statistics.

  - Main Function (main):
      - File Handling: 
          - Opens and reads data from a CSV file named "Bitcoin Data.csv".
      - Data Processing:
          - Reads each line of the CSV file.
          - Tokenizes each line into individual fields.
          - Converts tokens into appropriate types and creates bitCoinEntry objects.
          - Catches and reports invalid entries.
      - Output:
          - Prints each valid bitCoinEntry.
          - Displays summary statistics about the dataset.

KEY POINTS:

  - Error Handling: The program uses exception handling to manage invalid data entries, incrementing an invalidDataSets counter and reporting these errors.
  - Data Storage: Utilizes a vector to store all valid entries.
  - Statistics Calculation: Provides an estimate of file size based on the number of entries and their attributes.
  - Time and Space Complexity: Time -> O(n), Space -> O(n)

PROS:
  - Structured Data Storage: Efficiently stores and manages trading data using a class.
  - Robust Error Handling: Handles errors gracefully by catching exceptions and reporting invalid entries.
  - Clear Output: Provides detailed information about each entry and overall statistics.

CONS:
  - No Data Validation: Assumes that the input data is in the correct format without additional validation beyond conversion errors.
  - Hardcoded File Name: The CSV file name is hardcoded, which might limit flexibility.

Overall, the program is designed to efficiently read, process, and analyze Bitcoin trading data from a CSV file, handling errors and providing a summary of the processed data*/

//Main program Here

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

//Class defined for Data Storage
class bitCoinEntry{
    string openTime, closeTime;
    double open, high, low, close, volume, quoteAssestVolume, takerBuyBaseAssetVolume, takerBuyQuoteAssetVolume;
    unsigned int numberOfTrades, ignore;
    public :
        bitCoinEntry (string openTime, double open, double high, double low, double close, double volume, string closeTime, double quoteAssestVolume,  unsigned int numberOfTrades,double takerBuyBaseAssetVolume, double takerBuyQuoteAssetVolume, unsigned int ignore) : openTime(openTime), closeTime(closeTime), open(open), high(high), low(low), close(close), volume(volume), quoteAssestVolume(quoteAssestVolume), takerBuyBaseAssetVolume(takerBuyBaseAssetVolume), takerBuyQuoteAssetVolume(takerBuyQuoteAssetVolume), numberOfTrades(numberOfTrades), ignore(ignore) {} //Constructor for Asking Data Values

        bitCoinEntry(){} //Blank Constructor   

        void print() const {
            cout << openTime << ", " << open << ", " << high << ", " << low << ", " << close << ", " << volume << ", " << closeTime << ", " << quoteAssestVolume << ", " << numberOfTrades << "," << takerBuyBaseAssetVolume << ", " << takerBuyQuoteAssetVolume << ", " << ignore << endl;
        }
};

//Tokenising Function
vector <string> tokenise (string csvLine, char seperator){
     vector <string> tokens;
     string token;
     for (char i : csvLine){
          if (i != seperator) token += i;
          else {
               if (token == "") continue;
               tokens.push_back(token); 
               token = "";
          }
     }
     tokens.push_back(token);
     return tokens;
}

//Summary Statistics Function
void summaryStatistics (const vector <bitCoinEntry> & bitCoinBookEntry, int & invalidDataSets){
    int rows = bitCoinBookEntry.size(), rowSize = sizeof(bitCoinBookEntry[0]);
    cout<<"\nSummary : "<<endl;
    cout<<"\tNumber of columns : 11"<<endl
        <<"\tNumber of Valid Data Sets : "<<rows <<endl
        <<"\tInvalid Data Entries : "<<invalidDataSets<<endl
        <<"\tSize of the CSV File (ignoring Invalid Entries) : "<<rowSize * rows<<" bytes."<<endl
        <<"\tTotal Size of the CSV File : "<<rowSize * (rows + invalidDataSets)<<" bytes."<<endl;
}

int main(){
    vector <bitCoinEntry> bitCoinBookEntry; //Vector to store the CSV File Data
    
    ifstream csvFile {"Bitcoin Data.csv"}; //Input File Stream having 10 Data Lines, 2 with error
    if (!csvFile.is_open()) {cout<<"Error, File not Opened..."; return 1;} //Check for File opening error
    string csvLine; int invalidDataSets {0};

    while (getline(csvFile, csvLine, '\n')){ //Readig whole CSV File
        vector <string> tokens = tokenise(csvLine, ','); //Tokenising the Lines
        //Storing in the respective feilds
        try {
            bitCoinBookEntry.push_back(bitCoinEntry(tokens[0], stod(tokens[1]), stod(tokens[2]), stod(tokens[3]), stod(tokens[4]), stod(tokens[5]), tokens[6], stod(tokens[7]), stoi(tokens[8]), stod(tokens[9]), stod(tokens[10]), stoi(tokens[11]))); //Pushing each error free line into Vector
        }
        catch (const exception & e){
            invalidDataSets++;
            cout<<"\nInvalid Entry "<<invalidDataSets<<" : "<<csvLine<<endl; //Printing the error
        }
    }

    // Traverse and print each entry
    cout<<endl;
    for (const auto& entry : bitCoinBookEntry){cout<<"Element : "; entry.print();}
    //Summary Statistics about the data
    summaryStatistics(bitCoinBookEntry, invalidDataSets); cout<<endl;

    csvFile.close(); //Closing the opened File
    return 0;
}