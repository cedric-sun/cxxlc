#include <stdio.h>
int main()
{
    char a;
    int count,score,cases;
    scanf("%d",&cases);
    getchar();
    while (cases--)
    {
        count=score=0;
        while ((a=getchar())!=EOF)
        {
            if (a=='O') score+=++count;
            else if (a=='X') count=0;
            else if (a=='\n') break;
        }
        printf("%d\n",score);
    }
    return 0;
}
