#include <bits/stdc++.h>
using namespace std;

typedef struct info
{
    string brand;
    string model;
    int Year;
    string Fuel_type;
    int mileage;
} cars;

void information()
{
    int num_of_cars;
    cout << "Enter the number of cars: ";
    cin >> num_of_cars;

    vector<cars> car_type(num_of_cars); 
    
    
    auto fuel_chk = [](int mileage, float fuel_rate) {
        return (100.0 / mileage) * fuel_rate;
    };

    cout << "Enter the car information:" << endl;
    for (int i = 0; i < num_of_cars; i++)
    {
        cout << "Car " << i + 1 << " :" << endl;
        cout << "Brand: ";
        cin >> car_type[i].brand;
        cout << "Model: ";
        cin >> car_type[i].model;
        cout << "Year: ";
        cin >> car_type[i].Year;
        cout << "Fuel Type (Petrol/Diesel/Hybrid/Electric): ";
        cin >> car_type[i].Fuel_type;
        cout << "Mileage : ";
        cin >> car_type[i].mileage;
    }

    
    for (int i = 0; i < num_of_cars; i++)
    {
        if (car_type[i].Fuel_type == "Petrol")
            cout << "Estimated fuel cost for 100 miles: $" << fuel_chk(car_type[i].mileage, 0.89) << endl;
        else if (car_type[i].Fuel_type == "Diesel")
            cout << "Estimated fuel cost for 100 miles: $" << fuel_chk(car_type[i].mileage, 3.24) << endl;
        else if (car_type[i].Fuel_type == "Hybrid")
            cout << "Estimated fuel cost for 100 miles: $" << fuel_chk(car_type[i].mileage, 2.45) << endl;
        else if (car_type[i].Fuel_type == "Electric")
            cout << "This car is electric, efficiency measured in charge/km" << endl;
        else
            cout << "Unknown fuel type" << endl;
    }
}

int main()
{
    information();
    return 0;
}
