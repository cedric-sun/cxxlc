#include <stdio.h>
#include <string.h>
char str[105];
int less_by_dic(int a,int b)
{
    int i,n=strlen(str);
    for (i=0;i<n;i++)
        if (str[(i+a)%n]!=str[(i+b)%n])
            return str[(i+a)%n]<str[(i+b)%n];
    return 0;
}
int main()
{
    int cases,a,i,n;
    scanf("%d",&cases);
    while (cases--)
    {
        a=0;
        scanf("%s",str);
        n=strlen(str);
        for (i=1;i<n;i++)
            if (less_by_dic(i,a))
                a=i;
        for (i=0;i<n;i++)
            putchar(str[(a+i)%n]);
        putchar('\n');
    }
    return 0;
}
