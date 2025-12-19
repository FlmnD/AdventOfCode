#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{

    ifstream file("day1.txt");

    string line;

    int pos = 50;
    int zeronum = 0;

    while (getline(file, line))
    {
        int rot = stoi(line.substr(1, line.size() - 1));

        string move = line.substr(0, 1);

        if (rot > 100)
        {
            zeronum += rot / 100;
            rot %= 100;
        }

        if (move == "L")
        {
            int temp = pos - rot;

            if (temp < 0)
            {
                if (pos != 0)
                    zeronum++;

                pos = 100 - abs(temp);
            }
            else if (temp > 0)
            {
                pos = temp;
            }
            else
            {
                pos = 0;
            }

            cout << zeronum << " LL\n";
        }
        else
        {
            int temp = pos + rot;
            if (temp > 100)
            {
                if (pos != 0)
                    zeronum++;
                pos = temp - 100;
            }
            else if (temp < 100)
            {
                pos = temp;
            }
            else
            {
                pos = 0;
            }

            cout << zeronum << " RR\n";
        }

        if (pos == 0)
            zeronum++;
    }

    cout << "\n\n\n"
         << pos << "\n";
    cout << zeronum << "\n";

    return 0;
}
