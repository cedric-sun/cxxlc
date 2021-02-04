#include <stdio.h>
#include <string.h>
char str[1000];
int ifslump(int a,int b)
{
    int i;
    if (str[a]!='D'&&str[a]!='E')
        return 0;
    if (str[b]!='G')
        return 0;
    if (str[a+1]!='F')
        return 0;
    for (i=a+2; i<b; i++)
    {
        if (str[i]!='F')
        {
            if (ifslump(i,b))
                return 1;
            else
                return 0;
        }
    }
    return 1;
}
int ifslimp(int a,int b)
{
    if (str[a]!='A')
        return 0;
    if (b-a==1)
    {
        if (str[b]=='H')
        return 1;
        else
        return 0;
    }
    else
    {
        if (str[b]!='C') return 0;
        if (str[a+1]=='B')
        {
            if (ifslimp(a+2,b-1)) return 1;
            else return 0;
        }
        else
        {
            if (ifslump(a+1,b-1))
                return 1;
            else
                return 0;
        }
    }
}
int ifslurpy()
{
    int i,length=strlen(str);
    for (i=0; i<length; i++)
    {
        if ((str[i]=='C'||str[i]=='H')&&(str[i+1]=='D'||str[i+1]=='E'))
        {
            if (ifslimp(0,i)&&ifslump(i+1,length-1))
                return 1;
            else
                return 0;
        }
    }
    return 0;
}
int main()
{
    int i;
    scanf("%d",&i);
    printf("SLURPYS OUTPUT\n");
    while (i--)
    {
        scanf("%s",str);
        printf("%s\n",ifslurpy()?"YES":"NO");
    }
    printf("END OF OUTPUT\n");
    return 0;
}
