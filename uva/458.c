#include <stdio.h>
#include <string.h>
int main()
{
    int length,i;
    char str[10086];
    while (~scanf("%s",str))
    {
        length=strlen(str);
        for (i=0;i<length;i++)
            printf("%c",str[i]+'*'-'1');
        printf("\n");
    }
    return 0;
}
