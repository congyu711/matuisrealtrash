#include <iostream>
#include <cstring>
#include <string>
using namespace std;
void my_strcpy(char *destination, char *source)
{
    if (destination == NULL || source == NULL||destination==source||source[0]=='\0')
    {
        cout << "error";
        return;
    }
    if (sizeof(destination) / sizeof(*destination) < sizeof(source) / sizeof(*source))
    {
        cout << "error";
        return;
    }
    int cnt = 0;

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