#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;

const int N=105;

int dep[N],n;
bool vis[N];
set<int> g[N];

bool read()
{
    scanf("%d",&n);
    if (!n) return false;
    for (int i=1; i<=n; i++)
        g[i].clear();
    memset(vis,0,sizeof vis);
    memset(dep,0,sizeof dep);
    for (int i = 1; i <=n; i++)
    {
        int k;
        scanf("%d",&k);
        while (k--)
        {
            int temp;
            scanf("%d",&temp);
            g[i].insert(temp);
        }
    }
    return true;
}

void dfs(int a)
{
    if (vis[a]) return;
    vis[a]=true;
    for (set<int>::iterator it=g[a].begin(); it!=g[a].end(); ++it)
    {
        dfs(*it);
        g[a].insert(g[*it].begin(),g[*it].end());
    }
}

int solve()
{
    for (int i = 1; i <=n; i++)
        dfs(i);
    int maxt=0,id;
    for (int i = 1; i <=n; i++)
        if (g[i].size()>maxt)
        {
            maxt=g[i].size();
            id=i;
        }
    return id;
}
int main()
{
    while (read())
        printf("%d\n",solve());
    return 0;
}
