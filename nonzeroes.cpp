#include <bits/stdc++.h>

using namespace std;

vector<int> moveZeroes(vector<int> &arr, int n)
{
    // vector<int> temp;

    // for (int i = 0; i < n; i++)
    // {

    //     if (arr[i] != 0)
    //     {
    //         temp.push_back(arr[i]);
    //     }
    // }

    // int nz = temp.size();

    // for (int i = 0; i < nz; i++)
    // {
    //     arr[i] = temp[i];
    // }

    // for (int i = nz; i < n; i++)
    // {
    //     arr[i] = 0;
    // }

    // return arr;

    int j = -1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            j = i;
            break;
        }  
    }

    if (j == -1)
        return arr;

    for (int i = j + 1; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }

    return arr;
}

int main()
{

    vector<int> arr = {1, 2, 3, 0, 9, 2, 0};
    int n = arr.size();

    moveZeroes(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}