#include <iostream>
#include <limits>

using namespace std;

int get_input (int order);
double fraction (int numerator, int denominator);
double stock (int price, double fraction);
double final_shares (double stock, double shares);
void output (double final_share);
bool isnumeric(string number);
bool choice(void);

int main () {
    int shares, price, numerator, denominator;
    double decimal, stocks, final_share;
    
    do{

    shares = get_input(0);
    price = get_input(1);
    numerator = get_input(2);
    denominator = get_input(3);

    decimal = fraction(numerator, denominator);
    stocks = stock (price, decimal);
    final_share = final_shares (shares, stocks);
    output(final_share);



    } while (choice());
}


int get_input (int order) {
    string text [] = { "Number of shares: ", "Whole dollar of a price: $", "Numerator: ", "Denominator: "};
    string number;
  
     while (true) {

        cout << text[order];
        cin >> number;

        if (!isnumeric(number) || stoi(number) < 1) {
            continue;
        }
        
        return stoi(number);
    }
}

double fraction (int numerator, int denominator) {
    double fraction = (double) numerator/denominator;

    return fraction;
    
}

double stock (int price, double fraction) {
    double stock = price+fraction;

    return stock;
}

double final_shares (double stock, double shares) {
    double final_shares = stock*shares;

    return final_shares;
}

bool isnumeric(string number) {
    for (char character : number) {
        if (!isdigit(character)) {
            return false;  
        }
    }

    return true;
}


bool choice(void) {
    // Declare an array
    string decision;

    // Loop for making sure that the user inputed only "yes" or "no"
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


void output (double final_share) {
    cout << "The company's final share is $"<< final_share << ". " << endl;
}