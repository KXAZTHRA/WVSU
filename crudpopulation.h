#include <iostream>
#include <limits>
#include <string>
using namespace std;

void clear_input();
bool isnumeric(string number);

int get_input(int order) {
    string text[] = {"Initial population size: ", "Number of days: "};
    string number;

    while (true) {

        cout << text[order];
        cin >> number;

        if (!isnumeric(number) || stoi(number) < 1) {
            clear_input();
            continue;
        }
        
        return stoi(number);
    }
}


int calcPopulation(int population, int days) { // population = population
    int current_term = 0, last_term;
    
    for (int i = 0; i < days / 5; i++) {
        last_term = current_term;
        current_term = population;
        population = current_term + last_term;
    }

    return population;
}


void display(int finalSize, int population, int days) {
    cout << "\nThe crud's population after " << days << " days "  
         << "with an initial size of " << population << " pounds: "
         << finalSize << " pounds.\n";
}


bool choice(void) {
    // Declare an array
    string decision;
    clear_input();

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
            clear_input();
            continue;
        }
    }  
}


bool isnumeric(string number) {
    for (char character : number) {
        if (!isdigit(character)) {
            return false;  
        }
    }

    return true;
}


void clear_input() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
}