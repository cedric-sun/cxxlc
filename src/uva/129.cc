#include <cstdio>
char ans[90];
int cnt,n,L;
bool isrepe(int cur)//÷ÿ∏¥‘Ú∑µªÿ1
{
    bool flag;
    for (int i = 1; i <=(cur+1)/2; ++i)
    {
        flag=1;
        for (int j=0; j<i; j++)
            if (ans[cur-i+1+j]!=ans[cur-2*i+1+j])
            {
                flag=0;
                break;
            }
        if (flag) return 1;
    }
    return 0;
}
void output(int cur)
{
    for (int i=0; i<cur; i++)
    {
        putchar(ans[i]);
        if (i==cur-1)
            putchar('\n');
        else if ((i+1)%4==0)
        {
            if (i==63)
                putchar('\n');
            else
                putchar(' ');
        }
    }
    printf("%d\n",cur);
}
bool dfs(int cur)
{
    if (cnt==n)
    {
        output(cur);
        return true;
    }
    else
    {
        for (int i=0; i<L; i++)
        {
            ans[cur]=i+'A';
            if (!isrepe(cur))
            {
                cnt++;
                if(dfs(cur+1))
                    return true;
            }

        }
        return false;
    }
}
int main()
{
    while (scanf("%d %d",&n,&L)&&n)
    {
        cnt=0;
        dfs(0);
    }
    return 0;
}
