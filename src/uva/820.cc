#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

const int N=100+5;
int INF = 0x7fffffff;

int n,s,t,c;
int remnant[N][N];          //remnant network matrix
int flow[N];                //record usable flow amount of certain vertex
int pre[N];                 //mark prefix


int BFS(int src,int des)
{
    memset(pre,-1,sizeof pre);
    pre[src]=0;flow[src]= INF;
    queue<int> Q;
    Q.push(src);
    while(!Q.empty())
    {
        int u = Q.front();Q.pop();
        if(u == des) break;
        for(int v=1;v<=n;++v)
        {
            if(remnant[u][v]>0 && pre[v]==-1 && v!=src)
            {
                 pre[v] = u; //rec prefix
                 flow[v] = min(remnant[u][v],flow[u]);   //key:update flow
                 Q.push(v);
            }
        }
    }
    if(pre[des]==-1) return -1;      //no more augmenting path
    else return flow[des];
}

int MaxFlow(int src,int des)
{
    int increasement= 0;
    int sumflow = 0;
    while((increasement=BFS(src,des))!=-1)
    {
         int k = des;          //backtrack path
         while(k!=src)
         {
              int last = pre[k];
              remnant[last][k] -= increasement; //update positive edge
              remnant[k][last] += increasement; //update negative edge
              k = last;
         }
         sumflow += increasement;
    }
    return sumflow;
}

int main()
{
    int cnt=1;
    while (~scanf("%d",&n) && n)
    {
        memset(remnant,0,sizeof remnant);
        memset(flow,0,sizeof flow);
        scanf("%d %d %d",&s,&t,&c);
        for (int i=0;i<c;i++)
        {
            int u,v,cap;
            scanf("%d %d %d",&u,&v,&cap);
            if (u==v) continue;
            remnant[u][v]+=cap;
            remnant[v][u]+=cap;
        }

        printf("Network %d\n",cnt++);
        printf("The bandwidth is %d.\n\n",MaxFlow(s,t));
    }
    return 0;
}

