#include <bits/stdc++.h>

using namespace std;

vector<int> unionArrays(vector<int> &arr1, vector<int> &arr2, int n, int m)
{
    set<int> st;

    for (int i = 0; i < n; i++)
    {
        st.insert(arr1[i]);
    }

    for (int j = 0; j < m; j++)
    {
        st.insert(arr2[j]);
    }

    vector<int> unionArr(st.size());

    for (auto it : st)
    {
        unionArr.push_back(it);
    }

    return unionArr;
}
int main()
{

    vector<int> arr1 = {1, 1, 2, 3, 4, 5 ,6};
    vector<int> arr2 = {2, 3, 4, 4, 5, 6};

    vector<int> result = unionArrays(arr1, arr2, arr1.size(), arr2.size());

    // for (int ele : result)
    // {

        
    //     cout << ele << " ";
    // }


    for(int i = 0; i < result.size(); i++ ){
        cout<< result[i] << " "; 
    }
    cout << endl;
}