#include <cstdio>

const int N=500000+10;

int n,a[N],temp[N];
long long ans;

void merge_sort(int l,int r)
{
    if (r-l<=1) return;
    int m=(l+r)>>1;
    int p=l,q=m,i=l;
    merge_sort(l,m);
    merge_sort(m,r);
    while (p<m || q<r)
    {
        if (q>=r || (p<m && a[p]<=a[q])) temp[i++]=a[p++];
        else {temp[i++]=a[q++];ans+=m-p;}
    }
    for (i=l;i<r;i++) a[i]=temp[i];
}
int main()
{
    while (scanf("%d",&n),n)
    {
        for (int i=0;i<n;i++)
            scanf("%d",a+i);

        ans=0;
        merge_sort(0,n);
        printf("%lld\n",ans);
    }
    return 0;
}
