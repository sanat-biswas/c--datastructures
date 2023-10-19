#include <iostream>
using namespace std;

int main()
{
    string str = "welcome";

    string str_reverse;
    for (int i = str.size() - 1; i >= 0; i--)
    {
        str_reverse += str[i];
    }

    cout << str_reverse << endl;
}