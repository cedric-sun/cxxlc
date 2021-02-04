#include <cstdio>
#include <cstring>

const int N=1000;

int p,prime[N],fac[N][200],nop[200];
bool isprime[N+5];

void init()
{
    memset(isprime,1,sizeof isprime);
    p=0;
    for (int i=2; i<=N; i++)
    {
        if (isprime[i])
        {
            prime[p]=i;
            fac[i][p++]=1;
        }
        for (int j=0; j<p; j++)
        {
            int tmp=i*prime[j];
            if (tmp>N) break;
            isprime[tmp]=0;
            memcpy(fac[tmp],fac[i],sizeof(int)*200);
            fac[tmp][j]++;
            if (!(i%prime[j])) break;
        }
    }
}

double calc()
{
    double sum=1;
    for (int i=0; i<p; i++)
        if (nop[i])
        {
            sum*=(nop[i]+1);
            if (sum>1e18) return -1;
        }
    return sum;
}

int main()
{
    init();
    int T;
    scanf("%d",&T);
    for (int k=1;k<=T;k++)
    {
        int n,cnt=0;
        memset(nop,0,sizeof nop);
        scanf("%d",&n);
        while (getchar()!='\n') cnt++;
        for (int i=n; i>0; i-=cnt)
            for (int j=0; j<p; j++)
                nop[j]+=fac[i][j];
        double ans=calc();
        if (ans<0) printf("Case %d: Infinity\n",k);
        else printf("Case %d: %.0f\n",k,ans);
    }
    return 0;
}
