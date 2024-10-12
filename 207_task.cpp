#include <bits/stdc++.h>
#include "207_task.h"
#include <cstdlib>

using namespace std;

Product::Product() {
    product_name = "";
    product_category = "";
    description = "";
    amount_in_store = 0;
    reg_price = 0.0;
    discount_rate = 0.0;
}


    void Product ::set_product_name(string product_name)
    {
        this->product_name = product_name;
    }
    string Product :: get_product_name() const
    {
        return product_name;
    }

    void Product ::setProductCategory(string category)
    {
        product_category = category;
    }

    string Product ::getProductCategory() const
    {
        return product_category;
    }

    void Product ::setDescription(string desc)
    {
        description = desc;
    }

    string Product ::getDescription() const
    {
        return description;
    }

    void Product :: setAmountInStore(int amount)
    {
        amount_in_store = amount;
    }

    int Product :: getAmountInStore() const
    {
        return amount_in_store;
    }

    void Product ::setRegPrice(float price)
    {
        reg_price = price;
    }

    float Product ::getRegPrice() const
    {
        return reg_price;
    }

    void Product ::setDiscountRate(float discount)
    {
        discount_rate = discount;
    }

    float Product ::getDiscountRate() const
    {
        return discount_rate;
    }
    void Product ::PurchaseProduct(int amount)
    {
        amount_in_store -= amount;
        if (amount_in_store > 0)
            setAmountInStore(amount_in_store);
        if (amount_in_store <= 0)
        {
            setAmountInStore(0);
            cout << "Not avaiable in store" << endl;
            return;
        }
    }
    void Product ::RestockProduct(int amount)
    {
        amount_in_store += amount;
        setAmountInStore(amount_in_store);
    }
    double Product :: calculateDiscount(int amountofProducts) const
{
    if (amountofProducts > amount_in_store)
    {
        cout <<"Out of stock!!!" <<endl;
        return 0;
    }
    
    double discount = discount_rate / 100;
    double dis = amountofProducts * reg_price;

    if (amountofProducts >= 10)
    {
        dis *= (discount + 0.03);  // Extra 3% discount for 10 or more products
    }
    else if (amountofProducts >= 5)
    {
        dis *= discount;
    }
    else
    {
        return 0;  // No discount for less than 5 products
    }

    return dis;
}


    void Product :: netTotal(int amountofProducts)
    {
        double cost = 0;
        double dis = calculateDiscount(amountofProducts);
        cost = amountofProducts * reg_price;

        cout <<"The total cost is : "<< cost <<endl;
        cout <<"The total discount is : "<< dis <<endl;
        cout <<"The total amount need to pay is : "<< cost-dis <<endl;
    }

    bool Product :: operator < (const Product& other) const
    {
        return product_name < other.product_name;
    }

void EditInformationByKeyboard(Product &obj)
{
    string s , description = "" ;
    cout <<"Enter the product name: " ;
    cin >> s;
    cin.ignore();
    obj.set_product_name(s);
    cout << endl ;
    cout << "Enter the product category: ";
    cin >> s ;  
    cin.ignore();
    cout<<endl;
    cout <<"Insert the product description : ";
    while(1)
    {
        getline(cin,s);
        if(s.empty())break;
        description += s+'\n';
    }
    obj.setDescription(description);
    cout <<endl;
    int x;
    cout <<"Enter the amount in store : ";
    cin >> x;
    obj.setAmountInStore(x);
    cout <<endl;
    float price;
    cout <<"Enter the regular price of the product :";
    cin >> price;
    obj.setRegPrice(price);
    cout <<endl;
    float d_rate;
    cout <<"Enter the discount rate of the product : ";
    cin >> d_rate ;
    obj.setDiscountRate(d_rate);
}

string generateRandomString(int length) {
    string Alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int AlphabetSize = Alphabet.length();  // Use length() instead of sizeof()
    string random = "";

    for (int i = 0; i < length; i++) {
        random += Alphabet[rand() % AlphabetSize];
    }

    return random;
}

int randomIntGenerator(int min , int max)
{
    if(min>max) swap(min,max);
    // srand(static_cast<unsigned int>(time(0)));
    return rand() % (max-min+1) + min ;
}

double randomdoubleGenerator(double min ,double max)
{
    if(min>max) swap(min,max);
    double randomFraction = static_cast<double>(rand()) / RAND_MAX;

    return min + randomFraction*(max-min) ;   
}
void generateInformationRandom(Product &obj)
{
    string s ;
    int len ; 
    len = randomIntGenerator(3,7);
    s = generateRandomString(len);
    obj.set_product_name(s); 
    
    len = randomIntGenerator(3,7);
    s = generateRandomString(len);
    obj.setProductCategory(s);

    s ="";
    for(int i = 0 ; i < 10 ; i++)
    {
        len = randomIntGenerator(3,7);
        s += generateRandomString(len);
        s +=" "; 
    }
    obj.setDescription(s);

    len = randomIntGenerator(1,50);
    obj.setAmountInStore(len);

    len = randomIntGenerator(500 , 1000);
    obj.setRegPrice(len);

    double len1 = randomdoubleGenerator(3,15);
    obj.setDiscountRate(len1);
}

void showAllDiscount(vector<Product> &products)
{
    for(int i = 0 ; i < products.size() ; i++)
    {
        double dis;
        dis = products[i].getDiscountRate();
        cout << dis << endl;
    }
}

void showAllalphabetically(vector<Product> &products)
{
    sort(products.begin(), products.end());
    for(auto &it : products)
    {
        cout<<"Product : "<<it.get_product_name() <<" Amount: "<<it.getAmountInStore() <<endl;
    }
}

void grossTotal(vector<Product> &products, int size) {
    double totalCost = 0;
    
    for (int i = 0; i < size; i++) {
        int randomPurchaseAmount = randomIntGenerator(1, products[i].getAmountInStore());
        
        cout << "\nProduct: " << products[i].get_product_name() << endl;
        cout << "Attempting to purchase " << randomPurchaseAmount << " units." << endl;
        
        products[i].netTotal(randomPurchaseAmount);
        
        double productCost = randomPurchaseAmount * products[i].getRegPrice() - products[i].calculateDiscount(randomPurchaseAmount);
        totalCost += productCost;
    }
    
    cout << "\nGross total for all products: $" << totalCost << endl;
    
    char confirmation;
    cout << "Do you want to confirm the purchase? (y/n): ";
    cin >> confirmation;
    
    if (confirmation == 'y' || confirmation == 'Y') {
        cout << "Purchase confirmed! Total amount to pay: $" << totalCost << endl;
    } else {
        cout << "Purchase cancelled." << endl;
    }
}