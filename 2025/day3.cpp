#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;


// PART 1

int main()
{

    int maxjolt = 0;

    ifstream file("day3.txt");

    string line;

    while (getline(file, line))
    {

        int maxnum = 0;

        for (size_t i = 0; i < line.size(); i++)
        {
            int first = line[i] - '0';
            for (size_t j = i + 1; j < line.size(); j++)
            {
                int second = line[j] - '0';

                int combined = first * 10 + second;

                maxnum = max(combined, maxnum);
            }
        }

        maxjolt += maxnum;
    }

    cout << maxjolt << "\n";

    return 0;
}


// PART 2

int main()
{

    ifstream file("day2.txt");

    string line;

    vector<char> stack;

    ll voltagetot = 0;

    while (getline(file, line))
    {

        ll removenum = line.size() - 12;

        for (size_t i = 0; i < line.size(); i++)
        {

            while (!stack.empty() && stack.back() < line[i] && removenum > 0)
            {
                stack.pop_back();
                removenum--;
            }

            

            stack.push_back(line[i]);
        }

        while (removenum > 0 && !stack.empty())
        {
            stack.pop_back();
            removenum--;
        }

        cout << removenum << "\n";

        string numstr = "";

        for_each(stack.begin(), stack.end(), [&numstr](char element)
                 { numstr.append(1, element); });

        cout << numstr << "\n";

        voltagetot += stoll(numstr);

        stack.clear();
    }

    cout << "\n"
         << voltagetot << "\n";

    return 0;
}
