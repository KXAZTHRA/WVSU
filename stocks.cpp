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


    // shares for 2 companies
    int shares[2];
    // total_stocks for 2 companies
    double total_stocks[2];
    // mix_number for 2 companies
    // mix_number[0] == whole, mix_number[1] == numerator, mix_number[2] == denominator
    array<int, 3> mix_number[2]; // int mix_number[3][2]
    /* a | b | c company A
       a | b | c company B */
    
    // Names of the companies
    char company[] = {'A', 'B'};

    // To restart the program if the user wants to input new values
    do {
        // Iterate between the 2 companies
        for (int i = 0; i < 2; i++) {
            // Display company name
            cout << "COMPANY " << company[i];
            // Get shares for 1 company
            shares[i] = get_int(0);
            // Get mix number of the price of the stocks
            mix_number[i] = get_mixnumber();
            // Convert mix number of the stocks in decimal form
            total_stocks[i] = calculate_stocks2(mix_number[i]); 
            // Display total price
            display_total_price(shares[i], total_stocks[i]);

            // New line for aesthetic purposes
            cout << endl;
        }

        // Display table of the shares, stocks, and company name of the 2 companies
        table(shares, total_stocks, company);

    } while (choice());
}