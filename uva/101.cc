#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

struct loc
{
	int x,y;
};

vector< vector<int> > world;
loc l[25];

void init(int n)
{
	world.clear();
	world.resize(n);
	for (int i=0;i<n;i++)
	{
		world[i].push_back(i);
		l[i].x=i;
		l[i].y=0;
	}
}

int option(int &a1,int &b1)
{
	int opt=1;
	string str1,str2;
	cin>>str1;
	if (str1=="quit") return 0;
	cin>>a1>>str2>>b1;
	if (l[a1].x==l[b1].x) return -1;
	if (str1=="pile")
		opt+=2;
	if (str2=="over")
		opt++;
	return opt;
}

void replace_blks_over(int a)
{
	for (int i=world[l[a].x].size()-1 ; i>l[a].y ;i--)
	{
		int t=world[l[a].x][i];
		world[l[a].x].pop_back();
		world[t].push_back(t);
		l[t].x=t;
		l[t].y=0;
	}
}
void move_a_to_top_of_bstack(int a,int b)
{
	world[l[a].x].pop_back();
	world[l[b].x].push_back(a);
	l[a].x=l[b].x;
	l[a].y=world[l[b].x].size()-1;
}
void move_onto(int a,int b)
{
	replace_blks_over(a);
	replace_blks_over(b);
	move_a_to_top_of_bstack(a,b);
}
void move_over(int a,int b)
{
	replace_blks_over(a);
	move_a_to_top_of_bstack(a,b);
}
void pile_onto(int a,int b)
{
	replace_blks_over(b);
	for (int i=l[a].y;i<world[l[a].x].size();i++)
		move_a_to_top_of_bstack(world[l[a].x][i],b);
}
void pile_over(int a,int b)
{
    int temp1=world[l[a].x].size()
	for (int i=l[a].y;i<temp1 ;i++)
		move_a_to_top_of_bstack(world[l[a].x][i],b);
}

int main()
{
	int a,b,n;
	while (~scanf("%d",&n))
	{
		init(n);
		int flag=1;
		while (flag)
		{
			switch (option(a,b))
			{
				case 0:flag=0;break;
				case 1:move_onto(a,b);break;
				case 2:move_over(a,b);break;
				case 3:pile_onto(a,b);break;
				case 4:pile_over(a,b);break;
				default:break;
			}
		}

		for (int i=0;i<n;i++)
        {
            printf("%d:",i);
            for (int j=0;j<world[i].size();j++)
                printf(" %d",world[i][j]);
            putchar('\n');
        }
	}
	return 0;
}
