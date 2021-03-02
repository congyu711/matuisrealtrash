#include <iostream>

using namespace std;

int find(int n)
{
    if (n < 100 || n > 999)
        return 0;
    int ans = 0;
    for (int i = 101; i <= n; i++)
    {
        int c = 0;
        c += (i / 100) * (i / 100) * (i / 100);
        c += ((i % 100) / 10) * ((i % 100) / 10) * ((i % 100) / 10);
        c += (i % 10) * (i % 10) * (i % 10);
        // cout<<c<<endl;
        if(c==i)    ans++;
    }
    return ans;
}
int main()
{
    cout << find(949);
}