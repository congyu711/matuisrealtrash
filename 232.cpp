#include <iostream>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;
string a;
char ch[200010];
int cnt = 0;
int main()
{

    cin >> a;

    //cout<<a.length()<<endl;
    for (int i = 0; i < a.length(); i++)
    {
        //cout<<'1'<<endl;
        if ((i % 2) == 1 && (i != a.length()-1))
        {
            ch[cnt++] = a[i];
            ch[cnt++] = '*';
        }
        else
            ch[cnt++] = a[i];
    }
    int n = strlen(ch);
    // cout<<"                 "<<n<<endl;
    for (int i = 0; i < n; i++)
        cout << ch[i];
    cout << endl;
}