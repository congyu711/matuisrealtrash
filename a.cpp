#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

typedef struct student
{
	int id;
	string name;
	float chinese;
	float math;
	float english;
	float sum;
} student;
int cmp(const student &a, const student &b)
{
	return a.sum > b.sum;
}

/*输入参数：字符串name是要打开的文件名称。输出参数：stu是读出的学生的详细信息。函数的返回值：学生人数.任何错误返回0*/
int ReadStuInfoFromFile(char *name, student **stu)
{
	ifstream infile;
	infile.open(name);
	int num;
	infile >> num;
	student *a = (student *)malloc(num * (sizeof(student)));
	*stu = a;

	for (int i = 0; i < num; i++)
	{
		infile >> a[i].id >> a[i].name >> a[i].chinese >> a[i].math >> a[i].english;
		a[i].sum = a[i].chinese + a[i].english + a[i].math;
	}

	return num;
}

/*输入参数：stu是全班学生信息，n是人数。输出参数：3科平均成绩不及格人名单noPassStudent,不及格人数m.操作成功返回0，失败返回-1*/
int NoPass(student stu[], int n, student **noPassStudent, int *m)
{
	if (stu == NULL || n < 1)
		return -1;
	//int tmp = 0;
	student *a = (student *)malloc(n * sizeof(student));
	*noPassStudent = a;
	*m = 0;
	for (int i = 0; i < n; i++)
	{
		double ans = static_cast<double>(stu[i].sum) / 3.0;
		if (ans < 60.0)
		{
			noPassStudent[(*m)] = &stu[i];
			*m = *m + 1;
		}
	}
	//m = &tmp;
	return 0;
}

/*输入参数：stu是全班学生信息，n是人数。输出参数：3科平均成绩及格人名单PassStudent,及格人数m.操作成功返回0，失败返回-1*/
int Pass(student stu[], int n, student **PassStudent, int *m)
{
	if (stu == NULL || n < 1)
		return -1;
	//int tmp = 0;
	student *a = (student *)malloc(n * sizeof(student));
	*PassStudent = a;
	*m = 0;
	for (int i = 0; i < n; i++)
	{
		double ans = static_cast<double>(stu[i].sum) / 3.0;
		if (ans >= 60.0)
		{
			PassStudent[*m] = &stu[i];
			*m = *m + 1;
		}
	}
	//m = &tmp;
	return 0;
}

/*输入参数：stu是全班学生信息，n是人数。输出参数：按照总分/平均分排序后的结果也存储在stu中.操作成功返回0，失败返回-1*/
// int SortStudents(student stu[], int n)
// {
// 	if (stu == NULL || n < 1)
// 		return -1;
// 	sort(stu, stu + n, cmp);
// 	return 0;
// }
int SortStudents(student stu[], int n)
{
    if (stu == NULL || n < 1)
    {
        return -1;
    }
    else
    {
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - i - 1; j++)
                if (stu[j].sum < stu[j + 1].sum)
                {
                    student t = stu[j];
                    stu[j] = stu[j + 1];
                    stu[j + 1] = t;
                }
        return 0;
    }
}
/*输入参数：stu是全班学生信息，n是人数,id是待查找的学号。输出参数：rank是在班上的排名；stu是这个学生的详细信息。返回值：查找成功返回0，失败返回-1*/
int SearchStudent(student stu[], int n, int id, int *rank, student *rstu)
{
	if (n < 1 || stu == NULL)
		return -1;
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (stu[i].id == id)
			{
				*rank = i + 1;
				*rstu = stu[i];
				//rank = &_rank;
			}
		}
		return 0;
	}
}
// 文件名称：char name[]= "stuScores.txt";作为测试使用，不需要提交。
// 注意：第一个函数要求从文件name中读取数据，文件内容：
// 第一个数据是学生人数n；后面的数据是n个学生的详细信息，需要用fread依次读出人数及n个人的信息数据。读出的成绩数据并没有进行累加求和，需要您自己计算。

// 该题目的测试只针对函数，不需要在控制台输出。请务必保证函数实现正确，后台将会提供数据文件对函数进行测试。
// 自己写主函数测试建议如下：
void print(student **stu, int cnt)
{
	for (int i = 0; i < cnt; i++)
	{
		cout << stu[i]->id << ' ' << stu[i]->name << ' ' << stu[i]->chinese << ' ' << stu[i]->math << ' ' << stu[i]->english << endl;
	}
}
int main()
{
	// int n, rank, id, i, m;
	// char name[] = "stuScores.txt";
	// student *stu = NULL, *noPassStu = NULL, *passStu = NULL, rstu;
	// n = ReadStuInfoFromFile(name, &stu);
	// if (n == 0)
	// {
	// 	printf("error");
	// 	return -1;
	// }
	// PrintStudents(stu, n);

	// printf("\n no pass studnt--------\n");
	// i = NoPass(stu, n, &noPassStu, &m);
	// if (i == -1)
	// 	printf("no pass error");
	// else
	// 	PrintStudents(noPassStu, m);

	// printf("\n  passed studnt--------\n");
	// i = Pass(stu, n, &noPassStu, &m);
	// if (i == -1)
	// 	printf(" pass error");
	// else
	// 	PrintStudents(noPassStu, m);

	// printf("\n sort studnt--------\n");
	// //i = NoPass(stu, n, &noPassStu, &m);
	// i = SortStudents(stu, n);
	// if (i == -1)
	// 	printf("sort error");
	// else
	// 	PrintStudents(stu, n);

	// printf("\n search id--------\n");
	// //i = NoPass(stu, n, &noPassStu, &m);
	// scanf_s("%d", &id);
	// i = SearchStudent(stu, n, id, &rank, &rstu);
	// if (i == -1)
	// 	printf("search error");
	// else
	// 	PrintStudents(&rstu, 1);
	// if (stu)
	// {
	// 	free(stu);
	// 	stu = NULL;
	// }
	// if (noPassStu)
	// {
	// 	free(noPassStu);
	// 	noPassStu = NULL;
	// }
	// if (PassStu)
	// {
	// 	free(PassStu);
	// 	PassStu = NULL;
	// }
	// system("pause");
	// return 0;
}