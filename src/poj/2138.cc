#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int N=1005,inf=0x7f7f7f7f;
int n,maxlen,minlen,si;
int dist[N];
bool inq[N];
vector<vector<int> > g;
vector<int> List[81];       //按字符串长度分类
string inttostr[N];

bool diff1(int a,int b)     //判断两个字符串是否仅有一个字母不同
{
    string::iterator    ssit=inttostr[a].begin(),   //short string iterator
                        sse=inttostr[a].end(),
                        lsit=inttostr[b].begin(),   //long string iterator
                        lse=inttostr[b].end();
    while (ssit!=sse && lsit!=lse)
    {
        if (*ssit==*lsit) ++ssit,++lsit;
        else ++lsit;
    }
    if (ssit==sse) return 1;
    return 0;
}
void read()
{
    string s;
    cin>>n>>s;
    maxlen=0;minlen=inf;
    for (int i=0;i<n;i++)
    {
        string tmp;
        cin>>tmp;
        if (tmp==s) si=i;
        inttostr[i]=tmp;
        int len=tmp.length();
        List[len].push_back(i);
        maxlen=max(maxlen,len);
        minlen=min(minlen,len);
    }
}

void build()
{
    g.resize(n);
    for (int i=minlen;i<maxlen;i++)
    {
        for (vector<int>::iterator it1=List[i].begin();it1!=List[i].end();++it1)
            for (vector<int>::iterator it2=List[i+1].begin();it2!=List[i+1].end();++it2)
                if (diff1(*it1,*it2))
                    g[*it1].push_back(*it2);

    }
}

void spfa()
{
    memset(dist,0x7f,sizeof dist);
    dist[si]=0;
    deque<int> q;
    inq[si]=1;
    q.push_back(si);
    while (!q.empty())
    {
        const int cur=q.front();q.pop_front();
        inq[cur]=0;
        for (vector<int>::iterator it=g[cur].begin();it!=g[cur].end();++it)
        {
            if (dist[cur]<inf && dist[cur]-1<dist[*it])
            {
                dist[*it]=dist[cur]-1;
                if (!inq[*it])
                {
                    if (q.empty()) q.push_back(*it);
                    else if (dist[*it]<dist[q.front()]) q.push_front(*it);
                    else q.push_back(*it);
                    inq[*it]=1;
                }
            }
        }
    }
}
int findmax()
{
    int maxdist=inf,index;
    for (int i=0;i<n;i++)
        if (dist[i]<maxdist) maxdist=dist[index=i];
    return index;
}
int main()
{
    read();
    build();
    spfa();
    cout<<inttostr[findmax()]<<endl;
    return 0;
}
