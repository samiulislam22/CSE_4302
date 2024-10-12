#include <bits/stdc++.h>
#include <cstdlib>
#include "207_task.h"

using namespace std;

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    vector<Product> products(100);

    for(int i = 0 ; i < 2 ; i++)
    {
        EditInformationByKeyboard(products[i]);
    }

    showAllDiscount(products); 
    grossTotal(products ,100);    
    showAllalphabetically(products);
    return 0 ;
}