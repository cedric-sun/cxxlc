#include <cstdio>
#include <cstring>
#include <cmath>

const int N=sqrt(0x7fffffff);
int p,prime[N];
bool isprime[N];

void init()
{
    memset(isprime,1,sizeof isprime);
    p=0;
    for (int i=2;i<=N;i++)
    {
        if (isprime[i]) prime[p++]=i;
        for (int j=0;j<p;j++)
        {
            int tmp=i*prime[j];
            if (tmp>N) break;
            isprime[tmp]=0;
            if (!(i%prime[j])) break;
        }
    }
}

int main()
{
    init();
    int n;
    while (scanf("%d",&n),n)
    {
        printf("%d = ",n);
        bool flag=1;
        if (n<0) {printf("-1");n=-n;flag=0;}
        for (int i=0;i<p;i++)
        {
            while (!(n%prime[i]))
            {
                if (flag) flag=0;
                else printf(" x ");
                printf("%d",prime[i]);
                n/=prime[i];
            }
            if (n==1) break;
        }
        if (n!=1)
        {
            if (!flag) printf(" x ");
            printf("%d",n);
        }
        putchar('\n');
    }
    return 0;
}
