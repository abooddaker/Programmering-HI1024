#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
int main(void)  
{ 
    int array[10]; 
 
	for (int i=0; i<=9; i++) 
	{ 
	 scanf("%d", &array[i]); 
	} 
 
	for (int i=0; i<=9; i++) 
	{ 
	 if (array[i]%array[0]==0 && array[i]%array[9]==0) 
        { 
        printf("%d ", array[i]); 
        } 
    }
return 0; 
}

 
 
