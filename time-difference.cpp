#include "time-difference.h"


int main() {
    Time start(get_time("Enter start time: ")), future(get_time("Enter future time: "));

    int start_minutes = convert_to_min(start); // 2:30 am 150 mins, 2:30 am 150 mins
    int final_minutes = convert_to_min(future); // 2:31 am 151 mins, 2:29 am 149 mins
    int time_difference = final_minutes - start_minutes;

    // Time difference is negative, add 24 hrs
    if (time_difference < 0) {
        time_difference += 1440;
    }


    display(time_difference);

    while (choice()) {
        int new_minutes = get_int("Enter Minutes: ");
        final_minutes += new_minutes; // add addtional minutes to future_minutes

        string time = convert_to_time(final_minutes);
        cout << "You are now in: " << time << endl;
    }

    return 0;
}