#include <bits/stdc++.h>

using namespace std;

int missingNumber(vector<int> &arr, int n)
{
    // brute force
    //  for (int i = 0; i <= n; i++)
    //  {
    //      int flag = 0;
    //      for (int j = 0; j < n; j++)
    //      {
    //          if (arr[j] == i)
    //          {
    //              flag = 1;
    //              break;
    //          }
    //      }

    //     if (flag == 0)
    //         return i;
    // }

    // return -1;

    // better
    //  vector<int> hashArr(n+1, 0);
    //  for (int i = 0; i < n; i++)
    //  {
    //      hashArr[arr[i]] = 1;
    //  }

    // for (int i = 1; i <= n; i++)
    // {
    //     if (hashArr[i] == 0)
    //         return i;
    // }

    // return -1;

    // optimal
    int xor1 = 0, xor2 = 0;
    for (int i = 0; i < n; i++)
    {
        xor2 = xor2 ^ arr[i];
        xor1 = xor1 ^ (i + 1);
    }
    return xor1 ^ xor2;
}

int main()
{

    vector<int> arr = {1, 2, 4, 5};
    int n = 5;
    int result = missingNumber(arr, n);
    cout << result << endl;
    return 0;
}