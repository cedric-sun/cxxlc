#include <stdio.h>
int main()
{
    int i,k,zhishu=0;
    double zhengshu=1;
    while (scanf("%d",&k)!=EOF)
    {
zhishu=0;
zhengshu=1;

    for (i=0;i<k;i++)
    {
        if (zhengshu/2<1)
        {
            zhengshu*=5;
            zhishu+=1;
        }
        else
        {
           zhengshu/=2;
        }

    }
    printf("2^-%d = %.3fe-%d\n",k,zhengshu,zhishu);
    }

    return 0;

}
