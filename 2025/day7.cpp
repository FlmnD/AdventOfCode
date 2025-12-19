#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <memory>
#include <queue>
#include <stack>
#include <set>
#include <utility>

using namespace std;

typedef long long ll;

// template <typename T>
// void print2DVec(const vector<vector<T>> &vec)
// {
//     for_each(vec.begin(), vec.end(), [](auto vectemp)
//              {

//                  for_each(vectemp.begin(), vectemp.end(), [](T num)
//                           { cout << num << " "; });
//                  cout << "\n"; });
// }

// template <typename T>
// struct TreeNode
// {
//     T data;
//     TreeNode<T> *left;
//     TreeNode<T> *right;

//     TreeNode(T val) : data(val), left(nullptr), right(nullptr) {}

//     static void freeTree(TreeNode<T> **node);
//     static void printTree(const TreeNode<T> *node);
// };

// template <typename T>
// void TreeNode<T>::freeTree(TreeNode<T> **node)
// {
//     stack<TreeNode<T> *> s;

//     if (!node || !*node)
//         return;

//     s.push(*node);

//     while (!s.empty())
//     {
//         TreeNode<T> *temp = s.top();
//         s.pop();
//         if (temp->left)
//             s.push(temp->left);
//         if (temp->right)
//             s.push(temp->right);

//         delete temp;
//         temp = nullptr;
//     }

//     *node = nullptr;
// }

// template <typename T>
// void TreeNode<T>::printTree(const TreeNode<T> *node)
// {

//     if (!node)
//         return;

//     printTree(node->left);
//     cout << node->data << " ";
//     printTree(node->right);
// }

// void dfs(const TreeNode<pair<size_t, size_t>> *root, vector<pair<size_t, size_t>> &current, set<vector<pair<size_t, size_t>>> &all)
// {

//     if (!root)
//         return;

//     current.push_back(root->data);

//     if (!root->left && !root->right)
//         all.insert(current);
//     else
//     {
//         dfs(root->left, current, all);
//         dfs(root->right, current, all);
//     }

//     current.pop_back();
// }

// TreeNode<pair<size_t, size_t>> *buildTree(const vector<vector<char>> &grid,
//                                           size_t R, size_t C,
//                                           size_t r, size_t c)
// {
//     if (r < 0 || r >= R || c < 0 || c >= C)
//         return nullptr;

//     char cell = grid[r][c];
//     TreeNode<pair<size_t, size_t>> *node = new TreeNode<pair<size_t, size_t>>(make_pair(r, c));

//     if (r == R - 1)
//         return node;

//     if (cell == 'S' || cell == '.')
//     {
//         node->left = buildTree(grid, R, C, r + 1, c);
//     }
//     else if (cell == '^')
//     {
//         node->left = buildTree(grid, R, C, r + 1, c - 1);
//         node->right = buildTree(grid, R, C, r + 1, c + 1);
//     }

//     return node;
// }

// PART 1

int main()
{

    ifstream file("day7.txt");

    string line;

    vector<vector<char>> grid;

    size_t srow = 0;
    size_t scol = 0;

    bool firstPass = true;

    while (getline(file, line))
    {   
        if (firstPass) {
            firstPass = false;
            scol = line.find('S');
        }
        grid.emplace_back(vector<char>(line.begin(), line.end()));
    }

    unordered_set<size_t> rpos;


    int splits = 0;
    int timelines = 0;

    // auto root = buildTree(grid, grid.size(), grid[0].size(), srow, scol);

        for (size_t i = 0; i < grid.size(); i++)
    {
        for (size_t j = 0; j < grid[0].size(); j++)
        {
            char curr = grid[i][j];

            if (curr == 'S')
            {
                rpos.insert(j);
            }
            else if (curr == '^')
            {
                if (rpos.count(j) > 0)
                {
                    rpos.erase(j);
                    splits++;
                    rpos.insert(j + 1);
                    rpos.insert(j - 1);
                }
            }
        }
    }

    // vector<pair<size_t, size_t>> op;
    // set<vector<pair<size_t, size_t>>> all;

    // dfs(root, op, all);

    // //TreeNode<pair<size_t, size_t>>::printTree(root);
    // cout << "\n";
    // TreeNode<pair<size_t, size_t>>::freeTree(&root);

    // // timelines = dfs(root);

    // print2DVec(grid);

    cout << splits << "\n";
    //cout << all.size() << "\n";

    return 0;
}

// PART 2

ll dfs(const vector<string> &grid,
                  int R, int C,
                  int r, int c)
{
    if (r < 0 || r >= R || c < 0 || c >= C)
        return 0;

    char cell = grid[r][c];

    if (r == R - 1)
        return 1;

    if (cell == 'S' || cell == '.')
    {
        return dfs(grid, R, C, r + 1, c);
    }
    else if (cell == '^')
    {
        ll leftPaths = dfs(grid, R, C, r, c - 1);
        ll rightPaths = dfs(grid, R, C, r, c + 1);
        return leftPaths + rightPaths;
    }
    else
    {
        return 0;
    }
}

int main()
{
    ifstream file("day7.txt");

    vector<string> grid;
    string line;

    int srow = -1, scol = -1;
    int r = 0;

    while (getline(file, line))
    {
        if (!line.empty() && line.back() == '\r')
        {
            line.pop_back();
        }

        grid.push_back(line);

        if (srow == -1)
        {
            auto pos = line.find('S');
            if (pos != string::npos)
            {
                srow = r;
                scol = static_cast<int>(pos);
            }
        }

        ++r;
    }

    int R = static_cast<int>(grid.size());
    int C = (R > 0 ? static_cast<int>(grid[0].size()) : 0);

    ll totalPaths = dfs(grid, R, C, srow, scol);

    cout << totalPaths << "\n";

    return 0;
}
