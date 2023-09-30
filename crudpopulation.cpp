#include "crudpopulation.h"

int main() {
    int population, days, finalSize;
    cout << "This is the Crud Population calculator.\nCruds grow their population every 5 days.\n"
            "Their populations growth over time is the sum of the their 2 previous population counts.\n"
            "Enter the starting population of the crud, and the number of days for their population to grow...\n\n";

    do {

        population = get_input(0);
        days = get_input(1);

        finalSize = calcPopulation(population, days);

        display(finalSize, population, days);

    } while(choice());

}