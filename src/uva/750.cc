#include <iostream>
#include <cstdio>
#include <cstring>
using std::cin;
int csi,csj,location[8]={0},storage[20][8],a1,a2,n;
int check(int i, int j)
{
    int i1;
    int j1;
    for (i1 = 0; i1 < i; i1++)


    {
        j1 = location[i1];
        if (j == j1)
            return 0;
        if ((i1 + j1) == (i + j))
            return 0;
        if ((i1 - j1) == (i - j))
            return 0;
    }
    return 1;
}
void eight_queen(int i)
{
    int j;
    for (j = 0; j < 8; j++)
    {
        if (check(i, j))
        {
            location[i] = j;
            if (7 == i)
            {
                if (location[csj-1]==csi-1)
                {
                    for (n=0;n<8;n++)
                        storage[a2][n]=location[n];
                    a2++;
                }
                location[i] = 0;
                return;
            }
            eight_queen(i + 1);
            location[i] = 0;
        }
    }
}
int main()
{
    int k,a3;
    cin>>k;

    for (a1=1;a1<=k;a1++)
    {
        a2=0;
        cin>>csi>>csj;
        printf("SOLN       COLUMN\n #     1 2 3 4 5 6 7 8\n\n");

        memset(location,0,sizeof(location));
        eight_queen(0);
        for (a3=0;a3<a2;a3++)
        {


            printf("%2d    ",a3+1);
            for (n=0;n<8;n++)
                printf(" %d",storage[a3][n]+1);
            if (a3<a2-1)
                printf("\n");
        }
        if (a1!=k)
        printf("\n\n");
    }
    return 0;
}
