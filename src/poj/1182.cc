#include <cstdio>
#include <cstring>

const int N=50000;

int n,k;
int f[3*N+5];

int bA(int i){return 3*i;}
int bB(int i){return 3*i+1;}
int bC(int i){return 3*i+2;}

int uf(int x)
{
    return f[x]<0?x:f[x]=uf(f[x]);
}
void join(int a,int b)
{
    a=uf(a),b=uf(b);
    if (a==b) return;
    if (f[a]<=f[b]) f[a]+=f[b],f[b]=a;
    else f[b]+=f[a],f[a]=b;
}

bool issame(int a,int b)
{
    if (uf(a)==uf(b)) return 1;
    return 0;
}

int main()
{
    scanf("%d %d",&n,&k);
    int ans=0;
    memset(f,-1,sizeof f);
    for (int i=0; i<k; i++)
    {
        int d,x,y;
        scanf("%d %d %d",&d,&x,&y);
        if (x>n || y>n || x<=0 || y<=0)
        {
            ans++;
            continue;
        }
        if (d==1)
        {
            if ( issame(bA(x),bB(y)) || issame(bA(x),bC(y))
                /* ||issame(bB(x),bC(y)) || issame(bB(x),bA(y)) ||issame(bC(x),bA(y)) || issame(bC(x),bB(y))*/ )
            {
                ans++;
                continue;
            }
            else
            {
                join(bA(x),bA(y));
                join(bB(x),bB(y));
                join(bC(x),bC(y));
            }
        }
        else
        {
            if ( issame(bA(x),bA(y)) || issame(bA(x),bC(y))
                /* ||issame(bB(x),bB(y)) || issame(bB(x),bA(y)) ||issame(bC(x),bC(y)) || issame(bC(x),bB(y))*/ )
            {
                ans++;
                continue;
            }
            else
            {
                join(bA(x),bB(y));
                join(bB(x),bC(y));
                join(bC(x),bA(y));
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
