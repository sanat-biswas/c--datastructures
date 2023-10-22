// https://leetcode.com/problems/single-number/

#include <bits/stdc++.h>

using namespace std;

int singleNumber(vector<int> &nums)
{
    // map<long long, int> mapArr;

    // for (int i = 0; i < nums.size(); i++)
    // {
    //     mapArr[nums[i]]++;
    // }

    // for (auto it : mapArr)
    // {
    //     if (it.second == 1)
    //     {
    //         return it.first;
    //     }
    // }

    // return 0;

    int value = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        value ^= nums[i];
    }
    return value;
}
int main()
{

    vector<int> arr = {4, 1, 2, 1, 2};
    int result = singleNumber(arr);
    cout << result << endl;
}