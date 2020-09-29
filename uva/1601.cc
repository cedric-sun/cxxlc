#include <cstdio>
#include <cstring>
#include <cctype>
#include <queue>
using namespace std;

const int ls=20,ln=150;
const int dr[]= {1,0,-1,0,0};
const int dc[]= {0,-1,0,1,0};

struct state
{
    int a,b,c;
    state(int x,int y,int z):a(x),b(y),c(z) {};
};


int w,h,n;
int begin[3],target[3];
int next_legal_cell[ln][5],legal_dir_num[ln],dist[ln][ln][ln];

bool input()
{
    scanf("%d %d %d",&w,&h,&n);
    if (!w)  return 0;
    getchar();
    char graph[ls][ls];
    for (int i = 0; i < h; i++)
        fgets(graph[i],ls,stdin);

    int cnt=0;
    int r[ln],c[ln],id[ls][ls];
    char temp;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if ((temp=graph[i][j])!='#')
            {
                r[cnt]=i,c[cnt]=j,id[i][j]=cnt;
                if (islower(temp)) begin[temp-'a']=cnt;
                else if (isupper(temp)) target[temp-'A']=cnt;
                ++cnt;
            }
        }
    }

    for (int i = 0; i < cnt; i++)
    {
        legal_dir_num[i]=0;
        for (int j = 0; j < 5; j++)
        {
            int newr=r[i]+dr[j],newc=c[i]+dc[j];
            if (graph[newr][newc]!='#')
            {
                next_legal_cell[i][legal_dir_num[i]++]=id[newr][newc];
            }
        }
    }

    if(n <= 2)
    {
        legal_dir_num[cnt] = 1;
        next_legal_cell[cnt][0] = cnt;
        begin[2] = target[2] = cnt++;
    }
    if(n <= 1)
    {
        legal_dir_num[cnt] = 1;
        next_legal_cell[cnt][0] = cnt;
        begin[1] = target[1] = cnt++;
    }
    return 1;
}

bool illegal_move(int a,int b,int na,int nb)
{
    return (na==nb)||(na==b&&nb==a);
}
/*bool legal_move(int a,int b,int na,int nb)
{
    return (na!=nb)&&(na!=b||nb!=a);
}*/
int BFS()
{
    std::queue<state> q;
    memset(dist,-1,sizeof dist);
    dist[begin[0]][begin[1]][begin[2]] = 0;
    state start(begin[0],begin[1],begin[2]);
    q.push(start);
    while (!q.empty())
    {
        state cur=q.front();
        q.pop();
        int a=cur.a,b=cur.b,c=cur.c;
        if (a==target[0]&&b==target[1]&&c==target[2]) return dist[a][b][c];
        for (int i = 0; i < legal_dir_num[a]; i++)
        {
            int na=next_legal_cell[a][i];


            for (int j = 0; j < legal_dir_num[b]; j++)
            {
                int nb=next_legal_cell[b][j];
                if (illegal_move(a,b,na,nb)) continue;
                for (int k = 0; k < legal_dir_num[c]; k++)
                {
                    int nc=next_legal_cell[c][k];
                    if(dist[na][nb][nc] != -1) continue;
                    if (illegal_move(a,c,na,nc)||illegal_move(b,c,nb,nc)) continue;
                    dist[na][nb][nc]=dist[a][b][c]+1;
                    state next(na,nb,nc);
                    q.push(next);
                }
            }

            /*for (int j = 0; j < legal_dir_num[b]; j++)
            {
                int nb=next_legal_cell[b][j];
                if (legal_move(a,b,na,nb))
                {
                    for (int k = 0; k < legal_dir_num[c]; k++)
                    {
                        int nc=next_legal_cell[c][k];
                        if (dist[na][nb][nc]==-1&&legal_move(a,c,na,nc)&&legal_move(b,c,nb,nc))
                        {
                            dist[na][nb][nc]=dist[a][b][c]+1;
                            state next(na,nb,nc);
                            q.push(next);
                        }
                    }
                }
            }*/
        }
    }
    return -1;
}
int main()
{
    while (input())
    {
        printf("%d\n",BFS());
    }
    return 0;
}

