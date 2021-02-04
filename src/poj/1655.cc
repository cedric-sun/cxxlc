#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int N=20000+5;

int n,ans,min_balance;
vector<vector<int> > G;

int dfs(int u,int prev)
{
    int son=0,balance=0;
    for (vector<int>::iterator it=G[u].begin();it!=G[u].end();++it)
    {
        int v=*it;
        if (v==prev) continue;
        int tmp=dfs(v,u)+1;
        son+=tmp;
        balance=max(balance,tmp);
    }
    balance=max(balance,n-son-1);
    if (balance < min_balance || balance == min_balance && u<ans)
    {
        min_balance=balance;
        ans=u;
    }
    return son;
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        min_balance=0x7fffffff;
        G.clear();G.resize(n+1);
        for (int i=1;i<n;i++)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dfs(1,-1);
        printf("%d %d\n",ans,min_balance);
    }
    return 0;
}
