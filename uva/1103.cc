#include <cstdio>
#include <cstring>
#include <cstdlib>
const int L = 210;
const char cl[] = "ADJKSW";
char str[L][L / 4];
bool graph[L][L], visited[L][L];
int h, w, cnt, ans[6];

void draw()
{
	for (int i = 0; i<h; i++)
		for (int j = 0; j<w; j++)
		{
			char ch = str[i][j];
			int temp = (ch >= 'a') ? (ch - 'a' + 10) : (ch - '0');
			for (int k = 0; k<4; k++)
			{
				graph[i + 1][4 * j + 4 - k] = temp & 1;
				temp >>= 1;
			}
		}
}

void dfs0(int r, int c)
{
	if (r<0 || r>h + 1 || c<0 || c>4 * w + 1 || visited[r][c] || graph[r][c]) return;
	visited[r][c] = true;
	dfs0(r + 1, c);
	dfs0(r - 1, c);
	dfs0(r, c + 1);
	dfs0(r, c - 1);
}

void dfs1(int r, int c)
{
	if (r<0 || r>h + 1 || c<0 || c>4 * w + 1 || visited[r][c]) return;
	if (!graph[r][c])
	{
		dfs0(r, c);
		cnt++;
		return;
	}
	visited[r][c] = true;
	dfs1(r + 1, c);
	dfs1(r - 1, c);
	dfs1(r, c + 1);
	dfs1(r, c - 1);
}
int main()
{
	int cases = 1;
	while (~scanf("%d %d", &h, &w) && h)
	{
		for (int i = 0; i<h; i++)
			scanf("%s", str[i]);
        memset(graph,0,sizeof graph);
		memset(visited, 0, sizeof visited);
		memset(ans, 0, sizeof ans);
		draw();
		dfs0(0, 0);
		for (int i = 1; i <= h; i++)
			for (int j = 1; j <= 4 * w; j++)
				if (graph[i][j] && !visited[i][j])
				{
					cnt = 0;
					dfs1(i, j);
					switch (cnt)
					{
					case 0:ans[5]++; break;
					case 1:ans[0]++; break;
					case 2:ans[3]++; break;
					case 3:ans[2]++; break;
					case 4:ans[4]++; break;
					case 5:ans[1]++; break;
					}
				}

		printf("Case %d: ", cases++);
		for (int i = 0; i<6; i++)
			for (int j = 0; j<ans[i]; j++)
				putchar(cl[i]);
		putchar('\n');

	}
	return 0;
}
