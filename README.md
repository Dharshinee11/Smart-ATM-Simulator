# 🏧 Smart ATM Simulator

A secure and modular **ATM Simulator developed in C** that demonstrates real-world ATM operations through a structured, multi-module software architecture.

The project simulates essential banking operations such as PIN authentication, balance checking, deposits, withdrawals, transaction history, spending analytics, account insights, PIN management, and ATM cash availability monitoring.



## 📌 Project Overview

The **Smart ATM Simulator** is a console-based banking application developed using the C programming language.

Unlike a basic ATM program that only performs simple deposit and withdrawal operations, this project is designed using a **modular architecture**, where different responsibilities are separated into independent source and header files.

The system focuses on:

- 🔐 Secure user authentication
- 💰 Account and balance management
- 💳 Deposits and withdrawals
- 📜 Transaction history
- 📊 Spending analytics
- 📈 Account insights
- 🔑 PIN management
- 🏧 ATM cash availability monitoring
- 💾 Persistent account data

The project demonstrates practical concepts of **C programming, modular programming, file handling, functions, structures, conditional logic, and data management**.

---


## ✨ Key Features

### 🔐 1. Secure PIN Authentication

The system provides PIN-based authentication before allowing access to ATM operations.

- PIN verification
- Maximum 3 login attempts
- Incorrect PIN detection
- Account lock after repeated failed attempts
- Secure PIN change functionality

### 💰 2. Balance Management

Users can view and manage their current account balance.

- Check available balance
- Automatic balance updates
- Low-balance notification
- Balance validation during transactions

### 💵 3. Deposit Money

Users can deposit money into their account.

The system:
1. Accepts the deposit amount
2. Validates the input
3. Updates the account balance
4. Records the transaction
5. Saves the updated account information

### 💸 4. Withdraw Money

Users can withdraw money from their account.

Before processing a withdrawal, the system validates:

- Available account balance
- Withdrawal amount
- ATM cash availability
- Supported cash denominations

### 📜 5. Transaction History

The system records account transactions such as:

- Deposits
- Withdrawals
- Transaction amounts
- Account activity

### 📊 6. Spending Analytics

The analytics module processes transaction information to provide useful spending information.

It can be extended to identify:

- Total spending
- Withdrawal patterns
- Transaction frequency
- Account usage

### 🧠 7. Account Insights

The system provides account-level insights based on the user's financial activity.

Examples include:

- Current balance status
- Transaction activity
- Spending behavior
- Low-balance conditions

### 🔑 8. PIN Management

Users can securely change their ATM PIN.

The system:

1. Verifies the existing PIN
2. Accepts a new PIN
3. Validates the PIN format
4. Updates the stored PIN

### 🏧 9. ATM Cash Monitoring

The ATM module simulates physical cash availability.

Before dispensing money, the system checks whether the requested amount can be fulfilled using the available denominations.

### 💾 10. Account Data Persistence

The application supports file-based account persistence.

Account information can be:

- Loaded when the application starts
- Updated after transactions
- Saved before the application exits

---
## 🏗️ Project Architecture

The Smart ATM Simulator follows a **modular architecture**, where different responsibilities are separated into dedicated C source and header files.

                    SMART ATM SIMULATOR
                            │
                            ▼
                     ┌────────────┐
                     │   main.c   │
                     │ ATM Control│
                     └─────┬──────┘
                           │
          ┌────────────────┼────────────────┐
          ▼                ▼                ▼
    ┌────────────┐  ┌──────────────┐  ┌────────────┐
    │  Security  │  │ Transactions │  │    Cash    │
    │   Module   │  │    Module    │  │   Module   │
    └────────────┘  └──────────────┘  └────────────┘
          │                │                │
          ▼                ▼                ▼
     PIN Login         Transaction       Cash Status
     PIN Change        History           Validation
                       Deposits           Dispensing
                       Withdrawals
                           │
                           ▼
                    ┌────────────┐
                    │ Analytics  │
                    │   Module   │
                    └────────────┘


 📂 Project Structure
 ```text
Smart-ATM-Simulator/
│
├── main.c
│
├── atm.c
├── atm.h
│
├── security.c
├── security.h
│
├── transaction.c
├── transaction.h
│
├── cash.c
├── cash.h
│
├── analytics.c
├── analytics.h
│
├── .gitignore
│
└── README.md
```

Module Responsibilities
File	Responsibility
main.c	Controls the main program flow and ATM menu
atm.c / atm.h	= Handles core ATM operations
security.c / security.h =	Handles PIN authentication and PIN management
transaction.c / transaction.h =	Records and manages transaction history
cash.c / cash.h =	Manages ATM cash availability and dispensing
analytics.c / analytics.h =	Provides spending analytics and account insights
.gitignore =	Prevents unnecessary compiled files from being tracked

🔄 Application Workflow
```text
                 ┌─────────────────────┐
                 │     Start ATM       │
                 └──────────┬──────────┘
                            │
                            ▼
                 ┌─────────────────────┐
                 │ Load Account Data   │
                 └──────────┬──────────┘
                            │
                            ▼
                 ┌─────────────────────┐
                 │  PIN Authentication │
                 └──────────┬──────────┘
                            │
                    Authentication
                       Successful?
                      /          \
                    No            Yes
                    │              │
                    ▼              ▼
                 Exit        Display ATM Menu
                                   │
                                   ▼
                         ┌──────────────────┐
                         │ Select Operation │
                         └────────┬─────────┘
                                  │
              ┌───────────────────┼───────────────────┐
              │                   │                   │
              ▼                   ▼                   ▼
          Balance             Deposit             Withdraw
              │                   │                   │
              └───────────────────┼───────────────────┘
                                  │
                                  ▼
                         Record Transaction
                                  │
                                  ▼
                         Update Account Data
                                  │
                                  ▼
                            Save Account
                                  │
                                  ▼
                            Return to Menu
```

## Conclusion

The Smart ATM Simulator is a modular C-based application designed to simulate the core functionalities of a real-world ATM system. The project integrates secure PIN authentication, account management, cash withdrawal and deposit, transaction history, ATM cash monitoring, and spending analytics within a single structured system.

The project follows a modular architecture in which each functionality is separated into dedicated source and header files. This improves code organization, maintainability, testing, and future scalability while demonstrating practical application of C programming concepts such as functions, file handling, data validation, modular programming, and structured program design.

Overall, the project provides a practical understanding of how multiple software components can work together to build a reliable and secure transaction-oriented system. The modular design also provides a foundation for future enhancements such as multi-user account support, stronger authentication, database integration, graphical interfaces, and real-time monitoring.

## 🚀 Future Enhancements

The current software-based ATM simulator can be extended into a **hardware-integrated ATM prototype**, connecting the C-based transaction logic with physical input, display, and cash-dispensing components.

- 🔧 Hardware-based ATM prototype using a microcontroller
- 💳 RFID/NFC-based card authentication
- 🔢 Physical keypad for PIN entry
- 🖥️ LCD/OLED display for ATM interaction
- 🔐 Hardware-assisted secure authentication
- 🏧 Servo/stepper-based simulated cash dispensing mechanism
- 💰 IR/optical sensors for cash detection
- 🚨 Buzzer and status indicators for transaction alerts
- 📡 IoT-based ATM status and monitoring
- 🗄️ Database integration for account and transaction management
- 📱 Real-time transaction notifications
- 📊 Advanced spending analytics and visualization
- 👨‍💼 Admin dashboard for ATM monitoring

---

## 👩‍💻 Author

**Sreedharshinee A**

GitHub: [Dharshinee11](https://github.com/Dharshinee11)

---

## 📄 License

This project is developed for educational and academic purposes.
