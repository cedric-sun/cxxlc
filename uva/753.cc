#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <cstring>
using namespace std;

const int INF=0x7FFFFFFF;

struct adapter
{
    int rec,plug;
};

int n,m,k;
int nodelist[205];
adapter ada[105];
map<string,int> ID;
int remnant[305][305],pre[305],flow[305];

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
        for(int v=0;v<=des;++v)
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
    memset(flow,0,sizeof flow);
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

void BuildGraph()
{
    memset(remnant,0,sizeof remnant);

    for (int i=n+1;i<=n+m;i++)//for every device
    {
        remnant[0][i]=1;//Link every device to S

        for (int j=1;j<=n;j++)
            if (nodelist[i]==nodelist[j])
                remnant[i][j]=1;//Link every device to its direct-linkable receptacle

        for (int j=0;j<k;j++)//the j-th in ada[], the n+m+j+1 in nodelist[]
            if (nodelist[i]==ada[j].rec)
                remnant[i][n+m+j+1]=1;//Link every device to its linkable adapter
    }

    for (int i=0;i<k;i++)//for every adapter
    {
        for (int j=1;j<=n;j++)
            if (ada[i].plug==nodelist[j])
                remnant[n+m+i+1][j]=1;//Link every adapter to its linkable receptacle

        for (int j=0;j<k;j++)
            if (ada[i].plug==ada[j].rec)
                remnant[n+m+i+1][n+m+j+1]=INF;//Link every adapter to its linkable adapter
    }

    for (int i=1;i<=n;i++)
        remnant[i][n+m+k+1]=1;//Link every receptacle to T
}

void read()
{
    int num_id=1;
    cin>>n;
    for (int i=1; i<=n; i++) //rec id from 1 to n
    {
        string rec;
        cin>>rec;
        if (ID[rec]==0) ID[rec]=num_id++;
        nodelist[i]=ID[rec];
    }

    cin>>m;
    for (int i=n+1; i<=n+m; i++) //dev id from n+1 to n+m
    {
        string WTF,rec;
        cin>>WTF>>rec;
        if (ID[rec]==0) ID[rec]=num_id++;
        nodelist[i]=ID[rec];
    }

    cin>>k;
    for (int i=0;i<k;i++)//adapter id from n+m+1 to n+m+k
    {
        string rec,plug;
        cin>>rec>>plug;
        if (ID[rec]==0) ID[rec]=num_id++;
        if (ID[plug]==0) ID[plug]=num_id++;
        ada[i].rec=ID[rec];ada[i].plug=ID[plug];
    }
}

int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        ID.clear();
        read();
        BuildGraph();
        cout<<m-MaxFlow(0,n+m+k+1)<<endl;
        if (T) cout.put('\n');
    }
    return 0;
}
