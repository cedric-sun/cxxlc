#include <cstdio>
#include <algorithm>
using namespace std;

int n,cand[15];

void input()
{
    n=0;
    do
        scanf("%d",cand+n++);
    while (getchar()!='\n');
    /*
    string line;
    getline(cin,line);
    stringstream sline(line);
    while (sline>>cand[n]) ++n;
    */
}
void odd()
{
    int need=n>>1;
    int small=0;
    for (int i=n-1,j=0; j<need; i--)
    {
        small=small*10+cand[i];
        ++j;
    }
    int big_start=cand[0]?0:1;
    int big=cand[big_start];
    for (int i=0,j=0; j<need; i++)
    {
        if (i==big_start) continue;
        big=big*10+cand[i];
        ++j;
    }
    printf("%d\n",big-small);
}
void even()
{
    int min_diff=0x7fffffff,need=n>>1;
    do
    {
        if (cand[0]!=0 && cand[need]!=0)
        {
            int a=0,b=0;
            for (int i=0; i<need; i++)
            {
                a=a*10+cand[i];
                b=b*10+cand[i+need];
            }
            min_diff=min(min_diff,abs(a-b));
        }
    }
    while (next_permutation(cand,cand+n));
    printf("%d\n",min_diff);
}
int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    while (T--)
    {
        input();
        if (n&1) odd();
        else if (n==10) printf("247\n");
        else if (n==2) printf("%d\n",cand[1]-cand[0]);
        else even();
    }
    return 0;
}
