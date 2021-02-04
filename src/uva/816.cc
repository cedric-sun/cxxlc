#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
struct NODE
{
	int y, x, dir;
	NODE(int a = 0, int b = 0, int d = 0) :y(a), x(b), dir(d) {}
};

const char  dirs[] = "NESW",
turns[] = "FLR";
const int   dy[] = { -1, 0, 1, 0 },
dx[] = { 0, 1, 0, -1 };


int x0, y_0, idir, x1, y_1, x2, y2;
int dist[10][10][4];
NODE path[10][10][4];
bool he[10][10][4][3];
string str;


inline int d_id(char c)
{
	return strchr(dirs, c) - dirs;
}
inline int t_id(char c)
{
	return strchr(turns, c) - turns;
}
inline bool isin(int y, int x)
{
	return x>0 && x <= 9 && y>0 && y <= 9;
}


NODE walk(const NODE &r, int turn)
{
	int dir = r.dir;
	if (turn == 1) dir = (dir + 3) % 4;
	if (turn == 2) dir = (dir + 1) % 4;
	return NODE(r.y + dy[dir], r.x + dx[dir], dir);
}

bool input()
{
	getline(cin, str);
	if (str == "END") return false;
	char d;
	scanf("%d %d %c %d %d", &y_0, &x0, &d, &y2, &x2);
	idir = d_id(d);
	x1 = x0 + dx[idir], y_1 = y_0 + dy[idir];
	int x, y;
	char temp[10];
    memset(he,0,sizeof he);
	while (scanf("%d", &y) && y)
	{
		scanf("%d", &x);
		while (scanf("%s", temp) && strcmp(temp, "*"))
		{
			int len = strlen(temp), dir1 = d_id(temp[0]);
			for (int i = 1; i<len; i++)
				he[y][x][dir1][t_id(temp[i])] = true;
		}
	}
	getchar();
	return true;
}

void pa(NODE k)
{
	vector<NODE> v;
	for (;;)
	{
		v.push_back(k);
		if (!dist[k.y][k.x][k.dir]) break;
		k = path[k.y][k.x][k.dir];
	}
	v.push_back(NODE(y_0, x0, idir));

	int cnt = 0;
	for (int i = v.size() - 1; i >= 0; i--)
	{
		if (cnt % 10 == 0) putchar(' ');
		printf(" (%d,%d)", v[i].y, v[i].x);
		if ((++cnt % 10) == 0) putchar('\n');
	}
	if (v.size() % 10) putchar('\n');
}
void bfs()
{
	queue<NODE> q;
	memset(dist, -1, sizeof dist);
	NODE P(y_1, x1, idir);
	dist[y_1][x1][idir] = 0;
	q.push(P);
	while (!q.empty())
	{
		NODE k = q.front();
		q.pop();
		if (k.x == x2&&k.y == y2)
		{
			pa(k);
			return;
		}
		for (int i = 0; i<3; i++)
		{
			NODE v = walk(k, i);
			if (isin(v.y, v.x) && dist[v.y][v.x][v.dir]<0 && he[k.y][k.x][k.dir][i])
			{
				dist[v.y][v.x][v.dir] = dist[k.y][k.x][k.dir] + 1;
				path[v.y][v.x][v.dir] = k;
				q.push(v);
			}
		}
	}
	printf("  No Solution Possible\n");
}

int main()
{
	while (input())
	{
		cout << str << '\n';
		bfs();
	}
	return 0;
}
