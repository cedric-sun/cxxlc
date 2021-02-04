#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

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
int ans;
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

int Pairs_Num(int u,int init_depth)//O(nlogn)
{
    dist.clear();
    Get_Dist_List(u,-1,init_depth);//O(n)
    sort(dist.begin(),dist.end());//O(nlogn)
    vector<int>::iterator it1=dist.begin(),it2=dist.end()-1;
    int pairs_cnt=0;
    while (it1<it2)//O(n)
    {
        if (*it1+*it2<query) it1++;
        else if (*it1+*it2>query) it2--;
        else
        {
            if (*it1==*it2)
            {
                pairs_cnt+=(it2-it1)*(it2-it1+1)>>1;
                break;
            }
            viit st=it1,ed=it2;
            while (*st==*it1) ++st;
            while (*ed==*it2) --ed;
            pairs_cnt+=(st-it1)*(it2-ed);
            it1=st;
            it2=ed;
        }
    }
    return pairs_cnt;
}

void Solve(int u)
{
    ans+=Pairs_Num(u,0);
    done[u]=1;
    for (adjit it=G[u].begin(); it!=G[u].end(); ++it)
    {
        int v=it->v;
        if (done[v]) continue;
        ans-=Pairs_Num(v,it->l);
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

        while (scanf("%d",&query)==1 && query)
        {
            ans=0;
            memset(done,0,sizeof done);
            min_balance=INF;
            Get_Root(1,-1,n);
            Solve(root);
            puts(ans>0?"AYE":"NAY");
        }
        puts(".");
    }
    return 0;
}
