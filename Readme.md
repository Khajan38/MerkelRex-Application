# MARKELREX APPLICATION
The Library Management System (LMS) : LIBRARIAN'S HUB is a comprehensive software solution designed to facilitate the management and operation of a library. It automates various processes involved in managing books, members, and transactions, making it easier for librarians and library staff to efficiently handle daily tasks. The system is intended for use in libraries of all sizes, from small community libraries to large academic and public institutions.

<img src="Library-Management-System\Library.jpeg" alt="Library" height="250">

__See me on LinkedIn__ : [Link to my LinkedIn ID](https://www.linkedin.com/in/khajanbhatt/)

## Files in the Project

    --> Mission_8 Library_Management_System.cpp : 
              Main Program code for Abstraction 

    --> Display_Basics.hpp : 
              Resuable files for all missions

    --> Library-Management-System : 
              Directory for Header Files
          * Classes Declaration File.hpp : 
              All classes like Book, Member and LIbrary are declared here
          * Main Header File.hpp : 
              All Main fucntions that call fucntions from other header files are made here
          * Library Functions File.hpp : 
              All functions defined for Library are given definition here --> for Director
          * Member Fucntions File.hpp : 
              All friend fucntions are defined here --> for Members
          * Library.jpeg : 
              Image for Readme File
          * Library-Management-System.jpeg : 
              Image for Readme File to show its purpose

<img src="Library-Management-System\Library-Management-System.jpeg" alt="Library Management System Operations"  height="250">

## Features and Working:

  The __Librarian's Hub__ opens when the user runs the file __"Mission_8 Library_Management_System.cpp"__. Designing Templates for all pages is done by using __"Display_Basics.hpp"__ which includes various function methods for Page Templates. These include-
  
  - Headings : __"Display_Basics.hpp -> Header()"__
  - Word Padding to center : __"Display_Basics.hpp -> padding [] () {}"__
  - Footers and Bottom Lines : __"Display_Basics.hpp -> Bottom_Line(), Bottom_Line_2()"__
  - Main Menus : __"Display_Basics.hpp -> Main_Menu()"__
  - Exit Window : __"Display_Basics.hpp -> Exiting_Window()"__
  
  Now the first page that opens is the __Login Page__ which is executed by __"Library-Management-System/Main Functions File.hpp -> Login_Page()"__. This checks weather you are an Member or a Director or just an intruder. Thus corresponding windows are called of which Intruders develops to the __"Display_Basics.hpp -> Exiting_Window()"__. However, for Member and Director corresponding Menus are opened.

   - For __Member__, we are headed to the __"Library-Management-System/Main Functions File.hpp -> Member_Menu()"__ which calls __"Display_Basics.hpp -> Main_Menu()"__ with Member Menu Items. These further gives choices for various operations.

       - For __Borrowing Book__, it calls __"Library-Management-System/Member Functions File.hpp -> Borrow_Book()"__ which calls necessary headers and displays a list of books available to borrow by help of __"Library-Management-System/Library Functions File.hpp -> Display_Table()"__. It asks user for Borrow Book ID and issues book if available and updates the Libarary Database.

       - For __Retuning Book__, it calls __"Library-Management-System/Member Functions File.hpp -> Return_Book()"__ which asks user for Return Book ID and marks book returned in the Library Database after matching all conditions.

       - For __Dispalying all Borrowed Books__, it calls __"Library-Management-System/Member Functions File.hpp -> Borrowed_Books()"__ which showcases a table showing list of all borrowed books list, if issued by Library.

       - For __Checking Membership Card__, it calls __"Library-Management-System/Member Functions File.hpp -> Membership_Card()"__ which showcases a card showing all details of Member verified by the Library Director with correct paddings.

       - For __Exiting from the Program__, it calls the __"Display_Basics.hpp -> Exiting_Window()"__ which lets user to the Exit and Thank You Window and clears the prompt screen then.


   - For __Director__, we are headed to the __"Library-Management-System/Main Functions File.hpp -> Director_Menu()"__ which calls __"Display_Basics.hpp -> Main_Menu()"__ with Director Menu Items. These further gives choices for various operations.

       - For __Display all Books__, it calls __"Library-Management-System/Library Functions File.hpp -> Library :: DisplayBooks()"__ which calls necessary headers and displays a list of all Books present in the Library by help of __"Library-Management-System/Library Functions File.hpp -> Display_Table()"__. It also prompts total no. of books available and shows which book is borrowed and by which member.

      - For __Display all Members__, it calls __"Library-Management-System/Library Functions File.hpp -> Library :: DisplayMembers()"__ which calls necessary headers and displays a list of all Members available to borrow by help of __"Library-Management-System/Library Functions File.hpp -> Display_Table()"__. It also prompts total no. of members.

       - For __Adding New Book__, it calls __"Library-Management-System/Library Functions File.hpp -> AddBook()"__ which asks director for New Book Information and add + update it to the Books Database.

       - For __Removing Existing Book__, it calls __"Library-Management-System/Library Functions File.hpp -> RemoveBook()"__ which calls necessary headers and displays a list of books available to remove by help of __"Library-Management-System/Library Functions File.hpp -> Display_Table()"__. It asks director for Delete Book ID and removes book if not issued by any member of the Library and updates it to the Book Database.

       - For __Adding New Member__, it calls __"Library-Management-System/Library Functions File.hpp -> AddMember()"__ which asks director for New Member Information and add + update it to the Members Database.

       - For __Removing Existing Memebr__, it calls __"Library-Management-System/Library Functions File.hpp -> RemoveMember()"__ which calls necessary headers and displays a list of members available to remove by help of __"Library-Management-System/Library Functions File.hpp -> Display_Table()"__. It asks director for Delete Member ID and removes member if he/she has no issues in the Library and updates it to the Member Database.

       - For __Exiting from the Program__, it calls the __"Display_Basics.hpp -> Exiting_Window()"__ which lets user to the Exit and Thank You Window and clears the prompt screen then.

### Flow of Operations:
    Main Program : "Mission_8 Library_Management_System.cpp"

    Login Page : Library-Management-System/Main Functions File.hpp -> Login_Page()

    As Member : Library-Management-System/Main Functions File.hpp -> Member_Menu()
          Main_Menu : Display_Basics.hpp -> Main_Menu()
          Borrowing Book : Library-Management-System/Member Functions File.hpp -> Borrow_Book()
          Returning Book : Library-Management-System/Member Functions File.hpp -> Return_Book()
          Display Borrowed Books : Library-Management-System/Member Functions File.hpp -> Borrowed_Books()
          Display Memebership Card : Library-Management-System/Member Functions File.hpp -> Membership_Card()
          Exiting : Display_Basics.hpp -> Exiting_Window()

    As Director : Library-Management-System/Main Functions File.hpp -> Director_Menu() 
          Main_Menu : Display_Basics.hpp -> Main_Menu()
          Display all Books : Library-Management-System/Library Functions File.hpp -> DisplayBooks()
          Display all Memebers : Library-Management-System/Library Functions File.hpp -> DisplayMembers()
          Add New Book : Library-Management-System/Library Functions File.hpp -> AddBook()
          Remove Existing Book : Library-Management-System/Library Functions File.hpp -> RemoveBook()
          Add new Member : Library-Management-System/Library Functions File.hpp -> AddMember()
          Add new Member : Library-Management-System/Library Functions File.hpp -> RemoveMember()
          Exiting : Display_Basics.hpp -> Exiting_Window()