#include <iostream>
#include <windows.h>
#include <string>
#include <algorithm>
using namespace std;

struct Time {
        int hours, minutes;
        bool isAM;
};


//int strings, Time

void type(string word) {
    // "Type" messages or prompts in the terminal

    // Iterate between every character in our message
    for (int i = 0; i < word.length(); i++) {
        Sleep(25);
        cout << word[i];
    }
}

Time get_time(string prompt) {
    string input;
    Time time;

    while (true) {
        type(prompt);
        getline(cin, input);

        if (input.length() > 8 || input.length() < 7) {
            cerr << "Invalid time!\n";
            continue;
        }
        else if (count(input.begin(), input.end(), ':') != 1 || count(input.begin(), input.end(), ' ') != 1) {
            cerr << "Invalid time!\n";
            continue;
        }

        // 2:30 pm
        int delimiter1 = input.find(':'); // 1
        int delimiter2 = input.find(' '); // 

        // 2:30 PM
        time.hours  = stoi(input.substr(0, delimiter1));
        time.minutes = stoi(input.substr(delimiter1 + 1, delimiter2)); 
        string AM_PM = input.substr(delimiter2 + 1, input.length());

        for (int i = 0; i < 2; i++) {
            AM_PM[i] = toupper(AM_PM[i]); // AM
        }

        if (time.hours < 0 || time.hours > 12) {
            cerr << "Invalid hour!\n";
            continue;
        }
        else if (time.minutes < 0 || time.minutes > 59) {
            cerr << "Invalid minutes!\n";
            continue;
        }
        else if (AM_PM == "AM") {
            time.isAM = true;
        }
        else if (AM_PM == "PM") {
            time.isAM = false;
        }
        else {
            cerr << "Invalid time!\n";
            continue;
        }

        return time;
    }
}


int convert_to_min(Time time) {
    int min;

    if (time.isAM == false && time.hours != 12) {
        time.hours += 12;
    }
    else if (time.isAM == true && time.hours == 12) {
        time.hours -= 12;
    }

    min = time.hours * 60 + time.minutes;
    
    return min;
}


void display(int time_difference) {
    string display = to_string(time_difference);

    type("The time difference is " + display + " minutes.\n");
}


bool choice(void) {
    // Declare an array
    string decision;

    // Loop for making sure that the user input only "yes" or "no"
    while (true) {
        // Ask user for a decision
        type("\nWould you like to travel more? Yes or No: ");
        cin >> decision;
        cout << endl;
    
        // Convert the text to uppercase, making the input case-insensitive
        decision[0] = toupper(decision[0]);
        
        if (decision[0] == 'Y') {

            cin.ignore();
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


bool isnumber(string input) {
    for (char character : input) {
        if (!isdigit(character)) {
            return false;
        }
    }

    return true;
}


int get_int(string prompt) {
    string input;

    while (true) {
        cout << prompt;
        cin >> input;

        if (!isnumber(input) || stoi(input) < 1) {
            continue;
        }

        return stoi(input);
    }
}


string convert_to_time(int minutes) {
    int count(1), hrs(minutes / 60); // count = 1

    while (hrs > 12) {
        hrs -= 12;
        count++;
    }

    string hours = to_string(hrs), mins = to_string(minutes % 60);

    if (hours.length() != 2) { 
        hours = '0' + hours;
    }
    
    if (mins.length() != 2) {
        mins = '0' + mins;
    }

    string output = hours + ':' + mins; // 04:09 pm

    if (hrs == 12) {
        if (count % 2 == 0) {
            output += " AM";
        }
        else {
            output += " PM";
        }
    }
    else if (count % 2 == 0) {
        output += " PM";
    }
    else {
        output += " AM"; 
    }

    return output;
}