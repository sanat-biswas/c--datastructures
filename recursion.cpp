#include <bits/stdc++.h>
using namespace std;

int nSum(int n)
{
    if (n == 0)
        return 0;
    return n + nSum(n - 1);
}
int main()
{
    int n = 5;
    cout << nSum(n) << endl;
}