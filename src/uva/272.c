#include <stdio.h>
int main()
{
    char a,sig='L';
    while ((a=getchar())!=EOF)
    {
        if (a==34)
        {
            if (sig=='L')
            {
                printf("``");
                sig='R';
            }
            else
            {
                printf("''");
                sig='L';
            }
        }
        else
            putchar(a);
    }
    return 0;
}
