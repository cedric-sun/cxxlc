#include <cstdio>
#include <queue>
using namespace std;

struct regist
{
    int id,t,v;
    bool operator < (const regist &ref) const
    {
        if (t==ref.t)
            return id>ref.id;
        return t>ref.t;
    }
    regist(int idd,int tt,int vv):id(idd),t(tt),v(vv){}
};

int main()
{
    char tmp[20];
    priority_queue<regist> q;
    while (scanf("%s",tmp),tmp[0]!='#')
    {
        int id,v;
        scanf("%d %d",&id,&v);
        q.push(regist(id,v,v));
    }
    int n,time=0;
    scanf("%d",&n);
    while (n--)
    {
        regist a=q.top();
        printf("%d\n",a.id);
        q.pop();
        time=a.t;
        a.t=time+a.v;
        q.push(a);
    }
    return 0;
}
