#include <stdio.h>
const char kb[]="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
int main()
{
    int i,flag;
    char a;
    while ((a=getchar())!=EOF)
    {
        flag=0;
        for (i=0;i<sizeof(kb);i++)
            if (a==kb[i])
            {
                flag=1;

                break;
            }
            if (flag)
            putchar(kb[i-1]);
            else
            putchar(a);
    }
    return 0;
}
