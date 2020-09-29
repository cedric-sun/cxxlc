#include <cstdio>
#include <cmath>
#include <cstring>
bool isprime[32],used[32];
int ans[16],n,cnt=1;
bool ifprime(int a)
{
    for (int i=2; i<=sqrt(a); i&1?i+=2:i++)
        if (!(a%i))
            return 0;
    return 1;
}
void init_prime_list()
{
    for (int i = 2; i < 32; ++i)
        if (ifprime(i))
            isprime[i]=true;
}
void dfs(int cur)
{
    if (cur==n&&isprime[1+ans[n-1]])
    {
        for (int i = 0; i < n; ++i)
        {
            if (i)
                putchar(' ');
            printf("%d",ans[i]);
        }
        putchar('\n');
        return;
    }
    else
    {
        for (int i=2; i<=n; i++)
        {
            if (!used[i]&&isprime[ans[cur-1]+i])
            {
                ans[cur]=i;
                used[i]=true;
                dfs(cur+1);
                used[i]=false;
            }
        }
    }
}
int main()
{
    init_prime_list();
    ans[0]=1;
    while (~scanf("%d",&n))
    {
        if (cnt!=1)
            putchar('\n');
        printf("Case %d:\n",cnt++);
        memset(used,0,sizeof used);
        dfs(1);
    }
    return 0;
}
