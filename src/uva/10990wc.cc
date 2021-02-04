#include <cstdio>
#include <cstring>

const int N=2000000;

int p,prime[N],depth[N+5],phi[N+5];
bool isprime[N+5];

void init()
{
    memset(isprime,1,sizeof isprime);
    p=0;
    for (int i=2; i<=N; i++)
    {
        if (isprime[i])
        {
            prime[p++]=i;
            phi[i]=i-1;
        }
        for (int j=0,tmp;j<p && (tmp=i*prime[j])<=N; j++)
        {
            isprime[tmp]=0;
            if (!(i%prime[j]))
            {
                phi[tmp]=phi[i]*prime[j];
                break;
            }
            else
                phi[tmp]=phi[i]*(prime[j]-1);
        }
    }

    depth[1]=0;
    for (int i=2;i<=N;i++)          //递推计算深度
        depth[i]+=depth[phi[i]]+1;
    for (int i=2;i<=N;i++)          //前缀和
        depth[i]+=depth[i-1];
}

int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        printf("%d\n",depth[b]-depth[a-1]);
    }
    return 0;
}
