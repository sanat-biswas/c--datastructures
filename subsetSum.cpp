#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void findSubsetSum(int ind, int sum, vector<int> &arr, int n, vector<int> &subsetSum)
    {
        if (ind == n)
        {
            subsetSum.push_back(sum);
            return;
        }

        // for picking up the element
        findSubsetSum(ind + 1, sum + arr[ind], arr, n, subsetSum);

        // for not picking up the element
        findSubsetSum(ind + 1, sum, arr, n, subsetSum);
    }

public:
    vector<int> subsetsums(vector<int> arr, int n)
    {
        vector<int> ans;
        findSubsetSum(0, 0, arr, n, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
  // Create a vector of integers
  vector<int> arr = {5, 2, 1};

  // Create a Solution object
  Solution sol;

  // Find all subset sums of the given array
  vector<int> subsetSums = sol.subsetsums(arr, arr.size());

  // Print the results
  for (int i = 0; i < subsetSums.size(); i++) {
    cout << subsetSums[i] << " ";
  }
  cout << endl;

  return 0;
}