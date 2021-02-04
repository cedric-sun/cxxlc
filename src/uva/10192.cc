#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

//return LCS length
template<typename T>
int lcslen(const T &a,const T &b,const int alen,const int blen)
{
	int c[alen+1][blen+1];
	for (int i=0;i<=alen;i++) c[i][0]=0;
	for (int i=0;i<=blen;i++) c[0][i]=0;
	for (int i=1;i<=alen;i++)
		for (int j=1;j<=blen;j++)
			if (a[i-1]==b[j-1]) c[i][j]=c[i-1][j-1]+1;
			else c[i][j]=max(c[i][j-1],c[i-1][j]);
	return c[alen][blen];
}

int main()
{
    int cnt=1;
    string a,b;
    while (getline(cin,a),a!="#")
    {
        getline(cin,b);
        printf("Case #%d: you can visit at most %d cities.\n",cnt++,lcslen(a,b,a.length(),b.length()));
    }
    return 0;
}
