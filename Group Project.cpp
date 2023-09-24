#include <iostream>
#include <limits>
#include <array> 
using namespace std;

string get_Dayinput();
void get_Validatedtime(int& h, int& m);
int getCallDuration();
double calculate(string day, int hour, double callLength);
bool choice(void);
void clear_input();

int main() {
    int h, m, callDuration;

    do {
        // Get day
        string day = get_Dayinput();

        // Get the time when the call started 
        get_Validatedtime(h, m);

        // Get call length
        callDuration = getCallDuration();

        // Calculate fare
        double fare = calculate(day, h, callDuration);

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
        for (string day : days) {
            if (text == day) {
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


bool isNumeric(const string& str) {
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

void get_Validatedtime(int& h, int& m) {
    string milTime;
    string delimiter = ":";
    bool isValidTime = false;

    do {
        cout << "\nTime the call started (in military format e.g. 16:00): ";
        cin >> milTime;

        // to check if milTime is exactly 5 characters
        if (milTime.length() != 5) {
            cout << "\nInvalid input. Please try again using HH:MM.\n";
            continue;
        }

        if (milTime[2] != ':') {
            clear_input();
            continue;
        }

        size_t pos = 0;
        string token;

        int hours, minutes;
        bool isValidHour = true;

        if ((pos = milTime.find(delimiter)) != string::npos) {
            token = milTime.substr(0, pos);

            // conversion of hours into an int variable
            if (token == "00" || token == "0") {
                hours = 0;
            } else {

                // calling the isNumeric function to check if it's a valid integer
                if (isNumeric(token)) {
                    hours = stoi(token);
                } else {
                    cout << "Invalid value. Please enter a valid integer for hours." << endl;
                    isValidHour = false;
                    break;
                }

                // to check if hours are in the valid range
                if (hours < 0 || hours > 24) {
                    cout << "Invalid value. Please enter an hour between 0 and 24." << endl;
                    isValidHour = false;
                    break;
                }
            }

            milTime.erase(0, pos + delimiter.length());
        }

        // to check if hour is valid before proceeding
        if (!isValidHour) {
            continue;
        }

        // to check if there are no more colons remaining in milTime
        if (milTime.find(delimiter) != string::npos) {
            cout << "Invalid value. Please enter a valid integer for minutes." << endl;
            continue;
        }

        // the remaining value in milTime will be the minutes
        if (isNumeric(milTime)) {
            minutes = stoi(milTime);
        } else {
            cout << "Invalid value. Please enter a valid integer for minutes." << endl;
            continue;
        }

        // to check if minutes are in the valid range
        if (minutes < 0 || minutes > 59) {
            cout << "Invalid value. Please enter minutes between 0 and 59." << endl;
            continue;
        }

        h = hours;
        m = minutes;

        isValidTime = true;

    } while (!isValidTime);
}

int getCallDuration() {
    string input;
    int num;

    while (true) {
        cout << "Enter call duration in minutes: ";
        cin >> input;

        bool valid = true;

        for (int i : input) {
            if (isdigit(i) == false) {
                valid = false;
                break;
            }
        }

        if (valid) {
            try {
                num = stoi(input);
                if (num > 0) {
                    return num;
                }
            }
            catch (...) {
                valid = false;
            }
        }

        if (valid == false) {
            cout << "Invalid input" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        }
    }
}


double calculate(string day, int hour, double callLength) {
    string weekdays[] = {"MO", "TU", "WE", "TH", "FR"};
    double fare;
    
    for (string weekday : weekdays) {
        if (day == weekday) {
            if (hour >= 8 && hour <= 18) {
                fare = 0.40 * callLength;
            }
            else {
                fare = 0.25 * callLength;
            }

            return fare;
        }
    }

    fare = 0.15 * callLength;
    return fare;
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
