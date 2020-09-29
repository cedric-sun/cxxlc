#include <cstdio>
#include <queue>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    while (~scanf("%d",&n))
    {
        priority_queue<ll,vector<ll>,greater<ll> > q;
        for (int i=0;i<n;i++)
        {
            ll a;
            scanf("%lld",&a);
            q.push(a);
        }

        ll ans=0;
        while (q.size()>1)
        {
            ll a=q.top();q.pop();
            ll b=q.top();q.pop();
            ans+=a+b;
            q.push(a+b);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
