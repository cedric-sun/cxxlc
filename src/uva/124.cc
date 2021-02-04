#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <cstring>
using namespace std;

string G[26];
string avail;
set<string> ans;
bool vis[26];
char tempans[30];
int p;

void dfs(int u)
{
    vis[u]=1;
    int len=G[u].length();
    for (int i=0;i<len;i++)
        if (!vis[G[u][i]-'a'])
            dfs(G[u][i]-'a');

    tempans[--p]=u+'a';
}
int main()
{
    bool flag=0;
    char c1,c2;
    while (~(c1=getchar()))
    {
        for (int i=0;i<26;i++) G[i].clear();
        avail.clear(); ans.clear();

        avail.push_back(c1);
        while (getchar()==' ')
            avail.push_back(getchar());
        do
        {
            scanf("%c %c",&c1,&c2);
            G[c1-'a'].push_back(c2);
        }while (getchar()==' ');

        sort(avail.begin(),avail.end());
        int len=avail.length();
        tempans[len]='\0';
        do
        {
            p=len;
            memset(vis,0,sizeof vis);
            for (int i=0;i<len;i++)
                if (!vis[avail[i]-'a'])
                    dfs(avail[i]-'a');

            ans.insert(tempans);
        }while (next_permutation(avail.begin(),avail.end()));

        if (flag) putchar('\n');
        else flag=1;
        for (set<string>::iterator it=ans.begin();it!=ans.end();it++)
            cout<<(*it)<<'\n';
    }
}
