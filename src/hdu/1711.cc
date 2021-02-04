#include <cstdio>

int n,m;
int T[1000000+5],P[10000+5],next[10000+5];

void makenext()
{
    next[0]=-1;
    int i=0,j=-1;
    while (i<m)
    {
        if (j==-1||P[i]==P[j])
        {
            i++;j++;
            if (P[i]!=P[j]) next[i]=j;
            else next[i]=next[j];
        }
        else j=next[j];
    }
}

int kmp()
{
    int i=0,j=0;
    while (i<n && j<m)
    {
        if (T[i]==P[j]||j==-1) i++,j++;
        else j=next[j];
    }
    if (j==m) return i-m+1;
    return -1;
}
int main()
{
    int k;
    scanf("%d",&k);
    while (k--)
    {
        scanf("%d %d",&n,&m);
        for (int i=0;i<n;i++)
            scanf("%d",T+i);
        for (int i=0;i<m;i++)
            scanf("%d",P+i);

        if(m>n) printf("-1\n");
        else
        {
            makenext();
            printf("%d\n",kmp());
        }
    }
    return 0;
}
