#include <cstdio>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
map<string,int> s;
int f[200+5],n,r,id;
struct edge
{
    int u,v,w;
    bool operator < (edge & ref) {return w>ref.w;}
}e[19900+5];

int uf(int x)
{
    return f[x]==x?x:f[x]=uf(f[x]);
}
int findid(char *a)
{
    if (!s.count(a))
        s[a]=id++;
    return s[a];
}
int solve()
{
    char sr[35],ds[35];
    scanf("%s %s",sr,ds);
    int src=findid(sr),dst=findid(ds);
    for (int i=0;i<r;i++)
    {
        int u=uf(e[i].u),v=uf(e[i].v);
        if (u!=v) f[u]=v;
        if (uf(src)==uf(dst))
            return e[i].w;
    }
    return -1;
}
int main()
{
    int cnt=0;
    while (scanf("%d %d",&n,&r),n||r)
    {
        id=0;
        char tmp1[35],tmp2[35];
        s.clear();
        for (int i=0;i<n;i++) f[i]=i;
        for (int i=0;i<r;i++)
        {
            scanf("%s %s %d",tmp1,tmp2,&e[i].w);
            e[i].u=findid(tmp1);e[i].v=findid(tmp2);
        }
        sort(e,e+r);
        printf("Scenario #%d\n",++cnt);
        printf("%d tons\n\n",solve());
    }
    return 0;
}
