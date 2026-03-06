🏦 Bank Management System in C


A console-based Bank Management System implemented in C that simulates core banking operations such as account creation, deposits, withdrawals, fund transfers, and balance inquiries.

This project demonstrates structured programming concepts, data handling using structures, and menu-driven system design.

📌 Project Overview

The Bank Management System is designed to manage multiple customer accounts using an in-memory data structure. It provides a user-friendly menu interface and performs necessary validations to ensure correct transaction processing.


This project is ideal for understanding:

Structures in C
Arrays of structures
Function-based modular programming
Input validation
Nested loop logic
Basic financial transaction handling

✨ Features
Create a new bank account
Deposit funds into an account
Withdraw funds with balance validation
Transfer funds between accounts
Check account balance
Menu-driven interactive interface
Error handling and validation checks

🧠 System Design
Data Structure Used
C
Copy code
struct Account {
    int accountNumber;
    char FirstName[50];
    char LastName[50];
    float balance;
};
Accounts are stored in an array of size 500.
Each account is uniquely identified by its account number.
Transactions update the in-memory account balance.
🛠️ Technologies Used
Programming Language: C
Compiler: GCC / MinGW / Turbo C / Any Standard C Compiler
Execution Mode: Command Line Interface (CLI)

▶️ How to Compile and Run
🔹 Compile
Bash
Copy code
gcc filename.c -o bank
🔹 Run (Linux/macOS)
Bash
Copy code
./bank
🔹 Run (Windows)
Bash
Copy code
bank.exe
📋 Application Menu
Copy code

1. Create Account
2. Deposit
3. Withdraw
4. Transfer
5. Check Balance
6. Exit
🔐 Validations Implemented
Prevents negative or zero deposits
Prevents negative withdrawals
Checks for sufficient balance before withdrawal
Prevents transfer to same account
Validates sender and receiver account existence
Displays appropriate error messages
⚠️ Current Limitations
Maximum of 500 accounts
Data is not persistent (no file storage)
No authentication system (PIN/password)
No transaction history tracking
🚀 Future Enhancements
File handling for permanent data storage
Account authentication (PIN-based login)
Transaction history log
Account deletion functionality
Improved formatted output
Use of dynamic memory allocation
Refactoring with helper functions for cleaner logic
📚 Learning Outcomes
Through this project, the following core programming concepts are reinforced:
Structured programming approach
Working with arrays of structures
Control flow management
Nested looping logic
Modular function design
Error handling strategies
👩‍💻 Author
Developed as an academic and learning project to strengthen foundational C programming skills and understand real-world system design principles.
📄 License
This project is open for educational use and improvement.
