#include <cstdio>
#include <cstring>
const int N=26;
bool G[N][N],avail[N];
char ans[N+5];
int ss;
char in[10086][25];

void dfs(int u)
{
    avail[u]=false;
    for (int i=0;i<N;i++)
        if (avail[i] && G[u][i])
            dfs(i);

    ans[ss++]=u+'A';
}

int main()
{
    int cnt=0;
    do
        scanf("%s",in[cnt]);
    while (in[cnt++][0]!='#');

    memset(avail,0,sizeof avail);
    memset(G,0,sizeof G);
    ss=0;
    for (int i=1; i<cnt-1; i++)
        for (int p1=0,p2=0; in[i-1][p1] && in[i][p2]; p1++,p2++)
        {
            if (in[i-1][p1]!=in[i][p2])
            {
                G[in[i-1][p1]-'A'][in[i][p2]-'A']=1;
                avail[in[i-1][p1]-'A']=avail[in[i][p2]-'A']=1;
                break;
            }
        }

    for (int i=0;i<N;i++)
        if (avail[i]) dfs(i);

    while (ss--)
        putchar(ans[ss]);
    putchar('\n');
}
