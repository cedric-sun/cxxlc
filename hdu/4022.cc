#include <iostream>
#include <map>
#include <set>
#include <cstdio>
const int N=100010;
using namespace std;
int n,m;
typedef map<int,multiset<int> >mp;
multiset<int>::iterator iter;

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0&&m==0)break;
        mp mp1,mp2;
        int x,y,c,d,_count;
        for(int i=0; i<n; i++)
        {
            scanf("%d%d",&x,&y);
            mp1[x].insert(y);
            mp2[y].insert(x);
        }
        for(int i=0; i<m; i++)
        {
            scanf("%d%d",&c,&d);
            _count=0;
            if(c==0)
            {
                _count=mp1[d].size();
                for(iter=mp1[d].begin(); iter!=mp1[d].end(); iter++)
                {
                    mp2[*iter].erase(d);
                }
                mp1[d].clear();
            }
            else if(c==1)
            {
                _count=mp2[d].size();
                for(iter=mp2[d].begin(); iter!=mp2[d].end(); iter++)
                {
                    mp1[*iter].erase(d);
                }
                mp2[d].clear();
            }
            printf("%d\n",_count);
        }
        printf("\n");
    }
    return 0;
}
