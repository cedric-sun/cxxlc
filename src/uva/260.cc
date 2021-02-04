#include <cstdio>
#include <cstring>
const int N=203;
const int di[6]= {-1,-1,0,0,1,1};
const int dj[6]= {-1,0,-1,1,0,1};
/*
 ( i-1 , j-1 ) , ( i-1 ,  j  )
 (  i  , j-1 ) , (  i  , j+1 )
 ( i+1 ,  j  ) , ( i+l , j+1 )
*/

int n;
char g[N][N];
bool vis[N][N];

bool dfsw(int i,int j)
{
    if (vis[i][j]) return 0;

    vis[i][j]=1;
    if (j==n-1) return 1;
    for (int k=0; k<6; k++)
    {
        int ni=i+di[k],nj=j+dj[k];
        if (g[ni][nj]!='w') continue;
        if (vis[ni][nj]) continue;
        if (ni<0||ni>=n||nj<0||nj>=n) continue;
        if (dfsw(ni,nj))
                return 1;
    }
    return 0;
}


bool dfsb(int i,int j)
{
    if (vis[i][j]) return 0;

    vis[i][j]=1;
    if (i==n-1) return 1;
    for (int k=0; k<6; k++)
    {
        int ni=i+di[k],nj=j+dj[k];
        if (g[ni][nj]!='b') continue;
        if (vis[ni][nj]) continue;
        if (ni<0||ni>=n||nj<0||nj>=n) continue;
        if (dfsb(ni,nj))
                return 1;
    }
    return 0;
}

char calc()
{
    for (int i=0; i<n; i++)
        if (g[i][0]=='w')
            if (dfsw(i,0)) return 'W';

    for (int j=0; j<n; j++)
        if (g[0][j]=='b')
            if (dfsb(0,j)) return 'B';

    return 'E';
}
int main()
{
    int cnt=1;
    while (scanf("%d",&n),n)
    {
        for (int i=0; i<n; i++)
            scanf("%s",g[i]);

        memset(vis,0,sizeof vis);


        printf("%d %c\n",cnt++,calc());
    }
    return 0;
}
