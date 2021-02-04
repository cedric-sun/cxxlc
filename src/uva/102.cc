#include <iostream>
using namespace std;

int main()
{
    int i,j,bin[3][3],b1,b2,b3,movesrecorder[6],minmoves;
    while (cin>>bin[0][0])
    {
        minmoves=bin[0][0];
        for (i=0; i<3; i++)
            for (j=i==0?1:0; j<3; j++)
            {


                cin>>bin[i][j];
                minmoves+=bin[i][j];
            }
        i=0;
        for (b1=0; b1<3; b1++)
            for (b2=0; b2<3; b2++)
            {
                if (b2==b1)
                    continue;
                for (b3=0; b3<3; b3++)
                {
                    if (b3==b1||b3==b2)
                        continue;
                    movesrecorder[i++]=bin[1][b1]+bin[2][b1]+bin[0][b2]+bin[2][b2]+bin[0][b3]+bin[1][b3];
                }
            }
        minmoves=movesrecorder[0];
        for (i=1; i<6; i++)
            if (movesrecorder[i]<minmoves)
                minmoves=movesrecorder[i];
        if (movesrecorder[1]==minmoves)
            cout<<"BCG";
        else if (movesrecorder[0]==minmoves)
            cout<<"BGC";
        else if (movesrecorder[4]==minmoves)
            cout<<"CBG";
        else if (movesrecorder[5]==minmoves)
            cout<<"CGB";
        else if (movesrecorder[2]==minmoves)
            cout<<"GBC";
        else if (movesrecorder[3]==minmoves)
            cout<<"GCB";
        cout<<' '<<minmoves<<endl;
    }
    return 0;
}
