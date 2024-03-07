#include <stdio.h>
#include <math.h>

typedef struct PointType{
    double x,y;
}point;

int main(){
    // Initialize p1, p2 by the origin

    //struct PointType p1, p2;
    point p1 = {0.0, 0.0}, p2={0.0, 0.0};

    double dis = sqrt(  (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y) );

    printf("Initial distance: %lf\n", dis);

    printf("Enter x and y for p1:");
    scanf("%lf %lf", &(p1.x), &p1.y );
    printf("Enter x and y for p2:");
    scanf("%lf %lf", &(p2.x), &p2.y );

    dis = sqrt(  (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y) );
    printf("New distance: %lf\n", dis);

}

