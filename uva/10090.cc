#include <cstdio>
#include <cmath>

using namespace std;

typedef long long ll;
ll n,c1,n1,c2,n2;
ll x,y,gcd;

void exgcd(ll a,ll b)
{
    if (!b) {x=1;y=0;gcd=a;return;}
    exgcd(b,a%b);
    ll tmp=x;
    x=y;
    y=tmp-a/b*y;
    return;
}

int main()
{
    while (scanf("%lld",&n),n)
    {
        scanf("%lld %lld %lld %lld",&c1,&n1,&c2,&n2);
        exgcd(n1,n2);
        if (n%gcd) printf("failed\n");
        else
        {
            ll lb=ceil(-1.0*x*n/n2),ub=floor(1.0*y*n/n1);
            if (lb>ub) {printf("failed\n");continue;}
            ll t;
            if (c1*n2-c2*n1>=0) t=lb;
            else t=ub;
            printf("%lld %lld\n",(x*n+n2*t)/gcd,(y*n-n1*t)/gcd);
        }
    }
    return 0;
}
