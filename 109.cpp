#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;
char arr[300];
int cnt, ans;

int main()
{
    char c;
    while ((c = getchar()) != '\n')
    {
        arr[cnt++] = c;
    }
    arr[cnt++] = ' ';
    bool flag = 0;

    for (int i = 0; i < cnt; i++)
    {
        if (arr[i] == ' ')
        {
            if (flag == 1)
            {
                ans++;
                flag = 0;
            }
            continue;
        }
        else
        {
            flag = 1;
        }
    }
    cout << ans;
}