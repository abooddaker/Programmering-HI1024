#include <stdio.h>

int main()
{
    float data = 1, sum = 0, maxData = 0;
    while(data > 0){
        printf("Ange matdata: ");
        scanf("%f",&data);
        if(data > 0){
            sum += data;
        }
        if(data>maxData){
            maxData = data;
        }
    }
    if(sum>0){
        printf("Storsta matdata: %.3f Summa: %.3f\n",maxData,sum);
    }else{
        printf("Matdata saknas\n");
    }
    return 0;
}