#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calc( double x0, double y0, double x1, double y1, double x2, double y2 )
{
	double A1 = x1-x0,B1 = y1-y0,C1 = x1*x1-x0*x0+y1*y1-y0*y0;
	double A2 = x2-x0,B2 = y2-y0,C2 = x2*x2-x0*x0+y2*y2-y0*y0;
	double c  = (B1*C2-B2*C1)/(A1*B2-A2*B1);
	double d  = (A2*C1-A1*C2)/(A1*B2-A2*B1);
	double e  = -x1*x1-y1*y1-x1*c-y1*d;
	double h  = c/-2.0;
	double k  = d/-2.0;
	double r  = sqrt((x1-h)*(x1-h)+(y1-k)*(y1-k));

	printf("(x ");
	if ( h > 0 ) printf("- %.3lf)^2 + (y ",h);
	else printf("+ %.3lf)^2 + (y ",-h);
	if ( k > 0 ) printf("- %.3lf)^2 = %.3lf^2\n",k,r);
	else printf("+ %.3lf)^2 = %.3lf^2\n",-k,r);

	printf("x^2 + y^2 ");
	if ( c < 0 ) printf("- %.3lfx ",-c);
	else printf("+ %.3lfx ",c);
	if ( d < 0 ) printf("- %.3lfy ",-d);
	else printf("+ %.3lfy ",d);
	if ( e < 0 ) printf("- %.3lf = 0\n\n",-e);
	else printf("+ %.3lf = 0\n\n",e);
}

int main()
{
	double x1,x2,x3,y1,y2,y3;
	while ( scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3) != EOF )
		calc( x1, y1, x2, y2, x3, y3 );
	return 0;
}

