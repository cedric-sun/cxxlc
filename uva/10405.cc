#include <iostream>
#include <algorithm>

using namespace std;

//return LCS length
int lcslen(const string &a,const string &b)
{
	const int alen=a.length(),blen=b.length();
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
    //freopen("output.txt","w",stdout);
    string a,b;
    while (getline(cin,a))
    {
        getline(cin,b);
        cout<<lcslen(a,b)<<endl;
    }
    return 0;
}
