#include <iostream>
#include <fstream>
#include <string>

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


