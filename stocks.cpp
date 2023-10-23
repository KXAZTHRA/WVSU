/*Ihe price of stocks is sometimes given to the nearest eighth of a dollar; for
example, 297/8 or 891/2. Write a program that computes the value of the
user's holding of one stock. program asks for the number of shares of
stock owned, the Whole-dollar portion Of the price, and the fraction portion.
The fraction portion is to be input as two int values, one for the numerator
and one for the denominator. The program then outputs the value of
the user's holdings. Your program should allow the user to repeat this
calculation as often as the user wishes and will include a function definition
that has three int arguments consisting of the whole-dollar portion of the
price and the two integers that make up the fraction part. function
returns the price of one share of stock as a single number of type double.*/

#include "stocks.h"


int main() {
    // Welcome message
    display_message();

    // Stock[0] == whole, stock[1] == numerator, stock[2] == denominator
    int shares;
    array<int, 3> mix_number;

    do {
        shares = get_int(0);
        mix_number = get_mixnumber();

        double total_stocks = calculate_stocks2(mix_number);

        display_total_price(shares, total_stocks);

    } while (choice());
}