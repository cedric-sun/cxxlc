#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int dr[]= {1,0,-1,0};
const int dc[]= {0,1,0,-1};
const int size=sizeof(int)*4;
int init[4],goal[4],maxd;
int id[10][10],rofid[100],cofid[100];
bool found;

void initalize()
{
    int cnt=0;
    for (int i = 1; i <=8; i++)
    {
        for (int j = 1; j <=8; j++)
        {
            id[i][j]=cnt;
            rofid[cnt]=i,cofid[cnt++]=j;
        }
    }
}
bool input()
{
    int r,c;
    for (int i = 0; i < 4; i++)
    {
        if (scanf("%d %d",&r,&c)==EOF) return 0;
        init[i]=id[r][c];
    }
    for (int i = 0; i < 4; i++)
    {
        scanf("%d %d",&r,&c);
        goal[i]=id[r][c];
    }
    sort(init,init+4);
    sort(goal,goal+4);
    return 1;
}

bool arrive(int *cur)
{
    int *temp=new int[4];
    memcpy(temp,cur,size);
    sort(temp,temp+4);
    if (!memcmp(temp,goal,size))
    {
        delete temp;
        return true;
    }
    delete temp;
    return false;
}

bool move(int i,int dir,int *cur)
{
    int nr=rofid[cur[i]]+dr[dir],nc=cofid[cur[i]]+dc[dir];
    int cnt=0;
    for (int j = 0; j < 4; j++)
    {
        if (id[nr][nc]==cur[j])
        {
            nr+=dr[dir],nc+=dc[dir];
            cnt++;
        }

    }
    if (cnt>1) return 0;
    if (nr<1||nr>8||nc<1||nc>8) return 0;
    cur[i]=id[nr][nc];
    return 1;

}
void dfs(int *cur,int d)
{
    if (arrive(cur))
    {
        found=1;
        return;
    }
    if (d==8) return;

    int *next=new int[4];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            memcpy(next,cur,size);
            if (move(i,j,next))
            {
                dfs(next,d+1);
            }
            if (found)
                return;
        }
    }
}
int main()
{

    initalize();
    while (input())
    {
        found=0;
        dfs(init,0);
        if (found)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
