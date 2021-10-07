#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>

using namespace std;



int main()
{
    
    int n {2};

    //Vector for the alphabets in a sentence
    vector<float> alphabets('z'-'a'+1, 0.0);

    //vectors of vectors for the n number of text
    vector<vector<float> > alphabets_vector {};
    for (int i {0}; i < n; i++)
    {
        alphabets_vector.push_back(alphabets);
    }

    //get sentences
    string sentences[n];
    for (int i {0}; i < n; i++)
    {
        cout << "Enter the Sentence " << i+1 << ": ";
        getline(cin, sentences[i]);
        cout << endl;
    }

    //Create an Histogramm for the sentencea
    double sum[n];
    for (int i {0}; i < n; i++)
    {
        
        for (auto c : sentences[i])
        {
            if (isalpha(c))
            {
                ++alphabets_vector[i][tolower(c)-'a'];
            }
        }
        //printing a horizontal graph with *
        cout << "Histogram for Sentence " << i+1 << " is: " << endl;
        for (auto c {'a'}; c <= 'z'; ++c)
        {
            if (alphabets_vector[i][c - 'a'])
            {
                cout << c << " " << string(alphabets_vector[i][c - 'a'], '*') << endl;
            }
        }
        cout << endl;

        for (auto d : alphabets_vector[i])
        {
            sum[i] += d;
        }
    }

    //Normalize the Histogram
    for (int i {0}; i < n; i++)
    {
        for (int j {0}; j < alphabets_vector[i].size(); j++)
        {
            alphabets_vector[i][j] /= sum[i];
        }
    }

    //Compute the squares of the squares of differences of the coressponding bin value
    vector<float> binvalue('z'-'a'+1, 0.0);
    float total_sum {0.0};
    for (int i {0}; i < alphabets_vector[0].size(); i++)
    {
        binvalue[i] = pow((alphabets_vector[0][i] - alphabets_vector[1][i]), 2.0);
        total_sum += binvalue[i];
    }

    cout << "The similarity given by the sum of the squared difference of both sentence is: "; 
    cout << total_sum;
    cout << endl;

    return 0;
}