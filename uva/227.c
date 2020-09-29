#include <stdio.h>
char board[5][5];
int main()
{
    int i,j,si,sj,error,cases=1;
    char op,temp;

    while ((board[0][0]=getchar())!='Z')
    {
        if (board[0][0]==' ')
        {
            si=0,sj=0;
        }
        for (i=0;i<5;i++)
        {
            for(j=!i?1:0;j<5;j++)
            {
                board[i][j]=getchar();
                if (board[i][j]==' ')
                {
                    si=i,sj=j;
                }
            }
            getchar();
        }


        error=0;
        while ((op=getchar())!='0')
        {
            if (op=='\n')
                continue;
            if (!error)
            {
                switch(op)
                {
                    case 'A':
                        if (si-1>=0) {temp=board[si][sj];board[si][sj]=board[si-1][sj];board[si-1][sj]=temp;si-=1;}
                        else error=1;
                        break;
                    case 'B':
                        if (si+1<5) {temp=board[si][sj];board[si][sj]=board[si+1][sj];board[si+1][sj]=temp;si+=1;}
                        else error=1;
                        break;
                    case 'L':
                        if (sj-1>=0) {temp=board[si][sj];board[si][sj]=board[si][sj-1];board[si][sj-1]=temp;sj-=1;}
                        else error=1;
                        break;
                    case 'R':
                        if (sj+1<5) {temp=board[si][sj];board[si][sj]=board[si][sj+1];board[si][sj+1]=temp;sj+=1;}
                        else error=1;
                        break;
                }
            }
        }
        getchar();

        if (cases!=1)
            putchar('\n');
        printf("Puzzle #%d:\n",cases++);
        if (error)
            printf("This puzzle has no final configuration.\n");
        else
            for (i=0;i<5;i++)
            {
                for (j=0;j<5;j++)
                {
                    if (j)
                        putchar(' ');
                    putchar(board[i][j]);
                }
                putchar('\n');
            }

    }
return 0;
}
