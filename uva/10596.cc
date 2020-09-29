#include <cstdio>
#include <cstring>

int n,r;
int f[205],deg[205];

int uf(int x)
{
    return x==f[x]?x:f[x]=uf(f[x]);
}
bool solve()
{
    int cnt=0;
    for (int i=0;i<n;i++)
    {
        if (deg[i]&1) return 0;
        if (f[i]==i) cnt++;
    }
    if (cnt!=1) return 0;
    return 1;
}
int main()
{
    while (~scanf("%d %d",&n,&r))
    {
        for (int i=0;i<n;i++) f[i]=i;
        memset(deg,0,sizeof deg);
        for (int i=0;i<r;i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            deg[a]++;deg[b]++;
            a=uf(a),b=uf(b);
            if (a!=b)
                f[a]=b;
        }
        if ((!r)||(n==1)||solve())
            printf("Possible\n");
        else
            printf("Not Possible\n");
    }
    return 0;
}
