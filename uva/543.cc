#include <cstdio>
#include <cstring>

const int N=1000000;

int p,prime[N];
bool isprime[N+5];

int bs(int x)
{
    int l=0,r=p-1,m;
    while (l<r)
    {
        m=(l+r)>>1;
        if (prime[m]>x) r=m;
        else l=m+1;
    }
    return l-1;
}

void init()
{
    memset(isprime,1,sizeof isprime);
    p=0;
    isprime[1]=0;
    for (int i=2;i<=1000;i++)
        if (isprime[i])
            for (int j=2;j*i<=N;j++) isprime[i*j]=0;

    for (int i=2;i<=N;i++)
        if (isprime[i])
            prime[p++]=i;
}

int calc(int n)
{
    for (int j=bs(n);j>=0;j--)
            if (isprime[n-prime[j]]) return prime[j];
}

int main()
{
    int n,ans;
    init();
    while (scanf("%d",&n),n)
        printf("%d = %d + %d\n",n,n-(ans=calc(n)),ans);
    return 0;
}
