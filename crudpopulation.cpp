#include "crudpopulation.h"

int main() {
    int population, days, finalSize;
    cout << "Press enter to start program...\n";

    do {

        population = get_input(0);
        days = get_input(1);

        finalSize = calcPopulation(population, days);

        display(finalSize, population, days);

    } while(choice());

}