#include <cstdio>
#include <algorithm>
#include <string>

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
    int n1,n2,cnt=1;
    while (scanf("%d %d",&n1,&n2),n1||n2)
    {
        int a[105],b[105];
        for (int i=0;i<n1;i++) scanf("%d",a+i);
        for (int i=0;i<n2;i++) scanf("%d",b+i);

        printf("Twin Towers #%d\n",cnt++);
        printf("Number of Tiles : %d\n\n",lcslen(a,b,n1,n2));
    }
    return 0;
}
