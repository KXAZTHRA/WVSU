#include <iostream>
#include <string>
#include <iomanip>
#include <array>
#include <algorithm>
using namespace std;

bool isnumber(string input);
bool validmixnumber(string input);


void display_message() {
    string message = "WELCOME TO THE STOCKS CALCULATOR.\n\n 1.) To use this program, input 1 integer data for the whole-dollar portion of the stock;\n 2.) Then, input 2 integer data for the fraction portion of the stock;\n 3.) The program will calculate the total stocks for you.\n\n";
    cout << message;
}


int get_int(int order) {
    string prompts[] = {"Input number of shares: ", "Input whole dollar portion: ", "Input the numerator of the fraction portion: ", "Input the denominator of the fraction portion: "};
    string input;

    cout << endl;
    while (true) {
        cout << prompts[order];
        cin >> input;

        // Reject not number input, negative number input, and zero denominator
        if (!isnumber(input) || stoi(input) < 0 || (order == 3 && stoi(input) == 0) || (order > 1 && stoi(input) > 8)) {
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
