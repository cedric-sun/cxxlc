#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> pii;

const int N=10000+5;

int n,m,indexx;
int dfn[N],low[N],cut[N];
vector< vector<int> > G;

void tarjan(int u,int prev)
{
    dfn[u]=low[u]=indexx++;
    int child_cnt=0;
    for (vector<int>::iterator it=G[u].begin() ; it!=G[u].end() ; ++it)
    {
        int v=*it;
        if (v==prev) continue;
        if (!dfn[v])
        {
            child_cnt++;
            tarjan(v,u);
            low[u]=min(low[u],low[v]);
            if (prev==-1 && child_cnt>1) cut[u]=child_cnt;
            else if (prev!=-1 && low[v]>=dfn[u]) cut[u]++;
        }
        else low[u]=min(low[u],dfn[v]);
    }
}

bool cmp(const pii &ref_1,const pii &ref_2)
{
    return ref_1.second==ref_2.second?
    ref_1.first<ref_2.first
    :
    ref_1.second>ref_2.second;
}
int main()
{
    while (scanf("%d %d",&n,&m),n||m)
    {
        indexx=1;
        G.clear();G.resize(n);
        memset(dfn,0,sizeof dfn);
        memset(cut,0,sizeof cut);
        while (1)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            if (u==-1 && v==-1) break;
            G[u].push_back(v);
            G[v].push_back(u);
        }

        tarjan(0,-1);
        if (cut[0]==0) cut[0]=1;
        for (int i=1;i<n;i++) cut[i]++;

        vector<pii> ans;
        for (int i=0;i<n;i++) ans.push_back(make_pair(i,cut[i]));
        sort(ans.begin(),ans.end(),cmp);

        for (int i=0;i<m;i++)
            printf("%d %d\n",ans[i].first,ans[i].second);
        putchar('\n');
    }
    return 0;
}
