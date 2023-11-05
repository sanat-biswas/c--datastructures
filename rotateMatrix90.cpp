#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> rotateMatrix90Degrees(vector<vector<int>> &matrix, int n)
{
    vector<vector<int>> ans(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans[j][n - 1 - i] = matrix[i][j];
        }
    }

    return ans;
}
int main()
{

    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

    int n = matrix.size();

    vector<vector<int>> res = rotateMatrix90Degrees(matrix, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << res[i][j] << " ";
        }

        cout << endl;
    }
}