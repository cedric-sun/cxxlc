#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
string name[20];
vector<queue<int> > vote;
bool valid[20];
struct candi
{
    int id,num;
    bool operator < (candi &ref)
    {
        return num>ref.num;
    }
} poll[20];

bool judge_tied(int left)
{
    int value=poll[0].num;
    for (int i=1;i<left;i++)
        if (poll[i].num!=value)
            return 0;
    return 1;
}
int main()
{
    int T,n;
    cin>>T;
    for (int k=0;k<T;k++)
    {
        cin>>n;
        cin.get();
        for (int i=0; i<n; i++)
            getline(cin,name[i]);
        vote.clear();
        while (cin.peek()!='\n')
        {
            queue<int> tmp;
            for (int i=0; i<n; i++)
            {
                int t;
                cin>>t;cin.get();
                tmp.push(t-1);
            }
            vote.push_back(tmp);
        }

        int nov=vote.size(),half=nov/2,left=n;
        memset(valid,1,sizeof valid);
        if (k)
            cout<<endl;
        while (left)
        {
            for (int i=0; i<n; i++)
            {
                poll[i].id=i;
                poll[i].num=0;
            }
            for (int i=0; i<nov; i++)
                while (!valid[vote[i].front()])
                    vote[i].pop();

            for (int i=0; i<nov; i++)
                poll[vote[i].front()].num++;

            sort(poll,poll+n);

            if (poll[0].num>half)
            {
                cout<<name[poll[0].id]<<endl;
                break;
            }
            if (judge_tied(left))
            {
                for (int i=0;i<n;i++)
                    if (valid[i])
                        cout<<name[i]<<endl;
                break;
            }

            int min=poll[left-1].num;
            for (int i=left-1; poll[i].num==min; i--)
            {
                valid[poll[i].id]=0;
                left--;
            }
        }
    }
    return 0;
}

