#include <cstdio>
bool solve(int &W)
{
    int W1,D1,W2,D2;
    bool B1=true,B2=true;
    scanf("%d %d %d %d",&W1,&D1,&W2,&D2);
    if (!W1) B1=solve(W1);
    if(!W2) B2=solve(W2);
    W=W1+W2;
    return B1&&B2&&(W1*D1==W2*D2);
}

int main()
{
    int cases,W;
    scanf("%d",&cases);
    while (cases--)
    {
        printf("%s\n",solve(W)?"YES":"NO");
        if (cases) putchar('\n');
    }
    return 0;
}
