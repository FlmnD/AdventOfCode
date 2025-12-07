#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <memory>

using namespace std;

template <typename T>
void print2DVec(const vector<vector<T>> &vec)
{
    for_each(vec.begin(), vec.end(), [](auto vectemp)
             {

                 for_each(vectemp.begin(), vectemp.end(), [](T num)
                          { cout << num << " "; });
                 cout << "\n"; });
}

class TreeNode
{
public:
    TreeNode(int data) : data(data), left(nullptr), right(nullptr) {}
    TreeNode(int data, std::unique_ptr<TreeNode> &&left, std::unique_ptr<TreeNode> &&right) : data(data), left(std::move(left)), right(std::move(right)) {}

    void setData(int data)
    {
        this->data = data;
    }

    void setLeft(std::unique_ptr<TreeNode> left)
    {
        this->left = std::move(left);
    }

    void setRight(std::unique_ptr<TreeNode> right)
    {
        this->right = std::move(right);
    }

    int getData() const
    {
        return data;
    }

    const TreeNode *getRight() const
    {
        return right.get();
    }

    const TreeNode *getLeft() const
    {
        return left.get();
    }

private:
    int data;
    std::unique_ptr<TreeNode> left;
    std::unique_ptr<TreeNode> right;
};

int dfs(TreeNode *root) {

    if (!root) return 1;

    

    
}

int main()
{

    ifstream file("day7.txt");

    string line;

    vector<vector<char>> grid;

    bool firstPass = true;

    size_t spos = 0;

    while (getline(file, line))
    {
        if (grid.size() == 0)
            spos = line.find('S');
        grid.emplace_back(vector<char>(line.begin(), line.end()));
    }

    unordered_set<size_t> rpos;

    int splits = 0;
    int timelines = 0;

    TreeNode root(spos);

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
                    root.setRight(make_unique<TreeNode>(j+1));
                    rpos.insert(j - 1);
                    root.setLeft(make_unique<TreeNode>(j - 1));
                }
            }
        }
    }


    print2DVec(grid);

    cout << splits << "\n";

    return 0;
}
