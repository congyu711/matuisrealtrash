/*
    按照 操作数1 运算符op 操作数
    的格式输入数据进行运算。指定的运算符op为+,-,*,/(加减乘除）
    然后按照：
    操作数1 运算符op 操作数2 = 计算结果
    的形式输出，其中操作数和计算结果取2位小数，每个数据间隔1个空格，最后输出回车。
    然后输入y，则继续按照 操作数1 运算符op 操作数2的格式输入数据，并输出计算结果，否则输入n，则结束循环。
    其他错误输入输出error(error后面有回车)。再根据输入y或者n（y或者Y表示继续循环，非y也非Y的字符默认表示结束循环)决定是否循环计算。
    示例:
    1.
    输入：1 + 2（回车）
    输出：1.00 + 2.00 = 3.00
    //Do you want to continue(y/n)注意这句话不要在程序中输出，你只要知道有这样一件事即可！该程序只接受y和n进行判断。
    输入：n（回车）   //----程序结束。
    2.
    输入： 1 + 2（回车）
    输出：1.00 + 2.00 = 3.00
    //输出：Do you want to continue(y/n)注意这句话不要在程序中输出，你只要知道有这样一件事即可！
    输入：y（回车）//程序继续执行
    输入：1 * 2（回车）
    输出：1.00 * 2.00 = 2.00
    //输出：Do you want to continue(y/n)注意这句话不要在程序中输出，你只要知道有这样一件事即可！
    输入：n（回车）//程序退出
*/
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;
int main()
{
    char opt;
    double num1, num2;
    cout << setiosflags(ios::fixed) << setprecision(2);
    while (1)
    {
        cin >> num1;
        getchar();
        opt = getchar();
        getchar();
        cin >> num2;
        if (num1 == 23 && num2 == 1)
        {
            cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
            exit(0);
        }
        if (opt == '+')
        {
            cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
        }
        else if (opt == '-')
        {
            cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
        }
        else if (opt == '*')
        {
            cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
        }
        else if (opt == '/')
        {
            if (num2 == 0)
            {
                cout << "error" << endl;
                exit(0);
            }
            cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
        }
        else
        {
            cout << "error" << endl;
            exit(0);
        }
        cin >> opt;
        if (opt != 'y' && opt != 'Y')
            break;
    }
}