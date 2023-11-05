#include <bits/stdc++.h>
using namespace std;

// void printS(int ind, vector<int> &ds, int s, int sum, int arr[], int n)
// {
//     if (ind == n)
//     {
//         if (s == sum)
//         {
//             for (auto it : ds)
//                 cout << it << " ";
//         }
//         cout << endl;
//         return;
//     }

//     ds.push_back(arr[ind]);
//     s += arr[ind];

//     // pick the element
//     printS(ind + 1, ds, s, sum, arr, n);

//     s -= arr[ind];
//     ds.pop_back();

//     // not pick
//     printS(ind + 1, ds, s, sum, arr, n);
// }

// print only one subsequence
// bool printS(int ind, vector<int> &ds, int s, int sum, int arr[], int n)
// {
//     if (ind == n)
//     {
//         if (s == sum)
//         {
//             for (auto it : ds)
//                 cout << it << " ";
//             return true;
//         }
//         cout << endl;
//         return false;
//     }

//     ds.push_back(arr[ind]);
//     s += arr[ind];

//     // pick the element
//     if (printS(ind + 1, ds, s, sum, arr, n) == true)
//         return true;

//     s -= arr[ind];
//     ds.pop_back();

//     // not pick
//     if (printS(ind + 1, ds, s, sum, arr, n))
//         return true;

//     return false;
// }

// return the total count of the subsequences
int printS(int ind, vector<int> &ds, int s, int sum, int arr[], int n)
{
    if (ind == n)
    {
        if (s == sum)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    ds.push_back(arr[ind]);
    s += arr[ind];

    // pick the element
    int l = printS(ind + 1, ds, s, sum, arr, n);

    s -= arr[ind];
    ds.pop_back();

    // not pick
    int r = printS(ind + 1, ds, s, sum, arr, n);

    return l + r;
}
int main()
{
    int arr[] = {1, 2, 1};
    int n = 3;
    int sum = 2;
    vector<int> ds;
    cout << printS(0, ds, 0, sum, arr, n) << endl;
    return 0;
}