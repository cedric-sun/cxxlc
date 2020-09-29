#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
const int am=10005;
int i_o[am],p_o[am],lch[am],rch[am],n;
int best,best_sum;

bool read(int *a)
{
    int num;
    string line;
    n=0;
    if (!getline(cin,line))
        return false;
    stringstream ss(line);
    while (ss>>num) a[n++]=num;
    return n>0;
}

int build(int L1,int R1,int L2,int R2)
{
    if (L1>R1)
        return 0;
    int root=p_o[R2];
    int p=L1;
    while (i_o[p]!=root) p++;
    int cnt=p-L1;
    lch[root]=build(L1,p-1,L2,L2+cnt-1);
    rch[root]=build(p+1,R1,L2+cnt,R2-1);
    return root;
}

void dfs(int u,int sum)
{
    sum+=u;
    if (!lch[u]&&!rch[u])
    {
        if (sum<best_sum || (sum==best_sum&&u<best))
        {
            best=u;
            best_sum=sum;
        }
    }
    if (lch[u]) dfs(lch[u],sum);
    if (rch[u]) dfs(rch[u],sum);
}

int main()
{
    while (read(i_o))
    {
        read(p_o);
        build(0,n-1,0,n-1);
        best_sum=1<<30;
        dfs(p_o[n-1],0);
        cout<<best<<'\n';
    }
    return 0;
}
