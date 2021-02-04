#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int nop[25],lnk[1005],id[105];
bool vis[1005];
vector<vector<int> > g;

int dfs(int u)
{
    for (vector<int>::iterator it=g[u].begin();it!=g[u].end();it++)
        if (!vis[*it])
        {
            vis[*it]=1;
            if (lnk[*it]==-1 || dfs(lnk[*it]))
            {
                lnk[*it]=u;
                return 1;
            }
        }
        return 0;
}

int main()
{
    int n,m;
    nop[0]=1;
    while (scanf("%d %d",&n,&m),n||m)
    {
        for (int i=1;i<=n;i++)
        {
            int t;
            scanf("%d",&t);
            nop[i]=nop[i-1]+t;
            for (int j=nop[i-1];j<nop[i];j++)
                id[j]=i;
        }

        g.clear();g.resize(nop[n]);

        for (int i=1;i<=m;i++)
        {
            int t;
            scanf("%d",&t);
            while (t--)
            {
                int t2;
                scanf("%d",&t2);
                for (int j=nop[t2-1];j<nop[t2];j++)
                    g[j].push_back(i);
            }
        }

        memset(lnk,-1,sizeof lnk);
        int jud=0;
        for (int i=1;i<nop[n];i++)
        {
            memset(vis,0,sizeof vis);
            jud+=dfs(i);
        }

        if (jud==nop[n]-1)
        {
            vector<vector<int> > ans;
            ans.clear();ans.resize(n+1);
            for (int i=1;i<=m;i++)
                if (lnk[i]>0)
                    ans[id[lnk[i]]].push_back(i);
            printf("1\n");
            for (int i=1;i<=n;i++)
            {
                int len=ans[i].size();
                for (int j=0;j<len;j++)
                {
                    if (j) putchar(' ');
                    printf("%d",ans[i][j]);
                }
                putchar('\n');
            }
        }
        else
            printf("0\n");
    }
    return 0;
}
