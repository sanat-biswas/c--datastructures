#include <bits/stdc++.h>
using namespace std;

// find the maximum of two elements
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// find the maximum of three elements
int max(int a, int b, int c)
{
    return max(max(a, b), c);
}

int maxSubArrayCrossingSum(vector<int> &arr, int l, int m, int h)
{
    int sum = 0;
    int leftSum = INT_MIN;

    for (int i = m; i >= l; i--)
    {
        sum += arr[i];
        if (sum > leftSum)
        {
            leftSum = sum;
        }
    }

    sum = 0;
    int rightSum = INT_MIN;
    for (int i = m; i <= h; i++)
    {
        sum += arr[i];
        if (sum > rightSum)
        {
            rightSum = sum;
        }
    }

    return max(leftSum + rightSum - arr[m], leftSum, rightSum);
}

int maxSubArraySum(vector<int> &arr, int l, int h)
{
    if (l > h)
    {
        return INT_MIN;
    }

    if (l == h)
    {
        return arr[l];
    }

    int m = (l + h) / 2;

    /**
     * return the maximum of the following three possible cases:
     * a. Maximum subArray in the left half
     * b. Maximum subarray in the right half;
     * maximum subarray sum such that the subarray crosses the midpoint
     */
    int maximum = max(maxSubArraySum(arr, l, m - 1),
                      maxSubArraySum(arr, m + 1, h),
                      maxSubArrayCrossingSum(arr, l, m, h));

    cout << maximum << endl;

    return maximum;
}
int main()
{
    vector<int> arr = {-2, -1};
    int n = arr.size();
    cout << maxSubArraySum(arr, 0, n - 1) << endl;
}