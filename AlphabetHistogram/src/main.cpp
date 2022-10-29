#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;


int main()
{
    //slot of each alphabet 
    vector histogram('z' - 'a' + 1, 0);

    string in_str;

    cout << "Enter the words or sentence: ";
    getline(cin, in_str);

    for (auto c : in_str)
    {
        if (isalpha(c))
            ++histogram[tolower(c) - 'a'];
    }
    cout << endl;
    
    //printing a horizontal graph with *
    for (auto c {'a'}; c <= 'z'; ++c)
    {
        if (histogram[c - 'a'])
        {
            cout << c << " " << string(histogram[c - 'a'], '*') << endl;
        }
    }

    cout << " The breakdown per alphabet is shown below" << endl;
    for (auto c {'a'}; c <= 'z'; ++c)
    {
        cout << setw(3) << c;
    }
    cout << endl;
    for (auto h : histogram)
    {
        cout << setw(3) << h;
    }
    cout << endl;
}
