#include <bits/stdc++.h>
using namespace std;

int arrSum(int arr[], int n)
{
    if (n <= 0)
        return 0;
    return arrSum(arr, n - 1) + arr[n - 1];
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << arrSum(arr, n) << endl;
}