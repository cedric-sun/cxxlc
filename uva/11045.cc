#include <cstdio>
#include <map>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

int n, m, kind, lnk[40];
bool vis[40];
vector<vector<int> > g;
map<string, int> shoot;

void init()
{
	g.clear();
	g.resize(m);
	kind = n / 6;
	shoot.clear();
	shoot["XXL"] = 0;
	shoot["XL"] = kind * 1;
	shoot["L"] = kind * 2;
	shoot["M"] = kind * 3;
	shoot["S"] = kind * 4;
	shoot["XS"] = kind * 5;
}

int dfs(int u)
{
	for (vector<int>::iterator it = g[u].begin(); it != g[u].end(); it++)
		if (!vis[*it])
		{
			vis[*it] = 1;
			if (lnk[*it] == -1 || dfs(lnk[*it]))
			{
				lnk[*it] = u;
				return 1;
			}
		}
	return 0;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d", &n, &m);
		init();
		for (int i = 0; i<m; i++)
		{
			char t1[10], t2[10];
			scanf("%s %s", t1, t2);
			int s1 = shoot[t1], s2 = shoot[t2];
			for (int j = 0; j<kind; j++)
				g[i].push_back(s1 + j);
			for (int j = 0; j<kind; j++)
				g[i].push_back(s2 + j);
		}


		memset(lnk, -1, sizeof lnk);
		int jud = 0;
		for (int i = 0; i<m; i++)
		{
			memset(vis, 0, sizeof vis);
			jud += dfs(i);
		}

		if (jud == m)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
