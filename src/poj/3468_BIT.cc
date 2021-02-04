#include <cstdio>

const int N=100000+10;

int n,q;
long long c[N];

void add(int k,int v)
{
    while (k<=n)
    {
        c[k]+=v;
        k+=k&-k;
    }
}

long long sum(int k)
{
    long long s=0;
    while (k)
    {
        s+=c[k];
        k-=k&-k;
    }
    return s;
}
int main()
{
    scanf("%d %d",&n,&q);
    for (int i=1; i<=n; i++)
    {
        int tmp;
        scanf("%d",&tmp);
        add(i,tmp);
    }
    for (int i=0; i<q; i++)
    {
        char opt;
        scanf(" %c",&opt);
        if (opt=='Q')
        {
            int a,b;
            scanf("%d %d",&a,&b);
            printf("%lld\n",sum(b)-sum(a-1));
        }
        else
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            for (int i=a; i<=b; i++) add(i,c);
        }
    }
    return 0;
}
