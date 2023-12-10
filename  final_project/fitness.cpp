/*Final Proj 
Assume that your user is a fitness/wellness enthusiast, write a program that
(1) has function computing the current BMI
(2) has a function that computes daily calorie intake based on its food choices (you have to have a predefined data food intake)
(3) has a function that gives the non-workout/daily activities calories burn 
(4)if doing workout, the type of workout with various calorie burn value based on number of repetitions and sets
(5) shall be able to predict when to attain the desired weight based on date started and ended
(6)provide data  flow dialogue
(7)provide pseudocode
(8)provide (???) for data sets*/
#include "Dataset.h"

struct date {
    int month, day, year;
};

void display_message();
void type(string word);

double get_BMI();
double get_input (int order);
double bmi (double weight, double height);
string classification (double BMI);
void display (double BMI, double weight, double height);

double calories();
double getCalories(map<string, double> foodCalories);

double workout();
void display_valid_workouts();
double calculate_calories_burnt();

double get_double(string prompt);
date get_date(string prompt);
bool valid_date(string input);
bool isdecimal(string input);
void calculate_diet_timeline(double weight, double calories_consumed, double calories_burned);
date calculate_end_date(int days, date start_date);
void interpret(date end_date, int days);


int main() {
    // Display message about how to use the program
    display_message();

    // Ask and Calculate BMI
    double weight = get_BMI();

    // Ask user for foods eaten a day and compute the overall calorie intake
    double total_calories = calories();

    // Ask user for non-workout activities that may burn calories

    // Ask user for the type of workout with equivalent calorie burn values based on the number of repetition and sets
    double work_out_burn = workout();

    // Ask user for his/her desired weight, date the workout started and compute when will the user attain that desired weight
    calculate_diet_timeline(weight, total_calories, work_out_burn);
}

void display_message(){
    string message = "WELCOME TO THE HEALTH AND FITNESS CALCULATOR!\n\nThis program will help you achieve your health goals by\nproviding tools to track your BMI, monitor your food intake,\nrecord your workouts, and estimate your weight loss timeline.\n\nTo get started, follow these simple steps:\n1. Enter your current weight and height.\n2. Log your daily food intake.\n3. Record your workout sessions.\n4. Set your desired weight goal.\n\nThe program will then:\n- Calculate your BMI and interpret your weight status.\n- Track your total calorie intake and burn each day.\n- Estimate your weight loss timeline based on your goals.\n\nReady for a healthier you? Let's get started.\n\n";
    type(message);

}

void type(string word) {
    // "Type" messages or prompts in the terminal

    // Iterate between every character in our message
    for (int i = 0; i < word.length(); i++) {
        Sleep(25);
        cout << word[i];
    }
}

double get_BMI() {
    double weight, height, BMI;
    
    weight = get_input (0);
    height = get_input (1);
    BMI= bmi(weight,height);
    display(BMI,weight,height);
    cout <<  classification(BMI) << endl;
    Sleep(5000);

    return weight;

}

double get_input (int order) {
    string text [] = { "Enter weight (in kilograms): ", "Enter height (in meters): " };
    string number;
  
     while (true) {

        cout << text[order];
        cin >> number;

        if (!isdecimal(number) || stod(number) < 1) {
            continue;
        }
        
        return stod(number);
    }
}


double bmi (double weight, double height) {
    double bmi = weight/ (pow(height, 2));

    return bmi;
}


string classification(double BMI){ 
    if (BMI < 18.5) {
        return "Your BMI Classification is Underweight.\n";
    }
    else if (BMI >= 18.5 && BMI <= 24.9){
        return "Your BMI Classification is in Normal Range.\n";
    }
    else if (BMI >= 25 && BMI <= 29.9){
        return "Your BMI Classification is Overweight.\n";
    }
    else{
        return "Your BMI Classification is Obese.\n";
    }
}


void display (double BMI, double weight, double height) {
    cout << "\nYour BMI is " << setprecision(2) << fixed << BMI << endl;
}


double calories() 
{
   double totalCalories = getCalories(foodCalories);
   cout << "Total calories for the day: " << totalCalories << " calories." << endl << endl;

   return totalCalories;
}


double getCalories(map<string, double> foodCalories)
{
    double totalCalories = 0.0;
    vector<string> foodNames;

    cout << "Here are the list of food that are in the dataset. Add whatever you have eaten." << endl << endl;

   for (const auto& entry : foodCalories) 
   {
      foodNames.push_back(entry.first);
   }
   const int columnsPerRow = 5;

   for (size_t i = 0; i < foodNames.size(); i += columnsPerRow) 
   {
      for (int j = 0; j < columnsPerRow && (i + j) < foodNames.size(); ++j) 
      {
         cout << setw(30) << left << foodNames[i + j];
      }
         cout << endl;
   }

    cout << endl;
    
    string food = "";
    cin.ignore();
    while (true)
    {
        cout << "Enter food for breakfast (To proceed to lunch, input 'next'): ";
        getline(cin, food);
        transform(food.begin(), food.end(), food.begin(), ::toupper);

        if (food == "NEXT")
        {
            cout << endl;
            break;
        }


        if(foodCalories.find(food) != foodCalories.end())
         {
            totalCalories += foodCalories.at(food);
            cout << "Added " << food << " to calorie count." << endl;
         }
         else
         {
            cout << "Food not found in dataset.\n";
         }
    }

    
    
    while (true)
    {
        cout << "Enter food for lunch (To proceed to dinner, input 'next'): ";
        getline(cin, food);
        transform(food.begin(), food.end(), food.begin(), ::toupper);

        if (food == "NEXT")
         {
            cout << endl;
            break;
         }

         if(foodCalories.find(food) != foodCalories.end())
         {
            totalCalories += foodCalories.at(food);
            cout << "Added " << food << " to calorie count." << endl;
         }
         else
         {
            cout << "Food not found in dataset.\n";
         }
    }
    
    while (true)
    {
        cout << "Enter food for dinner (To proceed to dinner, input 'next'): ";
         getline(cin, food);
         transform(food.begin(), food.end(), food.begin(), ::toupper);

        if (food == "NEXT")
         {
            cout << endl;
            break;
         }

         if(foodCalories.find(food) != foodCalories.end())
         {
            totalCalories += foodCalories.at(food);
            cout << "Added " << food << " to calorie count." << endl;
         }
         else
         {
            cout << "Food not found in dataset.\n";
         }
    }

    
    
    while (true)
    {
        cout << "Enter food for snacks (To proceed, input 'exit'): ";
         getline(cin, food);
         transform(food.begin(), food.end(), food.begin(), ::toupper);

        if (food == "EXIT")
         {
            cout << endl;
            break;
         }
         if(foodCalories.find(food) != foodCalories.end())
         {
            totalCalories += foodCalories.at(food);
            cout << "Added " << food << " to calorie count." << endl;
         }
         else
         {
            cout << "Food not found in dataset.\n";
         }
    }

    return totalCalories;
}


double workout() {
    display_valid_workouts();
    return calculate_calories_burnt();
}


void display_map(const map<string, double>& exercise_map) {
    int count = 0;
    const int columns = 3;

    for (const auto& entry : exercise_map) {
        cout << left << setw(25) << entry.first;

        if (++count % columns == 0) {
            cout << endl;
        }
    }
}

void display_valid_workouts() {
    cout << "Valid Workouts Measured Per Minute:\n\n";
    display_map(exercisePerMinute);
    cout << "\n\nValid Workouts Measured Per Rep:\n\n";
    display_map(exercisePerRep);
    cout << endl << endl;
}


double get_time() {
    string text = "Enter workout duration (in minutes): ";
    string number;

    cout << text;
    cin >> number;

    if (!isdecimal(number) || stod(number) <= 0) {
        cout << "Invalid input, please try again.\n\n";
        return get_time();
    }

    return stod(number);
}

double calculate_time_cal(const string& workout, double time, const map<string, double>& exercisePerMinute) {
    if (exercisePerMinute.find(workout) != exercisePerMinute.end()) {
        double cal_per_min = exercisePerMinute.at(workout) * time;
        return cal_per_min;
    } else {
        cout << "Invalid workout, please try again.\n\n";
        return 0;
    }
}

double get_reps(int order) {
    string text[] = {"Enter number of sets: ", "Enter number of reps: "};
    string number;

    cout << text[order];
    cin >> number;

    if (!isdecimal(number) || stod(number) <= 0) {
        cout << "Invalid input, please try again.\n\n";
        return get_reps(order);
    }

    return stod(number);
}

double calculate_rep_cal(const string& workout, double sets, double reps, const map<string, double>& exercisePerRep) {
    if (exercisePerRep.find(workout) != exercisePerRep.end()) {
        double cal_per_rep = exercisePerRep.at(workout) * sets * reps;
        return cal_per_rep;
    } else {
        cout << "Invalid workout, please try again.\n\n";
        return 0;
    }
}

double calculate_calories_burnt() {
    double total_calories_burnt = 0;
    double calories = 0;

    
    while (true) {
        string workout;
        cout << "Enter your workout (or type 'none' to quit): ";
        getline(cin, workout);

        transform(workout.begin(), workout.end(), workout.begin(), ::toupper);

        if (workout == "NONE") {
            break;
        }

        if (exercisePerMinute.find(workout) != exercisePerMinute.end()) {
            double time;

            time = get_time();

            calories = calculate_time_cal(workout, get_time(), exercisePerMinute);
            cout << "Calories burnt for " << workout << ": " << calories << " cal.\n";

            total_calories_burnt += calories;
            cout << "Total calories burnt tracker: " << total_calories_burnt << " cal.\n\n";
        } else if (exercisePerRep.find(workout) != exercisePerRep.end()) {
            double sets, reps;

            sets = get_reps(0);
            reps = get_reps(1);

            calories = calculate_rep_cal(workout, sets, reps, exercisePerRep);
            cout << "Calories burnt for " << workout << ": " << calories << " cal.\n";

            total_calories_burnt += calories;
            cout << "Total calories burnt tracker: " << total_calories_burnt << " cal.\n\n";
        } else {
            cout << "Invalid workout, please try again.\n\n";
            continue;
        }
        cin.ignore();
    }

    cout << "\nThe total number of calories you burnt through workouts: " << total_calories_burnt << " cal.\n";
    return total_calories_burnt;
}


void calculate_diet_timeline(double weight, double calories_consumed, double calories_burned) {
    int days = 0;
    double calorie_difference, weight_gained, desired_weight;
    
    while (true) {
        desired_weight = get_double("\nWhat is your desired weight? (in kg): ");

        if (desired_weight == weight) {
            type("Desired weight is the same as your actual weight. Please enter another input!\n");
            continue;
        }

        break;
    }

    if (desired_weight > weight) {
        if (calories_consumed > calories_burned) {
            calorie_difference = calories_consumed - calories_burned;
            weight_gained = calorie_difference * 0.00013;

            while (weight + weight_gained < desired_weight) {
                weight += weight_gained;
                days++;
            }
        }
        else {
            type("You will not be able to achieve your desired weight base on your diet and workout plan! Please revise it ASAP.\n");
            return;
        }
    }
    else if (desired_weight < weight) {
        if (calories_consumed < calories_burned) {
            calorie_difference = calories_burned - calories_consumed;
            weight_gained = calorie_difference * 0.00013;

            while (weight - weight_gained > desired_weight) {
                weight -= weight_gained;
                days++;
            }
        }
        else {
            type("You will not be able to achieve your desired weight base on your diet and workout plan! Please revise it ASAP.\n");
            return;
        }
    }

    date start_date = get_date("What date did you start implementing your diet and workout? (in MM/DD/YY): ");
    date end_date = calculate_end_date(days, start_date);
    interpret(end_date, days);
}


double get_double(string prompt) {
    string input;

    while (true) {
        type(prompt);
        getline(cin, input);

        if (!isdecimal(input) || stod(input) < 0) {
            continue;
        }

        return stod(input);
    }
}


bool isdecimal(string input) {
    if (count(input.begin(), input.end(), '.') > 1) {
        return false;
    }

    for (char character : input) {
        if (character == '.') {
            continue;
        }
        else if (!isdigit(character)) {
            return false;
        }
    }

    return true;
}


date get_date(string prompt) {
    int thirtyOneDays[7] = {1, 3, 5, 7, 10, 12};
    string input;
    date date;
    bool Isvalid_date = true;

    while (true) {
        type(prompt);
        getline(cin, input);

        if (input.length() != 8 || !valid_date(input)) {
            cerr << "Follow the correct DATE format! (MM/DD/YY)\n";
            continue;
        }

        date.month = stoi(input.substr(0, 2));
        date.day = stoi(input.substr(3, 5));
        date.year = stoi(input.substr(6, 8));


        for (int i = 1; i <= 7; i++) {
            if (date.month == thirtyOneDays[i]) {
                if (date.day > 31) {
                    Isvalid_date = false;
                    break;
                }
            }
        }

        if (date.month == 2) {
            if (date.day > 28) {
                Isvalid_date = false;
            }
        }
        else {
            if (date.day > 30) {
                Isvalid_date = false;
            }
        }

        if (Isvalid_date == false) {
            continue;
        }

        return date;
    }
}

bool valid_date(string input) {
    if (count(input.begin(), input.end(), '/') != 2) {
        return false;
    }

    for (char character : input) {
        if (character == '/') {
            continue;
        }
        else if (!isdigit(character)) {
            return false;
        }
    }

    return true;
}


date calculate_end_date(int days, date start_date) {
    start_date.day += days;
    int number_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    while (start_date.day > number_days[start_date.month - 1]) {
        if (start_date.month == 13) {
            start_date.month -= 12;
            start_date.year++;
        }
        start_date.day -= number_days[start_date.month - 1];
        start_date.month++;
    }
    
    return start_date;
}


void interpret(date end_date, int days) {
    map<int, string> months = {{1, "January"}, {2, "February"}, {3, "March"}, {4, "April"}, {5, "May"}, {6, "June"}, {7, "July"}, {8, "August"}, {9, "September"}, {10, "October"}, {11, "November"}, {12, "December"}};

    type("\n\nIF YOU FOLLOW YOUR DIET AND WORKOUT PLAN CONSISTENTLY, YOU WILL ACHIEVE YOUR DESIRED WEIGHT in ");
    cout << days << " days, on " << months[end_date.month] << " " << end_date.day << ", 20" << end_date.year << ".\n\n";

    type("END OF THE PROGRAM!!!");
    
}