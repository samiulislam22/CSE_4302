#include <bits/stdc++.h>

using namespace std;

class RationalNumber
{
    private:
    int numerator ;
    int denominator;
    public :
    void assign(int num , int denom);
    float convert(int num , int denom);
    void invert (int num , int denom);
    void print();
};

void RationalNumber :: invert(int num , int denom)
{
    numerator = denom ;
    denominator = num ;
}
void RationalNumber :: assign(int num , int denom)
{
    if(denom == 0 ) 
    {
        cout << "Undefined" <<endl;
        exit(0);
    }
    numerator = num , denominator = denom ;
}
void RationalNumber :: print()
{
    if(denominator == 0)
    {
        cout << "Undefined" <<endl;
        exit(0);
    }
    cout << numerator / denominator ;
}
float RationalNumber :: convert(int num , int denom)
{
    assign(num , denom);
    return ((float)numerator / (float)denominator);
}
int main()
{
    int x , y ;
    cin >> x >> y ;
    RationalNumber rnum;
    rnum.assign(x,y);
    rnum.print();
    return 0 ;
}
