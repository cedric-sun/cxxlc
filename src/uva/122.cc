#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
struct NODE
{
    NODE()
    {
        valued=false;
        LEFT=RIGHT=NULL;
    }
    bool valued;
    int value;
    NODE *LEFT,*RIGHT;
};

const int AM=10000;
char str[AM];
bool error;
NODE *root=NULL;
vector <int> ans;


void addNODE(int v,char *L)
{
    int len=strlen(L);
    NODE *cur=root;
    for (int i=0; i<len; i++)
    {
        if (L[i]=='L')
        {
            if (cur->LEFT==NULL) cur->LEFT=new NODE;
            cur=cur->LEFT;
        }
        else if (L[i]=='R')
        {
            if (cur->RIGHT==NULL) cur->RIGHT=new NODE;
            cur=cur->RIGHT;
        }
    }
    if (cur->valued) error=true;
    else
    {
        cur->value=v;
        cur->valued=true;
    }

}

void rt(NODE *cur)
{
    if (!cur) return;
    rt(cur->LEFT);
    rt(cur->RIGHT);
    delete cur;
}

bool read()
{
    rt(root);
    root=new NODE;
    error=false;
    for (int v;;)
    {
        if (scanf("%s",str)>>1) return false;
        if (!strcmp(str,"()")) break;
        sscanf(&str[1],"%d",&v);
        addNODE(v,strchr(str,',')+1);

    }
    return true;
}

bool BFS()
{
    queue <NODE*> q;
    ans.clear();
    q.push(root);
    while (!q.empty())
    {
        NODE *cur=q.front();
        q.pop();
        if (!cur->valued) return false;
        ans.push_back(cur->value);
        if (cur->LEFT) q.push(cur->LEFT);
        if (cur->RIGHT) q.push(cur->RIGHT);
    }
    return true;
}



void printans()
{
    for (unsigned i=0; i<ans.size(); i++)
    {
        if (i) putchar(' ');
        printf("%d",ans[i]);
    }
    putchar('\n');
}
int main()
{
    while (read())
    {
        if (BFS()&&!error)
            printans();
        else
            printf("not complete\n");
    }
    return 0;
}
