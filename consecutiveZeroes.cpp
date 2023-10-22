#include <bits/stdc++.h>
using namespace std;

int findMaxConscutiveZeroes(vector<int> &arr)
{

    int count = 0, maxi = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 1)
        {
            count++;
            maxi = max(maxi, count);
        }
        else
        {
            count = 0;
        }
    }

    return maxi;
}
int main()
{

    vector<int> arr = {1, 1, 0, 0, 1, 1, 1, 1, 0, 1};
    int result = findMaxConscutiveZeroes(arr);

    cout << result << endl;
}