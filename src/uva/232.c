#include <stdio.h>
#include <string.h>
int start[10][10],temp[10][10];
char board[10][10];
int main()
{
    int r,c,i,j,m,n,cases=1,k;
    while (scanf("%d",&r)&&r)
    {
        if (!r)
            break;
        scanf("%d",&c);
        getchar();
        k=1;
        memset(start,0,sizeof(start));
        for (i=0; i<r; i++)
        {
            for (j=0; j<c; j++)
            {
                board[i][j]=getchar();
                if (board[i][j]!='*'&&(i-1<0||j-1<0||board[i-1][j]=='*'||board[i][j-1]=='*'))
                    start[i][j]=k++;
            }
            getchar();
        }
        memcpy(temp,start,sizeof(start));
        if (cases>1)
            putchar('\n');
        printf("puzzle #%d:\n",cases++);
        printf("Across\n");
        for (i=0; i<r; i++)
            for (j=0; j<c; j++)
            {
                if (temp[i][j])
                {
                    printf("%3d.",start[i][j]);
                    for (m=j; m<c&&board[i][m]!='*'; m++)
                    {
                        putchar(board[i][m]);
                        temp[i][m]=0;
                    }
                    putchar('\n');
                }
            }
        memcpy(temp,start,sizeof(start));
        printf("Down\n");
        for (i=0; i<r; i++)
            for (j=0; j<c; j++)
            {
                if (temp[i][j])
                {
                    printf("%3d.",start[i][j]);
                    for (n=i; n<r&&board[n][j]!='*'; n++)
                    {
                        putchar(board[n][j]);
                        temp[n][j]=0;
                    }
                    putchar('\n');
                }
            }

    }
    return 0;
}
