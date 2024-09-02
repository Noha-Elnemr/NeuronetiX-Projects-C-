#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

struct Transaction
{
    string description;
    double amount;
    string category;
};

// Global vector to store transactions
vector<Transaction> transactions;

void inputTransaction()
{
    Transaction t;
    cout << "Enter description: ";
    cin.ignore();
    getline(cin, t.description);
    cout << "Enter amount (positive for income, negative for expense): ";
    cin >> t.amount;
    cout << "Enter category: ";
    cin.ignore();
    getline(cin, t.category);
    transactions.push_back(t);
    cout << "Transaction added successfully!\n";
}

void viewTransactions()
{
    if (transactions.empty())
    {
        cout << "No transactions to display.\n";
        return;
    }

    cout << "\nAll Transaction\n";
    cout << left << setw(20) << "Description"
         << setw(10) << "Amount"
         << setw(15) << "Category" << endl;
    cout << string(45, '-') << endl;

    for (const auto &t : transactions)
    {
        cout << left << setw(20) << t.description
             << setw(10) << t.amount
             << setw(15) << t.category << endl;
    }
    char sortChoice;
    cout << "Do you want to sort transactions by amount? (y/n): ";
    cin >> sortChoice;

    if (sortChoice == 'y' || sortChoice == 'Y')
    {
        cout << "\nAll Transaction(sorted)\n";
        sort(transactions.begin(), transactions.end(), [](const Transaction &a, const Transaction &b)
             { return a.amount < b.amount; });
        cout << left << setw(20) << "Description"
             << setw(10) << "Amount"
             << setw(15) << "Category" << endl;
        cout << string(45, '-') << endl;

        for (const auto &t : transactions)
        {
            cout << left << setw(20) << t.description
                 << setw(10) << t.amount
                 << setw(15) << t.category << endl;
        }
    }
}

void viewSummary()
{
    cout << "\nSummary\n";
    double totalIncome = 0, totalExpenses = 0;
    for (const auto &t : transactions)
    {
        if (t.amount > 0)
            totalIncome += t.amount;
        else
            totalExpenses += t.amount;
    }

    double balance = totalIncome + totalExpenses;

    cout << "Total Income: " << totalIncome << endl;
    cout << "Total Expenses: " << totalExpenses << endl;
    cout << "Balance: " << balance << endl;
}

void getInsights()
{
    cout << "\nSpending Insight\n";
    if (transactions.empty())
    {
        cout << "No transactions to analyze.\n";
        return;
    }

    map<string, double> categoryExpenses;
    double totalExpenses = 0;

    for (const auto &t : transactions)
    {
        if (t.amount < 0)
        {
            categoryExpenses[t.category] += t.amount;
            totalExpenses += t.amount;
        }
    }

    cout << "Total Expenses: " << abs(totalExpenses) << endl;
    for (const auto &pair : categoryExpenses)
    {
        double percentage = (pair.second / totalExpenses) * 100;
        cout << "Category: " << pair.first << " - Spent: " << abs(pair.second) << " (" << percentage << "% of total)" << endl;
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\nPersonal Finance Tracker\n";
        cout << "1. Input Transaction\n";
        cout << "2. View Transactions\n";
        cout << "3. View Summary\n";
        cout << "4. Get Insights\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            inputTransaction();
            break;
        case 2:
            viewTransactions();
            break;
        case 3:
            viewSummary();
            break;
        case 4:
            getInsights();
            break;
        case 5:
            cout << "Exiting the program.  Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
