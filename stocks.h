#include <iostream> // cin and cout
#include <string> // stod() and stoi()
#include <iomanip> // setprecision and fixed
#include <array> // array<data_type, index>
#include <algorithm> // count(), begin(), end()
#include <windows.h> // Sleep()
using namespace std; 

bool isnumber(string input);
bool validmixnumber(string input);
void type(string word, int typingspeed);


void display_message() {
    // Display Welcome message

    string message = "WELCOME TO THE STOCKS CALCULATOR.\n\n 1.) To use this program, input 1 integer data for the whole-dollar portion of the stock;\n 2.) Then, input 2 integer data for the fraction portion of the stock;\n 3.) The program will calculate the total stocks for you.\n\n";
    // Default typing speed
    const int typingspeed = 50;
    type(message, typingspeed);
}


void type(string word, int typingspeed) {
    // "Type" messages or prompts in the terminal

    // Iterate between every character in our message
    for (int i = 0; i < word.length(); i++) {
        Sleep(typingspeed);
        cout << word[i];
    }
}


int get_int(int order) {
    // Get validated integer value 

    string prompts[] = {"Input number of shares: "};
    string input;

    cout << endl;

    while (true) {
        cout << prompts[order];
        cin >> input;

        // Reject not number input, negative number input, and zero denominator
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

                                      // Convert denominator character to integer
        if(!validmixnumber(input) ||  input[input.length() - 1] - '0' > 8) {
            continue;
        }

        delimiter = input.find('/');

        // "123/4"
        mix_number[0] = stoi(input.substr(0, delimiter - 1));
        mix_number[1] = stoi(input.substr(delimiter - 1, delimiter));
        mix_number[2] = stoi(input.substr(delimiter + 1, input.length())); // substr([start, end))

        if (mix_number[1] > mix_number[2]) {
            continue;
        }

        return mix_number;
    }    
}


bool validmixnumber(string input) {
    size_t delimiter;

    /*Check if input has more than '/' characters
    ex. don't accept "12/3/4", accept "123/4"*/ 
    if (count(input.begin(), input.end(), '/') != 1) {
       return false;
    }
        
    /* Find the index of the '/' character
    ex. "123/4", delimiter == [3] */
    delimiter = input.find('/');

    /*Check if the index of the delimiter is before the last character
    ex. dont accept "123/34", accept "123/4"*/
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


void table(int shares[], double stocks[], char company[]) {
    cout << "COMPANY\tSHARES\tSTOCKS\tTOTAL PRICE\n";

    for (int i = 0; i < 2; i++) {
        cout << company[i] << '\t' << shares[i] << "\t$" << stocks[i] << "\t$" << shares[i] * stocks[i] << endl;
    }

    double total_company_stocks = (shares[0] * stocks[0]) + (shares[1] * stocks[1]);

    cout << "\nThe total stocks of company A and B: $" << fixed << setprecision(2) << total_company_stocks << endl; 
}


bool choice(void) {
    // Declare an array
    string decision;

    // Loop for making sure that the user input only "yes" or "no"
    while (true) {
        // Ask user for a decision
        cout << "\nDo you want to continue? Yes or No: ";
        cin >> decision;
        cout << endl;
    
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
