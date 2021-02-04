#include <cstdio>
#include <cstring>

int n;
char pre[30],in[30],l[30],r[30];

int build(int pl,int pr,int il,int ir)
{
    if (il>ir) return 0;
    char root=pre[pl];
    int droot=root-'A'+1;
    int p=il;
    while (in[p]!=root) p++;
    int cnt=p-il;
    l[root-'A'+1]=build(pl+1,pl+cnt,il,p-1);
    r[root-'A'+1]=build(pl+cnt+1,pr,p+1,ir);
    return droot;
}

void dfs(int root)
{
    if (l[root])
        dfs(l[root]);
    if (r[root])
        dfs(r[root]);
    putchar(root+'A'-1);
}
int main()
{
    while (~scanf("%s %s",pre,in))
    {
        n=strlen(pre);
        dfs(build(0,n-1,0,n-1));
        putchar('\n');
    }
    return 0;
}
