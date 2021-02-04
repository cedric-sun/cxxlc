#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n,cnt,fa[3000],v[3000];
vector<int> leaves;

bool build(int f)
{
    char tmp;
    while ((tmp=cin.peek())!=')' && !isdigit(tmp) && tmp!='-') cin.get();
    if (cin.peek()==')') {cin.get();return 0;}
    int id=++cnt;
    int value;cin>>value;
    v[id]=value;fa[id]=f;
    bool flag=0;
    for (int i=0;i<2;i++)
    {
        while (cin.get()!='(');
        if (build(id)) flag=1;
    }
    if (!flag) leaves.push_back(id);
    while (cin.get()!=')');
    return 1;
}

int main()
{
    //freopen("out.txt","w",stdout);
    while (~scanf("%d",&n))
    {
        leaves.clear();
        memset(fa,0,sizeof fa);
        memset(v,0,sizeof v);
        cnt=0;build(cnt);
        bool find=0;
        for (auto it=leaves.begin();it!=leaves.end();++it)
        {
            int sum=0,id=*it;
            while (id)
            {
                sum+=v[id];
                id=fa[id];
            }
            if (sum==n) {find=1;break;}
        }
        cout<<(find?"yes":"no")<<endl;
    }
    return 0;
}
