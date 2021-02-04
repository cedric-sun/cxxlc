#include <cstdio>
#include <algorithm>
using namespace std;
struct deno
{
    int v,num;
    bool operator < (const deno &ref) const
    {
        return v>ref.v;
    }
} a[21];
int main()
{
    int n,c;
    scanf("%d %d",&n,&c);
    for (int i=0; i<n; i++)
        scanf("%d %d",&a[i].v,&a[i].num);
    sort(a,a+n);
    int p,ans=0;
    for (p=0; a[p].v>=c && p<n; p++)
        ans+=a[p].num,a[p].num=0;
    while (1)
    {
        int tmp=c;
        for (int tp=p; tp<n; tp++)
        {
            if (tmp==0) break;
            if (a[tp].num>0)
            {
                int maxavail=min(a[tp].num,tmp/a[tp].v);
                if (maxavail>0)
                {
                    tmp-=maxavail*a[tp].v;
                    a[tp].num-=maxavail;
                }
            }
        }

        if (tmp>0)
            for (int i=n-1; i>=p; i--)
                if (a[i].num)
                {
                    tmp-=a[i].v;
                    a[i].num--;
                    break;
                }

        if (tmp<=0) ans++;
        else break;
    }
    printf("%d\n",ans);
    return 0;
}
