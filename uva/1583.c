#include <stdio.h>
#include <string.h>
int list[100005];
void calc()
{
    int i,j,k;
    memset(list,0,sizeof(list));
    for (i=1; i<=100000; i++)
    {
        k=j=i;
        while (j!=0)
        {
            k+=j%10;
            j/=10;
        }
        if (!list[k])
        list[k]=i;
    }
}
int main()
{
    calc();
    int cases,i;
    scanf("%d",&cases);
    while (cases--)
    {
        scanf("%d",&i);
        printf("%d\n",list[i]);
    }
    return 0;
}
