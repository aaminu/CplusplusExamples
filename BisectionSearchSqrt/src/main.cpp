#include <iostream>

using namespace std;

int main(){

    double x {0.0};
    cout << "Enter a positive integer value: ";
    if (!(cin >> x))
    {
        cout << "Error in value entered!" << endl;
        return -1;
    }
    
    cout << endl;

    double lower_band {1.0};
    double upper_band {0.0};
    double update_step {0.0001};
    double mid_val {0.0};

    if (x > 4.0)
    {
        upper_band = x/2;
    }else{
        upper_band = x;
    }

    while (upper_band >= lower_band)
    {
        mid_val =  (lower_band + upper_band)/2;
        if (mid_val * mid_val > x)
        {
            upper_band =  mid_val - update_step;
        }else{
            lower_band = mid_val + update_step;
        }
    }
    
    cout << " The square root for " << x << " is: " << (lower_band + upper_band)/2 << endl;
    
    return 1;
}