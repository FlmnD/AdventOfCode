#include <iostream>
#include <fstream>
#include <string>

using namespace std;

typedef long long ll;

bool isRepeat(const string& s) {

    if (s.size() < 2) return false;

    // PART 1
    //ll ind = s.size() / 2;

    // if (s.substr(0, ind) == s.substr(ind, s.size() - ind)) {
    //     return true;
    // }

    string temp = "";

    bool isbroken = false;
    
    for (ll i = s.size(); i >= 0; i--) {

        string ssubs = s.substr(0, i);

        ll sub = s.find(ssubs, 0);

        if (sub != string::npos && s.find(ssubs, sub + 1) != string::npos && s.find(ssubs, sub + 1) == sub + ssubs.size())
        {
            temp = s.substr(s.find(ssubs, sub + 1), i);
            isbroken = true;
            break;
        }
    }

    if (!isbroken) return false;
        

    ll j = 1;

    while (j < s.size()) {
 
        ll t = s.find(temp, j);

        if (t != string::npos && t == j + temp.size() - 1)
        {
            j = t;
  
            if (j + temp.size() == s.size())
            {   
                // cout << s << "\n";
                return true;
            }
        }
        else
        {
            return false;
        }

        j++;
        
    }
    
    return false;
}

int main () {

    ifstream file("day2.txt");

    string line;

    ll count = 0;

    while (getline(file, line, ',')) {

        ll ind = line.find('-');

        string first = line.substr(0, ind);
        string second = line.substr(ind + 1, line.size() - ind + 1);

        ll firstint = stoll(first);
        ll secondint = stoll(second);

        for (ll i = firstint; i <= secondint; i++) {
            string id = to_string(i);
                if (isRepeat(id))
                {
                    count += i;
                }
        }

        
    }

    cout << count << "\n";

    return 0;
}
