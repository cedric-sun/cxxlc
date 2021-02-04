#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int N=30;

struct _style
{
    int a,b,h;
}style[N*3];

int dp[N*3];//dp[i] represent the length of the longest path ends with style[i]
vector<vector<int> > DAG;

inline bool check(int i,int j)//whether style[i] can be put upon style[j]
{
    return style[i].a<style[j].a && style[i].b<style[j].b || style[i].a<style[j].b && style[i].b<style[j].a;
}

int dfs(int u)//dp solve the longest path in DAG;
{
    if (~dp[u]) return dp[u];
    dp[u]=style[u].h;
    for (vector<int>::iterator it=DAG[u].begin();it!=DAG[u].end();++it)
        dp[u]=max(dp[u],style[u].h+dfs(*it));
    return dp[u];
}

int main()
{
    int n;
    int cnt=1;
    while (scanf("%d",&n),n)
    {
        for (int i=0;i<n;i++)
        {
            int a,b,h;
            scanf("%d %d %d",&a,&b,&h);
            style[i].a=a;       style[i].b=b;       style[i].h=h;
            style[n+i].a=a;     style[n+i].b=h;     style[n+i].h=b;
            style[n*2+i].a=h;  style[n*2+i].b=b;  style[n*2+i].h=a;
        }

        n*=3;

        //for (int i=0;i<n;i++) printf("%d\t%d\t%d\n",style[i].a,style[i].b,style[i].h);

        DAG.clear();DAG.resize(n);
        for (int i=0;i<n;i++)
        {
            for (int j=i+1;j<n;j++)
            {
                if (check(i,j)) DAG[i].push_back(j);
                if (check(j,i)) DAG[j].push_back(i);
            }
        }

        int ans=0;
        memset(dp,-1,sizeof dp);
        for (int i=0;i<n;i++)
            ans=max(ans,dfs(i));

        printf("Case %d: maximum height = %d\n",cnt++,ans);
    }
    return 0;
}
