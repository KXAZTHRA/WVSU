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


int calcPopulation(int population, int days) { // current_term == population
    int last_term, temp;
    
    for (int i = 0; i < days / 5; i++) {
        temp = last_term;
        last_term = population;
        population = last_term + temp;
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