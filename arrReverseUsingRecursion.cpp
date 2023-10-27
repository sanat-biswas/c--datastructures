#include <bits/stdc++.h>
using namespace std;

void fn(int i, int arr[], int n)
{
    if (i >= n / 2)
        return;
    swap(arr[i], arr[n - i - 1]);
    fn(i + 1, arr, n);
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};

    fn(0, arr, 5);
    for (int i = 0; i < 5; i++)
    {

        cout << arr[i] << " ";
    }
    cout << endl;
}