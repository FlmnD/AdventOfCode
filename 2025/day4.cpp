#include <fstream>
#include <vector>
#include <iostream>
#include <chrono>

using namespace std;


int main() {

    auto start = std::chrono::high_resolution_clock::now();

    ifstream file("day4.txt");

    string line;

    vector<vector<char>> vec;

    constexpr int dirx[] = {1, 0, -1, 0, 1, -1, 1, -1};
    constexpr int diry[] = {0, 1, 0, -1, 1, -1, -1, 1};

    int index = 0;

    while (getline(file, line)) {
        vec.emplace_back(line.begin(), line.end());

        index++;
    }

    int pickups = 0;

    bool canmove = true;

    int xlen = vec.size();
    int ylen = vec[0].size();

    while (canmove) {
        canmove = false;
        for (size_t i = 0; i < xlen; i++)
        {
            for (size_t j = 0; j < ylen; j++)
            {

                if (vec[i][j] == '@')
                {
                    int rolls = 0;

                    for (int k = 0; k < 8; k++)
                    {
                        int newx = i + dirx[k];

                        int newy = j + diry[k];

                        if (newy >= 0 && newx >= 0 && newx < xlen && newy < ylen && vec[newx][newy] == '@')
                        {
                            rolls++;
                        }
                    }

                    if (rolls < 4)
                    {
                        pickups++;
                        canmove = true;
                        vec[i][j] = '.';
                    }
                }
            }
        }
    }
    

    cout << pickups << "\n";

    auto stop = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);

    std::cout << "Time taken: " << duration.count() << " ms" << "\n";

    return 0;
}
