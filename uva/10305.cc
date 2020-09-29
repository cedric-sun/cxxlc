#include <cstdio>
#include <cstring>
#include <vector>
using std::vector;

bool vis[105];
vector<vector<int> > G;
int p,ans[105];

void dfs(int u)
{
    vis[u]=1;
    for (vector<int>::iterator it = G[u].begin();it!=G[u].end();it++)
        if (!vis[*it])
            dfs(*it);

    ans[--p]=u;
}

int main()
{
    int n,m;
    while (scanf("%d %d",&n,&m),n||m)
    {
        memset(vis,0,sizeof vis);
        G.clear();G.resize(n+1);
        p=n;
        while (m--)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            G[a].push_back(b);
        }

        for (int i=1;i<=n;i++)
            if (!vis[i])
                dfs(i);

        for (int i=0;i<n;i++)
        {
            if (i) putchar(' ');
            printf("%d",ans[i]);
        }
        putchar('\n');

    }
    return 0;
}
