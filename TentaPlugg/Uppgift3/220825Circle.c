#include <stdio.h>
#include <math.h>

struct point{
    float x,y;
};
typedef struct point Point;
struct circle{
    float radius;
    Point centre;
};
typedef struct circle Circle;

void printCircle(Circle c);
int within(Circle c1, Circle c2);
float distance(Point p1, Point p2);

int main(){
    Circle circle1 =  {7,{-2,6}};
    printCircle(circle1);
    Circle circle2 =  {5,{2,3}};
    Circle circle3 =  {3,{-2,2}};
    Circle circle4 =  {8,{6,7}};
    printf("%d,%d\n",within(circle2,circle3),within(circle2,circle4));
    return 0;
}

int within(Circle c1, Circle c2){
    return distance(c1.centre,c2.centre)<=c1.radius;
}

float distance(Point p1, Point p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

void printCircle(Circle c){
    printf("Radie %.1f medelpunkt:(%.1f,%.1f)\n",c.radius,c.centre.x,c.centre.y);
}