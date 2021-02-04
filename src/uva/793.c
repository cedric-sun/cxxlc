#include <stdio.h>
#include <ctype.h>

int f[100005];

int uf(int x)
{
    if (f[x]!=x) f[x]=uf(f[x]);
    return f[x];
}

int main()
{
    int T,n,a,b,succ_cnt,unsucc_cnt,i,j;
    char c;
    scanf("%d",&T);
    for (i=0;i<T;i++)
    {
        scanf("%d",&n);getchar();
        succ_cnt=0,unsucc_cnt=0;
        for (j=1;j<=n;j++) f[j]=j;
        while (isalpha(c=getchar()))
        {
            scanf("%d %d",&a,&b);getchar();
            a=uf(a);b=uf(b);
            if (c=='c') f[a]=b;
            else a==b?succ_cnt++:unsucc_cnt++;
        }
        if (i) putchar('\n');
        printf("%d,%d\n",succ_cnt,unsucc_cnt);
    }
    return 0;
}


