#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int di[8]= {1,1,-1,-1,2,2,-2,-2};
const int dj[8]= {2,-2,2,-2,1,-1,1,-1};

bool vis[8][8];
int cnt[8][8],from,to;

int bfs()
{
    queue<int> q;
    q.push(from);
    while (!q.empty())
    {
        int cur=q.front(),j=cur&0xF,i=cur>>4;
        q.pop();
        for (int k=0; k<8; k++)
        {
            int ni=i+di[k],nj=j+dj[k];
            if (ni>=0 && ni<8 && nj>=0 && nj<8 && !vis[ni][nj])
            {
                int ns=(ni<<4)+nj;
                cnt[ni][nj]=cnt[i][j]+1;
                if (ns==to) return cnt[ni][nj];
                vis[ni][nj]=1;
                q.push(ns);
            }
        }
    }
}

int main()
{
    char cfrom[5],cto[5];
    while (~scanf("%s %s",cfrom,cto))
    {
        int ini=cfrom[0]-'a',inj=cfrom[1]-'1';
        from=(ini<<4)+inj,to=((cto[0]-'a')<<4)+cto[1]-'1';
        cnt[ini][inj]=0;
        memset(vis,0,sizeof vis);
        printf("To get from %s to %s takes %d knight moves.\n",cfrom,cto,from==to?0:bfs());
    }
    return 0;
}
