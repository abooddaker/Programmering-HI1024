#include <stdio.h>
#define ROW 4
#define COL 5
#define GOAL 10

struct position{
    int row,col;
};
typedef struct position Position;

int numberOfJumps(int carrotGarden[][COL], int startRow, int startCol);
Position getNextPos(int carrotGarden[][COL],Position currentPos);

int main(){
    int carrotGarden[ROW][COL] = {  {1,0,4,1,2},
                                    {3,2,2,3,1},
                                    {4,1,3,2,2},
                                    {6,4,1,0,2}};

    //printf("%d\n",numberOfJumps(carrotGarden,2,3));//3
    //printf("%d\n",numberOfJumps(carrotGarden,3,2));//3
    //printf("%d\n",numberOfJumps(carrotGarden,0,2));//2
    printf("%d\n",numberOfJumps(carrotGarden,0,1));//2
    return 0;
}

//assumes that the goal is reachable by following the rules
int numberOfJumps(int carrotGarden[][COL], int startRow, int startCol){
    int numberCarrotsEaten = carrotGarden[startRow][startCol];
    carrotGarden[startRow][startCol] = 0;
    int numberJumps = 0;
    Position nextPos,currentPos = {startRow,startCol};

    while(numberCarrotsEaten<GOAL){
        nextPos = getNextPos(carrotGarden,currentPos);
        //printf("(%d,%d), ",nextPos.row,nextPos.col);
        numberCarrotsEaten += carrotGarden[nextPos.row][nextPos.col];
        carrotGarden[nextPos.row][nextPos.col] = 0;
        currentPos = nextPos;
        numberJumps++;
    }
    return numberJumps;
}

Position getNextPos(int carrotGarden[][COL],Position currentPos){
    Position nextPos = currentPos;
    int bestResult = 0;
    for(int i=currentPos.row-1;i<=currentPos.row+1;i++){
        if(0<=i && i<ROW){
            for(int j=currentPos.col-1;j<=currentPos.col+1;j++){
                if(0<=j && j<COL){
                    if(carrotGarden[i][j]>bestResult){
                        nextPos.row=i;
                        nextPos.col=j;
                        bestResult=carrotGarden[i][j];
                    }
                }
            }
        }
    }
    return nextPos;
}