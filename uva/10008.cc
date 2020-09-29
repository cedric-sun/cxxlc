#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <cstdio>
using namespace std;
struct ch
{
	char c;
	int occ;
	ch():occ(0){};
	bool operator < (ch& a)
	{
        if (occ==a.occ)
            return c<a.c;
        return occ>a.occ;
	}
};
ch ar[26];
void init()
{
	for (int i = 0; i < 26; ++i)
		ar[i].c='A'+i;
}
int main()
{
	int T;
	scanf("%d",&T);
	getchar();
	init();
	while (T--)
	{
		string str;
		getline(cin,str);
		int len=str.length();
		for (int i = 0; i < len; ++i)
		{
			if (isalpha(str[i]))
				ar[toupper(str[i])-'A'].occ++;
		}
	}
	sort(ar,ar+26);
	for (int i=0;ar[i].occ!=0;i++)
		printf("%c %d\n",ar[i].c,ar[i].occ);
	return 0;
}
