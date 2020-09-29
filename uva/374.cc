#include <cstdio>
typedef long long ll;
ll modmul(ll a,ll b,ll n)
{
    ll ans=0;
    while (b)
    {
        if (b&1) ans=(ans+a)%n;
        a=(a+a)%n;
        b>>=1;
    }
    return ans;
}

ll modexp(ll a,ll b,ll n)
{
    ll ans=1;
    while (b)
    {
        if (b&1) ans=modmul(ans,a,n);
        a=modmul(a,a,n);
        b>>=1;
    }
    return ans;
}

int main()
{
    ll b,p,m;
    while (~scanf("%lld %lld %lld",&b,&p,&m))
    {
        printf("%lld\n",modexp(b,p,m));
    }
    return 0;
}
