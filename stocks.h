#include <iostream> // cin and cout
#include <string> // stod() and stoi()
#include <iomanip> // setprecision and fixed
#include <algorithm> // count(), begin(), end()
#include <windows.h> // Sleep() and system()
#include <vector> // vector<data_type> 
using namespace std; 

const double typingspeed = 0.25;

bool isnumber(string input);
bool validmixnumber(string input);
void type(string word, int typingspeed);


void display_message() {
    // Display Welcome message

    string message = "WELCOME TO THE STOCKS CALCULATOR!\n\n 1.) To use this program, input 1 integer data for the number of companies;\n 2.) Then, input another 1 integer data for the shares of every company;\n 3.) Lastly, input a mix number (e.g. 11/2) for the stocks value.\n\nThe program will start calculating the total price of the company's stocks, and create a summary table for every company.\n\n\n";
    // Default typing speed
    type(message, typingspeed);
    Sleep(5);
    system("CLS");
}


void type(string word, int typingspeed) {
    // "Type" messages or prompts in the terminal

    // Iterate between every character in our message
    for (int i = 0; i < word.length(); i++) {
        Sleep(typingspeed);
        cout << word[i];
    }
}


string get_name(string prompt) {
    string input = "";

    type(prompt, typingspeed);
    cin.ignore();
    getline(cin, input);

    return input;
}


int get_int(string prompt) {
    // Get validated integer value 
    string input;

    while (true) {
        type(prompt, typingspeed);
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


double get_mixnumber(string prompt) {
    string input;
    size_t delimiter;
    int mix_number[3];

    while (true) {
        type(prompt, typingspeed);
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

        if (mix_number[1] >= mix_number[2]) {
            continue;
        }

        return mix_number[0] + (double) mix_number[1] / mix_number[2];
    }    
}


bool validmixnumber(string input) {
    size_t delimiter;

    /*Check if input has more than '/' characters
    ex. don't accept "12/3/4", accept "123/4"*/ 
    if (count(input.begin(), input.end(), '/') != 1 || input.length() < 4) {
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


void display_total_price(double totalPrice, string name) {
    cout << "The total price of " << name << "'s stocks is $" << setprecision(2) << fixed << totalPrice << endl << endl;
}


void table(vector<string> name, vector<int> shares, vector<double> stocks, vector<double> totalPrice, int companies) {
    double total_company_stocks = 0;

    cout << "COMPANY\t\t\tSHARES\t\tSTOCKS\t\tTOTAL PRICE\n";
    for (int i = 0; i < companies; i++) {
        cout << name[i] << "\t\t" << shares[i] << "\t\t$" << stocks[i] << "\t\t$" << totalPrice[i] << endl;
        total_company_stocks += totalPrice[i];
    }

    cout << "\nThe total stocks of all the companies: $" << fixed << setprecision(2) << total_company_stocks << endl; 
}


bool choice(void) {
    // Declare an array
    string decision;

    // Loop for making sure that the user input only "yes" or "no"
    while (true) {
        // Ask user for a decision
        type("\nDo you want to continue? Yes or No: ", typingspeed);
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