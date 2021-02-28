#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
    double n, x;
    cin >> x >> n;
    cout << setiosflags(ios::fixed) << setprecision(6);

    if (n < 0)
    {
        cout << "error";
        exit(0);
    }
    double ans = 1, factorial = 1, powern = x;
    for (int i = 1; i <= n; i++)
    {
        factorial *= (double)i;

        ans += powern / factorial;

        powern *= x;
    }
    cout << ans;
}