//bubble sort
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[20];
void _swap(int x, int y)
{
    arr[x] = arr[x] ^ arr[y];
    arr[y] = arr[x] ^ arr[y];
    arr[x] = arr[x] ^ arr[y];
}
int main()
{
    for (int i = 1; i <= 10; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j < 11 - i; j++)
            if (arr[j] > arr[j + 1])
                _swap(j, j + 1);
    }
    for (int i = 1; i <= 9; i++)
    {
        cout << arr[i] << ',';
    }
    cout << arr[10];
}