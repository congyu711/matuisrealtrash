#include <iostream>
#include <cstring>
#include <string>
using namespace std;
void my_strcpy(char *destination, char *source)
{
    int cnt = 0;
    int sn = 0, dn = 0;
    // while (destination[dn++] != '\0')
    //     ;
    // while (source[sn++] != '\0')
    //     ;
    // if (sn > dn)
    // {
    //     printf("error");
    //     return;
    // }

    while (source[cnt] != '\0')
    {
        destination[cnt] = source[cnt];
        cnt++;
    }
}

// int main()
// {
//     char a[] = "dddddddd d ";
//     char b[] = "ccccccccccccccccccccc";
//     my_strcpy(b, a);
//     for (int i = 1; b[i] != '\0'; i++)
//         cout << b[i];
// }