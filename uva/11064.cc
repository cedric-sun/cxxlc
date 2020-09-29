#include <cstdio>
#include <cstring>
#include <cmath>

typedef long long ll;

const int N=sqrt(0x7fffffff)+1;

int p,prime[N];
bool isprime[N+5];

void init()
{
    memset(isprime,1,sizeof isprime);
    p=0;
    for (int i=2;i<=N;i++)
    {
        if (isprime[i]) prime[p++]=i;
        for (int j=0,tmp;j<p && (tmp=i*prime[j])<=N;j++)
        {
            isprime[tmp]=0;
            if (!(i%prime[j])) break;
        }
    }
}

int main()
{
    init();
    ll n;
    while (~scanf("%lld",&n))
    {
        ll Rf=n,fn=1,ans=n;
        for (int i=0;i<p;i++)
        {
            if (!(n%prime[i]))
            {
                int cnt=0;
                Rf=Rf/prime[i]*(prime[i]-1);
                while (!(n%prime[i])) {n/=prime[i];++cnt;}
                fn*=(cnt+1);
                if (n==1) break;
            }
        }
        if (n!=1)
        {
            Rf=Rf/n*(n-1);
            fn<<=1;
        }

        ans=ans-Rf-fn+1; //Rf和fn中重复计算了1

        printf("%lld\n",ans);
    }
    return 0;
}
