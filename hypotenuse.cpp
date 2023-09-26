#include <iostream>
#include <array>
#include <cmath>
#include <limits>
using namespace std;

void clear_input();
array<double, 2> get_input();
double calcH(double length1, double length2);

int main() {
    // Length[0] == base 
    // Length[1] == perpendicular side
    array<double, 2> length = get_input(); 

    double hypotenuse = calcH(length[0], length[1]);
    cout << "\nThe hypotenuse of the triangle: " << hypotenuse << endl;

    return 0;
}


array<double, 2> get_input() {
    array<string, 2> text = {"Enter the length of the base: ", "Enter the perpendicular side of the triangle: "};
    array<double, 2> number;

    for (int i = 0; i < 2; i++) {
        cout << text[i];
        cin >> number[i];

        if (cin.fail()) {
            clear_input();
            i--;
            continue;
        }
        else if (number[i] < 1) {
            clear_input();
            i--;
            continue;
        }
    }

    return number;
}


double calcH(double length1, double length2) {
    return sqrt(pow(length1, 2) + pow(length2, 2));
}


void clear_input() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
