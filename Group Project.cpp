#include <iostream>
#include <limits>
#include <array> 
using namespace std;

string get_Dayinput();
bool choice(void);
void clear_input();

int main() {
    
    do {
        // Get day
        string day = get_Dayinput();

        // Get the time when the call started 
        
        // Get call length
        // Calculate fare
        // Display Fare
        
    } while(choice());
}


string get_Dayinput() {
    string days[] = {"MO", "TU", "WE", "TH", "FR", "SA", "SU"};
    string text; 
    bool isAlpha, isDay;

    while (true) {
        isAlpha = true, isDay = false;

        cout << "The day the call started (MO, TU, WE, TH, FR, SA, SU): ";
        cin >> text;

        // within the alphabet 
        for (int letter = 0; letter < text.length(); letter++)
        {
            if (!isalpha(text[letter])) {
                isAlpha = false;
                break;
            }

            text[letter] = toupper(text[letter]);
        }

        if (isAlpha != true) {
            clear_input();
            continue;
        }

        // within the days in a week  
        for (int day = 0; day < days->length(); day++) {
            if (text == days[day]) {
                isDay = true;
                break;
            }
        }

        if (!isDay) {
            clear_input();
            continue;
        }

        return text;
    }
}


bool choice(void) {
    // Declare an array
    string decision;

    // Loop for making sure that the user inputed only "yes" or "no"
    while (true) {
        // Ask user for a decision
        cout << "\nDo you want to continue? Yes or No: ";
        cin >> decision[0];
    
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
