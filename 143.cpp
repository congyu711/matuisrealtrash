/*

    题 号:	143	统计字符串中字符a和d的个数	语言要求：	C++
    编写程序，输入一个字符串，分别统计输出该字符串中的字母a和d的个数。

    输入输出格式要求：
        输入格式：string回车
    例如：
    输入：thedaythemonththeyear123回车
    输出：a:2,d:1
    输入：a
    输出：a:1,d:0
*/
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
int cnta, cntd;
int main()
{
    string a;
    cin >> a;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == 'a')
            cnta++;
        else if (a[i] == 'd')
            cntd++;
    }
    cout << "a:" << cnta << ",d:" << cntd << endl;
}