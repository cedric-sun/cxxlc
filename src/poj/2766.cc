#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
using namespace std;
struct rt
{
    int x,y,dir[4];
};

rt board[2500];
int n,r,id[55][55];
vector<vector<int> >xlist;
vector<vector<int> >ylist;
set<int> path;
const int inf(1<<30);


int getneigh(int a,int dir)
{
    vector<int>::iterator itx,ity;
    switch(dir)
    {
        case 0:
            itx=upper_bound(ylist[board[a].y].begin(),ylist[board[a].y].end(),board[a].x);
            return (itx==ylist[board[a].y].end())?inf:id[*itx][board[a].y];
        case 1:
            ity=lower_bound(xlist[board[a].x].begin(),xlist[board[a].x].end(),board[a].y);
            return (ity==xlist[board[a].x].begin())?inf:id[board[a].x][*(ity-1)];
        case 2:
            itx=lower_bound(ylist[board[a].y].begin(),ylist[board[a].y].end(),board[a].x);
            return (itx==ylist[board[a].y].begin())?inf:id[*(itx-1)][board[a].y];
        case 3:
            ity=upper_bound(xlist[board[a].x].begin(),xlist[board[a].x].end(),board[a].y);
            return (ity==xlist[board[a].x].end())?inf:id[board[a].x][*ity];
    }
    return -1;
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d %d",&n,&r);

        path.clear();
        xlist.clear();xlist.resize(n+2);
        ylist.clear();ylist.resize(n+2);
        memset(id,0,sizeof id);
        memset(board,0,sizeof board);

        int x,y;
        for (int i=0;i<=r;i++)
        {
            scanf("%d %d",&x,&y);
            board[i].x=x;board[i].y=y;
            id[x][y]=i;
            xlist[x].push_back(y);
            ylist[y].push_back(x);
        }


        for (int i=1;i<=n;i++)
        {
            sort(xlist[i].begin(),xlist[i].end());
            sort(ylist[i].begin(),ylist[i].end());
        }

        for (int i=0;i<=r;i++)
            for (int j=0;j<4;j++)
                board[i].dir[j]=getneigh(i,j);


        int cur=r,t;
        //for (int i=0;board[r].dir[i]==inf ;t=++i);


        if (!x) t=0;
        else if (!y) t=3;
        else if (x==n+1) t=2;
        else if (y==n+1) t=1;


        while (1)
        {
            if (board[cur].dir[t]==inf || board[cur].dir[t]==r)
            {
                t=(t+1)%4;
                switch (t)
                {
                    case 0:printf("%d %d\n",board[cur].x,n+1);break;
                    case 1:printf("%d %d\n",n+1,board[cur].y);break;
                    case 2:printf("%d %d\n",board[cur].x,0);break;
                    case 3:printf("%d %d\n",0,board[cur].y);break;
                }
                break;
            }
            int st=(t<<13)+cur;
            if (path.count(st))
            {
                printf("0 0\n");
                break;
            }
            path.insert(st);
            cur=board[cur].dir[t];
            t=(t+1)%4;
        }
    }
    return 0;
}
