#include <iostream>
// #include <cstring>
// #include <string>
// #include <cmath>
// #include <iomanip>
// #include <vector>
using namespace std;

struct Person
{

    int no;
    int age;
    int height;
};
int cmp(const Person &a, const Person &b)
{
    if (a.no == b.no)
    {
        if (a.age == b.age)
            return a.height > b.height;
        else
            return a.age > b.age;
    }
    else
        return a.no > b.no;
}
void sort(Person *array, int n)
{
    if (n < 1||array==NULL)
    {
        cout << "error";
        return;
    }
    // stable_sort(array, array + n, cmp);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
            if (cmp(array[j], array[j + 1]))
            {
                Person aa = array[j];
                array[j] = array[j + 1];
                array[j + 1] = aa;
            }
    }
}
// int main()
// {
//     Person array[200];
//     array[0].age = 2;
//     array[0].height = 1;
//     array[0].no = 1;
//     array[1].age = 1;
//     array[1].height = 1;
//     array[1].no = 1;
//     sort(array, 2);
//     cout << array[0].age;
// }