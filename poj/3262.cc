#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

struct cow
{
    int t,d;
    bool operator < (const cow &ref) const {return 1.0*t/d>1.0*ref.t/ref.d;}
}a[100005];
ll sum[100005];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d %d",&a[i].t,&a[i].d);
    sort(a,a+n);
    sum[0]=0;
    for (int i=1;i<n;i++)
        sum[i]=sum[i-1]+a[i-1].d;
    ll ans=0;
    for (int i=n-1;i>=0;i--)
        ans+=2*a[i].t*sum[i];
    printf("%lld\n",ans);
    return 0;
}

