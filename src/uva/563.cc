#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

class EK_Max_Flow
{
private:
    struct edge{int u,v,rem,next;};
    int VN,EN;      int E_size;     int max_flow;       int STA,DST;
    queue<int> Q;
    edge *E;
    int *flow,*first,*pre;
public:
    EK_Max_Flow();
    ~EK_Max_Flow();
    void redef(int,int,int,int);
    void clear();
    void addedge(int,int,int,bool);
    int run(void);
};

EK_Max_Flow::EK_Max_Flow()
{
    E_size=0;
    E=NULL;
    flow=first=pre=NULL;
}

EK_Max_Flow::~EK_Max_Flow()
{
    delete [] E;E=NULL;
    delete [] first;first=NULL;
    delete [] pre;pre=NULL;
    delete [] flow;flow=NULL;
}

void EK_Max_Flow::redef(int _VN,int _EN,int _STA,int _DST)
{
    VN=_VN;STA=_STA;DST=_DST;
    E_size=0;

    if (E!=NULL) {delete E;E=NULL;}
    E=new edge[(_EN<<1)+5];

    if (first!=NULL) {delete first;first=NULL;}
    first=new int[VN+5];
    memset(first,-1,sizeof(int)*(VN+5));

    if (pre!=NULL) {delete pre;pre=NULL;}
    pre=new int[VN+5];

    if (flow!=NULL) {delete flow;flow=NULL;}
    flow=new int[VN+5];
}

void EK_Max_Flow::addedge(int u,int v,int cap,bool IS_DIRECTIONAL)
{
    E[E_size].u=u;              E[E_size].v=v;
    E[E_size].rem=cap;
    E[E_size].next=first[u];    first[u]=E_size++;
    swap(u,v);
    E[E_size].u=u;              E[E_size].v=v;
    E[E_size].rem=IS_DIRECTIONAL?0:cap;
    E[E_size].next=first[u];    first[u]=E_size++;
}

int EK_Max_Flow::run()
{
    while (!Q.empty()) Q.pop();
    max_flow=0;
    while (1)
    {
        memset(pre,-1,sizeof(int)*(VN+5));
        flow[STA]=0x7FFFFFFF;
        Q.push(STA);
        while (!Q.empty())
        {
            int u=Q.front();Q.pop();
            for (int k=first[u];k!=-1;k=E[k].next)
            {
                int v=E[k].v;
                if (pre[v]==-1 && v!=STA && E[k].rem>0)
                {
                    pre[v]=k;
                    flow[v]=min(E[k].rem,flow[u]);
                    Q.push(v);
                }
            }
        }

        if (pre[DST]==-1) break;

        for (int k=pre[DST];k!=-1;k=pre[E[k].u])
        {
            E[k].rem-=flow[DST];
            E[k^1].rem+=flow[DST];
            //for edge k, k^1 represent its reversed edge.
        }

        max_flow+=flow[DST];
    }

    return max_flow;
}

const int di[]={0,1,0,-1},dj[]={1,0,-1,0};
int s,a,b;
EK_Max_Flow DIO;

inline int id(int i,int j){return (i-1)*a+j;}

void BuildGraph()
{
    int sta=0,dst=2*s*a+1;

    DIO.redef(2*s*a+5,s*a*6,sta,dst);

    for (int i=1;i<=s;i++)
    {
        for (int j=1;j<=a;j++)
        {
            int rec=id(i,j),sen=rec+s*a;//receive & send
            DIO.addedge(rec,sen,1,1);
            for (int k=0;k<4;k++)
            {
                int ni=i+di[k],nj=j+dj[k];
                if (ni>=1 && ni <=s && nj>=1 && nj<=a)
                    DIO.addedge(sen,id(ni,nj),1,1);
                else
                    DIO.addedge(sen,dst,1,1);
            }
        }
    }

    for (int k=0;k<b;k++)
    {
        int i,j;
        scanf("%d %d",&i,&j);
        DIO.addedge(sta,id(i,j),1,1);
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d %d %d",&s,&a,&b);
        BuildGraph();
        puts(DIO.run()==b?"possible":"not possible");
    }
    return 0;
}
