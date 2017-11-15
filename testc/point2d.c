#include <stdio.h>
#include <math.h>

typedef struct _Point2D
{
	int x;
	int y;
}Point2D;

int main()
{
	Point2D p1,p2;
	printf(" designate point 1\n"); 
	scanf("%d %d",&(p1.x),&(p1.y));
	printf(" designate point 2\n"); 
	scanf("%d %d",&(p2.x),&(p2.y));
	double d = sqrt(pow(p2.x-p1.x,2)+pow(p2.y-p1.y,2));
	printf("two points  distance is %lf",d);
	return 0;
}
