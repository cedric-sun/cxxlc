#include <cstdio>
#include <cstdlib>
#include <cstring>
const int l=250,O=105;
const int dx[]= {1,0,0,-1};
const int dy[]= {0,1,-1,0};
const char dirlist[]="ensw";

int maxl,table[30],ans[30],cnt;
bool b[l][l],visited[l][l];

void output()
{
    for (int i = 0; i < maxl; i++)
    {
        putchar(dirlist[ans[i]]);
    }
    putchar('\n');
}

bool legal(int cur,int x,int y,int newx,int newy,int newdir)
{
    if (b[newx][newy]) return 0;
    if (abs(newx-O)+abs(newy-O)>table[maxl]-table[cur+1]) return 0;
    if (visited[newx][newy]&&!(newx==O&&newy==O&&cur+1==maxl)) return 0;
    for (int i=x; i!=newx; i+=dx[newdir])
        if (b[i][newy]) return 0;
    for (int i=y; i!=newy; i+=dy[newdir])
        if (b[newx][i]) return 0;
    return 1;
}

void dfs(int cur,int x,int y,int dir)
{
    if (cur==maxl)
    {
        if (x==O&&y==O)
        {
            output();
            cnt++;
        }
        return;
    }

    for (int i=0; i<4; i++)
    {
        if (i==dir||i+dir==3) continue;
        int newx=x+(cur+1)*dx[i],newy=y+(cur+1)*dy[i];
        if (legal(cur,x,y,newx,newy,i))
        {
            ans[cur]=i;
            visited[newx][newy]=1;
            dfs(cur+1,newx,newy,i);
            visited[newx][newy]=0;
        }
    }


}
int main()
{
    int T;
    table[0]=0;
    for(int i=1; i<=20; i++) table[i]=table[i-1]+i;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d %d",&maxl,&n);
        memset(b,0,sizeof b);
        memset(visited,0,sizeof visited);
        visited[O][O]=true;
        cnt=0;
        for (int i=0; i<n; i++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            if (abs(x)>O||abs(y)>O) continue;
            b[x+O][y+O]=1;
        }

        dfs(0,O,O,-1);

        printf("Found %d golygon(s).\n\n",cnt);
    }
    return 0;
}
