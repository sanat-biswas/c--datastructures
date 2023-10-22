#include <bits/stdc++.h>

using namespace std;

vector<int> findArrayIntersection(vector<int> &a, int n, vector<int> &b, int m)
{
    vector<int> ans;

    // brute force approach
    //  int visited[m] = {0};
    //  for (int i = 0; i < n; i++)
    //  {
    //      for (int j = 0; j < m; j++)
    //      {
    //          if (a[i] == b[j] && visited[j] == 0)
    //          {
    //              ans.push_back(a[i]);
    //              visited[j] = 1;
    //              break;
    //          }

    //         if (b[j] > a[i])
    //             break;
    //     }
    // }

    // optimal solution

    int i = 0, j = 0;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int last = -1;
    while (i < n && j < m)
    {
        if (a[i] == b[j])
        {

            // if (last != a[i])
            // {

            ans.push_back(a[i]);
            // last = a[i];
            // }
            i++;
            j++;
        }
        else if (b[j] > a[i])
        {
            ++i;
        }
        else
        {
            ++j;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr1 = {4, 9, 5};
    vector<int> arr2 = {9, 4, 9, 8, 4};

    int n = arr1.size();
    int m = arr2.size();

    vector<int> result = findArrayIntersection(arr1, n, arr2, m);

    for (auto i : result)
    {
        cout << i << " ";
    }

    cout << endl;
}