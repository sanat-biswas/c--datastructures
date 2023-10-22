#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &arr)
{
    // map<int, int> mpp;

    // for (int i = 0; i < arr.size(); i++)
    // {
    //     mpp[arr[i]]++;
    // }

    // for (auto it : mpp)
    // {
    //     if (it.second > (arr.size() / 2))
    //     {
    //         return it.first;
    //     }
    // }

//Alogrithm ===> Moore's voting algorithm
    int cnt = 0;
    int el;

    for (int i = 0; i < arr.size(); i++)
    {
        if (cnt == 0)
        {
            cnt++;
            el = arr[i];
        }
        else if (arr[i] == el)
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
    }

    int cnt1 = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == el)
            cnt1++;
    }
    if (cnt1 > (arr.size()) / 2)
    {
        return el;
    }

    return -1;
}
int main()
{

    vector<int> arr = {3, 2, 3};
    int result = majorityElement(arr);
    cout << result << endl;
}