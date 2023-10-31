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
    display_message();
    
    do {
        // Ask for the number of companies
        int companies = get_int("Enter the number of companies: ");

        // Create arrays or "vectors"
        vector<string> names(companies);
        vector<int> shares(companies);
        vector<double> stocks(companies);
        vector<double> totalPrice(companies);

        for (int i = 0; i < companies; i++) {
            cout << endl;
            names[i] = get_name("Enter Company Name: ");
            shares[i] = get_int("Enter the number of shares: ");
            stocks[i] = get_mixnumber("Enter a mix number: ");
            totalPrice[i] = shares[i] * stocks[i];
            display_total_price(totalPrice[i], names[i]);
        }

        table(names, shares, stocks, totalPrice, companies);
    } while (choice()); 
}