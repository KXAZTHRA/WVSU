#include <iostream>
#include <map>
#include <string>
#include <limits>
#include <iomanip>
#include <vector>
#include <algorithm>
#include "Dataset.h"

using namespace std;

double getCalories(map<string, double> foodCalories);

int main() 
{
   double totalCalories = getCalories(foodCalories);
   cout << "Total calories for the day: " << totalCalories << " calories." << endl;

   return 0;
}

double getCalories(map<string, double> foodCalories)
{
    double totalCalories = 0.0;
    string food;
    vector<string> foodNames;

    cout << "Here are the list of food that are in the dataset. Add whatever you have eaten." << endl;
    cout << endl;

   for (const auto& entry : foodCalories) 
   {
      foodNames.push_back(entry.first);
   }
   const int columnsPerRow = 7;

   for (size_t i = 0; i < foodNames.size(); i += columnsPerRow) 
   {
      for (int j = 0; j < columnsPerRow && (i + j) < foodNames.size(); ++j) 
      {
         cout << setw(30) << left << foodNames[i + j];
      }
         cout << endl;
   }

    cout << endl;
    cout << "Enter food for breakfast (To proceed to lunch, input 'next'):" << endl;
    
    while (true)
    {
         getline(cin, food);
         if (food == "next")
         {
            break;
         }

         transform(food.begin(), food.end(), food.begin(), ::toupper);

         if(foodCalories.find(food) != foodCalories.end())
         {
            totalCalories += foodCalories.at(food);
            cout << "Added " << food << " to calorie count." << endl;
         }
         else
         {
            cout << "Food not found in dataset. Input again or type 'next' to proceed to lunch" << endl;
         }
    }

    cout << "Enter food for lunch (To proceed to dinner, input 'next'):" << endl;
    
    while (true)
    {
         getline(cin, food);
         if (food == "next")
         {
            break;
         }

         transform(food.begin(), food.end(), food.begin(), ::toupper);

         if(foodCalories.find(food) != foodCalories.end())
         {
            totalCalories += foodCalories.at(food);
            cout << "Added " << food << " to calorie count." << endl;
         }
         else
         {
            cout << "Food not found in dataset. Input again or type 'next' to proceed to lunch" << endl;
         }
    }

    cout << "Enter food for dinner (To proceed to dinner, input 'next'):" << endl;
    
    while (true)
    {
         getline(cin, food);
         if (food == "next")
         {
            break;
         }

         transform(food.begin(), food.end(), food.begin(), ::toupper);

         if(foodCalories.find(food) != foodCalories.end())
         {
            totalCalories += foodCalories.at(food);
            cout << "Added " << food << " to calorie count." << endl;
         }
         else
         {
            cout << "Food not found in dataset. Input again or type 'next' to proceed to lunch" << endl;
         }
    }

    cout << "Enter food for snacks (To proceed, input 'exit'):" << endl;
    
    while (true)
    {
         getline(cin, food);
         if (food == "exit")
         {
            break;
         }

         transform(food.begin(), food.end(), food.begin(), ::toupper);

         if(foodCalories.find(food) != foodCalories.end())
         {
            totalCalories += foodCalories.at(food);
            cout << "Added " << food << " to calorie count." << endl;
         }
         else
         {
            cout << "Food not found in dataset. Input again or type 'exit' to proceed" << endl;
         }
    }

    return totalCalories;
}