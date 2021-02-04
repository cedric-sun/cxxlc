#include <cstdio>


const int N=1000000;
int p;
long long m[N],f[N];

void updateto(int n)
{
    for (int i=p+1;i<=n;i++)
    {
        m[i]=m[i-1]+m[i-2]+1;
        f[i]=m[i-1]+1;
    }
    p=n;
}

int main()
{
    int n;
    p=1;
    m[0]=0,m[1]=f[0]=f[1]=1;
    while (scanf("%d",&n),~n)
    {
        if (n>p) updateto(n);
        printf("%lld %lld\n",m[n],m[n]+f[n]);
    }
    return 0;
}
