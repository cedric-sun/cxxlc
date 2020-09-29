#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

struct cow
{
    int s,e,id;
    bool operator < (const cow &ref) const {return e>ref.e;}
}a[50005];

bool cmp(const cow &ref1,const cow &ref2) {return ref1.s<ref2.s;}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%d %d",&a[i].s,&a[i].e);
        a[i].id=i;
    }
    sort(a,a+n,cmp);
    priority_queue<cow> q;
    q.push(a[0]);
    int sn=0,sid[50005];
    sid[a[0].id]=++sn;
    for (int i=1;i<n;i++)
    {
        cow tmp=q.top();
        if (tmp.e < a[i].s)
        {
            q.pop();
            sid[a[i].id]=sid[tmp.id];
            q.push(a[i]);
        }
        else
        {
            sid[a[i].id]=++sn;
            q.push(a[i]);
        }
    }

    printf("%d\n",sn);
    for (int i=0;i<n;i++)
        printf("%d\n",sid[i]);
    return 0;
}
