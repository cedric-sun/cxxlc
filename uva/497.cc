#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N=10000+5;

int prev[N],subseq[N],subseq_size;

template <class T>
void backtrack(const T a[],int t,int d)
{
    if (d<1) return;
    backtrack(a,prev[t],d-1);
    subseq[subseq_size++]=a[t];
}

template <class T>
int bsearch(const T a[],const int c[],int sz,const T &key)
{
    int l=1,r=sz;
    while (l<r)
    {
        int mid=(l+r)>>1;
        if (a[c[mid]]<key) l=mid+1;
        else r=mid;
    }
    return l;
}

template <class T>
int LIS(const T a[],int n)//array index begin from 1
{
    int j,sz=1;
    int *c=new int[n+1];
    int *dp=new int[n+1];

    c[1]=1;
    dp[1]=1;

    for (int i=2;i<=n;i++)
    {
        if (a[i]<=a[c[1]])         j=1;
        else if (a[i]>a[c[sz]])    j=++sz;
        else                       j=bsearch(a,c,sz,a[i]);

        c[j]=i;
        dp[i]=j;
        prev[i]=c[j-1];
    }

    backtrack(a,c[sz],sz);
    delete c;
    delete dp;
    return sz;
}

int main()
{
    int T;
    cin>>T;
    for (int REIMU=0;REIMU<T;REIMU++)
    {
        int a[N];
        int n=0;
        do
        {
            cin>>a[++n];cin.get();
        }while (cin.peek()!='\n' && cin.peek()!=EOF);

        subseq_size=0;

        if (REIMU) putchar('\n');
        printf("Max hits: %d\n",LIS(a,n));
        for (int i=0;i<subseq_size;i++)
            printf("%d\n",subseq[i]);
    }
    return 0;
}
