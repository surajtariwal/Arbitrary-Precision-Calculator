# Arbitrary-Precision-Calculator
A C-based Arbitrary Precision Calculator that performs large number arithmetic (beyond standard data type limits) using Doubly Linked Lists.

📌 Overview

This project implements an Arbitrary Precision Calculator in C that performs arithmetic operations on extremely large integers beyond the limits of built-in data types.
The calculator uses Doubly Linked Lists to store and process each digit individually, enabling operations on numbers of virtually unlimited size.

🚀 Features

➕ Addition of large numbers,
➖ Subtraction of large numbers,
✖️ Multiplication,
➗ Division,
Handles numbers larger than long long limits,
Dynamic memory allocation,
Efficient digit-by-digit computation,
Modular design with separate functions,

🛠 Technologies Used

C Programming,
Doubly Linked List,
Dynamic Memory Allocation (malloc, free),
Modular Programming,
Makefile (Linux/GCC),

⚙️ How It Works

Large numbers are stored digit-by-digit in a Doubly Linked List.
Each node represents a single digit.
Arithmetic operations are performed similar to manual calculation:
Carry handling for addition/multiplication
Borrow handling for subtraction
Repeated subtraction / long division method for division
Result is stored in a separate linked list.

🏗 Project Structure
main.c
addition.c
subtraction.c
multiplication.c
division.c
header.h


▶️ How to Compile & Run
make
./apc
