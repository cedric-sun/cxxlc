#include <bits/stdc++.h>
using namespace std;

int lnk[10];
bool vis[10];
char CC[0xFF];
vector<char> G[0xFF];

int dfs(int u)
{
    for (vector<char>::iterator it=G[u].begin(); it!=G[u].end(); it++)
    {
        int com=*it-'0';
        if (!vis[com])
        {
            vis[com]=1;
            if (lnk[com]==-1 || dfs(lnk[com]))
            {
                lnk[com]=u;
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    while (cin.peek()!=EOF)
    {
        int index=0;
        string line;
        while (getline(cin,line),isalpha(line[0]))
        {
            for (char i='0'; i<line[1]; i++)
            {
                G[index].clear();
                CC[index]=line[0];
                for (int j=3; line[j]!=';'; j++) G[index].push_back(line[j]);
                ++index;
            }
        }

        if (index<=10)
        {
            int cnt=0;
            memset(lnk,-1,sizeof lnk);
            for (int i=0; i<index; i++)
            {
                memset(vis,0,sizeof vis);
                cnt+=dfs(i);
            }
            if (cnt!=index) puts("!");
            else
            {
                for (int i=0;i<10;i++)
                {
                    if (lnk[i]==-1) putchar('_');
                    else putchar(CC[lnk[i]]);
                }
                putchar('\n');
            }
        }
        else puts("!");
    }
    return 0;
}
