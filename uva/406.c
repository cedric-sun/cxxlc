#include <stdio.h>
int ifss(int a);
void tqss(int n,int *arr);
int main()
{
    int n,c,ssofn[200]={1,2,3},i,j;
    while (scanf("%d %d",&n,&c)!=EOF)
    {
        for (i=3;i<168;i++)
            ssofn[i]=0;
        tqss(n,ssofn);
        i=0;
        while (ssofn[i]!=0)
            i++;
        if (i%2!=0)
        {
            printf("%d %d:",n,c);
            if (2*c-1>i)
                for (j=0;j<i;j++)
                printf(" %d",ssofn[j]);
            else
                for (j=(i-1)/2-c+1;j<=(i-1)/2+c-1;j++)
                printf(" %d",ssofn[j]);
        }
        else
        {
            printf("%d %d:",n,c);
            if (2*c>i)
                for (j=0;j<i;j++)
                printf(" %d",ssofn[j]);
            else
                for (j=i/2-c;j<=i/2+c-1;j++)
                printf(" %d",ssofn[j]);
        }
        printf("\n");
    }
    return 0;
}
int ifss(int a)
{
    int i;
    if (a==2||a==3)
        return 1;
    for (i=3;i<a;i++)
        if (a%i==0)
        return 0;
    return 1;
}
void tqss(int n,int *arr)
{
    int i,k=3;
    for (i=5;i<=n;i++)
        if (ifss(i))
        arr[k++]=i;
}
