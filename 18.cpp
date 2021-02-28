#include <iostream>
#include <cmath>
using namespace std;
int n;
int main()
{
    cin >> n;
    if (n < 3)
    {
        cout << "error";
        exit(0);
    }
    int sqn = sqrt((float)n);
    for (int i = 2; i < sqn; i++)
    {
        if (n % i == 0)
        {
            cout << "no";
            exit(0);
        }
    }
    cout << "yes";
}