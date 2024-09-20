#include <bits/stdc++.h>

using namespace std ;

int main()
{
    double a , b, c , d ;
    char dummychar ;
    cout << "enter the first fraction: ";    
    cin >> a >> dummychar >> b ;
    cout <<endl << "enter the next fraction: ";
    cin >> c >> dummychar >> d  ;

    auto result = [](double a , double b , double c , double d){return ((a*d + b*c)/(b*d));};
    cout << endl << result(a,b,c,d);

    return 0 ;
}