#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int N=500+5;

int n,m,root;
static int index;
int dfn[N],low[N];
bool instack[N];

vector<vector<int> > G;

bool tarjan(int u,int f,int ignore,int &v_cnt)
{
    dfn[u]=low[u]=index++;
    instack[u]=1;
    int ctn=0;
    ++v_cnt;
    for (vector<int>::iterator it=G[u].begin();it!=G[u].end();++it)
    {
        int v=*it;
        if (v==f || v==ignore) continue;
        if (!dfn[v])
        {
            if (!tarjan(v,u,ignore,v_cnt)) return 0;
            ++ctn;
            low[u]=min(low[u],low[v]);
            if ((u==root && ctn>1) || (u!=root && dfn[u]<=low[v])) return 0;
        }
        else if (instack[v])
        {
            low[u]=min(low[u],dfn[v]);
        }
    }
    instack[u]=0;
    return 1;
}

bool solve()
{
    for (int i=0;i<n;i++)
    {
        memset(dfn,0,sizeof dfn);
        memset(low,0,sizeof low);
        memset(instack,0,sizeof instack);
        root=0;
        if (i==0) root=1;
        int v_cnt=0;
        if (!tarjan(root,-1,i,v_cnt)) return 0;
        if (v_cnt!=n-1) return 0;
    }
    return 1;
}
int main()
{
    while (scanf("%d %d",&n,&m),n||m)
    {
        index=1;
        G.clear();G.resize(n+5);
        for (int i=0;i<m;i++)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
        }

        printf("%s\n",solve()?"YES":"NO");
    }
    return 0;
}
