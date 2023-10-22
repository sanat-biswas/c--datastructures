#include <bits/stdc++.h>

using namespace std;

long long maxSubArraySum(vector<int> &arr)
{

    //using kadane's algorithm
    long long sum = 0;

    long long maximum = LONG_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];

        if (sum > maximum)
        {
            maximum = sum;
        }

        if (sum < 0)
        {
            sum = 0;
        }
    }

    return maximum;
}
int main()
{

    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxSubArraySum(arr) << endl;
}