#include <iostream>
#include <string>
#include <windows.h>
#include <iomanip>
using namespace std;

void type(string word);
bool isnumeric(string number);
double put_comma(double number);


double get_double(string prompt) {
    string input;

    while (true) {
        type(prompt);
        cin >> input;

        if (!isnumeric(input) || stod(input) < 0) {
            continue;
        }

        return stod(input);
    }
}


void type(string word) {
    // "Type" messages or prompts in the terminal

    // Iterate between every character in our message
    for (int i = 0; i < word.length(); i++) {
        Sleep(25);
        cout << word[i];
    }
}


bool isnumeric(string number) {
    // count how many '.' in the whole string (from the beginning to the end)
    int Count = count(number.begin(), number.end(), '.'); 

    // Automatic, the input is not numeric if it contains more than 1 '.'
    if (Count > 1) {
        return false; 
    }


    for (char character : number) {
        // Skips '.' character
        if (character == '.') {
            continue;
        }
        if (!isdigit(character)) {
            return false;  
        }
    }

    return true;
}


void display(int years, double housePrice, double downPayment, double loanBalance, double interestPayment, double mortgageCost, double taxSavings, double afterTaxCost) {
    cout << setprecision(2) << fixed << endl
         << "Year: " << years << endl
         << "Loan Balance: $" << put_comma(loanBalance) << endl
         << "Interest Payment: $" << put_comma(interestPayment) << endl
         << "Mortgage Cost: $" << put_comma(mortgageCost) << endl
         << "Tax Savings: $" << put_comma(taxSavings) << endl
         << "After-tax Cost: $" << put_comma(afterTaxCost) << endl << endl;
    Sleep(3000);
}


bool choice(void) {
    // Declare an array
    string decision;

    // Loop for making sure that the user input only "yes" or "no"
    while (true) {
        // Ask user for a decision
        type("\nDo you want to continue? Yes or No: ");
        cin >> decision;
        cout << endl;
    
        // Convert the text to uppercase, making the input case-insensitive
        decision[0] = toupper(decision[0]);
        
        if (decision[0] == 'Y') {
            system("CLS");
            return true;
        }
        else if (decision[0] == 'N') {
            return false;
        }
        else {
            continue;
        }
    }
}


double put_comma(double number) {
    return number;
}   