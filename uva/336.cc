#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <cstring>
using namespace std;

map<int,int> id;
vector<int> g[31];
bool vis[35];
int d[35];

void bfs(int s,int t)
{
    queue<int> q;
    q.push(s);
    vis[s]=1;
    while (!q.empty())
    {
        int cur=q.front();
        q.pop();
        if (d[cur]<t)
            for (vector<int>::iterator it=g[cur].begin(); it!=g[cur].end(); it++)
                if (!vis[*it])
                {
                    vis[*it]=1;
                    d[*it]=d[cur]+1;
                    q.push(*it);
                }
    }
}
int main()
{
    int n,cnt=1;
    while (scanf("%d",&n),n)
    {
        id.clear();
        for (int i=1; i<=30; i++) g[i].clear();
        int nop=1;
        while (n--)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            if (!id[a]) id[a]=nop++;
            if (!id[b]) id[b]=nop++;
            g[id[a]].push_back(id[b]);
            g[id[b]].push_back(id[a]);
        }

        int o,t;
        while (scanf("%d %d",&o,&t),o)
        {
            memset(vis,0,sizeof vis);
            memset(d,0,sizeof d);
            int ans=0;
            bfs(id[o],t);
            for (int i=1;i<nop;i++)
                if (!vis[i]) ans++;
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",cnt++,ans,o,t);
        }
    }
    return 0;
}
