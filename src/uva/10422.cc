#include <cstdio>
#include <queue>
#include <map>
#include <cstring>
#include <string>
using namespace std;

const int   di[]= {1,1,-1,-1,2,2,-2,-2},
        dj[]= {2,-2,2,-2,1,-1,1,-1};
const char  target[5][5]=
{
    '1','1','1','1','1',
    '0','1','1','1','1',
    '0','0',' ','1','1',
    '0','0','0','0','1',
    '0','0','0','0','0'
};

struct state
{
    char G[5][5];
    int bi,bj,step;
    state(int bii,int bjj,int stepp,char g[5][5]):bi(bii),bj(bjj),step(stepp)
    {
        memcpy(G,g,sizeof G);
    }
};

char start[5][5];
map<string,bool> check;
int bfs(int ibi,int ibj)
{
    queue<state> q;
    q.push(state(ibi,ibj,0,start));
    while (!q.empty())
    {
        state t=q.front();
        q.pop();
        if (t.step>10) return -1;
        for (int i=0; i<8; i++)
        {
            int ni=t.bi+di[i],nj=t.bj+dj[i];
            if (ni>=0 && ni<5 && nj>=0 && nj <5)
            {
                int k=0;
                char tmp[5][5],s[26];
                memcpy(tmp,t.G,sizeof t.G);
                tmp[t.bi][t.bj]=tmp[ni][nj];
                tmp[ni][nj]=' ';
                for (int i=0; i<5; i++)
                    for (int j=0; j<5; j++)
                        s[k++]=tmp[i][j];
                s[25]='\0';
                if (!check[s])
                {
                    check[s]=1;
                    if (!memcmp(tmp,target,sizeof tmp)) return t.step+1;
                    q.push(state(ni,nj,t.step+1,tmp));
                }
            }
        }
    }

}
int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    while (T--)
    {
        int ibi,ibj;
        for (int i=0; i<5; i++)
        {
            for (int j=0; j<5; j++)
                if ((start[i][j]=getchar())==' ')
                {
                    ibi=i;
                    ibj=j;
                }
            getchar();
        }
        if (!memcmp(start,target,sizeof start)) printf("Solvable in 0 move(s).\n");
        else
        {
            int ans=bfs(ibi,ibj);
            if (ans<0)
                printf("Unsolvable in less than 11 move(s).\n");
            else
                printf("Solvable in %d move(s).\n",ans);
        }
    }
    return 0;
}
