#include <cstdio>
#include <map>
using namespace std;

int len;
int coe[5],pow3[105];
map<int,int> mp;

void init()
{
    len=0;
    for (int i=-50;i<=50;i++)
        if (!i) continue;
        else pow3[len++]=i*i*i;
}

int main()
{
    init();
    for (int i=0;i<5;i++) scanf("%d",coe+i);
    mp.clear();
    for (int i=0;i<len;i++)
        for (int j=0;j<len;j++)
            mp[coe[0]*pow3[i]+coe[1]*pow3[j]]++;

    int ans=0;
    for (int i=0;i<len;i++)
        for (int j=0;j<len;j++)
            for (int k=0;k<len;k++)
            {
                int tmp=coe[2]*pow3[i]+coe[3]*pow3[j]+coe[4]*pow3[k];
                map<int,int>::iterator it=mp.find(-tmp);
                if (it!=mp.end())
                    ans+=it->second;
            }

    printf("%d\n",ans);
}
