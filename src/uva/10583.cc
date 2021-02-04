#include <cstdio>
#include <set>
using std::set;

int f[50005];
int uf(int x)
{
    if (f[x]!=x) f[x]=uf(f[x]);
    return f[x];
}

int main()
{
    int i,n,m,a,b,cnt=1;
    set<int> t;
    while (scanf("%d %d",&n,&m),n)
    {
        t.clear();
        for (i=1;i<=n;i++) f[i]=i;
        for (i=0;i<m;i++)
        {
            scanf("%d %d",&a,&b);
            a=uf(a);b=uf(b);
            f[a]=b;
        }
        for (i=1;i<=n;i++) t.insert(uf(i));

        printf("Case %d: %d\n",cnt++,t.size());
    }
    return 0;
}
