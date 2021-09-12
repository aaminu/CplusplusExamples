#include <iostream>

using namespace std;

int main(){

    int a {0};
    int b {0};

    cout << "Enter two integer a and b: ";
    cin >> a >> b;
    cout << endl;

    //cout << "The number you entered are: " << a << " and " << b << endl;
    int tmp {0};
    while (b != 0)
    {
        tmp = b;
        b = a % b;
        a = tmp;
    }
    cout << "The greatest commmon divisor is: " << a << endl;

    return 1;
}