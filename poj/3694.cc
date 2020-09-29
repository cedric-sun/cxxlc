#include <cstdio>
#include <cstring>
#include <algorithm>
using std::min;
const int N=100000+10;

struct Edge
{
    int v,next;
    Edge(int _v=-1,int _next=-1):v(_v),next(_next) {}
} edge[N<<2];

int n,m,q,edge_cnt,id,sccid,top,ans;
int head[N],dfn[N],low[N],stack[N],f[N],depth[N],father[N],scc[N];
int EU[N<<1],EV[N<<1];
bool instack[N];

void init()
{
    edge_cnt=id=sccid=top=ans=0;
    memset(head,-1,sizeof head);
    memset(dfn,0,sizeof dfn);
}

int uf (int x) {return x==f[x]?x:f[x]=uf(f[x]);}

void addEdge(int u,int v)
{
    edge[edge_cnt]=Edge(v,head[u]);
    head[u]=edge_cnt++;
}

void dfs(int u,int fa,int d)
{
    depth[u]=d;
    f[u]=u;
    for (int i=head[u];~i;i=edge[i].next)
    {
        int v=edge[i].v;
        if (v==fa) continue;
        father[v]=u;
        dfs(v,u,d+1);
        ans++;
    }
}

void lca(int u,int v)
{
    top=0;
    u=uf(u),v=uf(v);
    while (u!=v)
    {
        if (depth[u]>depth[v])
        {
            stack[++top]=u;
            u=uf(father[u]);
        }
        else
        {
            stack[++top]=v;
            v=uf(father[v]);
        }
        ans--;
    }
    while (top)
    {
        f[stack[top--]]=u;
    }
}
void tarjan(int u,int fa)
{
    dfn[u]=low[u]=++id;
    stack[++top]=u;
    instack[u]=1;
    int fg=1;
    for (int i=head[u];~i;i=edge[i].next)
    {
        int v=edge[i].v;
        if (v==fa && fg) {fg=0;continue;}
        if (!dfn[v])
        {
            tarjan(v,u);
            low[u]=min(low[u],low[v]);
        }
        else if (instack[v])
        {
            low[u]=min(low[u],dfn[v]);
        }
    }

    if (dfn[u]==low[u])
    {
        ++sccid;
        while (stack[top]!=u)
        {
            instack[stack[top]]=0;
            scc[stack[top--]]=sccid;
        }
        instack[stack[top]]=0;
        scc[stack[top--]]=sccid;
    }
}
int main()
{
    int cnt=1;
    while (scanf("%d %d",&n,&m),n||m)
    {
        init();
        for (int i=0; i<m; i++)
        {
            int u, v;
            scanf("%d %d",&u,&v);
            EU[i]=u;EV[i]=v;
            addEdge(u,v);
            addEdge(v,u);
        }

        tarjan(1,-1);

        edge_cnt=0;memset(head,-1,sizeof head);
        for (int i=0;i<m;i++)
        {
            int u=scc[EU[i]],v=scc[EV[i]];
            if (u!=v)
            {
                addEdge(u,v);
                addEdge(v,u);
            }
        }

        dfs(scc[1],-1,1);
        printf("Case %d:\n",cnt++);
        scanf("%d",&q);
        while (q--)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            lca(scc[u],scc[v]);
            printf("%d\n",ans);
        }
        putchar('\n');
    }
    return 0;
}
