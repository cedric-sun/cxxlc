#include <stdio.h>
#include <string.h>
int ans[10005][10];
void calc()
{
    int i,temp;
    for (i=1;i<=10000;i++)
    {
        memcpy(ans[i],ans[i-1],sizeof(ans[0]));
        temp=i;
        while (temp!=0)
        {
            ans[i][temp%10]++;
            temp/=10;
        }
    }
}
int main()
{
    int i,cases,N;
    scanf("%d",&cases);
    calc();
    while (cases--)
    {
        scanf("%d",&N);
        for (i=0;i<=9;i++)
        {
            if (i) putchar(' ');
            printf("%d",ans[N][i]);
        }
        putchar('\n');
    }
    return 0;
}
