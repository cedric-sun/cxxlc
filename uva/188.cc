#include <string>
#include <sstream>
#include <iostream>
#include <map>
using namespace std;

const int pow32[]={1,32,1024,32768,1048576};

int n,wi,wj;
int w[20];

int hash(string a)
{
    int ans=0;
    for (int i=a.length()-1,j=0;i>=0;i--)
        ans+=(a[i]-'a'+1)*pow32[j++];
    return ans;
}

bool judge(int c)
{
    map<int,int> t;
    for (int i=1;i<=n;i++)
    {
        int hash=(c/w[i])%n;
        if (t[hash]) {wi=w[i];wj=t[hash];return 0;}
        t[hash]=w[i];
    }
    return 1;
}
int main()
{
    string line;
    while (getline(cin,line))
    {
        string word;
        stringstream ss(line);
        n=0;
        int minw=(1<<31)-1;
        while (ss>>word)
        {
            w[++n]=hash(word);
            minw=min(minw,w[n]);
        }

        int c=minw;
        while (!judge(c))
            c=min( (c/wi+1)*wi, (c/wj+1)*wj );

        cout<<line<<'\n';
        cout<<c<<"\n\n";
    }
    return 0;
}
