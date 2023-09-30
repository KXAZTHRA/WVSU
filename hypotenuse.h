#include <iostream>
#include <array>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

void clear_input();
bool isnumeric(string number);

array<double, 2> get_input() {
    array<string, 2> text = {"Enter the length of the base: ", "Enter the perpendicular side of the triangle: "};
    array<string, 2> input;
    array<double, 2> number;

    // repeat 2 times 
    for (int i = 0; i < 2; i++) {

        cout << text[i];
        cin >> input[i];

        if (!isnumeric(input[i]) || stod(input[i]) < 0) { 
            clear_input();
            i--;
            continue;
        }

        number[i] = stod(input[i]);
    }

    return number;
}


double calcH(double length1, double length2) {
    // formula of the pythagorean theorem
    return sqrt(pow(length1, 2) + pow(length2, 2));
}


bool isnumeric(string number) {
    // count how many '.' in the whole string (from the beginning to the end)
    int Count = count(number.begin(), number.end(), '.'); 

    // Automatic, the input is not numeric if it contains more than 1 '.'
    if (Count != 1) {
        return false; 
    }


    for (char character : number) {
        // Skips '.' character
        if (character == '.') {
            continue;
        }
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