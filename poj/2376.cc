#include <cstdio>
#include <algorithm>
using namespace std;

struct interval
{
    int s,e;
    bool operator < (const interval &ref) const
    {
        if (s==ref.s)
            return e<ref.e;
        else
            return s<ref.s;
    }
} a[1000005];

int n,T;
int solve()
{
    sort(a,a+n);
    a[n].s=0x7FFFFFFF;
    int ans=0,tmp=0,t=0;
    bool flag=0;
    for (int i=0; i<n; i++)
        if (a[i].s<=t+1)
        {
            if (a[i].e>tmp)
            {
                tmp=a[i].e;
                flag=1;
            }
            if (a[i+1].s>t+1 && flag)
            {
                t=tmp;
                ans++;
                flag=0;
            }
        }
    return t<T?-1:ans;
}
int main()
{
    while (~scanf("%d %d",&n,&T))
    {
        for (int i=0; i<n; i++)
            scanf("%d %d",&a[i].s,&a[i].e);
        printf("%d\n",solve());
    }
    return 0;
}
