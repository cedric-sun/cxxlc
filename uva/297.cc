#include <cstdio>
#include <cstring>
const int L=32;
char str[1024+10];
bool graph[L][L];
int ans,p;

void draw(int r,int c,int w)
{
    char ch=str[p++];
    if (ch=='p')
    {
        draw(r,c+w/2,w/2);
        draw(r,c,w/2);
        draw(r+w/2,c,w/2);
        draw(r+w/2,c+w/2,w/2);
    }
    else if (ch=='f')
    {
        for (int i=r;i<r+w;i++)
            for (int j=c;j<c+w;j++)
            if (!graph[i][j]) {graph[i][j]=true;ans++;}
    }
}

int main()
{
    int cases;
    scanf("%d",&cases);
    while (cases--)
    {
        memset(graph,0,sizeof graph);
        ans=0;
        for (int i=0;i<2;i++)
        {

        scanf("%s",str);
        p=0;
        draw(0,0,L);
        }
        printf("There are %d black pixels.\n",ans);
    }
    return 0;
}
