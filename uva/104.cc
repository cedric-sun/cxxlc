#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

#define MAXN 110
#define INF 0x3f3f3f3f

double d[MAXN][MAXN][MAXN];
int path[MAXN][MAXN][MAXN];

int n, m;

void print_path(int s, int e, int step)
{
    if(step == 0)
    {
        printf("%d", s);
    }
    else
    {
        print_path(s, path[s][e][step], step-1);
        printf(" %d", e);
    }
}

void Floyd()
{
    for(int step = 2; step <= n; step++) //步数 
    {
        for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
            if(d[i][j][step] < d[i][k][step-1] * d[k][j][1])
            {
                d[i][j][step] = d[i][k][step-1] * d[k][j][1];
                path[i][j][step] = k;
            }
        for(int i = 1; i <= n; i++)
        {
            if(d[i][i][step] > 1.01)
            {
                print_path(i, i, step);
                printf("\n");
                return ;
            }
        }
    }
    printf("no arbitrage sequence exists\n");
}

void init()
{
    memset(d, 0, sizeof(d));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i == j) d[i][i][1] = 1.0;
        }
    }
}

int main()
{
    while(~scanf("%d", &n))
    {
        init();
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++) if(i != j)
            {
                scanf("%lf", &d[i][j][1]);
                path[i][j][1] = j;
            }
        }
        Floyd();
    }
    return 0;
}