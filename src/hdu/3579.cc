#include <cstdio>

typedef int ll;

void exgcd(ll a,ll b,ll &gcd,ll &x,ll &y)//ax+by=gcd
{
	if(!b){gcd=a;x=1;y=0;return;}
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

ll excrt(ll *m, ll *r, int n)
{
    ll M = m[0], R = r[0], x, y, d;
    for (int i = 1; i < n; ++i)
    {
        exgcd(M, m[i], d, x, y);
        if ((r[i] - R) % d) return -1;
        x = (r[i] - R) / d * x % (m[i] / d);
        R += x * M;
        M = M / d * m[i];
        R %= M;
    }
    return R > 0 ? R : R + M;
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int c=1;c<=T;c++)
    {
        int n,mi[10],ai[10];
        scanf("%d",&n);
        for (int i=0;i<n;i++) scanf("%d",mi+i);
        for (int i=0;i<n;i++) scanf("%d",ai+i);
        printf("Case %d: %d\n",c,excrt(mi,ai,n));
    }
    return 0;
}
