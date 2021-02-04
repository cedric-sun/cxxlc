#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

int acnt,bcnt;
int c[105][105];
string a[105],b[105];

string backtrack(int i,int j)
{
    if (i==0 || j==0) return "";
    if (a[i-1]==b[j-1]) return backtrack(i-1,j-1)+' '+a[i-1];
    if (c[i][j-1]>c[i-1][j]) return backtrack(i,j-1);
    return backtrack(i-1,j);
}

int calc_c()
{
	for (int i=0;i<=acnt;i++) c[i][0]=0;
	for (int i=0;i<=bcnt;i++) c[0][i]=0;
	for (int i=1;i<=acnt;i++)
		for (int j=1;j<=bcnt;j++)
			if (a[i-1]==b[j-1]) c[i][j]=c[i-1][j-1]+1;
			else c[i][j]=max(c[i][j-1],c[i-1][j]);
    return c[acnt][bcnt];
}

bool read()
{
    string txt;
    if (!getline(cin,txt,'#')) return 0;
    cin.get();
    stringstream ss(txt);
    acnt=0;
    while (ss>>a[acnt]) acnt++;

    getline(cin,txt,'#');cin.get();
    ss.clear();ss.str(txt);
    bcnt=0;
    while (ss>>b[bcnt]) bcnt++;
    return 1;
}

int main()
{
    //freopen("out.txt","w",stdout);
    while (read())
    {
        calc_c();
        string ans=backtrack(acnt,bcnt);
        if (!ans.empty()) ans.erase(ans.begin());
        cout<<ans<<endl;
    }
    return 0;
}
