#include <bits/stdc++.h>
using namespace std;


//find the second largest element in the array
int secondLargest(vector<int> &a, int n)
{
    int largest = a[0];
    int secondLargest = -1;

    for (int i = 0; i < n; i++)
    {
        if (a[i] > largest)
        {
            secondLargest = largest;
            largest = a[i];
        }
        else if (a[i] < largest && a[i] > secondLargest)
        {
            secondLargest = a[i];
        }
    }

    return secondLargest;
}
// for finding the largest element
int main()
{

    vector<int> arr = {1, 2, 3, 4, 5};
    cout << secondLargest(arr, arr.size()) << endl;
}