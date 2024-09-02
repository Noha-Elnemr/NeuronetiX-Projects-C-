# Personal Finance Tracker Project

## Introduction

The **Transaction Management System** is designed to assist users in managing their financial transactions through a command-line interface. It allows users to enter transaction details, view and sort transactions, and analyze their financial data. This document outlines the system's functionality, how to use it, and potential areas for future enhancement.

## System Overview

The system provides the following key features:

- **Input Transactions**: Record details of new financial transactions.
- **View Transactions**: Display a list of all transactions with optional sorting.
- **View Summary**: Show a financial summary including total income, expenses, and balance.
- **Get Insights**: Offer insights into spending habits by category.

## Features and Functionality

### 3.1. Input Transactions

**Purpose**: To add new financial transactions into the system.

**Process**:

- **Description**: Enter a brief description of the transaction (e.g., "Lunch", "Electric Bill"). This helps in identifying and categorizing the transaction.
- **Amount**: Input the monetary value of the transaction. Positive values are recorded as income, while negative values represent expenses. This distinction allows for proper financial tracking.
- **Category**: Specify a category for the transaction (e.g., Food, Entertainment, Bills). This helps in categorizing the expenses and analyzing spending patterns.

**Details**:

- Each transaction is recorded with its description, amount, and category.
- Transactions are stored in arrays or lists and indexed by their order of entry.

### 3.2. View Transactions

**Purpose**: To display a list of all recorded transactions.

**Features**:

- **Display**: Shows transactions in a tabular format with columns for Description, Amount, and Category.
- **Sorting**: Provides an option to sort transactions by amount. Users can choose to see transactions ordered from the smallest to the largest amount or vice versa.

**Process**:

- Transactions are presented with clear formatting for easy readability.
- Sorting functionality helps users quickly identify high or low-value transactions.

### 3.3. View Summary

**Purpose**: To provide a summary of financial transactions.

**Features**:

- **Total Income**: Sum of all positive transaction amounts. This represents the total income.
- **Total Expenses**: Sum of all negative transaction amounts. This represents the total expenses.
- **Balance**: The net balance, calculated as Total Income minus Total Expenses. This indicates the overall financial position.

**Process**:

- Calculates the total income and expenses by iterating through all transactions.
- Displays the summary in a straightforward format for quick assessment of financial status.

### 3.4. Get Insights

**Purpose**: To analyze and provide insights into spending habits by category.

**Features**:

- **Total Expenses**: Displays the overall amount spent across all transactions.
- **Category Analysis**: Breaks down expenses by category and shows each category's contribution to the total expenses. Provides a percentage to illustrate how each category impacts overall spending.

**Process**:

- Aggregates expenses by category to determine how much has been spent in each category.
- Calculates and displays the percentage of total expenses attributed to each category, helping users understand their spending patterns.

## How to Use

### Using the Menu:

- **Input Transactions**: Select this option to record a new transaction. Follow prompts to enter the description, amount, and category.
- **View Transactions**: Choose this option to view all transactions. You can also sort transactions by amount.
- **View Summary**: Select this to view the summary of total income, expenses, and balance.
- **Get Insights**: Choose this option to get detailed insights into spending by category.
- **Exit**: Select this option to close the application.

### Example Workflow:

1. **Input**: Add a transaction by providing a description like "Groceries", an amount such as "-30.00", and a category like "Food".
2. **View Transactions**: Display all entered transactions and choose to sort by amount if desired.
3. **Summary**: Check the total income, total expenses, and balance.
4. **Insights**: Review spending by category to understand where most of the money is going.

## Troubleshooting

- **Invalid Inputs**: Ensure all inputs are correctly formatted. For example, amounts should be numerical values, and descriptions and categories should be properly spelled.
- **Sorting Issues**: If sorting does not work as expected, check that the sorting logic is correctly implemented and applied.

## How to run the project

- **in the terminal write** `g++ Personal_Finance_Tracker.cpp -o finance`
- **to genrate** `./finance`
