#ifndef PRODUCT_H
#define PRODUCT_H

#include<bits/stdc++.h>

using namespace std;

class Product{
private:
    string product_name;
    string product_category, description;
    int amount_in_store;
    float reg_price;
    float discount_rate;

public :
    Product();
    void set_product_name(string product_name);
    string get_product_name() const ;

    void setProductCategory(string category);
    string getProductCategory()const;

    void setDescription(string desc);
    string getDescription() const;

    void setAmountInStore(int amount);
    int getAmountInStore() const;

    void setRegPrice(float price);
    float getRegPrice() const;

    void setDiscountRate(float discount);
    float getDiscountRate() const;

    void PurchaseProduct(int amount);
    void RestockProduct(int amount);

    double calculateDiscount(int amountofProducts) const;

    void netTotal(int amountofProducts);

    bool operator<(const Product& other) const;
};
void EditInformationByKeyboard(Product &obj);
void generateInformationRandom(Product &obj);
string generateRandomString(int length);
int randomIntGenerator(int min , int max);
void showAllDiscount(vector<Product> &products);
void showAllalphabetically(vector<Product> &products);
void grossTotal(vector<Product> &products, int size);

#endif