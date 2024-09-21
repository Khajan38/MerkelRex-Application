cmake_minimum_required(VERSION 3.10)

# Set project name
project(MerkelRex)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories for header files
include_directories(include)

# Add executable and source files
add_executable(MerkelRex 
    src/main.cpp
    src/MerkelMain.cpp
    src/MerkelMenu.cpp
    src/MerkelRex\ Engine.cpp
    src/CSV\ Reader.cpp
    src/OrderBook.cpp
    src/Wallet.cpp
    src/OrderBookEntry.cpp
    src/Statistical\ Functions.cpp
    src/Display\ Basics.cpp
    src/Help.cpp
)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)