#include <cstdio>
#include <algorithm>
#include <cstring>
using std::max;
int strikefreedom[30005],sum[30005];

int uf(int x)
{
    if (strikefreedom[x]!=x) strikefreedom[x]=uf(strikefreedom[x]);
    return strikefreedom[x];
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        memset(sum,0,(n+1)*sizeof(int));
        for (int i=1;i<=n;i++) strikefreedom[i]=i;
        for (int i=0;i<m;i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            a=uf(a);b=uf(b);
            strikefreedom[a]=b;
        }

        for (int i=1;i<=n;i++)
            sum[uf(i)]++;

        int ans=0;

        for (int i=1;i<=n;i++)
            ans=max(ans,sum[i]);

        printf("%d\n",ans);
    }
}
