#include <bits/stdc++.h>
using namespace std;

int longestConsecutiveSubsequence(vector<int> &arr)
{
    if (arr.size() == 0)
        return 0;
    // brute force
    //  sort(arr.begin(), arr.end());

    // int n = arr.size();
    // int count = 0, longest = 1, lastSmaller = INT_MIN;

    // for (int i = 0; i < n; i++)
    // {
    //     // if the previous element is consecutive
    //     if (arr[i] - 1 == lastSmaller)
    //     {
    //         count++;
    //         lastSmaller = arr[i];
    //     }

    //     // if the element is not equal to last smaller or the element is not consecutive then refresh the count with 1
    //     // and put that element in the lastsmaller
    //     else if (lastSmaller != arr[i])
    //     {
    //         count = 1;
    //         lastSmaller = arr[i];
    //     }

    //     longest = max(longest, count);
    // }


    //optimal
    int longest = 1;
    int n = arr.size();

    unordered_set<int> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(arr[i]);
    }

    for (auto it : st)
    {
        if (st.find(it - 1) == st.end())
        {
            int count = 1;
            int x = it;
            while (st.find(x + 1) != st.end())
            {
                x += 1;
                count++;
            }

            longest = max(longest, count);
        }
    }

    return longest;
}
int main()
{
    vector<int> arr = {100, 102, 100, 101, 101, 4, 3, 2, 3, 2, 1, 1, 1, 2};
    cout << longestConsecutiveSubsequence(arr) << endl;
}