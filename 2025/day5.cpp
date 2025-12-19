#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{

    ifstream file("day5.txt");

    string line;

    vector<pair<ll, ll>> vec;

    bool hasreached = false;

    ll freshids = 0;

    while (getline(file, line))
    {

        if (line.empty())
        {
            hasreached = true;
            break;
        }

        if (!hasreached)
        {

            int dashpos = line.find('-');

            ll first = stoll(line.substr(0, dashpos));
            ll second = stoll(line.substr(dashpos + 1, line.size() - dashpos + 1));

            vec.push_back(make_pair(first, second));
        }
        // PART 1
        // else
        // {
        //     for (size_t i = 0; i < vec.size(); i++)
        //     {
        //         auto temp = vec[i];

        //         ll first = temp.first;
        //         ll second = temp.second;

        //         if (stoll(line) >= first && stoll(line) <= second)
        //         {
        //             freshids++;
        //             break;
        //         }

        //     }
        // }
    }

    file.close();

    sort(vec.begin(), vec.end());

    for (auto it = vec.begin() + 1; it != vec.end();)
    {
        auto &second = *(it);
        auto &first = *(it - 1);

        if (second.first >= first.first && second.second <= first.second)
        {
            it = vec.erase(it);
        }
        else if (second.first >= first.first && second.first <= first.second && second.second >= first.second)
        {
            first.second = second.second;
            it = vec.erase(it);
        }
        else
        {
            ++it;
        }

        
    }

    for (auto p : vec)
    {   
        //cout << p.first << "-" << p.second << "\n";
        freshids += p.second - p.first + 1;
        cout << freshids << "\n";
    }

    cout << "\n"
         << freshids << "\n";

    return 0;
}
