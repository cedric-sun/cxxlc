#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

const int N=10005;
const int INF=0x7FFFFFFF;

struct adj
{
    int v,l;
    adj(int _v,int _l):v(_v),l(_l) {}
};

typedef vector<adj>::iterator adjit;
typedef vector<int>::iterator viit;

int n,query;
int root,min_balance;
int node_cnt[N];
bool done[N];
vector<adj> G[N];

int Get_Root(int u,int prev,const int Tree_Size)//O(n)
{
    int son=1,balance=0;
    for (adjit it=G[u].begin(); it!=G[u].end(); it++)
    {
        int v=it->v;
        if (v==prev || done[v]) continue;
        int tmp=Get_Root(v,u,Tree_Size);
        son+=tmp;
        balance=max(balance,tmp);
    }
    balance=max(balance,Tree_Size-son);
    if (balance<min_balance)
    {
        min_balance=balance;
        root=u;
    }
    return son;
}

vector<int> dist;
void Get_Dist_List(int u,int prev,int d)//O(n)
{
    dist.push_back(d);
    node_cnt[u]=1;
    for (adjit it=G[u].begin(); it!=G[u].end(); ++it)
    {
        int v=it->v;
        if (v==prev || done[v]) continue;
        Get_Dist_List(v,u,d+it->l);
        node_cnt[u]+=node_cnt[v];
    }
}

map<int,bool> mp;
void Pairs_Num(int u,int init_depth,int mode)//O(n^2)
{
    dist.clear();
    Get_Dist_List(u,-1,init_depth);//O(n)

    int len=dist.size();
    for (int i=0; i<len-1; i++)
        for (int j=i+1; j<len; j++)
        {
            if (mode)
            {
                //printf("Added %d\n",dist[i]+dist[j]);
                mp[dist[i]+dist[j]]=1;
            }
            else
            {
                //printf("Deleted %d\n",dist[i]+dist[j]);
                mp[dist[i]+dist[j]]=0;
            }
        }

}

void Solve(int u)
{
    Pairs_Num(u,0,1);
    done[u]=1;
    for (adjit it=G[u].begin(); it!=G[u].end(); ++it)
    {
        int v=it->v;
        if (done[v]) continue;
        Pairs_Num(v,it->l,0);
        min_balance=INF;
        Get_Root(v,-1,node_cnt[v]);
        //Or Get_Root(v,-1,Get_Node_Num(v,-1));
        Solve(root);
    }
}

int main()
{
    while (scanf("%d",&n)==1 && n)
    {
        for (int i=1; i<=n; i++) G[i].clear();
        for (int u=1; u<=n; u++)
        {
            int v,l;
            while (scanf("%d",&v),v)
            {
                scanf("%d",&l);
                G[u].push_back(adj(v,l));
                G[v].push_back(adj(u,l));
            }
        }

        memset(done,0,sizeof done);
        min_balance=INF;
        Get_Root(1,-1,n);
        Solve(root);

        //for (map<int,bool>::iterator it=mp.begin();it!=mp.end();++it) printf("%d %d\n",it->first,it->second);

        while (scanf("%d",&query)==1 && query)
        {
            puts(mp[query]?"AYE":"NAY");
        }
        puts(".");
    }
    return 0;
}

