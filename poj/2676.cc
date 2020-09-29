#include <cstdio>
#include <cstring>
const int l=10;
int graph[l][l];
bool in_row_yet[l][l],in_column_yet[l][l],in_grid_yet[l][l];

void input()
{
    int temp;
    for (int i = 1; i <=9; ++i)
    {
        for (int j = 1; j <=9; ++j)
        {
            graph[i][j]=temp=getchar()-'0';
            if (temp)
            {
                int k=3*((i-1)/3)+(j-1)/3+1;
                in_row_yet[i][temp]=in_column_yet[j][temp]=in_grid_yet[k][temp]=1;
            }
        }
        getchar();
    }
}

bool dfs(int r,int c)
{
    if (r==10)
        return true;

    bool flag=false;

    if (graph[r][c])
    {
        flag=(c==9)?dfs(r+1,1):dfs(r,c+1);
        return flag;
    }
    else
    {
        int k=3*((r-1)/3)+(c-1)/3+1;
        for (int i=1; i<=9; i++)
        {
            if (!in_row_yet[r][i]&&!in_column_yet[c][i]&&!in_grid_yet[k][i])
            {
                graph[r][c]=i;
                in_row_yet[r][i]=in_column_yet[c][i]=in_grid_yet[k][i]=true;
                flag=(c==9)?dfs(r+1,1):dfs(r,c+1);

                if (!flag)
                {
                    graph[r][c]=0;
                    in_row_yet[r][i]=in_column_yet[c][i]=in_grid_yet[k][i]=false;
                }
                else
                    return true;
            }
        }
        return false;
    }
}

void output()
{
    for (int i = 1; i <=9; ++i)
    {
        for (int j = 1; j <=9; ++j)
        {
            printf("%d",graph[i][j]);
        }
        putchar('\n');
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    while (T--)
    {
        memset(in_row_yet,0,sizeof in_row_yet);
        memset(in_column_yet,0,sizeof in_column_yet);
        memset(in_grid_yet,0,sizeof in_grid_yet);
        input();
        dfs(1,1);
        output();
    }
    return 0;
}
