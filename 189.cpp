/*
    题目3：输入n(n<100)个有序正数，请用折半查找算法，查找x在其中的位置。
    例如,
    输入:
    5
    1,2,3,4,5
    2
    输出:
    2
    测试集合中，x数一定在正数数组中。即不用处理错误逻辑。
*/
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> arr;
    int n, t, tar;
    cin >> n;
    while (n--)
    {
        cin >> t;
        arr.push_back(t);
        getchar();
    }
    cin >> tar;
    int ans = distance(arr.begin(), lower_bound(arr.begin(), arr.end(), tar)) + 1;
    cout << ans;
}
//lower_bound