#include <iostream>
#include <map>
#include <string>
#include <limits>
#include <iomanip>
#include <vector>
using namespace std;

map<string, double> foodCalories = {
    {"CHICKEN ADOBO", 215}, {"PORK ADOBO", 220}, {"BALUT", 188}, {"BANGUS", 150}, {"BIBINGKA", 200},
    {"BEEF STEAK", 200}, {"BUKO SALAD", 120}, {"CALDERETA", 250}, {"KAMOTE CUE", 150}, {"CHAMPORADO", 150},
    {"CHICKEN INASAL", 230}, {"CHICKEN TINOLA", 150}, {"CHICHARON", 544}, {"DINUGUAN", 120}, {"EMBUTIDO", 260},
    {"ENSAYMADA", 340}, {"FISH SINIGANG", 150}, {"HALO-HALO", 160}, {"KARE-KARE", 250}, {"KINILAW", 120},
    {"LAING", 200}, {"LECHON BABOY", 298}, {"LECHON KAWALI", 250}, {"LONGGANISA", 310}, {"LUMPIANG SHANGHAI", 240},
    {"MANGGANG HILAW", 60}, {"MENUDO", 150}, {"PAN DE SAL", 300}, {"PANCIT BIHON", 230}, {"PANCIT CANTON", 300},
    {"LECHON PAKSIW", 240}, {"PUTO", 100}, {"SINANGAG", 130}, {"PORK SINIGANG", 200}, {"PORK SISIG", 480},
    {"TAHO", 100}, {"TAPSILOG", 300}, {"TINOLANG MANOK", 110}, {"TOCINO", 300}, {"RICE", 130}, {"HAMBURGER", 250},
    {"HOT DOG", 150}, {"CHEESEBURGER", 300}, {"CHICKEN NUGGETS", 280}, {"FRENCH FRIES", 365}, {"CAESAR SALAD", 150},
    {"BUFFALO WINGS", 480}, {"MACARONI AND CHEESE", 330}, {"GRILLED CHICKEN BREAST", 165}, {"SPAGHETTI", 200},
    {"PIZZA", 285}, {"CHOCOLATE CHIP COOKIE", 50}, {"ICE CREAM", 150}, {"DONUT", 240}, {"PANCAKES", 200},
    {"BACON", 135}, {"EGGS", 140}, {"STEAK", 500}, {"BBQ RIBS", 600}, {"MASHED POTATOES", 210}, {"POPCORN", 55},
    {"APPLE", 95}, {"BANANA", 105}, {"MANGO", 60}, {"STRAWBERRY", 32}, {"ORANGE", 52}, {"GRAPES", 69},
    {"WATERMELON", 30}, {"PINEAPPLE", 50}, {"AVOCADO", 160}, {"PAPAYA", 43}, {"KIWI", 61}, {"POMEGRANATE", 83},
    {"BLUEBERRIES", 57}, {"RASPBERRY", 52}, {"BLACKBERRY", 40}};

map<string, double> exerciseCalories = {
    {"RUNNING", 7.7}, {"SWIMMING", 12.1}, {"CYCLING", 8}, {"PUSH-UPS", 0.5}, {"MODIFIED PUSH-UPS", 0.3}, {"DIPS", 1.2},
    {"SQUATS", 2.2}, {"LUNGES", 1.3}, {"WALKING LUNGES", 0.9}, {"PLANK", 5}, {"SIDE PLANK", 2.6}, {"SIT-UPS", 0.2}, 
    {"CRUNCHES", 0.1}, {"JUMPING JACKS", 10.0}, {"JUMPING ROPE", 12.3}, {"BURPEES", 1.3}, {"BOX JUMPS", 2.2},
    {"MOUNTAIN CLIMBING", 14.2}, {"YOGA", 5.5}, {"PILATES", 3.7}, {"DANCING", 5.5}, {"WALKING", 4.7}, {"USING STAIRS", 11},
    {"ELLIPTICAL TRAINER", 6}};
