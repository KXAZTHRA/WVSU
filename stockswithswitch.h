#include <iostream>
#include <string>
#include <iomanip>
#include <array>
#include <algorithm>
using namespace std;

bool isnumber(string input);
bool validmixnumber(string input);


void display_message() {
    string message = "\nWELCOME TO THE STOCKS CALCULATOR.\n\n This program allows you to enter the stock price and the number\nof shares, and it will calculate the total stock price for you.\n\n";
    cout << message;
}


int get_type() {
    int type;
    
    while (true) {
        cout << "Enter 1 if the stock price contains a fraction. Press 2 if it is a whole number: ";
        cin >> type;
        if (type == 1 || type == 2) {
            return type;  // Return the valid input.
        } else {
            continue;
        }
    }
}


int get_int() {
    string prompt= "Input number of shares: ";
    string input;

    cout << endl;
    while (true) {
        cout << prompt;
        cin >> input;

        // Reject not number input, negative number input
        if (!isnumber(input) || stoi(input) < 0) {
            continue;
        }

        return stoi(input);
    }
}


bool isnumber(string input) {
    for (char character: input) {
        if (!isdigit(character)) {
            return false;
        }
    }

    return true;
}


array<int, 3> get_mixnumber() {
    string prompt = "Input mix number: ";
    string input;
    size_t delimiter;
    array<int, 3> mix_number;

    while (true) {
        cout << prompt;
        cin >> input;

        if(!validmixnumber(input)) {
            continue;
        }

        delimiter = input.find('/');

        mix_number[0] = stoi(input.substr(0, delimiter - 1));
        mix_number[1] = stoi(input.substr(delimiter - 1, delimiter));
        mix_number[2] = stoi(input.substr(delimiter + 1, input.length()));

        return mix_number;
    }    
}

int get_wholedollar() {
    string prompt = "Input whole dollar number: ";
    string input;
    int wholedollar;

    while (true) {
        cout << prompt;
        cin >> input;

        if (!isnumber(input) || stoi(input) < 0) {
            continue;
        }

        return stoi(input);
    }    
}

bool validmixnumber(string input) {
    size_t delimiter;

    if (count(input.begin(), input.end(), '/') != 1) {
       return false;
    }
        
    delimiter = input.find('/');

    if (delimiter != input.length() - 2) {
        return false;
    }

    for (char character : input) {
        if (character == '/') {
            continue;
        }
        else if (!isdigit(character)) {
            return false;
        }
    }

    return true;
}


double calculate_stocks2(array<int, 3> mix_number) {
    // mix_number[0] == whole, mix_number[1] == numerator, mix_number[2] == denominator
    return mix_number[0] + ((double) mix_number[1] / mix_number[2]);
}


void display_total_price(int shares, double total_stocks) {
    cout << "The total price of the user's stock is $" << setprecision(2) << fixed << shares * total_stocks << endl;
}


void display(int shares, double wholedollar){
    cout << "The total price of the user's stock is $" << setprecision(2) << fixed << shares * wholedollar << endl;
}


bool choice(void) {
    // Declare an array
    string decision;

    // Loop for making sure that the user input only "yes" or "no"
    while (true) {
        // Ask user for a decision
        cout << "\nDo you want to continue? Yes or No: ";
        cin >> decision;
    
        // Convert the text to uppercase, making the input case-insensitive
        decision[0] = toupper(decision[0]);
        
        if (decision[0] == 'Y') {
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
