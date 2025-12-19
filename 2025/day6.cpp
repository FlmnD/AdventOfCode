#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>


using namespace std;

typedef long long ll;

ll eval_problem(const vector<ll> &nums, char op)
{
    if (nums.empty())
        return 0;
    if (op == '+')
    {
        ll s = 0;
        for (ll v : nums)
            s += v;
        return s;
    }
    else if (op == '*')
    {
        ll p = 1;
        for (ll v : nums)
            p *= v;
        return p;
    }
    return 0;
}

int main()
{
    ifstream file("day6.txt");

    vector<string> lines;
    string line;
    while (getline(file, line))
    {
        if (!line.empty() && line.back() == '\r')
            line.pop_back(); 
        lines.push_back(line);
    }

    size_t rows = lines.size();
    size_t cols = 0;
    for (auto &s : lines)
        cols = max(cols, s.size());
    for (auto &s : lines)
        s.resize(cols, ' ');

    size_t op_row = rows - 1;

    vector<bool> is_sep(cols, false);
    for (size_t c = 0; c < cols; ++c)
    {
        bool sep = true;
        for (size_t r = 0; r < rows; ++r)
        {
            if (lines[r][c] != ' ')
            {
                sep = false;
                break;
            }
        }
        is_sep[c] = sep;
    }

    vector<pair<int, int>> blocks;
    int c = 0;
    while (c < (int)cols)
    {
        if (is_sep[c])
        {
            ++c;
            continue;
        }
        int start = c;
        while (c < (int)cols && !is_sep[c])
            ++c;
        int end = c - 1;
        blocks.push_back({start, end});
    }

   
    auto read_row_number = [&](int row, int c_start, int c_end) -> ll
    {
        string s;
        for (int c = c_start; c <= c_end; ++c)
        {
            char ch = lines[row][c];
            if (isdigit((unsigned char)ch))
                s.push_back(ch);
        }
        if (s.empty())
            return -1; 
        return stoll(s);
    };

    auto read_col_number = [&](int col) -> string
    {
        string s;
        for (size_t r = 0; r + 1 < rows; ++r)
        { 
            char ch = lines[r][col];
            if (isdigit((unsigned char)ch))
                s.push_back(ch);
        }
        return s; 
    };

    ll total_part1 = 0;

    for (auto [start, end] : blocks)
    {
        char op = 0;
        for (int col = start; col <= end; ++col)
        {
            char ch = lines[op_row][col];
            if (ch == '+' || ch == '*')
            {
                op = ch;
                break;
            }
        }
        if (!op)
            continue; 

        vector<ll> nums;

        for (int r = 0; r < (int)op_row; ++r)
        {
            ll val = read_row_number(r, start, end);
            if (val != -1)
                nums.push_back(val);
        }

        total_part1 += eval_problem(nums, op);
    }

    ll total_part2 = 0;

    for (auto [start, end] : blocks)
    {
        char op = 0;
        for (int col = start; col <= end; ++col)
        {
            char ch = lines[op_row][col];
            if (ch == '+' || ch == '*')
            {
                op = ch;
                break;
            }
        }
        if (!op)
            continue;

        vector<ll> nums;

        for (int col = end; col >= start; --col)
        {
            string s = read_col_number(col);
            if (!s.empty())
            {
                nums.push_back(stoll(s));
            }
        }

        total_part2 += eval_problem(nums, op);
    }

    cout << "Part 1 total: " << total_part1 << "\n";
    cout << "Part 2 total: " << total_part2 << "\n";

    return 0;
}
