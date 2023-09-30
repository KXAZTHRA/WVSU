#include <iostream>
#include <limits>
using namespace std;

void clear_input();
bool isnumeric(int number);

int get_input(int order) {
    string text[] = {"Initial population size: ", "Number of days: "};
    int number;
    clear_input();

    while (true) {

        cout << text[order];
        cin >> number;

        if (cin.fail()) {
            clear_input();
            continue;
        }
        else if (number < 1) {
            clear_input();
            continue;
        }
        
        return number;
    }
}


int calcPopulation(int population, int days) { // population = population
    int current_term = 0, last_term;
    
    for (int i = 0; i < days / 5; i++) {
        last_term = current_term;
        current_term = population;
        population = current_term + population;
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


void clear_input() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
}