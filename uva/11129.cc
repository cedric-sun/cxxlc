#include <cstdio>
#include <cstring>

const int N=10000+5;

int a[N],tmp[N];

void divide(int l,int r)//[l,r]
{
    if (r-l<2) return;
    int i,j;
    for (i=l;i<=r;i++)
        tmp[i]=a[i];
    for (i=l,j=l;j<=r;i++,j+=2)
        a[i]=tmp[j];
    for (j=l+1;j<=r;i++,j+=2)
        a[i]=tmp[j];

    int mid=(l+r)>>1;
    divide(l,mid);
    divide(mid+1,r);
}
int main()
{
    int n;
    while (scanf("%d",&n) , n)
    {
        for (int i=0;i<n;i++)
            a[i]=i;
        divide(0,n-1);
        printf("%d:",n);
        for (int i=0;i<n;i++)
            printf(" %d",a[i]);
        putchar('\n');
    }
    return 0;
}
