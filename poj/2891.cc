#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

void exgcd(ll a,ll b,ll &gcd,ll &x,ll &y)//ax+by=gcd
{
    if(!b)
    {
        gcd=a;
        x=1;
        y=0;
        return;
    }
    exgcd(b,a%b,gcd,y,x);
    y-=x*(a/b);
}

/* solve mod equation set:

        X mod m[0]=r[0]
        X mod m[1]=r[1]
        ......
        X mod m[n-1]=r[n-1]

which elements of m[] aren't relatively prime
return minimum X
*/

ll excrt(vll &m, vll &r, int n)
{
    ll M = m[0], R = r[0], x, y, gcd;
    for (int i = 1; i < n; ++i)
    {
        exgcd(M, m[i], gcd, x, y);
        if ((r[i] - R) % gcd) return -1;
        x = (r[i] - R) / gcd * x % (m[i] / gcd);
        R += x * M;
        M = M / gcd * m[i];
        R %= M;
    }
    return R > 0 ? R : R + M;
}

int main()
{
    int n;
    while (~scanf("%d",&n))
    {
        vll m,r;
        for (int i=0; i<n; i++)
        {
            ll tm,tr;
            scanf("%I64d %I64d",&tm,&tr);
            m.push_back(tm);
            r.push_back(tr);
        }
        printf("%I64d\n",excrt(m,r,n));
    }
    return 0;
}
