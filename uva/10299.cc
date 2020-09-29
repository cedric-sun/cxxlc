#include <cstdio>
#include <cmath>
#include <cstring>

const int N=sqrt(1000000000);
int p,prime[N];
bool isprime[N+5];

void init()
{
    memset(isprime,1,sizeof isprime);
    p=0;
    for (int i=2; i<=N; i++)
    {
        if (isprime[i]) prime[p++]=i;
        for (int j=0,tmp; j<p && (tmp=i*prime[j])<=N; j++)
        {
            isprime[tmp]=0;
            if (!(i%prime[j])) break;
        }
    }
}

int main()
{
    init();
    int n;
    while (scanf("%d",&n),n)
    {
        long long ans=n;
        if (n!=1)
        {
            for (int i=0; i<p; i++)
            {
                if (!(n%prime[i]))
                {
                    ans=ans/prime[i]*(prime[i]-1);
                    while (!(n%prime[i])) n/=prime[i];
                    if (n==1) break;
                }
            }
            if (n!=1) ans=ans/n*(n-1);
        }
        else
            ans=0;
        printf("%lld\n",ans);
    }
    return 0;
}
