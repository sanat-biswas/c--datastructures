#include <bits/stdc++.h>

using namespace std;

int longestSubArrayWithSumk(vector<int> &arr, long long k)
{

    // if the array contains the negatives and zeroes
    //  map<long long, int> prefixSum;
    //  long long sum = 0;
    //  int maxLen = 0;

    // for (int i = 0; i < arr.size(); i++)
    // {
    //     sum += arr[i];
    //     if (sum == k)
    //     {
    //         maxLen = max(maxLen, i + 1);
    //     }

    //     long long rem = sum - k;
    //     if (prefixSum.find(rem) != prefixSum.end())
    //     {
    //         int len = i - prefixSum[rem];
    //         maxLen = max(maxLen, len);
    //     }

    //     if (prefixSum.find(sum) == prefixSum.end())
    //     {
    //         prefixSum[sum] = i;
    //     }
    // }

    int left = 0, right = 0;
    int maxLen = 0;

    long long sum = arr[0];
    int n = arr.size();

    while (right < n)
    {

        while (left <= right && sum > k)
        {
            sum -= arr[left];
            left++;
        }
        if (sum == k)
        {
            maxLen = max(maxLen, right - left + 1);
        }

        right++;
        if (right < n)
            sum += arr[right];
    }

    return maxLen;
}
int main()
{
    vector<int> arr = {1, 2, 3, 1, 1, 1, 1, 3, 3};
    int k = 6;
    int result = longestSubArrayWithSumk(arr, k);
    cout << result << endl;
}