/*Write a program that computes the annual after-tax cost at a new house for the first
the first year of ownership. The cost is computed as the annual mortgageCost
minus the tax savings. The input should be the price of the house and the
down payment. The annual mortgageCost cost can be estimated as 3 percent of the
initial loan balance credited toward paying off the loan principal plus 6 per-
cent of the initial loan balance in interest. Ihe initial loan balance is the price
minus the down payment. Assume a 35 percent marginal tax rate and assume
that interest payments are tax deductible. So, the tax savings is 35 percent of the
interest payment. Your program should use at least two function definitions
and should allow the user to repeat this calculation as often as the user wishes.*/

#include "after-tax.h"

int main() {
    double housePrice, downPayment, loanBalance, interestPayment, mortgageCost, taxSavings, afterTaxCost;

    do {
        housePrice = get_double("House Price: $");
        downPayment = get_double("Down Payment: $");
        loanBalance = housePrice - downPayment;

        for (int year = 1; year <= 10; year++) {
            interestPayment = 0.06 * loanBalance;
            mortgageCost = 0.03 * loanBalance + interestPayment;
            taxSavings = 0.35 * interestPayment;
            afterTaxCost = mortgageCost - taxSavings;

            display(year, housePrice, downPayment, loanBalance, interestPayment, mortgageCost, taxSavings, afterTaxCost);
            loanBalance -= 0.03 * loanBalance;
        }

    } while (choice());

}

