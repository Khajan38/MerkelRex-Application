```
MerkelRex/
├── src/                          # Source files
│   ├── CSV Reader.cpp            # CSV Reader implementation
│   ├── Display Basics.cpp        # Display utilities implementation
│   ├── Help.cpp                  # Help system implementation
│   ├── main.cpp                  # Main entry point of the program
│   ├── MerkelMain.cpp            # Core application logic
│   ├── MerkelMenu.cpp            # Menu logic
│   ├── MerkelRex Engine.cpp      # Matching engine implementation
│   ├── OrderBook.cpp             # OrderBook class implementation
│   ├── OrderBookEntry.cpp        # OrderBookEntry class implementation
│   ├── Statistical Functions.cpp # Functions for stats
│   ├── Wallet.cpp                # Wallet logic
│
├── include/                      # Header files
│   ├── CSV Reader.hpp            # CSV Reader declarations
│   ├── Display Basics.hpp        # Display utilities declarations
│   ├── Help.hpp                  # Help system declarations
│   ├── MerkelMain.hpp            # MerkelMain class declarations
│   ├── MerkelRex Engine.hpp      # MerkelRex Engine class declarations
│   ├── OrderBook.hpp             # OrderBook class declarations
│   ├── OrderBookEntry.hpp        # OrderBookEntry class declarations
│   ├── Wallet.hpp                # Wallet class declarations
│
├── data/                         # Data files
│   └── data.csv                  # CSV file used by the application
│
├── tests/                        # Test files
│   ├── BidAsk.cpp                # Bid and Ask Test
│   ├── data.csv                  # Small Dataset for Testing
│   ├── Entrance Window.cpp       # Username Validation Test
│   ├── Statistical Functions.cpp # Getting Statistical Data
│   ├── Tokenising Test.cpp       # CSV Token Generation
│   └── Wallet.cpp                # Testing Wallet Functionality 
│
├── docs/                         # Documentation
│   ├── README.md                 # General project documentation
│   ├── Help.txt                  # Help text for the application (Main Menu help section)
│   └── Directory Structure.md    # Tells about Directory Structure
│
├── CMakeLists.txt / Makefile     # Build system (CMake or Make)
├── .gitignore                    # Ignored files by Git
├── LICENSE                       # License for your project
└── README.md                     # Project overview
```