#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    int c;
    for (int i = 0; i < n; i++)
    {
        cin >> c;
        arr.push_back(c);
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
        if (i != arr.size() - 1)
            cout << ',';
    }
}