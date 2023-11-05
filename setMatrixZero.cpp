#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> setMatrixZero(vector<vector<int>> &matrix, int n, int m)
{
    int col[m] = {0};
    int row[n] = {0};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            //if the row or col is marked
            if (row[i] || col[j])
            {
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}
int main()
{
    int n = 3, m = 3;
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};

    // Set all elements in rows and columns containing a zero to zero
    matrix = setMatrixZero(matrix, n, m);

    // Print the modified matrix

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}