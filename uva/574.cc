#include <cstdio>

int t,n,cnt,a[12],ans[12];

void dfs(int p,int len,int sum)
{
    if (sum>t) return;
    if (sum==t)
    {
        for (int i=0;i<len;i++)
        {
            if (i) putchar('+');
            printf("%d",ans[i]);
        }
        putchar('\n');
        cnt++;
        return;
    }
    for (int i=p;i<n;i++)
    {
        ans[len]=a[i];
        dfs(i+1,len+1,sum+a[i]);
        while (a[i]==a[i+1] && i+1<n) i++;
    }
}

int main()
{
    while (scanf("%d %d",&t,&n),n)
    {
        for (int i=0;i<n;i++)
            scanf("%d",a+i);
        cnt=0;
        printf("Sums of %d:\n",t);
        dfs(0,0,0);
        if (!cnt) printf("NONE\n");
    }
    return 0;
}
