#include <iostream>
#include <iomanip>
using namespace std;
int chessboard[8][8],location[8]= {0},sum=0,maxsum=0,t;
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
                for (t=0,sum=0; t<8; t++)
                    sum+=chessboard[t][location[t]];
                if (sum>maxsum)
                    maxsum=sum;
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
    int i,j,k;
    cin>>k;
    while (k--)
    {
        maxsum=0;
        for (i=0; i<8; i++)
            for (j=0; j<8; j++)
                cin>>chessboard[i][j];
        eight_queen(0);
        cout<<setw(5)<<maxsum<<endl;
    }
    return 0;
}
