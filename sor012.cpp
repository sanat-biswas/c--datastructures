#include <bits/stdc++.h>
using namespace std;

void sortArray(vector<int> &arr, int n)
{
    int cnt_0 = 0, cnt_1 = 0, cnt_2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            cnt_0++;
        else if (arr[i] == 1)
            cnt_1++;
        else
            cnt_2++;
    }

    // replace the places in the original array
    for (int i = 0; i < cnt_0; i++)
    {
        arr[i] = 0;
    }

    for (int i = cnt_0; i < cnt_0 + cnt_1; i++)
    {
        arr[i] = 1;
    }

    for (int i = cnt_0 + cnt_1; i < n; i++)
    {
        arr[i] = 2;
    }
}
int main()
{
    vector<int> arr = {0, 2, 1, 2, 0, 1};
    sortArray(arr, arr.size());

    cout << "After sorting:" << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0;
}