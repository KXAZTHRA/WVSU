#include <iostream>
using namespace std;
int main()
{
    int initial_size, days, next_term, number_of_sequences, second_size, final_size;
    char ans;

do
{
    cout << "Enter the initial size of the crud population (in pounds): ";
    cin >> initial_size;
    cout << "Enter the number of days: ";
    cin >> days;

    number_of_sequences = (days / 5) + 1;
    second_size = initial_size;

    for (int i = 3; i <= number_of_sequences; ++i) {
        next_term = initial_size + second_size;
        initial_size = second_size;
        second_size = next_term;
    }

    final_size = (number_of_sequences == 1 ? initial_size : second_size);

    cout << "The final size of the crud population after " << days << " days: " << final_size << " pound/s." << endl;

    cout << "Do you want to input another population size? If yes, enter the character 'y' and press return.\n";
    cin >> ans ;
} 
while (ans == 'y' || ans =='Y');
    cout << "Thank you and goodbye!\n";
    return 0;

}
