#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int N=5000+5;
const int M=10000+5;
int F,R,index,sccid,tp;
int dfn[N],low[N],scc[N],stack[N],JOJO[M],DIO[M];
bool onstack[N];

vector< vector<int> > G;

void tarjan(int u,int prev)
{
    dfn[u]=low[u]=index++;
    onstack[u]=1;
    stack[++tp]=u;
    bool flag=1;
    for (vector<int>::iterator it=G[u].begin();it!=G[u].end();++it)
    {
        int v=*it;
        if (v==prev && flag) {flag=0;continue;}
        if (!dfn[v])
        {
            tarjan(v,u);
            low[u]=min(low[u],low[v]);
        }
        else if (onstack[v])
            low[u]=min(low[u],dfn[v]);
    }
    if (dfn[u]==low[u])
    {
        int top;
        do
        {
            top=stack[tp--];
            onstack[top]=0;
            scc[top]=sccid;
        }while (top!=u);
        ++sccid;
    }
}

int main()
{
    while (~scanf("%d %d",&F,&R))
    {
        index=1;sccid=1;tp=0;
        G.clear();G.resize(F+5);
        memset(dfn,0,sizeof dfn);
        memset(low,0,sizeof low);
        memset(scc,0,sizeof scc);
        memset(onstack,0,sizeof onstack);

        for (int i=0;i<R;i++)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            JOJO[i]=u;DIO[i]=v;
            G[u].push_back(v);
            G[v].push_back(u);
        }

        tarjan(1,-1);

        G.clear();G.resize(F+5);

        for (int i=0;i<R;i++)
        {
            int u=JOJO[i],v=DIO[i];
            if (scc[u]==scc[v]) continue;
            G[scc[u]].push_back(scc[v]);
            G[scc[v]].push_back(scc[u]);
        }

        int lcnt=0;

        for (int i=1;i<=F;i++)
            if (G[i].size()==1) lcnt++;

        printf("%d\n",(lcnt+1)>>1);
    }
    return 0;
}
