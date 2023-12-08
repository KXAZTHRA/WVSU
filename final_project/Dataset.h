#include <iostream>
#include <map>
#include <string>
#include <limits>

using namespace std;

map<string, double> foodCalories = {
    {"Chicken Adobo", 215}, {"Pork Adobo", 220}, {"Balut", 188}, {"Bangus", 150}, {"Bibingka", 200},
    {"Beef Steak", 200}, {"Buko Salad", 120}, {"Caldereta", 250}, {"Kamote Cue", 150}, {"Champorado", 150},
    {"Chicken Inasal", 230}, {"Chicken Tinola", 150}, {"Chicharon", 544}, {"Dinuguan", 120}, {"Embutido", 260},
    {"Ensaymada", 340}, {"Fish Sinigang", 150}, {"Halo-halo", 160}, {"Kare-Kare", 250}, {"Kinilaw", 120},
    {"Laing", 200}, {"Lechon Baboy", 298}, {"Lechon Kawali", 250}, {"Longganisa", 310}, {"Lumpiang Shanghai", 240},
    {"Manggang Hilaw", 60}, {"Menudo", 150}, {"Pan de Sal", 300}, {"Pancit Bihon", 230}, {"Pancit Canton", 300},
    {"Lechon Paksiw", 240}, {"Puto", 100}, {"Sinangag", 130}, {"Pork Sinigang", 200}, {"Pork Sisig", 480},
    {"Taho", 100}, {"Tapsilog", 300}, {"Tinolang Manok", 110}, {"Tocino", 300}, {"Rice", 130}, {"Hamburger", 250},
    {"Hot Dog", 150}, {"Cheeseburger", 300}, {"Chicken Nuggets", 280}, {"French Fries", 365}, {"Caesar Salad", 150},
    {"Buffalo Wings", 480}, {"Macaroni and Cheese", 330}, {"Grilled Chicken Breast", 165}, {"Spaghetti", 200},
    {"Pizza", 285}, {"Chocolate Chip Cookie", 50}, {"Ice Cream", 150}, {"Donut", 240}, {"Pancakes", 200},
    {"Bacon", 135}, {"Eggs", 140}, {"Steak", 500}, {"BBQ Ribs", 600}, {"Mashed Potatoes", 210}, {"Popcorn", 55},
    {"Apple", 95}, {"Banana", 105}, {"Mango", 60}, {"Strawberry", 32}, {"Orange", 52}, {"Grapes", 69},
    {"Watermelon", 30}, {"Pineapple", 50}, {"Avocado", 160}, {"Papaya", 43}, {"Kiwi", 61}, {"Pomegranate", 83},
    {"Blueberries", 57}, {"Raspberry", 52}, {"Blackberry", 40}};

map<string, double> exerciseCalories = {
    {"Running", 7.7}, {"Swimming", 12.1}, {"Cycling", 8}, {"Push-ups", 0.5}, {"Modified Push-ups", 0.3}, {"Dips", 1.2},
    {"Squats", 2.2}, {"Lunges", 1.3}, {"Walking lunges", 0.9}, {"Plank", 5}, {"Side plank", 2.6}, {"Sit-ups", 0.2}, 
    {"Crunches", 0.1}, {"Jumping jacks", 10.0}, {"Jumping rope", 12.3}, {"Burpees", 1.3}, {"Box jumps", 2.2},
    {"Mountain climbing", 14.2}, {"Yoga", 5.5}, {"Pilates", 3.7}, {"Dancing", 5.5}, {"Walking", 4.7}, {"Using stairs", 11},
    {"Elliptical trainer", 6}};