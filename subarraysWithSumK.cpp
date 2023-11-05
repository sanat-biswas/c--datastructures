#include <bits/stdc++.h>

using namespace std;

int findAllSubarrayWithGivenSum(vector<int> &arr, int k)
{
    unordered_map<int, int> mpp;
    mpp[0] = 1;
    int prefSum = 0, cnt = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        prefSum += arr[i];
        int remove = prefSum - k;
        cnt += mpp[remove];
        mpp[prefSum] += 1;
    }
    return cnt;
}
int main()
{
    vector<int> arr = {1, 2, 3, -1, 1, 1, 1, 4, 2, -1};
    int k = 3;
    int count = findAllSubarrayWithGivenSum(arr, k);
    cout << count << endl;
}