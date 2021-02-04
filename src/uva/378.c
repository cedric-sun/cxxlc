#include <stdio.h>
int main()
{
    int i;
    double x1,y1,x2,y2,x3,y3,x4,y4,D,Dx,Dy,n1x,n1y,n2x,n2y;
    scanf("%d",&i);
    printf("INTERSECTING LINES OUTPUT\n");
    while (i--)
    {
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
        n1x=y1-y2;
        n1y=x2-x1;
        n2x=y3-y4;
        n2y=x4-x3;
        D=n1x*n2y-n2x*n1y;
        Dx=(n1x*x1+n1y*y1)*n2y-(n2x*x3+n2y*y3)*n1y;
        Dy=n1x*(n2x*x3+n2y*y3)-n2x*(n1x*x1+n1y*y1);
        if (D>1e-6||D<-1e-6)
            printf("POINT %.2lf %.2lf\n",Dx/D,Dy/D);
        else if (Dx>1e-6||Dx<-1e-6||Dy>1e-6||Dy<-1e-6)
            printf("NONE\n");
        else
            printf("LINE\n");
    }
    printf("END OF OUTPUT\n");
    return 0;
}
