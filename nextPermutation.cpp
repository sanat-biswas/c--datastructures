#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterPermutation(vector<int> &a)
{
    int ind = -1;
    int n = a.size();
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] < a[i + 1])
        {
            ind = i;
            break;
        }
    }

    if (ind == -1)
    {
        reverse(a.begin(), a.end());
        return a;
    }

    for (int i = n - 1; i >= ind; i--)
    {
        if (a[i] > a[ind])
        {
            swap(a[i], a[ind]);
            break;
        }
    }

    reverse(a.begin() + ind + 1, a.end());
    return a;
}
int main()
{

    vector<int> arr = {2, 1, 5, 4, 3, 0, 0};

    // Print the original array
    cout << "The original array is: ";
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;

    // Find the next greater permutation
    vector<int> next_permutation = nextGreaterPermutation(arr);

    // Print the next greater permutation
    cout << "The next greater permutation is: ";
    for (int i = 0; i < next_permutation.size(); i++)
        cout << next_permutation[i] << " ";
    cout << endl;

    return 0;
}