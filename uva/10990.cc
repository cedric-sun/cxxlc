#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int N=2000000;

int p,prime[N],depth[N+5],phi[N+5];
bool isprime[N+5];

vector<vector<int> > G;

void init()
{
    G.resize(N+5);
    memset(isprime,1,sizeof isprime);
    p=0;
    for (int i=2; i<=N; i++)
    {
        if (isprime[i])
        {
            prime[p++]=i;
            phi[i]=i-1;
            G[i-1].push_back(i);
        }
        for (int j=0,tmp;j<p && (tmp=i*prime[j])<=N; j++)
        {
            isprime[tmp]=0;
            if (!(i%prime[j]))
            {
                G[phi[tmp]=phi[i]*prime[j]].push_back(tmp);
                break;
            }
            else
                G[phi[tmp]=phi[i]*(prime[j]-1)].push_back(tmp);
        }
    }
}

void dfs(int x,int d)
{
    depth[x]=d;
    for (auto it=G[x].begin(); it!=G[x].end(); ++it)
        dfs(*it,d+1);
}

int main()
{
    init();
    dfs(1,0);
    for (int i=2; i<=N; i++)
        depth[i]+=depth[i-1];
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        printf("%d\n",depth[b]-depth[a-1]);
    }
    return 0;
}
