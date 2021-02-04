#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int N=105;
int n,s,cnt;
int stack[N],dist[N];
bool vis[N];
vector<vector<int> > out;
vector<vector<int> > in;

void dfs(int x)
{
    for (vector<int>::iterator it=out[x].begin(); it!=out[x].end(); it++)
        if (!vis[*it])
        {
            vis[*it]=1;
            dfs(*it);
        }
    stack[cnt++]=x;
}

void dp()
{
    dist[s]=0;
    for (int i=cnt-1; i>=0; i--)
    {
        int tmp=stack[i];
        for (vector<int>::iterator it=in[tmp].begin(); it!=in[tmp].end(); it++)
            if (dist[tmp]< dist[*it]+1)
                dist[tmp]=dist[*it]+1;
    }
}

int main()
{
    int k=1;
    while (scanf("%d",&n),n)
    {
        in.clear();out.clear();
        in.resize(n+1);out.resize(n+1);
        memset(vis,0,sizeof vis);
        memset(dist,0x80,sizeof dist);
        scanf("%d",&s);
        int a,b;
        while (scanf("%d %d",&a,&b),a)
        {
            out[a].push_back(b);
            in[b].push_back(a);
        }

        /*
        printf("In\n");
        for (int i=1; i<=n; i++)
        {
            printf("%d\t",i);
            for (vector<int>::iterator it=in[i].begin(); it!=in[i].end(); it++)
                printf("%d\t",*it);
            putchar('\n');
        }
        printf("Out\n");
        for (int i=1; i<=n; i++)
        {
            printf("%d\t",i);
            for (vector<int>::iterator it=out[i].begin(); it!=out[i].end(); it++)
                printf("%d\t",*it);
            putchar('\n');
        }
        */
        cnt=0;
        dfs(s);
        dp();

        int maxp=s;
        for (int i=1; i<=n; i++)
            if (dist[maxp]==dist[i] && i<maxp) maxp=i;
            else if (dist[i]>dist[maxp]) maxp=i;

        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",k++,s,dist[maxp],maxp);
    }
    return 0;
}
