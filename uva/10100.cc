#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <cstdio>

using namespace std;

bool blank;
int acnt,bcnt;
int c[1005][1005];
string a[1005],b[1005];

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
    blank=0;
    string txt;
    if (!getline(cin,txt)) return 0;
    if (txt.empty()) blank=1;
    for (auto it=txt.begin();it!=txt.end();it++) if (!isalpha(*it) && !isdigit(*it)) *it=' ';
    stringstream ss(txt);
    acnt=0;
    while (ss>>a[acnt]) acnt++;

    getline(cin,txt);
    if (txt.empty()) blank=1;
    for (auto it=txt.begin();it!=txt.end();it++) if (!isalpha(*it) && !isdigit(*it)) *it=' ';
    ss.clear();
    ss.str(txt);
    bcnt=0;
    while (ss>>b[bcnt]) bcnt++;
    return 1;
}

int main()
{
    //freopen("out.txt","w",stdout);
    int cnt=1;
    while (read())
    {
        printf("%2d. ",cnt++);
        if (blank) {printf("Blank!\n");continue;}
        printf("Length of longest match: %d\n",calc_c());
    }
    return 0;
}

