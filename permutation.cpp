#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void recurPermute(vector<int> &ds, vector<int> &nums, vector<vector<int>> &ans, int freq[])
    {
        if (ds.size() == nums.size())
        {
            ans.push_back(ds);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (!freq[i])
            {
                freq[i] = true;
                ds.push_back(nums[i]);
                recurPermute(ds, nums, ans, freq);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        int freq[nums.size()];

        for (int i = 0; i < nums.size(); i++)
            freq[i] = 0;
        recurPermute(ds, nums, ans, freq);
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