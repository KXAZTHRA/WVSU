#include "hypotenuse.h"

int main() {
    // Length[0] == base 
    // Length[1] == perpendicular side
    array<double, 2> length = get_input(); 

    double hypotenuse = calcH(length[0], length[1]);
    cout << "\nThe hypotenuse of the triangle: " << hypotenuse << endl;

    return 0;
}
