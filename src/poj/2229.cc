#include <cstdio>
int n;
int f[1000005];
int main()
{
    scanf("%d",&n);
    f[1]=1;
    f[2]=2;
    for (int i=3; i<=n; i++)
    {
        if (i&1) f[i]=f[i-1];
        else
        {
            f[i]=f[i-2]+f[i/2];
            f[i]%=1000000000;
        }
    }
    printf("%d\n",f[n]);
    return 0;
}
