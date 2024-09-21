# MerkelRex Application Documentation

## Overview

This document serves as a detailed guide to understanding the internal structure and functionality of the MerkelRex Application. It includes information on how the application works, its various components, and guidelines on how to extend or modify its functionality.

## Table of Contents
- [Project Structure](#project-structure)
- [Order Book Overview](#order-book-overview)
- [Matching Engine](#matching-engine)
- [Statistical Analysis](#statistical-analysis)
- [Wallet Management](#wallet-management)
- [How to Add Features](#how-to-add-features)
- [Help System Details](#system-details)

## Project Structure
For detailed information about the project's structure, please refer to the [Directory Structure](docs/Directory%20Structure.md) document.

## Order Book Overview
- The OrderBook class is central to the MerkelRex Application. 
- It is responsible for parsing the data from the CSV file (data.csv), storing the orders, and facilitating the matching of buy and sell orders.

   ### Key Components:
     - OrderBookEntry: Represents a single entry in the order book (buy/sell order).
     - OrderBook: A collection of OrderBookEntry objects with methods to manage and analyze the data.

   ### How Data is Parsed
     - The OrderBook class reads the CSV file and splits each line into attributes (timestamp, product, bid/ask type, price, and quantity), which are stored in OrderBookEntry objects.

## Matching Engine
- The Matching Engine matches buy and sell orders by checking the compatibility of bid and ask prices. It efficiently matches orders in the correct order of priority (by timestamp and price).

   ### Matching Algorithm:
     - Orders are matched based on timestamp, and within the same timestamp, by the best price (highest bid and lowest ask).
     - Unmatched orders remain in the order book for future matching attempts.

## Statistical Analysis
- The statistical functions are key to analyzing the order book data. 

   ### Statistical Insights:
     - Maximum and Minimum Price: For both buy and sell orders over a given period.
     - Average Price: For all matched orders.
     - Volume Statistics: Analyzes the total quantity traded.

   ### How Statistics Are Generated:
     - The OrderBook class uses helper methods to filter and analyze the data based on user commands.
     - The statistical outputs are printed to the console.

## Wallet Management
- The Wallet class allows users to keep track of their currencies. 
- It manages the balance of multiple cryptocurrencies and updates balances based on completed trades.

  ### Wallet Features:
    - Deposit: Add funds to your wallet.
    - Withdraw: Remove funds based on completed trades.
    - Balance Check: Show current balances for each currency.

## How to Add Features

### Create New Classes: 
   - For any new functionality, create a new class and place it in the src/ directory, with corresponding headers in include/.
### Modify the Menu System: 
   - Update Menu.cpp to include new user commands for your feature.
### Add Unit Tests: 
   - You can extend the test cases (if any) for each new functionality added to ensure robustness.

## Help System Details
   - The Help class provides useful guidance and information to users. 
   - It reads from a Help.txt file to provide dynamic help content.
   - Edit the Help.txt file to update the content visible to users.
   - The Help.cpp class fetches this data and displays it in the application.