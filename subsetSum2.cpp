#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void findSubsets(int ind, vector<int> &nums, vector<vector<int>> &ans, vector<int> &ds)
    {
        ans.push_back(ds);

        for (int i = ind; i < nums.size(); i++)
        {

            if (i != ind && nums[i] == nums[i - 1])
                continue;
            // for picking up the element
            ds.push_back(nums[i]);
            findSubsets(i + 1, nums, ans, ds);
            ds.pop_back();
        }

        // for not picking up the element
        // findSubsetSum(ind + 1, sum, arr, n, subsetSum);
    }

public:
    vector<vector<int>> subsetsums(vector<int> nums)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        findSubsets(0, nums, ans, ds);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    // Create a vector of integers
    vector<int> arr = {5, 2, 1};

    // Create a Solution object
    Solution sol;

    // Find all subsets of the given array
    vector<vector<int>> subsets = sol.subsetsums(arr);

    // Print the results
    for (int i = 0; i < subsets.size(); i++)
    {
        for (int j = 0; j < subsets[i].size(); j++)
        {
            cout << subsets[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}