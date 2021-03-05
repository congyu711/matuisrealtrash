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

using namespace std;
int caltot, calmax, cppmax, cpptot;
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
int cmpcal(const stu &a, const stu &b)
{
    return a.calculus > b.calculus;
}
int cmpcpp(const stu &a, const stu &b)
{
    return a.cplusplus > b.cplusplus;
}
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
    }
    for (int i = 0; i < n; i++)
    {
        caltot += ans[i].calculus;
        cpptot += ans[i].cplusplus;
        calmax = max(calmax, ans[i].calculus);
        cppmax = max(cppmax, ans[i].cplusplus);
    }
    sort(ans, ans + n, cmpcpp);
    cout << "C_average:" << cpptot / n << endl;
    cout << "C_max:" << cppmax << endl;
    for (int i = 0; i < n && ans[i].cplusplus == ans[0].cplusplus; i++)
    {
        //lisi 1 19920202 1.56 89 88
        cout << ans[i].name << ' ' << ans[i].sex << ' ' << ans[i].birthday << ' ';
        printf("%.2f", ans[i].height);
        cout << ' ' << ans[i].cplusplus << ' ' << ans[i].calculus << endl;
    }
    cout << "C_min:" << ans[n - 1].cplusplus << endl;
    cout << "Calculus_average:" << caltot / n << endl;
    cout << "Calculus_max:" << calmax << endl;
    sort(ans, ans + n, cmpcal);
    for (int i = 0; i < n && ans[i].calculus == ans[0].calculus; i++)
    {
        //lisi 1 19920202 1.56 89 88
        cout << ans[i].name << ' ' << ans[i].sex << ' ' << ans[i].birthday << ' ';
        printf("%.2f", ans[i].height);
        cout << ' ' << ans[i].cplusplus << ' ' << ans[i].calculus << endl;
    }
    cout << "Calculus_min:" << ans[n - 1].calculus << endl;
}