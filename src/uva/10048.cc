#include <cstdio>
#include <cstring>
#include <algorithm>
using std::max;
using std::min;
const int N=100+5;
const int inf=0x7F7F7F7F;
int G[N][N];

int main()
{
    int c,s,q,cnt=0;
    while (scanf("%d %d %d",&c,&s,&q),c)
    {
        memset(G,0x7F,sizeof G);
        for (int i=1;i<=c;i++)
            G[i][i]=0;

        for (int i=1;i<=s;i++)
        {
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            G[u][v]=G[v][u]=w;
        }
        for (int k=1;k<=c;k++)
            for (int i=1;i<=c;i++)
                for (int j=1;j<=c;j++)
                    if (G[i][k]<inf && G[k][j]<inf)
                        G[i][j]=min(G[i][j],max(G[i][k],G[k][j]));

        if (cnt) putchar('\n');
        printf("Case #%d\n",++cnt);

        for (int i=0;i<q;i++)
        {
            int a,b;
            scanf("%d %d\n",&a,&b);
            if (G[a][b]<inf)
                printf("%d\n",G[a][b]);
            else
                printf("no path\n");
        }
    }
    return 0;
}
