#include <stdio.h>
int main()
{
    int n,m,i;
    double result;
    while (scanf("%d %d",&n,&m)!=EOF&&n!=0&&m!=0)
    {
        result=1;
        for (i=0;i<n-m;i++)
            result*=(n-i)*1.0/(n-m-i);
        printf("%d things taken %d at a time is %.0lf exactly.\n",n,m,result);
    }
    return 0;
}
