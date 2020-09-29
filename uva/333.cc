#include <cstring>
#include <cstdio>
using namespace std;
char buf[101];
int  save[11];
int main()
{
    while (gets(buf))
    {
        int a = 0,b = strlen(buf)-1;
        while (buf[a] == ' ') a ++;
        while (buf[b] == ' ') buf[b --] = 0;
        int flag = 0,count = 0;
        for (int i = a ; buf[i] ; ++ i)
        {
            if ((buf[i] >= '0' && buf[i] <= '9')||(buf[i] == 'X' && count == 9))
                save[count ++] = buf[i]=='X'?10:buf[i]-'0';
            else if (buf[i] != '-')
            {
                flag = 1;
                break;
            }
            if (count > 10)
            {
                flag = 1;
                break;
            }
        }
        if (count != 10) flag = 1;
        for (int i = 1 ; i < 10 ; ++ i)
            save[i] += save[i-1];
        for (int i = 1 ; i < 10 ; ++ i)
            save[i] += save[i-1];
        if (save[9]%11) flag = 1;
        printf("%s is ",&buf[a]);
        if (flag)
            printf("incorrect.\n");
        else printf("correct.\n");
    }
    return 0;
}

