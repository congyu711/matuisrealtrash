//Euler Sieven O(n)
/*
    编写一个程序，找出1~N中的所有素数,其中1<N,N为整数。

    输入输出格式要求：
        1.要求每个数后面都要输出逗号，
        请不要输出其他字符

            2.遇到异常情况，输出error
    例如：
    输入：5
    输出：2,3,5,

    输入：a
    输出：error
*/
#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int prime[200010];
bool check[200010];
int cnt, n;
int main()
{
    cin >> n;
    if (n <= 1)
    {
        cout << "error";
        exit(0);
    }
    for (int i = 2; i <= n; i++)
    {
        if (!check[i])
            prime[cnt++] = i;
        for (int j = 0; j < cnt && i * prime[j] <= n; j++)
        {
            check[i * prime[j]] = 1;
            if (i % prime[j] == 0)
            {
                break;
            }
        }
    }
    // for(int i=0;i<cnt;i++)
    // {
    //     cout<<prime[i]<<endl;
    // }
    for (int i = 0; i < cnt; i++)
    {
        cout << prime[i] << ',';
    }
}