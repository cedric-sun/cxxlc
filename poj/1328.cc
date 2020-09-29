#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
struct point
{
    double l,r;
    bool operator < (const point &ref) const
    {
        if (r==ref.r) return l>ref.l;
        return r<ref.r;
    }
} a[1005];
int n,d;

int solve()
{
    sort(a,a+n);
    int ans=0;
    double p=-1e300;
    for (int i=0;i<n;i++)
    {
        if (a[i].l>p)
        {p=a[i].r;ans++;}
    }
    return ans;
}
int main()
{
    int cnt=1;
    while (scanf("%d %d",&n,&d),n)
    {
        bool flag=0;
        for (int i=0; i<n; i++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            if (y>d) flag=1;
            if (!flag)
            {
                double r=sqrt(d*d*1.0-y*y*1.0);
                a[i].l=x-r;
                a[i].r=x+r;
            }
        }

        printf("Case %d: %d\n",cnt++,flag?-1:solve());
    }
    return 0;
}

