//我怎么也没能想到，某门课程最高分的学生竟然竟然还要有顺序要求
//垃圾码图


/*
编写学生管理系统，其中学生的信息有姓名（汉语拼音，最多20个字符），性别（男/女，用1表示男，2表示女）、
生日（19850101（年月日））、身高（以m为单位），还需要处理C语言、微积分两门课的成绩，请编写程序实现功能：
输入学生的人数和每个学生的信息；输出每门课程的总平均成绩、最高分和最低分，以及获得最高分的学生的信息。
需要注意的是某门课程最高分的学生可能不只一人。

输入输出格式要求：
身高输出时保留两位小数，请按照例子中进行输出，请勿输出其他字符
例如：
输入：3 zhangsan 1 19910101 1.85 85 90 lisi 1 19920202 1.56 89 88 wangwu 2 19910303 1.6 89 90回车
输出：
C_average:87
C_max:89
lisi 1 19920202 1.56 89 88
wangwu 2 19910303 1.60 89 90
C_min:85
Calculus_average:89
Calculus_max:90
zhangsan 1 19910101 1.85 85 90
wangwu 2 19910303 1.60 89 90
Calculus_min:88
*/

#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
int caltot, calmax, cppmax, cpptot;
int calmin = 0x7fffffff, cppmin = 0x7fffffff;
class stu
{
public:
    double height;
    string name;
    int sex;
    int birthday;
    int cplusplus;
    int calculus;
};
vector<int> calindex, cppindex;
int main(int argc, char **argv)
{
    int n;
    cin >> n;
    stu ans[2000];

    for (int i = 0; i < n; i++)
    {
        cin >> ans[i].name >> ans[i].sex >> ans[i].birthday >>
            ans[i].height >> ans[i].cplusplus >> ans[i].calculus;
        getchar();
        calmax = max(calmax, ans[i].calculus);
        cppmax = max(cppmax, ans[i].cplusplus);
        calmin = min(calmin, ans[i].calculus);
        cppmin = min(cppmin, ans[i].cplusplus);
    }
    for (int i = 0; i < n; i++)
    {
        caltot += ans[i].calculus;
        cpptot += ans[i].cplusplus;
        if (ans[i].calculus == calmax)
        {
            calindex.push_back(i);
        }
        if (ans[i].cplusplus == cppmax)
        {
            cppindex.push_back(i);
        }
    }
    //sort(ans, ans + n, cmpcpp);
    cout << "C_average:" << cpptot / n << endl;
    cout << "C_max:" << cppmax << endl;
    for (int i = 0; i < cppindex.size(); i++)
    {
        int c = cppindex[i];
        //lisi 1 19920202 1.56 89 88
        cout << ans[c].name << ' ' << ans[c].sex << ' ' << ans[c].birthday << ' ';
        printf("%.2f", ans[c].height);
        cout << ' ' << ans[c].cplusplus << ' ' << ans[c].calculus << endl;
    }
    cout << "C_min:" << cppmin << endl;
    cout << "Calculus_average:" << caltot / n << endl;
    cout << "Calculus_max:" << calmax << endl;
    //sort(ans, ans + n, cmpcal);
    for (int i = 0; i < calindex.size(); i++)
    {
        int c = calindex[i];
        //lisi 1 19920202 1.56 89 88
        cout << ans[c].name << ' ' << ans[c].sex << ' ' << ans[c].birthday << ' ';
        printf("%.2f", ans[c].height);
        cout << ' ' << ans[c].cplusplus << ' ' << ans[c].calculus << endl;
    }
    cout << "Calculus_min:" << calmin << endl;
}