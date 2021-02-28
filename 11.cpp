#include <string>
#include <iostream>
using namespace std;
int main()
{
    string a;
    cin >> a;
    for (int i = 0; i < a.length(); i++)
    {
        int c = static_cast<int>(a[i]);
        if (c < 65 || c > 122 || (c > 90 && c < 97))
        {
            cout << "error";
            exit(0);
        }
    }
    for (int i = 0; i < a.length(); i++)
    {
        int c = static_cast<int>(a[i]);
        c += 4;
        if ((c > 90 && c < 97) || c > 122)
            c -= 26;
        a[i] = static_cast<char>(c);
    }
    cout << a;
}