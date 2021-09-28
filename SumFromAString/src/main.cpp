#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string expression;

    cout << "Enter Expression: ";
    getline(cin, expression);
    cout << endl;

    vector<string>  values {};
    string delimeter = "+";
    size_t pos {0};
    string token;

    while((pos = expression.find(delimeter)) != string::npos)
    {
        token = expression.substr(0, pos);
        token.erase(remove(token.begin(), token.end(), ' '), token.end());;
        values.push_back(token);
        expression.erase(0, pos + delimeter.length());
    }
    expression.erase(remove(expression.begin(), expression.end(), ' '), expression.end());;
    values.push_back(expression);

    int sum_value {0};
    for (int i {0}; i < values.size(); i++)
    {
        if (values[i] != "")
        {
            sum_value += stoi(values[i]);
        }
        //cout << values[i] <<",";
    }
    cout << "The sum of the Expression is: " << sum_value << endl;

    return 0;
}


