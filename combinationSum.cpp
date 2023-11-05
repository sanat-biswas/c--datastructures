#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        printSum(0, candidates, target, ans, ds);
        return ans;
    }

private:
    void printSum(int ind, vector<int> &arr, int target, vector<vector<int>> &ans, vector<int> &ds)
    {

        if (ind == arr.size())
        {
            if (target == 0)
            {
                ans.push_back(ds);
            }
            return;
        }

        if (arr[ind] <= target)
        {
            ds.push_back(arr[ind]);
            printSum(ind, arr, target - arr[ind], ans, ds);
            ds.pop_back();
        }

        printSum(ind + 1, arr, target, ans, ds);
    }
};

int main()
{
    vector<int> ans = {10,1,2,7,6,1,5};
    int target = 8;
    Solution sol;

    vector<vector<int>> combinations = sol.combinationSum(ans, target);
    for (vector<int> combination : combinations)
    {

        for (int element : combination)
        {
            cout << element << " ";
        }
        cout << endl;
    }
    // return 0;
}
