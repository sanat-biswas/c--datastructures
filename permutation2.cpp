#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void recurPermute(int ind, vector<int> &nums, vector<vector<int>> &ans)
    {
        if (ind == nums.size())
        {
            ans.push_back(nums);
            return;
        }

        for (int i = ind; i < nums.size(); i++)
        {
            swap(nums[ind], nums[i]);
            recurPermute(ind + 1, nums, ans);
            swap(nums[ind], nums[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        recurPermute(0, nums, ans);
        return ans;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3};

    // Create an object of the Solution class
    Solution sol;

    // Call the permute() function to generate all permutations of the vector
    vector<vector<int>> permutations = sol.permute(nums);

    // Print all permutations to the console
    for (auto permutation : permutations)
    {
        for (auto element : permutation)
        {
            cout << element << " ";
        }
        cout << endl;
    }

    return 0;
}