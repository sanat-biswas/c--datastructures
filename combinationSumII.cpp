#include <bits/stdc++.h>
using namespace std;

class Solution
{

private:
    void findCombinationSum(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
    {
        if (target == 0)
        {
            ans.push_back(ds);
            return;
        }

        for (int i = ind; i < arr.size(); i++)
        {
            if (i > ind && arr[i] == arr[i - 1])
                continue;
            if (arr[i] > target)
                break;
            ds.push_back(arr[i]);
            findCombinationSum(i + 1, target - arr[i], arr, ans, ds);
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        // sort the array as we need the combinations in sorted order
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        findCombinationSum(0, target, candidates, ans, ds);
        return ans;
    }
};

int main()
{
    vector<int> ans = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    Solution sol;

    vector<vector<int>> combinations = sol.combinationSum2(ans, target);
    for (int i = 0; i < combinations.size(); i++)
    {
        for (int j = 0; j < combinations[i].size(); j++)
        {
            cout << combinations[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}