#include <bits/stdc++.h>

using namespace std;

vector<int> rearrangeArray(vector<int> &nums)
{
    int n = nums.size();
    int positiveIndex = 0, negativeIndex = 1;

    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (nums[i] < 0)
        {
            // negatives

            ans[negativeIndex] = nums[i];
            negativeIndex += 2;
        }
        else
        {
            // positives

            ans[positiveIndex] = nums[i];
            positiveIndex += 2;
        }
    }

    return ans;
}
int main()
{
    vector<int> arr = {3, 1, -2, -5, 2, -4};
    vector<int> result = rearrangeArray(arr);
    for (auto it : result)
    {
        cout << it << " ";
    }
    cout << endl;
}