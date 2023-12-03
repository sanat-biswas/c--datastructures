#include <bits/stdc++.h>

using namespace std;

vector<int> getRow(int rowIndex)
{
    vector<int> arr(rowIndex + 1);

    arr[0] = 1;

    int ans = 1;
    for (int i = 1; i <= rowIndex; i++)
    {
        ans *= (rowIndex - i + 1);

        ans /= i;
        arr[i] = ans;

        // cout<<(rowIndex - i) <<" ans ";
    }
    return arr;
}
int main()
{
    int row = 3;
    vector<int> res = getRow(row);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}