#include <cstdio>
#include <cstring>

int n,m;
int graph[105][105];
bool boom[105][105];

void add(int r,int c)
{
    for (int i=-1; i<=1; i++)
        for (int j=-1; j<=1; j++)
        {
            int nr=r+i,nc=c+j;
            if (nr<0||nr>=n||nc<0||nc>=m) continue;
            if (boom[nr][nc]) continue;
            graph[nr][nc]++;
        }
}
int main()
{
    int cnt=0;
    while (scanf("%d %d",&n,&m)&&n)
    {
        getchar();
        memset(graph,0,sizeof graph);
        memset(boom,0,sizeof boom);
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                if (getchar()=='*')
                {
                    boom[i][j]=1;
                    add(i,j);
                }
            }
            getchar();
        }

        if (cnt) putchar('\n');
        printf("Field #%d:\n",++cnt);
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                if (boom[i][j])
                    putchar('*');
                else
                    printf("%d",graph[i][j]);
            }
            putchar('\n');
        }
    }
    return 0;
}
