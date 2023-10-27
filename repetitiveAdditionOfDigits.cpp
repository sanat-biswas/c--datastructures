#include <bits/stdc++.h>
using namespace std;

int digitSum(int n)
{
    if (n == 0)
        return 0;
    if (n < 10)
        return n;
    else
    {
        int sum = 0;
        while (n > 0)
        {
            int rem = n % 10;
            sum += rem;
            n /= 10;
        }

        return digitSum(sum);
    }
}

int main()
{
    int n = 98;
    cout << digitSum(n) << endl;
}