#include <iostream>

using namespace std;

double initialLoanBalance, Interest, taxSavings, annualMortgageCost, aftertaxCost;
string price, down;
bool choice();

int main()
{
    do{    
    cout << "PILA ANG PRICE SANG HOUSE:" ;
    cin >> price;

    cout << "Pila gn down?";
    cin >> down;
   
    cout << "ari ho: " << oneTwo(price, down) << endl;
    }while(choice());
}

array<double, 2> getPrice(price, down){
array<double, 2> a;
a[0]= price;

while(true){

    if(!digit(price) || !digit(down)){
        continue;
    }
    if(stoi(price) || < 0 && stoi(down) < 0){
        continue;
    }

    else{
        
    }
}

}

double oneTwo(double price, double down)
{
    initialLoanBalance = price - down;
    Interest = initialLoanBalance * 0.06;
    taxSavings = Interest * 0.35;

    annualMortgageCost = (0.03 * initialLoanBalance) + Interest;
    aftertaxCost = annualMortgageCost - taxSavings;

    return aftertaxCost;
}

bool choice()
{
    string inputDallas;
    cout << "pakyo ka sapa?" << endl;
    cin >> inputDallas;
while(true)
{
    if(toupper(inputDallas[0]) == 'Y')
    {
        return true;
    }
    else if(toupper(inputDallas[0]) == 'N')
    {
        return false;
    }
    else
    {
        continue;
    }
}
    }
