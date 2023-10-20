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
    while (i < n && j < m)
    {
        if (a[i] < b[j])
        {
            i++;
        }
        else if (b[j] < a[i])
        {
            j++;
        }
        else
        {
            // incase both are equal
            ans.push_back(a[i]);
            i++;
            j++;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr1 = {1, 1, 2, 3, 4, 5, 6};
    vector<int> arr2 = {2, 3, 4, 4, 5, 6};

    int n = arr1.size();
    int m = arr2.size();

    vector<int> result = findArrayIntersection(arr1, n, arr2, m);

    for (auto i : result)
    {
        cout << i << " ";
    }

    cout << endl;
}