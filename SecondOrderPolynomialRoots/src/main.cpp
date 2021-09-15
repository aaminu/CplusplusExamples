#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){

    string welcome = "The second order polynomial is given as: ax² + bx + c = 0";
    cout << welcome << endl;

    //coeffiecients
    double a {0.0};
    double b {0.0};
    double c {0.0};
    double d {0.0};

    cout << "Enter the coefficients a b c: ";
    if (!(cin >> a >> b >> c))
    {
        cout << "Error in value entered!" << endl;
        return -1;
    }
    cout << endl;

    d = pow(b, 2.0) - (4*a*c);
    //cout << d <<  endl;

    if (d >= 0)
    {
        double x_1 {0.0};
        double x_2 {0.0};
        x_1 = (-b - sqrt(d)) / (2 * a);
        x_2 =  (-b + sqrt(d)) / (2 * a);
        cout << "The roots of the equation are (";
        cout << fixed << setprecision(2) <<  x_1 << ", ";
        cout << fixed << setprecision(2) <<  x_2 << ")" ;
        cout << endl;
    }else{
        cout << "No roots exits for the polynomial equation given!" << endl;
        return -1;
    }

    
    return 1;
}