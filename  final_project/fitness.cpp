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
#include <iostream>
#include <map>
using namespace std;

// Declare data set for food name, and its corresponding value
map<string, double> foodCalories = {{"Chicken Adobo", 215}, {"Pork Adobo", 220}, {"Balut", 188}, {"Bangus", 150}, {"Bibingka", 200}, {"Beef Steak", 200}, {"Buko Salad", 120}, {"Caldereta", 250}, {"Kamote Cue", 150}, {"Champorado", 150}, {"Chicken Inasal", 230}, {"Chicken Tinola", 150}, {"Chicharon", 544}, {"Dinuguan", 120}, {"Embutido", 260}, {"Ensaymada", 340}, {"Fish Sinigang", 150}, {"Halo-halo", 160}, {"Kare-Kare", 250}, {"Kinilaw", 120}, {"Laing", 200}, {"Lechon Baboy", 298}, {"Lechon Kawali", 250}, {"Longganisa", 310}, {"Lumpiang Shanghai", 240}, {"Manggang Hilaw", 60}, {"Menudo", 150}, {"Pan de Sal", 300}, {"Pancit Bihon", 230}, {"Pancit Canton", 300}, {"Lechon Paksiw", 240}, {"Puto", 100}, {"Sinangag", 130}, {"Pork Sinigang", 200}, {"Pork Sisig", 480}, {"Taho", 100}, {"Tapsilog", 300}, {"Tinolang Manok", 110}, {"Tocino", 300}, {"Rice", 130}, {"Hamburger", 250}, {"Hot Dog", 150}, {"Cheeseburger", 300}, {"Chicken Nuggets", 280}, {"French Fries", 365}, {"Caesar Salad", 150}, {"Buffalo Wings", 480}, {"Macaroni and Cheese", 330}, {"Grilled Chicken Breast", 165}, {"Spaghetti", 200}, {"Pizza", 285}, {"Chocolate Chip Cookie", 50}, {"Ice Cream", 150}, {"Donut", 240}, {"Pancakes", 200}, {"Bacon", 135}, {"Eggs", 140}, {"Steak", 500}, {"BBQ Ribs", 600}, {"Mashed Potatoes", 210}, {"Popcorn", 55}, {"Apple", 95}, {"Banana", 105}, {"Mango", 60}, {"Strawberry", 32}, {"Orange", 52}, {"Grapes", 69}, {"Watermelon", 30}, {"Pineapple", 50}, {"Avocado", 160}, {"Papaya", 43}, {"Kiwi", 61}, {"Pomegranate", 83}, {"Blueberries", 57}, {"Raspberry", 52}, {"Blackberry", 40}};

// Declare data set for work-out activities, and its corresponding calorie burn value
map<string, double> exerciseCalories = {{"Running", 240}, {"Cycling", 240}, {"Swimming", 360}, {"Weightlifting", 112}, {"Jumping Rope", 240}, {"Yoga", 120}, {"Walking", 120}, {"HIIT", 400}, {"Elliptical", 240}, {"Rowing", 240}, {"Push ups", 240}, {"Sit ups", 240}, {"Squats", 240}, {"Burpees", 240}, {"Plank", 120}, {"Boxing", 400}, {"Kickboxing", 400}, {"Circuit Training", 400}, {"Pilates", 240}, {"Zumba", 240}, {"Dancing", 240}, {"Hiking", 360}, {"Rock Climbing", 480}, {"Surfing", 240}, {"Skating", 240}, {"Biking", 240}, {"Basketball", 480}, {"Tennis", 360}, {"Soccer", 480}, {"Volleyball", 240}};

int main() {
    // Display message about how to use the program

    // Ask and Calculate BMI

    // Ask user for foods eaten a day and compute the overall calorie intake

    // Ask user for non-workout activities that may burn calories

    // Ask user for the type of workout with equivalent calorie burn values based on the number of repetition anf sets

    // Ask user for his/her desired weight, date the workout started and compute when will the user attain that desired weight


}