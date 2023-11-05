#include <bits/stdc++.h>
using namespace std;

vector<int> superiorElement(vector<int> &a)
{
    vector<int> ans;
    int n = a.size();

    int maximum = INT_MIN;
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] > maximum)
        {
            ans.push_back(a[i]);
        }

        maximum = max(maximum, a[i]);
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{

    vector<int> arr = {1, 2, 3, 2};

    vector<int> res = superiorElement(arr);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}